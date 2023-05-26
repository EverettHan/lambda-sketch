/**
* @level Protected
* @usage U1
*/
/* -*-c++-*- */
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2001  
//-----------------------------------------------------------------------------
// class CATContainerLinkable (extension) :
//	
// October 2001 (slg)
// 
// This class provides binding to CATILinkableObject for CATContainer
// Class used to surcharge CATILinkableObject for containers.
//-----------------------------------------------------------------------------
#ifndef CATContainerLinkable_H_
#define CATContainerLinkable_H_

//#include "CATIALinkableElement.h"
#include "CATExtensionAdapter.h"
#include "CATILinkableObject.h"
#include "CATOmcBase.h"
#include "CATOmcContainer.h"
class CATISymbolicLink;
/**
* Class to provide binding to CATILinkableObject for CATContainer latetype.
* <br><b>Role:</b> Class used to implement CATILinkableObject for containers.
* CATILinkableObject is the interface which allows the retrieval of the document 
* to which the object belongs.
*/
class ExportedByCATOmcBase CATContainerLinkable : public CATExtensionAdapter
{
public:

  CATDeclareClass;

  /**
  * Resets the delegation flag.
  * <br><b>Role</b>: Method to reset the delegation flag.
  * @param iPointedObject
  *  The Pointed Object.
  * @return
  *  <b>Legal values</b>:
  *  <br><tt>S_OK :</tt>   on Success
  *  <br><tt>E_FAIL:</tt>  on failure
  */
  static HRESULT ResetPDMAdapterDelegation ( CATBaseUnknown* iPointedObject);


  CATContainerLinkable();
  virtual ~CATContainerLinkable();

private:
  CATContainerLinkable( const CATContainerLinkable &);
  CATContainerLinkable& operator = (const CATContainerLinkable &);

public:

  /**
  * Retreives the Identifier corresponding to the container.
  * <br><b>Role</b>: Method to get the container identifier. 
  This method implements the CATILinkableObject
  *									interface.
  * @param identifier
  *  The Identifier of the Container.
  */ 	
  virtual
    void GetIdentifier( SEQUENCE(octet) & identifier,boolean & IsAnUuid);
  /**
  * Retreives the Locator Type corresponding to the container.
  * <br><b>Role</b>: Method to get the Locator Type. 
  */ 	
  virtual
    SEQUENCE(octet) GetLocatorType();
  /**
  * Retreives Additional Infos corresponding to the container.
  * <br><b>Role</b>: Method to get Additional Infos. 
  */ 	
  virtual
    SEQUENCE(octet) GetAdditionalInfos();
  /**
  * Retreives NamingContext corresponding to the container.
  * <br><b>Role</b>: Method to get Additional Infos. 
  */ 	
  virtual
    CATBaseUnknown* GetNamingContext(CATIdent interfaceID);
  /**
  * Retreives the document in which the container is located.
  * <br><b>Role</b>: Method to get the corresponding document. 
  */ 	
  virtual 
    CATDocument*        GetDocument ();
  virtual SEQUENCE(octet)     GetLastModificationId () ;
  /**
  *  GetSymbolicLink
  */
  virtual CATISymbolicLink *  GetSymbolicLink();

private:

  CATOmcContainer* AsOmcContainer();

};

#endif
