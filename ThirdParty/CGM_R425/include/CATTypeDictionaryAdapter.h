#ifndef CATTypeDictionaryAdapter_h
#define CATTypeDictionaryAdapter_h

#include "CATLifSpecs.h"

#include "CATGlobalFunctions.h"
#include "CATIType.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATListValCATAttributeInfos.h"
#include "CATListValCATIType.h"
#include "CATITypeDictionaryListener.h"
#include "CATCkeTypeQualification.h"
class CATICkeObject_var;
class CATIInstance_var;
class CATIEnumere_var;

class CATListValCATBaseUnknown_var ;
class CATCkeDictionaryIndexVisitor;

//-----------
// Adaptater
//----------- 
class ExportedByCATLifSpecs CATTypeDictionaryAdapter : public CATBaseUnknown
{
public:
	
	CATTypeDictionaryAdapter();
	virtual ~CATTypeDictionaryAdapter();
	
	//-------------------------------
	// CATITypeDictionary
	//-------------------------------
	virtual HRESULT ListPackages( CATListOfCATUnicodeString& olListOfPackages );
	virtual HRESULT ListPrerequisitesForPackage( const CATUnicodeString& iPackage,
		CATListOfCATUnicodeString& olListOfPrerequisites );
	virtual HRESULT AddPackage( const CATUnicodeString& iPackage,
		CATListOfCATUnicodeString& ilListOfPrerequisites );
	virtual HRESULT RemovePackage( const CATUnicodeString& iPackage );
	virtual HRESULT ListTypesForPackage( const CATUnicodeString& iPackage, 
		CATListValCATIType_var& olListOfTypes,
		boolean iIncludePrerequisites = 1 );
	virtual HRESULT ListTypesForPackages( const CATListOfCATUnicodeString& iPackages,
		CATListValCATIType_var& olListOfTypes,
		boolean iIncludePrerequisites = 1 );
	virtual HRESULT LoadPackage( const CATUnicodeString& iPackage );
	virtual HRESULT AddTypeForPackage( const CATIType_var& iType,
		const CATUnicodeString& iPackage,
		int isBrowsable = 1);
	virtual HRESULT FindType( const CATUnicodeString& iType,
		CATIType_var& oType );
	virtual HRESULT RetrieveType( const CATUnicodeString& iType,
							  CATIType_var& oType ) ;
	virtual HRESULT FindNLSType( const CATUnicodeString& iNLSType,
		CATIType_var& oType );
	virtual HRESULT FindNLSTypes( const CATUnicodeString& iNLSType,
		CATListValCATIType_var& olListOfTypes );
	virtual HRESULT FindTypeInPackage( const CATUnicodeString& iType,
		const CATUnicodeString& iPackage,
		CATIType_var& oType,
		boolean iIncludePrerequisites = 1);
	virtual HRESULT FindNLSTypeInPackages( const CATUnicodeString& iNLSType,
		const CATListOfCATUnicodeString& iPackages,
		CATIType_var& oType,
		boolean iIncludePrerequisites = 1);
	virtual HRESULT FindNLSTypesInPackages( const CATUnicodeString& iNLSType,
		const CATListOfCATUnicodeString& ilListOfPackages,
		CATListValCATIType_var& olListOfTypes,
		boolean iIncludePrerequisites = 1);
	virtual HRESULT CreateType( const CATUnicodeString& iTypeName,
		const CATUnicodeString& iNLSTypeName,
		const CATIType_var& iSuperType,
		CATIType_var            &oTypeCreated,
		const CATListValCATAttributeInfos* ilListOfAttributeInfos = NULL,
		CATInstanciationFunction iInstanciationFunction = NULL );
	virtual HRESULT CreateType( const CATUnicodeString& iTypeName,
		const CATUnicodeString& iNLSTypeName,
		const CATIType_var& iSuperType,
		CATIType_var            &oTypeCreated,
		const CATListValCATAttributeInfos* iListOfAttributeInfos ,
		const CATUnicodeString& iInstanciatiorName);
	virtual HRESULT UpdateType( const CATUnicodeString& iTypeName,
		const CATUnicodeString& iPackage,
		const CATListValCATAttributeInfos* ilListOfAttributeInfos = NULL );
	virtual HRESULT RemoveType( const CATIType_var& iType );
	virtual HRESULT RemoveType( const CATUnicodeString& iType );
	virtual HRESULT AdviseInstanciated( const CATIType_var &iType,
		const CATICkeObject_var &iInstance);
	virtual HRESULT AdviseTypeAdded( const CATIType_var &iType );
	virtual HRESULT AdviseTypeUpdated(const CATIType_var & iType );
	virtual HRESULT AdviseTypeRemoved( const CATIType_var &iType );
	virtual HRESULT Synchronize();
	virtual HRESULT AddDictionaryListener( const CATITypeDictionaryListener_var &iListener );
	virtual HRESULT RemoveDictionaryListener( const CATITypeDictionaryListener_var &iListener );
	virtual HRESULT AddMethodForPackage( const CATBaseUnknown_var& iMethod,
		const CATUnicodeString& iPackage );
	virtual HRESULT AdviseMethodAdded( const CATBaseUnknown_var &iMethod );
	virtual HRESULT AdviseMethodRemoved( const CATBaseUnknown_var &iMethod );
	virtual HRESULT FindPackageFromType(const CATIType_var& iType, CATUnicodeString& oPackage);
	virtual HRESULT FindTypeSafe( const CATUnicodeString &iType,
		const CATUnicodeString &iPackage, 
		CATIType_var & oType );
	virtual HRESULT ListSubTypesOfTypeForPackage( const CATUnicodeString& iPackage,
		const CATIType_var& iFatherType,
		CATListValCATIType_var& oListOfSubTypes,
		boolean iIncludePrerequisites = 1 );
	virtual HRESULT ListSubTypesOfTypeForPackages( const CATListOfCATUnicodeString& iPackages,
		const CATIType_var& iFatherType,
		CATListValCATIType_var& oListOfSubTypes,
		boolean iIncludePrerequisites = 1 );
	 
