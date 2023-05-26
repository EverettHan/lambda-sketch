/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2005

#ifndef CATOmbAfterSwitchEvent_H
#define CATOmbAfterSwitchEvent_H

/**
 * @level Protected 
 * @usage U1
 */

#include "CATOmbSwitchEvent.h"


/**
* Event sent after a Switch transtition from one representation to another one. 
* It allows listener to perform specific treatement since a different representation is now used. 
*/
class ExportedByCATOmbSwitchEngine CATOmbAfterSwitchEvent:public CATOmbSwitchEvent
{
            
public:
    CATDeclareClass;

    CATOmbAfterSwitchEvent();
    
    /**
    * Destroys the service.    
    *<br> Frees the ressources of this object. 
    **/
    virtual ~CATOmbAfterSwitchEvent();            
    
private:
    
    
    // Copy Constructor and copy operator are forbidden. 
    CATOmbAfterSwitchEvent (CATOmbAfterSwitchEvent &);
    CATOmbAfterSwitchEvent& operator=(CATOmbAfterSwitchEvent&);
    
    
};

#endif


