#ifndef CATAcquisitionAgent_H
#define CATAcquisitionAgent_H
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 1999
// protected DI0STATE.m

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATDialogAgent.h"

#include "CATBaseUnknown.h"
#include "CATDlgEngUtility.h"
#include "CATAcquisitionFilter.h"
#include "CATBooleanDef.h"

class CATDlgContextualMenu;
class CATString;

/**
 * Base class for a state command acquisition agent.
 * <b>Role</b>: An acquisition agent is a specific dialog agent dedicated 
 * to get something "under the mouse" in addition to the notification. 
 * Acquisition agents are valued as dialog agents, but in addition, they
 * store values.
 * <br>Do not instantiate directly acquisition agents because this base class
 * is useless as it is. Instead, use one of its derived classes:
 * @href CATPathElementAgent or @href CATIndicationAgent.
 */
class ExportedByCATDialogEngine CATAcquisitionAgent : public CATDialogAgent
{
  
  /** @nodoc */
  CATDeclareClass;
  
public:
  
  /** @nodoc */
  enum BehaviorMode {SimpleValuation, WithPrevaluation,
                     ManipulatorValuation, EditValuation,
                     ContextValuation, DragValuation };
  /**
  * Agent valuation state.
  * <br><b>Role</b>: It is linked to the latest meaningful notification received 
  * by the agent.
  * @param NotValuated
  *   The agent is neither valued nor prevalued. It has not received expected
  *   notifications or has been reinitialized since then.
  * @param Transient
  *   The agent has received an expected notification which is being studied
  *   and is not accepted yet.
  * @param PreValuated
  *   The agent has received a notification representing a prevaluation.
  *   In general, the prevaluation is associated with the @href
  *   CATPreactivate and @href CATMove notifications and happens when an 
  *   object is under the mouse without being selected.
  * @param Valuated
  *   The agent has received a notification representing a valuation.
  *   In general, the valuation is associated with the @href CATActivate 
  *   notification and happens when an object is selected with a 
  *   mouse left click.
  */
  enum ValuationState {NotValuated, Transient, PreValuated, Valuated};
  
  /** @nodoc */
  CATAcquisitionAgent (const CATString &iId, 
                       CATDlgEngBehavior iBehavior=NULL);
  
  virtual ~CATAcquisitionAgent ();
  
  /*---------------------------------*/
  // ValuationState Management                  
  /*---------------------------------*/
  
  /**
  * Returns the valuation state of the agent.
  * <br><b>Role</b>: It is the latest state of the agent.
  * For example, if a valued agent receives a prevaluation, the returned state
  * is <tt>PreValuated</tt>, whereas it is still valued.
  * @return
  *   The valuation state.
  */
  virtual CATAcquisitionAgent::ValuationState GetValuationState () const;
  
  /**
  * Values an agent dynamically.
  * <br><b>Precondition</b>: Use the @href CATIndicationAgent#SetValue or the 
  * @href CATPathElementAgent#SetValue method before, to give a value to the 
  * agent. But these methods are useless if you do not call 
  * <tt>SetValuation</tt> just after.
  */
  virtual void SetValuation ();
  
  /*---------------------------------*/
  // Contextual menu                  
  /*---------------------------------*/
  
  /**
  * Returns the contextual menu.
  * <br><b>Precondition</b>: The agent must expect a @href CATContext 
  * notification and must have been valued. Such a notification is sent when
  * the user clicks with the right mouse button.
  * @return
  *   The contextual menu.
  */
  CATDlgContextualMenu * GetContextualMenu ();
  
  /*---------------------------------*/
  //     INTERNAL METHODS 
  /*---------------------------------*/
  
  /*---------------------------------*/
  /*     BEHAVIOR                    */
  /*---------------------------------*/
  
