/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2005

/**
* @level Private (Restricted access to PUA Framework)
* @usage U1
*/

#ifndef CATOmbSwitchSessionServiceForPUA_H
#define CATOmbSwitchSessionServiceForPUA_H

#include "CATOmbSessionService.h"
#include "CATOmbSwitchEngineForRestrictedClients.h"
class CATIOmiSwitchEngine;

/**
* This class provides a Session service that allows the creation of a CATIOmiSwitchEngine.
* This CATIOmiSwitchEngine can unload dirty documents. 
* Its usage is restricted to the PUA Framework. 
*/
class ExportedByCATOmbSwitchEngine CATOmbSwitchSessionServiceForPUA : public CATOmbSessionService
{
            
public:
    

    CATOmbSwitchSessionServiceForPUA(CATOmbSessionContext *ipSessionContext = NULL);
        
    virtual ~CATOmbSwitchSessionServiceForPUA();
    
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
    
    /**
    * Instanciates a new Switch Engine to perform unload operation without keeping modified data
    *
    * @param oSwitchEngine
    *   The switch engine that has been instanciated. SwitchEngine is addreffed.
    *
    * @return  
    *           S_OK           : Switch has been correclty instanciated.       
    *      <br> E_FAIL         : unexpected error.
    */
    HRESULT CreateSwitchEngineForRefresh(CATIOmiSwitchEngine*& opSwitchEngine);

    /**
    * Instanciates a new Switch Engine to allow OpenEngine operation whithout downgrading current loading mode.
    * Components already opened in a given loading mode keep staying in this mode when asked by OpenEngine to be switched into a downgraded loading state.
    * Switch Validate step refuses the switch in a standard way, as if the transition was not allowed by SelectiveLoading dictionary.
    * for example: when trying to open in Visualisation mode a component already opened in Edit mode.
    *
    * @param oSwitchEngine
    *   The switch engine that has been instanciated. SwitchEngine is addreffed.
    *
    * @return  
    *           S_OK           : Switch has been correclty instanciated.       
    *      <br> E_FAIL         : unexpected error.
    */
    HRESULT CreateSwitchEngineForOpenEngine(CATIOmiSwitchEngine*& opSwitchEngine);
    
private:
        
    // Copy Constructor and copy operator are forbidden. 
    CATOmbSwitchSessionServiceForPUA (CATOmbSwitchSessionServiceForPUA &);
    CATOmbSwitchSessionServiceForPUA& operator=(CATOmbSwitchSessionServiceForPUA&);       
};

#endif


