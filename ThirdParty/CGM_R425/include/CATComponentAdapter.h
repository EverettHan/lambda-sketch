 /* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2004
#ifndef CATComponentAdapter_H_
#define CATComponentAdapter_H_
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2004
#include "CATComponentAdaptor.h"
#include "CATObjectModelerBase.h"

/**
 * @level Private
 * @usage U2       
 */


/**
 * Usage notes:
 *
 *   New interface: Interface in order to manage specific plm   information on CATDocument
 * <p>
 * Using this prefered syntax will enable mkdoc to document your class.
 */
class CATIAdpPLMIdentificator;
class CATIAdpType;
class ExportedByCATObjectModelerBase CATComponentAdapter  : public CATComponentAdaptor
{
 public:

   /**
  * @see CATPLMIdentification.CATIComponent 
  */
 CATComponentAdapter();
  /**
  * @see CATPLMIdentification.CATIComponent 
  */
  virtual ~CATComponentAdapter();
  
 /**
  * @see CATPLMIdentification.CATIComponent#HasAlias
  */
  virtual HRESULT HasAlias(CATUnicodeString &oAlias);

  /**
   * @see CATPLMIdentification.CATIComponent#HasFunctionalName
   */
  virtual HRESULT HasFunctionalName( CATUnicodeString &oFunctionalName );

    /**
   * @see CATPLMIdentification.CATIComponent#IsOnceInstantiable
   */
  virtual HRESULT IsOnceInstantiable();

    /**
   * @see CATPLMIdentification.CATIComponent#GetPublicAttributes
   */
  virtual HRESULT GetPublicAttributes(CATListOfCATUnicodeString  &  ioAttributeNameList,
                                      CATListOfCATUnicodeString  &  oAttributeValueList);
 
};
 
#endif




