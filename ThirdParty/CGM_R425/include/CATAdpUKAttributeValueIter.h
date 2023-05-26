/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2012
/**
 * @level Protected
 * @usage U1  
 */
#ifndef CATAdpUKAttributeValueIter_H
#define CATAdpUKAttributeValueIter_H

#include "CATPLMIntegrationAccess.h"
#include "CATErrorDef.h"
#include "CATString.h"
class CATIAdpValueReader;


/**
 * Class giving access to  attribute value inside a set of attributes.
 *
 * <br><b>Role</b>: provide access to  attribute value inside a set of attributes .
 */
class ExportedByCATPLMIntegrationAccess CATAdpUKAttributeValueIter
{
public:

/** 
 * Retrieves the iterator to access value attribute inside a set of attributes.
 *
 * <br><b>Role</b>: Retrieves the iterator to acces atribute value inside a set of attributes.
 *
 * @param ioPosition [inout]
 *   On input, it's the index of the attribute  (specify 0 for the first attribute). On output, it will contain the index
 * of the next attribute.
 * @param oAttributeId [out]
 *   The name of the attribute.
 * @param oAttributeValue [out]
 *   The object to read attribute value.
 *  <ul>
 *  <li>You must delete this object when useless.</li>
 *  </ul>
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if everything ran ok.</li>
 *   <li><code>S_FALSE</code> if no more attribute set is available.</li>
 *   <li><code>E_INVALIDARG</code> if invalid position is provided.</li>
 *   <li><code>E_FAIL</code> if a fatal error occured during the operation. Nothing was done during the operation.</li>
 *   </ul>
 *
 */
  virtual HRESULT Next(  int&    ioPosition,    CATString & oAttributeId,  CATIAdpValueReader    *&    oAttributeValue ) = 0;


 /**
  * Destructor.
  */
  virtual ~CATAdpUKAttributeValueIter(void) {}
};
#endif
