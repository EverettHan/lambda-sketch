//=======================================================================================
// WARNING: YWE 18:09:24 SINGLE-CODE 2014x => NO LOCAL CHANGE EXPECTED - USE IMPORT  
//=======================================================================================
//===================================================================
// COPYRIGHT Dassault Systemes 2013/07/19
//===================================================================
// PLMIExchangeExperienceStatus.cpp
// Header definition of class PLMIExchangeExperienceStatus
//===================================================================
//
// Usage notes: Define an exchange experience status.
//
//===================================================================
//  2013/07/19 Creation: Code generated by the 3DS wizard
//===================================================================
#ifndef PLMIExchangeExperienceStatus_H
#define PLMIExchangeExperienceStatus_H

#include "PLMExchangeInterfaces.h"
#include "CATBaseUnknown.h"

#include "CATListOfCATBoolean.h"
#include "CATListOfCATUnicodeString.h"

extern ExportedByPLMExchangeInterfaces  IID IID_PLMIExchangeExperienceStatus ;


class ExportedByPLMExchangeInterfaces PLMIExchangeExperienceStatus: public CATBaseUnknown
{
   CATDeclareInterface;

public:

   /**
   * <b> GetSessionModel :</b> Retrieve the session model associated with the controller.
   * This will allow a direct interaction with the model.
   * i.e : Views components and commands will likely use this method to directly access/modify the model. 
   *
   * @param opSession [out, PLMExchangeExperienceSession#Release] 
   * output PLMExchangeExperienceSession stored in the controller.
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *                   E_FAIL.
   */ 
  // HRESULT SetIdentification();  

   /**
   * <b> LinkWithOperations :</b> Link the status with one or multiple existing operation .
   * The created link is the  'From' one, meaning that the operation can be launched from this status.
   * It's equivalent to the operation's method : SetFromStatusLink.
   * Also set if the operation is sensitive for this status.      
   *
   * @param iListOperationId [in] 
   * input list of operation to link the status with.
   *
   * @param iListIsSensitive [in] 
   * input list of boolean to set whether or not the status link is sensistive.
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *                   E_FAIL.
   */ 
   virtual HRESULT LinkWithOperations(CATListOfCATUnicodeString & iListOperationId, CATListOfCATBoolean & iListIsSensitive) = 0 ;

};

//-----------------------------------------------------------------------

#endif
 