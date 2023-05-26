//===================================================================
// COPYRIGHT Dassault Systemes 2013 - 2015
//===================================================================
// PLMIExchangeExperienceOption.cpp
// Header definition of class PLMIExchangeExperienceOption
//===================================================================
//
// Usage notes: Define the experience option.
//
//===================================================================
//  2013/07/18 Creation: Code generated by the 3DS wizard
//===================================================================
#ifndef PLMIExchangeExperienceOption_H
#define PLMIExchangeExperienceOption_H

#include "PLMExchangeInterfaces.h"

#include "PLMIExchangeExperienceDesignInfo.h"
#include "PLMExchangeExperienceDictionary.h"
#include "CATListOfCATUnicodeString.h"
#include "CATListOfCATString.h"
#include "CATBaseUnknown.h"

class CATTime;
extern ExportedByPLMExchangeInterfaces  IID IID_PLMIExchangeExperienceOption ;

class ExportedByPLMExchangeInterfaces PLMIExchangeExperienceOption: public CATBaseUnknown
{
CATDeclareInterface;

public:     

   /**
   * <b> SetValueType :</b> The type of the value for the current option (By Default it's set to String).   
   *
   * @param iValueType (in)
   * input PLMExchangeExperienceValueType corresponding to the type of value.
   * <u>ValueType_Boolean</u> : CATBoolean. It can be multi valued.
   * <u>ValueType_Integer</u> : int. It can be multi valued.
   * <u>ValueType_Float</u> : double. It can be multi valued.
   * <u>ValueType_String</u> : CATUnicodeString. It can be multi valued.
   * <u>ValueType_NLSKey</u> : NLS Key. The value to display will be computed from the NLSKey. It can be multi valued.
   * <u>ValueType_Date</u> : CATTime. It can be multi valued.
   * <u>ValueType_FileName</u> : CATUnicodeString. It can be multi valued.
   * <u>ValueType_FolderPath</u> : CATUnicodeString.  It can be multi valued.
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL .
   */ 
   virtual HRESULT SetValueType(PLMExchangeExperienceValueType iValueType) = 0; 

   /**
   * <b> GetValueType :</b> Get the type of the value for the current option.   
   *
   * @param iValueType (in)
   * input PLMExchangeExperienceValueType corresponding to the type of value.
   * <u>ValueType_Boolean</u> : CATBoolean.  
   * <u>ValueType_Integer</u> : int.
   * <u>ValueType_Float</u> : double. 
   * <u>ValueType_String</u> : CATUnicodeString.
   * <u>ValueType_NLSKey</u> : CATString.
   * <u>ValueType_Date</u> : CATTime.
   * <u>ValueType_FileName</u> : CATUnicodeString.
   * <u>ValueType_FolderPath</u> : CATUnicodeString.   
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL .
   */ 
   virtual HRESULT GetValueType(int & oValueType) = 0; 

   /**
   * <b> SetMultipleChoice :</b> Set the multiple choice for the option. 
   * If multiple choice is used, then the option value(s) could only be choosen among these choices.
   * The given pointer must be cast from the correct type (as specified with SetValueType) .
   * It must NOT be NULL and must point a valid object.
   *
   * @param ipChoiceValue (out)
   * input pointer on option value. 
   * <u>ValueType_Boolean</u> : CATBoolean.
   * <u>ValueType_Integer</u> : int. 
   * <u>ValueType_Float</u> : double. 
   * <u>ValueType_String</u> : CATUnicodeString. 
   * <u>ValueType_NLSKey</u> : NLS Key. The value to display will be computed from the NLSKey.
   * <u>ValueType_Date</u> : CATTime. 
   *
   * @param iPos (in)
   * input position of the choice value to set (in case of a multi-choice option).
   * Value set on new position will automatically be added.
   *   - Between 1 and NbOfMultipleChoice -> Value is replaced
   *   - Is > to NbOfMultipleChoice -> Value is appended.
   *   - Equal to 0 -> Existing values are removed, and given value is appended (position = 1).
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL 
   */ 
   virtual HRESULT SetMultipleChoice(void * & ipChoiceValue , int iPos = 1) = 0;

