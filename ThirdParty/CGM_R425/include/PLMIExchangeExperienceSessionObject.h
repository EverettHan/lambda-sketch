//===================================================================
// COPYRIGHT Dassault Systemes 2013/03/19
//===================================================================
// PLMIExchangeExperienceSessionObject.cpp
// Header definition of class PLMIExchangeExperienceSessionObject
//===================================================================
//
// Usage notes: Object used to interact with the object in session.
//
//===================================================================
//  2013/03/19 Creation: Code generated by the 3DS wizard
//===================================================================
#ifndef PLMIExchangeExperienceSessionObject_H
#define PLMIExchangeExperienceSessionObject_H

#include "PLMExchangeInterfaces.h"
#include "PLMExchangeExperienceDictionary.h"
#include "PLMIExchangeExperienceOperation.h"
#include "CATBaseUnknown.h"

class CATUnicodeString;
class CATPLMID;
class CATListPtrPLMIExchangeExperienceSessionObject;
class PLMIExchangeExperienceSessionObject;
class PLMIExchangeExperienceDesignInfo;
class PLMIExchangeExperienceObjSearchCriterion;
class CATIPLMComponent;

extern ExportedByPLMExchangeInterfaces  IID IID_PLMIExchangeExperienceSessionObject ;

class ExportedByPLMExchangeInterfaces PLMIExchangeExperienceSessionObject: public CATBaseUnknown
{
   CATDeclareInterface;

public:

   /**
   * <b> GetPLMID :</b> Get the associated plmid. 
   *
   * @param oPLMId (out)
   * output PLMID corresponding to session object.   
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL if there's an issue with the retrieval of the plmid .
   */ 
   virtual HRESULT GetPLMID(CATPLMID & oPLMId) = 0;

   /**
   * <b> GetPLMComponent :</b> Get a pointer on the associated CATIPLMComponent. 
   * Please release the pointer after use.
   *
   * @param opComp [out, CATBaseUnknown#Release]
   * output pointer on the associated CATIPLMComponent.
   *
   * @return
   *    Legal values:  S_OK if the method succeeds 
   *                   S_FALSE if there's no associated plm component. opComp will then be equal to NULL.
   *    Other,         E_FAIL if there's an issue with the retrieval of the plm component.
   */ 
   virtual HRESULT GetPLMComponent(CATIPLMComponent * & opComp) = 0 ;

   /**
   * <b> GetAlias :</b> Get the string corresponding to the object's alias.   
   *
   * @param oStrAlias (out)
   * output string.
   *
   * @return
   *    Legal values:  S_OK if the method succeeds                               
   *    Other,         E_FAIL 
   */ 
   virtual HRESULT GetAlias(CATUnicodeString & oStrAlias)=0;

   /**
   * <b> GetIcons :</b> Get the object associated icons.    
   *
   * @param oListStrIcons (out)
   * output string the icon name.   
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL .
   */ 
   virtual HRESULT GetIcons(CATListOfCATUnicodeString & oListStrIcons) = 0 ;

   /**
   * <b> GetStatus :</b> Get the string key of the session object's current status.   
   *
   * @param oStrStatusKey (out)
   * output string corresponding to the status string key.
   *
   * @return
   *    Legal values:  S_OK if the method succeeds                               
   *    Other,         E_FAIL if no status was set for this session object.
   */ 
   virtual HRESULT GetStatus(CATUnicodeString &  oStrStatusKey) = 0;

   /**
   * <b> GetStatusNlsValue :</b> Get the string value corresponding to the set status key on the current session object.   
   *
   * @param oStrStatusValue (out)
   * output string corresponding to the nls value of current object's status string key.
   *
   * @return
   *    Legal values:  S_OK if the method succeeds                               
   *    Other,         E_FAIL.
   */ 
   virtual HRESULT GetStatusNlsValue(CATUnicodeString &  oStrStatusValue) = 0;

   /**
   * <b> SetPLMComponent :</b> Set the CATIPLMComponent associated with the current session object.
   * An add ref will be done on the given CATIPLMComponent.
   *
   * @param ipComp [in]
   * input pointer on the CATIPLMComponent to set on the current session object
   *
   * @return
   *    Legal values:  S_OK if the method succeeds    
   *    Other,         E_FAIL.
   */ 
   virtual HRESULT SetPLMComponent(CATIPLMComponent * & ipComp) = 0;

   /**
   * <b>SetStatus  :</b> Initialize the object with the given status key.   
   * Also return the updated list of available operation.
   * If the operation was there before the status changed, then it will keep its state.
   * If not, then the new added operation will have the "enabled" state.
   * ie : 
   *   - Object has status StA and 2 operations, Op0 (Enabled) Op1 (forbidden).
   *   - Object change its status to StB and the operations available are now Op1 (forbidden) and Op2 (Enabled).
   *
   * @param iStrStatusKey (in)
   * input string corresponding to the status string key.
   *
   * @param oListOfOperationId (out)
   * output pointer on a list of operation Id available on this sesssion object, for the new status.
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL .
   */ 
   virtual HRESULT SetStatus(const CATUnicodeString &  iStrStatusKey, CATListOfCATUnicodeString * oListOfOperationId = NULL) = 0;

