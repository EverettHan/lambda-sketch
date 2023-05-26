#ifndef CATVidCtlTweaker_h
#define CATVidCtlTweaker_h

// COPYRIGHT Dassault Systemes 2005

// VisuImmersiveDialogEx framework
#include <VisuDialog.h>
#include <CATVidCtl.h>
#include <CATVidBoxing.h>

// IntrospectionInfrastructure framework
#include <CATBasicBoxing.h>
#include <CATSYPPropertyDescriptor.h>
#include <CATSYPPropertyDescriptorEx.h>

// UIVCoreTools framework
#include <UIVCoreToolsInline.h>

// System framework
#include <CATBaseUnknown.h>
#include <CATUnicodeString.h>
#include <CATBoolean.h>
#include <CATLISTV_CATBaseUnknown.h>

class CATVidTweakerValidatorAbstract;
class CATVidCtlSimpleCombo;
class CATSYPEvent;

/**
 * Base class for all the different tweakers.
 * A tweaker is a widget used to edit an introspectable property value.
 * Each type of property is associated to a specific tweaker class.
 *
 * Each tweaker class must implement the generic GetData and SetData methods used to retrieve and set the 
 * property value from have a generic CATBaseUnknown. 
 * A tweaker class must also have at least the following introspectable properties :
 *   * a property called "TweakerData" of the same type as the edited property : this is
 *     the property bound to the edited introspectable property. Setting the property "TweakerData" doest NOT mean
 *     that the end user has explicitely edited the property value.
 *   * a property called "Value" of the same type as the edited property : this is
 *     the property bound in the tweaker template. Setting the property "Value" means
 *     that the end user has explicitely edited the property value (the CustomizeFlag property
 *     of the tweaker must then be set to TRUE).
 * 
 * Use the macros CATDeclareTweaker and CATImplementTweaker to create a new tweaker class
 * dealing with your boxing type.
 */
class ExportedByVisuDialog CATVidCtlTweaker : public CATVidCtl
{
  CATDeclareClass;

public:
  CATVidCtlTweaker();

  /**
  * Set the internal typed property from a string.
  * @param i_stringValue string value representation 
  */
  void SetValueAsString(CATUnicodeString i_stringValue);
/**
  * @see SetValueAsString
  */
  CATUnicodeString GetValueAsString() const;

  /**
   * Sets the edited property descriptor extension.
   */
  void SetPropertyDescriptorEx(CATSYPPropertyDescriptorEx * i_pPropertyDescriptorEx);

  /**
   * Returns the edited property descriptor.
   */
  const CATSYPPropertyDescriptor& GetPropertyDescriptor() const;

  /**
   * Returns the type of the edited property.
   * This method must be implemented by each tweaker class with the use of the macros 
   * CATDeclareTweaker and CATImplementTweaker.
   */
  virtual CATUnicodeString GetType() const {return CATUnicodeString("");};

  /**
   * @return the flag indicating if the type of the edited property is a boxing value or a CATBaseUnknown
   * This method must be implemented by each tweaker class with the use of the macros 
   * CATDeclareTweaker and CATImplementTweaker.
   */
  virtual int GetValueTypeFlag() const {return 0;};

  /**
   * Each tweaker class must implement the generic GetData and SetData methods used to retrieve and set the 
   * property value from have a generic CATBaseUnknown. 
   * The value is a CATBaseUnknown_var : depending on the type of the property, 
   * it can be directly assigned for object types or it has to be encapsulated 
   * in a box for primitive data types (see CATBoxing.h).
   * These methods must be implemented by each tweaker class with the use of the macros 
   * CATDeclareTweaker and CATImplementTweaker.
   */
  virtual CATBaseUnknown_var GetData() const {return NULL_var;};
  virtual HRESULT SetData(const CATBaseUnknown_var& i_spData) {return E_FAIL;};

  /**
   * Calls the CATSYPModifyProperty macro on all the edited introspectable properties.
   * The default implementation calls it on the properties "Value" and "TweakerData".
   * If a tweaker has additional edited introspectable properties, it must implement this
   * method to calls the CATSYPModifyProperty macro on the properties "Value" and "TweakerData"
   * and on its own introspectable properties.
   */
  virtual void CATSYPModifyEditedProperties();

  /**
   * Returns TRUE if the tweaker is initialized, FALSE otherwise.
   * The tweaker is initialized once the InternalSetData method has been called.
   */
  CATBoolean GetInitFlag() const;