  /**
  * @nodoc
  * Associates a notification class to a valuation mode.
  * <b>Role</b>:This method is meaningful only with @href CATPathElementAgent.
  * When the agent receives a notification whose class is a 
  * <tt>iNotifClass</tt>, its valuation status changes according to the 
  * <tt>iValuationMode</tt> mode. 
  * For example, if <code>SetBehaviorOnNotify(Valuation, "CATActivate")</code>
  * is called on an agent, this agent will get valued when it receives a 
  * @href CATActivate notification if the object under the mouse is expected 
  * by the agent.
  * It is the default behavior of an agent.
  * @param iValuationMode
  *   The valuation mode.
  * @param iNotifClass
  *   The notification class.
  */
  virtual void SetBehaviorOnNotify (ValuationMode iValuationMode, 
                                    const char * iNotifClass);
  
    /**
    * @nodoc
    * Cancels the effect of the @href #SetBehaviorOnNotify method.
    * @param iValuationMode
    *   The valuation mode.
    * @param iNotifClass
    *   The notification class.
  */
  virtual void ResetBehaviorOnNotify (ValuationMode iValuationMode, 
                                      const char * iNotifClass);
  
  /*------------------------------------------------*/
  /* Filter on Value                                */
  /*------------------------------------------------*/
  
  /**
  * Associates a filter to the acquisition agent.
  * @param iFilter
  *   The filter to be applied.
  */
  void SetFilter (CATAcquisitionFilter * iFilter);

  /** @nodoc */
  CATBoolean ApplyFilter ();
  
  /*------------------------------------------------*/
  /* ValuationState Management                      */
  /*------------------------------------------------*/
  
  /** @nodoc */
  virtual void SetValuationState (CATAcquisitionAgent::ValuationState);
  /** @nodoc */
  virtual void SetPrevaluation ();
  /** @nodoc */
  virtual void ResetPrevaluation ();
  
  /*------------------------------------------------*/
  /* Value Management                               */
  /*------------------------------------------------*/
  
  /** @nodoc */
  void RestoreValue ();
  
  /** @nodoc */
  virtual void * UndoValue ();
  /** @nodoc */
  virtual void * RedoValue ();
  /** @nodoc */
  virtual void ResetValue ();
  
  /** @nodoc */
  virtual void * DecodeNotification (CATCommand * from, CATNotification * notif);
  
  /** @nodoc */
  virtual void InitializeValue();
  /** @nodoc */
  virtual void StoreValue ();
  
  /*------------------------------------------------*/
  /* CSO Management                                 */
  /*------------------------------------------------*/
  
  /** @nodoc */
  virtual void PutIntoPSO ();
  /** @nodoc */
  virtual CATBoolean UpdatePSO ();
  /** @nodoc */
  virtual void RemoveFromPSO ();
  /** @nodoc */
  virtual void PutIntoHSO ();
  /** @nodoc */
  virtual void RemoveFromHSO ();
  
  /*---------------------------------*/
  //     OBSOLETE METHODS 
  /*---------------------------------*/
  
  /** 
  * @nodoc 
  * Use SetBehavior instead.
  */
  virtual void SetBehaviorMode (BehaviorMode);
  
  /** @nodoc */
  void SetCSOMode (ModeOffOn mode=ON);

private:

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATAcquisitionAgent ();
  CATAcquisitionAgent (const CATAcquisitionAgent &);
  CATAcquisitionAgent & operator= (const CATAcquisitionAgent &);

  /*----------------------------------------------------------*/
  /* DE² DUMP	-DE² internal use ONLY-			*/
  /*----------------------------------------------------------*/
  /** @nodoc */
  const CATAcquisitionFilter* const GetFilter();

 protected:
  
  /*----------------------------------------------------------*/
  /* Set/Retrieve the agent properties	-DE² use-			*/
  /*----------------------------------------------------------*/
  /** @nodoc */
  virtual HRESULT _GetProperty(CATUnicodeString iPropertyId, CATBaseUnknown_var& iospPropValue);
  virtual HRESULT _SetProperty(CATUnicodeString iPropertyId, const CATListValCATBaseUnknown_var& ispPropValue);

  friend class CATDE2DumpCppStateCommand;
};

#endif
