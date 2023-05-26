//===================================================================
// COPYRIGHT Microsoft 2014/01/10
//===================================================================
//
//  CATPLMMLEngineSyncAsyncAdapter.h
//  Define  the  CATPLMMLEngineSyncAsyncAdapter interface
//
//===================================================================
// http://osmwebdsy/wiki/index.php/1-Modeler_Language_ML_or_MeuL:_Navigation
//===================================================================
// Usage notes:
// Need to implement interface CATIPLMMLEngineAsyncTaskCB using adapter CATPLMMLEngineSyncAsyncAdapter
// eg:
//class TSTCATPLMMLEngineAsyncTaskCB : public CATPLMMLEngineSyncAsyncAdapter
//{
//  CATDeclareClass;
//public:
//  TSTCATPLMMLEngineAsyncTaskCB();
//  ~TSTCATPLMMLEngineAsyncTaskCB();
//  HRESULT OnTaskCompleted();
//};
//
//CATImplementClass( TSTCATPLMMLEngineAsyncTaskCB,Implementation,CATPLMMLEngineSyncAsyncAdapter,CATnull );
//
//#include "TIE_CATIPLMMLEngineAsyncTaskCB.h"
//TIEchain_CATIPLMMLEngineAsyncTaskCB(TSTCATPLMMLEngineAsyncTaskCB);
//
//
//TSTCATPLMMLEngineAsyncTaskCB::TSTCATPLMMLEngineAsyncTaskCB()
//  :CATPLMMLEngineSyncAsyncAdapter(),
//{}
//
//TSTCATPLMMLEngineAsyncTaskCB::~TSTCATPLMMLEngineAsyncTaskCB()
//{}
//
//HRESULT TSTCATPLMMLEngineAsyncTaskCB::OnTaskCompleted()
//{
//  // your own code
//  // all methods provided in adapter CATPLMMLEngineSyncAsyncAdapter are available here.
//}
//===================================================================
// Jan 2014    Creation:  EPB
//=================================================================== 

#ifndef CATPLMMLEngineSyncAsyncAdapter_H
#define CATPLMMLEngineSyncAsyncAdapter_H

#include "CATPLMModelerLanguage.h"

#include "CATBaseUnknown.h"

#include "CATPLMMLOptions.h"
#include "CATPLMMLRelationStatus.h"
#include "CATPLMMLRelationSynchroStatus.h"
#include "CATPLMMLOptions.h"
#include "CATPLMMLOmxCollection.h"
#include "CATPLMMLPairAliasOrTypeNameObjPos.h"
#include "CATPLMMLListPairAliasOrTypeNameObjPos.h"

#include "CATUnicodeString.h"         // System PublicInterfaces
#include "CATString.h"                // System PublicInterfaces

#include "CATPLMID.h"
#include "CATPLMTypeH.h"
#include "CATPLMTypeHArray.h"
#include "CATPLMTypeHSet.h"

#include "CATOmxSR.h"
#include "CATOmxKeyString.h"
#include "CATOmxArray.h"

#include "CATLISTV_Declare.h"
class CATLISTV(CATPLMID);

class CATIPLMError;
class CATError;
class CATIPLMCompMetaDataService;
class CATPLMMLEngineParameters;
class CATPLMMLEngineParametersSimple;
class CATIPLMMLDicoNavNode;
class CATIPLMMLTable;
class CATOmxAny;
class CATPLMMLDicoAliases;
class CATIPLMMLFilterFunction;
class CATPLMMLNodeInfoIterator;
class CATIPLMCompRecordReadSet;
class CATPLMMLDicoAliasCustosTypesAttrs;
class CATIPLMExpandResultHandler;
class CATPLMMLTableManager;

class ExportedByCATPLMModelerLanguage CATPLMMLEngineSyncAsyncAdapter : public CATBaseUnknown
{
  friend class CATPLMMLEngineCompAdapter;
  friend class CATEPLMMLEngineCompDbgAdapter;
  friend class TSTCATPLMMLEngineAsyncTaskCB;
public:
  CATPLMMLEngineSyncAsyncAdapter();
  virtual ~CATPLMMLEngineSyncAsyncAdapter();

  HRESULT ListNode(CATPLMMLNodeInfoIterator& oIterator);

  // AddRef made on ipPostFilteringFunc
  HRESULT ApplyPostFiltering(CATIPLMMLFilterFunction* ipPostFilteringFunc);

  int GetNbOfLines();

