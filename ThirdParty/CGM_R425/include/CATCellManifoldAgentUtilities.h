#ifndef CATCellManifoldAgentUtilities_H
#define CATCellManifoldAgentUtilities_H

#include "CATErrorDef.h"

#include "AdvOpeInfra.h"
#include "CATCGMNewArray.h"
#include "CATMathDef.h"
#include "ListPOfCATDeclarativeManifold.h"
#include "ListPOfCATFace.h"
#include "CATListOfCATCells.h"

class CATGeoFactory;
class CATSoftwareConfiguration;
class CATBody;
class CATCellManifoldPatternNavigator;
class CATlsoDataCache;
class CATCGMJournalList;
class CATFaceHashTable;

class ExportedByAdvOpeInfra CATCellManifoldAgentUtilities
{
public:
  CATCGMNewClassArrayDeclare;      // Pool allocation

  CATCellManifoldAgentUtilities();
  virtual ~CATCellManifoldAgentUtilities();

  CATBody * UnExtrapolateBody(CATGeoFactory * iFactory, CATSoftwareConfiguration * iConfig, CATBody * iBody, CATLength iExtrapolationLength);
 
  CATBody * CallSplitShell(CATGeoFactory * iFactory, CATSoftwareConfiguration * iConfig, CATBody * iToSplitBody, CATBody * iSplittingBody, CATBoolean iPositiveSide);

  CATBody * GetReferenceExtrapolatedBody(CATGeoFactory * iFactory, CATSoftwareConfiguration * iConfig, CATBody * iOutputBody, CATCellManifoldPatternNavigator * iPatternNavigator);

  CATBody * GetReferenceExtrapolatedFaceBody(CATGeoFactory * iFactory, CATSoftwareConfiguration * iConfig, CATlsoDataCache * iLSODataCache, int iNumRefFace, CATBody * iOutputBody, CATCellManifoldPatternNavigator * iPatternNavigator);

  CATLONG32 DefineExplicitType(ListPOfCATFace & iInstanceFaceList, CATBody * iRefBody, CATBody * iInputBody, CATSoftwareConfiguration * iConfig);

  CATBody * CallCompatible(CATGeoFactory * iFactory, CATSoftwareConfiguration * iConfig, CATBody * iBody1, CATBody * iBody2, CATCGMJournalList *& ioJournal);

  CATBoolean CallIntersect(CATGeoFactory * iFactory, CATSoftwareConfiguration * iConfig, CATBody * iBody1, CATBody * iBody2);

  HRESULT    CallNeutralDraftDetection (CATBody                                 * iBody,
                                        CATSoftwareConfiguration                * iConfig,
                                        const ListPOfCATFace                    & iDraftedFaceList,                                                
                                        const ListPOfCATFace                    & iNeutralCandidateList,
                                        ListPOfCATFace                          & oResultFaceList);

  double    CallComputePerimeter (CATSoftwareConfiguration * iConfig, const CATFaceHashTable &iFaceHT);

  double    CallComputeArea (CATSoftwareConfiguration * iConfig, const ListPOfCATFace &iFaces, double & oAbsoluteErrorEst);

  double    CallDistanceMin(CATGeoFactory * iFactory, CATSoftwareConfiguration * iConfig, ListPOfCATCell & iCellsList1, ListPOfCATCell & iCellsList2);

private:
  

};
#endif 

