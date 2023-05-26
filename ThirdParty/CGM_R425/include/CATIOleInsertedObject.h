// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATIOleInsertedObject_h
#define CATIOleInsertedObject_h
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
#include "CATInsertDeclarations.h"
#include "CATUnicodeString.h"
//
#ifdef _WINDOWS_SOURCE
#include <Ole2.h>
#else
class IOleObject;
#endif



#include "AC0WINLNK.h"
extern ExportedByAC0WINLNK IID IID_CATIOleInsertedObject ;




class ExportedByAC0WINLNK CATIOleInsertedObject : public CATIInsertedObject
{
  CATDeclareInterface;

	public:
 
	// To Get The Ole Handler Corresponding To The Inserted Object
	virtual
	  IOleObject*	GetOLEInsertedObject	() = 0;

	virtual
	  CATUnicodeString GetServerCLSID () =0;
	

	// For Linked Object Only ( For Embedded "" is returned )  (available on Windows only !)
	virtual
	  CATUnicodeString GetOleLinkedObjectPath	( ) = 0;

	// en attendant la livraison de ple, on garde cette methode
	virtual
	  HRESULT CreateBitmapInFile( const CATUnicodeString& iFileName, int Hatched = 0, int IntAspect = 1) = 0;

	// Create Inserted Representation Into A Bitmap In File ( 24 bits bmp ) (On Windows only!)
	virtual
	  HRESULT CreateBitmap ( unsigned char *& Buffer, int& Length, int Hatched = 0, int IntAspect = 1) = 0;

};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIOleInsertedObject, CATIInsertedObject ) ;

#endif