   /**
   * <b>SetOperationState  :</b> Set the operation state for the given operation id.
   * It is used to disable, enable or forbid an operation.
   *
   * @param iStrOperationKey (in)
   * input string corresponding to the operation string key.
   *
   * @param iOperationState (in)
   * input operation state as defined by the enum PLMIExchangeExperienceOperation::OperationState; 
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL .
   */ 
   virtual HRESULT SetOperationState(const CATUnicodeString &  iStrOperationKey, PLMIExchangeExperienceOperation::OperationState iOperationState) = 0;

   /**
   * <b>AddObjectProperty  :</b> Add an object property as defined by the enum PLMExchangeObjectProperty in the file PLMExchangeBaseObject.h.
   * The input value could be an aggregation of multiple value. ie : PLMExchangeObjectProperty_BySelection | PLMExchangeObjectProperty_WithDelegation .
   * This method does not replace the existing object properties with the given properties mask, but it add them to it. 
   *
   * @param iObjectProperty (in)
   * input mask of PLMExchangeObjectProperty to add to the object.
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL .
   */    
   virtual HRESULT AddObjectProperty(int iObjectProperty) = 0;

   /**
   * <b>GetOperationState  :</b> Get the operation state for the given operation id.   
   *
   * @param iStrOperationKey (in)
   * input string corresponding to the operation string key.
   *
   * @param oOperationState (in)
   * output operation state as defined by the enum PLMIExchangeExperienceOperation::OperationState; 
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL .
   */ 
   virtual HRESULT GetOperationState(CATUnicodeString &  iStrOperationKey, int & oOperationState) = 0;

   /**
   * <b>GetOperationIds  :</b> Get the list of available operation for this session object.
   * This list of operation is deduced from the session object type and status.
   *
   * @param oListOfOperationId (out)
   * output list of operation Id available on this sesssion object.
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL .
   */ 
   virtual HRESULT GetOperationIds( CATListOfCATUnicodeString & oListOfOperationId) = 0;

   /**
   * <b> GetChildren :</b> Get the first level children of the current session object if no search criterion are set.
   * Otherwise, the returned children depend on the given criterion.
   * If an object meet any of the defined criteria, then it's added to the output list. 
   * PLMIExchangeExperienceObjSearchCriterion can be created with the object PLMIExchangeExperienceCustoServices (accessible through PLMIExchangeExperienceCustomization).
   *
   * @param oListObjectChild (out)
   * output list of PLMIExchangeExperienceSessionObject. 
   * Please release the object within the list after use.
   *
   * @param ipSearchCriterion (in)
   * input pointer on PLMIExchangeExperienceObjSearchCriterion. The criteria will define the type and level to search for.
   * Refer to PLMIExchangeExperienceObjSearchCriterion.h for addionnal informations.
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Legal values:  S_FALSE if there is no children .
   *    Other,         E_FAIL if there's an issue with the retrieval of the children .
   */ 
   virtual HRESULT GetChildren(CATListPtrPLMIExchangeExperienceSessionObject & oListObjectChild , PLMIExchangeExperienceObjSearchCriterion * ipSearchCriterion = NULL) = 0;
 
   /**
   * <b> IsPointedBy :</b> Get the first level object pointing the current session object, if no search criterion are set.
   * Otherwise, the returned list depend on the given criterion.
   * If an object meet any of the defined criteria, then it's added to the output list. 
   * PLMIExchangeExperienceObjSearchCriterion can be created with the object PLMIExchangeExperienceCustoServices (accessible through PLMIExchangeExperienceCustomization).
   *
   * @param oListPointingObj (out)
   * output list of PLMIExchangeExperienceSessionObject. 
   * Please release the object within the list after use.
   *
   * @param ipSearchCriterion (in)
   * input pointer on PLMIExchangeExperienceObjSearchCriterion. The criteria will define the type and level to search for.
   * Refer to PLMIExchangeExperienceObjSearchCriterion.h for addionnal informations.
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Legal values:  S_FALSE if there is no pointing object.
   *    Other,         E_FAIL if there's an issue with the retrieval of the pointing object .
   */ 
   virtual HRESULT IsPointedBy(CATListPtrPLMIExchangeExperienceSessionObject  & oListPointingObj, PLMIExchangeExperienceObjSearchCriterion * ipSearchCriterion = NULL) = 0 ;


   /**
   * <b> GetType :</b> Get the PLM core type of the session object. 
   *
   * @param oSessionObjectType (out)
   * output pointer on PLMExchangeExperienceObjectType corresponding to the type of the object. (Defined in PLMExchangeExperienceDictionary.h) 
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL .
   */ 
   virtual HRESULT GetType(PLMExchangeExperienceObjectType * oSessionObjectType) = 0 ;

   /**
   * <b> ListAttributes :</b> Get the list of available attributes for the current session object.
   *
   * @param oListOfAttrName (in)
   * output list of CATUnicodeString containing the attribute name.   
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL .
   */ 
   virtual HRESULT ListAttributes(CATListOfCATUnicodeString & oListOfAttrName) = 0;

