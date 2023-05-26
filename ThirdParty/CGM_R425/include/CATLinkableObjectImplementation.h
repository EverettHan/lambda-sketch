/**
 * @level Private
 * @usage U1
 */
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2004
// Creation: DEM

#ifndef CATLinkableObjectImplementation_h
#define CATLinkableObjectImplementation_h

#include "CATObjectModelerBase.h"

#include "CATLinkableObjectAdapter.h"

class CATIContainer;


/**
* Adapter for CATILinkableObject. Implements useful methods.
*/
class ExportedByCATObjectModelerBase CATLinkableObjectImplementation : public CATLinkableObjectAdapter
{
public:
 /** 
  * Method should be called to register the container when
  * loaded.
  */
	static void RegisterContainer(CATIContainer& Cont);

  /** @nodoc */	
  CATLinkableObjectImplementation();

  /** @nodoc */
  virtual ~CATLinkableObjectImplementation();

protected:

	/** @nodoc */	
	virtual HRESULT GetRelativeIdentifier(SEQUENCE(octet) & identifier) =0;

  /** @nodoc */
	virtual CATIContainer* GetContainer() =0;

private:

  /** @nodoc */
  virtual CATBaseUnknown* GetNamingContext (CATIdent interfaceID);

  /** @nodoc */
  virtual void  GetIdentifier( SEQUENCE(octet) & identifier ,boolean & IsAnUuid);


  /** @nodoc */
  virtual CATDocument * GetDocument () ;

  /** @nodoc */
  virtual SEQUENCE(octet)  GetLastModificationId () ;

  /** @nodoc */
  virtual SEQUENCE(octet)  GetLocatorType();

  /** @nodoc */
  virtual SEQUENCE(octet)  GetAdditionalInfos();

public:
  /** @nodoc */	
  static void RegisterRegisterObject(CATILinkableObject& iLinkableObject);
  
};

#endif

