#ifndef CATAddElements_H
#define CATAddElements_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "SceneGraphManager.h"
#include "CATCsoNotification.h"
#include "CATAddElement.h"
#include "list.h"


/**
* class CATAddElements.
* Notification sent when elements are added to a Set of Objects.
*
* Directly use the variable member <b>_ListElt</b> to add/remove elements
* or to give the whole list of them.
*
* @see CATHSO, CATPSO
*/
class ExportedBySceneGraphManager CATAddElements : public CATCsoNotification
{
  CATDeclareClass;

  public:

  /**
  * The default constructor.
  */
  CATAddElements();

  virtual ~CATAddElements();

  /**
  *  The list of all elements added in the set.
  *
  */
  list<CATBaseUnknown> _ListElt;
};

#endif
