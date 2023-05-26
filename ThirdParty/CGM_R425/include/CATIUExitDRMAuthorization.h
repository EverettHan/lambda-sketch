/* COPYRIGHT DASSAULT SYSTEMES 2006 */
/**
 * @CAA2Level L0
 * @CAA2Usage U5
 */

#ifndef CATIUExitDRMAuthorization_H
#define CATIUExitDRMAuthorization_H

#include "CATWTypes.h"
#include "CATErrorDef.h"
#include "CATSysDRMHR.h"
#include "CATUnicodeString.h"

#ifdef __JS0DRMDOC
#define ExportedByJS0DRMDOC  DSYExport
#else
#define ExportedByJS0DRMDOC  DSYImport
#endif
#include "DSYExport.h"



extern "C" const IID IID_CATIUExitDRMAuthorization;


/**
 * Interface to enable user specific DRM (digital rights management) mechanism on
 * documents.
 * <b>Role</b>: This interface is a user exit, that allows an user to augment the
 * security of its strategical documents by assigning security parameters inside 
 * the document itself and not only relying on a perimeter-based security.
 *
 * The CATIUExitDRMAuthorization user exit allows the following to the 
 * implementation  of the interface
 *       - being called when a document is logically opened in the V5 
 *       - being called when a document is logically closed in the V5 
 *       - give a authorization data that must be added to the document
 *       - receive the authorization data that is stored in the document if any
 *       - Grant of refuse access to the data depending on the authorization
 *          data  associated to the document  and the user authority/identity
 **/

class ExportedByJS0DRMDOC  CATIUExitDRMAuthorization : public IUnknown
{
public:
/**
 * Creates the DRM authorization container for a given document.
 * <br><b>Role</b>:Creates the DRM authorization context necessary to work on 
 * the document pointed by iDocumentID. This method will be called at the logical 
 * opening of the document. It must be thread safe.
 * @param iDocumentID
 *      Pointer to the wide char string null terminated defining the document ID
 * @return
 *   <b>Legal values</b>:
 *   <br><tt> S_OK :</tt>on Success.
 *   <br><tt> DRM_E_INVALIDNAME :</tt> invalid name for the document.
 *   <br><tt> DRM_E_INVALIDPARAMETER :</tt> DRM environment not set.
 *   <br><tt> DRM_E_DOCUMENTNOTFOUND :</tt> document can not be found.
 *   <br><tt> DRM_E_INSUFFICIENTMEMORY :</tt> no more memory to make the open.
 *   <br><tt> DRM_E_UNKNOWN :</tt> unexpected error.
*/
  virtual HRESULT DRMInitAuthorization( const CATUC2Bytes * iDocumentID)=0;

/**
 * Releases the DRM authorization container for a given document.
 * <br><b>Role</b>:Releases the DRM authorization context that has been created by
 * @href #DRMInitAuthorization
 * @return
 *   <b>Legal values</b>:
 *   <br><tt> S_OK :</tt>on Success.
 *   <br><tt> E_FAIL :</tt> error
 *   <br><tt> DRM_E_REVERTED :</tt> DRMReleaseAuthorization already called
 *   <br><tt> DRM_E_UNKNOWN :</tt> unexpected error.
*/
  virtual HRESULT DRMReleaseAuthorization( const CATUC2Bytes * iDocumentID)=0;


/**
 * Returns if the given right is granted or not.
 * <br><b>Role</b>:Returns if the given right is granted or not for the
 * authenticated user.
 * @param iRight
 *    The right to be checked. TBD
 *	READ, SAVE, PRINT, SAVEAS,  EXPORT, MODIFY_RIGHTS
 * @return
 *   <b>Legal values</b>:
 *   <br><tt> S_OK :</tt> if granted .
 *   <br><tt> DRM_E_ACCESSDENIED:</tt> right not granted.
 *   <br><tt> DRM_E_UNKNOWNRIGHT :</tt> unknown right
 *   <br><tt> DRM_E_UNKNOWN :</tt> unexpected error.
*/
  virtual HRESULT  IsGranted( DWORD iRightToCheck)=0;


/**
 * Creates the exportable authorization blob for a protected document.
 * <br><b>Role</b>: Creates the digital rights blobs for a protected document on
 * an exportable format. This information will be packed inside the DRM enabled
 * document during its saving phase. This data blob can be retrieved at opening
 * by @href #DRMImportAuthorization .
 * @param  oDRMAuthorization [out]
 *  Buffer where the protected exportable authorization data will be stored.
 * @param iDRMAuthorizationSize [out]
 *   the size of of the DRM authorization buffer.
 * @return
 *   <br><tt> S_OK :</tt>on Success.
 *   <br><tt> DRM_E_FAIL :</tt> problem during envelope generation.
 *   <br><tt> DRM_E_ACCESSDENIED:</tt> access to the document not granted.
 *   <br><tt> DRM_E_INVALIDPARAMETER :</tt> arguments incorrect.
 *   <br><tt> DRM_E_INSUFFICIENTMEMORY :</tt> no more memory to make the  envelope.
 *   <br><tt> DRM_E_UNKNOWN :</tt> unexpected error.
*/    
  virtual  HRESULT DRMExportAuthorization ( void  *&oDRMAuthorization,
					    size_t &oDRMAuthorizationSize) = 0;
  
/**
 * Frees the exportable authorizationdata.
 * <br><b>Role</b>: Frees the authorization data associated to a given document 
 * that has been allocated during the @href #DRMExportAuthorization
 * @param iDRMAuthorizationEnvelope [in]
 *     DRMAuthorization Buffer.
 * @return
 *   <br><tt> S_OK :</tt>on Success.
 *   <br><tt> DRM_E_FAIL :</tt> problem during license generation.
*/    
  virtual  HRESULT DRMFreeAuthorization (void *iDRMAuthorization) = 0;



/**
 * Returns to DRM code the Authorization data associated with a document.
 * <br><b>Role</b>: Returns to the DRM code the Authorization data associated with 
 * the document that has been opened with @href DRMCreateContext. The DRM code 
 * should be able to retrieve here all the necessary information for retrieving 
 * the buffer ( since the call to @href CATIUExitDRMDocument::DRMImportEnvelope).
 * Thanks to this buffer the DRM code is now able to build the authorizations
 * that the document's publisher has set.
 * @param  iDRMAuthorization [in]
 *  Buffer containing the DRM Authorization data.
 * @param iDRMAuthorizationSize [in]
 *   the size of the DRM Authorization data.
 * @return
 *   <b>Legal values</b>:
 *   <br><tt> S_OK :</tt>on Success.
 *   <br><tt> DRM_E_FAIL :</tt> problem during license retrieval.
 *   <br><tt> DRM_E_NODRM :</tt> Not DRM protected document.
 *   <br><tt> DRM_E_ACCESSDENIED:</tt> access to the document not granted.
 *   <br><tt> DRM_E_INVALIDPARAMETER :</tt> arguments incorrects.
 *   <br><tt> DRM_E_UNKNOWN :</tt> unexpected error.
*/          
  virtual  HRESULT DRMImportAuthorization( const void *iDRMAuthorization,
					   size_t iDRMAuthorizationSize) = 0;

};



#endif