  /**
   * Returns TRUE if the edited property value has been modified by the end user, FALSE otherwise.
   */
  CATBoolean GetCustomizeFlag() const;

  /**
   * Specifies the validator used by the tweaker.
   * By default, there is no validator.
   */
  void SetValidator(CATVidTweakerValidatorAbstract * i_pValidator);

  /**
   * Returns the validator used by the tweaker.
   */
  CATVidTweakerValidatorAbstract * GetValidator() const;

  int IsViewProgrammatic() const;

  /**
   * Returns the style sheet name used to generate the CATVidCtlTweaker view.
   */
  CATUnicodeString GetStyleSheetName() const;

  /**
   * Creates the CATVidCtlTweaker view with the given template and variation name,
   * using the stored style sheet name.
   * @see GetStyleSheetName
   */
  void GenerateView(const CATUnicodeString& i_templateName);

  /**
   * Returns TRUE if the tweaker supports a range (minimum and maximum value) for its edited property.
   * @see SetMinimumTweakerValue
   * @see SetMaximumTweakerValue
   */
  virtual CATBoolean SupportsRange() const;

  /**
   * Returns TRUE if the tweaker supports a range and if MinimumTweakerValue and 
   * MaximumTweakerValue have been set, FALSE otherwise.
   * @see SupportsRange
   * @see SetMinimumTweakerValue
   * @see SetMaximumTweakerValue
   */
  virtual CATBoolean GetUseRangeState() const;

  /**
   * Sets the minimum value of the property (can be NULL_var if no minimum value exists)
   * The value is a CATBaseUnknown_var : depending on the type of the property, 
   * it can be directly assigned for object types or it has to be encapsulated 
   * in a box for primitive data types (see CATBoxing.h).
   * 
   * The following code is an example of how to use the SetMinimumTweakerValue method 
   * for a property of type int :
   * @code
   * pTweaker->SetMinimumTweakerValue(CATBoxingOfint::Box(0));
   * @endcode
   * @param i_minValue the minimum value. Can be NULL_var if no minimum value exists.
   * i_minValue must be compatible with the corresponding property type.
   * @return S_OK if the operation is successful, E_FAIL otherwise.
   */
  HRESULT SetMinimumTweakerValue(const CATBaseUnknown_var& i_minValue);

  /**
   * @return the minimum value of the property (can be NULL_var if no minimum value exists)
   */
  const CATBaseUnknown_var& GetMinimumTweakerValue() const;

  /**
   * Sets the maximum value of the property (can be NULL_var if no maximum value exists)
   * The value is a CATBaseUnknown_var : depending on the type of the property, 
   * it can be directly assigned for object types or it has to be encapsulated 
   * in a box for primitive data types (see CATBoxing.h).
   * 
   * The following code is an example of how to use the SetMaximumTweakerValue method 
   * for a property of type int :
   * @code
   * pTweaker->SetMaximumTweakerValue(CATBoxingOfint::Box(100));
   * @endcode
   * @param i_maxValue the maximum value. Can be NULL_var if no maximum value exists.
   * i_maxValue must be compatible with the corresponding property type.
   * @return S_OK if the operation is successful, E_FAIL otherwise.
   */
  HRESULT SetMaximumTweakerValue(const CATBaseUnknown_var& i_maxValue);

  /**
   * @return the maximum value of the property (can be NULL_var if no maximum value exists)
   */
  const CATBaseUnknown_var& GetMaximumTweakerValue() const;

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
  int GetSingleStepValueAsInt() const;

  /**
   * Calls the CATSYPModifyProperty macro on the introspectable properties
   * impacted by the MinimumTweakerValue change.
   */
  virtual void CATSYPModifyMinimumProperties();

  /**
   * Calls the CATSYPModifyProperty macro on the introspectable properties
   * impacted by the MaximumTweakerValue change.
   */
  virtual void CATSYPModifyMaximumProperties();

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

  /**
   * Sets the selected index of the tweaker combo box.
   * The tweaker uses a combo box when the edited property is an enum or
   * when a list of possible values has been set for the property.
   * @see CATVidCtlTweakerEnum
   * @see SetPossibleValues
   */
  virtual void SetSelectedIndex(int i_index);

  /**
   * Returns the selected index of the tweaker combo box.
   * The tweaker uses a combo box when the property is an enum or
   * when a list of possible values has been set for the property.
   * @see CATVidCtlTweakerEnum
   * @see SetPossibleValues
   */
  int GetSelectedIndex() const;

