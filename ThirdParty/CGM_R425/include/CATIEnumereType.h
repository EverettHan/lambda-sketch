#ifndef CATIEnumereType_h
#define CATIEnumereType_h


// COPYRIGHT DASSAULT SYSTEMES 1998

#include "CATLifSpecs.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"

// OLE iid

#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATLifSpecs IID_CATIEnumereType;
#else
extern "C" const IID IID_CATIEnumereType;
#endif


/**   
 * Interface dedicated to enumerated types management.
 *
 * <b>Role</b> : An enum type is a @href CATIType type that allows only a list of values.
 * These values are seen as strings.
 *
 * @see CATIType
 */

class ExportedByCATLifSpecs CATIEnumereType : public CATBaseUnknown
{

public :
	/**
	* Returns the list of values (with their internal string representations).
	*
	* @param olListValueNames List of strings.
	*/
	virtual HRESULT GetValues (CATListOfCATUnicodeString& olListValueNames) const = 0;

	/**
	* Returns the list of values (with their NLS string representations).
	*
	* @param olListValueNLSNames List of strings.
	*/
	virtual HRESULT GetNLSValues (CATListOfCATUnicodeString& olListValueNLSNames) const = 0;

	/**
	* Sets the list of values (with their internal strings).
	*
	* @param ilListOfValues List of strings.
	*/
	virtual HRESULT SetValues (const CATListOfCATUnicodeString &ilListOfValues)  = 0;

	/**
	* Sets the name of the CATNls file to be used to convert internal names into NLS ones.
	*
	* @param iCatalogName Catalog name.
	*/
	virtual HRESULT SetNLSCatalog (const CATUnicodeString& iCatalogName) = 0;

	/**
	* Returns the index of an internal possible value.
	*
	* It returns E_FAIL if the string is unknown.
	*
	* @param iInternalName Internal name of the list of possible values.
	* @param oIndex Index of the string.
	*/
	virtual HRESULT IndexOf(const CATUnicodeString& iInternalName,
						    int& oIndex) = 0;

	/**
	* Returns the index of an internal possible value.
	*
	* It returns E_FAIL if the string is unknown.
	*
	* @param iNLSName NLS name of the list of possible values.
	* @param oIndex Index of the string.
	*/
	virtual HRESULT IndexOfNLS(const CATUnicodeString& iNLSName,
							   int& oIndex) = 0;

private:
  CATDeclareInterface;

}; 

CATDeclareHandler(CATIEnumereType, CATBaseUnknown);

#endif
