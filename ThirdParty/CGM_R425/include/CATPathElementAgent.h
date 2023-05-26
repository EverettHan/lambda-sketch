#ifndef CATPathElementAgent_H
#define CATPathElementAgent_H
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 1999
// protected CATCmdDialogAgents.m

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATAcquisitionAgent.h"

//#include "CATListOfCATBaseUnknown.h"
#include "CATLISTP_CATBaseUnknown.h"
#include "CATListOfCATString.h"
#include "CATListOfInt.h"
#include "CATDialog.h"
#include "CATString.h"
#include "CATUnicodeString.h"
#include "CATDlgEngUtility.h"
#include "CATEventSubscriberTypedefs.h"
#include "CATBooleanDef.h"

// Compatibility VC7 - _SO is a #define
#if defined(_MSC_VER) && (_MSC_VER==1300) && defined(_SO)
#undef _SO
#endif

/** @nodoc */
#define STOP_LOOKING_FOR_TRUNCATED_PATH &CATPathElementAgent::_emptyPathElement

class CATFrmEditor;
class CATFrmLayout;
class CATPathElement;
class CATSO;
class CATBaseUnknown;
class CATCommand;
class CATNotification;
class CATMultiSelectionAgentUI;
class CATRepShortHelp;

/**
 * Class representing an agent dedicated to selection.
 * <b>Role</b>: <p>A Path element agent is a specific acquisition agent which
 * retrieves the path of the object under the mouse and stores it
 * as its value. The selection can be done in 3D/2D viewers or in  
 * specification trees.</p>
 * <p>The required object can be directly under the mouse or can be in the path of the
 * object under the mouse. Here is an example to understand the path truncation:
 *  <pre>
 *   Suppose a Point aggregated by an Open_Body inside a Part document included in a
 *   Product document. The path of the Point is as follows:
 *
 *   Product.1/Part.1/Open_body.2/Point.3
 *   
 *   In the specification tree or in 3D you select Point.3; the object under the mouse
 *   is Point.3 but you can require an object of its path: Open_body.2 for example. 
 *   Point.3 is the selected object whenever Open_body.2 is the required object.
 *  </pre>
 * </p>
 * <p>The object filtering is based on interface implementation. There are two kinds of filtering:
 *  <ol>
 *   <li>With an ordered list, thanks to the @href #SetOrderedTypeList method </li>
 *    <br>The interface's order is more important than the object's position in the selected path.
 *     For each interface of the list, a <tt>QI</tt> is done for all objects of the selected path 
 *     (from the leaf to the root), if one object implements the current interface, the process is 
 *     ended. The required path is from the root to this object.
 *   <li>With a non ordered list, thanks to the @href #AddElementType method</li>
 *    <br>The object's position in the selected path is more important than the interface's 
 *    order. 
 *    For each object of the selected path (from leaf to root), a <tt>QI</tt> of all 
 *    interfaces is done, if the current object implements one of them, the process is ended.
 *    The required path is from the root to this current object.
 * </ol>
 *  <pre>
 *   In the previous sample, suppose that Point implements the Itf1 interface and Open_body
 *   implements the itf2 interface.
 *   case 1: An ordered list with itf2 then itf1.
 *           The path of the agent is = Product.1/Part.1/Open_body.2/
 *
 *   case 2: A non ordered list with itf2 and itf1.
 *           The path of the agent is = Product.1/Part.1/Open_body.2/Point.3
 *  </pre>
 * </p>
 * <p>The @href #GetValue method returns the path of the required object, in case of mono-selection,
 * whenever the @href #GetListOfValues method returns the list of required objects in case of
 * multi-selection. 
 * </p>
 * @see CATPathElement
 */
class ExportedByCATDialogEngine CATPathElementAgent : public CATAcquisitionAgent
{
  
  /** @nodoc */
  CATDeclareClass;

public:
  
