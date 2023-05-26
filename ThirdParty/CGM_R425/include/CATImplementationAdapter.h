/* -*-c++-*- */
#ifndef CAT_IMPLEMENTATION_ADAPTER_H
#define CAT_IMPLEMENTATION_ADAPTER_H

// COPYRIGHT DASSAULT SYSTEMES 1999 

  
/**
  * @level Protected
  * @usage U1
 */


// --------------------------------------------------------------------------
//                         Export for Window NT
// --------------------------------------------------------------------------

#include  "CATOMY.h"


// --------------------------------------------------------------------------
//                            For test only
// --------------------------------------------------------------------------

#include <CATIOStream.h>


// --------------------------------------------------------------------------
//                         Set Interface Mode
// --------------------------------------------------------------------------

#include "CATInterfaceDeclarations.h"
#include "CATEventSubscriber.h"
#include "CATLISTV_CATBaseUnknown.h"
#include "CATInterfaceObject.h"      //to still have the old way and definitions

// --------------------------------------------------------------------------
//                       Preliminary declarations
// --------------------------------------------------------------------------

// Includes pour migration Liens Symboliques -> detruits en fin de migration
#include "CATILinkableObject.h"

//===================================================================================
//              CATAImplementationAdapter :  D E C L A R A T I O N S
//===================================================================================

/**  
Implementation Adapter Class. */

class ExportedByCATOMY CATImplementationAdapter : public CATEventSubscriber
{
  public:
    //
    // --> Constructor / Destructor
    //
	/** @nodoc */
    CATImplementationAdapter() ;
    virtual ~CATImplementationAdapter() ;

    //
    // --> Macro needed for Interface implementations
    //
    CATDeclareClass ;
  
    //
    // --> Inverse Links Default Behaviour : Nothing
    //
    /** @nodoc */
    virtual void AddInverseLink    ( CATBaseUnknown_var inverse_handler ) ;
    /** @nodoc */
    virtual void RemoveInverseLink ( CATBaseUnknown_var inverse_handler ) ;
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
    // --> Copy constructor, Assignmentoperator
    //
    /** @nodoc */
    CATImplementationAdapter( const CATImplementationAdapter& ) ;
    /** @nodoc */
    CATImplementationAdapter& operator=( const CATImplementationAdapter& ) ;

 
};
   

#endif