  /**
   * Sets the selected string of the tweaker combo box.
   * @see SetSelectedIndex
   */
  void SetSelectedString(const CATUnicodeString& i_value);

  /**
   * Returns the selected string of the tweaker combo box.
   * @see GetSelectedIndex
   */
  CATUnicodeString GetSelectedString() const;

  /**
   * Specifies whether the tweaker uses transactions for editing the property or not.
   * When the tweaker uses an edition transaction, the following events are emitted :
   *   - EditingStarted : event emitted at the beginning of the edition transaction before any value modification
   *   - ValueLiveChanged : event emitted (potentially several times per transaction) when the value is 
   *     modified during the end user interaction (e.g the drag of a slider or the multipress of a 
   *     spinbox in a tweaker of double)
   *   - ValueChanged : event emitted when the transaction is about to finish and when the value has been 
   *     modified during this transaction
   *   - EditingFinished : event emitted at the end of the edition transaction after any value modification
   *
   * When the tweaker does not use any edition transaction (the default behavior), only the ValueChanged event is 
   * emitted when the property value is modified.
   *
   * By default, the UseTransactionFlag property is set to FALSE.
   *
   * @see EditingStarted
   * @see ValueLiveChanged
   * @see ValueChanged
   * @see EditingFinished
   * @see SetUseDetailedViewTransactionFlag
   */
  void SetUseTransactionFlag(CATBoolean i_useTransactionFlag);

  /**
   * Returns TRUE if the tweaker uses transactions for editing the property, FALSE otherwise.
   * By default, the UseTransactionFlag property is set to FALSE.
   * @see SetUseTransactionFlag
   */
  CATBoolean GetUseTransactionFlag() const;

  /**
   * Specifies whether the duration of the edition transaction is related to the display of the 
   * tweaker detailed view or not.
   * Some tweakers are using a detailed view displayed in a popup window to edit the property (e.g the the Color tweaker).
   * When the tweaker uses an edition transaction and when the UseDetailedViewTransactionFlag property is set to TRUE,
   * the following events are emitted :
   *   - EditingStarted : event emitted at the beginning of the edition transaction when the tweaker detailed view is displayed
   *   - EditingFinished : event emitted at the end of the edition transaction when the tweaker detailed view is closed
   *
   * By default, the UseDetailedViewTransactionFlag property is set to FALSE.
   * Note that this property has an effect only when the other UseTransactionFlag property is set to TRUE.
   *
   * @see EditingStarted
   * @see EditingFinished
   * @see SetUseTransactionFlag
   */
  void SetUseDetailedViewTransactionFlag(CATBoolean i_useDetailedViewTransactionFlag);

  /**
   * Returns TRUE if the duration of the edition transaction is related to the display of the 
   * tweaker detailed view, FALSE otherwise.
   * By default, the UseDetailedViewTransactionFlag property is set to FALSE.
   * @see SetUseDetailedViewTransactionFlag
   */
  CATBoolean GetUseDetailedViewTransactionFlag() const;

  /**
   * Returns TRUE if the tweaker is under an edition transaction, FALSE otherwise.
   * An edition transaction begins with the dispatch of the EditingStarted event and 
   * ends with the dispatch of the EditingFinished one.
   * @see SetUseTransactionFlag
   * @see EditingStarted
   * @see EditingFinished
   */
  INLINE CATBoolean GetInEditionTransactionState() const {return _inEditionTransactionState;};

  /**
   * Returns TRUE if the tweaker detailed view is visible, FALSE otherwise.
   */
  INLINE CATBoolean GetDetailedViewVisibleState() const {return _detailedViewVisibleState;};

  /**
   * Specifies whether the tweaker value is undefined or not.
   * When a tweaker value is undefined, the tweaker view does not display any value until the end user enters one.
   * By default, the UndefinedFlag property is set to FALSE.
   */
  void SetUndefinedFlag(CATBoolean i_undefinedFlag);

  /**
   * Returns TRUE if the tweaker value is undefined, FALSE otherwise.
   */
  INLINE CATBoolean GetUndefinedFlag() const {return _undefinedFlag;}

  /**
   * Sets a flag indicateing that the current entry of the value is badly expressed. Especially usefull in case of default serialization of value.
   */
  void SetIncorrectInputFlag(int i_incorrectInputFlag);
  /** @return if the current entry value is in a correct form.*/
  int GetIncorrectInputFlag() const;

