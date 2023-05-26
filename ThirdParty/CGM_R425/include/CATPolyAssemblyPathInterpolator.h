// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyAssemblyPathInterpolator.h
// Header definition of CATPolyAssemblyPathInterpolator
//
//===================================================================
//
// Usage notes: Interpolator used in the CATPolyAssemblyPathPlanning classes
//
//===================================================================
//
// October 2013 Creation: JXO
// October 2013 Modifications JXO/XXC: New axis for rotations and translations
// August  2018 Modifications JXO: Config space is now refcounted.
//===================================================================
#ifndef CATPolyAssemblyPathInterpolator_H
#define CATPolyAssemblyPathInterpolator_H

// ExportedBy
#include "PolyBodyBVHOperators.h"

// Poly
class CATPolyPPTopologicalSpaceR3;
#include "CATPolyPPTopologicalSpaceSO3.h"
#include "CATPolyPPCartesianProduct.h"
#include "CATPolyUniformRandomGenerator.h"
class CATPolyPPCartesianProduct6D;
#include "CATPolyPPPosition.h"

// Math
class CATMathAxis;
#include "CATMathTransformation.h"

// System
#include "CATBoolean.h"

/**
 * \addtogroup PathPlan3DAssembly
 * @{
 */

//todo put this class in its own header
/**
 *  interface to convert from/to:
 *    - 3D position (CATMathTransformation)
 *    - configuration (CATPolyPPPosition )
 * */
class ExportedByPolyBodyBVHOperators CATPPPositionTo3DConverterInterface
{
  public:
  /** 
   * Convert from 3D position to PPPosition
   * 
   */
  virtual CATPolyPPPosition::SPtr  ConvertToPP(const CATMathTransformation & iTransfo) const = 0 ;

  /** 
   *  Converts a point in configuration space to the position in 3D
   */
  virtual CATMathTransformation ConvertTo3D(const CATPolyPPPosition & iPoint) const = 0;
};



/**
 * Interpolator used in the CATPolyAssemblyPathPlanning classes, in a physical environment, modelized with R3 x SO3.
 */
class ExportedByPolyBodyBVHOperators CATPolyAssemblyPathInterpolator : public CATPPPositionTo3DConverterInterface
{
public:
  /** 
   * Constructor
   * @param iAxisForTranslations see CATPolyAssemblyPathPlanning.
   * @param iAxisForRotations see CATPolyAssemblyPathPlanning.
   * @param iRotationType type of the rotation. See CATPolyPPTopologicalSpaceSO3.
   * @param iDoNotDeleteSpace Don't use.
   */
  CATPolyAssemblyPathInterpolator(const CATMathAxis & iAxisForTranslations,
                                  const CATMathAxis & iAxisForRotations,
                                  CATPolyPPTopologicalSpaceSO3::RotationType iRotationType = CATPolyPPTopologicalSpaceSO3::EulerAnglesZYX,
                                  CATBoolean iDoNotDeleteSpace = FALSE);  
    
  /** Destructor */
  virtual ~CATPolyAssemblyPathInterpolator();

  /** Sets the axis used for limits computation for the translations
   *  Center of this axis is irrelevant. */
  void SetAxisForTranslations(const CATMathAxis & iAxis);

  /** Sets the axis used for the rotations:
   *  - Limits for the angles are expressed in this axis
   *  - Center of this axis overrides any previous computed center for the rotations
   */
  void SetAxisForRotations(const CATMathAxis & iAxis);

  /**
   * Sets the limits of the search space, in model space.
   * Limits always have to be set AFTER SetAxisForTranslations and SetAxisForRotations.
   * Limits apply to the moving object in the physical world, so depending on its gravity center
   *        they may not apply to the coordinates of the positions.
   * @param iDim
   *        Dimension: 1, 2 for 2D case
   *                   3 for 3D case
   *                   4 to 6 for Yaw, Pitch, roll
   * @param min the min limit 
   * @param max the max limit
   * @return E_INVALIDARG if iDim out of range, S_OK otherwise
   */
  HRESULT SetLimits(int iDim, double min, double max);

  /**
   * Interpolates between positions
   * @param iPos1 start point of interpolation 
   * @param iPos2 end point of interpolation
   * @param iParam interpolation value between iPos1 and iPos2
   *   0 for iPos1, 1 for iPos2, linear interpolation
   */
  CATMathTransformation Interpolate(const CATMathTransformation & iPos1, const CATMathTransformation & iPos2, double iParam) const;

  /** Returns the axis used for the translations */
  const CATMathAxis & GetAxisForTranslations() const {return m_AxisForTranslations;}

  /** Returns the axis used for the rotations */
  const CATMathAxis & GetAxisForRotations() const {return m_AxisForRotations;}

  /** DEPRECATED
   *  Use CATPolyAssemblyPathPlanning::GetCenterOfMovingObject instead
   */
  CATMathTransformation GetModelConversionMatrix() const {return CATMathTransformation();}

  virtual CATPolyAssemblyPathInterpolator* Clone() const;

  /**
   * Converts a box expressed in the physical world to a box in config space.
   */
  virtual CATMathBox ConvertToConfigSpace( const CATMathBox& iBox ) const {return CATMathBox();}

  /** Converts the position of moving model (inside iMovingModel) to a point in configuration space
  * @return to be deleted by caller
  */
  virtual CATPolyPPPosition * Convert(const CATMathTransformation & iTransfo) const;
  virtual CATPolyPPPosition::SPtr  ConvertToPP(const CATMathTransformation & iTransfo) const  ;

  
  /** Converts a point in configuration space to the position of moving model (inside iMovingModel)
  */
  virtual CATMathTransformation Convert(const CATPolyPPPosition & iPoint) const;
  virtual CATMathTransformation ConvertTo3D(const CATPolyPPPosition & iPoint) const ;

  /** For Phoenix record */
  const CATPolyPPCartesianProduct * GetSpace() const;

  const CATMathBox & GetMovingBox() const {return m_MovingBox;}
  void SetMovingBox(const CATMathBox & iBox);

    /** Resets the random generator */
  void ResetBaseRandomGenerator(unsigned int iRandomSeed = 0, CATPolyUniformRandomGenerator::Type iType = CATPolyUniformRandomGenerator::undefined);
  CATPolyUniformRandomGenerator& GetBaseRandomGenerator(){ return m_BaseGenerator; };

protected:
  CATPolyAssemblyPathInterpolator( const CATPolyAssemblyPathInterpolator& iOther );

private:
  void UpdateAxisForRotations();

protected:
  CATPolyPPTopologicalSpaceR3 * m_TopoSpaceR3;
  CATPolyPPTopologicalSpaceSO3 * m_TopoSpaceSO3;
  CATPolyPPCartesianProduct * m_Space;
  //CATPolyPPCartesianProduct6D * m_Space6D;
  CATMathTransformation M_Model2RRT;
  CATMathTransformation M_RRT2Model;
  CATMathTransformation M_Model2Trans;
  CATMathTransformation M_Trans2Model;
  CATMathTransformation M_Model2Rot;
  CATMathTransformation M_Rot2Model;
  CATMathTransformation M_Rot2Trans;
  CATMathTransformation M_Trans2Rot;

  CATMathBox m_MovingBox;
  CATMathBox m_MovingBoxInConfigSpace;
private:
  CATMathAxis m_AxisForTranslations;
  CATMathAxis m_AxisForRotations;
  CATPolyUniformRandomGenerator m_BaseGenerator;
  CATBoolean m_limitshavebeenset;
};

/** @} */
#endif