  /**
  * Constructs a path element agent.
  * @param iId
  *   The agent identifier. It is used to retrieve the undo/redo titles in 
  *   the command resource file.
  * @param iType
  *   The type of the expected objects.
  *   The type corresponds to an interface implemented by the object. 
  *   <br><b><Legal values></b>If it is NULL, all the objects
  *   are accepted.
  *   <br>You can add interfaces with @href #AddElementType or you can specified later
  *   an ordered list thanks to the @href #SetOrderedTypeType method.
  * @param iBehavior
  *   The behavior of the agent.
  *   <br><b>Legal values</b>: The behavior is given in the form of a
  *   concatenation of the facet values using the | character.
  *   <br>e.g.: <code>CATDlgEngRepeat|CATDlgEngActive</code>
  *   <br>If it is NULL, the agent has the default behavior value for each
  *   facet.
  *   <br>The facets specific to this agent are :
  *   <ul>
  *   <li><b>Highlight</b>: <tt>CATDlgEngWithoutSO (default)</tt>,
  *   <tt>CATDlgEngWithPSO</tt>,
  *   <tt>CATDlgEngWithHSO</tt>,
  *   or <tt>CATDlgEngWithPSOHSO</tt>.</li>
  *   <li><b>HSO manager</b>: <tt>CATDlgEngOldHSOManager (default)</tt>,
  *   or <tt>CATDlgEngNewHSOManager</tt>.</li>
  *   <li><b>Multi acquisition</b>: <tt>CATDlgEngMonoAcquisition (default)</tt>,
  *   <tt>CATDlgEngMultiAcquisition</tt>,
  *   <tt>CATDlgEngMultiAcquisitionCtrl</tt>,
  *   <tt>CATDlgEngMultiAcquisitionUserCtrl</tt>,
  *   <tt>CATDlgEngMultiAcquisitionSelModes</tt> or
  *   <tt>CATDlgEngMultiAcquisitionCtrlNoFeedback</tt>. </li>
  *   <li><b>Deep acquisition</b>: <tt>CATDlgEngWithoutDeepSel (default)</tt>,
  *   <tt>CATDlgEngWithDeepSel</tt>,
  *   or <tt>CATDlgEngWithDeepFirstSel</tt>.</li>
  *   <li><b>Truncation</b>: <tt>NULL (default)</tt>,
  *   or <tt>CATDlgEngNoSubPath</tt>.</li>
  *   <li><b>Valuation from CSO</b>: <tt>CATDlgEngNotValuedFromCSO (default)</tt>,
  *   or <tt>CATDlgEngValuedFromCSO</tt>.</li>
  *   <li><b>Valuation from genuine or filtered paths</b>: <tt>NULL (default)</tt>,
  *   or <tt>CATDlgEngCSOAgentValuedFromFilteredPath</tt>.</li>
  *   <li>Valuation mode</b>: <tt>CATDlgEngSimpleValuation (default)</tt>,
  *   <tt>CATDlgEngWithPrevaluation</tt>,
  *   <tt>CATDlgEngWithManipulation</tt>,
  *   <tt>CATDlgEngWithEdit</tt>,
  *   <tt>CATDlgEngWithContext</tt>,
  *   or <tt>CATDlgEngWithDrag</tt>.</li>
  *   <li><b>Tooltip</b>: <tt>CATDlgEngWithoutTooltip (default)</tt>,
  *   or <tt>CATDlgEngWithTooltip</tt>.</li>
  *   <li><b>User Selection Filter</b>: <tt>CATDlgEngWithoutUserSelectionFilter (default)</tt>,
  *   or <tt>CATDlgEngWithUserSelectionFilter</tt>.</li>
  *   </ul>
  *   The behavior may be specified later with the @href CATDialogAgent#SetBehavior 
  *   method.
  */
  CATPathElementAgent (const CATString &iId, 
                       CATClassId iType=NULL, 
                       CATDlgEngBehavior iBehavior=NULL);
  
  virtual ~CATPathElementAgent ();

   
  /**
  * Requests the CATPathElementAgent delayed destruction.
  * <br><b>Role</b>: The CATPathElementAgent will be destroyed as soon as this will be possible
  */  
  virtual void RequestDelayedDestruction();
  
  /*---------------------------------*/
  //     TYPE FILTERING 
  /*---------------------------------*/
  
  /**
  * Sets an object type expected by the agent.
  * <br><b>Role</b>: The type corresponds to an interface implemented by the 
  * object. 
  * <br>This method may be used several times: then the expected objects must
  * implement one of the given interfaces.
  * <br>However this method cancels any previous use of @href 
  * #SetOrderedTypeList which is an incompatible method.
  * <br>By using a non-ordered type list, for each object in the selection path
  * the agent checks whether it adheres to one of the types until it founds one.
  * @param iTypeIID
  *   It is the identifier of an interface that the expected objects
  *   must implement.
  * @see #SetOrderedTypeList
  */
  void AddElementType (const IID & iTypeIID);