	//-------------------------------
	// CATITypeDictionaryInternal
	//-------------------------------
	virtual HRESULT ForcedFindType( const CATUnicodeString& iType, CATIType_var& oType );
	virtual HRESULT ForcedFindMethods( const CATUnicodeString& iMethod, CATListValCATBaseUnknown_var& oMethods );
	virtual HRESULT ForcedListPackages( CATListOfCATUnicodeString& oListOfPackages );
	
	virtual HRESULT ListSubProcessesInPackage(const CATString& iPackageName, CATListValCATBaseUnknown_var& oSubProcesses);
	virtual HRESULT FindSubProcess(const CATString& iSubProcessName, CATBaseUnknown_var& oSubProcess);
	virtual HRESULT ForcedFindSubProcess(const CATString& iSubProcessName, CATBaseUnknown_var& oSubProcess);
	
	virtual HRESULT ListMainBehaviorsForType(const CATIType_var& iType, CATListValCATBaseUnknown_var& oMainBehaviors);
	virtual HRESULT FindMainBehaviorForType(const CATString& iTypeName, const CATString& iBehaviorName, CATBaseUnknown_var& oMainBehavior);
	virtual HRESULT ForcedFindMainBehaviorsForType(const CATString& iTypeName, const CATString& iBehaviorName, CATListValCATBaseUnknown_var& oMainBehaviors);
	
	virtual HRESULT TraverseIndex(CATCkeDictionaryIndexVisitor& aVisitor);
	virtual HRESULT PackageIsLoaded(const CATUnicodeString &iPackage,int& iIsLoaded);
	/**
	 * Asks to load a library by its name.
	 * @param iLibraryName: C++ class name of the library
	 * @return   : CATCke::True if succeeded
	 */
	virtual CATCke::Boolean LoadLibrary (const char *iLibraryName);
	
	/**
	* Returns the list of the types that can be instanciated.
	*
	* @param olListOfTypes List of types that can be instanciated.
	*/
	virtual HRESULT ListInstanciableTypes (CATListValCATIType_var& olListOfTypes) ;

