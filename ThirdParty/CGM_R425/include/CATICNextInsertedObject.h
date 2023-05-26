// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATICNextInsertedObject_h
#define CATICNextInsertedObject_h
////////////////////////////////////////////////////////////////////////////////////
//
//		INTERFACE DEFINING AN OLE CONTENT OBJECT ( EMBEDDED OR LINKED )
//
//		
//		Dec.97	(slg)
///////////////////////////////////////////////////////////////////////////////////////


/**
 * @level Private
 * @usage U3
 */

#include "CATIInsertedObject.h"
#include "CATUnicodeString.h"
//

#include "AC0WINLNK.h"
extern ExportedByAC0WINLNK IID IID_CATICNextInsertedObject;



class ExportedByAC0WINLNK CATICNextInsertedObject : public CATIInsertedObject
{
  CATDeclareInterface;

	public:
 
	// For the case of the embedded document the document is returned
	virtual 
		CATBaseUnknown_var			GetInsertedObject	() = 0;

	// CATObject type
	virtual
		CATUnicodeString			GetObjectType () =0;
	

};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATICNextInsertedObject, CATIInsertedObject ) ;

#endif