  /**
   * Returns the @c EditingStarted event.
   * The @c EditingStarted event is emitted by the tweaker at the beginning of the edition transaction 
   * before any value modification.
   * This event is emitted only when the UseTransactionFlag property is set to TRUE.
   *
   * @see SetUseTransactionFlag
   * @see EditingFinished
   * @see GetInEditionTransactionState
   * @par EventProperties
   *   - Name: @c "EditingStarted"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on the returned pointer.
   */
  static CATSYPEvent * EditingStarted();

  /**
   * Returns the @c ValueLiveChanged event.
   * The @c ValueLiveChanged event is emitted (potentially several times per transaction) by the tweaker when 
   * the value is modified during the end user interaction (e.g the drag of a slider or the multipress of a 
   * spinbox in a tweaker of double)
   * This event is emitted only when the UseTransactionFlag property is set to TRUE.
   *
   * @see SetUseTransactionFlag
   * @par EventProperties
   *   - Name: @c "ValueLiveChanged"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on the returned pointer.
   */
  static CATSYPEvent * ValueLiveChanged();

  /**
   * Returns the @c ValueChanged event.
   * The @c ValueChanged event is emitted when the tweaker value is modified.
   * When the tweaker uses an edition transaction, the ValueChanged event is emitted when the transaction is
   * about to finish and when the value has been modified during this transaction.
   * When the tweaker does not use any edition transaction, the ValueChanged event is 
   * emitted whenever the property value is modified.
   *
   * @see SetUseTransactionFlag
   * @see ValueLiveChanged
   * @par EventProperties
   *   - Name: @c "ValueChanged"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on the returned pointer.
   */
  static CATSYPEvent * ValueChanged();

  /**
   * Returns the @c EditingFinished event.
   * The @c EditingFinished event is emitted by the tweaker at the end of the edition transaction 
   * after any value modification.
   * This event is emitted only when the UseTransactionFlag property is set to TRUE.
   *
   * @see SetUseTransactionFlag
   * @see EditingStarted
   * @see GetInEditionTransactionState
   * @par EventProperties
   *   - Name: @c "EditingFinished"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on the returned pointer.
   */
  static CATSYPEvent * EditingFinished();

  /**
  * Returns the @c EditingEscaped event.
  * The @c EditingEscaped event is emitted by the tweaker when escape is pressed during edition.     
  *    
  * @par EventProperties
  *   - Name: @c "EditingEscaped"
  *   - Type of propagation: @c NoPropagation
  *   - Type of argument: @ref CATSYPEventArgs
  * 
  * @return the event instance. @c AddRef has NOT been called on the returned pointer.
  */
  static CATSYPEvent * EditingEscaped();

  /**
   * Resets the tweaker with the initial property value that has been set when the tweaker 
   * has been initialized.
   * @see InternalSetData
   */
  void OnResetCB(CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs);

  /**
   * Handles the EditingStarted event emitted by some tweaker views.
   */
  void OnEditingStarted(CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs);

  /**
   * Handles the EditingFinished event emitted by some tweaker views.
   */
  void OnEditingFinished(CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs);

  /**
  * Handles the OnEditingEscaped event emitted by some tweaker views.
  */
  void OnEditingEscaped(CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs);

  /**
   * Handles the EditingFinished and ReturnPressed events emitted by the tweaker combo box.
   */
  void OnComboEditingFinishedEvent(CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs);

  /**
   * Handles the detailed view visible state changed event.
   */
  void OnDetailedViewVisibleStateChanged(CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs);

  virtual void OnEditorTextEdited(CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs);
  virtual void OnEditorEditingFinished(CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs);

  /**
   * Sets an introspectable object as semantics : each property will be connected to the Tweaker to properties with same name.
   */
  void SetSemantics(const CATBaseUnknown_var& i_spSemantics);
  /**
   * @return the semantics set on the Tweaker.
   */
  const CATBaseUnknown_var& GetSemantics() const { return _spSemantics; }

  void SetStrongFlag(CATBoolean i_strongFlag);
  CATBoolean GetStrongFlag() const { return _strongFlag; }

  virtual void TunnelInformation(const CATVidInformation& i_information) override;

protected:

  virtual ~CATVidCtlTweaker();

  void SetProgrammaticViewFlag(int i_programmaticViewFlag) { _programmaticViewFlag = i_programmaticViewFlag; }

  /**
   * Specifies whether the edited property value has been modified by the end user or not.
   */
  void SetCustomizeFlag(CATBoolean i_customizeFlag);

