/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2006
#ifndef CATAdpResultVersion_H
#define CATAdpResultVersion_H

/**
 * @level Protected
 * @usage U3
 */

#include "CATPLMIntegrationAccess.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"
class CATIAdpPLMIdentificator;
class CATIPLMError;
class CATListPtrCATIAdpPLMIdentificator;

/**
 * Class giving access to a set of informations resulting from a query.
 *
 * <br><b>Role</b>: provide a set of informations about a component resulting from a query in a database.
 */
class ExportedByCATPLMIntegrationAccess CATAdpResultVersion
{
public:

/** 
 * Gets the source identificator.
 *
 * @param oSource [out, CATBaseUnknown#Release]
 *   The retrieved component identificator.
 *
 * @return
 *   <code>S_OK</code> if the related identifier could be retrieved.
 *   <code>E_FAIL</code> otherwise.
 *
 */ virtual HRESULT GetSource(CATIAdpPLMIdentificator *& oSource ) = 0;

/** 
 * Gets the associated elements returned by the query.
 *
 * @param oIdentificators [out, #delete]
 *   The list of retrieved component identificator. 
 *   Each element should be released after use.
 *
 * @return
 *   <code>S_OK</code> if the list can be retrieved.
 *   <code>E_FAIL</code> otherwise (check the report).
 *
 */  virtual HRESULT GetIdentifiers( CATListPtrCATIAdpPLMIdentificator *& oIdentificators ) = 0;

/**
 * Gets the report associated to the input.
 *
 * @param oReport[out, CATBaseUnknown#Release],
 * 	The report.
 *
 * @return
 *   <code>S_OK</code> There is an error associated to this input.
 *   <code>S_FALSE</code> The is no error for this input (oReport is NULL).
 *
 */
  virtual HRESULT GetReport (CATIPLMError **  oReport ) = 0;

 /**
  * If I want the destructor of my subclass to have a chance to be called....
  */
  virtual ~CATAdpResultVersion() {}
};
#endif
