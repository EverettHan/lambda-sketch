#ifndef CATExtrapParTangencyTool_H
#define CATExtrapParTangencyTool_H
// COPYRIGHT DASSAULT SYSTEMES 2000

#include "ParallelLight.h"

#include "CATTopDef.h"
#include "CATExtrapolParallelTool2.h"
#include "CATGeoFactory.h"
#include "CATCGMJournalList.h"
#include "CATMathVector.h"
class CATBody;
class CATVertex;
class CATMathPoint;
class CATDomain;
//
//--------------------------------------------------------------------------
//
class ExportedByParallelLight CATExtrapParTangencyTool : public CATExtrapolParallelTool2
{
  CATCGMVirtualDeclareClass(CATExtrapParTangencyTool);
 public:

   
  CATExtrapParTangencyTool( CATGeoFactory * iGeoFactory,
														CATTopData * iData,
														CATDistanceTool * iDist,
														CATBody * iShFond);
  CATExtrapParTangencyTool( CATGeoFactory * iGeoFactory,
    CATTopData * iData,
    CATICGMDistanceTool * iDist,
    CATBody * iShFond);
  virtual ~CATExtrapParTangencyTool();


/** @nodoc */
  int ComputeExtrapolationPar( CATBody * Wire[2], 
                     CATLaw ** MapLaw1, CATLaw** MapLaw2,
										 CATBody * Parallel[2], CATBody * Extrap[2],
                     CATCGMJournalList * Report, CATLONG32 WT[2]);
	
	int GetExtrapInfo();
  CATLONG32 GetConnexionInfo();

 protected:
   CATMathPoint _ExtParallel[2][2];

 private :

   CATLONG32 _Simplif;
   void CheckExtrap(CATGeoFactory * Facto, CATTopData * iData, CATBody * BuildVtx, 
                    CATBody *WireIni,CATBody * TabParallelIni,CATLONG32 toextrap,
                    CATBody * TabParallel, CATLONG32 & Authorized);
   void ComputeExtrapolTangency(CATVertex * iCurVtx,CATBody  * iOrigWire, CATLONG32 iext,CATMathVector & oDirToExtrap);
   void TestDegeneratedSolution (CATVertex * iCurVtx,CATBody  * iOrigWire, CATLONG32 iext,CATLONG32 & isdegenerated);
//   void ChooseExtrap(CATGeoFactory * iFacto,CATTopData * iData,CATBody ** BuildVtx,CATBody ** WireIni, CATBody **TabParallel, int & toextrap);

   //aov wk23 2005 start MacCabe Action
   CATBody * ExtrapolWireOnShell(CATGeoFactory * Facto,CATTopData * iData,CATCGMJournalList *& Report,
                                 CATBody * TabParallel[2],/*CATBody * ParallBody[2],*/CATVertex * Vertex[2],int iext);

   CATBody * ExtrapFromVertexAndDir(CATGeoFactory * Facto,CATTopData * iData,CATCGMJournalList *& Report,
                                    CATDomain * CurDom,CATVertex * CurVtx,/*CATBody * ParallBody[2],*/
                                    CATBody * TabWire[2],const CATMathVector & DirToExtrap,int iext);

   CATLONG32 CheckGapBetweenWireToExtrap(CATGeoFactory * Facto,CATTopData * iData,CATBody * TabParallel[2],
                                         /*CATBody * ParallBody[2],*/CATBody * volatile & BodyInters,
                                         const CATMathPoint & PointIni0,const CATMathPoint & PointIni1,CATBody * WireIni[2],
                                         double evallaw ,CATBody * volatile ContactBody[2],CATVertex * Vertex[2],
                                         int Mode=0);

   void CheckIfConnexion(CATGeoFactory * Facto,CATTopData * iData,CATCGMJournalList *& Report,
                         /*CATBody * ParallBody[2],*/CATBody * volatile & BodyInters,CATBody * volatile ContactBody[2],
                         int iselectsommet,CATBody * volatile ExtrapLim[2],CATBody *& BodInters1,
                         CATBody *& BodInters2);

   void IntersectExtrapolWithParallel(CATGeoFactory * Facto,CATTopData * iData,CATCGMJournalList *& Report,
                                      CATBody * TabParallel[2],CATBody * volatile & BodyInters,
                                      CATBody * volatile ExtrapLim[2],CATBody *& BodInters1,CATBody *& BodInters2);

   void RelimitateExtrapolation(CATGeoFactory * Facto,CATTopData * iData,CATCGMJournalList *& Report,
                                CATBody * TabParallel[2],CATBody * volatile & BodyInters,
                                CATBody * BodInters1,CATBody * BodInters2,CATBody * volatile ContactBody[2],
                                CATBody * volatile ExtrapLim[2],/*CATBody * ParallBody[2],*/CATBody * Extrap[2]);

   void SolveDegeneratedSituation(CATGeoFactory * Facto,CATTopData * iData,CATCGMJournalList *& Report,
                                  CATBody * TabParallel[2],/*CATBody * ParallBody[2],*/CATBody * TabWire[2],
                                  CATLONG32 WT[2],CATBody * TabExtrap[2],CATBody * Extrap[2]);

   void TestConnexion(CATGeoFactory * iFacto,CATTopData * iData,CATBody * Parallel,CATBody * ContactBody,int index);

   //aov wk23 2005 end MacCabe Action

   CATLONG32 _Connexion;
   CATLONG32 _ExtrapInfo[2];
   double    _LgthExtrap;
   CATBody * _ShFond;
   CATLONG32 _iextrap[2];
   CATLONG32 _Extrema1;
   CATLONG32 _Extrema2;
   CATLaw ** _MapLaws[2];
   CATBody * _ParallBody[2];

   //When a wire is removed from Parallel body it should also be removed from factory if it's not used anywhere else
   //We need to keep track of this domain pointer esp. to avoid leaks during recursive calls to ComputeExtrapolationPar
   CATDomain * _pDomToRemove;
};

#endif
