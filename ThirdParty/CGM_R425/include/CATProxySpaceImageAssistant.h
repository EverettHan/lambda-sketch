#ifndef __CATProxySpaceImageAssistant_H
#define __CATProxySpaceImageAssistant_H

/**
 * @level Private
 * @usage U1       
 */

#include "ExportedByCATPLMTos.h"
#include "CATBaseUnknown.h"
#include "CATProxySpace.h"
#include "CATLISTV_CATPLMID.h"

class CATUnicodeString;
class CATProxyTransaction;
class CATOmXStream;
class CATProxySpacePersistencyInformation;
class CATListValCATComponentIdPersistencyInformation;


class ExportedByCATPLMTos CATProxySpaceImageAssistant
{
public:

  ////////////////////////////////////////////////////////////
  //              CONSTRUCTOR / DESTRUCTOR                  //
  ////////////////////////////////////////////////////////////

  /* Constructor
  * @param iSpace : The space in which to do local save modifications
  * @param iTransaction : Working transaction LocalSave/Open (if available)
  */
  CATProxySpaceImageAssistant (const CATProxySpace & iSpace, CATProxyTransaction * iTransaction = NULL);

  virtual ~CATProxySpaceImageAssistant ();

  /**
  * Defines the next local save transaction
  *  
  * @param iTransactionName
  *        The transaction name.
  * @return 
  *       S_OK   : if succeeded
  *       E_FAIL : if failed
  */
  HRESULT NextLocalSaveTransaction (const CATUnicodeString & iTransactionName);

  /**
  * Returns the current local save transaction
  *  
  * @param oTransactionName
  *        The transaction name.
  * @return 
  *       S_OK   : if succeeded
  *       S_FALSE: if no current transaction
  *       E_FAIL : if failed
  */
  HRESULT GetLocalSaveTransaction (CATUnicodeString & oTransactionName);

  /** 
  * StoreImage
  *
  * Streams the TOS into a CATOmXStream object (which represents a binary file).
  * The purpose of this method is to offer the capability to stream the TOS into a binary file
  *
  * @param iStream
  *   The CATOmXStream in which the TOS is streamed
  *    
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  HRESULT StoreImage (CATOmXStream & iStream);

  /** 
  * PrepareRestoreImage 
  * Untreams the TOS from a CATOmXStream object (which represents a binary file) into
  * a CATProxySpacePersistencyInformation object. Does not reconcile the unstreamed
  * information with the current TOS. Must be used before other operations like
  * GetListOfComponentIdInformation or ReconcileTOS
  *
  * @param iStream
  *   The CATOmXStream from which the TOS is unstreamed
  *
  * @param oPersistencyInformation
  *   The CATOmXStream from which the TOS is unstreamed
  *    
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  HRESULT PrepareRestoreImage(CATOmXStream & iStream, CATProxySpacePersistencyInformation & oPersistencyInformation);

  /** 
  * GetListOfComponentIdInformation 
  * Uses a CATProxySpacePersistencyInformation object (created by PrepareRestoreImage) to
  * create a liste of information about the unstreamed entities without reconciling the 
  * CATProxySpacePersistencyInformation with the current space.
  *
  * @param iPersistencyInformation
  *   The unstreamed persistency information, used to generate the list of information
  *
  * @param oListOfInformation
  *   A list of object providing information about the unstreamed entities
  *    
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  HRESULT GetListOfComponentIdInformation(CATProxySpacePersistencyInformation & iPersistencyInformation, CATListValCATComponentIdPersistencyInformation & oListOfInformation);

  /** 
  * FinalyseRestoreImage
  * Uses a CATProxySpacePersistencyInformation object (created by PrepareRestoreImage) to
  * reconcile the current TOS with its state at the moment of its streaming. 
  *
  * @param iPersistencyInformation
  *   The unstreamed persistency information, used to generate the list of information
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  HRESULT FinalyseRestoreImage(CATProxySpacePersistencyInformation & iPersistencyInformation);


  /**
  * Set current transaction name after restore in the time line,
  * in historical service.
  * <br><b>Role</b>: 
  * @param iName
  * 
  * @return
  * <dl>
  * <dt><code>S_OK</code>the transaction name is set<dd>
  * <dt><code>E_FAIL</code>the space is not initialized<dd>
  * </dl>
  */
  HRESULT SetCurrentTransactionAfterRestore(const CATUnicodeString & iName);

  HRESULT RemoveFromMemTOS(const CATUnicodeString &iMemTOSFilePath, const CATPLMIDs &iIds);
  HRESULT MergeMemTOS(const CATUnicodeString &iMemTOSPath);
private:

  // Forbidden operators 
  CATProxySpaceImageAssistant (CATProxySpaceImageAssistant&);
  CATProxySpaceImageAssistant& operator=(CATProxySpaceImageAssistant&);
  // Letter
  CATProxySpace _Space;

  friend class CATPLMLocalSave_Test;
  friend class CATOxiSessionImageAssistant;
  void ResetLocalSaveTransaction();
};

#endif
