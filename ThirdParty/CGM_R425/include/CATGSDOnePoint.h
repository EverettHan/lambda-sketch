/*-*-c++-*-*/
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2000
//=============================================================================
//
// CATGSDOnePoint :
// Implementation class for global deformation point-wise. 
//
//=============================================================================
// Nov 2000  Creation                          Daniel Johansson  
//=============================================================================

#ifndef CATGSDOnePoint_H  
#define CATGSDOnePoint_H 

#include "CATGSDOnePoint.h"
#include "CATMathGridOfPoints.h"
#include "CATMathGridOfVectors.h"
#include "CATNurbsSurface.h"
#include "CATNurbsCurve.h"
#include "CATMathPoint.h"
#include "CATKnotVector.h"
#include "CATMath3x3Matrix.h" 
#include "CATMathMxNMatrix.h"
#include "CATMathMxNFullMatrix.h"
#include "CATMathNxNMatrix.h"
#include "CATMathVector.h"
#include "CATMathDirection.h"
#include "CATFrFUtiNurbs.h"
#include "CATGeometry.h"
#include "CATGSDBase.h"
#include "CATCGMVirtual.h"

class ExportedByFrFOpeSur CATGSDOnePoint : public CATCGMVirtual

{
public:

/**
 * Construktor 
 */
   CATGSDOnePoint (CATGSDBase *iAnaOpe, CATGSDBase  *iSynOpe ) ; 
   
/**
 *Destruktor
 */   
   virtual ~CATGSDOnePoint () ;

/**
 * After ANY change in the AnaOpe or SynOpe
 */
   void Update () ;

/**
 * Before Run(): 
 */
   void SetPoint( CATMathPoint *iPoint ) ;
   
/** 
 * Run returns 1 if ok, else 0.
 */   
   CATLONG32 Run () ;  
   
/**
 *  After Run() :
 */
   void GetPoint                    ( CATMathPoint  *oPoint ) ;
   void GetTransformedCanonicalAxes ( CATMathVector *oX, CATMathVector *oY, CATMathVector *oZ ) ; 
   void TransformDeriv              ( CATMathVector *iDeriv, CATMathVector *oDeriv ) ;  
   void TransformNormal             ( CATMathDirection *iNormal, CATMathDirection *oNormal ) ;

   // -------------------------------------------------------------------------
   
private:
   
   CATGSDBase *_AnaOpe, *_SynOpe ; 
};

#endif
