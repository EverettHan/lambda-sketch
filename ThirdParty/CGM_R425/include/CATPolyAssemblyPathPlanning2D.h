// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyAssemblyPathPlanning2D.h
// Header definition of CATPolyAssemblyPathPlanning2D
//
//===================================================================
//
// Usage notes: Base class for path planning in a physical environment,
//              with a 2D trajectory
//
//===================================================================
//
// January 2013 Creation: JXO
// Septemb 2013 Modif JXO: Phoenix related methods
// October 2013 Modif JXO: Random generator parameters
// October 2013 Modif JXO: Offset
//===================================================================
#ifndef CATPolyAssemblyPathPlanning2D_H
#define CATPolyAssemblyPathPlanning2D_H

// ExportedBy
#include "PolyBodyBVHOperators.h"

// Poly
class CATBVHTreeSet;
class CATPolyPPPosition;
class CATPolyPPCartesianProduct;
class CATPolyPPTopologicalSpaceR2;
#include "CATPolyAssemblyPathPlanning.h"

// Math
class CATMathTransformation;

/**
 * \addtogroup PathPlan3DAssembly
 * @{
 */

/**
 * Base class for path planning in a physical environment, with a 2D trajectory
 */
class ExportedByPolyBodyBVHOperators CATPolyAssemblyPathPlanning2D : public CATPolyAssemblyPathPlanning
{
public:
  /**
   * Constructor.
   * Movement is planar inside OIJ in axis system for translations (see CATPolyAssemblyPathPlanning)
   * @param iScene
   *        BVHTreeSet containing the whole scene where iMovingModel should be moving (without iMovingModel)
   * @param iMovingModel
   *        BVHTreeSet containing moving model. Should contain one and only one model.
   * @param iRandomSeed Seed for the random generator. You should NEVER use 0.
   * @param iType CATPolyUniformRandomGenerator::AdvMathematics is a good idea
   */
  CATPolyAssemblyPathPlanning2D(CATBVHTreeSet & iScene, CATBVHTreeSet & iMovingModel, unsigned int iRandomSeed = 17, CATPolyUniformRandomGenerator::Type iType = CATPolyUniformRandomGenerator::AdvMathematics);
  CATPolyAssemblyPathPlanning2D( const CATPolyAssemblyPathPlanning2D& iOther );
  /** Destructor */
  ~CATPolyAssemblyPathPlanning2D();

  /**
   * Sets the limits of the search space, in model space.
   * Limits always have to be set AFTER SetAxisForTranslations and SetAxisForRotations.
   * Limits apply to the moving object in the physical world, so depending on its gravity center
   *        they may not apply to the coordinates of the positions.
   * @param iDim
   *          - 1 X translation
   *          - 2 Y translation
   *          @warning Dimension not start at 0
   *
   * @param[in] min
   *        Limit min of the iDim dimension
   * @param[in] max
   *        Limit max of the iDim dimension
   * @return E_INVALIDARG if iDim out of range, S_OK otherwise
   */
  HRESULT SetLimits(int iDim, double min, double max);

  /** Sets the offset of the plane in z direction (translation axis) */
  void SetOffset(double off){m_offset = off;}

  /** Converts the position of moving model (inside iMovingModel) to a point in configuration space
   * @return to be deleted by caller
   */
  virtual CATPolyPPPosition * Convert(const CATMathTransformation & iTransfo) const;

  /** Converts a point in configuration space to the position of moving model (inside iMovingModel)
   */
  virtual CATMathTransformation Convert(const CATPolyPPPosition & iPoint) const;

  virtual CATMathBox ConvertToConfigSpace( const CATMathBox& iBox ) const;

  /** For Phoenix record */
  virtual const CATListOfInt & GetLimitedDimensions() const;
  /** For Phoenix record */
  virtual const CATListOfDouble & GetMinLimits() const;
  /** For Phoenix record */
  virtual const CATListOfDouble & GetMaxLimits() const;
  /** For Phoenix record */
  virtual CATPolyAssemblyPathPlanning2D * CastTo2D() {return this;}

  virtual CATPolyAssemblyPathPlanning2D* Clone() const;

protected:
  friend class CATPolyBodyPathPlanningOperODT;
  CATPolyPPTopologicalSpaceR2 * m_TopoSpace;
  CATMathPlane m_Plane;
  double m_offset;

private:
  CATListOfInt     m_LimitedDimensions;
  CATListOfDouble  m_MinLimits, m_MaxLimits;
};

/** @} */

#endif