  /**
  * Sets an object type expected by the agent.
  * <br><b>Role</b>: The type corresponds to an interface implemented by the 
  * object. 
  * <br>This method may be used several times: then the expected objects must
  * implement one of the given interfaces.
  * <br>However this method cancels any previous use of @href 
  * #SetOrderedTypeList which is an incompatible method.
  * <br>By using a non-ordered type list, for each object in the selection path
  * the agent checks whether it adheres to one of the types until it founds one.
  * @param iTypeClassId
  *   It is the identifier of an interface that the expected objects
  *   must implement.
  * @see #SetOrderedTypeList
  */
  void AddElementType (CATClassId iTypeClassId);

  /** @nodoc */
  void SetElementType (const IID & iTypeIID);

  /** @nodoc */
  void SetElementType (CATClassId iTypeClassId);
  
  /**
  * Sets an ordered list of object types expected by the agent.
  * <br><b>Role</b>: A type corresponds to an interface implemented by the 
  * object. 
  * <br>This method may give several types: then the expected objects must implement
  * one of the given interfaces.
  * <br>Since an agent has only one ordered type list,
  * successive calls to <tt>SetOrderedTypeList</tt> for the same agent
  * successively overwrite the list.
  * Moreover this method cancels any previous use of @href #AddElementType 
  * which is an incompatible method.
  * <br>By using an ordered type list, for each type in the list
  * the agent checks whether an object in the selection path adheres to it
  * until it founds one.
  * @param iOrderedTypeList
  *   The ordered type list.
  * @see #AddElementType
  */
  void SetOrderedTypeList (const CATListOfCATString & iOrderedTypeList);
  
  /**
  * Appends an object type expected by the agent in the ordered type list.
  * <br><b>Role</b>: The type corresponds to an interface implemented by the 
  * object. 
  * <br>This method may be used several times: then the expected objects must
  * implement one of the given interfaces.
  * <br>By using an ordered type list, for each type in the list
  * the agent checks whether an object in the selection path adheres to it
  * until it founds one.
  * @param iTypeClassId
  *   It is the identifier of an interface that the expected objects
  *   must implement.
  * @see #SetOrderedTypeList, #AddElementType
  */
  void AddOrderedElementType (CATClassId iTypeClassId);

  /**
  * Resets the list of object types expected by the agent and adds an object type in the ordered type list.
  * <br><b>Role</b>: The type corresponds to an interface implemented by the 
  * object. 
  * <br>By using an ordered type list, for each type in the list
  * the agent checks whether an object in the selection path adheres to it
  * until it founds one.
  * @param iTypeClassId
  *   It is the identifier of an interface that the expected objects
  *   must implement.
  * @see #SetOrderedTypeList, #AddElementType
  */
  void SetOrderedElementType (CATClassId iTypeClassId); 
  
  /**
  * Returns the ordered list of object types expected by the agent.
  * @return
  *   The ordered type list.
  * @see #SetOrderedTypeList
  */
  CATListOfCATString & GetOrderedTypeList () const;

  /**
  * Returns the count of object types expected by the agent.
  * <br><b>Role</b>: The count of element types ranges from 1 to n
  * if one or more (ordered or not) types are expected, 0 otherwise.
  */
  int GetElementTypeSize ();
  
  /**
  * Returns an object type from those expected by the agent
  * by using the object type index.
  * <br><b>Role</b>: This method returns the <tt>iIndex</tt>th object type
  * from those (ordered or not) expected by the dialog agent,
  * that is set using the @href #AddElementType or @href #SetOrderedTypeList methods.
  * @param iIndex
  *   The index of the object type .
  *   <br><b>Legal values</b>: <tt>iIndex</tt> range starts with 1, which 
  *   is the default.
  *   Use @href #GetElementTypeSize to get the object type count.
  */
  CATClassId GetElementType (int iIndex=1);
  
  /*---------------------------------*/
  //     VALUE 
  /*---------------------------------*/
  
