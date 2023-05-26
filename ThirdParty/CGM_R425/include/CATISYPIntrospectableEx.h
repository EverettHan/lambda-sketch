#ifndef CATISYPIntrospectableEx_h
#define CATISYPIntrospectableEx_h

// IntrospectionInfrastructure framework
#include <IntroInfra.h>

// System framework
#include <CATBaseUnknown.h>
#include <CATUnicodeString.h>
#include <CATLISTV_CATBaseUnknown.h>
#include <CATBoolean.h>

extern ExportedByIntroInfra IID IID_CATISYPIntrospectableEx;

class CATSYPPropertyDescriptorEx;

/** 
 * @ingroup groupCIDIntrospection
 * Interface used to enrich the property description of an introspectable object.
 * This additional information is used by the tweaker infrastructure to customize the widgets 
 * created to edit the introspectable properties.
 * @see CATISYPIntrospectable
 */
class ExportedByIntroInfra CATISYPIntrospectableEx : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
   * Returns the extended descriptor of the given property.
   * @param i_propertyName the property name
   * @return the descriptor. AddRef has been called on the returned pointer.
   * @see CATSYPPropertyDescriptorEx
   */
  virtual CATSYPPropertyDescriptorEx * GetPropertyDescriptorEx(const CATUnicodeString &i_propertyName) = 0;

  /**
   * Specifies the minimum value of the property referenced by the given name.
   * The value is a CATBaseUnknown_var : depending on the type of the property, 
   * it can be directly assigned for object types or it has to be encapsulated 
   * in a box for primitive data types (see CATBoxing.h).
   * 
   * The following code is an example of how to use the SetMinimumValue method 
   * for a property of type int :
   * @code
   * introspectableEx->SetMinimumValue("IntegerProperty", CATBoxingOfint::Box(0));
   * @endcode
   * @param i_propertyName the name of the property
   * @param i_minValue the minimum value. Can be NULL_var if no minimum value exists.
   * i_minValue must be compatible with the corresponding property type.
   * @return S_OK if the operation is successful, E_FAIL otherwise.
   */
  virtual HRESULT SetMinimumValue(const CATUnicodeString &i_propertyName, const CATBaseUnknown_var& i_minValue) = 0;

  /**
   * Returns the minimum value of the property referenced by the given name.
   * This method returns NULL_var if no minimum value exists.
   * @param i_propertyName the name of the property
   */
  virtual CATBaseUnknown_var GetMinimumValue(const CATUnicodeString &i_propertyName) = 0;

  /**
   * Specifies the maximum value of the property referenced by the given name.
   * The value is a CATBaseUnknown_var : depending on the type of the property, 
   * it can be directly assigned for object types or it has to be encapsulated 
   * in a box for primitive data types (see CATBoxing.h).
   * 
   * The following code is an example of how to use the SetMaximumValue method 
   * for a property of type int :
   * @code
   * introspectableEx->SetMaximumValue("IntegerProperty", CATBoxingOfint::Box(100));
   * @endcode
   * @param i_propertyName the name of the property
   * @param i_maxValue the maximum value. Can be NULL_var if no maximum value exists.
   * i_maxValue must be compatible with the corresponding property type.
   * @return S_OK if the operation is successful, E_FAIL otherwise.
   */
  virtual HRESULT SetMaximumValue(const CATUnicodeString &i_propertyName, const CATBaseUnknown_var& i_maxValue) = 0;

  /**
   * Returns the maximum value of the property referenced by the given name.
   * This method returns NULL_var if no maximum value exists.
   * @param i_propertyName the name of the property
   */
  virtual CATBaseUnknown_var GetMaximumValue(const CATUnicodeString &i_propertyName) = 0;

  /**
   * Sets the step value used to edit the value of the property referenced by the given name.
   * The step value is only used for numerical properties (i.e properties of type int, float or double).
   * When the user uses the arrows to change the spin box's value,
   * the value will be incremented/decremented by the amount of the single step. 
   */
  virtual HRESULT SetSingleStepValue(const CATUnicodeString &i_propertyName, double i_singleStepValue) = 0;

  /**
   * Returns the step value used to edit the value of the property referenced by the given name.
   */
  virtual double GetSingleStepValue(const CATUnicodeString &i_propertyName) const = 0;

  /**
   * Specifies the possible values of the property referenced by the given name.
   * Each value is a CATBaseUnknown_var : depending on the type of the property, 
   * it can be directly assigned for object types or it has to be encapsulated 
   * in a box for primitive data types (see CATBoxing.h).
   * @param i_propertyName the name of the property
   * @param i_possibleValues the possible values. Can be an empty list if any value is allowed.
   * i_possibleValues must be compatible with the corresponding property type.
   * @param i_exhaustiveListFlag specifies whether the possible values list is exhaustive or not
   * @return S_OK if the operation is successful, E_FAIL otherwise.
   */
  virtual HRESULT SetPossibleValues(const CATUnicodeString &i_propertyName, const CATListValCATBaseUnknown_var& i_possibleValues, CATBoolean i_exhaustiveListFlag = TRUE) = 0;

  /**
   * Returns the possible values of the property referenced by the given name.
   * This method returns an empty list if any value is allowed.
   * @param i_propertyName the name of the property
   * @param o_exhaustiveListFlag set to TRUE if the possible values list is exhaustive, to FALSE otherwise
   */
  virtual const CATListValCATBaseUnknown_var& GetPossibleValues(const CATUnicodeString &i_propertyName, CATBoolean& o_exhaustiveListFlag) = 0;

};

CATDeclareHandler(CATISYPIntrospectableEx, CATBaseUnknown);

#endif // CATISYPIntrospectableEx_h