   /**
   * <b> GetSelectedMultipleChoiceIndex :</b> Get selected multiple choice index for a given value position. 
   * i.e An option can have 2 values selected out of 3 choices A, B ,C. 
   *  1st value is B, 2nd value is C.
   *  GetSelectedMultipleChoiceIndex on value iPos = 1 will return 2 (index of B) while  iPos = 2 will return 3 (index of C).
   *
   * @param oSelectedIndex (out)
   * output integer corresponding to the selected multiple choice for the given value position.
   *
   * @param iPos (in)
   * input position of the value to consider (in case of a multi-valued option).   
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL .
   */ 
   virtual HRESULT GetSelectedMultipleChoiceIndex(int & oSelectedIndex, int iPos = 1) = 0;

   /**
   * <b> GetNbOfChoices :</b> Get the number of choices set for the option .   
   *
   * @return
   *    Legal values:  0  : No value as being set.
   *                   1  : 1 value has been set.
   *                x > 1 : x value has been set .
   */ 
   virtual int GetNbOfChoices() = 0;

   /**
   * <b> SetValue :</b> Set the value of the option. 
   * If multiple choice is used, then the option value(s) could only be choosen among these choices.
   * The given pointer must be cast from the correct type (as specified with SetValueType) .   
   * It must NOT be NULL and must point a valid object.
   *
   * @param ipOptionValue (in)
   * input pointer on option value. 
   * <u>ValueType_Boolean</u> : CATBoolean. It can be multi valued.
   * <u>ValueType_Integer</u> : int. It can be multi valued.
   * <u>ValueType_Float</u> : double. It can be multi valued.
   * <u>ValueType_String</u> : CATUnicodeString. It can be multi valued.
   * <u>ValueType_NLSKey</u> : CATString. It can be multi valued.
   * <u>ValueType_Date</u> : CATTime. It can be multi valued.
   * <u>ValueType_FileName</u> : CATUnicodeString. It can be multi valued.
   * <u>ValueType_FolderPath</u> : CATUnicodeString.  It can be multi valued.
   *
   * @param iPos (in)
   * input position of the value to set (in case of a multi-valued option).
   * Value set on new position will automatically be added.
   *   - Between 1 and NbOfValue -> Value is replaced
   *   - Is > to NbOfValue -> Value is appended.
   *   - Equal to 0 -> Existing values are removed, and given value is appended (position = 1).
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL 
   */ 
   virtual HRESULT SetValue(void * & ipOptionValue , int iPos = 1) = 0;

   /**
   * <b> SetValue :</b> Set the value and the type of the option. 
   * If multiple choice is used, then the option value(s) could only be choosen among these choices.
   * The given pointer must be cast from the correct type (as specified with iValueType) .   
   * It must NOT be NULL and must point a valid object.
   * In case of multiple value option, the given value type must stay the same for all the added values.
   *
   * @param iValueType (in)
   * input PLMExchangeExperienceValueType corresponding to the type of value.
   * <u>ValueType_Boolean</u> : CATBoolean. It can be multi valued.
   * <u>ValueType_Integer</u> : int. It can be multi valued.
   * <u>ValueType_Float</u> : double. It can be multi valued.
   * <u>ValueType_String</u> : CATUnicodeString. It can be multi valued.
   * <u>ValueType_NLSKey</u> : NLS Key. The value to display will be computed from the NLSKey. It can be multi valued.
   * <u>ValueType_Date</u> : CATTime. It can be multi valued.
   * <u>ValueType_FileName</u> : CATUnicodeString. It can be multi valued.
   * <u>ValueType_FolderPath</u> : CATUnicodeString.  It can be multi valued. 
   *
   * @param ipOptionValue (in)
   * input pointer on option value. 
   *
   * @param iPos (in)
   * input position of the value to set (in case of a multi-valued option).
   * Value set on new position will automatically be added.
   *   - Between 1 and NbOfValue -> Value is replaced
   *   - Is > to NbOfValue -> Value is appended.
   *   - Equal to 0 -> Existing values are removed, and given value is appended (position = 1).
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL 
   */ 
   virtual HRESULT SetValue(PLMExchangeExperienceValueType iValueType, void * & ipOptionValue , int iPos = 1) = 0;

