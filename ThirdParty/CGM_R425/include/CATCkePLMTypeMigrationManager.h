// COPYRIGHT DASSAULT SYSTEMES  2012
//=============================================================================
//

#ifndef CATCkePLMTypeMigrationManager_H
#define CATCkePLMTypeMigrationManager_H

#include "PLMDictionaryNavServices.h"
#include "CATCkePLMTypeMigrationHelper.h"
#include "CATOmxOMap.h" 
#include "CATListOfCATUnicodeString.h"

class CATCkeMigrationCase;
typedef void* CATCkePLMTypeMigrationH;
 
class ExportedByPLMDictionaryNavServices CATCkePLMTypeMigrationManager
{
public:
	// This migration manager should be used when migrating a set of objects from former typing system (aka V1) and unified typing system (aka V1) or the other way round
	// It will cache some information on types

	// If you use this constructor, it is because you want the target typing system to be the one of the server (CATUnicornLevel::NewTyping)
	// It is the case for import of briefcases
	CATCkePLMTypeMigrationManager ();

	// If you use this constructor, it is because you want to precise what is the targeted typing system
	// It shall be used in the context of DBDI where the target is V1 sometimes even on a V2 server
	CATCkePLMTypeMigrationManager (const CATCkePLMTypeMigrationHelper::Target &iTarget);
	~CATCkePLMTypeMigrationManager ();

	// This method constructs a Migration helper or retrieve it if it has already be computed (same arguments) and kept

	// A migration helper will indicate what are the changes that need to be operated on an object of a given type and a given discipline, to migrate it to the targeted typing system
	// In input, the type can be a type in V1 or V2
	// If the type is a V1 type, we need also the value of the V_discipline attribute: example: RepresentationDS + Drafting
	// If the type is a V2 type, we don't really need the value of the V_discipline attribute: example: Drawing or a specialization type of Drawing

	// !! Do not deallocate the pointer
	CATCkePLMTypeMigrationHelper *FindMigrationHelper (const CATIType_var &iInputType,const CATUnicodeString &iDisciplineAttributeValueInput);
	CATCkePLMTypeMigrationHelper *FindMigrationHelper (const CATIType_var &iInputType,const CATIType_var &iDisciplineType);

	// Sometimes (Briefcase), we want to re-import an object. In this context, we know the target type and we don't want to change the type
	// Here we simply deduce the targeted typing system based on the nature of the type
	// !! Do not deallocate the pointer
	CATCkePLMTypeMigrationHelper *FindMigrationHelperKnowingTargetedType (const CATIType_var &iInputType,const CATUnicodeString &iDisciplineAttributeValueInput,const CATIType_var &iTargetedType);
	CATCkePLMTypeMigrationHelper *FindMigrationHelperKnowingTargetedType (const CATIType_var &iInputType,const CATIType_var &iDisciplineType,const CATIType_var &iTargetedType);

	// Briefcase import from V1 to V2 with a V2 type pre computed
	CATCkePLMTypeMigrationHelper *FindMigrationHelperV1toV2WithPreComputedV2 (const CATIType_var &iTargetType);


	// a migration helper can also be used for extension types. In this case, we can simply provide the discipline value. It is sufficient 
	// !! Do not deallocate the pointer
	CATCkePLMTypeMigrationHelper *FindMigrationHelper (const CATUnicodeString &iDisciplineAttributeValueInput);

	// Indicates if a migration has been performed on the data (from former to new typing)
	HRESULT NewTypingMigrationIfFinished (CATBoolean &alors);


