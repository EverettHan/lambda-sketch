// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATIInsertedObject_h
#define CATIInsertedObject_h
////////////////////////////////////////////////////////////////////////////////////
//
//		INTERFACE DEFINING A CONTENT OBJECT ( CNEXT EMBED OR OLE EMBED/LINK )
//
//		
//		March.98	(slg)
///////////////////////////////////////////////////////////////////////////////////////


/**
 * @level Protected 
 * @usage U3
 */

#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATInsertDeclarations.h"
//

#include "AC0WINLNK.h"
extern ExportedByAC0WINLNK IID IID_CATIInsertedObject ;

#ifdef _WINDOWS_SOURCE
#include <Ole2.h>
#else
class IOleObject;
#endif


class ExportedByAC0WINLNK CATIInsertedObject : public CATBaseUnknown
{
  CATDeclareInterface;

	public:
 
	virtual
		HRESULT					LaunchServerApplication	() = 0;

	virtual
		HRESULT					CloseServerApplication	() = 0;


        // the different types are defined in CATInsertDeclarations
	// To Determine The Type Of Content Object 
	virtual
		CATContentObjectType		GetContentObjectType	( ) = 0;
  
    virtual
	  void                       SaveObject () = 0;

	// Notifications on Inserted Object Data, View modifications and Save Event	
	virtual
		void					ActivateNotifications() = 0;

	virtual
		void					DesActivateNotifications() = 0;

	virtual
		void					Update	( boolean SaveContentObject = FALSE) = 0;


};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIInsertedObject, CATBaseUnknown ) ;

#endif








