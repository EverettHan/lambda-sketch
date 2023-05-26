#ifndef CATCellManifoldAgentUtilitiesAdvBridge_H
#define CATCellManifoldAgentUtilitiesAdvBridge_H

#include "AdvOpeInfra.h"
#include "CATCGMNewArray.h"
#include "CATCellManifoldAgentUtilities.h"
#include "CATCellManifoldAgentUtilitiesBridge.h"
#include "ListPOfCATDeclarativeManifold.h"
#include "ListPOfCATFace.h"

class CATGeoFactory;
class CATSoftwareConfiguration;
class CATBody;
class CATPersistentCellInfra;
class CATCellManifoldPatternNavigator;
class CATFaceHashTable;

class ExportedByAdvOpeInfra CATCellManifoldAgentUtilitiesAdvBridge : public CATCellManifoldAgentUtilitiesBridge
{
public:
  CATCGMNewClassArrayDeclare;      // Pool allocation

  CATCellManifoldAgentUtilitiesAdvBridge();
  virtual ~CATCellManifoldAgentUtilitiesAdvBridge();

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

  double CallComputePerimeter (CATSoftwareConfiguration * iConfig, const CATFaceHashTable &iFaceHT);

  double CallComputeArea (CATSoftwareConfiguration * iConfig, const ListPOfCATFace &iFaces, double & oAbsoluteErrorEst);

  double CallDistanceMin(CATGeoFactory * iFactory, CATSoftwareConfiguration * iConfig, ListPOfCATCell & iCellsList1, ListPOfCATCell & iCellsList2);

private:
  CATCellManifoldAgentUtilities *_CellManifoldAgentUtilities;

};

extern "C" ExportedByAdvOpeInfra CATCellManifoldAgentUtilitiesAdvBridge * CATCreateCellManifoldAgentUtilitiesAdvBridge();

#endif 