	// Indicates if a migration has been performed on the data (from former to new typing)
  // This service is introduced for usage by PVS (saved queries and saved filters) in order to help them upgrade their data on the fly
  // PVS saved data contain some kind of a query which includes, name of the type, name of the attributes
  // As the query may have been saved in former typing (with custo types), the objective of the service is to 
  // - give the new type on which the query must be performed
  // - for each attribute, indicate what is the new name of the attribute (if changed) and the name of the extension where the attribute is located (if any)
  // Note that if the query didn't involve any former typing type and attributes, the service will answer that no migration need to be performed
  //
  // The correspondance between type and attributes (and extensions) comes from two sources
  // 1) the basic correspondance, independent from the customer customization
  // 2) a business rule that is computing the correspondance (delivered by the customer)
  // 
  // Returns E_INVALIDARG if input were incorrect (type & attributes not valid)
	// Returns E_FAIL if we failed in finding correspondance for some attributes. In this case we put "ERROR" in the name of the corresponding attribute)
	// Returns S_OK if there is a migration to perform
	// Returns S_FALSE if there is a no migration to perform
	HRESULT MigrateQuery (const CATIType_var &iInputType,                         // Input type saved in the query, that can be a former typing custo type (or not)
						            const CATListOfCATUnicodeString &iListAttributeNames,   // List of attributes saved in the query. May contain former typing attributes and modeler attributes
						            CATIType_var &iOutputType,                              // Type on which the query must be performed, if migration is necessary
          						  CATListOfCATUnicodeString &oListExtensionTypeNames,     // List of extension names for each attribute in input. May be blank if the attribute is located on the main type 
					          	  CATListOfCATUnicodeString &oListAttributeNames );       // List of attribute names to use for each attribute in input. May be blank, if the attribute is to be ignored
	
	// Indicates if a migration has been performed on the data (from former to new typing)
  // This service is introduced for usage by PVS (saved queries and saved filters) in order to help them upgrade their data on the fly
  // PVS saved data contain some kind of a query which includes, name of the type, name of the attributes
  // As the query may have been saved in former typing (with custo types), the objective of the service is to 
  // - give the new type on which the query must be performed
  // - for each attribute, indicate what is the new name of the attribute (if changed) and the name of the extension where the attribute is located (if any)
  // Note that if the query didn't involve any former typing type and attributes, the service will answer that no migration need to be performed
  //
  // The correspondance between type and attributes (and extensions) comes from two sources
  // 1) the basic correspondance, independent from the customer customization
  // 2) a business rule that is computing the correspondance (delivered by the customer)
  // 
  // this service is introduced to support OCDX migration when we don't find the type in dictionary....
  //
  // Returns E_INVALIDARG if input were incorrect (type & attributes not valid)
	// Returns E_FAIL if we failed in finding correspondance for some attributes. In this case we put "ERROR" in the name of the corresponding attribute)
	// Returns S_OK if there is a migration to perform
	// Returns S_FALSE if there is a no migration to perform
	HRESULT MigrateQueryWhenTypeIsLost (const CATUnicodeString &iInputTypeName,                         // Input type saved in the query, that can be a former typing custo type (or not)
						                          const CATListOfCATUnicodeString &iListAttributeNames,   // List of attributes saved in the query. May contain former typing attributes and modeler attributes
						                          CATIType_var &iOutputType,                              // Type on which the query must be performed, if migration is necessary
          						                CATListOfCATUnicodeString &oListExtensionTypeNames,     // List of extension names for each attribute in input. May be blank if the attribute is located on the main type 
					          	                CATListOfCATUnicodeString &oListAttributeNames );       // List of attribute names to use for each attribute in input. May be blank, if the attribute is to be ignored
  
  class ExtensionWithAttributes {
  public:
    ExtensionWithAttributes (const CATIType_var &extensionTypeInput,const CATListOfCATUnicodeString &ListAttributeNamesInput,const CATListOfCATUnicodeString &ListAttributeValuesInput):_extensionTypeInput(extensionTypeInput),_ListAttributeNamesInput(ListAttributeNamesInput),_ListAttributeValuesInput(ListAttributeValuesInput) {}
    ~ExtensionWithAttributes() {}

