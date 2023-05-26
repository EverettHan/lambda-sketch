#ifndef CATSFCylindricalTransformQuery_H
#define CATSFCylindricalTransformQuery_H

#include "GMScalarFieldsOperators.h"

#include "CATBoolean.h"
#include "CATUnicodeString.h"

// Math
#include "CATMathPoint.h"
#include "CATMathVector.h"

// CGM
#include "CATICGMObject.h"

// Scalar Fields
#include "SFTypes.h"
#include "CATSFDagNodeQuery.h"

// STD
#include <memory>

namespace SF
{
  class SFDagNode;
  class SFCylindricalTransform;

  using  SFDagNodePtr = std::shared_ptr<SFDagNode>;
  using  SFCylindricalTransformPtr = std::shared_ptr<SFCylindricalTransform>;
}

/**
 * CATSFCylindricalTransformQuery contains methods to introspect specific node types members.
 * This class is meant to be overridden by node type.
 * You can use GetTypedQuery to easily get the right derived class for you specific
 * node type.
 */
class ExportedByGMScalarFieldsOperators CATSFCylindricalTransformQuery : public CATSFDagNodeQuery
{
public:

  typedef std::unique_ptr<CATSFCylindricalTransformQuery>      UPtr;
  typedef std::shared_ptr<CATSFCylindricalTransformQuery>      Ptr;

  /**
   * dtor
   */
  virtual ~CATSFCylindricalTransformQuery();

  /**
 * Get the origin of the axis associated with the cylindrical transformation.
 */
  virtual HRESULT GetOrigin(CATMathPoint& oOrigin) const = 0;

  /**
   * Get the axis of the axis associated with the cylindrical transformation.
   */
  virtual HRESULT GetAxis(CATMathVector& oOrigin) const = 0;

  /**
   * Get the reference periodicity of associated with the cylindrical transformation.
   */
  virtual double GetReferencePeriodicity() const = 0;
protected:
  /**
   * ctor
   *
   */
  CATSFCylindricalTransformQuery();
};

#endif // CATSFCylindricalTransformQuery_H
