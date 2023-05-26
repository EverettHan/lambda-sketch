/**
* @level Private
* @usage U1
*/
#ifndef _CATOmbComponentLinkSetUnstreamer_H
#define _CATOmbComponentLinkSetUnstreamer_H

#include "CATOmbLinkTraderForRestrictedAccess.h"
#include "IUnknown.h"
#include "CATDataType.h"
#include "CATFile.h"
#include "CATUnicodeString.h"
#include "CATOmbIDLinkCorrTable.h"
#include "CATComponentId.h"

class CATDocument;
class CATComponentId;
class CATOmbLink;
class CATOmbVirtualStorage;

/**
* class managing a set of PLM links
*/
class ExportedByCATOmbLinkTraderForRestrictedAccess  CATOmbComponentLinkSetUnstreamer
{
public:

  CATOmbComponentLinkSetUnstreamer (CATComponentId & iComId, CATDocument & iDocTarget):_ComId(iComId),_DocTarget(iDocTarget) {}
  ~CATOmbComponentLinkSetUnstreamer() {}

  const CATOmbLink * GetCorrLink (CATULONG32 iRefLinkID) {return _LinkID_NewLink.GetCorrLink(iRefLinkID);}
  
  HRESULT Load (CATOmbVirtualStorage & iStorage);

private:

  /* forbidden operations */
  CATOmbComponentLinkSetUnstreamer (CATOmbComponentLinkSetUnstreamer &);
  CATOmbComponentLinkSetUnstreamer& operator=(CATOmbComponentLinkSetUnstreamer&);

  CATComponentId _ComId;
  CATDocument& _DocTarget;
  CATOmbIDLinkCorrTable _LinkID_NewLink;
};

#endif
