#ifndef CATAdpIdentifierSet_h
#define CATAdpIdentifierSet_h

/**
 * @level Protected
 * @usage U1
 */

#include "CATAdpStdAttributeSet.h"
#include "CATString.h"
#include "CATPLMIntegrationAccess.h"

class CATIAdpValueWriter;
class CATIAdpValueReader;
class CATAdpPrivateAttributeSet;

/**
 * Class defining a set of attributes identifying a component.
 *
 * <br><b>Role</b>: provide a mean to identify a component in the database though a set of attributes (@href CATAdpProtectedQueryServices ).
 */
class ExportedByCATPLMIntegrationAccess CATAdpIdentifierSet : public CATAdpStdAttributeSet
{
public :
  CATAdpIdentifierSet();
  virtual ~CATAdpIdentifierSet();
};
#endif
