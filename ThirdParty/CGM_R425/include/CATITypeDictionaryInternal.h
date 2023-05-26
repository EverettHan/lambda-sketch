// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// CATITypeDictionaryInternal.h
// Define the CATITypeDictionaryInternal interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Sep 2004  Creation: Code generated by the CAA wizard  sgq
//===================================================================
#ifndef CATITypeDictionaryInternal_H
#define CATITypeDictionaryInternal_H

#include "CATLifSpecs.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATLifSpecs IID IID_CATITypeDictionaryInternal;
#else
extern "C" const IID IID_CATITypeDictionaryInternal;
#endif

#include "CATListOfCATUnicodeString.h"
#include "CATBoolean.h"
#include "CATITypeDictionary.h"
#include "CATUnicodeString.h"

class CATIType_var;
class CATListValCATBaseUnknown_var;
class CATString;
class CATCkeDictionaryIndexVisitor;
class CATIEnumere_var;
//------------------------------------------------------------------

#define CATITypeDictionaryInternal_Simplification
/**
*
*/
class ExportedByCATLifSpecs CATITypeDictionaryInternal : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
  *
  */

  virtual HRESULT ForcedFindType(const CATUnicodeString& iType, CATIType_var& oType) = 0;
  virtual HRESULT ForcedFindMethods(const CATUnicodeString& iMethod, CATListValCATBaseUnknown_var& oMethods) = 0;
  virtual HRESULT ForcedListPackages(CATListOfCATUnicodeString& oListOfPackages) = 0;

  virtual HRESULT ListSubProcessesInPackage(const CATString& iPackageName, CATListValCATBaseUnknown_var& oSubProcesses) = 0;
  virtual HRESULT FindSubProcess(const CATString& iSubProcessName, CATBaseUnknown_var& oSubProcess) = 0;
  virtual HRESULT ForcedFindSubProcess(const CATString& iSubProcessName, CATBaseUnknown_var& oSubProcess) = 0;

  virtual HRESULT ListMainBehaviorsForType(const CATIType_var& iType, CATListValCATBaseUnknown_var& oMainBehaviors) = 0;
  virtual HRESULT FindMainBehaviorForType(const CATString& iTypeName, const CATString& iBehaviorName, CATBaseUnknown_var& oMainBehavior) = 0;
  virtual HRESULT ForcedFindMainBehaviorsForType(const CATString& iTypeName, const CATString& iBehaviorName, CATListValCATBaseUnknown_var& oMainBehaviors) = 0;

  virtual HRESULT TraverseIndex(CATCkeDictionaryIndexVisitor& aVisitor) = 0;

  virtual HRESULT PackageIsLoaded(const CATUnicodeString &iPackage, int& iIsLoaded) = 0;

  // Service for PLM Dic enumere projection
  virtual CATIEnumere_var CreateEnumereType(const CATUnicodeString &name, const CATUnicodeString& nlsName, const CATListOfCATUnicodeString &listValues, const CATListOfCATUnicodeString &listNlsValues) = 0;


  // NEW SERVICES. DO NOT USE UNTIL YOU GET THE RIGHT DISCUSSION WITH KNOWLEDGE TEAM

  /**
  * Creates a Rep modeler type. Remember to add it to the dictionary in order to be able to use it.
  * (@href CATITypeDictionary#AddTypeForPackage ).
  * You can create a concrete type or an abstract one.
  * It is mandatory to give a name nd a NLS name. The name is an identifier. The NLs Name is to present it to user.
  * It is highly recommanded to provide an Icon name.
  * A supertype must be given. If no type is provided, we will use PLM Entity.
  * A type may have no attributes but usually it has some.
  * An instanciation function (for a concrete type) enables to create the object from the Knowledge language
  *
  * @param iTypeName Internal name of the type.
  * @param iNLSTypeName NLS name of the type.
  * @param iSuperType Supertype of the type.
  * @param isAbstract is the type an abstract type
  * @param iIconName name of the icon to represent this type.
  * @param oTypeCreated Created type.
  * @param ilListOfAttributeInfos List of the type attributes.
  * @param iInstanciationFunction Instanciation function needed for Generative Knowledge (default to NULL).
  * @param iIsDerivable: can we derive this type with a customer type
  * @param iIsExtensible: can we extend this type with a customer extension
  */
  virtual HRESULT CreateRepModelerType(const CATUnicodeString& iTypeName,
    const CATUnicodeString& iNLSTypeName,
    const CATIType_var&     iSuperType,
    const CATBoolean        isAbstract,
    const CATUnicodeString  &iIconName,
    CATIType_var            &oTypeCreated,
    const CATListValCATAttributeInfos* ilListOfAttributeInfos = NULL,
    const CATUnicodeString& iInstanciatiorName = "",
    const CATBoolean        iIsDerivable = FALSE,
    const CATBoolean        iIsExtensible = TRUE
  ) = 0;
  /**
  * Creates a Rep extension type. Remember to add it to the dictionary in order to be able to use it.
  * (@href CATITypeDictionary#AddTypeForPackage ).
  * You can create a concrete type or an abstract one.
  * It is mandatory to give a name nd a NLS name. The name is an identifier. The NLs Name is to present it to user.
  * It is highly recommanded to provide an Icon name.
  * A supertype must be given. If no type is provided, we will use PLM Entity.
  * A type may have no attributes but usually it has some.
  * An instanciation function (for a concrete type) enables to create the object from the Knowledge language
  *
  * @param iTypeName Internal name of the type.
  * @param iNLSTypeName NLS name of the type.
  * @param iSuperType Supertype of the type.
  * @param isAbstract is the type an abstract type
  * @param iIconName name of the icon to represent this type.
  * @param oTypeCreated Created type.
  * @param ilListOfAttributeInfos List of the type attributes.
  * @param iInstanciationFunction Instanciation function needed for Generative Knowledge (default to NULL).
  * @param iIsDerivable: can we derive this type with a customer type
  */
  virtual HRESULT CreateRepExtensionType(const CATUnicodeString& iTypeName,
    const CATUnicodeString& iNLSTypeName,
    const CATIType_var&     iSuperType,
    const CATBoolean        isAbstract,
    const CATUnicodeString  &iIconName,
    CATIType_var            &oTypeCreated,
    const CATListValCATAttributeInfos* ilListOfAttributeInfos = NULL,
    const CATUnicodeString& iInstanciatiorName = "",
    const CATBoolean        iIsDerivable = FALSE
  ) = 0;

  /**
  * Creates a PLM Modeler type. Remember to add it to the dictionary in order to be able to use it.
  * (@href CATITypeDictionary#AddTypeForPackage ).
  * You can create a concrete type or an abstract one.
  * It is mandatory to give a name nd a NLS name. The name is an identifier. The NLs Name is to present it to user.
  * It is highly recommanded to provide an Icon name.
  * A supertype must be given. If no type is provided, we will use PLM Entity.
  * A type may have no attributes but usually it has some.
  * An instanciation function (for a concrete type) enables to create the object from the Knowledge language
  *
  * @param iTypeName Internal name of the type.
  * @param iNLSTypeName NLS name of the type.
  * @param iSuperType Supertype of the type.
  * @param isAbstract is the type an abstract type
  * @param iIconName name of the icon to represent this type.
  * @param oTypeCreated Created type.
  * @param ilListOfAttributeInfosPublic List of the type attributes (public)
  * @param ilListOfAttributeInfosPrivate List of the type attributes (private)
  * @param iInstanciationFunction Instanciation function needed for Generative Knowledge (default to NULL).
  * @param iIsSearchable: is the type available in the search/query
  * @param iIsDerivable: can we derive this type with a customer type
  * @param iIsExtensible: can we extend this type with a customer extension
  * @param iSupportsDeployment: can we specialize the deployment type on this type
  */
  virtual HRESULT CreatePLMModelerType(const CATUnicodeString& iTypeName,
    const CATUnicodeString& iNLSTypeName,
    const CATIType_var&     iSuperType,
    const CATBoolean        isAbstract,
    const CATUnicodeString  &iIconName,
    CATIType_var            &oTypeCreated,
    const CATListValCATAttributeInfos* ilListOfAttributeInfosPublic = NULL,
    const CATListValCATAttributeInfos* ilListOfAttributeInfosPrivate = NULL,
    const CATUnicodeString& iInstanciatiorName = "",
    const CATBoolean        iIsSearchable = TRUE,
    const CATBoolean        iIsDerivable = FALSE,
    const CATBoolean        iIsExtensible = TRUE,
    const CATBoolean        iSupportsDeployment = FALSE,
    const CATBoolean        iDMCDerivable = FALSE
  ) = 0;

  /**
  * Creates a Custo type (V1 typing system). Remember to add it to the dictionary in order to be able to use it.
  * (@href CATITypeDictionary#AddTypeForPackage ).
  * It is mandatory to give a name nd a NLS name. The name is an identifier. The NLs Name is to present it to user.
  * A supertype must be given. And it should be a modeler type only.
  *
  * @param iTypeName Internal name of the type.
  * @param iNLSTypeName NLS name of the type.
  * @param iSuperType Supertype of the type.
  * @param oTypeCreated Created type.
  * @param ilListOfAttributeInfos List of the type attributes.
  * @param iInstanciationFunction Instanciation function needed for Generative Knowledge (default to NULL).
  */
