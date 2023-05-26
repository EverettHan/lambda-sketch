/* -*-c++-*- */
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2004
//=============================================================================

/**
* @level Protected
* @usage U1
*/

#ifndef CATOmbPCSServices_H
#define CATOmbPCSServices_H

#include "AC0XXLNK.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"
#include "CATListValCATOmbTupleUserIdLateTypeSize.h"
#include "CATDataType.h"
#include "CATOmxCollecManager.h"
#include "CATOmxDefaultCollecManager.h"
#include "CATOmxSR.h"
#include "CATOmyCioUrlUsageCtx.h"
#include "CATOmxArray.h"
class CATDocument;
class CATUnicodeString;
class CATStorage;
class CATComponentId;
class CATOmbLoadableDataUniqueKey;
class CATDocument;
class CATPLMID_Any;
class CATPLMID;

class ExportedByAC0XXLNK IDURLCouple2
{
public:
  IDURLCouple2();
  IDURLCouple2(const IDURLCouple2& copy);
  IDURLCouple2(const CATOmxSR<CATBaseUnknown>& iId, const CATOmxSR<CATOmyCioUrlUsageCtx>& iUrl, CATBoolean iValid);
  HRESULT GetPLMID(CATPLMID& thePlmid) const;
  HRESULT GetPhysicalID(CATUuid& thePhysicalUuid) const;
  
  CATOmxSR<CATBaseUnknown>& GetId();
  CATOmxSR<CATOmyCioUrlUsageCtx>& GetUrl();
  CATBoolean GetValidity();
  void SetId(const CATOmxSR<CATBaseUnknown> & iId);
  void SetUrl(const CATOmxSR<CATOmyCioUrlUsageCtx> & iUrl);
  void SetValidity(CATBoolean iValid);
private:
  CATOmxSR<CATBaseUnknown> m_Id;
  CATOmxSR<CATOmyCioUrlUsageCtx> m_url;
  CATBoolean m_Valid;//sera à FALSE si le composant n'est plus en PLM_Mode
};

template<> CATOmxCollecManager& CATOmxDefaultCollecManager<IDURLCouple2>::manager();

class ExportedByAC0XXLNK CATOmbPCSServices
{
public :
  /**NOT IMPL*/
  static HRESULT IsOverallCostOfDocumentProjectionAbovePcsAcceptance(CATDocument& iDocument,CATBoolean& oIsExpensive);  
  /**NOT IMPL*/
  static HRESULT RetrieveDocumentAndContainersPersistencySize(const CATUnicodeString &iFilePath, CATLONG64 &oDocumentSize, CATLISTV(CATOmbTupleUserIdLateTypeSize) &oList);  

  /**
   * Scans linearily input keys until a loaded CATDocument can be found on corresponding stream descriptor.
   * @param iCID
   *   Component to scan
   * @param iKeys
   *   An array if CATOmbLoadableDataUniqueKey
   * @param iKeysSize
   *   Number of elements in iKeys array
   * @param oDocument
   *   found CATDocument (not AddRef'ed)
   * @return
   *   >= 0
   *     index in iKeys of found CATDocument
   *   -1
   *     no loaded document found
   *   else
   *     invalid args or error
   *
   * Usage:
   * CATBaseUnknown* component;
   * static const CATOmbLoadableDataUniqueKey keys[] = 
   * {
   *   CATOmbLoadableDataUniqueKey(CATOmbStreamDescriptorFormat_Authoring,    NULL,         NULL),
   *   CATOmbLoadableDataUniqueKey(CATOmbStreamDescriptorFormat_Authoring,    "CATIAV5INV6",NULL),
   *   CATOmbLoadableDataUniqueKey(CATOmbStreamDescriptorFormat_AuthoringVisu, NULL,        NULL),
   * };
   * CATDocument* doc;
   * int index = CATOmbPCSServices::GetFirstLoadedDocumentWithPriority(component,keys,sizeof(keys)/sizeof(*keys),doc);
   * if(index>=0)
   * {
   * }
   */
  static int GetFirstLoadedDocumentWithPriority(const CATComponentId& iCID,const CATOmbLoadableDataUniqueKey* iKeys,int iKeysSize,CATDocument*& oDocument);
  /**
  * Specific HHI demo
  * provide the corresponding server url that would be accessed while loading the RepRef in a specific VisuMode or IndexMode
  * usage
  * You build a list IDURLCouple according to the list of ComponentId (ListOfCmponentIDs) you want to process
  *   CATOmxArray<IDURLCouple> mylist;
  *  for(int i=0;i<nComponents;i++)
  *  {
  *    IDURLCouple toadd;
  *    toadd.m_Id=ListOfCmponentIDs[i];
  *    mylist.Append(toadd);
  *  }
  *
  *  HRESULT HR=CATOmbPCSServices::FillTheIDURLCouplesForVisuMode(mylist);
  *  if(SUCCEEDED(HR))
  *  {
  *    ...
  *  }
  */

  static HRESULT FillTheIDURLCouplesForVisuMode2(CATOmxArray<IDURLCouple2>& iList);
  static HRESULT GetURLForVisuMode2(CATBaseUnknown* iComponent,CATOmxSR<CATOmyCioUrlUsageCtx>& oURL);
  static HRESULT LoadAuthoringDocument(CATBaseUnknown* iComponent);
};


#endif


