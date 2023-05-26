#ifndef IVSUIEvents_H
#define IVSUIEvents_H

//COPYRIGHT DASSAULT SYSTEMES 2012

/**
* @CAA2Level L0
* @CAA2Usage U1
*/

#include "IVInterfaces.h"
#include "CATBaseUnknown.h"

class CATSYPEvent;

/**
* Events emitted by the IVISUIEntity
*
* In order to register/unregister a component as a listener, call
* AddHandler/RemoveHandler on the SUI entity.
* @see IVISUIEntity, CATSYPEvent
*/
class ExportedByIVInterfaces IVSUIEvents : public CATBaseUnknown 
{

  CATDeclareClass;

public:

  /**
   * Event emitted
   * - by the SUI entity
   * - each time the entity has been updated and is ready to be read
   */
  static CATSYPEvent* SUIEntityUpdated();

private:

  IVSUIEvents();
  virtual ~IVSUIEvents();
};

#endif

