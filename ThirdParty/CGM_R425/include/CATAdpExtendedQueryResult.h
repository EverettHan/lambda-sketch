/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2010
/**
 * @level Protected
 * @usage U1  
 */
#ifndef CATAdpExtendedQueryResult_H
#define CATAdpExtendedQueryResult_H

#include "CATPLMIntegrationAccess.h"
#include "CATErrorDef.h"
class CATIAdpExtType;
class CATPLMTypeH;
class CATIAdpPLMIdentificator;
class CATAdpQueryAttributeSet;

/**
 * Class giving access to a set of informations resulting from a query.
 *
 * <br><b>Role</b>: provide a set of informations about a component resulting from a query in a database.
 */
class ExportedByCATPLMIntegrationAccess CATAdpExtendedQueryResult
{
public:

/** 
 * Gets the component identificator.
 *
 * <br><b>Role</b>: Gets the @href CATIAdpPLMIdentificator enabling to identify a component.
 *
 * @param oIdentifier [out, CATBaseUnknown#Release]
 *   The retrieved component identificator.
 *
 * @return
 *   <code>S_OK</code> if the related identifier could be retrieved.
 *   <code>E_FAIL</code> otherwise.
 *
 */
  virtual HRESULT GetIdentifier( CATIAdpPLMIdentificator *& oIdentifier ) = 0;

/**
 * Gets an attribute set.
 *
 * <br><b>Role</b>: Gets an attribute set corresponding to the attributes retrieved in a database for a component through a query.
 * The attributes retrieved depend of the context of use.
 *
 * @param oAttSet[out],
 * 	The component attribute set.
 *
 * @return
 *   <code>S_OK</code> if the attibute set could be retrieved.
 *   <code>E_FAIL</code> otherwise.
 *
 */
  virtual HRESULT GetAttributeSet( CATAdpQueryAttributeSet & oAttSet ) = 0;

 /**
 * @deprecated V6R2013
 * @nodoc
 */
  virtual HRESULT GetExtensionAttributeSet( CATIAdpExtType *iType, CATAdpQueryAttributeSet & oAttSet ) = 0;

  /**
 * Gets an attribute set.
 *
 * <br><b>Role</b>: Gets an attribute set from an extension corresponding to the attributes retrieved in a database for a component through a query.
 * The attributes retrieved depend of the context of use.
 *
 * @param iType[in],
 * 	The extension type.
 * @param oAttSet[out],
 * 	The component attribute set.
 *
 * @return
 *   <code>S_OK</code> if the attibute set could be retrieved.
 *   <code>E_FAIL</code> otherwise.
 *
 */
  virtual HRESULT GetExtensionAttributeSet(const CATPLMTypeH & iType, CATAdpQueryAttributeSet & oAttSet ) = 0;
 /**
  * Destructor.
  */
  virtual ~CATAdpExtendedQueryResult(void) {}
};
#endif
