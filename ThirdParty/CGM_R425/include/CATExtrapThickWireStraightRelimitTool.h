#ifndef CATExtrapThickWireStraightRelimitTool_H
#define CATExtrapThickWireStraightRelimitTool_H
// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATTopDef.h"
#include "CATExtrapolParallelTool.h"
#include "CATExtrapParTangencyTool.h"
#include "CATExtrapParCornerTool.h"
#include "CATGeoFactory.h"
#include "CATCGMJournalList.h"
#include "CATMathVector.h"

class CATMathPoint;

//
//--------------------------------------------------------------------------
//
class CATExtrapThickWireStraightRelimitTool : public CATExtrapParTangencyTool
{
 public:

  CATExtrapThickWireStraightRelimitTool(CATGeoFactory * iGeoFactory, CATTopData * iData, CATDistanceTool * iDist, CATBody * iShFond);
  CATExtrapThickWireStraightRelimitTool(CATGeoFactory * iGeoFactory, CATTopData * iData, CATICGMDistanceTool * iDist, CATBody * iShFond);
  virtual ~CATExtrapThickWireStraightRelimitTool();


/** @nodoc */
  
  int ComputeExtrapolationPar( CATBody * Wire[2], 
                     CATLaw ** MapLaw1, CATLaw** MapLaw2,
										 CATBody * Parallel[2], CATBody* Extrap[2],
										 CATCGMJournalList * Rep, CATLONG32 WT[2]);

  int GetExtrapInfo();
//  CATLONG32 GetConnexionInfo();

  // void DeleteOverlap(CATGeoFactory * iFacto,CATTopData * iData,CATBody * iBodyPtImage,CATBody *& iCurvePar,CATVertex * iVxParallelExtremity);
/*
  void CheckExtrap(CATGeoFactory * Facto, CATTopData * iData, CATBody * BuildVtx, 
                    CATBody *WireIni,CATBody * TabParallelIni,CATLONG32 toextrap,
                    CATBody * TabParallel, CATLONG32 & Authorized);
void ComputeExtrapolTangency(CATVertex * iCurVtx,CATBody  * iOrigWire, CATLONG32 iext,CATMathVector & oDirToExtrap);
*/
 private:
   /*
   CATLONG32 _Connexion;
   CATMathPoint _ExtParallel[2][2];

   CATLONG32 _iextrap[2];
   CATLONG32 _Extrema1;
   CATLONG32 _Extrema2;
   
   CATLaw ** _MapLaws[2];

   double    _LgthExtrap;
*/

};

#endif




















