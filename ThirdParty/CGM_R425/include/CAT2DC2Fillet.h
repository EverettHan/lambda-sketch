/*-*-c++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 2001 
//==========================================================================
//
// CAT2DC2Fillet:
//
//==========================================================================
//
// Usage notes:
// Consider a circular fillet between two surfaces. The fillet have a
// radius being 1.5 times the wanted radius.
//
// Now see the method "SetData(...)":
// iPt0, iPt5, iNo0 and iNo5 are supposed to be in a plane perpendicular to 
// the "spine" of the fillet such that
//  - iPt0 is on the fillet and the first surface 
//  - iPt5 is on the fillet and the second surface 
//  - iNo0 is the surface normal at iPr0.
//  - iNo0 is the surface normal at iPr5.
// The intersection of the plane with the surfaces yields two curves.
// iCurvature0 and  iCurvature5 are the curvatures of these curves at iPr0 
// and iPt5 respectively. The sign of a curvature is positive if the cores-
// ponding normal is pointing towards the correspondin gcentre of the oscu-
// lating circle.
//
// Now see the method "GetData(...)":
// The points iPt0, oPt1, oPt2, oPt3, oPt4, iPt5 are the "Bezier points" 
// of a curve with G2 contact at the surfaces and a wanted minimal radius.
//
//========================================================================== 
// 10/01     Creation                       Daniel Johansson
//========================================================================== 

#ifndef CAT2DC2Fillet_H
#define CAT2DC2Fillet_H
/* NDN Coverage 030106
#include "FrFOpeCrv.h"
#include "CATMathPoint.h"
#include "CATMathDirection.h"
#include "CATCGMVirtual.h"

//-----------------------------------------------------------------------------
class ExportedByFrFOpeCrv CAT2DC2Fillet : public CATCGMVirtual
{
public :
  
  virtual ~CAT2DC2Fillet() {} ;

  virtual void SetData( const CATMathPoint iPt0, 
                        const CATMathPoint iPt5,
                        const CATMathDirection iNo0,
                        const CATMathDirection iNo5,
                              double iCurvature0,
                              double iCurvature5 ) = 0 ;

//
// If  Initialize == 0, the new profile is supposed to be similar to the previous, i.e. having
// allmost the same curvatures, almost the same distances between iPt7 and iPt0 ... This saves
// computing time alot.
//

  virtual void SetData( const CATMathPoint iPt0, 
                        const CATMathPoint iPt7,
                        const CATMathDirection iNo0,
                        const CATMathDirection iNo7,
                              double iCurvature0,
                              double iCurvature7,
                              double iCurvVariation0,
                              double iCurvVariation7, 
                              CATLONG32   iInitialize = 1 ) = 0 ;

  // Finds the solution, and if not, returns zero.    
  virtual CATLONG32 Run() = 0 ;
  
  virtual void GetResult(CATMathPoint &oPt1, 
                         CATMathPoint &oPt2,
                         CATMathPoint &oPt3,
                         CATMathPoint &oPt4 ) = 0 ;

  virtual void GetResult(CATMathPoint &oPt1, 
                         CATMathPoint &oPt2,
                         CATMathPoint &oPt3,
                         CATMathPoint &oPt4,
                         CATMathPoint &oPt5,
                         CATMathPoint &oPt6 ) = 0 ;

  //returns the curve parameter of minimal radius
  virtual double GetParam() = 0 ;
  
};

//
// Creator 
//
ExportedByFrFOpeCrv CAT2DC2Fillet * CreateCAT2DC2Fillet () ;
*/
#endif