  /**
  * Returns the agent value.
  * <br><b>Role</b>: The value is the path of the selected object. 
  * <br>If no type has been specified, the returned path contains all the 
  * objects from the the root object to the selected object. Otherwise, with 
  * a type query, if the selected object is a child of the required object, 
  * the returned path is a subpath, that is a path that begins with the root
  * object and truncated with the first object matching the requested type.
  * <br>Moreover, the returned value depends on the @href 
  * CATAcquisitionAgent#ValuationState.
  * Indeed, if the agent valuation state is <tt>Valuated</tt>, the 
  * <tt>GetValue</tt> method returns the real value; but if the agent 
  * valuation state is <tt>PreValuated</tt>, the <tt>GetValue</tt> method 
  * returns the prevalue even if the agent has got a value. 
  * @see #AddElementType, #SetOrderedTypeList
  * @return
  *   The value.
  *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
  *   returned value.
  */
  virtual CATPathElement * GetValue ();
  
  /**
  * Sets the agent value.
  * <br><b>Role</b>: The value is a path object.
  * <br>This method does not register an undo step.
  * <br><b>Postcondition</b>: Use the @href CATAcquisitionAgent#SetValuation
  * method to make the agent accept the value, otherwise this value is not
  * taken into account.
  * @param iValue
  *   The value.
  *   <br><b>Cyclic reference</b>: A copy of <tt>iValue</tt> is kept and  
  *   AddRef'ed. It is Released in the agent destructor.
  */
  virtual void SetValue (CATPathElement * iValue );
  
  /**
  * Returns the agent list of values.
  * <br><b>Role</b>: This method is usable only on MultiAcquisition objects, 
  * otherwise use the @href #GetValue method.
  * <br>Moreover, the returned list depends on the @href 
  * CATAcquisitionAgent#ValuationState.
  * Indeed, if the agent valuation state is <tt>Valuated</tt>, the 
  * <tt>GetListofValues</tt> method returns the real list of values; but if
  * the agent valuation state is <tt>PreValuated</tt>, the 
  * <tt>GetListOfValues</tt> method returns the list of prevalues even if
  * the agent has got values. 
  * @return
  *   The list of values.
  *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
  *   returned list.
  */
  virtual CATSO * GetListOfValues ();
  
  /**
  * Sets the agent list of values.
  * <br><b>Role</b>: This method is usable only on MultiAcquisition objects,
  * otherwise use the @href #SetValue method.
  * <br>This method does not register an undo step.
  * <br><b>Postcondition</b>: Use the @href CATAcquisitionAgent#SetValuation
  * method to make the agent accept the value list, otherwise this list is not
  * taken into account.
  * @param iList
  *   The list of values.
  *   <br><b>Cyclic reference</b>: A copy of <tt>iList</tt> is kept and 
  *   AddRef'ed. It is Released in the agent destructor.
  */
  virtual void SetListOfValues (CATSO * iList);
  
  /**
  * Returns the selected object.
  * <br><b>Role</b>: The returned value is the required object that is the first  
  * matching the requested type. In otherwords, it is the leaf of the path 
  * returned by the @href #GetValue method. 
  * <br>Moreover, the returned value depends on the @href 
  * CATAcquisitionAgent#ValuationState.
  * Indeed, if the agent valuation state is <tt>Valuated</tt>, the 
  * <tt>GetElementValue</tt> method returns the real value; but if the agent 
  * valuation state is <tt>PreValuated</tt>, the <tt>GetElementValue</tt> method 
  * returns the prevalue even if the agent has got a value.  
  * @return
  *   The selected object.
  *   <br>If the behavior of the agent 
  * ( @href CATDlgEngBehavior ) is not <tt>CATDlgEngMonoAcquisition</tt>, in 
  * other words in case of multi-selection, the 
  *   returned value is NULL.
  *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
  *   returned value.
  */
  virtual CATBaseUnknown * GetElementValue ();
  
  /** @nodoc */
  virtual CATClassId GetValueType();
  
  /**
  * Returns whether the shift and control keys have been pushed during 
  * the selection.
  * @return
  *   The key use.
  *   <br><b>Legal values</b>: Use the defined values to decode the returned
  *   integer:
  *   <ul>
  *   <li><tt>ShiftModifierOn</tt></li>
  *   <li><tt>ControlModifierOn</tt></li>
  *   </ul>
  *   <pre>
  *   e.g.
  *   #include "CATDeviceEvent.h"
  *   ...
  *   if (Agent->GetModifier() & ControlModifierOn)
  *   ...
  *   </pre>
  */
  virtual int GetModifier ();
  
