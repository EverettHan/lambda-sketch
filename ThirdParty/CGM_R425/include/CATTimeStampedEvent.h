#ifndef CATTimeStampedEvent_H
#define CATTimeStampedEvent_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATDataType.h"
#include "SGInfra.h"
#include "CATNotification.h"

#include <string.h>

//Ia64+
#include <time.h>
//Ia64-
/**
* Base class for most visualization events containing the time at which it occured.
*
* <b>Role</b>: To add to basic notifications the time at which they occured.
* The time between two events can have a significance for user interface.
* It i used to communicate between the GraphicWindow and the Viewer
*/

class ExportedBySGInfra CATTimeStampedEvent : public CATNotification
{
  CATDeclareClass;

//------------------------------------------------------------------------------
  public :

    /** @nodoc */
    CATTimeStampedEvent();
    /** @nodoc */
    virtual ~CATTimeStampedEvent();

    /**
    *  Time at which the event occured.
    */
    CATULONG32 time;		// CPU Time when the event occured

    /** @nodoc */
    inline CATTimeStampedEvent & operator = (const CATTimeStampedEvent &);

};

inline CATTimeStampedEvent & CATTimeStampedEvent::operator = (const CATTimeStampedEvent &event)
{
 time = event.time;
 return (*this);
}

#endif
