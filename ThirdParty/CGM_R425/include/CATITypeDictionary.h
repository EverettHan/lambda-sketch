#ifndef CATITypeDictionary_h
#define CATITypeDictionary_h

// COPYRIGHT DASSAULT SYSTEMES 2000

/** 
 * @CAA2Level L1
 * @CAA2Usage U3
 */

// include module definition
#include "CATLifSpecs.h"


#include "CATGlobalFunctions.h"
#include "CATIType.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATListValCATAttributeInfos.h"
#include "CATListValCATIType.h"
#include "CATITypeDictionaryListener.h"
#include "CATCke.h"


class CATListValCATBaseUnknown_var ;

class CATICkeObject_var;

// OLE iid
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATLifSpecs IID_CATITypeDictionary;
#else
extern "C" const IID IID_CATITypeDictionary;
#endif

/**
 * Interface dedicated to accessing the unique repository of Knowledge types shown to the user.
 * The types come from the declaration of types by application within libraries (@href CATIAddLibrary)
 * or from the schemas defined in the database
 *
 * <b>Role</b>: This interface allows the developper to create and access
 * "exposed" types. These types can be grouped into packages
 * (one type belongs to at most one package).<br>
 * <br>
 * A package may require other packages : this means that types gathered in this
 * package, refer to types belonging to those required packages (through supertype
 * relation or attribute relation).<br>
 * <br>
 * Note that all the types are not systematically loaded at run-time (for performance
 * concern) so one can force the load of a package. In order to work, the person creating
 * a package, has to create a CATRsc file called "CATPackage<Name of my package>.CATRsc" with
 * one line : "PackageImplementation = "<Name of my implementation of CATIAdd[Type]Library>";".<br>
 * <br>
 * The most basic types are:
 * <li>"Boolean"</li>
 * <li>"Integer"</li>
 * <li>"Real"</li>
 * <li>"String"</li>
 * <li>"Magnitude"</li>
 * <li>"Feature"</li><br>
 * <br>
 * "Feature" is the common supertype of all complex types. If no supertype is provided
 * when creating a type, "Feature" is assumed.<br>
 * <br>
 * The dictionary can be retrieved with the @href CATGlobalFunctions#GetTypeDictionary service.
 *
 * @see CATIType, CATITypeDictionaryListener, CATIAddLibrary
 */
class ExportedByCATLifSpecs CATITypeDictionary : public CATBaseUnknown
{
	CATDeclareInterface;
public:
	/**
	* Returns the list of loaded packages names.
	*
	* @param olListOfPackages list of packages
	* @return classic HRESULT
	*/
	virtual HRESULT ListPackages( CATListOfCATUnicodeString& olListOfPackages ) = 0;

	/**
	* Returns the list of required packages for a given package.
	*
	* @param iPackage a package name.
	* @param olListOfPrerequisites the list of required package names.
	* @return classic HRESULT
	*/
	virtual HRESULT ListPrerequisitesForPackage( const CATUnicodeString& iPackage,
												 CATListOfCATUnicodeString& olListOfPrerequisites ) = 0;
	
	/**
	* Creates a package in the dictionary.
	*
	* @param iPackage Name of the package.
	* @param ilListOfPrerequisites List of required package names.
	* @return classic HRESULT
	*/
	virtual HRESULT AddPackage( const CATUnicodeString& iPackage,
								CATListOfCATUnicodeString& ilListOfPrerequisites ) = 0;

	/**
	* Removes a package and all the types belonging to it from the dictionary.
	*
	* @param iPackage Name of the package to be removed.
	* @return classic HRESULT
	*/
	virtual HRESULT RemovePackage( const CATUnicodeString& iPackage ) = 0;

	/**
	* Returns the list of the types contained in a package.
	*
	* The returned list can be restricted to the types in the package or be extended to
	* the types also belonging to required packages.
	*
	* @param iPackage Name of the package.
	* @param olListOfTypes List of wanted types.
	* @param iIncludePrerequisites Includes (1) or not (0) types of required packages. Default is 1.
	* @return classic HRESULT
	*/
	virtual HRESULT ListTypesForPackage( const CATUnicodeString& iPackage,
										 CATListValCATIType_var& olListOfTypes,
										 boolean iIncludePrerequisites = 1 ) = 0;