  /*---------------------------------*/
  //     TOOLTIP MESSAGE
  /*---------------------------------*/
  
  /**
  * Adds a message to the tooltip displayed over the selected object.
  * <br><b>Role</b>: This method enables to add a specific message
  * to the tooltip in addition to the path of the selected object. However, this
  * method is useless if the behavior of the agent ( @href CATDlgEngBehavior ) 
  * is <tt>CATDlgEngWithoutTooltip</tt>. 
  * @param iMsg
  *   The message to display
  * @param iPath
  *   The path object to display.
  *   This is to be used only if the preselection contains several objects.
  *   <br>If it is NULL, the current path under the mouse is displayed.
  */
  virtual void SetMessage (const CATUnicodeString iMsg,
                           const CATPathElement * iPath=NULL);
  
  /*---------------------------------*/
  //     CURSOR
  /*---------------------------------*/
  
  /**
  * Sets a customized "No Selection" cursor.
  * <br><b>Role</b>: This method enables to display a cursor different
  * from the standard "No Selection" one.
  * @param iCursor
  *   The cursor.
  *   Use @href CATDialog#DefineCursor to define the new cursor.
  */
  void SetNoSelectionCursor (CATDialog::CATDlgHCursor iCursor);

  /**
  * Resets the customized "No Selection" cursor.
  * <br><b>Role</b>: This method cancels previous uses of @href #SetNoSelectionCursor.
  */
  void ResetNoSelectionCursor ();
  
  /**
  * Sets a customized "Preselection" cursor.
  * <br><b>Role</b>: This method enables to display a cursor different
  * from the standard "Preselection" one.
  * @param iCursor
  *   The cursor.
  *   Use @href CATDialog#DefineCursor to define the new cursor.
  */
  void SetPreselectionCursor (CATDialog::CATDlgHCursor cursor);

  /**
  * Resets the customized "Preselection" cursor.
  * <br><b>Role</b>: This method cancels previous uses of @href #SetPreselectionCursor.
  */
  void ResetPreselectionCursor ();
  
  
  /*---------------------------------*/
  //     INTERNAL METHODS 
  /*---------------------------------*/
  
  /*---------------------------------*/
  /* Decode management               */
  /*---------------------------------*/
  
  /** 
  * @nodoc 
  * Override this method to check the path(es) consistency in decode process
  * BEFORE GetSubPath (path troncature).
  */
  virtual CATPathElement * PrecheckPath (CATPathElement *PathToCheck);
  
  /** 
  * @nodoc 
  * Override this method to check the path(es) consistency in decode process
  * AFTER GetSubPath (path troncature).
  */
  virtual CATPathElement * CheckPath (CATPathElement *PathToCheck, int ElementTypeListPosition);
  
  /** 
  * @nodoc 
  * Do not override DecodeNotification, use PrecheckPath and/or CheckPath.
  */
  virtual void * DecodeNotification (CATCommand* from, CATNotification * notif);

  /** 
  * @nodoc 
  * Internal use only.
  */
  void NoSoDuplication ();
  
  /*---------------------------------*/
  /* Undo and Redo management        */
  /*---------------------------------*/
  
  /** @nodoc */
  virtual void * UndoValue ();
  /** @nodoc */
  virtual void * RedoValue ();

  /** @nodoc */
  virtual void InitializeValue();
  /** 
  * @nodoc 
  * Override this method to process the path(es) in StoreValue step
  */
  virtual CATPathElement * ProcessPath (CATPathElement *PathToProcess, int ElementTypeListPosition);
  
  /** 
  * @nodoc 
  * Do not override StoreValue, use ProcessPath.
  */
  virtual void  StoreValue ();
  /** @nodoc */
  virtual void  ResetValue ();
  
  /*---------------------------------*/
  /* CSO Management                  */
  /*---------------------------------*/
  
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
  
  /** @nodoc */
  virtual CATStatusChangeRC Activate (CATCommand * FromClient,
                                      CATNotification * EvtDat);
  /** @nodoc */
  virtual CATStatusChangeRC Desactivate (CATCommand * FromClient,
                                         CATNotification * EvtDat);
  /** @nodoc */
  virtual CATStatusChangeRC Cancel (CATCommand * FromClient,
                                    CATNotification * EvtDat);

  
  /** @nodoc */
  friend class CATEDegCmdDbgAgent;
  
protected:
  
