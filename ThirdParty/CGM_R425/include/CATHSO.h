#ifndef CATHSO_h
#define CATHSO_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

/*
 * HISTORY : 
 *   16 Juillet 2001 - CDT : ajout d'un UUID servant d'identifiant unique entre chaque
 *      transaction du HSO. Cet identifiant va permettre de synchroniser les objets exterieurs
 *      tels que le CSO avec le HSO. Quand on ajoutera/enlevera un path du HSO, le HSO regenerera
 *      son identifiant unique de facon a dire "je vient d'etre modifie". Ainsi les objets exterieurs
 *      pourront se synchroniser sur le HSO en comparant l'uuid du HSO a l'instant t1 avec l'uuid
 *      du HSO a l'instant t2. Cela permet de savoir si le CSO est desynchroniser par rapport au HSO.
 */


#include "SceneGraphManager.h"
#include "CATXSO.h"
#include "CATUuid.h"


/**
*   Class representing the set of hihglighted objects.
*
*   @see CATPSO, CATAddElements, CATRemoveElements
*/
class ExportedBySceneGraphManager CATHSO : public CATXSO
{
public :
   /** @nodoc */
  CATDeclareClass;

  /**
   * Completes the action of adding elements to the set.
   * <br><b>Role</b> : Asks to the visu manager, @href CATVisManager, to put in highlight 
   * all elements of the set and sends a @href CATAddElements notification with the list
   * of all elements that have been really highlighted.
   *
   * @see CATXSO#AddElement, CATXSO#AddElements, CATAddElements
   */
  virtual void EndAddElements   ();

  
  /**
   * Completes the action of removing elements from the set.
   * <br><b>Role</b> : Asks to the visu manager, @href CATVisManager, to remove highlight of 
   * all elements of the set and sends a @href CATRemoveElements notification with the list of 
   * all elements that have been really unhighlighted.
   *
   * @see CATXSO#RemoveElement, CATXSO#RemoveElements, CATRemoveElements
   */
  virtual void EndRemoveElements   ();

  /**
   * Empties all elements from the set.
   * <br><b>Role</b>: Asks to the visu manager,  @href CATVisManager, to remove highlight
   * of all elements actually highlighted and sends a @href CATRemoveElements notification 
   * with the list of all elements that have been really unhighlighted.
   */
  virtual void Empty ();

  /**
   * @nodoc
   * Returns the uuid as the identifier of the HSO.
   */
  CATUuid GetIdentifier();

  private :
 /** @nodoc */
 CATUuid _Uuid; // identifiant unique pouvant servir a synchroniser objet exterieurs avec le HSO.


};

#endif

