//====================================================================
// Copyright Dassault Systemes Provence 2005, all rights reserved 
//====================================================================
//
// CATFrFCouplingPts:
// Object which represent a set of coupling points for a set of CURVES
//
//
//==================================================================
//
// Usage notes:
//  w (parametre du au couplage) = -1 <==> non calcule
//
//==========================================================================
// 17/04/2018 : NLD     : Mise au propre; smart indent
//                        XScaleRules
// April,2005 : ANR/FZA : Creation
//==========================================================================

#ifndef CATFrFCouplingPts_H
#define CATFrFCouplingPts_H

#include "CATFrFNetSurface.h"
#include "CATCrvParam.h"

class CATFrFPositionOnCCVSet;

//------------------------------------------------------------------
class ExportedByCATFrFNetSurface CATFrFCouplingPts 
{
  public :
                    CATFrFCouplingPts      (CATLONG32          NbOfPt      );

                    CATFrFCouplingPts      (CATLONG32          NbOfPt      ,
                                            CATLONG32        * NumCCV      ,
                                            CATLONG32        * NumCRV      ,
                                            CATCrvParam      * Param       );

                    CATFrFCouplingPts      (CATFrFCouplingPts* iCouplingPts); // copy constructor

                   ~CATFrFCouplingPts      ();

//-------------------  Methodes de lecture ------------------- 
  CATLONG32         GetDimCATFrFCouplingPts()
  {
   return _nbOfCCV;
  };
  CATCrvParam     * GetParamCouplingPts    (CATLONG32          num         );

  CATLONG32         GetNumCCVCouplingPts   (CATLONG32          num         );

  CATLONG32         GetNumCRVCouplingPts   (CATLONG32          num         );

  CATLONG32         GetTypeCCVCouplingPts  (CATLONG32          num         );

  CATLONG32         GetContinuity          (CATLONG32          num         );

  double            GetCurveLinearParam    ()
  {
   return _t;
  };

//-------------------  Methodes d ecriture ------------------- 
  void              SetContinuity         (CATLONG32           inum       ,
                                           CATLONG32           continuity );
/* Coverage
  void              SetTypeCCVCouplingPts (CATLONG32           inum       ,
                                           CATLONG32           type       );
*/
  void              SetAllParCouplingPts  (CATLONG32           num        ,
                                           CATLONG32           numCCV     ,
                                           CATLONG32           numCRV     ,
                                           CATCrvParam       & param      ,
                                           CATLONG32           kindOfLimit);

  // XScaleRules(NLD170418) t parametre de couplage, sur [0, 1]
  void              SetCurveLinearParam   (double              t          )
  {
   _t = t; 
  };

/* Coverage
//-------------------  Methodes de Merge ------------------- 
// merge des CATFrFCouplingPts this et pt2
//    si les dimensions
//       et les CurveLinearMapping values sont coherents
  CATFrFCouplingPts* CreateMerge(CATFrFCouplingPts *pt2);
//-------------------  Debug : Dump  ------------------- 
  void Dump();  
*/
//------------------- Datas -------------------  
 private :
   CATLONG32               _nbOfCCV;
   double                  _t;
   CATFrFPositionOnCCVSet* _PointsCouples ;
};
#endif



