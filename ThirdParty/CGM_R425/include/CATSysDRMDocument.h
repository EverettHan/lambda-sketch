//*===========================================================================*
//* COPYRIGHT DASSAULT SYSTEMES 2006                                          *
//*===========================================================================*
//*                                                                           *
//*                                                                           *
//*  Usage Notes:                                                             *
//*===========================================================================*
//*  Creation juillet  2006                                  adt              *
//*===========================================================================*
#ifndef CATSYSDRMDOCUMENT_H
#define CATSYSDRMDOCUMENT_H

#if defined(__JS0DRMDOC)
#define ExportedByJS0DRMDOC DSYExport
#else
#define ExportedByJS0DRMDOC DSYImport
#endif
#include "DSYExport.h"

#include "CATSmartMutex.h"
#include "CATResourceLock.h"
#ifndef _TS_DRM
#include "CATBaseUnknown.h"
#else
#include "CATSysTSBaseUnknown.h"
#endif
#include "CATSysDRMHR.h"


#define DRM_R_OK	0x00000001
#define DRM_W_OK	0x00000002
#define CATDRMFORCEOPEN	2
#define CATDRMRETRIEVE	1
#define CATDRMDUP	0

class CATSysSimpleHashTable;
class CATIUExitDRMDocument;
class CATIUExitDRMILockBytes;
class CATIUExitDRMAuthorization;



