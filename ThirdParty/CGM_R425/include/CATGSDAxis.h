/*-*-c++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 1998
//=====================================================================
//
// GlobDef object for MOVE :
//
//=====================================================================
// Usage notes:
//
//=====================================================================
// Feb 99   Creation                         D. Johansson
//=====================================================================

#ifndef CATGSDAxis_H  
#define CATGSDAxis_H 


#include <stdlib.h>
#include "CATMathVector.h"
#include "CATMathDirection.h"
#include "CATMathPoint.h"
#include "FrFOpeSur.h"
#include "CATMathDirection.h"
#include "CATMathAxis.h"
#include "CATGSDBase.h"
#include "CATGeoFactory.h"
class CATSoftwareConfiguration;

class  ExportedByFrFOpeSur CATGSDAxis : public CATGSDBase 

{  
public: 
  
  //===================================================================
  // Constructor:
  //===================================================================

  CATGSDAxis (      CATGeoFactory             * ifactory ,
                    CATSoftwareConfiguration  * iSoftwareConfiguration,
              const CATMathAxis               * Axis )  ;

  //===================================================================
  // Destructor:
  //===================================================================
  
  virtual ~CATGSDAxis () {} ; 

  //===================================================================
  // Change the Axis.
  //===================================================================

  void SetOtherAxis (const CATMathAxis *Axis ) ;

  //===================================================================
  // Used for differentiation by finite differences :
  //===================================================================

  void VeryCloseAtK ( CATLONG32 yes ) {} // nothing in this obj.

  //===================================================================
  // 
  //===================================================================

  void InitializeK () {} // nothing in this obj.

  //===================================================================
  // Evaluation of K(u, v, w) :
  //===================================================================

  CATLONG32 EvaluateKuvw() ; 

  //===================================================================
  // Projection onto K(u, v, 0) : 
  //===================================================================

  CATLONG32 ProjOnKuv0 () ;

  CATLONG32 EvaluateAnalysisAtXYZ   (const CATMathPoint   &iXYZ,
                                           CATMathPoint   &oUVW,
                                           CATMathPoint   &oKUV0,
                                           CATMathVector  &oKu0, 
                                           CATMathVector  &oKv0, 
                                           CATMathVector  &oW, 
                                           CATMathVector  &oWu, 
                                           CATMathVector  &oWv ) ;
    
    CATLONG32 EvaluateSynthesisAtUVW(const CATMathPoint   &iUVW,
                                           CATMathPoint   &oKUV0,
                                           CATMathVector  &oKu0, 
                                           CATMathVector  &oKv0, 
                                           CATMathVector  &oW, 
                                           CATMathVector  &oWu, 
                                           CATMathVector  &oWv ) ;
  
private:
  
  CATMathPoint     _Origin      ;
  CATMathDirection _UAx, _VAx, _WAx;
  
  //===================================================================
  // u, v when the point is projected onto uv-plane in a projVec dir. 
  //===================================================================
  
  CATLONG32 Get_uvw (const CATMathPoint  &point   ,
                     const CATMathVector &projVec ,
                           double        &ou      ,
                           double        &ov      ,
                           double        &ow      ) ;
  
  
  
};

#endif  
