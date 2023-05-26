#ifndef CATExtrapParCornerTool_H
#define CATExtrapParCornerTool_H
// COPYRIGHT DASSAULT SYSTEMES 2000

#include "ParallelLight.h"


#include "CATTopDef.h"
#include "CATExtrapolParallelTool2.h"
#include "CATGeoFactory.h"
#include "CATCGMJournalList.h"
#include "CATVertex.h"


//
//--------------------------------------------------------------------------
//
class ExportedByParallelLight CATExtrapParCornerTool : public CATExtrapolParallelTool2
{
  CATCGMVirtualDeclareClass(CATExtrapParCornerTool);
 public:

  CATExtrapParCornerTool(CATGeoFactory * iGeoFactory, CATTopData * iData, CATDistanceTool * iDist, CATBody * iShFond);
  CATExtrapParCornerTool(CATGeoFactory * iGeoFactory, CATTopData * iData, CATICGMDistanceTool * iDist, CATBody * iShFond);
  virtual ~CATExtrapParCornerTool();


/** @nodoc */
  int ComputeExtrapolationPar( CATBody * Wire[2], 
                     CATLaw ** MapLaw1, CATLaw** MapLaw2,
										 CATBody * Parallel[2], CATBody* Extrap[2],
										 CATCGMJournalList * Rep, CATLONG32 WT[2]);

  int GetExtrapInfo();
  CATLONG32 GetConnexionInfo();

  void DeleteOverlap(CATGeoFactory * iFacto,CATTopData * iData,CATBody * iBodyPtImage,CATBody *& iCurvePar,CATVertex * iVxParallelExtremity);

 private:
  CATLONG32 _Connexion;

};

#endif




















