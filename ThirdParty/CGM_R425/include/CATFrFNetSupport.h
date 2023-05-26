//====================================================================
// Copyright Dassault Systemes Provence 2005, all rights reserved 
//====================================================================
// CATFrFNetSupport:
// Utility for producing Loft from 2 sets of contours
//
//==========================================================================
// April,   2005 : ANR/FZA : Creation       (D'apres  CATLoftSupport )
//==========================================================================

#ifndef CATFrFNetSupport_H
#define CATFrFNetSupport_H
 
#include "CATFrFNetSurface.h"
#include "CATDataType.h" 
//=======================================================================
// Class Definition 
//=======================================================================
#include "CATDataType.h"
#include "CATBoolean.h"
class CATMathVector;

//-----------------------------------------------------------------------

class ExportedByCATFrFNetSurface CATFrFNetSupport
{
public :

                  CATFrFNetSupport           (const CATLONG32       iSize1 ,
                                              const CATLONG32       iSize2 );

                 ~CATFrFNetSupport();

//----------- Set Methods -----------------------------------------------

  int             SetOrdersAndTol            (const CATLONG32       iSize1 ,
                                                    CATLONG32     * iOrders,
                                                    double        * iG0Tol = 0,
                                                    double        * iG1Tol = 0,
                                                    double        * iG2Tol = 0);

  int             SetOrders                  (const CATLONG32       iRank  ,
                                              const CATLONG32       iOrders);

  int             SetOrdersForAdaptation     (const CATLONG32       iRank  ,
                                              const CATLONG32       iOrders);

  int             SetTolerance               (const CATLONG32       iRank  ,
                                              const double          iG0Tol ,  // = 0.001,
                                              const double          iG1Tol ,  // = 0.1  ,
                                              const double          iG2Tol ); // = 1.   );
 
  int             SetMainNormal              (const CATLONG32       indice1,
                                              const CATLONG32       indice2,
                                              const CATMathVector & iMainNormal);
 
  int             SetMainD1                  (const CATLONG32       indice1,
                                              const CATLONG32       indice2,
                                              const CATMathVector & iMainD1);
 
  int             SetMainD2                  (const CATLONG32       indice1,
                                              const CATLONG32       indice2,
                                              const CATMathVector & iMainD2);

  int             SetMainDerivOnSupport      (const CATLONG32       indice1,
                                              const CATLONG32       indice2,
                                              const CATLONG32       indice3,
                                              const CATMathVector & iMainDerivOnSupport);

  void            SetCaseInMono              (const CATLONG32       NbInternalGuideOrBase) ;

  //----------- Get Methods -----------------------------------------------

  CATLONG32     * GetOrders                  ();

  CATLONG32       GetOrders                  (const CATLONG32       iRank);
 
  CATLONG32       GetOrdersForAdaptation     (const CATLONG32       iRank);

  double        * GetTolerance               (const CATLONG32       iRank);
  
  CATLONG32       GetMaxOrder                ();

  CATMathVector   GetMainNormal              (const CATLONG32       indice1,
                                              const CATLONG32       indice2);
  
  CATMathVector   GetMainD1                  (const CATLONG32       indice1,
                                              const CATLONG32       indice2);

  CATMathVector   GetMainD2                  (const CATLONG32       indice1,
                                              const CATLONG32       indice2);
  
  CATMathVector * GetMainDerivOnSupport      (const CATLONG32       indice1,
                                              const CATLONG32       indice2);

  CATLONG32       GetCaseInMono              () ;

  void            SetLeftFirstDerIsComputed  (      CATBoolean      IsDerivative) ;
  void            SetRigthFirstDerIsComputed (      CATBoolean      IsDerivative) ;
  void            SetLeftSecondDerIsComputed (      CATBoolean      IsDerivative) ;
  void            SetRigthSecondDerIsComputed(      CATBoolean      IsDerivative) ;

  CATBoolean      GetLeftFirstDerIsComputed  () ;
  CATBoolean      GetRigthFirstDerIsComputed () ;
  CATBoolean      GetLeftSecondDerIsComputed () ;
  CATBoolean      GetRigthSecondDerIsComputed() ;

  void            SetAdaptation              (      CATBoolean      iadaptationIsNecessary) ;
  CATBoolean      GetAdaptation              () ;

  void            SetOrdreModified           (      CATBoolean      MaxOrderIsModified) ;
  CATBoolean      GetOrdreModified           () ;

  //----------------------------------------------------------------------

protected :

  void ComputeMaxOrder();

private :

  CATLONG32        _Size1;
  CATLONG32        _Size2;

  CATLONG32      * _Orders;
  CATLONG32      * _OrdersAdaptation ;

  CATMathVector ** _MainNormal;
  CATMathVector ** _MainD1;
  CATMathVector ** _MainD2;

  CATMathVector*** _MainDerivOnSupport;

  double        ** _Tolerance ;

  CATLONG32        _caseInMonoNet ;

  CATBoolean       _LeftFirstDerivative;
  CATBoolean       _RigthFirstDerivative;
  CATBoolean       _LeftSecondDerivative;
  CATBoolean       _RigthSecondDerivative;

  CATBoolean       _adaptationIsNecessary ;
  CATBoolean       _OrdreMaxModified ;

};
#endif
