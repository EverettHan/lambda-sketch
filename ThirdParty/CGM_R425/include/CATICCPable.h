/* -*-c++-*- */
#ifndef CATICCPable_H
#define CATICCPable_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/** 
  * @CAA2Level L1
  * @CAA2Usage U5
  */ 

#include "CATBaseUnknown.h"
#include "UIModelInterfaces.h"

#include "CATLISTV_Declare.h"

class CATUnicodeString;
class CATLISTV(CATBaseUnknown_var);

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByUIModelInterfaces IID IID_CATICCPable;
#else
extern "C" const IID IID_CATICCPable;
#endif

/**
  * Allows users to copy and/or delete the seleted element.
  * <b>Role</b>: Implement this interface to prevent the element deletion. The Cut action is doing both a Copy and a Delete action.
  */
class ExportedByUIModelInterfaces CATICCPable: public CATBaseUnknown
{
   CATDeclareInterface;
public:

  /**
    * If the element can be deleted.
    *   @param iContext 
    *      The list of paths of selected elements. 
    *   @param oAnswer 
    *      The answer.
    *      <br><b>Legal values</b>: 1 if the element can be deleted, 0 if it cannot be deleted.
    *   @param oMessage 
    *      Defines the message to explain why the selected element cannot be deleted.
    *      The message is displayed in a pop-up box.
    *   @return 
    *      S_OK if OK, E_FAIL if fail
    */	
   virtual HRESULT CanBeDeleted(const CATLISTV(CATBaseUnknown_var)& iContext,
                                int& oAnswer,
                                CATUnicodeString& oMessage)=0;

  /**
    * If the element can be copied. 
    *   @param iContext 
    *      The list of paths of selected elements. 
    *   @param oAnswer 
    *      The answer.
    *      <br><b>Legal values</b>: 1 if the feature can be copied, 0 if it cannot be copied.
    *   @param oMessage 
    *      Defines the message to explain why the selected element cannot be copied.
    *   @return 
    *      S_OK if OK, E_FAIL if failed.
    */	
   virtual HRESULT CanBeCopied (const CATLISTV(CATBaseUnknown_var)& iContext,
                                int& oAnswer,
                                CATUnicodeString& oMessage)=0;
};

CATDeclareHandler (CATICCPable, CATBaseUnknown);

#endif

