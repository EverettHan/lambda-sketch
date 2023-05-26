#ifndef __CATFrmContext_h
#define __CATFrmContext_h

// COPYRIGHT DASSAULT SYSTEMES 2014

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATCallbackManager.h"
#include "CATPathElement.h"
#include "CATString.h"
#include "CATBoolean.h"
#include "CATAfrFoundation.h"

class CATFrmEditor;
class CATCmdWorkshop;
class CATCmdWorkbench;
class CATFrmWindow;
class CATActiveObject;
class CATLISTP(CATFrmEditor);
class l_CATFrmContext;
class CATLISTP(CATFrmWindow);

/**
  * Class to manage Application Frame context.
  * <b>Role</b>
  * This class contains all the services for Application Frame context management.
  * <ul>
  * <li>Get the current workbench pointer or name</li>
  * <li>Get the current workshop pointer or name</li>
  * <li>Get the current editor</li>
  * <li>Get the current window</li>
  * <li>Get the list of opened editors</li>
  * </ul>
  * <br>The static method GetContext retrieves the pointer on the context. The other methods should be applied on this pointer.
  * <br>The context is managed in transactions. This prevents from re-entrance : a workbench change request will be refused (will do nothing)
  * while a workbench change is being processed and is not done.
  */

/**
  * Bit field set when the corresponding change is being processed.
  * <b>Role</b>For example, GetTransaction() & CATFrmCtxWorkbench is TRUE whether a transaction is opened
  * and the current workbench is being changed (and the change is not completely done).
  */
/** Current workbench being changed.*/
#define CATFrmCtxWorkbench     (1 << 0)
/** Current workshop being changed.*/
#define CATFrmCtxWorkshop      (1 << 1)
/** Current workbench name being changed.*/
#define CATFrmCtxWorkbenchName (1 << 2)
/** Current workshop name being changed.*/
#define CATFrmCtxWorkshopName  (1 << 3)
/** Current window being changed.*/
#define CATFrmCtxWindow        (1 << 6)
/** Current editor being changed.*/
#define CATFrmCtxEditor        (1 << 7)
/** @nodoc - Current active path being changed.*/
#define CATFrmCtxActivePath    (1 << 4)
/** @nodoc - Current UI-active path being changed.*/
#define CATFrmCtxUIActivePath  (1 << 5)
/** @nodoc - Current app changed.*/
#define CATFrmCtxApp  (1 << 8)

class ExportedByCATAfrFoundation CATFrmContext: public CATCallbackManager
{
  CATDeclareClass;
  friend class CATFrmEditor;

public:
	
/** This event is sent each time a transaction ends. */
  CATDeclareCBEvent(FrmContextModified);

