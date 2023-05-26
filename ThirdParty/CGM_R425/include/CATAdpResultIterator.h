/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2007
#ifndef CATAdpResultIterator_H
#define CATAdpResultIterator_H

/**
 * @level Protected
 * @usage U3
 */

#include "CATPLMIntegrationAccess.h"
#include "CATErrorDef.h"
#include "CATCollec.h"
class CATIAdpPLMIdentificator;
class CATLISTP(CATError);

/**
 * Class giving access to a set of errors resulting from an operation on the server.
 *
 * <br><b>Role</b>: provide a set of errors which occured during an operation performed on a component on the server.
 */
class ExportedByCATPLMIntegrationAccess CATAdpResultIterator
{
public:

/** 
 * Returns the next result encountered during the operation.
 *
 * <br><b>Role</b>: Access to the next result logged by the iterator during the operation.
 *
 * @param ioPosition [inout]
 *   On input, it's the index of the attribute (specify 0 for the first attribute). On output, it will represent the index of the next attribute.
 * @param oComponent [out, CATBaseUnknown#Release]
 *   The component the errors deal with.
 * @param oErrors [out, CATBaseUnknown#Release]
 *   The errors encountered for <tt>oComponent</tt>. 
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if everything ran ok.</li>
 *   <li><code>S_FALSE</code> if no more components are available. All the components were parsed.</li>
 *   <li><code>E_INVALIDARG</code> if invalid position is provided.</li>
 *   <li><code>E_FAIL</code> if a fatal error occured during the operation. Nothing was done during the operation.</li>
 *   </ul>
 *
 */
  virtual HRESULT Next( int & ioPosition, CATIAdpPLMIdentificator *& oComponent, CATLISTP(CATError) & oErrors ) = 0;

  virtual ~CATAdpResultIterator(void) {}
};
#endif