  /**
   * Initializes the tweaker with the data returned by the GetData method.
   * @see 7
   * @see GetInitFlag
   * @see OnResetCB
   */
  virtual void InternalSetData();

  /**
   * Called when the TweakerData value has changed.
   * This method will dispatch the ValueChanged event.
   * If a tweaker class modifies directly its _tweakerData member, it must call this method.
   * @param i_customizeFlag Specifies whether the edited property value has been modified by the end user or not.
   */
  void OnInternalValueChanged(CATBoolean i_customizeFlag = TRUE);

  /**
   * Called when the TweakerData value has changed.
   * A tweaker can implement this method if it needs to update some internal members value.
   */
  virtual void OnValueChanged();

  /**
   * Returns TRUE if the given proposed value is valid, FALSE otherwise.
   * If the tweaker supports a range and if MinimumTweakerValue and MaximumTweakerValue have 
   * been set, this method return FALSE if the proposed value does not respect the range.
   * @see GetUseRangeState
   */
  virtual CATBoolean IsValueValid(const CATBaseUnknown_var& i_value) const;

  /**
   * Returns the corrected value from the given proposed value.
   * By default, the given value is not returned unmodified.
   * If the tweaker considers the proposed value as invalid (see #IsValueValid) or if it
   * uses a list of possible values and the proposed value does not belong to this list, 
   * this method corrects the proposed value to restore the last valid value.
   * @see GetPossibleValues
   */
  CATBaseUnknown_var GetCorrectedValue(const CATBaseUnknown_var& i_value);

  /**
   * Sets the style sheet name used to generate the CATVidCtlTweaker view.
   */
  void SetStyleSheetName(const CATUnicodeString& i_styleSheetName);

  /**
   * Returns the index of the given value in the list of possible values.
   * This method returns -1 if the value does not belong to this list.
   */
  int _LocateInPossibleValues(const CATBaseUnknown_var& i_value) const;

  /**
   * Creates the tweaker combo box.
   */
  void _CreateCombo();

  /**
   * Updates the selected index of the tweaker combo box according to
   * the current tweaker value.
   */
  void _UpdateComboSelectedIndex();

  /**
   * Updates the tweaker value from the current combo box text.
   */
  void _UpdateValueFromCombo();

  /**
   * Returns the string at the given index of the tweaker combo box.
   * The tweaker uses a combo box when the property is an enum or
   * when a list of possible values has been set for the property.
   * @see CATVidCtlTweakerEnum
   * @see SetPossibleValues
   */
  CATUnicodeString _GetComboString(int i_index) const;

  /**
   * Returns TRUE if the tweaker uses a list of possible values, FALSE otherwise.
   */
  CATBoolean GetUsePossibleValuesState() const;

  CATBaseUnknown_var _spInitialData;

  CATBaseUnknown_var _spEditionStartingData;

  CATBoolean _initFlag;  

private:

  CATVidCtlTweaker (CATVidCtlTweaker &);
  CATVidCtlTweaker& operator=(CATVidCtlTweaker& original);

  void InitAtFirstExpose();
  INLINE CATBoolean GetInitialDataUpdated() { return _initialDataUpdated; }

  CATSYPPropertyDescriptorEx * _pPropertyDescriptorEx;
  CATVidTweakerValidatorAbstract * _pValidator;
  CATUnicodeString _styleSheetName;
  CATBaseUnknown_var _minValue;
  CATBaseUnknown_var _maxValue;
  double _singleStepValue;
  CATListValCATBaseUnknown_var * _pPossibleValues;
  CATVidCtlSimpleCombo * _pCombo;
  int _selectedIndex;
  CATBoolean _useTransactionFlag;  
  CATBoolean _useDetailedViewTransactionFlag;
  CATBoolean _inEditionTransactionState;
  CATBoolean _detailedViewVisibleState;
  CATBoolean _valueModifiedInTransaction;
  CATBoolean _customizeFlag;
  CATBoolean _exhaustiveListFlag;
  CATBoolean _undefinedFlag;
  CATBoolean _initialUndefinedFlag;
  CATBoolean _initialDataUpdated;
  CATBoolean _incorrectInputFlag;
  CATBaseUnknown_var _spSemantics;
  CATBoolean _programmaticViewFlag;
  CATBoolean _strongFlag;

  friend class CATVidCtlTweakerEnum;
};

