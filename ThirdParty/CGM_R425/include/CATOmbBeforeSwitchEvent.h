/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2005

#ifndef CATOmbBeforeSwitchEvent_H
#define CATOmbBeforeSwitchEvent_H

/**
 * @level Protected 
 * @usage U1
 */

#include "CATOmbSwitchEvent.h"

/**
* Event sent before a Switch transtition from one representation to another one. 
* It allows listener to perform specific treatement since a different representation will be used. 
*/
class ExportedByCATOmbSwitchEngine CATOmbBeforeSwitchEvent:public CATOmbSwitchEvent
{
  CATDeclareClass;            
public:
    

    CATOmbBeforeSwitchEvent();
    
    /**
    * Destroys the service.    
    *<br> Frees the ressources of this object. 
    **/
    virtual ~CATOmbBeforeSwitchEvent();
                
private:
    
    
    // Copy Constructor and copy operator are forbidden. 
    CATOmbBeforeSwitchEvent (CATOmbBeforeSwitchEvent &);
    CATOmbBeforeSwitchEvent& operator=(CATOmbBeforeSwitchEvent&);
    
    
};

#endif


