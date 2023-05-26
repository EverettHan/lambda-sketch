#ifndef SFEvaluationContext_h
#define SFEvaluationContext_h

// Mathematics
#include "CATMathPoint.h"
#include "CATMathTransformation.h"

// ScalarFields
#include "ScalarFields.h"
#include "ScalarFieldUtils.h"

// STD
#include <iostream>
#include <memory>
#include <vector>

namespace SF
{
  /**
   * @brief SFEvaluationContext contains thread specific information related
   * to the evaluation of the Direct Acyclic Graph used to specify scalar fields.
   * @details Key information are an identifier of the execution thread itself
   * (see GetTag) or the position at which you want to perform current evaluation
   * (see GetAtPosition).
   */
  class ExportedByScalarFields SFEvaluationContext {

    friend class SFDagEvaluator;
    friend class PolyBodyToSF;

    typedef std::unique_ptr<SFEvaluationContext> SFContextUPtr;
    typedef std::shared_ptr<SFEvaluationContext> SFContextPtr;
  public:
    SFEvaluationContext(const int iTag);
    SFEvaluationContext(const SFEvaluationContext& iOther);
    virtual ~SFEvaluationContext();

    /**
     * Identifier for the thread of execution. This might
     * be used internally by some classes to cache results
     * of evaluation per thread of execution.
     */
    SFINLINE const int GetTag() const
    {
      return _tag;
    }

    /**
     * Allows one to specific for which position in space
     * you want to evaluate the scalar value.
     */
    void SetAtPosition(const CATMathPoint& iPosition);

    void SetDomainSize(const double iDomaineSizeX, const double iDomaineSizeY, const double iDomaineSizeZ);

    void SetVoxelSize(const double iVoxelSize);

    /**
     * Allows one to specific for which position in space
     * you want to evaluate the scalar value.
     */
    SFEvaluationContext ApplyAffineTransform(const CATMathTransformation& iTransf);

    /**
     * Let's retrieve the position for which you want to evaluate
     * a scalar value.
     */

    SFINLINE const CATMathPoint& GetAtPosition() const
    {
      return _atPosition;
    }

    SFINLINE const double GetDomainDiameter() const
    {
      return sqrt(_domainSizeX * _domainSizeX + _domainSizeY * _domainSizeY + _domainSizeZ * _domainSizeZ);
    }

    SFINLINE const double GetDomainSizeX() const
    {
      return _domainSizeX;
    }

    SFINLINE const double GetDomainSizeY() const
    {
      return _domainSizeY;
    }

    SFINLINE const double GetDomainSizeZ() const
    {
      return _domainSizeZ;
    }

    SFINLINE const double GetVoxelSize() const
    {
      return _voxelSize;
    }

  private:
    const int         _tag;

    CATMathPoint  _atPosition;
    double _domainSizeX;
    double _domainSizeY;
    double _domainSizeZ;
    double _voxelSize;

  };
};

#endif // SFEvaluationContext_h
