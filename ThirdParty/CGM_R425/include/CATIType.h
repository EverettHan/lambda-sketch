#ifndef CATIType_h
#define CATIType_h

// COPYRIGHT DASSAULT SYSTEMES 2000

/** 
* @CAA2Level L1
* @CAA2Usage U3
*/

// inherited class 
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"

// load module
#include "CATLifSpecs.h"

// OLE IID
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATLifSpecs IID_CATIType;
#else
extern "C" const IID IID_CATIType;
#endif


class CATIType_var;
class CATListValCATIType_var;

/**
 * Interface dedicated to describing the Knowledge type of an object that can be manipulated in Knowledgeware.
 *
 * <b>Role</b>: This Knowledge type is shown to the user but does not necessarily 
 * reflect the internal structure of an object : as such, it is
 * an <b>exposed</b> type.<br> for the Knowledge.
 * A Knowledge type is defined by an internal name and a NLS name that is shown to 
 * the user.<br>
 * A Knowledge type is created by applications through CATITypeDictionary services.
 * This interface is multi implemented.
 * Most of the time a Knowledge type also implements CATIAttributesDescription as soon as it holds attributes.
 *
 * @see CATICkeObject, CATITypeDictionary, CATIAttributesDescription, CATAttributeInfos.
 */
 
class ExportedByCATLifSpecs CATIType : public CATBaseUnknown
{

public :
	/**
	* Returns the name of the Knowledge type (internal identifier).
	*
	* This name is the one used to find a type by its name in CATITypeDictionary services.
	* @return internal name of the type.
	*/
	virtual CATUnicodeString  Name    () const =0;

	/**
	* Returns the NLS name of the Knowledge type.
	*
	* @return NLS name of the type.
	*/
	virtual CATUnicodeString UserName () const = 0;

	/**
	* Tests if this Knowledge type is a subtype of (derives from) the given one.
	*
	* @param iType type to compared to.
	* @return True if this type is a subtype of the other, else False.
	*/
	virtual boolean IsaSortOf (const CATIType_var &iType) const = 0;

	/**
	* Returns the supertype (the type this type derives).
	*
	* An AddRef is done.
	* @return  [CATBaseUnknown#Release] the supertype.
	*/
	virtual CATIType* SuperType() const = 0;

	/**
	* Scans the direct sub types.
	*
	* @param olListOfTypes list to be filled with sub types.
	* @return S_OK if scan has succeeded;
	*/
    virtual HRESULT ScanSubTypes(CATListValCATIType_var& olListOfTypes) const =0;


private:
  CATDeclareInterface;

}; 

CATDeclareHandler(CATIType, CATBaseUnknown);

#endif