/**
 * Declares a tweaker class used for editing a boxing value.
 * This macro declares :
 *   * a member called _tweakerData of the given type
 *   * a property called "TweakerData" of the same type as the edited property : this is
 *     the property bound to the edited introspectable property. Setting the property "TweakerData" doest NOT mean
 *     that the end user has explicitely edited the property value.
 *   * a property called "Value" of the same type as the edited property : this is
 *     the property bound in the tweaker template. Setting the property "Value" means
 *     that the end user has explicitely edited the property value (the CustomizeFlag property
 *     of the tweaker must then be set to TRUE).
 *
 * @param TypeName
 * The type of the boxing value (e.g int, CATUnicodeString, ...) .
 * @see CATVidCtlTweaker
 */
#define CATDeclareTweaker(TYPE_NAME)  \
  CATDeclareClass;    \
  private:    \
    TYPE_NAME _tweakerData;  \
  public :    \
    virtual CATUnicodeString GetType() const;    \
    virtual int GetValueTypeFlag() const;    \
    virtual CATBaseUnknown_var GetData() const;    \
    virtual HRESULT SetData(const CATBaseUnknown_var& i_spData);    \
    void SetTweakerData(const TYPE_NAME& i_tweakerData);  \
    const TYPE_NAME& GetTweakerData() const;  \
    void SetValue(const TYPE_NAME& i_value);  \
    const TYPE_NAME& GetValue() const;


/**
 * Implements the mandatory methods for a tweaker class used for editing a boxing value.
 * @param TypeName
 * The type of the boxing value (e.g int, CATUnicodeString, ...) .
 * @see CATVidCtlTweaker
 */
#define CATImplementTweaker(TYPE_NAME)  \
CATImplementClass(CATVidCtlTweaker##TYPE_NAME, Implementation, CATVidCtlTweaker, CATNull);    \
  \
CATUnicodeString CATVidCtlTweaker##TYPE_NAME::GetType() const \
{\
  static CATUnicodeString s_##TYPE_NAME = #TYPE_NAME;\
  return s_##TYPE_NAME;\
}		\
  \
int CATVidCtlTweaker##TYPE_NAME::GetValueTypeFlag() const {return 1;}  \
  \
CATBaseUnknown_var CATVidCtlTweaker##TYPE_NAME::GetData() const \
{  \
  return CATBoxingOf##TYPE_NAME::Box(_tweakerData);  \
}  \
  \
HRESULT CATVidCtlTweaker##TYPE_NAME::SetData(const CATBaseUnknown_var& i_spData)  \
{  \
  TYPE_NAME tweakerData;  \
  HRESULT hr = CATBoxingOf##TYPE_NAME::Unbox(i_spData, tweakerData); \
  if (SUCCEEDED(hr))  \
  {  \
    SetTweakerData(tweakerData);  \
  }  \
  return hr;  \
}  \
void CATVidCtlTweaker##TYPE_NAME::SetTweakerData(const TYPE_NAME& i_tweakerData)  \
{  \
  CATSYPBoxingComparator<TYPE_NAME> comparator;  \
  if (comparator.AreEqual(i_tweakerData, _tweakerData)) return;  \
  _tweakerData = i_tweakerData;  \
  InternalSetData(); \
  if (!GetUndefinedFlag())  \
  {  \
    OnInternalValueChanged(FALSE); \
    CATSYPModifyEditedProperties(); \
  }  \
}  \
  \
const TYPE_NAME& CATVidCtlTweaker##TYPE_NAME::GetTweakerData() const  \
{  \
  return _tweakerData;  \
}  \
void CATVidCtlTweaker##TYPE_NAME::SetValue(const TYPE_NAME& i_value)  \
{  \
  CATSYPBoxingComparator<TYPE_NAME> comparator;  \
  if (comparator.AreEqual(_tweakerData, i_value)) return;  \
  TYPE_NAME correctedValue = i_value;  \
  if (GetUseRangeState() || (GetUsePossibleValuesState() && GetExhaustiveListFlag()))  \
  {  \
    CATBoxingOf##TYPE_NAME::Unbox(GetCorrectedValue(CATBoxingOf##TYPE_NAME::Box(i_value)), correctedValue);  \
  }  \
  _tweakerData = correctedValue;  \
  OnInternalValueChanged(); \
  CATSYPModifyEditedProperties(); \
}  \
  \
const TYPE_NAME& CATVidCtlTweaker##TYPE_NAME::GetValue() const  \
{  \
  return _tweakerData;  \
}

#endif // CATVidCtlTweaker_h
