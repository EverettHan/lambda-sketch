/* COPYRIGHT DASSAULT SYSTEMES 2006 */
/**
 * @CAA2Level L0
 * @CAA2Usage U5
 */

#ifndef CATIUExitDRMDocument_H
#define CATIUExitDRMDocument_H

#include "CATWTypes.h"
#include "CATErrorDef.h"
#include "CATUnicodeString.h"


#undef  ExportedByJS0DRMDOC 
#ifdef  __JS0DRMDOC
#define ExportedByJS0DRMDOC DSYExport
#else
#define ExportedByJS0DRMDOC DSYImport
#endif
#include "DSYExport.h"



extern "C" const IID IID_CATIUExitDRMDocument;
extern "C" const IID IID_CATIUExitDRMSession;
extern "C" const IID IID_CATIUExitDRMAuthorization;
extern "C" const IID IID_CATIUExitDRMUI;


			  

/**
 * Interface to enable user specific DRM (digital rights management) mechanism on
 * documents.
 * <b>Role</b>: This interface is a user exit, that allows an user to augment the
 * security of its strategical documents by assigning security parameters inside 
 * the document itself and not only relying on a perimeter-based security.
 **/
class ExportedByJS0DRMDOC  CATIUExitDRMDocument : public IUnknown
{
public:

/**
 * Creates the DRM context for a given document.
 * <br><b>Role</b>:Creates the DRM context necessary to work on the document
 * pointed by iDocumentID. This method will be called at the opening of the 
 * document. It must be thread safe.
 * @param iDocumentID
 *      Pointer to the wide char string null terminated defining the document ID
 * @return
 *   <b>Legal values</b>:
 *   <br><tt> S_OK :</tt>on Success.
 *   <br><tt> S_FALSE :</tt> To indicate that DRM  will not be used with 
 *			     the document.
 *   <br><tt> DRM_E_INVALIDNAME :</tt> invalid name for the document.
 *   <br><tt> DRM_E_ACCESSDENIED:</tt> access to the document not granted.
 *   <br><tt> DRM_E_INVALIDPARAMETER :</tt> DRM environment not set.
 *   <br><tt> DRM_E_DOCUMENTNOTFOUND :</tt> document can not be found.
 *   <br><tt> DRM_E_INSUFFICIENTMEMORY :</tt> no more memory to make the open.
 *   <br><tt> DRM_E_UNKNOWN :</tt> unexpected error.

*/
  virtual HRESULT DRMCreateContext( const CATUC2Bytes * iDocumentID)=0;



/**
 * Closes the DRM context.
 * <br><b>Role</b>: Closes the DRM context associated to a given document that has 
 * been previously created by @href #DRMCreateContext.
 * @return
 *   <b>Legal values</b>:
 *   <br><tt> S_OK :</tt>	on Success.
 *   <br><tt>  DRM_E_FAIL :</tt>	on Error.
*/
  virtual HRESULT DRMCloseContext() = 0;



/**
 * Creates the digital envelope for a protected document.
 * <br><b>Role</b>: Creates the digital envelope for a protected document on an
 * exportable format. This information will be packed with the DRM enabled
 * documentduring its saving phase. This data blob can be retrieved at opening 
 * by @href #DRMImportEnvelope .
 * @param  oDRMEnvelope [out]
 *  Buffer where the protected exportable Envelope data will be stored.
 * @param iDRMEnvelopeSize [out]
 *   the size of of the DRM Envelope.
 * @return
 *   <br><tt> S_OK :</tt>on Success.
 *   <br><tt> DRM_E_FAIL :</tt> problem during envelope generation.
 *   <br><tt> DRM_E_ACCESSDENIED:</tt> access to the document not granted.
 *   <br><tt> DRM_E_INVALIDPARAMETER :</tt> arguments incorrects.
 *   <br><tt> DRM_E_INSUFFICIENTMEMORY :</tt> no more memory to make the  envelope.
 *   <br><tt> DRM_E_UNKNOWN :</tt> unexpected error.
*/    
  virtual  HRESULT DRMExportEnveloppe ( void  *&oDRMEnvelope,
					size_t &oDRMEnvelopeSize) = 0;
  
/**
 * Frees the exportable envelope data.
 * <br><b>Role</b>: Frees  the envelope data associated to a given document that 
 * has been allocated during the @href #DRMExportEnveloppe
 * @param iDRMEnvelope [in]
 *     DRMEnvelope Buffer.
 * @return
 *   <br><tt> S_OK :</tt>on Success.
 *   <br><tt> DRM_E_FAIL :</tt> problem during license generation.
*/    
  virtual  HRESULT DRMFreeEnveloppe (void *oDRMEnvelope) = 0;



/**
 * Returns to DRM code the envelope data associated with a document.
 * <br><b>Role</b>: Returns to the DRM code the envelope data associated with 
 * the document that has been opened with @href DRMCreateContext. The DRM code 
 * should be able to retrieve here all the necessary information for retrieving 
 * the document, verify its integrety.
 * It is possible to revoque directly here all subsequent operation by returning
 * DRM_E_ACCESSDENIED.
 * @param  iDRMLicence [in]
 *  Buffer containing the DRM Envelope data.
 * @param iDRMLicenseSize [in]
 *   the size of the DRM license.
 * @return
 *   <b>Legal values</b>:
 *   <br><tt> S_OK :</tt>on Success.
 *   <br><tt> DRM_E_FAIL :</tt> problem during license retrieval.
 *   <br><tt> DRM_E_NODRM :</tt> Not DRM protected document.
 *   <br><tt> DRM_E_ACCESSDENIED:</tt> access to the document not granted.
 *   <br><tt> DRM_E_INVALIDPARAMETER :</tt> arguments incorrects.
 *   <br><tt> DRM_E_UNKNOWN :</tt> unexpected error.
*/          
  virtual  HRESULT DRMImportEnveloppe( const void *iDRMEnveloppe,
				       size_t iDRMEnveloppeSize) = 0;



/**
 * Returns the GUID of the library implementing the user exits.
 * <br><b>Role</b>: Returns the GUID of the library implementing the user exits.
 * Thus it will be possible to detect documents that have been DRM protected by
 * othercode or level of code. This GUID will be marshalled into the document.
 * @param  oUID [o]
 *  GUID structure.
 * @return
 *   <b>Legal values</b>:
 *   <br><tt> S_OK :</tt>on Success.
 *   <br><tt> DRM_E_FAIL :</tt> problem during license retrieval.
 *   <br><tt> DRM_E_INVALIDPARAMETER :</tt> arguments incorrects.
 *   <br><tt> DRM_E_UNKNOWN :</tt> unexpected error.
*/          
  virtual  HRESULT DRMGetLibUID( GUID &oUID) = 0;


};




/**
 * Returns  the display name of a DRM document.
 * <br><b>Role</b>:Returns the display name of a given DRM document 
 * The caller is reponsible to release the memory by  calling a 
 * delete []oDisplayName.
 * @param iDoc [i]
 *      Pointer to a CATIUExitDRMDocument 
 *  @param oDisplayName [o]
 *      Pointer to the wide char string null terminated defining the display of
 *      the DRM document. 
 * @return
 *   <b>Legal values</b>:
 *   <br><tt> S_OK :</tt>on Success.
 *   <br><tt> DRM_E_DOCUMENTNOTFOUND :</tt> document can not be found.
 *   <br><tt> DRM_E_INSUFFICIENTMEMORY :</tt> no more memory to make the open.
 *   <br><tt> DRM_E_UNKNOWN :</tt> unexpected error.
*/
HRESULT ExportedByJS0DRMDOC CATSysDRMGetDisplayName(CATIUExitDRMDocument *iDoc, 
						    CATUC2Bytes *& oDisplayName);




#endif



