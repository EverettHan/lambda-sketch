// COPYRIGHT Dassault Systemes 2003
//===================================================================
//
// CATIBrowseTypeDictionary.h
// Define the CATIBrowseTypeDictionary interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Apr 2003  Creation: Code generated by the CAA wizard  soc
//===================================================================
#ifndef CATIBrowseTypeDictionary_H
#define CATIBrowseTypeDictionary_H

#include "CATLifSpecs.h"
#include "CATBaseUnknown.h"

#include "CATBaseUnknown.h"

// OLE iid
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATLifSpecs IID IID_CATIBrowseTypeDictionary;
#else
extern "C" const IID IID_CATIBrowseTypeDictionary ;
#endif

#include "CATIType.h"
#include "CATUnicodeString.h"
#include "CATListValCATIType.h"


//------------------------------------------------------------------

/**
 * Describe the functionality of your interface here
 * <p>
 * Using this prefered syntax will enable mkdoc to document your class.
 */
class ExportedByCATLifSpecs CATIBrowseTypeDictionary: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

	/**
	* Adds a created type in an existing package of the dictionary and mark it as "NOT browsable", that means
	* that the added type will NOT be seen in the Knowledge Expert Browser (by default, each type added in
	* package by CATITypeDictionary::AddTypeForPackage is browsable).
	* Be carefull, if this package name equals "", then the type :
	* - is stored in the dictionary but belongs to no package
	* - will be browsable
	* A type created but not added to the dictionary cannot be used.
	*
	* @param iType Type to be added.
	* @param iPackage Name of the package the type has to be added to.
	* @return : E_FAIL if the type is not added or if the type is added without belonging 
	* to a package (that means that it will be browsable).
	*/
	virtual HRESULT AddUnbrowsableTypeForPackage( const CATIType_var& iType,
												const CATUnicodeString& iPackage) = 0;

	/**
	* Set the given type as not browsable. Note that the type must have been created
	* and added to a package of the dictionary in order for this method to successfull.
	* @param iType Internal name of the type
	* @param iPackage Name of the package the type was added to.
	* @return E_FAIL if the type can't be found in the given package.
	*/
	virtual HRESULT SetTypeAsNotBrowsableForPackage( const CATUnicodeString& iType,
													 const CATUnicodeString& iPackage) = 0;

	

	/**
	* Returns the list of all the browsable types contained in a package (unbrowsable types
	* are not returned so that you may get less types than the method
	* CATITypeDictionary::ListTypesForPackage() would give.
	*
	* The returned list can be restricted to the types in the package or be extended to
	* the types also belonging to required packages.
	*
	* @param iPackage Name of the package.
	* @param olListOfTypes List of wanted types.
	* @param iIncludePrerequisites Includes (1) or not (0) types of required packages. Default is 1.
	*/
	virtual HRESULT ListBrowsableTypesForPackage( const CATUnicodeString& iPackage,
												CATListValCATIType_var& olListOfTypes,
												boolean iIncludePrerequisites = 1 ) = 0;

	/**
	* Returns the lists of the browsable types contained in several packages.
	*
	* @param iPackages List of package names.
	* @param olListOfTypes List of found types.
	* @param iIncludePrerequisites Includes (1) or not (0) types of required packages. Default is 1.
	*/
	virtual HRESULT ListBrowsableTypesForPackages( const CATListOfCATUnicodeString& iPackages,
												CATListValCATIType_var& olListOfTypes,
												boolean iIncludePrerequisites = 1 ) = 0;



  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};

CATDeclareHandler(CATIBrowseTypeDictionary, CATBaseUnknown);

//------------------------------------------------------------------

#endif
