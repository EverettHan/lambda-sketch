// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyAssemblyPathPlanning6D.h
// Header definition of CATPolyAssemblyPathPlanning6D
//
//===================================================================
//
// Usage notes: Path planning in a physical environment, modelized with R3 x SO3
//
//===================================================================
//
// February 2013 Creation: JXO
// Septemb 2013 Modif JXO: Phoenix related methods
// October 2013 Modif JXO: New interpolator class & Random generator parameters
//===================================================================
#ifndef CATPolyAssemblyPathPlanning6D_H
#define CATPolyAssemblyPathPlanning6D_H

// ExportedBy
#include "PolyBodyBVHOperators.h"

// Poly
class CATBVHTreeSet;
class CATPolyPPPosition;
class CATPolyPPTopologicalSpaceR3;
class CATPolyPPTopologicalSpaceSO3;
class CATPolyBodyPathPlanningOperODT;
class CATPolyPPConfigurationChecker;
#include "CATPolyAssemblyPathPlanning.h"
#include "CATPolyPPCartesianProduct.h"

// Math
class CATMathTransformation;

/**
 * \addtogroup PathPlan3DAssembly
 * @{
 */

/**
 * Path planning in a physical environment, modelized with R3 x SO3
 */
class ExportedByPolyBodyBVHOperators CATPolyAssemblyPathPlanning6D : public CATPolyAssemblyPathPlanning
{
public:
  /**
   * Constructor
   * @param iScene
   *        BVHTreeSet containing the whole scene where iMovingModel should be moving (without iMovingModel)
   * @param iMovingModel
   *        BVHTreeSet containing moving model. Should contain one and only one model.
   *  @param iRotationType
   *        Specify the convention for rotation order
   * @param iRandomSeed Seed for the random generator. You should NEVER use 0.limi
   * @param iType CATPolyUniformRandomGenerator::AdvMathematics is a good idea
   */
  CATPolyAssemblyPathPlanning6D(CATBVHTreeSet & iScene, CATBVHTreeSet & iMovingModel, CATPolyPPTopologicalSpaceSO3::RotationType iRotationType = CATPolyPPTopologicalSpaceSO3::EulerAnglesZYX, unsigned int iRandomSeed = 17, CATPolyUniformRandomGenerator::Type iType = CATPolyUniformRandomGenerator::AdvMathematics);

  CATPolyAssemblyPathPlanning6D( const CATPolyAssemblyPathPlanning6D& iOther );
  /** Destructor */
  ~CATPolyAssemblyPathPlanning6D();

  /** Converts the position of moving model (inside iMovingModel) to a point in configuration space
   * @return to be deleted by caller
   */
  CATPolyPPPosition * Convert(const CATMathTransformation & iTransfo) const;

  /** Converts a point in configuration space to the position of moving model (inside iMovingModel)
   */
  CATMathTransformation Convert(const CATPolyPPPosition & iPoint) const;

  CATMathBox ConvertToConfigSpace( const CATMathBox& iBox ) const;

  /**
   * Sets the limits of the search space, in model space.
   * Limits always have to be set AFTER SetAxisForTranslations and SetAxisForRotations.
   * Limits apply to the moving object in the physical world, so depending on its gravity center
   *        they may not apply to the coordinates of the positions.
   * @param iDim
   *        Dimension: 1, 2 for 2D case
   *                   3 for 3D case
   * @param[in] min
   *        Limit min of the iDim dimension
   * @param[in] max
   *        Limit max of the iDim dimension
   * @return E_INVALIDARG if iDim out of range, S_OK otherwise
   */
  HRESULT SetLimits(int iDim, double min, double max);

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
  virtual CATPolyAssemblyPathPlanning6D * CastTo6D() {return this;}
  /** For Phoenix record */
  virtual CATPolyPPTopologicalSpaceSO3::RotationType GetRotationType() const;

  virtual CATPolyAssemblyPathPlanning6D* Clone() const;

private:

  friend class CATPolyBodyPathPlanningOperODT;

  CATListOfInt     m_LimitedDimensions;
  CATListOfDouble  m_MinLimits, m_MaxLimits;
};

/** @} */

#endif

