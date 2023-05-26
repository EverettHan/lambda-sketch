// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATIPLMSessionManagement.h
// Define the CATIPLMSessionManagement interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Jan 2006  Creation: ECN
//===================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef CATIPLMSessionManagement_H
#define CATIPLMSessionManagement_H

#include "CATPLMComponentInterfaces.h"
#include "CATBaseUnknown.h"
class CATUnicodeString;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMComponentInterfaces IID IID_CATIPLMSessionManagement;
#else
extern "C" const IID IID_CATIPLMSessionManagement ;
#endif

//------------------------------------------------------------------

/**
* Interface to create and delete a batch session.
*
* <br><b>Role</b>: this interface enables you to create and delete a batch PLM session. 
* These methods include the connection and the deconnection respectively.
*

*/
class ExportedByCATPLMComponentInterfaces CATIPLMSessionManagement: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

    /** 
    * Creates a batch session and connects to a repository .
    *
    * 
    * @return
    *    S_OK:   Success 
    *    E_FAIL: Failed 
    */
  virtual HRESULT InitPLMSession()=0;
    /** 
    * Closes the connection and delete the batch session.
    * 
    * 
    * @return
    *    S_OK:   Success 
    *    E_FAIL: Failed 
    */
  virtual HRESULT ClosePLMSession()=0;


  /**
   * Declares a Property.
   * These properties define the connection parameters to a repository.
   * They are :
   *    <ul>
   *    <li> <tt>Repository</tt> : the repository name, EV5, .... </li> 
   *    <li> <tt>UserID</tt> : the  user  name  for  connection </li> 
   *    <li> <tt>UserPasswd</tt> : the  user  password  for  connection </li> 
   *    <li> <tt>Server</tt> : the  server  name  for  connection, expected  format  is  'ServerName:PortNumber </li>
   *    <li> <tt>Role</tt> : the  user  role  on  server  for  connection </li> 
   *    </ul>
   * A property must be declared only if it associated key has a non null value. The keys definition order doesn't matter.
   * @param iKey
   * The  key of the connection property
   * @param iValue
   * The  value of the connection property
   * @return
   *      <ul>
   *       <li><tt>S_OK</tt> if the property has been successfully added.</li>
   *       <li><tt>E_INVALIDARG</tt>if the parameter name is invalid or if the length of iKey is null.</li> 
   *       <li><tt>E_FAIL</tt> otherwise if it has failed.</li>
   *      </ul>  
   *  
   */
  virtual HRESULT DeclareProperty(const CATUnicodeString& iKey,const CATUnicodeString& iValue)=0;


    



  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};

//------------------------------------------------------------------

#endif
