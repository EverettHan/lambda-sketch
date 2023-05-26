/* -*-c++-*- */
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2006  
//-----------------------------------------------------------------------------
// class CATOmbUndoRedoObserver:
// 
// this class is the basic interface for Modeler which need to observe UndoRedoEngine events
//
//===================================================================
//  July 2006  Creation: RJS
//===================================================================
#ifndef CATOmbUndoRedoObserver_H_
#define CATOmbUndoRedoObserver_H_

/**
* @level Protected 
* @usage U6
*/

#include "AD0XXBAS.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"
#include "CATDataType.h"
#include "CATOmbUndoRedoDefs.h"
#include "CATOmxArray.h"

class CATOmbSessionUndoContext;
class CATIContainer;
class CATOmbSessionUndoRedoTransaction;
class CATListPtrCATBaseUnknown;
class CATBaseUnknown;

/**
* <b>Role</b> : CATOmbUndoRedoObserver is a class from which you must inherit to define an observer to listen to UndoRedo Engine events.
* Observer help you to manage some internal part of your data model or some view of your data model.
* All events are related to a transaction Identifier which is always a number equal or greater than ZERO.
* Available events (CATOmbUndoRedoEventID) and ObserverType are defined in @href CATOmbUndoRedoDefs header.
* <br> Your observer must be used as follows :
* <ol> <li> Initialization
*   <ul> <li> <code>observer = new inheritingObserver;</code>
*   <li> Subsription :
*   <li> <code>CATOmbUndoRedoObserverServices::ObserverSubcription(observer,iObserverType,ioTransactionID);</code>
*   <li> observer type available type are :
*   <li> @href #OMB_MODELOBSERVER        : To update model on UndoRedoEngine events.
*   <li> @href #OMB_VIEWOBSERVER         : To update view on UndoRedoEngine events, all model observers are updated before view observers.
*   <li> @href #OMB_DEBUGOBSERVER        : To trigger Debug tools on UndoRedoEngine events, these observers are called after all update of other observers.
*   </ul>
* <li> Execution
*   <ul> <li> observer is called on UndoRedo Engine events :
*   <li> @href #OpenTransaction        : a transaction has been opened.
*   <li> @href #CloseTransaction       : a transaction has been closed.
*   <li> @href #BeforeUndo             : an Undo operation is coming.
*   <li> @href #AfterUndo              : an Undo operation has been performed.
*   <li> @href #BeforeRedo             : an Redo operation is coming.
*   <li> @href #AfterRedo              : an Redo operation has been performed.
*   <li> @href #UndoTransaction        : a transaction has been replayed backwards.
*   <li> @href #RedoTransaction        : a transaction has been replayed forwards.
*   <li> @href #ConcatenateTransaction : two transactions have been concatenated.
*   <li> @href #DeleteTransaction      : a transaction has been deleted.
*   <li> @href #BeforeDelete           : a list of transactions will be deleted.
*   <li> @href #AfterDelete            : a list of transactions has been deleted.
*   <li> @href #ContainerInitialized   : a container is initializied and can support UndoRedo management.
*   <li> @href #ContainerWithoutUndo   : a container is flagged to not support UndoRedo management.
*   <li> @href #ContainerRemoved       : a container is removed
*   <li> @href #UndoRedoReset          : UndoRedo log has been reset.
*   <li> @href #UndoRedoError          : an error have occured.
*   <li> @href #EndOfSubscription      : SessionUndo end.
*   </ul>
* <li> End
*   <ul> <li> <code>CATOmbUndoRedoObserverServices::ObserverUnsubsription(observer);</code>
*   <li> <code>observer->Release();</code>
*   <li> <code>observer=NULL;</code>
* </ol>
*/

