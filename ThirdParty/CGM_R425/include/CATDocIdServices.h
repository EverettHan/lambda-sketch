#ifndef CATDocIdServices_H
#define CATDocIdServices_H

// COPYRIGHT DASSAULT SYSTEMES 2003

/**
 * @level Protected 
 * @usage U1
 */

#include "AC0XXLNK.h"
#include "CATBoolean.h"
#include "CATUnicodeString.h"
#include "CATIDocId.h"

class CATVVSUrl;

class ExportedByAC0XXLNK CATDocIdServices
{
public:
  static unsigned int ComputeHashKey(CATIDocId &iDocId1); // Returns the key for hash table
  static CATBoolean AreEqual(CATIDocId &iDocId1, CATIDocId &iDocId2); // Returns TRUE if iDocId1 == iDocId2
  static int Compare(CATIDocId &iDocId1, CATIDocId &iDocId2); // Returns -1 if iDocId1 < iDocId2, 0 if iDocId1 == iDocId2, 1 if iDocId1 > iDocId2; NOTICE that it's slower than DocIdAreEqual()

  // For CATHashTable and CATSysSimpleHashTable
  static unsigned int HTComputeHashKey(void *ipDocId1); // BEWARE: ipDocId1 must be NULL or derive from CATIDocId (CATAssert())

  // For CATSysSimpleHashTable
  static int SimpHTCompare(void *ipDocId1, void *ipDocId2); // Returns 1 if DocId1 == DocId2 and 0 otherwise; BEWARE: ipDocId1 and ipDocId2 must be NULL or derive from CATIDocId (CATAssert())

    /**
   * METHODE StreamDocId
   * Stream the DocId of a document into a CATUnicodeString. The resulted Stream is under version control. Do not modify it.
   * @author BHG
   * @param iVersion The stream version
   * @param iDocId The DocId to Stream
   * @param oDocStream The DocId streamed
   */
  static HRESULT StreamDocId(CATIDocId& iDocId, CATUnicodeString& oDocStream);
  /**
   * METHODE UnstreamDocId
   * Recover a CATIDocId of a document in session from the given stream <B>iDocIdStreamed</B>
   * @author BHG
   * @param iVersion The stream version
   * @param iDocIdStreamed The string to be unstreamed
   * @param oDocId The recovered CATIDocId
   */
  static HRESULT UnstreamDocId(const CATUnicodeString iDocIdStreamed, CATIDocId*& oDocId);

  /**
   * Create a CATIDocId from a VVS url.
   * Created CATIDocId will be managed correctly only by a subset of Omb APIs (CATGetDocumentPropertySet for now).
   * DO NOT PASS iT TO OTHER APIS.
   */
  static CATIDocId_var CreateDocIdFromUrl(CATIDocEnvironment * iEnvironment, const CATVVSUrl& iIdentifier, const CATUnicodeString& iType="");
};

#endif