   /**
   * <b> SetValueWithMultiChoice :</b> Set the value of the option to a set multiple choice value.      
   *
   * @param iMultiChoicePos [in] 
   * input integer corresponding to the position of the multiple choice to set as the option value.
   *
   * @param iValuePos (in)
   * input position of the option value to Set (in case of a multi-value option).
   * Value set on new position will automatically be added.
   *
   * @return
   *    Legal values:  S_OK if the method succeeds        
   *                   E_FAIL .                
   */ 
   virtual HRESULT SetValueWithMultiChoice(int & iMultiChoicePos, int iValuePos = 1) = 0;

   /**
   * <b> GetValue :</b> Get the value of the option. 
   * Please cast the pointer depending on the set value type.
   *
   * @param iopOptionValue (out)
   * output pointer on option value. The given pointer must be cast from the correct type (as specified with SetValueType).
   * It must NOT be NULL and must point a valid object.
   * <u>ValueType_Boolean</u> : CATBoolean. It can be multi valued.
   * <u>ValueType_Integer</u> : int. It can be multi valued.
   * <u>ValueType_Float</u> : double. It can be multi valued.
   * <u>ValueType_String</u> : CATUnicodeString. It can be multi valued.
   * <u>ValueType_NLSKey</u> : CATString. It can be multi valued.
   * <u>ValueType_Date</u> : CATTime. It can be multi valued.
   * <u>ValueType_FileName</u> : CATUnicodeString. It can be multi valued.
   * <u>ValueType_FolderPath</u> : CATUnicodeString.  It can be multi valued.
   *
   * @param iPos (in)
   * input position of the value to get (in case of a multi-valued option).
   * Value set on new position will automatically be added.
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL .
   */ 
   virtual HRESULT GetValue(void * & iopOptionValue, int iPos = 1) = 0;

   /**
   * <b> GetNbOfValues :</b> Get the number of value set for the option .   
   *
   * @return
   *    Legal values:  0  : No value as being set.
   *                   1  : 1 value has been set.
   *                x > 1 : x value has been set .
   */ 
   virtual int GetNbOfValues() = 0;

   /******************************************************************************************
   *                   Set/Get Options properties by its type.                               *
   ******************************************************************************************/
   /** 
   * <b>PLMIExchangeExperienceOptionProperty:</b> Define the different properties of an option.
   * <u>OptionProperty_IsSensitive (boolean) </u> : The option is sensitive therefore any interaction on it will result in a callback call. (only unlocked for option definition)  
   * <u>OptionProperty_IsActivated (boolean) </u> : The option is desactived (greyed out) and no interaction is possible.   
   * <u>OptionProperty_IsHidden (boolean) </u> : The option is hidden and will not be displayed. 
   * <u>OptionProperty_IsLocked (boolean) </u> : The option is locked therefore it cannot be modified.
   * <u>OptionProperty_MaxValueAllowed (integer)(date) </u> : The maximum value allowed if the option is of numerical/date type.
   * <u>OptionProperty_MinValueAllowed (integer)(date) </u> : The minimum value allowed if the option is of numerical/date type.
   * <u>OptionProperty_IsOnServer (boolean) </u> : [for type : FileName and FolderPath] Whether or not the access is done on a server or on the local disk , Default value is False.
   * <u>OptionProperty_SupportedExtension (List of String) </u> : [for type : FileName and FolderPath] The list of file extension to consider. It must follow the following naming rule : "extension".
   * <u>OptionProperty_SupportedScope (List of String) </u> : [for type : FolderPath] Set the scope of Data to look for (immersive PLM Chooser). 
   * <u>OptionProperty_Path (String) </u> : [for type : FileName and FolderPath] Set the path of for the file/folder chooser (immersive PLM Chooser).
   * <u>OptionProperty_IsSupportedScope (boolean) </u> : [for type : FolderPath] Tell if the scope of Data to look for is set or not (immersive PLM Chooser). 
   * <u>OptionProperty_IsDLName (boolean) </u> : [for type : FolderPath] Tell if the selected path is of DLName type or actual physical path). 
   */
   enum PLMExchangeExperienceOptionProperty
   {
      OptionProperty_IsSensitive = 0x00000001,
      OptionProperty_IsActivated = 0x00000002,
      OptionProperty_IsHidden = 0x00000004,
      OptionProperty_IsLocked = 0x00000008,
      OptionProperty_MaxValueAllowed = 0x00000010,
      OptionProperty_MinValueAllowed = 0x00000020,
      OptionProperty_IsOnServer = 0x00000040,
      OptionProperty_SupportedExtension = 0x00000080,
      OptionProperty_SupportedScope = 0x00000100,
      OptionProperty_Path = 0x00000200,
      OptionProperty_IsSupportedScope = 0x00000400,
      OptionProperty_IsDLName = 0x00000800,
      OptionProperty_IsOnDrive = 0x00001000,
   };