#ifndef  CATITypeDictionaryInternal_Simplification
  virtual HRESULT CreateCustoType(const CATUnicodeString& iTypeName,
    const CATUnicodeString& iNLSTypeName,
    const CATIType_var&     iSuperType,
    CATIType_var            &oTypeCreated,
    const CATListValCATAttributeInfos* ilListOfAttributeInfos = NULL
  ) = 0;
#endif
  /**
  * Creates a Deployment extension (V2 typing system). Remember to add it to the dictionary in order to be able to use it.
  * (@href CATITypeDictionary#AddTypeForPackage ).
  * It is mandatory to give a name nd a NLS name. The name is an identifier. The NLs Name is to present it to user.
  * A supertype must be given. And it should be a modeler type only.
  *
  * @param iTypeName Internal name of the type.
  * @param iNLSTypeName NLS name of the type.
  * @param iSuperType Supertype of the type.
  * @param oTypeCreated Created type.
  * @param ilListOfAttributeInfos List of the type attributes.
  * @param iInstanciationFunction Instanciation function needed for Generative Knowledge (default to NULL).
  * @param iAutomatic do we want to automatically add this extension to the extended types
  */
#ifndef  CATITypeDictionaryInternal_Simplification
  virtual HRESULT CreateDeploymentExtension(const CATUnicodeString& iTypeName,
    const CATUnicodeString& iNLSTypeName,
    const CATIType_var&     iSuperType,
    CATIType_var            &oTypeCreated,
    const CATListValCATAttributeInfos* ilListOfAttributeInfos = NULL,
    const CATBoolean &iAutomatic = FALSE
  ) = 0;