	// Service for PLM Dic enumere projection
    virtual CATIEnumere_var CreateEnumereType(const CATUnicodeString &name,const CATUnicodeString& nlsName,const CATListOfCATUnicodeString &listValues,const CATListOfCATUnicodeString &listNlsValues) ;

	
	
	
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
	 HRESULT CreateRepModelerType( const CATUnicodeString& iTypeName,
								          const CATUnicodeString& iNLSTypeName,
								          const CATIType_var&     iSuperType,
								          const CATBoolean        isAbstract,
										  const CATUnicodeString  &iIconName ,
							           	  CATIType_var            &oTypeCreated,
										  const CATListValCATAttributeInfos* ilListOfAttributeInfos = NULL,
										  const CATUnicodeString& iInstanciatiorName = "",
										  const CATBoolean        iIsDerivable = FALSE,
										  const CATBoolean        iIsExtensible = FALSE
										  ) ;
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
	HRESULT CreateRepExtensionType( const CATUnicodeString& iTypeName,
								          const CATUnicodeString& iNLSTypeName,
								          const CATIType_var&     iSuperType,
								          const CATBoolean        isAbstract,
										  const CATUnicodeString  &iIconName ,
							           	  CATIType_var            &oTypeCreated,
										  const CATListValCATAttributeInfos* ilListOfAttributeInfos = NULL,
										  const CATUnicodeString& iInstanciatiorName = "",
										  const CATBoolean        iIsDerivable = FALSE
										  ) ;
	/**
	* Creates a PLM Modeler type. Remember to add it to the dictionary in order to be able to use it. 
	* (@href CATITypeDictionary#AddTypeForPackage ). The last (optional) argument should always be NULL.
	*
	* @param iTypeName Internal name of the type.
	* @param iNLSTypeName NLS name of the type.
	* @param iSuperType Supertype of the type.
	* @param oTypeCreated Created type.
	* @param ilListOfAttributeInfos List of the type attributes.
	* @param iInstanciationFunction Instanciation function needed for Generative Knowledge (default to NULL).
	* @param iIconName name of the icon to represent this type. 
	* @param iIsSearchable: is the type available in the search/query
	* @param iIsDerivable: can we derive this type with a customer type
	* @param iIsExtensible: can we extend this type with a customer extension
	* @param iSupportsDeployment: can we specialize the deployment type on this type
	* @param iDMCDerivable: is a modeler type V1 that needed to be customised in V1
	*/

	// The argument iInstanciationFunction is a pointer to function which can be used by
	// the CATIInstanciation#InstanciateObject service (which is not CAA).

	HRESULT CreatePLMModelerType( const CATUnicodeString& iTypeName,
								          const CATUnicodeString& iNLSTypeName,
								          const CATIType_var&     iSuperType,
								          const CATBoolean        isAbstract,
										  const CATUnicodeString  &iIconName ,
							           	  CATIType_var            &oTypeCreated,
										  const CATListValCATAttributeInfos* ilListOfAttributeInfosPublic = NULL,
										  const CATListValCATAttributeInfos* ilListOfAttributeInfosPrivate = NULL,
										  const CATUnicodeString& iInstanciatiorName = "",
										  const CATBoolean        iIsSearchable = TRUE,
										  const CATBoolean        iIsDerivable = FALSE,
										  const CATBoolean        iIsExtensible = FALSE,
										  const CATBoolean        iSupportsDeployment = FALSE,
										  const CATBoolean        iDMCDerivable = FALSE) ;

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
	HRESULT CreateCustoType		( const CATUnicodeString& iTypeName,
								          const CATUnicodeString& iNLSTypeName,
								          const CATIType_var&     iSuperType,
							           	  CATIType_var            &oTypeCreated,
										  const CATListValCATAttributeInfos* ilListOfAttributeInfos = NULL
                      ) {return E_FAIL;}
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
	*/
	HRESULT CreateDeploymentExtension		(   const CATUnicodeString& iTypeName,
														const CATUnicodeString& iNLSTypeName,
														const CATIType_var&     iSuperType,
							           					CATIType_var            &oTypeCreated,
														const CATListValCATAttributeInfos* ilListOfAttributeInfos = NULL,
														const CATBoolean &iAutomatic = FALSE
                      ) {return E_FAIL;}