	/**
	* Returns the lists of the types contained in several packages.
	*
	* @param iPackages List of package names.
	* @param olListOfTypes List of found types.
	* @param iIncludePrerequisites Includes (1) or not (0) types of required packages. Default is 1.
	* @return classic HRESULT
	*/
	virtual HRESULT ListTypesForPackages( const CATListOfCATUnicodeString& iPackages,
										  CATListValCATIType_var& olListOfTypes,
										  boolean iIncludePrerequisites = 1 ) = 0;
	/**
	* Forces a package to be loaded.
	*
	* This is mandatory to define types depending on other types.
	*
	* @param iPackage Name of the package to be loaded.
	* @return classic HRESULT
	*/
	virtual HRESULT LoadPackage( const CATUnicodeString& iPackage ) = 0;

	/**
	* Adds a created type in an existing package of the dictionary. If this package name
	* equals "", then the type is stored in the dictionary but belongs to no package. A type created
	* but not added to the dictionary cannot be used.
	*
	* @param iType Type to be added.
	* @param iPackage Name of the package the type has to be added to.
	* @param isBrowsable Is (1) or is not (0) seen in Knowledge type browsers.
	* @return classic HRESULT
	*/
	virtual HRESULT AddTypeForPackage( const CATIType_var& iType,
									   const CATUnicodeString& iPackage,
									   int isBrowsable = 1) = 0;
	
	/**
	* Returns a type found by its internal name. Note that the type must have been
	* added to the dictionary in order for this method to successfull.
  * The purpose of this method is to be used when building a library and retrieving a type loaded by the prerequisite packages
	* See also @href CATITypeDictionary#FindTypeSafe.
	* See also @href CATITypeDictionary#RetrieveType.
	*
	* @param iType Internal name of the type.
	* @param oType Type (or NULL_var if not found).
	* @return classic HRESULT
	*/
	virtual HRESULT FindType( const CATUnicodeString& iType,
							  CATIType_var& oType ) = 0;

	/**
	* Returns a type found by its NLS name. Note that the type must have been
	* added to the dictionary in order for this method to successfull.
	*
	* @param iNLSType NLS name of the type.
	* @param oType Type (or NULL_var if not found).
	* @return classic HRESULT
	*/
	virtual HRESULT FindNLSType( const CATUnicodeString& iNLSType,
								 CATIType_var& oType ) = 0;

	/**
	* Returns a list of types corresponding to an NLS name. Note that the type must have been
	* added to the dictionary in order for this method to successfull. Note that there may be
	* several types with the same NLS name (!).
	*
	* @param iNLSType NLS name of the type.
	* @param olListOfTypes List of types.
	* @return classic HRESULT
	*/
	 virtual HRESULT FindNLSTypes( const CATUnicodeString& iNLSType,
								   CATListValCATIType_var& olListOfTypes ) = 0;

	/**
	* Returns a type found in a certain package (and maybe in its required packages).
	*
	* @param iType Name of the type.
	* @param iPackage Name of the package.
	* @param oType Found type (or NULL_var).
	* @param iIncludePrerequisites Includes required packages (1, default) or not (0).
	* @return classic HRESULT
	*/
	virtual HRESULT FindTypeInPackage( const CATUnicodeString& iType,
									   const CATUnicodeString& iPackage,
									   CATIType_var& oType,
									   boolean iIncludePrerequisites = 1) = 0;

	/**
	* Returns a type found in a certain package (and maybe in its required packages).
	* @param iNLSType NLS name of the type.
	* @param iPackages Name of the packages.
	* @param oType Found type (or NULL_var).
	* @param iIncludePrerequisites Includes required packages (1, default) or not (0).
	* @return classic HRESULT
	*/
	virtual HRESULT FindNLSTypeInPackages( const CATUnicodeString& iNLSType,
										   const CATListOfCATUnicodeString& iPackages,
										   CATIType_var& oType,
										   boolean iIncludePrerequisites = 1) = 0;

	/**
	* Returns a type found in a list of packages (and maybe in their required packages).
	*
	* @param iNLSType NLS name of the type.
	* @param ilListOfPackages List of packages names.
	* @param olListOfTypes Found types.
	* @param iIncludePrerequisites Includes required packages (1, default) or not (0).
	* @return classic HRESULT
	*/
	 virtual HRESULT FindNLSTypesInPackages( const CATUnicodeString& iNLSType,
											 const CATListOfCATUnicodeString& ilListOfPackages,
											 CATListValCATIType_var& olListOfTypes,
											 boolean iIncludePrerequisites = 1) = 0;

	/**
	* Creates a type. Remember to add it to the dictionary in order to be able to use it
	* (@href CATITypeDictionary#AddTypeForPackage ). The last (optional) argument should always be NULL.
	*
	* @param iTypeName Internal name of the type.
	* @param iNLSTypeName NLS name of the type.
	* @param iSuperType Supertype of the type.
	* @param oTypeCreated Created type.
	* @param ilListOfAttributeInfos List of the type attributes.
	* @param iInstanciationFunction Instanciation function needed for Generative Knowledge (default to NULL).
	* @return classic HRESULT
	*/