class ExportedByJS0DRMDOC  CATSysDRMDocument : public 
#ifndef _TS_DRM
CATBaseUnknown
#else
CATSysTSBaseUnknown
#endif
{ 

  friend class CATSysDRMILB;
#ifndef _TS_DRM
  CATDeclareClass;
#else
  CATSysTSDeclareClass;
#endif

 public:
  HRESULT  __stdcall QueryInterface(const IID &iIID,  void **oPPV);
/**
 * Opens a document in the DRM context.
 * <br><b>Role</b>:Opens a document in a DRM context. This method has to be called
 * at the logical opening or creation of the document pointed by iDocumentID. 
 * It is decorallated from the physical opening of the document repository, it is
 * intended to signal the arrival of the document in session. 
 * @param iDocumentID
 *      Pointer to the wide char string null terminated defining the document ID
 * @return
 *   <b>Legal values</b>:
 *   <br><tt> S_OK :</tt>on Success.
 *   <br><tt> STG_E_INVALIDNAME :</tt> invalid name for the document.
 *   <br><tt> STG_E_INVALIDPARAMETER :</tt> DRM environment not set.
 *   <br><tt> STG_E_INSUFFICIENTMEMORY :</tt> no more memory to make the open.
*/
  static HRESULT Open (const CATUC2Bytes* iDocId);
 


  static HRESULT Open (const CATUC2Bytes* iDocId, CATSysDRMDocument **oDoc);


/**
 * Retrieves a document in the DRM context.
 * <br><b>Role</b>:Retrieves a document in a DRM context after its logical opening
 * @param iDocumentID
 *      Pointer to the wide char string null terminated defining the document ID
 * @param  oDoc
 *      Pointer on the DRMDocument to retrieved
 * @param  iMode
 *	Mode to know wether to try to open or just to retrieve the document.
 * @return
 *   <b>Legal values</b>:
 *   <br><tt> S_OK :</tt>on Success.
 *   <br><tt> STG_E_FILENOTFOUND:</tt> The document has never been opened.
 */
  static HRESULT GetDocument ( const CATUC2Bytes* iDocId, 
			       CATSysDRMDocument **oDoc,
			       DWORD iMode = CATDRMDUP);

/**
 * Checks rights on a document in the DRM context.
 * <br><b>Role</b>:Check rights on document in a DRM context. 
 * @param iDocumentID
 *      Pointer to the wide char string null terminated defining the document ID
 * @param iRightToCheck
 *      the rights to check.
 * @return
 *   <b>Legal values</b>:
 *   <br><tt> S_OK :</tt>on Success.
 *   <br><tt> STG_E_FILENOTFOUND:</tt> The document has never been opened.
*/
  static HRESULT IsGranted ( const CATUC2Bytes* iDocId, DWORD iRightToCheck);

/**
 * Closes a document in the DRM context.
 * <br><b>Role</b>:Cloes a document in a DRM context. This method has to be called
 * at the logical opening or creation of the document pointed by iDocumentID. 
 * It is decorallated from the physical opening of the document repository, it is
 * intended to signal the arrival of the document in session. 
 * @param iDocumentID
 *      Pointer to the wide char string null terminated defining the document ID
 * @return
 *   <b>Legal values</b>:
 *   <br><tt> S_OK :</tt>on Success.
 *   <br><tt> STG_E_FILENOTFOUND:</tt> The document has never been opened.
*/
  static HRESULT Close (const CATUC2Bytes* iDocId);

/**
 * Checks if the DRM is licensed.
 * <br><b>Role</b>:Check if the DRM is authorized in terms of licensing. 
 * @return
 *   <b>Legal values</b>:
 *   <br><tt> S_OK :</tt>on Success.
 *   <br><tt> S_FALSE:</tt> the license is not granted.
*/
  static HRESULT IsDRMAuthorized ();

/**
 * Checks if a document is DRM enabled.
 * <br><b>Role</b>:Check if a given document is DRM protected.
 * @param iDocumentID
 *      Pointer to the wide char string null terminated defining the document ID
 * @return
 *   <b>Legal values</b>:
 *   <br><tt> S_OK :</tt>the document is DRM protected.
 *   <br><tt> S_FALSE:</tt> the document is not protected.
 *   <br><tt> STG_E_FILENOTFOUND:</tt> the document is not in session.
*/
  static HRESULT IsDRMEnabled (const CATUC2Bytes* iDocId);


/**
 * Associates a DRM document with an other one.
 * <br><b>Role</b>:Associated a DRM document pointed by iDocId, and a previously 
 * already opened DRM document pointed by iBoundedDoc. The purpose is to apply 
 * the DRM of the Document pointed by iBoundedDoc to the document to be created 
 * under iDocId.
 * @param iDocumentID
 *      Pointer to the wide char string null terminated defining the document ID
 * @param iBoundedDoc
 *	Pointer to a CATSysDRMDocument object from which the DRM will be
 *	inheritated
 * @return
 *   <b>Legal values</b>:
 *   <br><tt> S_OK :</tt>the document is DRM protected.
 *   <br><tt> S_FALSE:</tt> the document is not protected.
 *   <br><tt> STG_E_FILENOTFOUND:</tt> the document is not in session.
*/
  static HRESULT AssociateDocument ( const CATUC2Bytes* iDocId,  
				     CATSysDRMDocument *iBoundedDoc);

/**
 * Associates a DRM document with an other one.
 * <br><b>Role</b>:Associated a DRM document pointed by iDocId, and a previously 
 * already opened DRM document pointed by iBoundedDoc. The purpose is to apply 
 * the DRM of the Document pointed by iBoundedDoc to the document to be created 
 * under iDocId.
 * @param iDocumentID
 *      Pointer to the wide char string null terminated defining the document ID
 * @param iBoundedDoc
 *	Pointer to the wide char string null terminated defining the document ID
 *      from which the DRM will be inheritated
 * @return
 *   <b>Legal values</b>:
 *   <br><tt> S_OK :</tt>the document is DRM protected.
 *   <br><tt> S_FALSE:</tt> the document is not protected.
 *   <br><tt> STG_E_FILENOTFOUND:</tt> the document is not in session.
*/
  static HRESULT AssociateDocument ( const CATUC2Bytes* iDocId, 
				     const CATUC2Bytes* iBoundDocId);



/**
 * Transfers the rights of a DRM document to an other one.
 * <br><b>Role</b>:Transfers the right of a DRM document pointed by iDocId1 to
 * a new DRM document pointed by iDocId2. The purpose is to apply 
 * the DRM of the first Document to the second one, if it is not already 
 * protected.
 * @param iDocID1
 *      Pointer to the wide char string null terminated defining the document ID
 * @param iDocId2
 *	Pointer to the wide char string null terminated defining the document ID
 *      from which the DRM will be inheritated
 * @return
 *   <b>Legal values</b>:
 *   <br><tt> S_OK :</tt>the document is DRM protected.
 *   <br><tt> STG_E_INVALIDPARAMETER:</tt> the second document is already protected.
 *   <br><tt> STG_E_FILENOTFOUND:</tt> the document is not in session.
*/
  static HRESULT TransfertRights(const CATUC2Bytes* iDocId1, 
				 const CATUC2Bytes* iDocId2);

  static HRESULT SetStorageName (const CATUC2Bytes* iDocId, 
				 const CATUC2Bytes* iNewDocId);

  static HRESULT CheckDocuments(DWORD iRights);

  const CATUC2Bytes*  GetStorageName ();
  HRESULT ReOpen ();
  ULONG ReleaseExtracted();

  static HRESULT GetPolicy ( DWORD iPolicy);

  static HRESULT CompareAuthorization(const CATUC2Bytes* iDocId1, 
				      const CATUC2Bytes* iDocId2);

 private :

  CATSysDRMDocument ( const CATUC2Bytes *iDocId, int mode );
  CATSysDRMDocument () 
#ifdef _TS_DRM
: CATSysTSBaseUnknown(true)
#endif
 {};
  virtual ~CATSysDRMDocument();
  
  unsigned int ComputeHashKey();
  static int Compare ( void *iDoc1, void *iDoc2);
  static unsigned int  Hash ( void * iDoc);
  static void Clean();
  static void _EnsureHashTbInit();


  unsigned int		_Hash;
  int			_Mode;
  int			_Encrypt;
  CATUC2Bytes *		_DRMDocId;
  CATUC2Bytes *		_DRMId;
  CATIUExitDRMAuthorization *_DRMDoc;
  CATSysDRMDocument *	_BoundDoc;
#ifndef _TS_DRM
  CATBaseUnknown *	_DRMDrv;
#else
  CATSysTSBaseUnknown *	_DRMDrv;
#endif
  // donnees globales
  static CATResourceLock		* _Lock;
  static CATSysSimpleHashTable *	_Tb;
};


#endif
