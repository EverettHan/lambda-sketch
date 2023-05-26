#ifndef CATCSO_h
#define CATCSO_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATAfrFoundation.h"
#include "CATCollec.h"
#include "CATCallbackManager.h"
#include "CATBoolean.h"

class CATBaseUnknown;
class CATHSO;
class CATSO;
class CATLISTP(CATBaseUnknown);
class CATCSOChangeNotification;
class CATSelectPathTree;
class CATSysSimpleHashTable;

/**
 * Class containing the selection.
 * <b>Role</b>: This class stores a list of the currently selected
 * elements. There is only one instance of this class by document. A pointer
 * to this class is returned by @href CATFrmEditor#GetCSO method. Use this
 * class to add or remove elements from the selection.
 * <br> This class dispatches a @href CATCSOChangeNotification event 
 * when elements are added or removed from the selection.
 * <br> Elements added to the selection are automatically highlighted. Elements
 * removed from the selection are automatically unhighlighted.
 * @see CATFrmEditor, CATHSO
 */
class ExportedByCATAfrFoundation CATCSO : public CATCallbackManager
{

  /** 
   * @nodoc 
   */
  CATDeclareCBEvent (CSO_NOTIFICATION);
    
  CATDeclareClass;

public:

  /**
   * Indicates how to add a set of elements to the selection.
   * @param Merge
   *   The operation follows a XOR type merge rule. If the element
   *   was not in the selection then it is added to the selection. If
   *   the element was in the selection then it is removed from the 
   *   selection.
   * @param Replace
   *   The set of elements replaces the existing selection.
   * @param Add
   *   The set of elements is added to the existing selection.
   */
  enum AddSOType { Merge, Replace, Add } ;

  /** 
   * @nodoc 
   */
  CATCSO(CATHSO *iHSO);
  virtual ~CATCSO();

  /**
   * Adds an element to the selection.
   * @param iPathElement
   *   The element to be added to the selection.
   *   <br><b>Legal values</b>: Any valid pointer to a @href CATPathElement instance.
   *   <br><b>Cyclic reference</b>: <tt>iPathElement</tt> is 
   *   AddRef'ed. It is released either when the element is removed from the set,
   *   or when the set is deleted or emptied.
   * @param iDispatchChange
   *   Request that a @href CATCSOChangeNotification event is sent after 
   *   the operation. If the element was already in the selection, the
   *   selection is not modified and the event is not sent.
   *   <br><b>Legal values</b>: 1 or a non null value to send the event, 0 to
   *   prevent sending it. 1 is the default.
   */  
  void AddElement(CATBaseUnknown * iPathElement, int iDispatchChange=1);

  /**
   * Removes an element from the selection.
   * @param iPathElement
   *   The element to be removed from the selection.
   *   <br><b>Legal values</b>: Any valid pointer to a @href CATPathElement
   *   instance.
   * @param iDispatchChange
   *   Requests that a @href CATCSOChangeNotification event is sent after
   *   the operation. If the element was not in the selection, the
   *   selection is not modified and the event is not sent.
   *   <br><b>Legal values</b>: 1 or a non null value to send the event, 0 to
   *   prevent sending it. 1 is the default.
   */
  void RemoveElement(CATBaseUnknown * iPathElement, int iDispatchChange=1);

  /**
   * Empties the selection.
   * <br><b>Role</b>: Fast way to remove all elements from the selection.
   * @param iDispatchChange
   *   Requests that a @href CATCSOChangeNotification event is dispatched at 
   *   the end of the operation.
   *   <br><b>Legal values</b>: 1 or a non null value to send the event, 0 to
   *   prevent sending it. 1 is the default.
   */
  void Empty(int iDispatchChange=1);

  /**
   * Adds a set of elements to the selection.
   * <br><b>Role</b>: Fast way to add a set of elements to
   * selection. An @href CATCSOChangeNotification is dispatched at the
   * end of the operation.
   * @param iSO
   *   The set of elements to be added to the selection.
   *   <br><b>Legal values</b>: Each element of the set must be a pointer
   *   to a @href CATPathElement instance.
   *   <br><b>Cyclic reference</b>: A pointer to each element of the set, added 
   *   in the CSO, is kept and AddRef'ed as long as the element is in the selection.
   * @param iType
   *   Indicates how the set is added to the selection.
   *   <br><b>Legal values</b>: It can be set to either <tt>CATCSO::Merge</tt>
   *   to perform an XOR merge with the selection or to <tt>CATCSO::Replace</tt>
   *   to replace the existing selection or to <tt>CATCSO::Add</tt> to extend
   *   the existing selection.
   * @see #AddSOType
   */
  void AddSO(CATSO * iSO, AddSOType iType);

  /**
   * @nodoc
   * Retrieve an element from the selection
   */
  CATBaseUnknown * GetElement(int num);

  /**
   * Returns the number of selected elements.
   */
  int GetSize();

  /**
   * Initializes the cursor to the begining of the element list.
   * <br><b>Role</b>: Use <tt>InitElementList</tt> to initialize a
   * loop on the selected elements. Then use @href #NextElement to
   * return each element.
   */
  void InitElementList();

  /**
   * Returns the element at cursor position.
   * <br><b>Role</b>: Returns a pointer to the <tt>CATPathElement</tt>
   *   instance at the cursor position. Increments the cursor position of 1
   *   after the operation.
   *   <br> Use <tt>NextElement</tt> to loop on the selection. The following
   *   code sample may be used:
   *   <br>
   *   <code>
   *   <br>cso->InitElementList();
   *   <br>while (element = cso->NextElement())
   *   <br>{
   *   <br>  // element processing here
   *   <br>}</code>
   *   <br>
   *   <br>where <tt>cso</tt> is a pointer to a <tt>CATCSO</tt> instance.
   * @return 
   *   The element at cursor position.
   *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
   *   returned value.
   * @see #InitElementList
   */
  CATBaseUnknown * NextElement();

  /**
   * Returns the position of an element in the selection.
   * @return
   *   0 if the element is not in the list else its position. Indice in this list
   *   begins at 1. 
   */  
  int Locate(CATBaseUnknown * element);

	/**
	 * Tells whether an element is contained in the list.
	 * @return TRUE if the element is here or FALSE otherwise
	 */
	CATBoolean Contains (CATBaseUnknown *);

  /** @nodoc */
  void DispatchChange();

  /** @nodoc */  
  void AddToUndoRedoManagement();
  void RemoveFromUndoRedoManagement();

  /**
   * @nodoc
   * Disables/Enables duplicates checks in the AddSO method.
   * <br><b>Role</b>: This method should be called when duplicates
   * checks in the AddSO method are to be disabled for performance 
   * reasons. By default the duplicates checks are performed.
   * @param iCheckDuplicates
   *   The check mode.
   * <br><b>Legal values</b>: if parameter is non null then duplicates
   * are checked. Checks are suppressed if parameter is 0.
   * @return
   *   The previous check duplicate mode.
   */
  int SetCheckDuplicates(const int iCheckDuplicates);

private:

  void InternalRemoveElement(int Location, int iDispatchChange);
  void InternalAddElement(CATBaseUnknown * iPathElement,int iDispatchChange, int iCheckDuplicates);
  
  int current;
  CATLISTP(CATBaseUnknown) * _List;
  CATHSO                   * _HSO;
  CATCSOChangeNotification * _ChangeNotification;
  CATSysSimpleHashTable * _CATCSOHTable;
  static int _TransCSOenv;
  CATBoolean _TransCSO;
  int _CheckDuplicates;

};

#endif
