/**
 * @level Private
 * @usage U1
 */
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2004
// Creation: DEM

#ifndef CATLinkableObjectAdapter_h
#define CATLinkableObjectAdapter_h

#include "CATObjectModelerBase.h"

#include "CATILinkableObject.h"


/**
* Adapter for CATILinkableObject. Implements useful methods.
*/
class ExportedByCATObjectModelerBase CATLinkableObjectAdapter : public CATILinkableObject
{
public:

  //Methods you will have to implement		
  virtual CATBaseUnknown* GetNamingContext (CATIdent interfaceID)=0 ;

  /** @nodoc */
  virtual void  GetIdentifier( SEQUENCE(octet) & identifier ,boolean & IsAnUuid) = 0;

  /** 
  * Returns associated document owning object.
  * <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the returned value.
  */
  /** @nodoc */
  virtual CATDocument * GetDocument ()=0 ;

  /** @nodoc */
  virtual SEQUENCE(octet)  GetLastModificationId ()=0 ;

  /** @nodoc */
  virtual SEQUENCE(octet)  GetLocatorType() = 0;

  /** @nodoc */
  virtual SEQUENCE(octet)  GetAdditionalInfos() = 0;

  // end of methods you will have to implement

  /** @nodoc */	
  CATLinkableObjectAdapter(){};

  /** @nodoc */
  virtual ~CATLinkableObjectAdapter(){};

  /** @nodoc */
  char* GetName (CATNameKind kind);
  
  /** @nodoc */
  SEQUENCE(octet) GetName_B (CATNameKind kind);
  
  /** @nodoc */
  void AddInverseLink    ( CATBaseUnknown_var inverse_handler );

  /** @nodoc */
  void RemoveInverseLink ( CATBaseUnknown_var inverse_handler );

  /** @nodoc */
  CATLISTV( CATBaseUnknown_var ) GetInverseLinks();

  /** @nodoc */
  CATISymbolicLink*   GetSymbolicLink();

  /** @nodoc */
  void  ListSupportedAreasIdentifier( CATListOfCATUnicodeString* listofareasidentifier
					     ,boolean& IsAStaticList);
  
  /** @nodoc */
  boolean IsAFilledArea(const CATUnicodeString& area_identifier);
  
  /** @nodoc */
  void  FillArea( const CATUnicodeString& area_identifier
			 ,SEQUENCE(octet)         pointed_name
			 ,boolean                 updateIfAlreadyExist);

  /** @nodoc */
  SEQUENCE(octet)  GetStoredName(const CATUnicodeString& area_identifier);
  
  /** @nodoc */
  CATLISTV(CATBaseUnknown_var) ExternalBindPointedObjects( const CATIdent interfaceId
								      ,CATIBindParameters* params);
  

};

#endif

