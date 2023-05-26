// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATDocLinkServices_H_
#define CATDocLinkServices_H_

/**
 * @level Private
 * @usage U1
 */

#include "CATObjectModelerBase.h"
#include "sequence_octet.h"
#include "sharedSequence_octet.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATDocumentsInSession.h"

class CATIDocDescriptor;
class CATIDocId;
class CATStorage;
class CATILinkableObject;
class CATDocumentProperty;

ExportedByCATObjectModelerBase
HRESULT CATCreateSequenceFromDocId(SEQUENCE(octet) & result, CATIDocId * iDocId);

ExportedByCATObjectModelerBase
HRESULT CATCreateDocIdFromSequence(CATIDocId ** result, const SEQUENCE(octet) & iSeq);

ExportedByCATObjectModelerBase
HRESULT CATCreateDocIdFromNameB(CATIDocId ** result, const SEQUENCE(octet) & iNameB);

ExportedByCATObjectModelerBase
HRESULT CATGetPtdDocInfosFromHint(CATUnicodeString & oDocEnv, CATUnicodeString & oDocType, CATUnicodeString & oDocId, const SEQUENCE(octet) & iHint);

ExportedByCATObjectModelerBase
HRESULT CATGetPtdDocInfosFromHint(const SEQUENCE(octet) & iHint,
  SHAREDSEQUENCE(octet) & oDocEnv,
  SHAREDSEQUENCE(octet) & oDocType,
  SHAREDSEQUENCE(octet) & oDocId);


ExportedByCATObjectModelerBase
HRESULT CATSplitDocIdSequence(const SEQUENCE(octet) & iSequence,
  SHAREDSEQUENCE(octet) & oVersion,
  SHAREDSEQUENCE(octet) & oEnvironment,
  SHAREDSEQUENCE(octet) & oDocType,
  SHAREDSEQUENCE(octet) & oIdentifier);

ExportedByCATObjectModelerBase
HRESULT CATAssembleDocIdSequence(SEQUENCE(octet) & oSequence,
  const SEQUENCE(octet) & iVersion,
  const SEQUENCE(octet) & iEnvironment,
  const SEQUENCE(octet) & iDocType,
  const SEQUENCE(octet) & iIdentifier);


class ExportedByCATObjectModelerBase CATDocLinkServices
{
public:

  static void UpdateUUIDOnLinks(CATBaseUnknown *);
  static void RemoveAssociatedSymbol(CATBaseUnknown *);

  // Returns documents pointing a list of documents and that will not be rerouted

  static HRESULT GetNotReroutedDocuments(CATLISTP(CATDocument) iPointedDocuments, CATLISTP(CATDocument) & oPointingDocuments);

  // restricted USE for FBDI FTA Product
  // Service to copy a CATDocumentProperty (i.e. CATDocument external link table) from a file to a CATDocument that 
  // is not initialized (NO CATInit->Init(1))
  // iDocTo : NOT initialized document where to copy CATDocumentProperty
  // iDocNameFrom: File Path Name where to find existing CATDocumentProperty to copy 
  static HRESULT CopyDocumentPropertyInDoc(CATDocument & iDocTo, CATUnicodeString & iDocNameFrom);
};



#endif


