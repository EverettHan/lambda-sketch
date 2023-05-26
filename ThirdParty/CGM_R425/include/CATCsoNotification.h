#ifndef CATCsoNotification_h
#define CATCsoNotification_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "SceneGraphManager.h"
#include "CATNotification.h"


class CATBaseUnknown;

/**
* class CATCsoNotification.
* Class representing a notification sent by an @href CATXSO .
* <br><b>Role</b> :  notification sent when objects are added to XSO
* or removed from XSO.
*/
class ExportedBySceneGraphManager CATCsoNotification : public CATNotification
{
  CATDeclareClass;

public:

  /**
  * The default constructor take an element on which we work.
  *
  * @param iElement
  *        A pointer on the working element.
  */
  CATCsoNotification (CATBaseUnknown *iElement);

  virtual ~CATCsoNotification();
  
  /**
  * Return the working object included in the notification.
  *
  * @return
  *        A pointer on the CATBaseUnknow working object.
  */
  CATBaseUnknown * GetObject() const;

  
private:
  CATBaseUnknown * _element;

};

#endif
