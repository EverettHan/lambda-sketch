/* -*-c++-*- */
#ifndef CATComponentAdaptor_H
#define CATComponentAdaptor_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2004
/**
* Root Adapater for Database Object Management in Client Session
*/
/* 
* @COPYRIGHT DASSAULT SYSTEMES 2004
* ----------------------------------------------------------------------------------------------------------------------
*   Origin              : Local running (inside wintop) of remote persistency entity 
*                            associative kernel change/data set of ... actors ...
*                            made as simple as possible to be affordable for enhanced infrastructure integration
*   Software's Category : Physical Layer (Middleware services) dedicated to client side
*                            (in a kind of software classification similar to the layered OSI Network 
*                             upper (logical) Layer is mainly about two main axis  (
*                                  Modeler (domain) specialisation (for Data and Attributes ...)
*                                  Upper Levering Operand Integration exchange (QEOPS, 
*   Premilinary         : Do not forget to contact your Database Administrators or any other representative
*                            (Authoring definition) for more convenient support 
*                          (Just to be sure that appropriate schema (Table for Data , or Services) are supported 
*                              when reference persistency occured when dealing with local work realized  )
*   Specification       : Simple genuine (re-usable) services about 
*                            - associativity between local insulated implementation and shared remote repository
*                            - synthetic change set (persistency intents)
*   Limitations         : No attributes vocabulary provided to let this current functional component software 
*                              be as comprehensible in specifications
*                         Status is slaved to Modelers deployement and Behaviors
*                             for more detailled specification (UML sequence diagram, statechart, ..)  
*                             consult specialized specifications database relative to upper Logical Software layer 
*                             it means Product Structure Legacy, PLM Client Core, Representation Model
*   Favorites entry-point for developpers :
*                         CATPLMRepositoryName : Repository classification 
*                         CATProxySpace   : Instance of a domain resolution                    
*                         CATComponentId  : Handle on primary associativity between local and remote entity           
* ------------------ ----------------------------------------------------------------------------------------------------
*/
/**
 * @level Protected
 * @usage U5   
 */

/**
*  Management of Database Object in Client Session through System identification.
*                 
*  <br>Implementation Recommandations :  
*    1) CodeExtension on Object is sufficient
*    2) TIEchain (Because multi-implemented)
*/

#include "ExportedByCATPLMTos.h"
#include "CATIComponent.h"
#include "CATPLMID_Any.h"
#include "CATLISTV_CATComponentId.h"
#include "CATComponentId.h"
#include "CATBoolean.h"
#include "CATOmxCollectionType.h"

class CATPLMTypeId;
class CATIAdpPLMIdentificator;
class CATIAdpType;
class CATOmxKeyValueBlock;
class CATOmxAny;

/**
*  Management of Database Object in Client Session by its System identification
*/
class ExportedByCATPLMTos CATComponentAdaptor  : public CATIComponent
{
public:

  /**
  * @see CATIComponent#IsComponent
  */
  virtual HRESULT IsComponent() const;

  /**
  * @see CATIComponent#GetPLMType
  */
  virtual HRESULT GetPLMType(CATPLMTypeId & oTypeReference) const;

  /**
  * @see CATIComponent#HasPLMOwner
  */
  virtual HRESULT HasPLMOwner(CATComponentId &oPLMAggregatingOwner);

  /**
  * @see CATIComponent#IsInstanceOf
  */
  virtual HRESULT IsInstanceOf(CATComponentId &oIsInstanceOf);

  /**
  * @see CATIComponent#IsStrongRelationalMasterInTOS
  */
  virtual CATBoolean IsStrongRelationalMasterInTOS() const {return FALSE;}

  /**
  * @see CATIComponent#IsPersistentUnitBoundToComponentModel
  */
  virtual CATBoolean IsPersistentUnitBoundToComponentModel() const;

  /**
  * @see CATIComponent#GetPersistentUnitBindingMode
  */
  virtual HRESULT GetPersistentUnitBindingMode(CATPLMPersistentUnitBindingMode & oBindingMode) const;

  /**
  * @see CATIComponent#HasAlias
  */
  virtual HRESULT HasAlias(CATUnicodeString &oAlias);

  /**
  * @see CATIComponent#HasFunctionalName
  */
  virtual HRESULT HasFunctionalName( CATUnicodeString &oFunctionalName );

  /**
  * @see CATIComponent#IsOnceInstantiable
  */
  virtual HRESULT IsOnceInstantiable();

  /**
  * @see CATIComponent#GetPublicAttributes
  */
  virtual HRESULT GetPublicAttributes(CATListOfCATUnicodeString  &  ioAttributeNameList,
    CATListOfCATUnicodeString  &  oAttributeValueList);

  /**
  * @see CATIComponent#ListExtensions
  */
  virtual HRESULT ListExtensions( CATPLMTypeIds & oExtensions );

  /**
  * @see CATIComponent#CheckAttributesMask
  */
  virtual HRESULT CheckAttributesMask( const CATPLMTypeId & iExtensionType, const CATPLMAttributesFilter & iFilter,
    CATLISTV(CATString) & oAttributeIds );

  /**
  * @see CATIComponent#GetAttributeValue
  */
  virtual HRESULT GetAttributeValue( const CATPLMTypeId & iExtensionType, const CATString & iAttributeId, 
                                     CATOmxCollectionType & oAttrValueCType, CATOmxAny & oAttributeValue );

  /**
  * @see CATIComponent#GetAttributeBlock
  */
  virtual HRESULT GetAttributeBlock( const CATPLMTypeId & iExtensionType, CATOmxKeyValueBlock &oAttrBlock );

  /**
  * @see CATIComponent#GetAttributeBlockForExport
  */
  virtual HRESULT GetAttributeBlockForExport( const CATPLMTypeId & iExtensionType, CATOmxKeyValueBlock &oAttrBlock );

  /**
  * @see CATIPLMComponent#GetAdpID
  */
  virtual HRESULT GetAdpID(CATIAdpPLMIdentificator *& oAdpID);

  /**
  * @see CATIPLMComponent#GetAdpType
  */
  virtual HRESULT GetAdpType(CATIAdpType *& oAdpType);

  /**
  * Deprecated
  */
  virtual HRESULT HasMasterStamp(CATLONG32 & oStamp) const ;

  /**
  * @see CATIComponent#GetMasterStamp
  */
  virtual HRESULT GetMasterStamp(CATOmxAny & oStamp) const ;

  /**
  * @see CATIComponent#TouchMasterStamp
  */
  virtual HRESULT TouchMasterStamp (CATBoolean & oMasterStampIsModified);

protected: 


  ~CATComponentAdaptor();
  CATComponentAdaptor();


private :

  CATComponentAdaptor(const CATComponentAdaptor &iCopy);
  CATComponentAdaptor& operator=(const CATComponentAdaptor &iCopy);
};


#endif