#endif
  /**
  * Creates a PLM Extension type. Remember to add it to the dictionary in order to be able to use it.
  * (@href CATITypeDictionary#AddTypeForPackage ). The last (optional) argument should always be NULL.
  * You can create a concrete type or an abstract one.
  * It is mandatory to give a name nd a NLS name. The name is an identifier. The NLs Name is to present it to user.
  * It is highly recommanded to provide an Icon name.
  * A supertype must be given. If no type is provided, we will use PLM Entity.
  * An extens type may have no attributes but usually it has some.
  * An instanciation function (for a concrete type) enables to create the object from the Knowledge language
  *
  * @param iTypeName Internal name of the type.
  * @param iNLSTypeName NLS name of the type.
  * @param iSuperType Supertype of the type.
  * @param isAbstract is the type an abstract type
  * @param iIconName name of the icon to represent this type.
  * @param oTypeCreated Created type.
  * @param ilListOfAttributeInfosPublic List of the type attributes (public)
  * @param ilListOfAttributeInfosPrivate List of the type attributes (private)
  * @param iInstanciationFunction Instanciation function needed for Generative Knowledge (default to NULL).
  * @param iIsSearchable: is the type available in the search/query
  * @param iIsDerivable: can we derive this type with a customer type
  */
#ifndef  CATITypeDictionaryInternal_Simplification
  virtual HRESULT CreatePLMExtensionType(const CATUnicodeString& iTypeName,
    const CATUnicodeString& iNLSTypeName,
    const CATIType_var&     iSuperType,
    const CATBoolean        isAbstract,
    const CATUnicodeString  &iIconName,
    CATIType_var            &oTypeCreated,
    const CATListValCATAttributeInfos* ilListOfAttributeInfosPublic = NULL,
    const CATListValCATAttributeInfos* ilListOfAttributeInfosPrivate = NULL,
    const CATUnicodeString& iInstanciatiorName = "",
    const CATBoolean        iIsSearchable = TRUE,
    const CATBoolean        iIsDerivable = FALSE
  ) = 0;
#endif                      

  /**
  * Creates a PLM Modeler type implemented as a discipline. Remember to add it to the dictionary in order to be able to use it.
  * (@href CATITypeDictionary#AddTypeForPackage ).
  * You can create a concrete type or an abstract one.
  * It is mandatory to give a name nd a NLS name. The name is an identifier. The NLs Name is to present it to user.
  * It is highly recommanded to provide an Icon name.
  * A supertype must be given. If no type is provided, we will use PLM Entity.
  * A type may have no attributes but usually it has some.
  * An instanciation function (for a concrete type) enables to create the object from the Knowledge language
  *
  * @param iTypeName Internal name of the type.
  * @param iNLSTypeName NLS name of the type.
  * @param iSuperType Supertype of the type.
  * @param isAbstract is the type an abstract type
  * @param iIconName name of the icon to represent this type.
  * @param oTypeCreated Created type.
  * @param iInstanciationFunction Instanciation function needed for Generative Knowledge (default to NULL).
  * @param iIsSearchable: is the type available in the search/query
  * @param iIsDerivable: can we derive this type with a customer type
  * @param iIsExtensible: can we extend this type with a customer extension
  * @param iSupportsDeployment: can we specialize the deployment type on this type
  */
