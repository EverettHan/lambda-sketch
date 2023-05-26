//=======================================================================================
// WARNING: YWE 18:09:24 SINGLE-CODE 2015x => NO LOCAL CHANGE EXPECTED - USE IMPORT  
//=======================================================================================
//===================================================================
// COPYRIGHT  2014/06/10
//===================================================================
// PLMIExchangeModelDefinition.cpp
// Header definition of class PLMIExchangeModelDefinition
//===================================================================
//
// Usage notes: Interface used to define the experience model which will be 
// manipulated by the customization. 
// i.e attribute mask can be added through this interface.
//
//===================================================================
//  2014/06/10 Creation: Code generated by the 3DS wizard
//===================================================================
#ifndef PLMIExchangeModelDefinition_H
#define PLMIExchangeModelDefinition_H

#include "PLMExchangeInterfaces.h"
#include "CATListOfCATUnicodeString.h"
#include "PLMExchangeExperienceDictionary.h"
#include "CATBaseUnknown.h"

class PLMIExchangeExperienceSessionObject;

extern ExportedByPLMExchangeInterfaces  IID IID_PLMIExchangeModelDefinition ;

/**
* <b> PLMExchangeModelAttrMaskFunction</b>: Type for the callback which will be used to define the attributes to use for the inputs.
* This type defined the function signature used by the AddAttributeMask.
* For the given object, mask id and list of internal id , the method will have to return : 
* - the list of attribute name associated with the given inputs,
* - the list of alias to use for each returned attribute name.
* - the list of type to use for each returned attribute. (PLMExchangeExperienceValueType defined in the PLMExchangeExperienceDictionary.h)
*   ValueType_NLSKey and ValueType_PtrCATBaseUnknown are NOT supported as type of attribute which can be used for a mask.
* The 3 output list, oListOfAttributeName ,oListOfAttributeAlias and oListOfAttributeType must have the same size as the input list iListOfInternalKey.
*
* The input ioMaskObjectKey holds the mapping key which will be associated with the returned information (oListOfAttributeName, oListOfAttributeAlias, oListOfAttributeType).
* This value will need to be kept for later use if the returned output can be applied to any other following session objects.
* If the given session object has the same output as another one already processed, then please :
* - Change ioMaskObjectKey to the "ioMaskObjectKey" key which has been used for the previous similar object.
* - Return empty lists. 
*
* If for the given input object, the mask doesn't apply, please return S_FALSE.
* If for the given input object, an internal key doesn't apply, please return empty string for the corresponding internalKey.
* i.e : Internal key at index 5 doesn't apply to current object, then index 5 of returned list oListOfAttributeAlias, oListOfAttributeAlias and oListOfAttributeType must be empty strings and 0.
* If for the given input object and internal key, there is no applicable alias, please return empty string for the corresponding index of the alias output list.
*
* The attributes defined for mask can be of two natures :
* - exposed attributes : These attributes are stored in the database and can be accessed through a query.
*        For these type of attributes, their values will automatically be set when needed.      
*        All attributes with a PLMExchangeExperienceValueType different from 0 are considered as "Exposed".   
* - internal attributes : These atttributes are not stored in the database and are usually computed at runtime.
*        They have to be manually set prior to any mask usage. 
*        All attributes with a PLMExchangeExperienceValueType equal to 0 are considered as "Internal".   
*
* Example : 
* input : 
*   - iStrMaskId == "SimulateMaskID"
*   - ipSessionObject
*   - List of internal identifier (key).
*     - InternalCreation
*     - InternalMaturity
*     - InternalProject
*     - ....
*   - ioMaskObjectKey = 10
* Output : 
*   - List of attribute name to associate with the "SimulateMaskID" for the type "PLMType_Reference".
*     - V_Created
*     - V_Maturity
*     - V_Project 
*     - ....
*   - List of alias name to associate with the returned attribute .
*     - Date of Creation
*     - Maturity
*     - Project
*     - ....
*   - List of type to associate with the returned attribute .
*     - ValueType_Date
*     - ValueType_String
*     - ValueType_String
*     - ValueType_None
*     - ....
*
* @param iStrMaskId (in).
* input string corresponding to the MaskId to consider.
* This mask id given has been set when calling the method AddAttributeMask.
*
* @param ipSessionObject (in).
* input object to consider when returning the list of attribute name.
* If the given object doesn't apply to the given mask id, please return S_FALSE with empty lists.
*
* @param iListOfInternalKey (in).
* input list of CATUnicodeString containing the internal identifier (key)  defined for the given mask id.
* For each internal id, an attribute name and alias must be associated.
*
* @param ioMaskObjectKey (in, out).
* input unsigned int which hold the key which will be associated with the outputs.
* This value can be set to a previous saved key. By doing so, the current session object will be associated with outputs returned for that particular saved key.
*
* @param oListOfAttributeName (out)
* output list of attribute name to use for the given mask and object type.  
* Attribute names which will be queried to retrieve the corresponding value.
* Values must be ordered as the iListOfInternalId.
* i.e : oListOfAttributeName[1] is the attribute name corresponding to the internal id iListOfInternalKey[1].
*
* @param oListOfAttributeAlias (out)
* output list of alias to associate with returned attribute name.  
* Values must be NLS and ordered as the oListOfAttributeAlias.
* i.e : oListOfAttributeAlias[1] is the alias of attribute oListOfAttributeName[1].
*
* @param oListOfAttributeType (out)
* output list of type to associate with returned attribute name .
* Types are defined in PLMExchangeExperienceDictionary.h #PLMExchangeExperienceValueType.  
* ValueType_NLSKey and ValueType_PtrCATBaseUnknown are NOT supported as type of attribute which can be used for a mask.
* Values must be ordered as the oListOfAttributeName.
* i.e : oListOfAttributeType[1] is the type of attribute oListOfAttributeName[1].
*
* @return
*    Legal values:  S_OK if the method succeeds.  
*                   S_FALSE if the mask doesn't to the given input object.
*    Other,         E_FAIL .
*/ 
typedef HRESULT (CATBaseUnknown::*PLMExchangeModelAttrMaskFunction)(CATUnicodeString & iStrMaskId, 
                                                                     PLMIExchangeExperienceSessionObject * & ipSessionObject, 
                                                                     CATListOfCATUnicodeString & iListOfInternalKey , 
                                                                     unsigned int & ioMaskObjectKey,
                                                                     CATListOfCATUnicodeString & oListOfAttributeName ,                                                                      
                                                                     CATListOfCATUnicodeString & oListOfAttributeAlias,
                                                                     CATListOfInt & oListOfAttributeType );