  CATFrmContext  ();
	virtual ~CATFrmContext ();
  
/** Retrieves the pointer on the Application Frame context singleton.
  * @return the pointer on the context */
  static CATFrmContext * GetContext ();

/** Retrieves the current workshop pointer.
  * @return the pointer on the current workshop */
	const CATCmdWorkshop  * GetWorkshop  () const;
/** Retrieves the current workshop name.
  * @return the workshop name */
	const CATString & GetWorkshopName  () const;
/** Retrieves the previous workshop name.
  * @return the previous workshop name. Useful during a workshop transition */
	const CATString & GetPreviousWorkshopName  () const;
/** Retrieves the next workshop name.
  * @return the next workshop name. Useful during a workshop transition. */
	const CATString & GetNextWorkshopName  () const;

/** Retrieves the current workbench pointer.
  * @return the pointer on the context */
	const CATCmdWorkbench * GetWorkbench () const;
/** Retrieves the current workbench name.
  * @return the current workbench name */
	const CATString & GetWorkbenchName () const;
/** Retrieves the previous workbench name.
  * @return the previous workbench name. Useful during a workbench transition */
	const CATString & GetPreviousWorkbenchName  () const;
/** Retrieves the next workbench name.
  * @return the next workbench name. Useful during a workbench transition. */
	const CATString & GetNextWorkbenchName  () const;
  
/** Retrieves the current app name.
  * @return the current app name */
  const CATString &  GetApp( );
/** Retrieves the previous app name.
  * @return the previous app name. Useful during a app transition */
  const CATString &  GetPreviousAppName( );
  /** Retrieves the next app name.
  * @return the next app name. Useful during a workbench transition. */
  const CATString &  GetNextAppName( );
/** Retrieves the current editor pointer.
  * @return the pointer on the editor */
	const CATFrmEditor * GetEditor () const;

/** Retrieves the current window pointer.
  * @return the pointer on the window */
  const CATFrmWindow * GetWindow () const;
/** Changes the current window.
  * @param ipWindow
  *   The window to set as current */
  void SetWindow (CATFrmWindow *ipWindow);

/** Retrieves the list of open editors. Please delete the list after use. 
  * @return the list of open editors */
  static CATLISTP(CATFrmEditor) *GetActiveEditorList ();
/** Retrieves the list of open editors.
  <br>Same as GetActiveEditorList but non-static */
  CATLISTP(CATFrmEditor) * GetEditorList();

/** Retrieves the current transaction status.
  * <b>Role</b>For example, GetTransaction() & CATFrmCtxWorkbench is TRUE whether a transaction is opened
  * and the current workbench is being changed (and the change is not completely done).
  * @return the transaction status */
  unsigned int GetTransaction();

// nodoc methods //

/** @nodoc
  * Changes the current workshop.
  * @param ipWorkshop
  *   The workshop
  * @param deleteTlb
  *   Tells whether the ancient workshop's toolbars have to be deleted (0 always works fine...)*/
  void SetWorkshop  (CATCmdWorkshop *ipWorkshop, int deleteTlb = 0);
/** @nodoc
  * Changes the current workshop by name.
  * @param iName
  *   The workshop name */
  void SetWorkshopName  (const CATString & iName);

/** @nodoc
  * Changes the current workbench.
  * @param ipWorkbench
  *   The workbench
  * @param ipWorkshop
  *   The workshop where to change the current workbench (NULL for the current workshop)*/
  void SetWorkbench (CATCmdWorkbench * ipWorkbench, CATCmdWorkshop *ipWorkshop = NULL);
/** @nodoc
  * Changes the current workbench by name.
  * @param iName
  *   The workbench name */
  void SetWorkbenchName (const CATString & iName);
  /** @nodoc
  * Changes the current app by its identifier.
  * @param iAppId
  *   The app identifier */
  void StartApp (const CATString & iAppId);

/** 
  * @nodoc 
  * Retrieves the current active path.
  * @return the active path */
  const CATPathElement & GetActivePath () const;
/** 
  * @nodoc 
  * Retrieves the current ui-active path.
  * @return the ui-active path */
  const CATPathElement & GetUIActivePath () const;

/** 
  * @nodoc 
  * Changes the current active path in the current editor.
  * @param iPath
  *   The path to set as the active path 
  * @param iObjectEdition
  *   <ul>
  *   <li>TRUE if the path change corresponds to an object edition. After the edition, all the actions done during this edition
  *       will be committed in one action. This is important for undo/redo.</li>
  *   <li>FALSE if the path change does not correspond to an object edition</li></ul>*/
  void SetActivePath   (CATPathElement & iPath, CATBoolean iObjectEdition=TRUE);
/** 
  * @nodoc 
  * Changes the current active path in the current editor.
  * @param iPath
  *   The path to set as the active path 
  * @param iObjectEdition
  * @return
  * <li>S_OK if the path was correctly changed</li>
  * <li>E_FAIL if the path could not be changed</li></ul>*/
  HRESULT SetActivePath (CATPathElement *ipPath, CATBoolean iObjectEdition=TRUE);
/** 
  * @nodoc 
  * Changes the current active path.
  * @param iPath
  *   The path to set as the active path 
  * @param ipEditor
  *   The editor where to change the path 
  * @param iObjectEdition*/
  void SetActivePath (CATPathElement &iPath, CATFrmEditor *ipEditor, CATBoolean iObjectEdition=TRUE);
/** 
  * @nodoc 
  * Changes the current active path.
  * @param iPath
  *   The path to set as the active path 
  * @param ipEditor
  *   The editor where to change the path 
  * @param iObjectEdition
  * @return
  * <li>S_OK if the path was correctly changed</li>
  * <li>E_FAIL if the path could not be changed</li></ul>*/
  HRESULT SetActivePath (CATPathElement *ipPath, CATFrmEditor *ipEditor, CATBoolean iObjectEdition=TRUE);

/** 
  * @nodoc 
  * Changes the current ui-active path in the current editor.
  * @param iPath
  *   The path to set as the active path */
  void SetUIActivePath (CATPathElement & iPath);
/** 
  * @nodoc 
  * Changes the current ui-active path.
  * @param iPath
  *   The path to set as the active path 
  * @param ipEditor
  *   The editor where to change the path */
  void SetUIActivePath (CATPathElement & iPath, CATFrmEditor *ipEditor);
  
/** @nodoc
  * Changes the current editor.
  * @param ipEditor
  *   The editor to set as current */
  void SetEditor (const CATFrmEditor *ipEditor);



private:


/** Reserved for CATFrmEditor class.*/
  void AddEditor(CATFrmEditor *pEditor);
/** Reserved for CATFrmEditor class.*/
  void RemoveEditor(CATFrmEditor *pEditor);

