// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATAdpConnectionParameters.h
// Header definition of CATAdpConnectionParameterss
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jan 2006  Creation: Code generated by the CAA wizard  EBN
//===================================================================
/**
* @level Protected
* @usage U1  
*/
#ifndef CATAdpConnectionParameters_H
#define CATAdpConnectionParameters_H

#include "CATPLMIntegrationAccess.h"

#include "CATBaseUnknown.h"
#include "CATBoolean.h"

class CATUnicodeString ;
class CATListValCATUnicodeString;
class CATPLMConnectionParameters;
//-----------------------------------------------------------------------

/**
* Class to manage PLM Parameters connections to VPDM.
*
* <br><b>Role</b>: This class provides all basic functions to manage connection parameters.
*   The connection parameters enable to autentify a connection through user, passward, role,.....  
*
*/
class ExportedByCATPLMIntegrationAccess CATAdpConnectionParameters : public CATBaseUnknown
{
public:

   /** @nodoc
    * Constructor.
    * <br><b>Role</b>: Destructor.
    */
   CATAdpConnectionParameters();

   /** @nodoc
    * Destructor.
    * <br><b>Role</b>: Destructor.
    */
  virtual ~CATAdpConnectionParameters();
   
  
   /**
    * give the list of parameters.
    * <br><b>Role:</b>This method gives the list of parameters declared.
    * @param oParamNamesList
    *   The list of parameter names.
    *
    * @return
    *   <ul>
    *   <li><tt>S_OK</tt>: List of Parameters correctly assigned. </li> 
    *   <li><tt>E_FAIL</tt>: Error.</li>
    *  </ul>
    *
  */
  HRESULT ListParameters( CATListValCATUnicodeString * oParamNamesList);

   /** 
    * puts a parameter and its value.
    * <br><b>Role:</b>This method sets a parameter and a value associated.
    * @param iParamName
    *   The parameter name. 
    * @param iParamValue
    *   The parameter value associated to parameter Name.
    *   The parameter value could be CATUnicodeString "" if you want to create a parameter without Value.
    *
    * @return
    *   <ul>
    *   <li><tt>S_OK</tt>: Parameter set correctly. </li> 
    *   <li><tt>E_FAIL</tt>: Error during parameter set.</li>
    *   <li><tt>E_INVALIDARG</tt>: Input parameter are not correct(iParamName may be NULL CATUnicodeString).</li>
    *  </ul>
    */
   HRESULT AddParameterValue(const CATUnicodeString & iParamName,  const CATUnicodeString & iParamValue );
   
   
   
 private :
  //
  CATPLMConnectionParameters* _pParameters ;

  friend class CATAdpConnectionServices ;

  /** 
  * Short role of the method.
  *
  * <br><b>Role</b>: Explain what this method does.
  *
  * @param oConnectionParameter [out,CATBaseUnknown#Release]
  *   The parameter role...
  *
  * @return
  *   <code>S_OK</code> if everything ran ok, otherwise...
  *
  */
  HRESULT GetCATPLMConnectionParameters( CATPLMConnectionParameters** oConnectionParameter ) ;

};

//-----------------------------------------------------------------------

#endif