    CATIType_var               _extensionTypeInput;       // Contains the extension in input
    CATListOfCATUnicodeString  _ListAttributeNamesInput;  // Contains the list of attributes of the extension,
    CATListOfCATUnicodeString  _ListAttributeValuesInput; // Contains the list of attributes values of the extension,
    CATIType_var               _extensionOrTypeInOutput;  // Contains how the extension is transformed: NULL means replaced by the type, Same extension type if kept, another one if it is transformed
    CATListOfCATUnicodeString  _ListAttributeNamesOutput; // Contains the list of attributes of the extension in output. May be blank if attribute is to be ignored 

    HRESULT ManageExtension (const CATIType_var &iTypeOfRequestInInput,CATIType_var &iTypeOfRequestInOutput);
  };



  // Indicates if a migration has been performed on the data (from former to new typing)
  // This service is introduced for usage by PVS (saved queries and saved filters) in order to help them upgrade their data on the fly
  // PVS saved data contain some kind of a query which includes, name of the type, name of the attributes BUT also some extensions
  // (this presence of extensions may change the results of the service)
  // As the query may have been saved in former typing (with custo types), the objective of the service is to 
  // - give the new type on which the query must be performed
  // - for each attribute, indicate what is the new name of the attribute (if changed) and the name of the extension where the attribute is located (if any)
  // Finally, for each extension in input there are two possibilities
  // - either the extension still exist on the objects after migration, and we can keep the query as it was defined (including the attributes)
  // - either the extension has been transformed into another one (the attributes are unchanged but may be ignored)
  // - either the extension has disappeared (replaced by the type of the object (the attributes are now defined on the object or may be ignored)
  // Note that if the query didn't involve any former typing type and attributes, the service will answer that no migration need to be performed
  //
  // The correspondance between type and attributes (and extensions) comes from two sources
  // 1) the basic correspondance, independent from the customer customization
  // 2) a business rule that is computing the correspondance (delivered by the customer)
  // 
  // Returns E_INVALIDARG if input were incorrect (type & attributes not valid)
	// Returns E_FAIL if we failed in finding correspondance for some attributes. In this case we put "ERROR" in the name of the corresponding attribute)
	// Returns S_OK if there is a migration to perform
	// Returns S_FALSE if there is a no migration to perform
	HRESULT MigrateQueryWithExtensions (const CATIType_var &iInputType,                         // Input type saved in the query, that can be a former typing custo type (or not)
						                          const CATListOfCATUnicodeString &iListAttributeNames,   // List of attributes saved in the query. May contain former typing attributes and modeler attributes
						                          CATIType_var &iOutputType,                              // Type on which the query must be performed, if migration is necessary
          						                CATListOfCATUnicodeString &oListExtensionTypeNames,     // List of extension names for each attribute in input. May be blank if the attribute is located on the main type 
					          	                CATListOfCATUnicodeString &oListAttributeNames,         // List of attribute names to use for each attribute in input. May be blank, if the attribute is to be ignored
                                      ExtensionWithAttributes *extensionTab [],              // Pass a tab of extension of size sizeTab
                                      int sizeTab );                                      
  // Indicates if a migration has been performed on the data (from former to new typing)
  // This service is introduced for usage by PVS (saved queries and saved filters) in order to help them upgrade their data on the fly
  // PVS saved data contain some kind of a query which includes, name of the type, name of the attributes BUT also some extensions
  // (this presence of extensions may change the results of the service)
  // As the query may have been saved in former typing (with custo types), the objective of the service is to 
  // - give the new type on which the query must be performed
  // - for each attribute, indicate what is the new name of the attribute (if changed) and the name of the extension where the attribute is located (if any)
  // Finally, for each extension in input there are two possibilities
  // - either the extension still exist on the objects after migration, and we can keep the query as it was defined (including the attributes)
  // - either the extension has been transformed into another one (the attributes are unchanged but may be ignored)
  // - either the extension has disappeared (replaced by the type of the object (the attributes are now defined on the object or may be ignored)
  // Note that if the query didn't involve any former typing type and attributes, the service will answer that no migration need to be performed
  //
  // The correspondance between type and attributes (and extensions) comes from two sources
  // 1) the basic correspondance, independent from the customer customization
  // 2) a business rule that is computing the correspondance (delivered by the customer)
  // 
  // this service is introduced to support OCDX migration when we don't find the type in dictionary....
  //
  // Returns E_INVALIDARG if input were incorrect (type & attributes not valid)
	// Returns E_FAIL if we failed in finding correspondance for some attributes. In this case we put "ERROR" in the name of the corresponding attribute)
	// Returns S_OK if there is a migration to perform
	// Returns S_FALSE if there is a no migration to perform
	HRESULT MigrateQueryWithExtensionsWhenTypeIsLost (const CATUnicodeString &iInputTypeName,                         // Input type saved in the query, that can be a former typing custo type (or not)
						                          const CATListOfCATUnicodeString &iListAttributeNames,   // List of attributes saved in the query. May contain former typing attributes and modeler attributes
						                          CATIType_var &iOutputType,                              // Type on which the query must be performed, if migration is necessary
          						                CATListOfCATUnicodeString &oListExtensionTypeNames,     // List of extension names for each attribute in input. May be blank if the attribute is located on the main type 
					          	                CATListOfCATUnicodeString &oListAttributeNames,         // List of attribute names to use for each attribute in input. May be blank, if the attribute is to be ignored
                                      ExtensionWithAttributes *extensionTab [],              // Pass a tab of extension of size sizeTab
                                      int sizeTab );                                      