  void SendEvents ();

  /**
   * @nodoc
   *
   * Add a new context associated to the given ID.
   *
   * @note Member function reserved for AfrWindowManagerVIDMDI (CID Frame)
   *
   * @param i_pContextId The ID of the context to create. Can't be NULL.
   */
  void AddContext(CATBaseUnknown * i_pContextId);
  /**
   * @nodoc
   *
   * Remove the context corresponding to the given ID.
   *
   * @note Member function reserved for AfrWindowManagerVIDMDI (CID Frame)
   *
   * @param i_pContextId The ID of the context to remove. Can't be NULL.
   */
  void RemoveContext(CATBaseUnknown * i_pContextId);
  /**
   * @nodoc
   *
   * Set the context corresponding to the given ID as current.
   *
   * @note Member function reserved for AfrWindowManagerVIDMDI (CID Frame)
   *
   * @param i_pContextId The ID of the context to set as current.
   */
  void SetCurrentContext(CATBaseUnknown * i_pContextId);
  /**
   * @nodoc
   *
   * Get the CATFrmWindow objects associated to the current context.
   *
   * @note Member function reserved for CATFrmLayout (CID Frame)
   *
   * @return the list of CATFrmWindow objects associated to the current context.
   */
  CATLISTP(CATFrmWindow) GetWindowsOfCurrentContext();
  /**
   * @nodoc
   *
   * Get the number of CATFrmWindow objects associated to the current context.
   *
   * @note Member function reserved for CATFrmLayout (CID Frame)
   *
   * @return the number of CATFrmWindow objects associated to the current
   * context.
   */
  int GetNumberOfWindowsOfCurrentContext();
  /**
   * @nodoc
   *
   * Add the given window to the current context.
   *
   * @note Member function reserved for CATFrmWindow (CID Frame)
   *
   * @param i_pWindow the window to add to the current context.
   */
  void AddWindowToCurrentContext(CATFrmWindow * i_pWindow);
  /**
   * @nodoc
   *
   * Add the given window to the given context.
   *
   * @note Member function reserved for CATFrmWindow (CID Frame)
   *
   * @param i_pWindow the window to add to the given context.
   * @param i_pContextId the given context identifier.
   */
  void AddWindowToContext(CATFrmWindow * i_pWindow, CATBaseUnknown * i_pContextId);
  /**
   * @nodoc
   *
   * Remove the given window from the current context.
   *
   * @note Member function reserved for CATFrmWindow (CID Frame)
   *
   * @param i_pWindow the window to remove from the current context.
   */
  void RemoveWindowFromCurrentContext(CATFrmWindow * i_pWindow);
  /**
   * @nodoc
   *
   * Remove the given window from the given context.
   *
   * @note Member function reserved for CATFrmWindow (CID Frame)
   *
   * @param i_pWindow the window to remove from the given context.
   * @param i_pContextId the given context identifier.
  */
  void RemoveWindowFromContext(CATFrmWindow * i_pWindow, CATBaseUnknown * i_pContextId);
  /**
   * @nodoc
   *
   * Set i_pWindow as the current window (called by CATFrmLayout to
   * update the CATFrmContext).
   *
   * @note Member function reserved for CATFrmLayout (CID Frame)
   *
   * @param i_pWindow the window to set as current.
   */
  void SetCurrentWindowFromLayout(CATFrmWindow * i_pWindow);
  /**
   * Get the context ID associated to the given window.
   *
   * @param i_pWindow the Window for which the context ID is requested.
   *
   * @return the Context ID associated to the given window.
   */
  CATBaseUnknown * GetContextIdOfFrmWindow(CATFrmWindow * i_pWindow);

  static CATFrmContext * _context;
  l_CATFrmContext * _pLetter;  
  
  static int GetAutomationStatus ();

  static void SetAutomationStatus (const int autostatus);

  friend class CATFrmEditor;
  friend class CATIAWindowImpl;
  friend class AfrWindowManagerVIDMDI;
  friend class CATFrmLayout;
  friend class CATFrmWindow;
  friend class CATAfrTstCIDFrameServices;
  static int _autostatus;


  /* Definition of the "transactional mechanism" :
     The transaction begins when a "set" operation is invoked.
     _transaction is set when the transaction begins. It can be set again if
     a "set" operation is done on the context. Each bit represents a "set" 
     operation and can be set only once during a transaction (the second
     time will do nothing). The bit is reset when the set operation is over.
     The transaction ends when _transaction comes back to zero. Then the 
     events are sent. 
  */
  unsigned int _transaction;
  unsigned int _transactionSave;
};

#endif//__CATFrmContext_h
