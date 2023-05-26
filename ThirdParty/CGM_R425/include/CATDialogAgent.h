#ifndef CATDialogAgent_h
#define CATDialogAgent_h
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 1999
// protected DI0STATE.m

/**
* @CAA2Level L1
* @CAA2Usage U1
*/

#include "CATCommand.h"
#include "CATBoolean.h"
#include "CATDlgEngUtility.h"

#include "CATString.h"

#include "CATMsgCatalog.h"
#include "CATDlgResource.h"


class CATAcquisitionFilter;
class CATUnicodeString;
class CATFrmEditor;
class CATDialog;
class CATECmdAgentEngine;
class CATNotification;
class CATBaseUnknown;
class CATDE2TargetPrivateImplementation;

/**
* Enables the use of a resource file whose name is the current class name.
* <b>Role</b>: Declares that the current object belongs to the <tt>thisclass
* </tt> class which derives from the <tt>baseclass</tt> class and that the
* resource file name is <tt>thisclass</tt>.
* <br>Search keys in the resource file must begin with the class name.
* <br>Use this macro in your command header file (.h).
* @param thisclass
*   The current class name which is also the resource file name.
* @param baseclass
*   The base class name of the current class
*/
#define CmdDeclareResource(thisclass, baseclass)                                  \
public:                                                                           \
	\
	virtual char* GetResourceFilename(int nDepth) const                             \
{                                                                                 \
	return ( nDepth <= 0 ? (char *)#thisclass : baseclass::GetResourceFilename(nDepth-1) ); \
}                                                                                 \
	virtual char* GetResourceClass(int nDepth) const                                \
{                                                                                 \
	return ( nDepth <= 0 ? (char *)#thisclass : baseclass::GetResourceClass(nDepth-1) );    \
}                                                                                 \
	virtual int IsOtherResourceFile(int nDepth) const                               \
{                                                                                 \
	return ( nDepth <= 0 ? 0 : baseclass::IsOtherResourceFile(nDepth-1) );          \
}

/**
* Enables the use of a resource file whose name is different from the current class name.
* <b>Role</b>: Declares that the current object belongs to the <tt>thisclass
* </tt> class which derives from the <tt>baseclass</tt> class and that the
* resource file name is <tt>FileName</tt>.
* <br>This macro may be more convenient than @href CmdDeclareResource since 
* it enables to put resources from several commands in the same file.
* <br>Search keys in the resource file must begin with the file name 
* followed by the command class name.
* <br>Use this macro in your command header.
* @param FileName
*   The resource file name
* @param thisclass
*   The current class name
* @param baseclass
*   The base class name of the current class
*/
#define CmdDeclareResourceFile(FileName, thisclass, baseclass)                   \
public:                                                                          \
	\
	virtual char* GetResourceFilename(int nDepth) const                            \
{                                                                                \
	return ( nDepth <= 0 ? (char *)#FileName : baseclass::GetResourceFilename(nDepth-1) ); \
}                                                                                \
	virtual char* GetResourceClass(int nDepth) const                               \
{                                                                                \
	return ( nDepth <= 0 ? (char *)#thisclass : baseclass::GetResourceClass(nDepth-1) );   \
}                                                                                \
	virtual int IsOtherResourceFile(int nDepth) const                              \
{                                                                                \
	return ( nDepth <= 0 ? 1 : baseclass::IsOtherResourceFile(nDepth-1) );         \
}

/**
* Base class for a state command agent.
* <b>Role</b>: A dialog agent translates a user interaction into a user 
* input. It is created to match a given end user interaction and is valued
* when the end user performs the interaction. It is associated with one
* or possibly several states. Its valuation triggers the evaluation
* of the state exit condition and, then, of the transition guard conditions 
* if the state condition returns TRUE.
* <br>An end user interaction is always defined using a notification whose 
* type reflects the interaction, and a notifier, that is, the object that 
* sends the notification.
* <br>A basic dialog agent is valued when both notification and notifier match
* the dialog agent's required ones.
* <br>Agents must be created in the @href CATStateCommand#BuildGraph method,
* along with the states they are dedicated to.
* @see CATDialogState, CATStateCommand
*/
class ExportedByCATDialogEngine CATDialogAgent: public CATCommand
{

	/** @nodoc */
	CATDeclareClass;

public:

	/** @nodoc */
	enum ModeOffOn {OFF ,ON};
	/** @nodoc */
	enum UndoType {NoUndo, SimpleUndo, UndoStop};

	/**
	* @nodoc
	* Agent valuation mode.
	* <br><b>Role</b>: It corresponds to the way a notification must be 
	* processed. It is used in the @href 
	* CATAcquisitionAgent#SetBehaviorOnNotify method which associates a 
	* notification class to a valuation mode.
	* @param PreValuation
	*   The notification linked to the <tt>PreValuation</tt> mode prevalues
	*   the agent whose @href CATAcquisitionAgent#ValuationState becomes <tt>
	*   PreValuated</tt> if the notification is accepted.
	*   <br>In general, the <tt>Prevaluation</tt> mode is associated with the 
	*   @href CATPreactivate and @href CATMove notifications which are received
	*   when an object is under the mouse without being selected.
	* @param Valuation
	*   The notification linked to the <tt>Valuation</tt> mode values
	*   the agent whose @href CATAcquisitionAgent#ValuationState becomes <tt>
	*   Valuated</tt> if the notification is accepted.
	*   <br>In general, the <tt>Valuation</tt> mode is associated with the @href
	*   CATActivate notification which is received when an object is selected 
	*   with a mouse left click.
	* @param ResetPreValuation
	*   The notification linked to the <tt>ResetPreValuation</tt> mode cancels 
	*   the previous prevaluation of the agent whose @href 
	*   CATAcquisitionAgent#ValuationState becomes <tt>NotValuated</tt> or <tt>
	*   Valuated</tt> if it has got a value.
	*   <br>In general, the <tt>ResetPrevaluation</tt> mode is associated with
	*   the @href CATEndPreactivate notification which is received when the 
	*   mouse leaves an object.
	*/
	enum ValuationMode {PreValuation, Valuation, ResetPreValuation};

	/**
	* Constructs a dialog agent.
	* @param iId
	*   The agent identifier. It is used to retrieve the undo/redo titles in 
	*   the command message file.
	* @param iBehavior
	*   The behavior of the agent.
	*   <br><b>Legal values</b>: The behavior is given in the form of a
	*   concatenation of the facet values using the | character.
	*   <br>e.g.: <code>CATDlgEngRepeat|CATDlgEngActive</code>
	*   <br>If it is NULL, the agent has the default behavior value for each 
	*   facet.
	*   <br>The behavior may be specified later with the @href #SetBehavior 
	*   method.
	* @param iMode
	*   The focus mode.
	*   <br><b>Legal values</b>: Must always be <tt>
	*   CATCommandModeUndefined</tt>.
	*   The focus of an agent is managed by the state command it belongs to.
	*/
	CATDialogAgent (const CATString & iId,
		CATDlgEngBehavior iBehavior=NULL, 
		CATCommandMode iMode=CATCommandModeUndefined);

	/**
	* @nodoc
	* OBSOLETE : Do not use, a dialog agent must have an Id
	*/
	CATDialogAgent ();

	/**
	* @nodoc
	* OBSOLETE : Do not use, dialog agents must have different Ids
	*/
	CATDialogAgent (CATDialogAgent & iAgent);

	/** @nodoc */
	virtual ~CATDialogAgent ();

	/**
	* Requests the Agent delayed destruction.
	* <br><b>Role</b>: The Agent will be destroyed as soon as this will be possible
	*/
	virtual void RequestDelayedDestruction ();

	/*---------------------------------*/
	//     VALUATION 
	/*---------------------------------*/

	/**
	* Values an agent dynamically.
	* <br><b>Role</b>: When using this method on an agent, the agent becomes 
	* valued immediately as if it had received an expected notification. 
	* <br>Moreover, this method enables to specify a notification which can be
	* considered as the valuating notification by methods like @href 
	* CATStateCommand#GetLastNotification or @href 
	* CATStateCommand#IsLastModifiedAgentCondition.
	* <br>However, this method doesn't register an undo step.
	* @param iNotif
	*   The notification to consider as the valuing notification 
	*   <br><b>Legal values</b>: The notifier may be NULL. It is an optional
	*   parameter.
	* @param iDoNotRegisterUndo
	*   Internal argument. Do not use it.
	*   <br><b>Legal values</b>: Its default value must always be used.
	*/ 
	void Accept (CATNotification * iNotif=NULL, int iDoNotRegisterUndo=0);

	/** @nodoc */
	void Accept (CATNotification * iNotif, int iDoNotRegisterUndo, ValuationMode iMode);

	/**
	* Specifies the user interaction expected by the agent.
	* <br><b>Role</b>: The agent becomes valued when it receives a notification
	* which belongs to the <tt>iNotifClass</tt> class from the <tt>iNotifier
	* </tt> notifier.
	* @param iNotifier
	*   The notifier.
	*   <br><b>Legal values</b>: The notifier may be NULL: the reception of the
	*   notification is sufficient to value the agent whatever the notifier. 
	* @param iNotifClass
	*   The notification class.
	*   <br><b>Legal values</b>: It can be NULL: any notification sent by the
	*   <tt>iNotifier</tt> notifier values the agent. 
	*/
	void AcceptOnNotify (CATCommand * iNotifier, const char * iNotifClass);

	/**
	* Specifies the user interaction expected by the agent.
	* <br><b>Role</b>: The agent becomes valued when it receives a notification 
	* which belongs to the <tt>iNotif</tt> notification class from the <tt>
	* iNotifier</tt> notifier.
	* @param iNotifier
	*   The notifier.
	*   <br><b>Legal values</b>: The notifier may be NULL: the reception of the
	*   notification is sufficient to value the agent whatever the notifier. 
	* @param iNotif
	*   The notification address.
	*   The agent checks whether the received notifications belong to the
	*   same class as the <tt>iNotif</tt> notification. So, only the 
	*   notification class matters. 
	*   <br><b>Legal values</b>: It can be NULL: any notification sent by the
	*   <tt>iNotifier</tt> notifier values the agent. 
	*/
	void AcceptOnNotify (CATCommand * iNotifier, CATNotification * iNotif);

	/**
	* Cancels the effect of the AcceptOnNotify method.
	* <br><b>Role</b>: The agent won't be valued anymore when receiving a 
	* notification which belongs to the <tt>iNotifClass</tt> class 
	* from the <tt>iNotifier</tt> notifier.
	* @param iNotifier
	*   The notifier.
	*   <br><b>Legal values</b>: Must have the same value as in the @href 
	*   #AcceptOnNotify method to cancel.
	* @param iNotifClass
	*   The notification class.
	*   <br><b>Legal values</b>: Must have the same value as in the @href 
	*   #AcceptOnNotify method to cancel.
	*/
	void IgnoreOnNotify (CATCommand * iNotifier, const char * iNotif);

	/**
	* Cancels the effect of the AcceptOnNotify method.
	* <br><b>Role</b>: The agent won't be valued anymore when receiving a
	* notification which  belongs to the <tt>iNotif</tt> notification class 
	* from the <tt>iNotifier</tt> notifier.
	* @param iNotifier
	*   The notifier.
	*   <br><b>Legal values</b>: Must have the same value as in the @href
	*   #AcceptOnNotify method to cancel.
	* @param iNotif
	*   The notification address.
	*   <br><b>Legal values</b>: Must have the same value as in the @href 
	*   #AcceptOnNotify method to cancel.
	*/
	void IgnoreOnNotify (CATCommand * iNotifier, CATNotification * iNotif);

	/**
	* Tries to value an agent with a given value.
	* <br><b>Role</b>: It only works with @href CATPathElementAgent agents and
	* the value must be a @href CATPathElement.
	* The Path Element is tested as if the object it represents had been selected
	* by the end user. If the object dosen't have the expected type, the agent 
	* is not valued and the method returns FALSE.
	* @param iValue
	*   The value.
	*   <br><b>Legal values</b>: Must be a @href CATPathElement. 
	* @return 
	*   The result of the valuation.
	*/
	CATBoolean TryValue (CATBaseUnknown * iValue);

	/**
	* Resets an agent to have it reusable.
	* <br><b>Role</b>: The agent is no more valued and is able to accept 
	* notifications again. 
	*/
	virtual void InitializeAcquisition ();

	/**
	* Tests whether the agent is valued.
	* @return 
	*   The result of the test.
	*/
	virtual CATBoolean IsOutputSet ();

	/** @nodoc */
	virtual CATBoolean IsActivated ();

	/*---------------------------------*/
	//     BEHAVIOR 
	/*---------------------------------*/

	/**
	* Sets the agent behavior.
	* <br><b>Role</b>: A behavior is made of behavioral facets that can be each 
	* set to a given value. These facets are listed in the @href 
	* CATDlgEngBehavior definition.
	* @param iBehavior
	*   The behavior.
	*   <br><b>Legal values</b>: The behavior is given in the form of a
	*   concatenation of the facet values using the | character.
	*   <br>e.g.: <code>CATDlgEngRepeat|CATDlgEngActive</code>
	*/
	virtual void SetBehavior (CATDlgEngBehavior iBehavior);

	/**
	* Returns the agent behavior.
	* <br><b>Role</b>: A behavior is made of behavioral facets that can be each 
	* set to a given value. These facets are listed in the @href 
	* CATDlgEngBehavior definition.
	* @return
	*   The behavior.
	*/
	virtual CATDlgEngBehavior GetBehavior ();

	/*---------------------------------*/
	//     EDITOR 
	/*---------------------------------*/

	/**
	* Returns the editor associated with the command.
	* <br><b>Role</b>: Do use this method instead of the @href 
	* CATFrmEditor#GetCurrentEditor method which gives the current editor which
	* may be the editor of another document, during a Drag&Drop for example.
	* @return
	*   The editor.
	*/
	CATFrmEditor * GetEditor ();

	/*-----------------------------------------------*/
	// NLS ressources 
	/*-----------------------------------------------*/

	/**
	* Declares that the command shares its resource file with a dialog.
	* <br><b>Role</b>: The resources of the <tt>iDialog</tt> dialog are written
	* in the command resource file and their research keys are prefixed with 
	* the command research key. 
	* @param iDialog
	*   The dialog.
	*/
	virtual void AddPanelForNLS (CATDialog * iDialog);

	/*---------------------------------*/
	//     INTERNAL METHODS 
	/*---------------------------------*/

	/*-------------------------------------------------*/
	/* ISO MANAGEMENT                                  */
	/*-------------------------------------------------*/

	/* Informs the ISO that the model has just changed    */
	/** @nodoc */
	void OnModify ();
	/** @nodoc */
	void SetVisibility (CATDlgEngVisibility);

	/*-------------------------------------------------*/
	/* Filter on senders                               */
	/*-------------------------------------------------*/

	/** @nodoc */
	void AddNotifier (CATCommand * from);
	/** @nodoc */
	void RemoveNotifier (CATCommand * from);

	/*-------------------------------------------------*/
	/* Add Views on which to be the father            */
	/*-------------------------------------------------*/

	/** @nodoc */
	void AddView (CATCommand * view);

	/*----------------------------------------------------------*/
	/* Returns the current notification. Must be used during  */
	/* a valuation, not after because the notification may have */
	/* been destroyed                                           */
	/*----------------------------------------------------------*/

	/** @nodoc */
	CATNotification * GetCurrentNotification ();

	/*----------------------------------------------------------*/
	/* Manage preselection                                      */
	/*----------------------------------------------------------*/

	/** @nodoc */
	CATDialogAgent * GetCurrentPrevaluatedAcquisition ();
	/** @nodoc */
	void SetCurrentPrevaluatedAcquisition (CATDialogAgent * cmd);
	/** @nodoc */
	virtual void RemoveLastPrevaluation ();
	/** @nodoc */
	virtual void ResetPrevaluation ();

	/*----------------------------------------------------------*/
	/* NLS ressources management                                */
	/*----------------------------------------------------------*/

	/** @nodoc */
	int getResourceValue (const CATString& key, CATUnicodeString& value);
	/** @nodoc */
	void SetResourceID (const CATString& rsc);
	/** @nodoc */
	CATString& GetResourceID ();

	/** @nodoc */
	virtual char* GetResourceFilename (int) const;
	/** @nodoc */
	virtual char* GetResourceClass (int) const;
	/** @nodoc */
	virtual int IsOtherResourceFile (int) const ;                                         
	/** @nodoc */
	void SetMsgParameter (const CATString& searchKey,
		int nbParameter,
		CATUnicodeString iTabOfParameter[]);
	/** @nodoc */
	CATUnicodeString * GetMsgParameter (const CATString& searchKey , int nbParameter);

	// agent prompt does not exist anymore.
	/** @nodoc */
	virtual void SetPrompt (CATString text);
	/** @nodoc */
	virtual CATString GetPrompt ();

	/** @nodoc */
	virtual void SetUndoTitle (const CATUnicodeString& text);
	/** @nodoc */
	virtual void SetRedoTitle (const CATUnicodeString& text);
	/** @nodoc */
	virtual CATUnicodeString& GetUndoTitle ();
	/** @nodoc */
	virtual CATUnicodeString& GetRedoTitle ();

	/*----------------------------------------------------*/
	/*  undo/redo management                              */
	/*----------------------------------------------------*/

	/** @nodoc */
	virtual void UndoCommand ();
	/** @nodoc */
	virtual void RedoCommand ();

	/**
	* Before  an agent's undo.
	* <br><b>Role:</b>
	*   This method is executed before the transaction undo and must not 
	*   modify transactional objects.
	*   <br>Method to overwrite, if necessary, if your @href CATStateCommand is a <tt>CATDialogAgent</tt>
	*/
	virtual void BeforeUndo ();

	/**
	* Before an agent's redo.
	* <br><b>Role:</b>
	*   This method is executed before the transaction redo and must not 
	*   modify transactional objects.
	*   <br>Method to overwrite, if necessary, if your @href CATStateCommand is a <tt>CATDialogAgent</tt>
	*/
	virtual void BeforeRedo ();

	/**  
	* After an agent's undo.
	* <br><b>Role:</b>
	*   This method is executed after the transaction undo and must not 
	*   modify transactional objects.
	*   <br>Method to overwrite, if necessary, if your @href CATStateCommand is a <tt>CATDialogAgent</tt>
	*/
	virtual void AfterUndo ();

	/**  
	* After an agent's redo.
	* <br><b>Role:</b>
	*   This method is executed after the transaction redo and must not 
	*   modify transactional objects.
	*   <br>Method to overwrite, if necessary, if your @href CATStateCommand is a <tt>CATDialogAgent</tt>
	*/
	virtual void AfterRedo ();

	/** @nodoc */
	virtual void Reset (); 

	/*----------------------------------------------------------*/
	/* Returns the state command it belongs to                  */
	/*----------------------------------------------------------*/

	/** @nodoc */
	CATDialogAgent * GetCallingCommand ();

	/*----------------------------------------------------------*/
	/* Filter handling                                          */
	/*----------------------------------------------------------*/

	/**
	* Creates a AND combination of two filters.
	* @param iFilter1
	*   The first filter.
	* @param iFilter2
	*   The second filter.
	* @return 
	*   The resulting filter.
	*   <br><b>Cyclic reference</b>: A pointer to the filter is kept and
	*   Released at the end of the command before the command destructor call.
	*   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
	*   returned value.
	* See also: @href CATStateCommand#Filter method.
	*/
	CATAcquisitionFilter * AndFilter (CATAcquisitionFilter * iFilter1,
		CATAcquisitionFilter * iFilter2);
	/**
	* Creates a OR combination of two filters.
	* @param iFilter1
	*   The first filter.
	* @param iFilter2
	*   The second filter.
	* @return 
	*   The resulting filter.
	*   <br><b>Cyclic reference</b>: A pointer to the filter is kept and
	*   Released at the end of the command before the command destructor call.
	*   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
	*   returned value.
	* See also: @href CATStateCommand#Filter method.
	*/
	CATAcquisitionFilter * OrFilter (CATAcquisitionFilter * iFilter1,
		CATAcquisitionFilter * iFilter2);
	/**
	* Creates a filter reverse of another one.
	* @param iFilter
	*   The genuine filter.
	* @return 
	*   The resulting filter.
	*   <br><b>Cyclic reference</b>: A pointer to the filter is kept and
	*   Released at the end of the command before the command destructor call.
	*   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
	*   returned value.
	* See also: @href CATStateCommand#Filter method.
	*/
	CATAcquisitionFilter * NotFilter (CATAcquisitionFilter * iFilter);

	/*----------------------------------------------------------*/
	/* Manages the life cycle of the envelop					*/
	/*----------------------------------------------------------*/

	/** @nodoc */
	virtual void EndCommand ();
  
	/*---------------------------------*/
	// OBSOLETE AND DEPRECATED METHODS 
	/*---------------------------------*/

	/**
	* @nodoc
	* OBSOLETE : Use SetBehavior instead.
	*/
	void SetRepeatMode (ModeOffOn);

	/** @nodoc */
	virtual void RemoveAcquisition ();

protected:

	/**
	* @nodoc 
	* Do not use : Ctor for agents with their own letter (ex:CATStateCommand)
	*/
	CATDialogAgent (const CATString & iId,
		CATCommandMode iMode);
	/**
	* @nodoc 
	* Do not use : Specific Ctor for specific CATStateCommand
	*/
	CATDialogAgent (const CATString & iId, 
		CATCommandMode iMode,
		CATFrmEditor * iEditor);
	/**
	* @nodoc 
	* Do not use : Specific Ctor for specific CATStateCommand
	*/
	CATDialogAgent (const CATString & iId, 
		CATCommandMode iMode,
		CATCommand * iFather);

	CATECmdAgentEngine * _Implement; 

protected:

	/*----------------------------------------------------------*/
	/* Set/Retrieve the agent properties	-DE² use-			*/
	/*----------------------------------------------------------*/
	/** @nodoc */
	virtual HRESULT _GetProperty(CATUnicodeString iPropertyId, CATBaseUnknown_var& iospPropValue);
	virtual HRESULT _SetProperty(CATUnicodeString iPropertyId, const CATListValCATBaseUnknown_var& ispPropValue);

private:
	// NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
	CATDialogAgent & operator= (const CATDialogAgent &);

	/*----------------------------------------------------------*/
	/* Set/Retrieve the agent properties	-DE² use-			*/
	/*----------------------------------------------------------*/
	/** @nodoc */
	HRESULT GetProperty(CATUnicodeString iPropertyId, CATBaseUnknown_var& iospPropValue);
	HRESULT SetProperty(CATUnicodeString iPropertyId, const CATListValCATBaseUnknown_var& ispPropValue);
  
  /*---------------------------------------------*/
  // Event data (used with CEF & C-Afr Url viewer)
  /*---------------------------------------------*/
  /** @nodoc */
public:
  void SetJsonData(const CATUnicodeString iJsonData);
private:
  CATUnicodeString _jsonData;

  /*---------------------------------------------*/
  // Dump to DE² methods
  /*---------------------------------------------*/
  /**
  * @nodoc 
  *  Internal use only 
  */
  virtual CATBoolean IsListenningToEvent()const;
  virtual int        GetListennedEventNb()const;
  virtual void       GetListennedEvent(int iIdx, CATCommand** oSender, CATString& oEvent)const;

  friend class CATDE2TargetPrivateImplementation;
  friend class CATDE2DumpCppStateCommand;
};

#endif
