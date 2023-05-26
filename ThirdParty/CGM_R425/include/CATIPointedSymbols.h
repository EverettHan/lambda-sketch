/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
//  CATIPointedSymbols :
//		interface used to get or set a pointed symbol list
//  
//=============================================================================          
//
//==================================================================
//  Usage notes
//		INTERNAL USE ONLY 
//		-----------------
//
//   This interface has been implemented on CATDocument and CATDocumentProperty
//	 It is called only by CATSessionLink::ManageLink (ObjectSpecsModeler) and
//	 should not be used for other cases.
//	 It also enables to stream the root pointed symbols name list outside the document
//
//	slg July.98
//==================================================================
#ifndef CATIPointedSymbols_H
#define CATIPointedSymbols_H

/**
 * @level Private
 * @usage U3
 */

#include "CATBaseUnknown.h"
#include "CATObjectModelerBase.h"
//
#include "CATListOfCATUnicodeString.h"
#include "CATDocumentsInSession.h"
#include "sequence_octet.h"
#include "CATLISTP_CATIDocId.h"
//
class CATListValCATBaseUnknown_var;
class CATISymbolicLink_var;
class CATISymbolProperty;
class CATISymbolProperty_var;

extern ExportedByCATObjectModelerBase IID IID_CATIPointedSymbols ;

/** 
 * The filters that can be used to retrieve the pointed documents.
 * @param ANY
 *	All documents are considered.
 * @param FOUND
 *	Only the pointed documents that are found by the document locators are selected.
 * @param NOT_FOUND
 *	Only the pointed documents that are not found by the document locators are selected.
 * @see #GetPointedDocIds
 */
enum CATStatusOfPointedDocument{ ANY, FOUND, NOT_FOUND };

class ExportedByCATObjectModelerBase CATIPointedSymbols : public CATBaseUnknown
{
  CATDeclareInterface;

  public:
  
  // oPointedSymbols: output (list of CATISymbolProperty_var )
  virtual
    HRESULT GetPointedSymbols (CATListValCATBaseUnknown_var& oPointedSymbols) = 0;

  virtual
    HRESULT AddPointedSymbolList ( const CATISymbolicLink_var& iPointedSymbol, int iNeedToSave = 0) = 0;

  virtual
    HRESULT GetRootSymbolProperty ( const SEQUENCE(octet)& iName, CATISymbolProperty_var& oRootSymbolProp) = 0;
  virtual
    HRESULT GetPointedFileNames ( CATListOfCATUnicodeString& PointedFileNames) = 0;
  virtual
    HRESULT GetPointedDocIds ( CATListOfCATUnicodeString& PointedDocEnv,
             CATListOfCATUnicodeString& PointedDocId) = 0;
  
  /**
   * Retrieves the document identifiers that are refered by the link table.
   * @param oPointedDocIds
   *	The list of pointed document identifiers.
   * @param iStatus
   *	A filter on the pointed documents.
   * @return
   *	S_OK.
   * @see #CATStatusOfPointedDocument
   */
  virtual
    HRESULT GetPointedDocIds (CATLISTP(CATIDocId)& oPointedDocIds,
             CATStatusOfPointedDocument iStatus = ANY ) const = 0;

  virtual
    HRESULT ReplaceLink ( const CATUnicodeString& LastFilePath, const CATUnicodeString& NewPath) = 0;
  virtual
    HRESULT ReplaceLink ( CATIDocId* iLastDocId, CATIDocId* iNewDocId) = 0;
  // inter-document relations
  virtual
    HRESULT GetPointedDocuments ( const CATLISTP (CATDocument)*& PointedDocuments) = 0;
  virtual
    HRESULT GetPointingDocuments ( const CATLISTP (CATDocument)*& PointingDocuments) = 0;
  virtual
    HRESULT GetPointedDocumentsToSave ( const CATLISTP (CATDocument)*& PointedDocumentsToSave) = 0;	
  
  /**
   * Retrieves the document identifier that is refered by an index in the link table.
   * @param iIndex
   *	The index.
   * @param opiDocId
   *	The identifier of the pointed document.
   *	<br><b>Lifecycle rules</b>: Release() must be called on it after use.
   * @return
   *	An HRESULT value: 
   *	<dl>
   *		<dt>S_OK</dt>
   *			<dd>The pointed document has been found by the document locators.</dd>
   *		<dt>S_FALSE</dt>
   *			<dd>The pointed document has not been found by the document locators.
   *			<br>The identifier is the one stored in the pointing document.</dd>
   *		<dt>E_FAIL</dt>
   *			<dd>The identifier has not been retrieved: unknown index, null persistent counter.</dd>
   *	</dl>
   */
  virtual
    HRESULT GetPointedDocId( int iIndex, CATIDocId*& opiDocId ) const = 0;
};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIPointedSymbols , CATBaseUnknown ) ;


#endif