  /*------------------*/
  // internal methods 
  /*------------------*/
  // internal parts of decoding. These 2 methods are used by
  // DecodeNotification and by derived classes.
  // Decoding a multi result selection (some paths are removed)
  virtual CATSO * DecodeSO (CATSO *so);
  // Decoding a single selection
  virtual CATPathElement * DecodePath (CATPathElement *result, CATString & EltType, int *TypePos = NULL);
  // CTRL key management for multi-selection
  void CtrlManagement (CATBaseUnknown *);

  void DisplayMessage (CATPathElement * iPath);
  CATUnicodeString DisplayName (const CATPathElement * iPath,
                                const int iNbElem=3);
  
  /*---------------------------------*/
  /* Class Filter                    */
  /*---------------------------------*/
  
  /** @nodoc */
  void ChangeFilteredClassesCB (CATCallbackEvent  iEvt,
                                void             *from,
                                CATNotification  *iNotif,
                                CATSubscriberData iDonnees, 
                                CATCallback       iIdCbk);

  /** @nodoc */
  int GetFilteredElementTypeSize ();
  
  /** @nodoc */
  CATClassId GetFilteredElementType (int iIndex=1);
  
  /*------------------*/
  // internal data 
  /*------------------*/
  CATListOfCATString * _TypeList;
  CATListOfCATString * _FilteredTypeList;
  CATListOfCATString * _OrderedTypeList;
  CATListOfCATString * _FilteredOrderedTypeList;
  int                  _HasCustomFilter;
  CATPathElement     * _value;    
  CATPathElement     * _preValue;  
  CATPathElement     * _tempValue;    
  CATBaseUnknown     * _ElementValue;    
  CATSO              * _SO;
  CATSO              * _preSO;
  CATSO              * _tempSO;
  int                  _modifier;
  int                  _tempModifier;
  CATString            _Type;
  CATString            _tempType;
  int                  _IncompatibleFilter;
  
  int                  _currentValueInd;
  CATLISTP (CATBaseUnknown) _valueStack;
  CATListOfInt         _modifierStack;
  CATListOfInt         _ListPos;
  CATListOfCATString   _TypeStack;

  static CATLISTP (CATBaseUnknown) _agentList;
  static int _goodCursorAlreadySet;
  CATDialog::CATDlgHCursor _noSelectionCursor;
  CATDialog::CATDlgHCursor _preselectionCursor;
  
  int _NoSoDuplication;
  int _ctrl;
  CATSO *_ctrlSO;

  CATUnicodeString  _Message;
  int               _ShortHelpOn;
  CATRepShortHelp * _ShortHelp;

  /** @nodoc */
  static const CATPathElement _emptyPathElement;

private:

  friend CATPathElement* CATPathElementAgentCallDecodePath(CATPathElementAgent*, CATPathElement*, CATString&, int*); //Calls protected method DecodePath
  friend class CATECmdAcquisitionAgentEngine;
  //Reset the cursor for the current viewer
  void ResetCurrentWiewerCursor();

  // "Control" mode
  void UICB (CATCommand * iFrom, CATNotification * iNotif,
             CATCommandClientData iData);
  CATMultiSelectionAgentUI * _agentUI;
  CATBoolean _waitingForEnd;
  CATSO * _valuatedSO;

  // User Selection Filter
  void DispatchActivity (CATFrmLayout * iLayout,
                         int            iActivity);
  void UpdateTypeList (CATCallbackEvent   iPublishedEvent,
                       void             * iPublishingObject,
                       CATNotification  * iNotification,
                       CATSubscriberData  iClientData,
                       CATCallback        iCallback);
  void UpdateType (int                  iActivity,
                   CATListOfCATString * iTypeList,
                   CATListOfCATString * iChangeList,
                   CATListOfCATString * iFilteredList);
  CATCallback _TypeCB;
  

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATPathElementAgent ();

protected:
  
  /*----------------------------------------------------------*/
  /* Set/Retrieve the agent properties	-DE² use-			*/
  /*----------------------------------------------------------*/
  /** @nodoc */
  virtual HRESULT _GetProperty(CATUnicodeString iPropertyId, CATBaseUnknown_var& iospPropValue);
  virtual HRESULT _SetProperty(CATUnicodeString iPropertyId, const CATListValCATBaseUnknown_var& ispPropValue);
};

#endif