	// The argument iInstanciationFunction is a pointer to function which can be used by
	// the CATIInstanciation#InstanciateObject service (which is not CAA).

	virtual HRESULT CreateType( const CATUnicodeString& iTypeName,
								const CATUnicodeString& iNLSTypeName,
								const CATIType_var& iSuperType,
								CATIType_var            &oTypeCreated,
								const CATListValCATAttributeInfos* ilListOfAttributeInfos = NULL,
								CATInstanciationFunction iInstanciationFunction = NULL ) = 0;
	/**
	* Creates a type. Remember to add it to the dictionary in order to be able to use it
	* (@href CATITypeDictionary#AddTypeForPackage ). The last argument should
	* always be the empty string.
	* @param iTypeName Internal name of the type.
	* @param iNLSTypeName NLS name of the type.
	* @param iSuperType Supertype of the type.
	* @param oTypeCreated Created type.
	* @param iListOfAttributeInfos List of the type attributes.
	* @param iInstanciatiorName Name of a CATIInstanciation implementation.
	* @return classic HRESULT
	*/

	// The last argument is the name of an implementation of the CATIInstanciation interface.

	virtual HRESULT CreateType( const CATUnicodeString& iTypeName,
								const CATUnicodeString& iNLSTypeName,
								const CATIType_var& iSuperType,
								CATIType_var            &oTypeCreated,
								const CATListValCATAttributeInfos* iListOfAttributeInfos ,
								const CATUnicodeString& iInstanciatiorName) = 0;

	/**
	* Removes a type from the dictionary.
	*
	* @param iType Type to be removed.
	* @return classic HRESULT
	*/
	virtual HRESULT RemoveType( const CATIType_var& iType ) = 0;

	/**
	* Removes a type from the dictionary.
	*
	* @param iTypeName Internal name of the type.
	* @return classic HRESULT
	*/
	virtual HRESULT RemoveType( const CATUnicodeString& iTypeName ) = 0;

	/**
	* Indicates that a type from the dictionary was instanciated.
	*
	* This service should be called when an object for which it exists a @href CATICkeObject
	* implementation (and then a @href CATIType for this @href CATICkeObject ), is created.
	*
	* @param iType Type.
	* @param iInstance Instance of the type iType that was instanciated.
	* @return classic HRESULT
	*/
	virtual HRESULT AdviseInstanciated( const CATIType_var &iType,
										const CATICkeObject_var &iInstance) = 0;

	/**
	* Indicates that a type was added to the dictionary.
	*
	* @param iType Added type.
	* @return classic HRESULT
	*/
	virtual HRESULT AdviseTypeAdded( const CATIType_var &iType ) = 0;
	
	/**
	* Indicates that a type was updated from the dictionary.
	*
	* @param iType Updated type.
	* @return classic HRESULT
	*/
	virtual HRESULT AdviseTypeUpdated(const CATIType_var & iType ) = 0;

	/**
	* Indicates that a type was removed from the dictionary.
	*
	* @param iType Removed type.
	* @return classic HRESULT
	*/
	virtual HRESULT AdviseTypeRemoved( const CATIType_var &iType ) = 0;

	/**
	* This method can be called to ask dictionary listeners to synchronize their description if needed.
	* @return classic HRESULT
	*/
	virtual HRESULT Synchronize() = 0;

	/**
	* Adds a listener on the dictionary.
	*
	* The listener is called back when events are raised by the object.
	*
	* @param iListener  Listener to be added.
	* @return classic HRESULT
	*/
	virtual HRESULT AddDictionaryListener( const CATITypeDictionaryListener_var &iListener ) = 0;

	/**
	* Removes a listener on the dictionary.
	*
	* The listener is called back when events are raised by the object.
	*
	* @param iListener Listener to be removed.
	* @return classic HRESULT
	*/
	virtual HRESULT RemoveDictionaryListener( const CATITypeDictionaryListener_var &iListener ) = 0;

	/**
	* Adds a method/function in a dictionary package.
	*
	* Note that a package can contain only types or packages, not both. A method/function is
	* created with the @href CATICkeFunctionFactory#CreateFunction service.
	*
	* @param iMethod a method.
	* @param iPackage Name of the package the method is to be added to.
	* @return classic HRESULT
	*/
	virtual HRESULT AddMethodForPackage( const CATBaseUnknown_var& iMethod,
										 const CATUnicodeString& iPackage ) = 0;
	