   /**
   * <b> SetProperty (boolean) :</b> Set the property value of the option.
   * Depending on the context, some property might be locked therefore it won't be possible to change it.
   *
   * @param iOptionProperty (in)
   * input PLMExchangeExperienceOptionProperty corresponding to the property to set.
   *
   * @param iHasProperty (in)
   * input CATBoolean corresponding to whether or not the option has the property.
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL.
   */ 
   virtual HRESULT SetProperty(PLMExchangeExperienceOptionProperty iOptionProperty, CATBoolean & iHasProperty) = 0;

   /**
   * <b> GetProperty (boolean) :</b> Get the value of a property for an option.   
   *
   * @param iOptionProperty (in)
   * input PLMExchangeExperienceOptionProperty corresponding to the property.
   *
   * @param oHasProperty (in)
   * output CATBoolean corresponding to whether or not the option has the property.
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL .
   */ 
   virtual HRESULT GetProperty(PLMExchangeExperienceOptionProperty iOptionProperty, CATBoolean & oHasProperty) = 0;

   /**
   * <b> SetProperty (integer) :</b> Set the property value of the option.
   * Depending on the context, some property might be locked therefore it won't be possible to change it.
   *
   * @param iOptionProperty (in)
   * input PLMExchangeExperienceOptionProperty corresponding to the property to set.
   *
   * @param iPropertyValue (in)
   * input integer corresponding to the property value.
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL .
   */ 
   virtual HRESULT SetProperty(PLMExchangeExperienceOptionProperty iOptionProperty, int & iPropertyValue) = 0;

   /**
   * <b> GetProperty (integer) :</b> Get the value of a property for an option.   
   *
   * @param iOptionProperty (in)
   * input PLMExchangeExperienceOptionProperty corresponding to the property.
   *
   * @param oPropertyValue (in)
   * output integer corresponding to the property value.
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL if the property is locked for modification.
   */ 
   virtual HRESULT GetProperty(PLMExchangeExperienceOptionProperty iOptionProperty, int & oPropertyValue) = 0;

  /**
   * <b> SetProperty (date) :</b> Set the property value of the option.
   * Depending on the context, some property might be locked therefore it won't be possible to change it.
   *
   * @param iOptionProperty (in)
   * input PLMExchangeExperienceOptionProperty corresponding to the property to set.
   *
   * @param iPropertyValue (in)
   * input CATTime corresponding to the property value.
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL .
   */ 
   virtual HRESULT SetProperty(PLMExchangeExperienceOptionProperty iOptionProperty, CATTime & iPropertyValue) = 0;

   /**
   * <b> GetProperty (date) :</b> Get the value of a property for an option.   
   *
   * @param iOptionProperty (in)
   * input PLMExchangeExperienceOptionProperty corresponding to the property.
   *
   * @param oPropertyValue (in)
   * output CATTime corresponding to the property value.
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL if the property is locked for modification.
   */ 
   virtual HRESULT GetProperty(PLMExchangeExperienceOptionProperty iOptionProperty, CATTime & oPropertyValue) = 0;