class ExportedByPLMExchangeInterfaces PLMIExchangeModelDefinition: public CATBaseUnknown
{
CATDeclareInterface;

public:

   /**
   * <b> AddAttributeMask</b> : Add an attribute mask for the current experience model.
   * The attribute mask is defined by an unique ID, a list of internal identifier and attribute maks function.
   * The list of internal identifier is used to link a unique key to a set of attribute.
   * This is because a key can be associated with different attribute name depending on the object type.
   * ie . Key == InternalCreation
   *       -> For Reference, associated attribute will be V_Created.
   *       -> For Entity, associated attribute will be V_DateOfCreation.
   *       -> ....
   * The given function (iMaskFunction) will be called for each object type defined for PLMExchangeExperienceObjectType.
   *
   * @param iStrMaskId (in)
   * input string corresponding mask key (must be unique).
   *
   * @param iListOfInternalKey (in)
   * input list of string corresponding to the internal key defined for the created mask.
   * Through the method iMaskFunction, these internal keys will be associated with an attribute name for each object type.
   *
   * @param ipMaskFunctionSource (in)
   * input pointer on the object to use when calling the given function pointer. 
   * This is only useful if the given function pointer is a private object method which is accessing internal attribute.
   * If the given function pointer doesn't access directly to any internal attributes, then the source ipMaskFunctionSource can be set to NULL.
   * An add ref will done on this pointer if not null. 
   *
   * @param iMaskFunction (in)
   * input address on the function to call. Please refer the type definition for further information. 
   *
   * @param ibForceInit (in)
   * input boolean on whether or not we force the initialization of the mask to the session :
   * - at the experience initialization.
   * - whenever new objects are added to the session.
   * By default, it's TRUE which means that the initialization of the mask when the experience is launched.
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL if the given status key already exists.
   *                   E_INVALIDARG, if the id  iStrMaskId is already used, or the list of internal key is empty.
   */ 
   virtual HRESULT AddAttributeMask(const CATUnicodeString & iStrMaskId, CATListOfCATUnicodeString & iListOfInternalKey , CATBaseUnknown * ipMaskFunctionSource,  PLMExchangeModelAttrMaskFunction iMaskFunction,  CATBoolean ibForceInit = TRUE) = 0;

};

//-----------------------------------------------------------------------

#endif
 
