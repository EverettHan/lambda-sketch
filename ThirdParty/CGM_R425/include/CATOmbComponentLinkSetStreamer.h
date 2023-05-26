/**
* @level Private
* @usage U1
*/
#ifndef _CATOmbComponentLinkSetStreamer_H
#define _CATOmbComponentLinkSetStreamer_H

#include "CATOmbLinkTraderForRestrictedAccess.h"
#include "CATBoolean.h"
#include "CATListPV.h"
#include "CATDataType.h"
#include "CATOmbLinkIDCorrTable.h"
#include "CATOmxSR.h"
#include "CATListOfCATOmbLink.h"

class CATOmbLink;
class CATComponentId;
class CATDocument;
class CATOmbLinkSource;
class CATOmbComponentLinkTable;
class CATDocumentProperty;
class CATOmbVirtualStorage;


/**
* class managing a set of PLM links
*/
class ExportedByCATOmbLinkTraderForRestrictedAccess  CATOmbComponentLinkSetStreamer
{
public:
  CATOmbComponentLinkSetStreamer() :_CLT(nullptr) {}

  CATBoolean IsEmpty();

  HRESULT Append(CATOmbLink & iLink);

  CATULONG32 GetCorrID(const CATOmbLink & iRefLink) const;

  HRESULT Save(CATOmbVirtualStorage & iStorage, bool iWithPLMRelations);

private:

  CATDocumentProperty & DocProperty();

  /* forbidden operations */
  CATOmbComponentLinkSetStreamer(CATOmbComponentLinkSetStreamer &);
  CATOmbComponentLinkSetStreamer & operator=(CATOmbComponentLinkSetStreamer &);

  CATOmbLinkIDCorrTable     _LinkIDCorrTable;
  CATOmbComponentLinkTable * _CLT;
  CATListPtrCATOmbLink     _Links;
  CATOmxSR<CATDocumentProperty> _DocProperty;
};

#endif