   /**
   * <b> LinkWithSysRepository :</b> Link the current option to a system repository (preference or setting).   
   * Does not work with option of type : ValueType_Date (for both preference and setting).
   * Does not work with option of type : ValueType_PtrCATBaseUnknown (for setting).
   * When linked, the option's value(s) will be loaded from or saved to the specified repository.
   * To specify when the option's value(s) is/are saved in the repository, please refer to the method SetSysRepositorySaveEvents(..).
   * In the repository, the option's values could be saved as multiple entries (differenciated by the option's properties).
   * For more information, please refer to the method LinkValueToProperty(...).
   *
   * @param iSysRepositoryType (in)
   * input corresponding to the type of the system repository to link the option with.
   * Type PLMExchangeExperienceSysRepositoryType is defined in the header : PLMExchangeExperienceDictionary.h.
   * Example of possible values : SysRepositoryType_Preference, SysRepositoryType_Setting.
   *
   * @param iStrSysRepoName (in)
   * input string corresponding to the repository name to link the option with.
   *
   * @param iStrSysRepoAttrName (in)
   * input string corresponding to the attribute name under which option's values will be saved under (in the specified repository).
   *
   * @param ibSetValue (in)
   * input boolean on whether or not to initialize the current option's value with on in the given repository (if applicable).
   * The information which will be retrieved from the given repository to initialize the option, depends on the option's set property links. (LinkValueToProperty).
   * For the option is to be correctly initialized from the given repository, the following conditions have to be met : 
   *  - The option type must have been set.   
   * By default, value is set to TRUE.
   * In that case, if no value could be loaded and initialized to the current option, then S_FALSE is returned.
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *                   S_FALSE, if ibSetValue == TRUE, and the option's value has not been initialized (because no value was found for the given repository information).
   *    Other,         E_FAIL .
   */ 
   virtual HRESULT LinkWithSysRepository(PLMExchangeExperienceSysRepositoryType iSysRepositoryType, const CATUnicodeString & iStrSysRepoName, const CATUnicodeString & iStrSysRepoAttrName, CATBoolean ibSetValue = TRUE) = 0;
     
  /**
   * <b> SetSysRepositorySaveEvents :</b> Set which events will trigger the save of the option current values in the linked system repository.
   * If no system repository has been linked to the current option, then this method does nothing. Please refer to method LinkWithSysRepository(..), for more information.
   * Multiple events can be set and some of them might requires arguments.
   * To register to multiple events, simply recall this method with the different desired event type values.
   *
   * @param iExchangeExperienceEvents (in)
   * input corresponding to the type of the event to register.
   * The events are defined in the header : PLMExchangeExperienceDictionary.h.
   * Possible values : 
   * PLMExchangeExperienceEvent::OnOptionInteraction() : Does not require any argument.
   * PLMExchangeExperienceEvent::OnExecute() : Requires argument corresponding triggering execution id.
   * PLMExchangeExperienceEvent::OnEndOfCommand()  : Does not require any argument.
   *
   * @param ipEventArg (in)
   * input pointer on a list of CATUnicodeString. To set depending on the registered events.
   * If no argument is required for given event, then set ipEventArg to NULL.
   * By default value is equal to NULL.
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL .
   */ 
   virtual HRESULT RegisterSysRepositorySaveEvent(CATCallbackEvent  iExchangeExperienceEvent, CATListOfCATUnicodeString * ipEventArg = NULL) = 0 ;

  /**
   * <b> LinkValueToProperty :</b> Set a link on the option value to an option PLMExchangeExperienceOptionProperty. Only works for Boolean type of property.
   * This method is only relevant if a system repository has been linked to the current option. (through LinkWithSysRepository).
   * By calling the multiple time, the option's value(s) will linked to more than 1 option properties.
   * Linking the option's value(s) to a property value, means that the option will consider two "set of value(s)" when interacting (save or load value) with the system repository:
   *  - a value for when the property is set (equal to true). 
   *  - another when the property is not set (equal to false).
   * i.e. : 
   *  - Option1 is linked to a system repository. 
   *  - Option1 has its values linked to the property OptionProperty_IsOnServer.
   *  - Option1 has its values linked to the property OptionProperty_IsActivated.
   *  - When the option is saved in or loaded from the specified system repository :
   *     - If OptionProperty_IsOnServer is TRUE and OptionProperty_IsActivated is TRUE, then the option's values will be saved to or loaded from an entry A.
   *     - If OptionProperty_IsOnServer is TRUE and OptionProperty_IsActivated is FALSE, then the option's values will be saved to or loaded from an entry B.
   *     - If OptionProperty_IsOnServer is FALSE and OptionProperty_IsActivated is TRUE, then the option's values will be saved to or loaded from an entry C.
   *     - If OptionProperty_IsOnServer is FALSE and OptionProperty_IsActivated is FALSE, then the option's values will be saved to or loaded from an entry D.
   *
   * By default, the option's value(s) is/are not linked to any property.
   *
   * @param iOptionPropertyId (in)
   * input property to link the option's value with.
   */ 
   virtual void LinkValueToProperty(PLMExchangeExperienceOptionProperty iOptionPropertyId) = 0;