  // Dedicated service to retrieve the modeler type corresponding to OCDX Former typing even when they do not exist anymore in dictionary
  // To be used by coexistence
  // Returns E_INVALIDARG if type in input is not an OCDX Former typing type
	// Returns S_OK if we found the corresponding modeler type
	HRESULT RetrieveModelerTypeOnLostOCDXTypes (const CATUnicodeString &iOCDXTypeName, CATUnicodeString &oCorrespondingModelerType);
private:
	
	CATCkePLMTypeMigrationHelper *_FindMigrationHelper (const CATIType_var &iType,const CATUnicodeString &iDisciplineAttributeValueInput,CATCkePLMTypeMigrationHelper::Target ts,int cas=0);

	CATOmxOMap<CATUnicodeString,CATCkePLMTypeMigrationH> _map;
	CATCkePLMTypeMigrationHelper::Target _Target;

  	HRESULT MigrateQueryInternal (const CATUnicodeString &iTypeLost,
                        const CATIType_var &iInputType,                         // Input type saved in the query, that can be a former typing custo type (or not)
						            const CATListOfCATUnicodeString &iListAttributeNames,   // List of attributes saved in the query. May contain former typing attributes and modeler attributes
						            CATIType_var &iOutputType,                              // Type on which the query must be performed, if migration is necessary
          						  CATListOfCATUnicodeString &oListExtensionTypeNames,     // List of extension names for each attribute in input. May be blank if the attribute is located on the main type 
					          	  CATListOfCATUnicodeString &oListAttributeNames );       // List of attribute names to use for each attribute in input. May be blank, if the attribute is to be ignored
  
    HRESULT MigrateQueryWithExtensionsInternal (const CATUnicodeString &iTypeLost,
                                      const CATIType_var &iInputType,                         // Input type saved in the query, that can be a former typing custo type (or not)
						                          const CATListOfCATUnicodeString &iListAttributeNames,   // List of attributes saved in the query. May contain former typing attributes and modeler attributes
						                          CATIType_var &iOutputType,                              // Type on which the query must be performed, if migration is necessary
          						                CATListOfCATUnicodeString &oListExtensionTypeNames,     // List of extension names for each attribute in input. May be blank if the attribute is located on the main type 
					          	                CATListOfCATUnicodeString &oListAttributeNames,         // List of attribute names to use for each attribute in input. May be blank, if the attribute is to be ignored
                                      ExtensionWithAttributes *extensionTab [],              // Pass a tab of extension of size sizeTab
                                      int sizeTab );                                      
  
};
#endif


