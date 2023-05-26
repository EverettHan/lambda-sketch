#ifndef CATPSO_h
#define CATPSO_h


// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */



#include "SceneGraphManager.h"
#include "CATXSO.h"

/**
*   
*   Class representing the set of pre-hihglighted objects.
*
*   @see CATHSO, CATAddElements, CATRemoveElements
*/
class ExportedBySceneGraphManager CATPSO : public CATXSO
{
public  :
   /** @nodoc */
  CATDeclareClass;

  /**
   * Completes the action of adding elements to the set.
   * <br><b>Role</b>: Asks visu manager to put in pre-highlight all elements
   * of the set and sends a @href CATAddElements notification with the list of all elements
   * that have been really pre-highlighted.
   *
   * @see CATXSO#AddElement, CATXSO#AddElements, CATAddElements
   */
  virtual void EndAddElements   ();


  /**
   * Completes the action of removing elements from the set.
   * <br><b>Role</b> : Asks to the visu manager, @href CATVisManager, to remove 
   * pre-highlight of all elements of the set and sends a @href CATRemoveElements 
   * notification with the list of all elements
   * that have been really un pre-highlighted.
   *
   * @see CATXSO#RemoveElement, CATXSO#RemoveElements, CATRemoveElements
   */
  virtual void EndRemoveElements   ();


  /**
   * Empties all elements in the set.
   * <br><b>Role</b>: Asks to the visu manager, @href CATVisManager, to remove pre-highlight 
   * of all elements actually pre-highlighted and sends a @href CATRemoveElements notification 
   * with the list of all elements that have been really un pre-highlighted.
   */
  virtual void Empty(void);


};

#endif