	/**
	* Indicates that a method was added to the dictionary.
	*
	* @param iMethod Added method.
	* @return classic HRESULT
	*/
	virtual HRESULT AdviseMethodAdded( const CATBaseUnknown_var &iMethod ) = 0;

	/**
	* Indicates that a method was removed from the dictionary.
	*
	* @param iMethod Removed method.
	* @return classic HRESULT
	*/
	virtual HRESULT AdviseMethodRemoved( const CATBaseUnknown_var &iMethod ) = 0;

	/**
	* Returns the Package of a Type (CATIType_var).
	* @param iType type.
	* @param oPackage name of the package returned.
	* @return classic HRESULT
	*/
	virtual HRESULT FindPackageFromType(const CATIType_var& iType, CATUnicodeString& oPackage) = 0;

	

    /** 
	* Returns a type found by its internal name and package name.
	* The difference between FindType and FindTypeSafe is that if the type
	* is not found, FindTypeSafe will load the given package and retry to
	* find the type.
  * The purpose of this method is to be used by applications that require to load their types
	* See also @href CATITypeDictionary#FindType.
	* See also @href CATITypeDictionary#RetrieveType.
	*
	* @param iType Internal name of the type.
	* @param iPackage Internal name of the package.
	* @param oType Type (or NULL_var if not found).
	* @return classic HRESULT
	*/
	virtual HRESULT FindTypeSafe( const CATUnicodeString &iType,
		                          const CATUnicodeString &iPackage, 
							      CATIType_var & oType ) = 0;

  
	/**
	* Returns a type found by its internal name. Returns the type if it was already loaded in the dictionary or not.
  * Will load the package containing the type if necessary
  * This is the prefered method to retrieve a type by its name in a general context
  * Do not use it in the definition of libraries to access the types loaded
	* See also @href CATITypeDictionary#FindTypeSafe.
	* See also @href CATITypeDictionary#FindType.
	*
	* @param iType Internal name of the type.
	* @param oType Type (or NULL_var if not found).
	* @return classic HRESULT
	*/
	virtual HRESULT RetrieveType( const CATUnicodeString& iType,
							  CATIType_var& oType ) = 0;

	/**
	* Returns the sub types list of the given type found in the given package.
	*
	* The returned list can be restricted to the sub types found in the given package or be extended to
	* the sub types also belonging to required packages.
	*
	* @param iPackage Name of the package.
	* @param iFatherType The type from which we'll get the sub types list.
	* @param oListOfSubTypes List of wanted sub types. 
	*		 Notice that if you give a non empty list, 
	*		 it will not be emptied before filling it with the wanted subtypes.
	* @param iIncludePrerequisites Includes (1) or not (0) types of required packages. Default is 1.
	* @return classic HRESULT
	*/
	virtual HRESULT ListSubTypesOfTypeForPackage( const CATUnicodeString& iPackage,
												  const CATIType_var& iFatherType,
												  CATListValCATIType_var& oListOfSubTypes,
												  boolean iIncludePrerequisites = 1 ) = 0;

	/**
	* Returns the sub types list of the given type found in the given packages.
	*
	* The returned list can be restricted to the sub types found in the given packages or be extended to
	* the sub types also belonging to required packages.
	*
	* @param iPackages Name of the package.
	* @param iFatherType The type from which we'll get the sub types list.
	* @param oListOfSubTypes List of wanted sub types. 
	*		 Notice that if you give a non empty list, 
	*		 it will not be emptied before filling it with the wanted subtypes.
	* @param iIncludePrerequisites Includes (1) or not (0) types of required packages. Default is 1.
	* @return classic HRESULT
	*/
	virtual HRESULT ListSubTypesOfTypeForPackages( const CATListOfCATUnicodeString& iPackages,
												   const CATIType_var& iFatherType,
												   CATListValCATIType_var& oListOfSubTypes,
												   boolean iIncludePrerequisites = 1 ) = 0;


	/**
	 * Asks to load a library by its name.
	 * @param iLibraryName C++ class name of the library
	 * @return   CATCke::True if succeeded
	 */
	virtual CATCke::Boolean LoadLibrary (const char *iLibraryName)=0;

	/**
	* Returns the list of the types that can be instanciated.
	*
	* @param olListOfTypes List of types that can be instanciated.
	* @return classic HRESULT
	*/
	virtual HRESULT ListInstanciableTypes (CATListValCATIType_var& olListOfTypes) = 0;

};

CATDeclareHandler(CATITypeDictionary, CATBaseUnknown);

#endif