   /**
   * <b> SetAttribute :</b> Add or set an attribute value. 
   * The given ipAttrValue pointer must be cast from the correct type (as specified by iAttrValueType).
   * It must NOT be NULL and must point a valid object.
   *
   * @param iStrAttrName (in)
   * input string corresponding to the attribute name to add/set.
   *
   * @param iAttrValueType (in)
   * input attribut value type. 
   * <u>ValueType_Boolean</u> : CATBoolean.  
   * <u>ValueType_Integer</u> : int.
   * <u>ValueType_Float</u> : double. 
   * <u>ValueType_String</u> : CATUnicodeString.
   * <u>ValueType_Date</u> : CATTime.
   * <u>ValueType_FileName</u> : CATUnicodeString.
   * <u>ValueType_FolderPath</u> : CATUnicodeString.   
   *
   * @param ipAttrValue (in)
   * input pointer on an attribut value. The given pointer must be cast from the correct type.
   * It must NOT be NULL and must point a valid object.
   *
   * @param iPos (in)
   * input position of the choice value to set (in case of a multi-value attribute).
   * Value set on new position will automatically be added.
   *   - Between 1 and NbOfValue -> Value is replaced
   *   - Is > to NbOfValue -> Value is appended.   
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL .
   */ 
   virtual HRESULT SetAttribute(const CATUnicodeString & iStrAttrName, PLMExchangeExperienceValueType iAttrValueType, void  *  & ipAttrValue, int iPos = 1  ) = 0 ;

   /**
   * <b> GetAttributeNbOfValues :</b> Get the number of value set for the given attribute .   
   *
   * @param iStrAttrName (in)
   * input string corresponding to the attribute name to get nb of value.
   *
   * @return
   *    Legal values:  0  : No value as being set.
   *                   1  : 1 value has been set.
   *                x > 1 : x value has been set .
   */ 
   virtual int GetAttributeNbOfValues(const CATUnicodeString & iStrAttrName)= 0 ;

   /**
   * <b> GetAttribute :</b> Get the value for the given attribute name.
   * Please cast the pointer depending on the set value type.
   *
   * @param iStrAttrName (in)
   * input string corresponding to the attribute name.
   *
   * @param opAttrValue (out)
   * output pointer on an attribut value. The given pointer must be cast from the correct type (as specified when the attribute was added).
   * It must NOT be NULL and must point a valid object.
   * <u>ValueType_Boolean</u> : CATBoolean.  
   * <u>ValueType_Integer</u> : int.
   * <u>ValueType_Float</u> : double. 
   * <u>ValueType_String</u> : CATUnicodeString.
   * <u>ValueType_Date</u> : CATTime.
   * <u>ValueType_FileName</u> : CATUnicodeString.
   * <u>ValueType_FolderPath</u> : CATUnicodeString.   
   *
   * @param iPos (in)
   * input position of the choice value to get (in case of a multi-value attribute).
   * Value must be between 1 and NbOfValue
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL .
   */ 
   virtual HRESULT GetAttribute(const CATUnicodeString & iStrAttrName, void * &  opAttrValue, int iPos = 1 ) = 0;

   /**
   * <b> GetDesignInfo</b> : Get the design info related to the session object.
   * This is where you will define the description and other displayed information regarding the session object.
   * The pointer needs to be released after use.
   *
   * @param opDesignInfoItf [out, PLMIExchangeExperienceDesignInfo#Release] 
   * output PLMIExchangeExperienceDesignInfo corresponding to the design info linked to the session object. Use this pointer to set information regarding the object displayed information. 
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL if the given option key already exists.
   */ 
   virtual HRESULT GetDesignInfo( PLMIExchangeExperienceDesignInfo * & opDesignInfoItf) = 0;

   /**
   * <b> GetAttributeInfoForMaskInternalKey</b> : Get the necessary attribute info regarding the attribute associated with the given internal key for the given mask id.
   * Please use the returned information, to retrieve the wanted attribute value with the help of the method GetAttribute(....).
   *
   * @param iStrMask [in] 
   * input mask id of the internal key for which, its associated attribute will be returned. 
   *
   * @param iStrInternalKey [in] 
   * input internal key for which we want to retrieve its associated attribute. 
   *
   * @param oStrAttributeName [out] 
   * output string corresponding to the name of the attribute associated with the given internal key.
   *
   * @param oValueType [out] 
   * output value type of the returned attribute name.
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *                   S_FALSE if the current internal key doesn't apply to the given object.
   *    Other,         E_FAIL 
   *                       - if the mask has not been applied to the object, 
   *                       - if the internal key has not being defined for the given mask id  .
   *                       - if there's an issue when retrieving the attribute information.
   */ 
   virtual HRESULT GetAttributeInfoForMaskInternalKey(const CATUnicodeString & iStrMask, const CATUnicodeString & iStrInternalKey, CATUnicodeString & oStrAttributeName, PLMExchangeExperienceValueType & oValueType) = 0;
};

//-----------------------------------------------------------------------

#endif
