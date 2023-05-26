#ifndef __CATISplitAfrServices_h
#define __CATISplitAfrServices_h

// COPYRIGHT DASSAULT SYSTEMES 2018

#include "CATBaseUnknown.h"
#include "UndoRedoUI.h"
#include "CATCommand.h"
#include "CATUndoRequest.h"

class CATString;
class CATUnicodeString;

/**

  */

class ExportedByUndoRedoUI CATISplitAfrServices : public CATBaseUnknown {

	CATDeclareInterface;

public:

  /**
    Displays a Notification 
    iType: 1 - for CATDlgNfyError
           2 - for CATDlgNfyWarning
	*/
	virtual int AfrNotify (
        CATString iName,
        CATUnicodeString iMessage,
        CATUnicodeString iTitle,
        int iType
		) = 0;
  /**

	*/
  virtual CATString GetRepeatedCommand( )= 0;
  
  /**

  */
  virtual void SetMessage(const CATUnicodeString & iMessage)= 0;

  /**

  */
  virtual void InitURManager(CATCommand * ioIdleCmd, CATCallback & iocbeditoractivated)= 0;

  /**

  */
  virtual void RemoveCBIdle(CATCommand * ioIdleCmd)= 0;

  /**

  */
  virtual void InitSO(CATBaseUnknown * & iSO)= 0;

  /**

  */
  virtual void InitSOWCSO(CATBaseUnknown * iSO)= 0;

  /**

  */
  virtual void EmptySO(CATBaseUnknown * iSO)= 0;

  /**

  */
  virtual void GatherSO(CATBaseUnknown * iSO, CATBaseUnknown *igatheredSO)= 0;

  /**

  */
  virtual void AddElementToSO(CATBaseUnknown * iSO, CATBaseUnknown * ielt, int i)= 0;

  /**

  */
  virtual void GetNoEngine(CATBaseUnknown * &ioNoEngine)= 0;

  /**

  */
  virtual CATCallbackManager * GetLayoutCBManager()= 0;

  /**

  */
  virtual void ActivateByWindow(CATBaseUnknown * ieditor)= 0;

  /**

  */
  virtual CATBaseUnknown * GetEditor()= 0;

  /**
  
  */
  virtual void DispatchNOENotif(CATNotification * iNotification) = 0;
  
  
  /**

  */
  virtual CATBaseUnknown* GetCurrentEditor() = 0;


  /**

  */
  virtual void UnsetRepeatedCommand() = 0;


  /**

  */
  virtual int getCATActiveObjectUndoMO(CATUndoRequest * iUndoI) = 0;

  /**

  */
  virtual void EmptyCSO() = 0;

  /**

  */
  virtual void GetUIActivePath(CATBaseUnknown & ioPathElement, CATBaseUnknown * iEditor) = 0;
  
  /**

  */
  virtual void AddCallBackEditorActivated(CATCallback & iocbEditorActivated, CATSubscriberMethod isubscriber, CATBaseUnknown * iurManager) = 0;

  /**

  */
  virtual void InterruptTask()=0;

  /**

  */
  virtual CATBaseUnknown * GetDiaNoEngine() = 0;

  /**

  */
  virtual void DumpPath(const CATUnicodeString & iTitle, CATBaseUnknown * iPath) = 0;

  /**

  */
  virtual CATBaseUnknown* CreateUIActiveUndoManager(CATBaseUnknown* iEditor, CATBaseUnknown* iNoEngine) = 0;

  /**

  */
  virtual CATBaseUnknown* NewUIActivationUndoRedoManager(CATBaseUnknown* iEditor) = 0;

  /**

  */
  virtual CATUnicodeString GetDocumentName(CATBaseUnknown* iEditor) = 0;

  /**

  */
  virtual CATBaseUnknown* GetRootElem(CATBaseUnknown* iEditor) = 0;

  /**

  */
  virtual int IsPhase2UILevelOn() = 0;
};


#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByUndoRedoUI IID_CATISplitAfrServices;
#else
extern "C" const IID IID_CATISplitAfrServices;
#endif
CATDeclareHandler (CATISplitAfrServices, CATBaseUnknown);

#endif//__CATISplitAfrServices_h