	// Creating a PLM Extension type
	HRESULT CreatePLMExtensionType( const CATUnicodeString& iTypeName,
								          const CATUnicodeString& iNLSTypeName,
								          const CATIType_var&     iSuperType,
								          const CATBoolean        isAbstract,
										  const CATUnicodeString  &iIconName ,
							           	  CATIType_var            &oTypeCreated,
										  const CATListValCATAttributeInfos* ilListOfAttributeInfosPublic = NULL,
										  const CATListValCATAttributeInfos* ilListOfAttributeInfosPrivate = NULL,
										  const CATUnicodeString& iInstanciatiorName = "",
										  const CATBoolean        iIsSearchable = TRUE,
										  const CATBoolean        iIsDerivable = FALSE
                      ) {return E_FAIL;}
		/**
	* Creates a PLM Modeler type implemented as a discipline. Remember to add it to the dictionary in order to be able to use it. 
	* (@href CATITypeDictionary#AddTypeForPackage ). The last (optional) argument should always be NULL.
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
	HRESULT CreatePLMModelerDiscipline (const CATUnicodeString& iTypeName,
												const CATUnicodeString& iNLSTypeName,
												const CATIType_var&     iSuperType,
												const CATBoolean        isAbstract,
												const CATUnicodeString  &iIconName ,
							           			CATIType_var            &oTypeCreated,
												  const CATUnicodeString& iInstanciatiorName = "",
												const CATBoolean        iIsSearchable = TRUE,
												const CATBoolean        iIsDerivable = FALSE,
												const CATBoolean        iIsExtensible = FALSE,
												const CATBoolean        iSupportsDeployment = FALSE,
											    const CATListValCATAttributeInfos* ilListOfAttributeInfosPublic = NULL,
										        const CATListValCATAttributeInfos* ilListOfAttributeInfosPrivate = NULL
                      ) {return E_FAIL;}

		/**
	* Creates a PLM Extension type implemented as a discipline. Remember to add it to the dictionary in order to be able to use it. 
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
	* @param iInstanciationFunction Instanciation function needed for Generative Knowledge (default to NULL).
	* @param iIsSearchable: is the type available in the search/query
	* @param iIsDerivable: can we derive this type with a customer type
	*/
	HRESULT CreatePLMExtensionDiscipline( const CATUnicodeString& iTypeName,
								          const CATUnicodeString& iNLSTypeName,
								          const CATIType_var&     iSuperType,
								          const CATBoolean        isAbstract,
										  const CATUnicodeString  &iIconName ,
							           	  CATIType_var            &oTypeCreated,
										  const CATUnicodeString& iInstanciatiorName = "",
										  const CATBoolean        iIsSearchable = TRUE,
										  const CATBoolean        iIsDerivable = FALSE,
										  const CATListValCATAttributeInfos* ilListOfAttributeInfosPublic = NULL,
									      const CATListValCATAttributeInfos* ilListOfAttributeInfosPrivate = NULL
                      ) {return E_FAIL;}

	/**
	* Do not use
	* Creates a PLM Customer type. Remember to add it to the dictionary in order to be able to use it. 
	* (@href CATITypeDictionary#AddTypeForPackage ). The last (optional) argument should always be NULL.
	*
	* @param iTypeName Internal name of the type.
	* @param iNLSTypeName NLS name of the type.
	* @param iSuperType Supertype of the type.
	* @param oTypeCreated Created type.
	* @param isAbstract is the type an abstract type
	* @param ilListOfAttributeInfos List of the type attributes.
	* @param iIconName name of the icon to represent this type. 
	* @param iIsSearchable: is the type available in the search/query
	* @param iIsDerivable: can we derive this type with a customer type
	*/

