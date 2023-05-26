/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2005

#ifndef CATOmbSwitchSessionService_H
#define CATOmbSwitchSessionService_H

/**
 * @level Protected 
 * @usage U1
 */

#include "CATOmbSessionService.h"
#include "CATOmbSwitchEngine.h"
class CATIOmiSwitchEngine;

/**
* This class provides a Session service that allows the creation of a CATIOmiSwitchEngine.
*/
class ExportedByCATOmbSwitchEngine CATOmbSwitchSessionService : public CATOmbSessionService
{
            
public:
    

    CATOmbSwitchSessionService(CATOmbSessionContext *ipSessionContext = NULL);
        
    virtual ~CATOmbSwitchSessionService();
    
    /**
    * Instanciates a new Switch Engine
    *
    * @param oSwitchEngine
    *   The switch engine that has been instanciated. SwitchEngine is addreffed.
    *
    * @return  
    *           S_OK           : Switch has been correclty instanciated.       
    *      <br> E_FAIL         : unexpected error.
    */
    HRESULT CreateSwitchEngine(CATIOmiSwitchEngine*& opSwitchEngine);
    
    
private:
    
    
    // Copy Constructor and copy operator are forbidden. 
    CATOmbSwitchSessionService (CATOmbSwitchSessionService &);
    CATOmbSwitchSessionService& operator=(CATOmbSwitchSessionService&);
    
    
};

#endif