#ifndef  CATITypeDictionaryInternal_Simplification

  virtual HRESULT CreatePLMModelerDiscipline(const CATUnicodeString& iTypeName,
    const CATUnicodeString& iNLSTypeName,
    const CATIType_var&     iSuperType,
    const CATBoolean        isAbstract,
    const CATUnicodeString  &iIconName,
    CATIType_var            &oTypeCreated,
    const CATUnicodeString& iInstanciatiorName = "",
    const CATBoolean        iIsSearchable = TRUE,
    const CATBoolean        iIsDerivable = FALSE,
    const CATBoolean        iIsExtensible = TRUE,
    const CATBoolean        iSupportsDeployment = FALSE,
    const CATListValCATAttributeInfos* ilListOfAttributeInfosPublic = NULL,
    const CATListValCATAttributeInfos* ilListOfAttributeInfosPrivate = NULL
  ) = 0;
#endif
  /**
* Creates a PLM Extension type implemented as a discipline. Remember to add it to the dictionary in order to be able to use it.
* (@href CATITypeDictionary#AddTypeForPackage ).
* You can create a concrete type or an abstract one.
* It is mandatory to give a name nd a NLS name. The name is an identifier. The NLs Name is to present it to user.
* It is highly recommanded to provide an Icon name.
* A supertype must be given. If no type is provided, we will use PLM Entity.
* An extens type may have no attributes but usually it has some.
* An instanciation function (for a concrete type) enables to create the object from the Knowledge language
*
* @param iTypeName Internal name of the type.
* @param iNLSTypeName NLS name of the type.
* @param iSuperType Supertype of the type.
* @param isAbstract is the type an abstract type
* @param iIconName name of the icon to represent this type.
* @param oTypeCreated Created type.
* @param iInstanciationFunction Instanciation function needed for Generative Knowledge (default to NULL).
* @param iIsSearchable: is the type available in the search/query
* @param iIsDerivable: can we derive this type with a customer type
*/
#ifndef  CATITypeDictionaryInternal_Simplification
  virtual HRESULT CreatePLMExtensionDiscipline(const CATUnicodeString& iTypeName,
    const CATUnicodeString& iNLSTypeName,
    const CATIType_var&     iSuperType,
    const CATBoolean        isAbstract,
    const CATUnicodeString  &iIconName,
    CATIType_var            &oTypeCreated,
    const CATUnicodeString& iInstanciatiorName = "",
    const CATBoolean        iIsSearchable = TRUE,
    const CATBoolean        iIsDerivable = FALSE,
    const CATListValCATAttributeInfos* ilListOfAttributeInfosPublic = NULL,
    const CATListValCATAttributeInfos* ilListOfAttributeInfosPrivate = NULL
  ) = 0;
