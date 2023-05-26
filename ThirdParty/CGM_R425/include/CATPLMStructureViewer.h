#ifndef CATPLMStructureViewer_H
#define CATPLMStructureViewer_H
/* -*-c++-*- */// System
#include "CATPLMStructureViewer_respRJS.h"
#include "CATUnicodeString.h"
// ObjectModelerCollection
#include "CATOmxArray.h"
#include "CATOmxKeyString.h"
#include "CATOmxKeyValueBlock.h"
#include "CATOmxOHMap.h"
// CATPLMIdentificationAccess
#include "CATPLMID.h"
#include "CATPLMTypeH.h"
// CATPLMIdentification
#include "CATPLMSessionDataSourceAdapter.h"
#include "CATPLMStreamDefinition.h"
#include "CATOmbUsageAndExtensionDescriptor.h"


class CATPLMBag;
class CATIOmbPLMDataSourceBuilderForImportPreview;

struct relPtr
{
  CATOmxKeyString _relName;
  CATPLMID _relID;
};


class CATPLMStructureViewer;

class CATPLMStructureViewerDataSource final : public CATPLMSessionDataSourceAdapter
{
public:
  ExportedByCATPLMStructureViewer_respRJS CATPLMStructureViewerDataSource(CATPLMStructureViewer &ictx);
  ~CATPLMStructureViewerDataSource();


  HRESULT GetStatus(CATPLMSessionDataSourceStatus & oDataSourceStatus) override;
  HRESULT GetPLMID(CATPLMID & oPLMID)override;
  //  HRESULT GetCompletionLevel(CATPLMCompletionLevel & oCompletionLevel);
  HRESULT GetAssociatedObject(const CATString & iRelType, CATPLMID & oAssObjId);
  HRESULT GetSDList(CATLISTV(CATPLMStreamDefinition) & oSDList)override;
  HRESULT ListExtensionTypes(CATLISTV(CATPLMTypeId) & oLExtensionType)override;
  HRESULT GetAttributeBlock(const CATPLMTypeId & iExtensionType, CATOmxKeyValueBlock &oAttrBlock)override;
  HRESULT GetSystemAttributesBlock(CATOmxKeyValueBlock & oAttrBlock)override;
  //  HRESULT GetMemoryState(CATBinary & oSessionMemoryState);
  //  CATIPLMSessionCoarseMemoryState * GetCoarseMemoryState();
  HRESULT Close();

private:
  CATPLMStructureViewerDataSource();
  CATPLMStructureViewerDataSource(const CATPLMStructureViewerDataSource& iDS);
  CATPLMStructureViewerDataSource& operator =	(const CATPLMStructureViewerDataSource&);

  CATOmxKeyValueBlock _AttrList;
  CATPLMTypeH _Type;
  CATPLMID _Id;
  int    _nbRel;
  relPtr _Rel[2];
  CATPLMStreamDefinition _SD;
  CATPLMStructureViewer& _ctx;
};


class CATVVSUrl;
class ExportedByCATPLMStructureViewer_respRJS CATPLMDataSourceBuilder
{
public:
  virtual HRESULT GenerateDataSources(const CATVVSUrl &iUrl, CATPLMStructureViewer& iHelper) = 0;

protected:
  CATPLMDataSourceBuilder() {};
  virtual ~CATPLMDataSourceBuilder() {};

};

class ExportedByCATPLMStructureViewer_respRJS CATPLMStructureViewer : public CATBaseUnknown
{
  CATDeclareClass;

  friend class CATPLMStructureViewerDataSource;
public:
  CATPLMStructureViewer();
  ~CATPLMStructureViewer();
  HRESULT ExplodeStructureInSession(const CATVVSUrl &iUrl, CATOmbUsageAndExtensionDescriptor& iImporterDefinition, CATPLMBag &ioBag);
  HRESULT ExplodeInSession(const CATVVSUrl &iUrl, CATPLMBag &iBag, CATIOmbPLMDataSourceBuilderForImportPreview& iBuilder);
  HRESULT RegisterDataSource(CATPLMStructureViewerDataSource* iDs, CATBoolean iIsRoot);
  void ResetCurrent();
  CATBoolean HaveRoot() { return _Roots.Size() != 0; }

  void GetCurrentTypeH(CATPLMTypeH& oTypeH) { oTypeH = _CurrentType; };
  void SetCurrentTypeH(const CATPLMTypeH& iType) { _CurrentType = iType; }
  CATUnicodeString GetCurrentId() { return _CurrentLocalId; }
  void SetCurrentId(CATUnicodeString iLocalId) { _CurrentLocalId = iLocalId; }


  HRESULT ComputePLMID(CATPLMTypeH& iType, CATPLMID& ioId);
  HRESULT AddStreamDescriptor(int iFormat, CATUnicodeString iRole, CATUnicodeString iTypeLate, CATUnicodeString iPersistancyName, CATUnicodeString iPersistancyType, CATUnicodeString iProtocol, CATUnicodeString iSite, CATUnicodeString iIdentifier);
  HRESULT SetLinkFromWorkingId(const CATString& iRelType, const CATUnicodeString& iLocalID);

  HRESULT AddSimpleAttributeForWorkingID(CATOmxKeyString attId, CATOmxAny attVal);
private:
  HRESULT GetExplodedRoots(CATPLMBag &tempoBag);
  CATOmxOHMap <CATUnicodeString, CATPLMStructureViewerDataSource*, CATOmxDefaultCollecManager<CATUnicodeString>::manager, com_manager > _ObjList;
  CATOmxArray<CATPLMID> _Roots;

  CATUnicodeString _CurrentLocalId;
  CATOmxKeyValueBlock _CurrentAttrList;
  CATPLMTypeH _CurrentType;
  int    _CurrentRelIdx;
  relPtr _CurrentRel[2];
  CATPLMStreamDefinition _CurrentSD;
};

#endif


