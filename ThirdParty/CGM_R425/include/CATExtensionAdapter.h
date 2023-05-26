/* -*-c++-*- */
#ifndef CAT_EXTENSION_ADAPTER_H
#define CAT_EXTENSION_ADAPTER_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
  * @level Protected
  * @usage U2
  */

// --------------------------------------------------------------------------
//                         Export for Window NT
// --------------------------------------------------------------------------

#include "AD0XXBAS.h"

// --------------------------------------------------------------------------
//                            For test only
// --------------------------------------------------------------------------

#include <CATIOStream.h>

// --------------------------------------------------------------------------
//                         Set Interface Mode
// --------------------------------------------------------------------------

#include "CATBaseUnknown.h"
#include "CATInterfaceDeclarations.h"
#include "CATInterfaceObject.h"       // to still have the old way and definitions

// --------------------------------------------------------------------------
//                  Declarations for Events management 
// --------------------------------------------------------------------------

#include "CATInterfaceEvents.h"

// --------------------------------------------------------------------------
//                  Declarations for Inverse Links
// --------------------------------------------------------------------------

#include "CATLISTV_CATBaseUnknown.h"

// --------------------------------------------------------------------------
//                       Preliminary declarations
// --------------------------------------------------------------------------

class CATImplementationAdapter ;


// Includes pour migration Liens Symboliques -> detruits en fin de migration
#include "CATILinkableObject.h"

//===================================================================================
//              CATExtensionAdapter :  D E C L A R A T I O N S
//===================================================================================

/** Extension Adapter Class. */

class ExportedByAD0XXBAS CATExtensionAdapter : public CATBaseUnknown
{
  public:
    CATDeclareClass;
  /** @nodoc */
    CATExtensionAdapter() ;
    virtual ~CATExtensionAdapter() ;

	/** @nodoc */
    virtual CATCallback         AddSubscription( CATInterfaceEvents  *eventManager,
				                 CATCallbackEvent     event,
				                 CATSubscriberMethod  method, 
				                 char                *interfaceID,
				                 CATSubscriberData    data = NULL  ) ;
	/** @nodoc */
    virtual void                RemoveSubscriptionsOn( CATInterfaceEvents *eventManager,
				                       CATCallbackEvent    event,
				                       char               *interfaceID,
				                       CATSubscriberData   data  ) ; 
	/** @nodoc */
    virtual void                RemoveInterfaceSubscriptions( CATInterfaceEvents *eventManager , 
                                                              char               *interfaceID ) ;
 	/** @nodoc */
   virtual CATCallbackManager *GetCallbackManager() ;
 
	/** @nodoc */
    virtual void                AddInverseLink    ( CATBaseUnknown_var inverse_handler ) ;
	/** @nodoc */
    virtual void                RemoveInverseLink ( CATBaseUnknown_var inverse_handler ) ;
	/** @nodoc */
    virtual CATLISTV( CATBaseUnknown_var ) GetInverseLinks() ;


    // -> Migration Liens symboliques : les fonctions suivantes seront detruites en
    // fin de migration

	/** @nodoc */
    virtual char* GetName (CATNameKind kind);
	/** @nodoc */
    virtual SEQUENCE(octet) GetName_B (CATNameKind kind);

	/** @nodoc */
    virtual CATISymbolicLink*   GetSymbolicLink();
	/** @nodoc */
    virtual void                GetIdentifier( SEQUENCE(octet) & identifier
					      ,boolean         & IsAnUuid);
	/** @nodoc */
    virtual CATDocument    * GetDocument ();
	/** @nodoc */
    virtual SEQUENCE(octet)  GetLocatorType();
	/** @nodoc */
    virtual SEQUENCE(octet)  GetAdditionalInfos();


	/** @nodoc */
    virtual void  ListSupportedAreasIdentifier( CATListOfCATUnicodeString* listofareasidentifier
					       ,boolean& IsAStaticList);
	/** @nodoc */
    virtual boolean IsAFilledArea(const CATUnicodeString& area_identifier);
	/** @nodoc */
    virtual void  FillArea( const CATUnicodeString& area_identifier
			   ,SEQUENCE(octet)         pointed_name
			   ,boolean                 updateIfAlreadyExist);
	/** @nodoc */
    virtual SEQUENCE(octet)  GetStoredName(const CATUnicodeString& area_identifier);
	/** @nodoc */
    virtual CATLISTV(CATBaseUnknown_var) ExternalBindPointedObjects( const CATIdent interfaceId
									,CATIBindParameters* params);
  
    
  protected:
    //
    // --> Copy constructor, Assignment operator
    //
    /** @nodoc */
	CATExtensionAdapter( const CATExtensionAdapter& ) ;
   	/** @nodoc */
	CATExtensionAdapter& operator=( const CATExtensionAdapter& ) ;
};

#endif