#endif

  /**
  * Creates a Contract type. Remember to add it to the dictionary in order to be able to use it.
  * (@href CATITypeDictionary#AddTypeForPackage ). The last (optional) argument should always be NULL.
  * It is mandatory to give a name nd a NLS name. The name is an identifier. The NLs Name is to present it to user.
  * A supertype must be given. If no type is provided, we will use Feature.
  * A contract may have volatile attributes
  *
  * @param iTypeName Internal name of the type.
  * @param iNLSTypeName NLS name of the type.
  * @param iSuperType Supertype of the type.
  * @param oTypeCreated Created type.
  * @param ilListOfAttributeInfos List of the type attributes.
  */
  virtual HRESULT CreateContractType(const CATUnicodeString& iTypeName,
    const CATUnicodeString& iNLSTypeName,
    const CATIType_var&     iSuperType,
    CATIType_var            &oTypeCreated,
    const CATListValCATAttributeInfos* ilListOfAttributeInfos = NULL
  ) = 0;
  /**
  * Creates a type with a private view (use only when you have private data. Remember to add it to the dictionary in order to be able to use it
  * (@href CATITypeDictionary#AddTypeForPackage ).
  *
  * @param iTypeName Internal name of the type.
  * @param iNLSTypeName NLS name of the type.
  * @param iSuperType Supertype of the type.
  * @param oTypeCreated Created type.
  * @param ilListOfAttributeInfosPublic List of the type attributes.
  * @param ilListOfAttributeInfosPrivate List of the type attributes.
  * @param iInstanciatiorName Name of a CATIInstanciation implementation.
  */

  // The last argument is the name of an implementation of the CATIInstanciation interface.

  virtual HRESULT CreateTypeWithPrivate(const CATUnicodeString& iTypeName,
    const CATUnicodeString& iNLSTypeName,
    const CATIType_var& iSuperType,
    CATIType_var            &oTypeCreated,
    const CATListValCATAttributeInfos* ilListOfAttributeInfosPublic,
    const CATListValCATAttributeInfos* ilListOfAttributeInfosPrivate,
    const CATUnicodeString& iInstanciatiorName) = 0;


  // This method retrieves the subtypes of a type... 
  virtual HRESULT ListSubtypes(const CATIType_var &iTypeOrigin, CATListValCATIType_var& olListOfSubTypes, CATBoolean iRecursive = TRUE) = 0; // A surcharger en dessous

  /**
  * Creates an occurence type. Remember to add it to the dictionary in order to be able to use it.
  * It is mandatory to give a name and a NLS name. The name is an identifier. The NLs Name is to present it to user.
  * A supertype must be given. If no type is provided, we will use Feature.
  *
  * @param iTypeName Internal name of the type.
  * @param iNLSTypeName NLS name of the type.
  * @param iSuperType Supertype of the type.
  * @param isAbstract is the type an abstract type
  * @param iIconName name of the icon to represent this type.
  * @param oTypeCreated Created type.
  * @param ilListOfAttributeInfos List of the type attributes.
  */
  virtual HRESULT CreateOccurrenceType(const CATUnicodeString& iTypeName,
    const CATUnicodeString& iNLSTypeName,
    const CATIType_var&     iSuperType,
    const CATBoolean        isAbstract,
    const CATUnicodeString  &iIconName,
    CATIType_var            &oTypeCreated,
    const CATListValCATAttributeInfos* ilListOfAttributeInfos = NULL
  ) = 0;

  /**
  * Do not use this method!!!!!!!!!!!!!!!! <br>
  * Updates the type by changing the list of its attributes.
  *
  * You must give the full list of new attributes.
  *
  * @param iTypeName Internal name of the type.
  * @param iPackage Name of the package.
  * @param ilListOfAttributeInfos List pointer of attributes (default = NULL).
  * @return classic HRESULT
  */
  virtual HRESULT UpdateType(const CATUnicodeString& iTypeName,
    const CATUnicodeString& iPackage,
    const CATListValCATAttributeInfos* ilListOfAttributeInfos = NULL) = 0;

  /**
  * Creates a type which is built as an aggregation of several types (ex: 3DPart). Remember to add it to the dictionary in order to be able to use it.
  * (@href CATITypeDictionary#AddTypeForPackage).
  * It is mandatory to give a name nd a NLS name. The name is an identifier. The NLs Name is to present it to user.
  * A supertype must be given. If no type is provided, we will use Feature.
  * @param iTypeName Internal name of the type.
  * @param iNLSTypeName NLS name of the type.
  * @param iSuperType Supertype of the type.
  * @param iListOfAggregatedTypes list of aggregated types
  * @param oTypeCreated Created type.
  * @param iInstanciatiorName.
  * @param iIconName name of the icon to represent this type.
  * @param iNewableProperty nvalue of the Newable property (Newable, All, Insert with _Offline and _CAA suffix
  */
  virtual HRESULT CreateComposedType(const CATUnicodeString& iTypeName,
    const CATUnicodeString& iNLSTypeName,
    const CATIType_var&     iSuperType,
    const CATListOfCATUnicodeString &iListOfAggregatedTypes,
    CATIType_var            &oTypeCreated,
    const CATUnicodeString& iInstanciatiorName,
    const CATUnicodeString  &iIconName = "",
    const CATUnicodeString  &iNewableProperty = "All") = 0;


  // This type is made available only in R217
  // It regroups all data base types
  virtual CATIType_var GetDatabaseObjectType() = 0;

  /**
  * States wether the Kwe Dico is empty.
  * @return boolean CATTrue:  the Kwe Dico is empty
  *                 CATFalse: the Kwe Dico is not empty
  */
  virtual CATBoolean IsKweDicoEmpty() = 0; //-- [chd:02.09.2018] 

};

//------------------------------------------------------------------
CATDeclareHandler(CATITypeDictionaryInternal, CATBaseUnknown);

#endif
