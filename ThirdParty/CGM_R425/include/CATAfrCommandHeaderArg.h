// COPYRIGHT Dassault Systemes 2008

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#ifndef CATAfrCommandHeaderArg_H
#define CATAfrCommandHeaderArg_H

#include "CATAfrFoundation.h"
#include "CATBaseUnknown.h"
#include "CATString.h"
#include "CATUnicodeString.h"

/**
* Class representing an argument.
*
* <br><b>Role</b>: Argument for a command header to pass to its command.
* <br>A @href CATAfrCommandHeaderArgs is a collection of CATAfrCommandHeaderArg.
*/
class ExportedByCATAfrFoundation CATAfrCommandHeaderArg: public CATBaseUnknown
{
  CATDeclareClass;

  public:

   /**
    * Argument modes.
    * @param In
    *    Input argument 
    * @param Out
    *    Output argument
    * @param InOut
    *    Input-Output argument
    */
    enum ArgumentMode {In, Out, InOut};

    CATAfrCommandHeaderArg (const CATString iID, const CATBaseUnknown_var iValue, const ArgumentMode iMode);
    CATAfrCommandHeaderArg (); // ("", NULL_var, In)

    virtual ~CATAfrCommandHeaderArg ();

    CATAfrCommandHeaderArg (CATAfrCommandHeaderArg &);

    CATAfrCommandHeaderArg& operator=(CATAfrCommandHeaderArg&);

    /**
     * Get the value.
     */
    const CATBaseUnknown_var GetValue ();

    /**
     * Change the value.
     * <br>Returns E_INVALIDARG if the new value type is not compatible with the old value type.
     * @param 
     *  The value.
     */
    HRESULT SetValue (const CATBaseUnknown_var);

    /**
     * Get the identifier.
     */
    const CATString  & GetID ();

    /**
     * Get the Argument mode.
     */
    const ArgumentMode GetMode ();


private:

  CATString _ID;
  CATBaseUnknown_var _Value;
  ArgumentMode _Mode;
};

/**
 * @nodoc
 *
 * Converts the extracted value from a CATAfrCommandHeaderArg using the GetValue
 * member function.
 * i_spValue the value get from the CATAfrCommandHeaderArg using GetValue.
 * o_convertedValue the argument value converted to a string.
 * Returns E_FAIL if the value can't be converted, otherwise S_OK.
 */
ExportedByCATAfrFoundation HRESULT CATAfrConvertValueToString(const CATBaseUnknown_var & i_spValue, CATUnicodeString & o_convertedValue);

#endif
