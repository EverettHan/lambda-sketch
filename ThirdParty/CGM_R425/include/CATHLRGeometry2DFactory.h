/* -*-C++-*-*/
#ifndef CATHLRGeometry2DFactory_H
#define CATHLRGeometry2DFactory_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1999
//
// CATHLRGeometry2DFactory 
//
// DESCRIPTION :
/**
 * Object used to create 2-dimensional object after projection by the HLR.
 */
//
//=============================================================================
// Abstract Class     : No
// Inline Functions   : Yes
//=============================================================================
//
// History
//
// Jan. 1999 JCH Creation            
// May  1999 HKL Creation de pcircles/pellipses limitees par un SetOfPoints
// Jun. 1999 HKL Use of curve parametrization for pspline creation
// Aug. 1999 HKL Added Remove method
// Sep. 1999 HLK Paraboles et Hyperboles
//
//=============================================================================

//=============================================================================
// For Windows NT
//-----------------------------------------------------------------------------
#include "HLRProject.h"

//=============================================================================
// For inheritance and other includes
//-----------------------------------------------------------------------------


//=============================================================================
// Forward declarations
//-----------------------------------------------------------------------------
class CATGeoFactory;
class CATMathPoint2D;
class CATMathSetOfPointsND;
class CATPlane;
class CATPCurve;
class CATSurParamReference;

//=============================================================================
// CLASS DEFINITION
//=============================================================================

class ExportedByHLRProject CATHLRGeometry2DFactory
{
public:
//============================================================
// CONSTRUCTORS AND DESTRUCTOR
//------------------------------------------------------------
/**
 * Default constructor.
 */
  CATHLRGeometry2DFactory(CATGeoFactory * iGeoFactory,
			  CATPlane      * iProjectionPlane);

/**
 * Destructor.
 */
  virtual ~CATHLRGeometry2DFactory();

//============================================================
// CREATION METHODS
//------------------------------------------------------------ 
/** Note that by default , all the methods return NULL  if no
 *  geometry has been created.
 */

/** Creates a line.
 */
  virtual CATPCurve * CreateLine(const CATMathPoint2D & iStartPoint, 
                                 const CATMathPoint2D & iEndPoint);

/** Creates a line and relimits it with 3D points (z is ignored).
 */
  virtual CATPCurve * CreateLine(const CATMathSetOfPointsND& iLimitPoints);

/** Creates a circle.
 */
  virtual CATPCurve * CreateCircle(const CATMathPoint2D & iCenter, double iRadius,
				   double iStartAngle, double iEndAngle);

/** Creates a circle and relimits by 3D points (z is ignored).
 */
  virtual CATPCurve * CreateCircle(const CATMathPoint2D & iCenter, double iRadius,
                                   const CATMathSetOfPointsND& iLimitPoints,
                                   int iIsComplete= 0);

/** Creates an ellipse.
 */
  virtual CATPCurve * CreateEllipse(const CATMathPoint2D & iCenter, double iMajorAxis,
				    double iMinorAxis, double iOffsetAngle,
				    double iStartAngle, double iEndAngle);

/** Creates an ellipse and relimits by 3D points (z is ignored)
 */
  virtual CATPCurve * CreateEllipse(const CATMathPoint2D & iCenter, 
                                    double iMajorAxis,
				    double iMinorAxis, 
                                    double iOffsetAngle,
                                    const CATMathSetOfPointsND& iLimitPoints,
                                    int iIsComplete=0);

/** Creates a parabola and relimits by 3D points (z is ignored)
 */
  virtual CATPCurve * CreateParabola(const CATMathPoint2D & iCenter, 
                                     double iOffsetAngle,
                                     const CATMathSetOfPointsND& iLimitPoints);

/** Creates an hyperbola and relimits by 3D points (z is ignored)
 */
  virtual CATPCurve * CreateHyperbola(const CATMathPoint2D & iCenter, 
                                      double iMajorAxis,
                                      double iMinorAxis, 
                                      double iOffsetAngle,
                                      const CATMathSetOfPointsND& iLimitPoints);

/** Creates a spline curve from an array of 3D points.
 */
  virtual CATPCurve * CreateSpline(const CATMathSetOfPointsND & iSetOfPoints,
                                   const double * iParameters = (const double*) 0);

/** Removes a created curve
 */
  void Remove (CATPCurve * iPCurveToRemove);

//============================================================
// INLINE METHODS
//------------------------------------------------------------
  inline CATGeoFactory * GetGeoFactory();

  inline CATPlane * GetPlane();
  
//============================================================
// INTERNAL DATA
//------------------------------------------------------------
protected:
// Pointer on the factory
  CATGeoFactory * _Factory;
  CATPlane      * _ProjectionPlane;
  const CATSurParamReference * _PlaneReference;

};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================

inline CATGeoFactory * CATHLRGeometry2DFactory::GetGeoFactory()
{
  return _Factory;
}

inline CATPlane * CATHLRGeometry2DFactory::GetPlane()
{
  return _ProjectionPlane;
}


#endif
