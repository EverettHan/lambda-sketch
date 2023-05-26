#ifndef CATSYPPropertyDescriptorEx_h
#define CATSYPPropertyDescriptorEx_h

// IntrospectionInfrastructure framework
#include <IntroInfra.h>
#include <CATSYPPropertyDescriptor.h>

// System framework
#include <CATBaseUnknown.h>
#include <CATUnicodeString.h>
#include <CATSysMacros.h>
#include <CATLISTV_CATBaseUnknown.h>
#include <CATBoolean.h>

class CATSYPMetaClass;

/**
 * Class containing additional information of an introspectable property.
 * This information can be retrieved with the CATISYPIntrospectableExt interface.
 * This additional information is used by the tweaker infrastructure to customize 
 * the widget created to edit the introspectable properties.
 * This class implements the CATISYPIntrospectable interface so its properties can be data bound.
 * @see CATISYPIntrospectable
 * @see CATISYPIntrospectableExt
 */
class ExportedByIntroInfra CATSYPPropertyDescriptorEx : public CATBaseUnknown
{
  CATDeclareClass;

public:

  /**
   * Constructor.
   */
  CATSYPPropertyDescriptorEx(
    const CATSYPMetaClass * i_pSYPMetaClass,
    const CATUnicodeString &i_propertyName);
  virtual ~CATSYPPropertyDescriptorEx();
  
  /**
   * Returns the corresponding property descriptor.
   */
  const CATSYPPropertyDescriptor& GetPropertyDescriptor() const;

  /**
   * Sets the minimum value of the property (can be NULL_var if no minimum value exists)
   * The value is a CATBaseUnknown_var : depending on the type of the property, 
   * it can be directly assigned for object types or it has to be encapsulated 
   * in a box for primitive data types (see CATBoxing.h).
   * 
   * The following code is an example of how to use the SetMinimumValue method 
   * for a property of type int :
   * @code
   * pPropertyDescriptorExt->SetMinimumValue(CATBoxingOfint::Box(0));
   * @endcode
   * @param i_minValue the minimum value. Can be NULL_var if no minimum value exists.
   * i_minValue must be compatible with the corresponding property type.
   * @return S_OK if the operation is successful, E_FAIL otherwise.
   */
  HRESULT SetMinimumValue(const CATBaseUnknown_var& i_minValue);

  /**
   * @return the minimum value of the property (can be NULL_var if no minimum value exists)
   */
  const CATBaseUnknown_var& GetMinimumValue() const;

  /**
   * Sets the maximum value of the property (can be NULL_var if no maximum value exists)
   * The value is a CATBaseUnknown_var : depending on the type of the property, 
   * it can be directly assigned for object types or it has to be encapsulated 
   * in a box for primitive data types (see CATBoxing.h).
   * 
   * The following code is an example of how to use the SetMaximumValue method 
   * for a property of type int :
   * @code
   * pPropertyDescriptorExt->SetMaximumValue(CATBoxingOfint::Box(100));
   * @endcode
   * @param i_maxValue the maximum value. Can be NULL_var if no maximum value exists.
   * i_maxValue must be compatible with the corresponding property type.
   * @return S_OK if the operation is successful, E_FAIL otherwise.
   */
  HRESULT SetMaximumValue(const CATBaseUnknown_var& i_maxValue);

  /**
   * @return the maximum value of the property (can be NULL_var if no maximum value exists)
   */
  const CATBaseUnknown_var& GetMaximumValue() const;

  /**
   * Sets the step value used to edit the value of the property.
   * The step value is only used for numerical properties (i.e properties of type int, float or double).
   * When the user uses the arrows to change the spin box's value,
   * the value will be incremented/decremented by the amount of the single step. 
   */
  HRESULT SetSingleStepValue(double i_singleStepValue);

  /**
   * Returns the step value used to edit the value of the property.
   */
  double GetSingleStepValue() const;

  /**
   * Specifies the possible values of the property.
   * Each value is a CATBaseUnknown_var : depending on the type of the property, 
   * it can be directly assigned for object types or it has to be encapsulated 
   * in a box for primitive data types (see CATBoxing.h).
   * @param i_possibleValues the possible values. Can be an empty list if any value is allowed.
   * i_possibleValues must be compatible with the corresponding property type.
   * @return S_OK if the operation is successful, E_FAIL otherwise.
   */
  HRESULT SetPossibleValues(const CATListValCATBaseUnknown_var& i_possibleValues);

  /**
   * Returns the possible values of the property.
   * This method returns an empty list if any value is allowed.
   */
  const CATListValCATBaseUnknown_var& GetPossibleValues() const;

  /**
   * Specifies whether the possible values list is exhaustive or not.
   * By default, the ExhaustiveListFlag property is set to TRUE, i.e no other value can be set for this property.
   * @see SetPossibleValues
   */
  void SetExhaustiveListFlag(CATBoolean i_exhaustiveListFlag);

  /**
   * Returns TRUE if the possible values list is exhaustive, FALSE otherwise.
   * @see SetPossibleValues
   */
  CATBoolean GetExhaustiveListFlag() const;

private:

  CATSYPPropertyDescriptorEx(const CATSYPPropertyDescriptorEx&);
  CATSYPPropertyDescriptorEx& operator=(const CATSYPPropertyDescriptorEx&);

  const CATSYPMetaClass * _pSYPMetaClass;
  CATUnicodeString _propertyName;
  CATBaseUnknown_var _minValue;
  CATBaseUnknown_var _maxValue;
  double _singleStepValue;
  CATListValCATBaseUnknown_var * _pPossibleValues;
  CATBoolean _exhaustiveListFlag;
};

#endif // CATSYPPropertyDescriptorEx_h

