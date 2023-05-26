/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2005

#ifndef CATOmbSwitchEvent_H
#define CATOmbSwitchEvent_H

/**
* @level Protected 
* @usage U1
*/

#include "CATLISTP_CATOmiSwitchOperation.h"
#include "CATOmbSwitchEngine.h"
#include "CATNotification.h"

/**
* This class is derived by CATOmbBeforeSwitchEvent and CATOmbAfterSwitchEvent. 
* All events sent during or because of a Switch Operation should be derived from this baseclass. 
*/
class ExportedByCATOmbSwitchEngine CATOmbSwitchEvent:public CATNotification
{

public:
  CATDeclareClass;

  CATOmbSwitchEvent();

  /**
  * Destroys the service.    
  *<br> Frees the ressources of this object. 
  **/
  virtual ~CATOmbSwitchEvent();

  /**
  * Base class of the events throw before and after a switch operations. 
  * CATOmiSwitchOperation lifecycle is handled by the CATOmbSwitchEngine object. Therefore, returned CATOmiSwitchOperation must not be deleted. 
  *
  * @param oSwitchs
  *   A list of Switch operations that have started or finished. 
  *
  * @return  
  *           S_OK           : Switch has been correclty instanciated.       
  *      <br> E_FAIL         : unexpected error.
  */
  HRESULT GetSwitchOperations(CATLISTP(CATOmiSwitchOperation) &oSwitchs);


  /**
  * Sets the switch operation list that will be (have been) performed. 
  *
  * @param iSwitchs
  *   A list of Switch operations that  will (have been) performed. This is the list used by the switch engine. 
  *   Do not do any modifiction to the list structure. 
  *
  * @return  
  *           S_OK           : Switch has been correclty instanciated.       
  *      <br> E_FAIL         : unexpected error.
  */
  HRESULT SetSwitchOperations(CATLISTP(CATOmiSwitchOperation) &iSwitchs);    

private:

  CATLISTP(CATOmiSwitchOperation)* _pSwitchOperations;

  // Copy Constructor and copy operator are forbidden. 
  CATOmbSwitchEvent (CATOmbSwitchEvent &);
  CATOmbSwitchEvent& operator=(CATOmbSwitchEvent&);

};

#endif


