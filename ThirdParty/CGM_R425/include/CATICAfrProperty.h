
#ifndef CATICAfrProperty_H
#define CATICAfrProperty_H

// COPYRIGHT DASSAULT SYSTEMES 2011/09/28
/**
 * @level Protected
 * @CAA2Usage U3
 */

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"
#include "CATLISTV_CATBaseUnknown.h"

extern ExportedByCATAfrItf  IID IID_CATICAfrProperty ;

//-----------------------------------------------------------------------------
/**
* Interface to manage Afr property.
*/
class ExportedByCATAfrItf CATICAfrProperty: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

    /**
    * Sets the boxed value.
	*  @param ispPropBoxedValue
    *    The boxed value
	*  @param iNotifyDataBlock
    *    A notification flag
	*  @return 
    *    An HRESULT value 
	*/
    virtual HRESULT SetPropertyValue( const CATBaseUnknown_var ispPropBoxedValue, const CATBoolean & iNotifyDataBlock = FALSE ) = 0;

    /**
    * Retrieves the value.
	*  @param ospPropValue
    *    The returned value
	*  @return 
    *    An HRESULT value. 
    */
    virtual HRESULT GetPropertyValue( CATBaseUnknown_var& ospPropValue ) = 0;

    /**
	* Sets a minimum value.
	* <b>Role</b>: Specifies the minimum value of the property referenced by the given name.
    * The value is a CATBaseUnknown_var : depending on the type of the property, 
    * it can be directly assigned for object types or it has to be encapsulated 
    * in a box for primitive data types.  
    * 
    * The following code is an example of how to use the SetMinimumValue method 
    * for a property of type int :
    * @code
    * introspectableExt->SetMinimumValue(CATBoxingOfint::Box(0));
    * @endcode
	*
    * @param i_minValue
	*   The minimum value. Can be NULL_var if no minimum value exists.
    *   the value must be compatible with the corresponding property type.
	*
	*  @return
	*    An HRESULT value. 
	*    <br><b>Legal values</b>:
    *    <ul>
    *      <li><b>S_OK</b>The function was executed successfully.</li>
    *      <li><b>E_FAIL</b> An error occurred during the execution of the function.</li>
    *    </ul>
    */
    virtual HRESULT SetMinimumValue( const CATBaseUnknown_var& i_minValue) = 0;

    /**
	* Gets the minimum value.
	* @return
    *   The minimum value of the property referenced by the given name.
    *   Returns NULL_var if no minimum value exists.
    */
    virtual CATBaseUnknown_var GetMinimumValue( ) = 0;

    /**
	* Sets a maximum value.
    * <b>Role</b>: Specifies the maximum value of the property referenced by the given name.
    * The value is a CATBaseUnknown_var : depending on the type of the property, 
    * it can be directly assigned for object types or it has to be encapsulated 
    * in a box for primitive data types.
    * 
    * The following code is an example of how to use the SetMaximumValue method 
    * for a property of type int :
    * @code
    * introspectableExt->SetMaximumValue(CATBoxingOfint::Box(100));
    * @endcode
     * @param i_maxValue the maximum value. Can be NULL_var if no maximum value exists.
    * i_maxValue must be compatible with the corresponding property type.
	*
	*  @return
	*    An HRESULT value. 
	*    <br><b>Legal values</b>:
    *    <ul>
    *      <li><b>S_OK</b>The function was executed successfully.</li>
    *      <li><b>E_FAIL</b> An error occurred during the execution of the function.</li>
    *    </ul>
    */
    virtual HRESULT SetMaximumValue( const CATBaseUnknown_var& i_maxValue ) = 0;

    /**
	* Gets the maximum value.
	* @return
    *  The maximum value of the property referenced by the given name.
    *  Returns NULL_var if no maximum value exists.
    */
    virtual CATBaseUnknown_var GetMaximumValue( ) = 0;

    /**
    * Sets the step value used to edit the value of the property.
    * <b>Role</b>: The step value is only used for numerical properties (i.e properties of type int, float or double).
    * <br>When the user uses the arrows to change the spin box's value,
    * the value will be incremented/decremented by the amount of the single step. 
    * @param i_singleStepValue
	*   The step value.
	*  @return
	*    An HRESULT value
    */
    virtual HRESULT SetSingleStepValue(double i_singleStepValue) = 0;

    /**
    * Gets the step value used to edit the value of the property.
	* @return
	*   The step value.
    */
    virtual double GetSingleStepValue() const = 0;

    /**
    * Specifies the possible values of the property referenced by the given name.
    * <b>Role</b>:Each value is a CATBaseUnknown_var : depending on the type of the property, 
    * it can be directly assigned for object types or it has to be encapsulated 
    * in a box for primitive data types.
    * @param i_possibleValues
	*   The possible values. Can be an empty list if any value is allowed.
    *   the values must be compatible with the corresponding property type.
    * @param i_exhaustiveListFlag
	*   A flag to specify whether the possible values list is exhaustive or not
	*  @return
	*    An HRESULT value. 
	*    <br><b>Legal values</b>:
    *    <ul>
    *      <li><b>S_OK</b>The function was executed successfully.</li>
    *      <li><b>E_FAIL</b> An error occurred during the execution of the function.</li>
    *    </ul>
    */
    virtual HRESULT SetPossibleValues( const CATListValCATBaseUnknown_var& i_possibleValues, 
                                       CATBoolean i_exhaustiveListFlag = TRUE ) = 0;

    /**
    * Gets the possible values of the property referenced by the given name.
    *  @return
	*    The list of possible values.
    *    Returns an empty list if any value is allowed.
    */
    virtual const CATListValCATBaseUnknown_var& GetPossibleValues( ) = 0;

};
#endif
