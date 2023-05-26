/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2006
#ifndef CATAdpQueryResult_H
#define CATAdpQueryResult_H

/**
 * @CAA2Level L1
 * @CAA2Usage U1  
 */

#include "CATPLMIntegrationAccess.h"
#include "CATErrorDef.h"
class CATIAdpPLMIdentificator;
class CATAdpAttributeSet;

/**
 * Class giving access to a set of informations resulting from a query.
 *
 * <br><b>Role</b>: provide a set of informations about a component resulting from a query in a database.
 */
class ExportedByCATPLMIntegrationAccess CATAdpQueryResult
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
  virtual HRESULT GetAttributeSet( CATAdpAttributeSet & oAttSet ) = 0;
 /**
  * Destructor.
  */
  virtual ~CATAdpQueryResult(void) {}
};
#endif
