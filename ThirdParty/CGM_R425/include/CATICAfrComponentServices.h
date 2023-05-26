
#ifndef CATICAfrComponentServices_H
#define CATICAfrComponentServices_H

// COPYRIGHT DASSAULT SYSTEMES 2011/09/27

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"
#include "CATErrorDef.h"
#include "CATUnicodeString.h"
#include "CATString.h"

class CATICAfrComponentController;
class CATSYPEventHandler;
class CATISYPCollection;
class CATICAfrComponent;

extern ExportedByCATAfrItf  IID IID_CATICAfrComponentServices ;
//-----------------------------------------------------------------------------
/**
* Interface managed C-AfrComponent.
**/
class ExportedByCATAfrItf CATICAfrComponentServices: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

    /**
    * CATCAfrInstantiateComponent
    */
    virtual HRESULT CATCAfrInstantiateComponent( const CATUnicodeString& iXMLFile, 
                                                 const CATUnicodeString& iTemplateName, 
                                                 const CATString& iComponentInstanceName, 
                                                 CATICAfrComponent** opiAfrComponent, 
                                                 const CATBoolean& ibAutomaticNaming = FALSE ) = 0;

    virtual HRESULT CATCAfrInstantiateComponent( const CATString& iComponentType, 
                                                 const CATString& iComponentInstanceName, 
                                                 CATICAfrComponent** opiAfrComponent ) = 0;

    /**
    * CATCAfrDeleteComponent
    */
    virtual HRESULT CATCAfrDeleteComponent( const CATString& iComponentInstanceName ) = 0;

    /**
    * CATCAfrDeleteComponent
    */
    virtual HRESULT CATCAfrDeleteComponent( CATICAfrComponent* ipiAfrComponent ) = 0;

    /**
    * CATCAfrDeleteComponent
    */
    virtual HRESULT CATCAfrGetComponent( const CATString& iComponentInstanceName, 
                                         CATICAfrComponent** opiAfrComponent ) = 0;
    /**
    * CATCAfrComponentChange
    */
    virtual HRESULT CATCAfrComponentChange( const CATString& iComponentInstanceName, 
      const CATUnicodeString & iValue ) = 0;

    /**
    * CATCAfrRegisterController
    */
    virtual HRESULT CATCAfrRegisterController( const CATString& iComponentInstanceName, 
      CATICAfrComponentController* ipiController ) = 0;
    /**
    * AddComponentViewDeletedCB
    */
    virtual  HRESULT AddComponentViewDeletedCB (const CATString& iComponentInstanceName,CATSYPEventHandler * i_pHandler) = 0;

    /**
    * RegisterComponent
    */
    virtual HRESULT RegisterComponent( CATBaseUnknown_var ispAfrComponent, 
                                       const CATString& iComponentInstanceName ) = 0;

    virtual HRESULT IncludeElementsByDeclarative( CATICAfrComponent* ipiAfrComponent,  
                                                 const CATUnicodeString & iTemplateName, 
                                                 const CATUnicodeString & iXmlFile) = 0;

    /**
    * AppendIfIncludeOrGroup
    */
    virtual HRESULT AppendIfIncludeOrGroup(const CATBaseUnknown_var  & i_spObject,  CATISYPCollection *ipCollection) = 0;
};
#endif
