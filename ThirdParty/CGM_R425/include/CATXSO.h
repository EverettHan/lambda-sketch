#ifndef CATXSO_H
#define CATXSO_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


#include "SceneGraphManager.h"

#include "CATCallbackManager.h"
#include "list.h"

class CATAddElements;
class CATRemoveElements;
class CATNotification;
class CATSO;



/**
*   Base class of set of objects.
*   <b>Role</b>: Class representing a set of objects which must be 
*   visualized in a particular way.
*   <br>Used by inheritance by @href CATHSO and @href CATPSO .
*/
class ExportedBySceneGraphManager CATXSO : public CATCallbackManager
{
  CATDeclareClass;

public:

  /**
  * @nodoc
  * Default constructor.
  */
  CATXSO();

  virtual ~CATXSO();


  /**
  *  Returns the count of elements in the set.
  *
  * @return 
  *         The size of the set.
  */
  int GetSize ();

  /**
   * Subscripting operator.
   * <br><b>Role</b>: Returns an object using the object index.
   * <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the returned value.
   * @param iIndex
   *        The index
   *        <br><b>Legal values</b>: <tt>iIndex</tt> values are between 0 and GetSize()-1.
   * @return
   *        The object at the iIndex position
   */
  inline CATBaseUnknown * operator [] (int iIndex) const ;


  
  /**
   * Adds just one element to the set.
   * <br>The method @href #EndAddElements is automatically called after. 
   *
   * @param iElement
   *        The element to add.It must be a @href CATPathElement
   *        <br>If iElement is already a member of the set, the element is not add.
   */
  virtual void AddElement       (CATBaseUnknown *iElement);

  /**
   * Adds one element in the set, among a list of several elements.
   * <br><b>Role</b> : To add several elements to the set, use this
   * method as many times as you need and call @href #EndAddElements
   * at the end to indicate the end of the operation.
   *
   * @param iElement
   *        The element to add. It must be a @href CATPathElement.
   *        <br>If iElement is already a member of the set, the element is not add.
   */
  virtual void AddElements      (CATBaseUnknown *iElement);
  
  /**
   * Completes the action of adding elements to the set.
   * <br><b>Role</b> : This method must be overridden to complete all necessary actions
   * to add elements to the set.
   *
   * @see #AddElements
   */
  virtual void EndAddElements   ();


  /**
   * Removes just one element from the set.
   * <br>The method @href #EndRemoveElements is automatically called after.
   *
   * @param iElement
   *        The element to remove. It must be a @href CATPathElement
   */
  virtual void RemoveElement    (CATBaseUnknown * iElement);

  /**
   * Removes one element in the set, among a list of several elements.
   * <br><b>Role</b> : To remove several elements from the set, use this
   * method as many times as you need and call @href #EndRemoveElements
   * at the end to indicate the end of the operation.
   *
   * @param iElement
   *        The element to remove. It must be  a @href CATPathElement
   */
  virtual void RemoveElements   (CATBaseUnknown * iElement);

  /**
   * Completes the action of removing elements from the set.
   * <br><b>Role</b> : This method must be overridden to complete all necessary actions
   * to remove elements from the set.
   *
   * @see #RemoveElements
   */
  virtual void EndRemoveElements();

  
  /**
   * @nodoc
   * Empties all elements from the set.
   * <br>This method could be overriden to optimize the empty of the set.
   */
  virtual void Empty ();


  /**
   * Checks if an element is already in the set.
   * <br><b>Role</b>: At first this method makes a pointer comparison and it's
   * failed, the method makes a comparison in using the @href CATPathElement#operator== . 
   * @param iElement
   *        The element to look for.
   * @return 
   *  0 if iElement is not a member of the set, otherwise 1.
   */
  int  IsMember (CATBaseUnknown * iElement);



  /**
  * Returns the name of the notification which is sent when elements
  * are added to the set.
  *
  * @return
  *        The name of the notification.
  */
  static const char * GetCATAddElements();
  
  /**
  * Returns the name of the notification which is sent when elements
  * are removed from the set.
  *
  * @return
  *        The name of the notification.
  */
  static const char * GetCATRemoveElements();


 /**
  * Returns the name of the notification which is sent when 
  * it is empty.
  *
  * @return
  *        The name of the notification.
  */
  static const char * GetCATEmptyElements();

  /**
  * @nodoc
  * Deprecated - Creates a callback on CATAddElements only.
  */
  static const char * GetCATAddElement();

  /**
  * @nodoc
  * Deprecated - Creates a callback on CATRemoveElements only.
  */
  static const char * GetCATRemoveElement();

  /**
  * @nodoc
  * Deprecated - Creates a callback on CATAddElements and CATRemoveElements notifications.
  */
  CATCallbackEvent GetConnexion() const;

  
  /**
  * @nodoc
  * Init the internal cursor before the beginning of the set.
  * Deprecated - Use operator[].
  */
  void InitElementList();

  /**
  * @nodoc
  *
  * Give the next element of the set, using the internal cursor.
  * Increment the internal cursor and return the element at its new position.
  * Deprecated - Use operator[].
  *
  * @return 
  *         The next element in the set. 
  *         Return NULL if the internal cursor is at the end of the set.
  */
  CATBaseUnknown * NextElement();

  /**
  * @nodoc
  *
  * Give the element at the actual position of the internal cursor.
  * Deprecated - Use operator[].
  *
  * @return 
  *         The actual element in the list. 
  *         Return NULL if the internal cursor is at the end of the set.
  */
  CATBaseUnknown * GetCurrentElement();


protected :
   
  /** @nodoc */
  ::list<CATBaseUnknown> _Liste;
  /** @nodoc */
  CATSO *_AddElements;
  /** @nodoc */
  CATSO *_RemoveElements;
  /** @nodoc */
  CATAddElements *_AddElementsNotif;
  /** @nodoc */
  CATRemoveElements *_RemoveElementsNotif;


public:
  /** @nodoc */
  CATDeclareCBEvent (SO_NOTIFICATION);
};

/** @nodoc */

inline CATBaseUnknown * CATXSO::operator [] (int i) const { return ( (i>=0)  ? _Liste[i] : 0); }


#endif
