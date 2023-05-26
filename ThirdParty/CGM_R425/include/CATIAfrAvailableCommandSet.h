#ifndef __CATIAfrAvailableCommandSet_h
#define __CATIAfrAvailableCommandSet_h

// COPYRIGHT DASSAULT SYSTEMES 2003

#include "CATBaseUnknown.h"
#include "CATAfrFoundation.h"
#include "CATCommandSet.h"


#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrFoundation IID IID_CATIAfrAvailableCommandSet;
#else
extern "C" const IID IID_CATIAfrAvailableCommandSet;
#endif

/**
  * Interface to manage command headers availability depending on specific contextes.
  * <b>Role</b>An Interface derived from CATIAfrAvailableCommandSet defines an avalability context
  * for the existing command headers. CATIAfrAvailableCommandSet should never be implemented but derived.
  * Each class implementing the derived interface builds a set of command header names.
  * When the context is activated, each command header which does not belong to the sets will be set
  * unavailable (greyed) untill the context is deactivated.
  * CATAfrAvailableCommandSetCmd class manages context activation and deactivation.
  * @see CATAfrAvailableCommandSetCmd
  */
class ExportedByCATAfrFoundation CATIAfrAvailableCommandSet: public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
    * Builds a set of available command headers.
    * <br><b>Role:</b>This method creates and returns a set of CATCommandHeader names.
    * Each command header which exists when the context is activated and does not belong to the set returned
    * by one of the implementation for the derived interface will be set unavailable (greyed)
    * untill the context is deactivated..
    * 
    * @param oSet
    *    The set of available commands. This is an output parameter:the set must be created in this 
    *    method, it will be released by the caller.
    * 
    * @return 
    * S_OK if a set was correctly built, else E_FAIL.
    */
	virtual HRESULT GetCommandSet (CATCommandSet    *& oSet) = 0;
};

#endif//__CATIAfrAvailableCommandSet_h
