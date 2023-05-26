
#ifndef __CATCleanerServices_h__
#define __CATCleanerServices_h__ 3 // Version number.

// COPYRIGHT DASSAULT SYSTEMES  1999
//=============================================================================
//
// CATCleanerServices:
//     
//      Updates the persist counter of the links
//
//=============================================================================
//	Usage Note :
//		these must be used ONLY by the cleaner
//		do not use them for any other purpose : you'll damage datas
//
//=============================================================================
// August 99   Creation                                mbv
//=============================================================================

/**
 * @level Private
 * @usage U1
 */

#include "AC0XXLNK.h"
#include "CATBaseUnknown.h"
#include "CATListOfInt.h"
#include "booleanDef.h"
#include "sequence_octet.h"

class CATIDocLinkManager;
class CATISymbolProperty;
class CATDocument;

enum CounterType
{
  SessionCounter,
  PersistCounter,
  SessionCounterForSave,
  PersistCounterForSave
};

// get counters
ExportedByAC0XXLNK HRESULT CATGetIndexCounter(CATIDocLinkManager * iLinkManager, int iIndex, CounterType iCounterType, int & oCounter);

// get session index
ExportedByAC0XXLNK int GetSessionIndexCount(CATIDocLinkManager * LinkManager, int Index);

// update persist index
ExportedByAC0XXLNK int GetPersistIndexCount(CATIDocLinkManager * LinkManager, int Index);
ExportedByAC0XXLNK HRESULT SetPersistIndexCount(CATIDocLinkManager * LinkManager, int Index, int count);

// retrieve SymbolProperty from Index and LinkManager
ExportedByAC0XXLNK CATISymbolProperty * RetrieveSymbolProperty(CATIDocLinkManager * LinkManager, int Index);

// update counters and upgrade version on SymbolProperties
ExportedByAC0XXLNK HRESULT CATSetLinksCounters(const CATDocument * iDocument,
  const CATListOfInt & iCounters,
  CATListOfInt * oModifiedIndexes = NULL,
  boolean iCheckOnly = FALSE,
  CATListOfInt * oUnexistingIndexes = NULL);

ExportedByAC0XXLNK HRESULT CATRegenerateIndex(const CATDocument * iDocument, int iIndex,
  const SEQUENCE(octet) & iCompleteName,
  int iNeedToSave = 0);

// get counters on SymbolProperties
ExportedByAC0XXLNK HRESULT CATGetLinksCounters(const CATDocument * iDocument, CATListOfInt & oCounters);

ExportedByAC0XXLNK void RemoveDocLinkRelation(CATDocument * iPting_Document, CATDocument & iPted_Document);

ExportedByAC0XXLNK HRESULT IsRelationshipSet(CATDocument * iPting_Document, CATDocument * iPted_Document, int iIdx, boolean SavingMode = FALSE);

// Tests if a link will be streamed during marshalling.
// Returns E_FAIL if failure.
ExportedByAC0XXLNK HRESULT IndexToBeStreamed(CATIDocLinkManager * ipiDocLinkManager,
  int iIndex,
  CATBoolean & oToBeStreamed);

#include "CATIDocId.h"
#include "CATSysMacros.h"
#include "CATDocument.h"

struct CATOmbLinksTableEntry
{
  int m_IndexInTable;
  int m_PersistCounter;
  CATIDocId * m_PointedDocId;
  CATDocument * m_PointedDocument;
  int m_ToBeStreamed;
  inline CATOmbLinksTableEntry() : m_PointedDocId(0), m_PointedDocument(0) { m_IndexInTable = m_PersistCounter = 0; }
  inline ~CATOmbLinksTableEntry() { CATSysReleasePtr(m_PointedDocId); CATSysReleasePtr(m_PointedDocument); }
};

struct CATOmbLinksTableEntryArray
{
  CATOmbLinksTableEntry * m_Array;
  unsigned int m_Size;
  inline CATOmbLinksTableEntryArray() : m_Array(0) { m_Size = 0; }
  inline ~CATOmbLinksTableEntryArray() { CATSysDeleteTab(m_Array); m_Size = 0; }
};

HRESULT ExportedByAC0XXLNK CATOmbGetLinksTableInfo(const CATDocument & iDocument, CATOmbLinksTableEntryArray & opInfo);


struct SymbolErrorsForDUA
{
  unsigned short ghostSymbol : 1;
  unsigned short completeNameToPLM : 1;
};
HRESULT ExportedByAC0XXLNK CATOmbGetSymbolErrorsForDUA(CATIDocLinkManager * piLinkManager, int iIndex, SymbolErrorsForDUA & oErrors);


#endif // __CATCleanerServices_h__
