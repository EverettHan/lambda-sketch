// COPYRIGHT DASSAULT SYSTEMES 2005

#ifndef CATCkeAttributeValuationFailing_h
#define CATCkeAttributeValuationFailing_h

#include "CATLifSpecs.h"
#include "CATBaseUnknown.h"
#include "CATICkeObject.h"
#include "CATUnicodeString.h"
#include "CATBoolean.h"



//-------------------------------------------------------------------
/**   
 * This class is used to keep an information about errors that have happened during valuation of attribute.
 * Such an object holds the information generated when we tried to valuate an attribute of an object, and the valuation has failed because the size of the value was greater than the max size accepted
 */
//-----------------------------------------------------------------------
class  ExportedByCATLifSpecs CATCkeAttributeValuationFailing
{

public :

	// this class is 
	CATCkeAttributeValuationFailing (const CATICkeObject_var &iObject,const CATUnicodeString &iAttributeName,const CATUnicodeString &iValue,const int iSizeMax);
	CATCkeAttributeValuationFailing (const CATCkeAttributeValuationFailing&);
	~CATCkeAttributeValuationFailing();

	CATCkeAttributeValuationFailing & operator = (const CATCkeAttributeValuationFailing&);

	// Object on which we tried to read the attribute
	CATICkeObject_var GetObject() const;
	// attribute name
	CATUnicodeString GetAttributeName() const;	
	// value with which we tried to valuate
	CATUnicodeString GetAttributeValue() const;
	// Size max
	int GetSizeMax() const;

	CATUnicodeString ErrorMessage () const;

	/** Operator to compare equality. */
	boolean           operator==(const CATCkeAttributeValuationFailing& iInfos ) const { return FALSE;}

	/**  Operator to compare difference. */
	boolean           operator!=(const CATCkeAttributeValuationFailing& iInfos ) const { return TRUE;}


private : 

	CATICkeObject_var _iObject;
	CATUnicodeString _iAttributeName;
	CATUnicodeString _iValue;
	int _iSizeMax;

};
   
#endif