	// The argument iInstanciationFunction is a pointer to function which can be used by
	// the CATIInstanciation#InstanciateObject service (which is not CAA).
  
	HRESULT CreatePLMCustomerType( const CATUnicodeString& iTypeName,
								          const CATUnicodeString& iNLSTypeName,
								          const CATIType_var&     iSuperType,
								          const CATBoolean        isAbstract,
										  const CATUnicodeString  &iIconName ,
							           	  CATIType_var            &oTypeCreated,
										  const CATListValCATAttributeInfos* ilListOfAttributeInfos = NULL,
										  const CATBoolean        iIsSearchable = TRUE,
										  const CATBoolean        iIsDerivable = FALSE
                      ) {return E_FAIL;}

	/**
	* Do not use
	* Creates a PLM Customer extension. Remember to add it to the dictionary in order to be able to use it. 
	* (@href CATITypeDictionary#AddTypeForPackage ). The last (optional) argument should always be NULL.
	*
	* @param iTypeName Internal name of the type.
	* @param iNLSTypeName NLS name of the type.
	* @param iSuperType Supertype of the type.
	* @param oTypeCreated Created type.
	* @param ilListOfAttributeInfos List of the type attributes.
	* @param iIconName name of the icon to represent this type. 
	* @param iIsSearchable: is the type available in the search/query
	* @param iIsDerivable: can we derive this type with a customer type
	*/

	// The argument iInstanciationFunction is a pointer to function which can be used by
	// the CATIInstanciation#InstanciateObject service (which is not CAA).
  
	HRESULT CreatePLMCustomerExtension( const CATUnicodeString& iTypeName,
								          const CATUnicodeString& iNLSTypeName,
								          const CATIType_var&     iSuperType,
								          const CATBoolean        isAbstract,
										  const CATUnicodeString  &iIconName ,
							           	  CATIType_var            &oTypeCreated,
										  const CATListValCATAttributeInfos* ilListOfAttributeInfos = NULL,
										  const CATBoolean        iIsSearchable = TRUE,
										  const CATBoolean        iIsDerivable = FALSE
                                            ) {return E_FAIL;}
#endif
	/**
	* Do not use
	* Creates a Rep Customer type. Remember to add it to the dictionary in order to be able to use it. 
	* (@href CATITypeDictionary#AddTypeForPackage ). .
	*
	* @param iTypeName Internal name of the type.
	* @param iNLSTypeName NLS name of the type.
	* @param iSuperType Supertype of the type.
	* @param oTypeCreated Created type.
	* @param ilListOfAttributeInfos List of the type attributes.
	* @param iIconName name of the icon to represent this type. 
	* @param iIsDerivable: can we derive this type with a customer type
	*/

	// The argument iInstanciationFunction is a pointer to function which can be used by
	// the CATIInstanciation#InstanciateObject service (which is not CAA).

	HRESULT CreateRepCustomerType( const CATUnicodeString& iTypeName,
								          const CATUnicodeString& iNLSTypeName,
								          const CATIType_var&     iSuperType,
								          const CATBoolean        isAbstract,
										  const CATUnicodeString  &iIconName ,
							           	  CATIType_var            &oTypeCreated,
										  const CATListValCATAttributeInfos* ilListOfAttributeInfos = NULL,
										  const CATBoolean        iIsDerivable = TRUE) ;

	/**
	* Do not use
	* Creates a Rep Customer extension. Remember to add it to the dictionary in order to be able to use it. 
	* (@href CATITypeDictionary#AddTypeForPackage ). The last (optional) argument should always be NULL.
	*
	* @param iTypeName Internal name of the type.
	* @param iNLSTypeName NLS name of the type.
	* @param iSuperType Supertype of the type.
	* @param oTypeCreated Created type.
	* @param ilListOfAttributeInfos List of the type attributes.
	* @param iIconName name of the icon to represent this type. 
	*/

	// The argument iInstanciationFunction is a pointer to function which can be used by
	// the CATIInstanciation#InstanciateObject service (which is not CAA).