class ExportedByAD0XXBAS CATOmbUndoRedoObserver : public CATBaseUnknown
{
public:
  /**
  * Observer update its internal data on event #UndoRedoError, #UndoRedoReset or #EndOfSubscription. 
  * UndoRedoResetevent inform that all available Undo operations has been performed. Thus there is no more current transaction opened. Notice after this events, observers can be called on Redo operations and must not flush their data. Redo operation may be disabled then in this case observers would be explicitly called on DeleteTransactions.
  * UndoRedoError means all observers must flush all related data to UndoRedo log. 
  * Observers  receive EndOfSubscription event to clean-up all its internal data. It occurs at the end of Session or when Observer decide to unregister from Undo/Redo Engine.
  * @param iEvent
  *   <br><b>Legal values</b>:
  *   <code>UndoRedoError</code>.
  *   <code>UndoRedoReset</code>.
  *   <code>EndOfSubscription</code>.
  * @param iTransactionID
  *		The identifier of current transaction.
  * @return
  *   An HRESULT value:
  *   <br><b>Legal values</b>:
  *   <code>S_OK</code>, operation succeeded.
  *   <code>E_FAIL</code>, operation failed.
  *   <code>E_NOTIMPL</code>, default when observer don't have to manage an event.
  */
  virtual HRESULT ObserverUpdate(const CATOmbUndoRedoEventID iEvent,const unsigned int iTransactionID)=0;
  /**
  * Observer update its internal data on event #DeleteTransaction. 
  * @param iEvent
  *   <br><b>Legal values</b>:
  *   <code>DeleteTransaction</code>.
  * @param iListOfTransactionID
  *		list of  identifier of the transactions which are involved in Delete operations according to chronology of transactions processing. 
  * @return
  *   An HRESULT value:
  *   <br><b>Legal values</b>:
  *   <code>S_OK</code>, operation succeeded.
  *   <code>E_FAIL</code>, operation failed.
  *   <code>E_NOTIMPL</code>, default when observer don't have to manage an event.
  */
  virtual HRESULT ObserverUpdate(const CATOmbUndoRedoEventID iEvent,const CATOmbSessionUndoTransactionIdVector& iListOfTransactionID)=0;
  /**
  * Observer update its internal data on event #ConcatenateTransaction. 
  * @param iEvent
  *   <br><b>Legal values</b>:
  *   <code>ConcatenateTransaction</code>.
  * @param iListOfTransactionID
  *		list of  identifier of the transactions which are involved in Concatenate operations according to chronology of transactions processing. 
  * @param iTargetTransactionID
  *		The identifier of transaction receiving concatenation. 
  * @return
  *   An HRESULT value:
  *   <br><b>Legal values</b>:
  *   <code>S_OK</code>, operation succeeded.
  *   <code>E_FAIL</code>, operation failed.
  *   <code>E_NOTIMPL</code>, default when observer don't have to manage an event.
  */
  virtual HRESULT ObserverUpdate(const CATOmbUndoRedoEventID iEvent,const unsigned int iTargetTransactionID,const CATOmbSessionUndoTransactionIdVector& iListOfTransactionID)=0;
  /**
  * Observer update its internal data on event #BeforeDelete and #AfterDelete. 
  * @param iEvent
  *   <br><b>Legal values</b>:
  *   <code>BeforeDelete</code>.
  *   <code>AfterDelete</code>.
  * @param iFirstTransactionID
  *		The first transaction that will be deleted/has been deleted
  * @param iLastTransactionID
  *		The last transaction that will be deleted/has been deleted
  * @return
  *   An HRESULT value:
  *   <br><b>Legal values</b>:
  *   <code>S_OK</code>, operation succeeded.
  *   <code>E_FAIL</code>, operation failed.
  *   <code>E_NOTIMPL</code>, default when observer don't have to manage an event.
  */
  virtual HRESULT ObserverUpdate(const CATOmbUndoRedoEventID iEvent,const unsigned int iFirstTransactionID,const unsigned int iLastTransactionID) {return E_NOTIMPL;}
  /**
  * Observer update its internal data on event #UndoTransaction, #RedoTransaction#, AfterUndo, #AfterRedo, #BeforeUndo or #BeforeRedo. 
  * @param iEvent
  *   <br><b>Legal values</b>:
  *   <code>BeforeUndo</code>.
  *   <code>BeforeRedo</code>.
  *   <code>AfterUndo</code>.
  *   <code>AfterRedo</code>.
  *   <code>UndoTransaction</code>.
  *   <code>RedoTransaction</code>.
  * @param iListOfTransactionID
  *		list of  identifier of the transactions which are involved in Undo or Redo operations according to chronology of transactions processing. 
  * @param ioContext
  *		The context during this operation. 
  * @return
  *   An HRESULT value:
  *   <br><b>Legal values</b>:
  *   <code>S_OK</code>, operation succeeded.
  *   <code>E_FAIL</code>, operation failed.
  *   <code>E_NOTIMPL</code>, default when observer don't have to manage an event.
  */
  virtual HRESULT ObserverUpdate(const CATOmbUndoRedoEventID iEvent,const CATOmbSessionUndoTransactionIdVector& iListOfTransactionID,const CATOmbSessionUndoContext& ioContext)=0;
  /**
  * @deprecated do not use
  */
  virtual HRESULT ObserverUpdate(const CATOmbUndoRedoEventID iEvent,const unsigned int iFromTransactionID,const unsigned int iToTransactionID,const CATOmbSessionUndoContext& ioContext) {return E_NOTIMPL;}
  /**
  * Observer update its internal data on event #OpenTransaction or #CloseTransaction. 
  * @param iEvent
  *   <br><b>Legal values</b>:
  *   <code>OpenTransaction</code>.
  *   <code>CloseTransaction</code>.
  * @param iTransactionID
  *		The current transaction's identifier. 
  * @param iTransactionInfo
  *		Informations on the command related to the current transaction. 
  * @return
  *   An HRESULT value:
  *   <br><b>Legal values</b>:
  *   <code>S_OK</code>, operation succeeded.
  *   <code>E_FAIL</code>, operation failed.
  *   <code>E_NOTIMPL</code>, default when observer don't have to manage an event.
  */
  virtual HRESULT ObserverUpdate(const CATOmbUndoRedoEventID iEvent,const unsigned int iTransactionID,const OmbUndoRedoContext& iTransactionInfo);//temporary for migration must be =0;
  /**
  * WARNING DEPRECATION : the following method must be removed on all Observers concrete implementations and be replaced by the method above (...OmbUndoRedoContext& iTransactionInfo) which will become oure virtual on next drop
  */
  virtual HRESULT ObserverUpdate(const CATOmbUndoRedoEventID iEvent,const unsigned int iTransactionID,const CommandTransactionType iTransactionType);
  /**
  * Observer update its internal data on event #ContainerRemoved, #ContainerWithoutUndo  or #ContainerInitialized. 
  * @param iEvent
  *   <br><b>Legal values</b>:
  *   <code>ContainerInitialized</code>.
  *   <code>ContainerRemoved</code>.
  *   <code>ContainerWithoutUndo</code>.
  * @param iTransactionID
  *		The current transaction's identifier. 
  * @param iContainer
  *		The current Container. 
  * @return
  *   An HRESULT value:
  *   <br><b>Legal values</b>:
  *   <code>S_OK</code>, operation succeeded.
  *   <code>E_FAIL</code>, operation failed.
  *   <code>E_NOTIMPL</code>, default when observer don't have to manage an event.
  */
  virtual HRESULT ObserverUpdate(const CATOmbUndoRedoEventID iEvent,const unsigned int iTransactionID,const CATBaseUnknown* iContainer) =0;
  /**
  * Observer update looks if observer is empty
  * @param iSearchInListOfTransactionID. 
  *   The list of transaction ID to check
  * @return
  *   An CATBoolean value:
  *   <br><b>Legal values</b>:
  *   <code>TRUE</code>, operation succeeded.
  *   <code>FALSE</code>, operation failed.
  */
  virtual CATBoolean ObserverRequest(const CATOmbSessionUndoTransactionIdVector& iSearchInListOfTransactionID){ return TRUE;}
  /**
  * return Identifier of Observer
  */
  virtual char* GetObserverIdentifer();

protected:
  CATOmbUndoRedoObserver(){};
  virtual ~CATOmbUndoRedoObserver();  
private:
  CATOmbUndoRedoObserver(const CATOmbUndoRedoObserver &);
  CATOmbUndoRedoObserver& operator =(const CATOmbUndoRedoObserver &);
};
/**
* Service grouping calls related to CATOmbUndoRedoObserver
* <b>Role</b>: This session service exposes ObjectModelerBase APIs to manage observers in SessionUndo log. <br>
*/
#define OMB_UNDOREDOMODESERVICES
class ExportedByAD0XXBAS CATOmbUndoRedoObserverServices{
public:
  /**
  * Add Observer in UndoRedo Engine. 
  * When added Observer is AddReffed by UndoRedo Engine. And a Transaction is opened on Observers according to UndoRedoengine state. 
  * @param iObserver
  *		Observer to add. 
  * @param iObserverType
  *   Observer type.
  * @param ioTransactionID
  *   Returned identifier of UndoRedoEngine's Current Transaction when Observer has been registered.
  *   Identifier is always a number equal or greater than ZERO, when operation succeeded.
  * @return
  *   An HRESULT value:
  *   <br><b>Legal values</b>:
  *   <code>S_OK</code>, operation succeeded.
  *   <code>S_FALSE</code>, operation was already done.
  *   <code>E_ACCESSDENIED</code>, operation failed because UndoRedo Engine is handling some transaction.
  *   <code>E_FAIL</code>, operation failed.
  */
  static HRESULT ObserverSubscription(CATOmbUndoRedoObserver* iObserver, OmbObserverType iObserverType, unsigned int& ioTransactionID);
  /**
  * Remove Observer in UndoRedo Engine. 
  * When UndoRedo Engine Observer, it send event EndOfSubscription and it release observer. 
  * @param iObserver
  *		Observer to remove. 
  * @param iObserverType
  *   Observer type.
  * @return
  *   An HRESULT value:
  *   <br><b>Legal values</b>:
  *   <code>S_OK</code>, operation succeeded.
  *   <code>S_FALSE</code>, operation postponed because UndoRedoEngine is processing some event.
  *   <code>E_FAIL</code>, operation failed.
  */
  static HRESULT ObserverCancelSubscription(CATOmbUndoRedoObserver* iObserver,OmbObserverType iObserverType);
  /**
  * Return UndoRedo mode of  UndoRedo manager
  * @return 
  *   OmbUndoRedoMode value
  */
  static OmbUndoRedoMode GetUndoRedoManagerMode();

private:
  CATOmbUndoRedoObserverServices(){};
  virtual ~CATOmbUndoRedoObserverServices(){};  
  CATOmbUndoRedoObserverServices(const CATOmbUndoRedoObserverServices &);
  CATOmbUndoRedoObserverServices& operator =(const CATOmbUndoRedoObserverServices &);
};



#endif
