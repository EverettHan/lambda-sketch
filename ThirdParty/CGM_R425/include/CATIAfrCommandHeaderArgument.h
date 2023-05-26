// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// CATIAfrCommandHeaderArgument.h
// Define the CATIAfrCommandHeaderArgument interface
//
//===================================================================
//
// Usage notes:
//   Use the CATExtIAfrCommandHeaderArgument as a base class
//   when implementing CATIAfrCommandHeaderArgument is mandatory.
//===================================================================
//
//  Sep 2004  Creation: Code generated by the CAA wizard  ers
//===================================================================
#ifndef CATIAfrCommandHeaderArgument_H
#define CATIAfrCommandHeaderArgument_H

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"

class CATString;
class CATUnicodeString;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrItf IID IID_CATIAfrCommandHeaderArgument;
#else
extern "C" const IID IID_CATIAfrCommandHeaderArgument ;
#endif

//------------------------------------------------------------------

/**
  * Interface implemented by @href CATCommandHeader derived classes to manage command arguments
  * <b>Role:</b> This interface manages arguments for CATCommandHeader instances.
  * A @href CATCommandHeader instance which implements this interface will automatically give
  * its pointer to this interface as argument to the command it starts.
  * <br> 
  * <b>Important notice</b>: Using the @href CATExtIAfrCommandHeaderArgument as a base class
  * when implementing <tt>CATIAfrCommandHeaderArgument</tt> is mandatory. 
 */
class ExportedByCATAfrItf CATIAfrCommandHeaderArgument: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

  /**
    * Sets the argument value as an integer.
    * <br><b>Role:</b>
    * Use this method to set the argument value when its type is integer. Otherwise use the other methods
    * or derive the interface to add methods.
    * @param integerArgument
    *   integer value for the argument
    * @return
    *   The HRESULT value is always S_OK in the default implementation.
    */
  virtual HRESULT SetIntegerArgument (const int integerArgument) = 0;

  /**
    * Gets the argument value if its type is integer.
    * <br><b>Role:</b>
    * Use this method to get the argument value when its type is integer. Otherwise use the other methods
    * or derive the interface to add methods.
    * @param integerArgument
    *   integer value for the argument if the return code is S_OK
    * @return
    *   The HRESULT value is always S_OK if the argument was set using SetIntegerArgument, E_FAIL otherwise.
    */
  virtual HRESULT GetIntegerArgument (int & integerArgument) = 0;

  /**
    * Sets the argument value as a String.
    * <br><b>Role:</b>
    * Use this method to set the argument value when its type is CATString. Otherwise use the other methods
    * or derive the interface to add methods.
    * @param StringArgument
    *   String value for the argument
    * @return
    *   The HRESULT value is always S_OK in the default implementation.
    */
  virtual HRESULT SetStringArgument (const CATString & stringArgument) = 0;

  /**
    * Gets the argument value if its type is CATString.
    * <br><b>Role:</b>
    * Use this method to get the argument value when its type is CATString. Otherwise use the other methods
    * or derive the interface to add methods.
    * @param StringArgument
    *   String value for the argument if the return code is S_OK
    * @return
    *   The HRESULT value is always S_OK if the argument was set using SetStringArgument, E_FAIL otherwise.
    */
  virtual HRESULT GetStringArgument (CATString & stringArgument) = 0;

  /**
    * Sets the argument value as an Unicode String.
    * <br><b>Role:</b>
    * Use this method to set the argument value when its type is CATUnicodeString. Otherwise use the other methods
    * or derive the interface to add methods.
    * @param unicodeStringArgument
    *   Unicode String value for the argument
    * @return
    *   The HRESULT value is always S_OK in the default implementation.
    */
  virtual HRESULT SetUnicodeStringArgument (const CATString & unicodeStringArgument) = 0;

  /**
    * Gets the argument value if its type is CATUnicodeString.
    * <br><b>Role:</b>
    * Use this method to get the argument value when its type is CATUnicodeString. Otherwise use the other methods
    * or derive the interface to add methods.
    * @param unicodeStringArgument
    *   String value for the argument if the return code is S_OK
    * @return
    *   The HRESULT value is always S_OK if the argument was set using SetUnicodeStringArgument, E_FAIL otherwise.
    */
  virtual HRESULT GetUnicodeStringArgument (CATString & unicodeStringArgument) = 0;


  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};

//------------------------------------------------------------------

#endif
