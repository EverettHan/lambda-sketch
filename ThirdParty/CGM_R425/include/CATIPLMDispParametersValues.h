// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATIPLMDispParametersValues.h
// Define the CATIPLMDispParametersValues interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  May 2005  Creation: Code generated by the CAA wizard  sbq
//===================================================================
#ifndef CATIPLMDispParametersValues_H
#define CATIPLMDispParametersValues_H

// PPRDispatcherCClient framework
#include "CATPLMDispatcherSpecificItf.h"

// System framework
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMDispatcherSpecificItf IID IID_CATIPLMDispParametersValues;
#else
extern "C" const IID IID_CATIPLMDispParametersValues ;
#endif

//------------------------------------------------------------------

/**
* Interface representing the connection parameter values.
* <p>
* This is an additional interface for a CATIPLMDispParameters.
*
* @see PPRDispatcherCClient.CATIPLMDispParameters
*/
class ExportedByCATPLMDispatcherSpecificItf CATIPLMDispParametersValues: public CATBaseUnknown
{
  CATDeclareInterface;

public:

   /**
    * Returns a string value
    * <br><b>Role:</b>This method allows to get a connection parameter value.
    * Information is returned only if connection has been successful.
    * @param iKey
    *   Name of the parameter value.
    * @param oValue
    *   Ouput parameter, string value.
    * @return
    *   <ul>
    *   <li><tt>S_OK</tt>: Successfull. </li> 
    *   <li><tt>E_FAIL</tt>: Error. Report to GetLastError for more information.</li>
    *  </ul>
    */
  virtual HRESULT GetConnectionValue(const CATUnicodeString iKey, CATUnicodeString *oValue)= 0;

   /**
    * Returns a list of string value
    * <br><b>Role:</b>This method allows to get a connection parameter value.
    * Information is returned only if connection has been successful.
    * @param iKey
    *   Name of the parameter value.
    * @param oList
    *   Ouput parameter, list of string value.
    * @return
    *   <ul>
    *   <li><tt>S_OK</tt>: Successfull. </li> 
    *   <li><tt>E_FAIL</tt>: Error. Report to GetLastError for more information.</li>
    *  </ul>
    */
  virtual HRESULT GetConnectionValue(const CATUnicodeString iKey, CATListOfCATUnicodeString **oList)= 0;

  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};

//------------------------------------------------------------------

#endif