	HRESULT CreateRepCustomerExtension( const CATUnicodeString& iTypeName,
								          const CATUnicodeString& iNLSTypeName,
								          const CATIType_var&     iSuperType,
								          const CATBoolean        isAbstract,
										  const CATUnicodeString  &iIconName ,
							           	  CATIType_var            &oTypeCreated,
										  const CATListValCATAttributeInfos* ilListOfAttributeInfos = NULL,
										  const CATBoolean        iIsDerivable = FALSE) ;


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
	HRESULT CreateContractType  ( const CATUnicodeString& iTypeName,
								          const CATUnicodeString& iNLSTypeName,
								          const CATIType_var&     iSuperType,
							           	  CATIType_var            &oTypeCreated,
										  const CATListValCATAttributeInfos* ilListOfAttributeInfos = NULL
										  ) ;

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

	HRESULT CreateTypeWithPrivate( const CATUnicodeString& iTypeName,
								const CATUnicodeString& iNLSTypeName,
								const CATIType_var& iSuperType,
								CATIType_var            &oTypeCreated,
								const CATListValCATAttributeInfos* ilListOfAttributeInfosPublic ,
								const CATListValCATAttributeInfos* ilListOfAttributeInfosPrivate ,
								const CATUnicodeString& iInstanciatiorName) ;

	// This method retrieves the subtypes of a type... Bad PCS at the moment
	virtual HRESULT ListSubtypes (const CATIType_var &iTypeOrigin, CATListValCATIType_var& olListOfSubTypes,CATBoolean iRecursive=TRUE); // A surcharger en dessous


	/**
	* Creates an occurence type. Remember to add it to the dictionary in order to be able to use it. 
	* It is mandatory to give a name nd a NLS name. The name is an identifier. The NLs Name is to present it to user.
	* A supertype must be given. If no type is provided, we will use Feature.
	* A contract may have volatile attributes
	* 
	* @param iTypeName Internal name of the type.
	* @param iNLSTypeName NLS name of the type.
	* @param iSuperType Supertype of the type.
	* @param isAbstract is the type an abstract type
	* @param iIconName name of the icon to represent this type. 
	* @param oTypeCreated Created type.
	* @param ilListOfAttributeInfos List of the type attributes.
	*/
	virtual HRESULT CreateOccurrenceType  ( const CATUnicodeString& iTypeName,
								            const CATUnicodeString& iNLSTypeName,
								            const CATIType_var&     iSuperType,
								            const CATBoolean        isAbstract,
										    const CATUnicodeString  &iIconName ,
							           	    CATIType_var            &oTypeCreated,
										    const CATListValCATAttributeInfos* ilListOfAttributeInfos = NULL
										   ) ;


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
	* @param iInstanciatiorName.*/
	virtual HRESULT CreateComposedType  ( const CATUnicodeString& iTypeName,
								          const CATUnicodeString& iNLSTypeName,
								          const CATIType_var&     iSuperType,
										  const CATListOfCATUnicodeString &iListOfAggregatedTypes,
							           	  CATIType_var            &oTypeCreated,
										  const CATUnicodeString& iInstanciatiorName,
									      const CATUnicodeString  &iIconName ="",
										  const CATUnicodeString  &iNewableProperty="All") ;

	virtual CATIType_var GetDatabaseObjectType();

  virtual CATBoolean IsKweDicoEmpty(); //-- [chd:30.03.2018] 

	protected:
	
		// A appeler lors d'un ListPackages. Peut etre appelé plusieurs fois puisque le travail n'est fait qu'une fois
		HRESULT CreatePLMPackages () const;

		// Va chercher un type PLM (et le charger): ne doit etre appelé qu'apres un echec du FindType en memoire
		HRESULT LoadAndFindPLMType (const CATUnicodeString &iTypeName,CATIType_var &oType) const;

		// Va forcer le chargement du contenu d'un package Knowledge (provoquant le chargement du metadata)
		// Doit etre appelé dans ListTypesForPackages
		HRESULT LoadPLMPackage (const CATUnicodeString &iPackageName) const;
	
};

#endif