   /**
   * <b> SetProperty (list of CATUnicodeString) :</b> Set the property value of the option.
   * Depending on the context, some property might be locked therefore it won't be possible to change it.
   *
   * @param iOptionProperty (in)
   * input PLMExchangeExperienceOptionProperty corresponding to the property to set.
   *
   * @param iPropertyValues (in)
   * input list of CATUnicodeString corresponding to the property values.
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL .
   */ 
   virtual HRESULT SetProperty(PLMExchangeExperienceOptionProperty iOptionProperty, CATListOfCATUnicodeString & iPropertyValues) = 0;

   /**
   * <b> GetProperty (list of CATUnicodeString) :</b> Get the value of a property for an option.   
   *
   * @param iOptionProperty (in)
   * input PLMExchangeExperienceOptionProperty corresponding to the property.
   *
   * @param oPropertyValues (in)
   * output list of CATUnicodeString corresponding to the property value.
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL if the property is locked for modification.
   */ 
   virtual HRESULT GetProperty(PLMExchangeExperienceOptionProperty iOptionProperty, CATListOfCATUnicodeString & oPropertyValues) = 0;

   /**
   * <b> SetProperty (list of CATListOfCATString) :</b> Set the property value of the option.
   * Depending on the context, some property might be locked therefore it won't be possible to change it.
   *
   * @param iOptionProperty (in)
   * input PLMExchangeExperienceOptionProperty corresponding to the property to set.
   *
   * @param iPropertyValues (in)
   * input list of CATUnicodeString corresponding to the property values.
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL .
   */ 
   virtual HRESULT SetProperty(PLMExchangeExperienceOptionProperty iOptionProperty, CATListOfCATString & iPropertyValues) = 0;

   /**
   * <b> GetProperty (list of CATListOfCATString) :</b> Get the value of a property for an option.   
   *
   * @param iOptionProperty (in)
   * input PLMExchangeExperienceOptionProperty corresponding to the property.
   *
   * @param oPropertyValues (in)
   * output list of CATUnicodeString corresponding to the property value.
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL if the property is locked for modification.
   */ 
   virtual HRESULT GetProperty(PLMExchangeExperienceOptionProperty iOptionProperty, CATListOfCATString & oPropertyValues) = 0;
   
   /**
   * <b> SetProperty (CATUnicodeString) :</b> Set the property value of the option.
   * Depending on the context, some property might be locked therefore it won't be possible to change it.
   *
   * @param iOptionProperty (in)
   * input PLMExchangeExperienceOptionProperty corresponding to the property to set.
   *
   * @param iPropertyValues (in)
   * input CATUnicodeString corresponding to the property values.
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL .
   */ 
   virtual HRESULT SetProperty(PLMExchangeExperienceOptionProperty iOptionProperty, CATUnicodeString & iPropertyValue) = 0;
   
   /**
   * <b> GetProperty (CATUnicodeString) :</b> Get the value of a property for an option.   
   *
   * @param iOptionProperty (in)
   * input PLMExchangeExperienceOptionProperty corresponding to the property.
   *
   * @param oPropertyValues (in)
   * output CATUnicodeString corresponding to the property value.
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL if the property is locked for modification.
   */ 
   virtual HRESULT GetProperty(PLMExchangeExperienceOptionProperty iOptionProperty, CATUnicodeString & oPropertyValue) = 0;

   /**
   * <b> GetDesignInfo :</b> Get the associate design info (which hold all the information to be displayed).      
   * Please release pointer after use.
   *
   * @param opDesignInfo  [out, PLMExchangeExperienceDesignInfo#Release]  
   * output PLMExchangeExperienceDesignInfo.
   *
   * @return
   *    Legal values:  S_OK if the method succeeds        
   *                   E_FAIL .                
   */    
   virtual HRESULT GetDesignInfo(PLMIExchangeExperienceDesignInfo * & opDesignInfo) = 0;
   
   /**
   * <b> EnableDisableWidget :</b> Helps in enabling/disabling the particular widget of an option
   * for now this API is implemented only for CATVidLineEditor, it does not support other widget for now.
   *
   * @param iWidgetValueNumber
   * Widget number that needs to be disabled.
   *
   *@param ibProperty
   * Property/value to set.
   *
   * @return
   *    Legal values:  S_OK if the method succeeds
   *                   E_FAIL .
   */
   virtual HRESULT EnableDisableWidget(int iWidgetValueNumber, CATBoolean ibProperty) = 0;
};

//-----------------------------------------------------------------------

#endif