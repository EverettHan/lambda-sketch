// COPYRIGHT DASSAULT SYSTEMES 2018, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyAssemblyPathPlanning2Dx1.h
// Header definition of CATPolyAssemblyPathPlanning2Dx1
//
//===================================================================
//
// Usage notes: Base class for path planning in a physical environment,
//              with a 2D trajectory, both translation (2D) and rotations (1D)
//
//===================================================================
//
// June 2018 Creation: JXO
//===================================================================
#ifndef CATPolyAssemblyPathPlanning2Dx1_H
#define CATPolyAssemblyPathPlanning2Dx1_H

// ExportedBy
#include "PolyBodyBVHOperators.h"

// Poly
class CATBVHTreeSet;
class CATPolyPPPosition;
class CATPolyPPCartesianProduct;
class CATPolyPPTopologicalSpaceR2;
class CATPolyPPTopologicalSpaceSO2;
#include "CATPolyAssemblyPathPlanning.h"

// Math
class CATMathTransformation;

/**
 * \addtogroup PathPlan3DAssembly
 * @{
 */

/**
 * Base class for path planning in a physical environment, with a 2D trajectory with rotations
 */
class ExportedByPolyBodyBVHOperators CATPolyAssemblyPathPlanning2Dx1 : public CATPolyAssemblyPathPlanning
{
public:
  /**
   * Constructor.
   * Movement is planar inside OIJ in axis system for translations (see CATPolyAssemblyPathPlanning)
   *          can rotate around this axis.
   * @param iScene
   *        BVHTreeSet containing the whole scene where iMovingModel should be moving (without iMovingModel)
   * @param iMovingModel
   *        BVHTreeSet containing moving model. Should contain one and only one model.
   * @param iRandomSeed Seed for the random generator. You should NEVER use 0.
   * @param iType CATPolyUniformRandomGenerator::AdvMathematics is a good idea
   */
  CATPolyAssemblyPathPlanning2Dx1(CATBVHTreeSet & iScene, CATBVHTreeSet & iMovingModel, unsigned int iRandomSeed = 17, CATPolyUniformRandomGenerator::Type iType = CATPolyUniformRandomGenerator::AdvMathematics);
  CATPolyAssemblyPathPlanning2Dx1( const CATPolyAssemblyPathPlanning2Dx1& iOther );
  /** Destructor */
  ~CATPolyAssemblyPathPlanning2Dx1();

  /**
   * Sets the limits of the search space, in model space.
   * Limits always have to be set AFTER SetAxisForTranslations and SetAxisForRotations.
   * Limits apply to the moving object in the physical world, so depending on its gravity center
   *        they may not apply to the coordinates of the positions.
   * @param[in] iDim
   *        Dimension: 1, 2 for X, Y
   *                   3 for rotations
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
  virtual CATPolyAssemblyPathPlanning2D * CastTo2D() {return 0;}
  /** For Phoenix record */
  virtual CATPolyAssemblyPathPlanning3D * CastTo3D() {return 0;}
  /** For Phoenix record */
  virtual CATPolyAssemblyPathPlanning6D * CastTo6D() {return 0;}
  /** For Phoenix record */
  virtual CATPolyAssemblyPathPlanning2Dx1 * CastTo2Dx1() {return this;}

  virtual CATPolyAssemblyPathPlanning2Dx1* Clone() const;

protected:
  friend class CATPolyBodyPathPlanningOperODT;
  CATPolyPPTopologicalSpaceR2 * m_TopoSpace2D;
  CATPolyPPTopologicalSpaceSO2 * m_TopoSpaceSO2;
  CATMathPlane m_Plane;
  double m_offset;

private:
  CATListOfInt     m_LimitedDimensions;
  CATListOfDouble  m_MinLimits, m_MaxLimits;
};

/** @} */

#endif

