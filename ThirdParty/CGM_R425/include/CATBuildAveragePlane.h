// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
//
// A class to build a average plane from a set of points (and a set of vector)
// 3 methodes can be used
// 1) Plane is defined by the inertia axis
// 2) Plane is defined by the flux (The points have to defined a closed polygone)
// 3) Plane is defined by normals, the maximum angle beetween plan Normal and the 
//    set of normals have to be minimum.
//
//=============================================================================
//
// Usage notes:
//
//=============================================================================
// May. 99    Creation                                        PMG
//=============================================================================
// 08/02/2002 : ktu : extention des cas ou les normal n'entrent pas dans une demi-sphere
//                   versionner au level 1;

#ifndef CATBuildAveragePlane_h
#define CATBuildAveragePlane_h

#include "CATMathSetOfPoints.h"
#include "CATMathSetOfVectors.h"
#include "CATLISTP_CATMathVector.h"
#include "CATMathPlane.h"
#include "CATMathLine.h"
#include "MathApprox.h"
#include "CATTolerance.h"

class CATSoftwareConfiguration;

class CATBuildAveragePlane
{
	public:

    virtual ~CATBuildAveragePlane();

		//Tolerance to defined degenerated case (Line,Point)
		virtual void SetTolerance(const double iSingularTolerance = 1.e-12) = 0;

		//To build a plane with a set of points.
		// Only the <iNbBoundsPoint> first items are used in the normal definition.
		// <ioption> can be :
		// _ 1 : Plane is built by Inertia methods
		// _ 2 : Plane is built by the flux methode Warning : The points have 
		//                       to be in order to define a "smooth" and closed polygone
		virtual void Build(const CATMathSetOfPoints & iPoints,
											 const CATLONG32 iNbBoundsPoint,
											 const short iOption = 1) = 0;
		
		
		// To build a plane with a Normal analysis methode
		// The Tolerance is defined in Radian
		virtual void Build(const CATMathSetOfVectors & iNormals,
				               const CATMathSetOfPoints  & iPoints ,
			                 const double iAngularTolerance = 0.01,
                       CATSoftwareConfiguration* iConfig = NULL) = 0;

		// To build a plane with a Tangente  analysis methode
		// it is an optimization methode, so a initialization is asked :  NormalInit
		// The Tolerance is defined in Radian
		virtual void Build(const CATMathSetOfVectors & iTangentes,
											 const CATMathSetOfPoints & iPoints,
							         const CATMathVector & NormalInit,
							         const double iTol,
                       CATSoftwareConfiguration* iConfig = NULL) = 0;
			  
		// Return if a plane is defined
		virtual CATBoolean IsPlane() const = 0;

		// Return the plane 
		virtual const CATMathPlane & Plane() const = 0;

		// Return if the points are on a line
		virtual CATBoolean IsLine() const = 0;

		// Returns the Line
		virtual const CATMathLine & Line() const = 0;

		// Returns if all the point are confused
		virtual CATBoolean IsPunctual() const = 0;

		// Returns the point
		virtual const CATMathPoint & Point() const = 0;

		// Return the paramtrics bounds of the projected points 
		// in the plane.
		virtual void MinMaxBox(double & Umin, double & Vmin, 
													 double & Umax, double & Vmax) const = 0;

		// Return the extremum distance beetween the points and the plane, on both plane 's side 
		virtual void MinMaxDistance(const CATMathSetOfPoints & Points, double& oFrontSide, double& oBackSide)const =0;

		// Return the maximum angle beetween the Set of Normal and the plane's normal
		virtual double GetMaxAngle() const = 0;

    // set optionnal sym Dir
    virtual void SetOtionnalSymDir( const CATMathVector & iDirSym )=0;
};

/** 
* Create a CATBuildAveragePlane instance

* @param iTolerance [in]
*   The Tolerance to use
* @param iLevel [in]
*   The code level to use
*   0 : History
*   1 : First level of corection
*   2 : Minimisation de l'aire (ie optimisation des axes U/V)
*   3 : Formule de Kahan pour le calcul du centre d'inertie.
*   4 : Evite les throw ...
*
* @return
*   a CATBuildAveragePlane object.
*
*/
ExportedByMathApprox CATBuildAveragePlane * CreateBuildAveragePlane(const CATTolerance & iTolerance, const int iLevel=0);

#endif