  HRESULT GetNbOfPlmid( const CATString & iAliasOrTypeName,
    int iLineNb,
    int&  oNbOfObjPlmid );

  HRESULT GetPlmid( const CATString & iAttrIdentifier,
    int iLineNb,
    int iObjectNb,
    CATPLMID & oPlmid);

  HRESULT ListExtension( const CATString & iAliasOrTypeName,
                                 int iLineNb,
                                 int iObjectNb,
                                 CATPLMTypeHSet& olType);

  HRESULT ListExtension( const CATString & iAliasOrTypeName,
                                 int iLineNb,
                                 int iObjectNb,
                                 CATPLMTypeHArray& olType);

  HRESULT GetNbOfObjects( const CATString & iAttrIdentifier,
    int iLineNb,
    int & oNbOfObjects);

  HRESULT GetAttributeValue(  const CATString & iAttrIdentifier,
    int iLineNb,
    int iObjectNb,
    CATOmxKeyString & oAttrKey,
    CATOmxAny & oAttrValue);

  HRESULT GetNbOfRel(  const CATString & iRelIdentifier,
    int iLineNb,
    int & oNbOfRelation);

  HRESULT GetRelIndex(  const CATString & iRelIdentifier,
    int iLineNb,
    int iAbsolutePosition,
    CATULONG32& oIndex);

  HRESULT GetRelStatus( const CATString & iRelIdentifier,
    int iLineNb,
    int iAbsolutePosition,
    CATPLMMLRelationStatus & oRelationStatus,
    CATPLMMLRelationSynchroStatus & oRelationSynchroStatus);

  HRESULT GetRelPointedComp(  const CATString & iRelIdentifier,
    int iLineNb,
    int iAbsolutePosition,
    CATLISTV(CATPLMID) & oListPlmid);

  HRESULT GetNbOfRel(  const CATString & iRelIdentifier,
    int iLineNb,
    int iPositionPointing,
    int & oNbOfRelation);

  HRESULT GetRelIndex(  const CATString & iRelIdentifier,
    int iLineNb,
    int iPositionPointing,
    int iPositionRelation,
    CATULONG32& oIndex);

  HRESULT GetRelStatus( const CATString & iRelIdentifier,
    int iLineNb,
    int iPositionPointing,
    int iPositionRelation,
    CATPLMMLRelationStatus & oRelationStatus,
    CATPLMMLRelationSynchroStatus & oRelationSynchroStatus);

  HRESULT GetRelPointedComp(  const CATString & iRelIdentifier,
    int iLineNb,
    int iPositionPointing,
    int iPositionRelation,
    CATLISTV(CATPLMID) & oListPlmid);

  HRESULT GetPathFromRoot(  const CATString & iAttrIdentifier,
                                    int iLineNb,
                                    int iObjectNb,
                                    CATLISTV(CATPLMID) & oListPlmid );

  HRESULT GetPathFromRoot(  const CATString & iAttrIdentifier,
                                    int iLineNb,
                                    int iObjectNb,
                                    CATPLMMLListPairAliasOrTypeNameObjPos& oLPairAliasOrTypeNameObjPos);

  HRESULT GetPathFromKey( const CATString & iAttrIdentifier,
                                  int iLineNb,
                                  int iObjectNb,
                                  CATLISTV(CATPLMID) & oListPlmid);

  HRESULT GetPathFromKey( const CATString & iAttrIdentifier,
                                  int iLineNb,
                                  int iObjectNb,
                                  CATPLMMLListPairAliasOrTypeNameObjPos& oLPairAliasOrTypeNameObjPos);

  HRESULT _SetRootNode(CATIPLMMLDicoNavNode* ipRootNode);
  HRESULT _SetTable(CATIPLMMLTable* ipTable);

private:
  /**
  * <br><b>Role</b>: 
  * @param opRootNode [out,CATBaseUnknown#Release]
  * 
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  HRESULT _GetRootNode(CATIPLMMLDicoNavNode*& opRootNode);

  // no AddRef
  HRESULT _GetTableOptim(CATIPLMMLTable*& opTable);

  CATPLMMLEngineSyncAsyncAdapter (CATPLMMLEngineSyncAsyncAdapter &);
  CATPLMMLEngineSyncAsyncAdapter& operator=(CATPLMMLEngineSyncAsyncAdapter&);

  CATOmxSR<CATIPLMMLDicoNavNode> _spRootNode;
  CATPLMMLTableManager* _pTableMngr;
};

#endif

