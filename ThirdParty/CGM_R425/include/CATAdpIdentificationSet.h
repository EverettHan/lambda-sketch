/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2006
#ifndef CATAdpIdentificationSet_H
#define CATAdpIdentificationSet_H

/**
 * @CAA2Level L1
 * @CAA2Usage U1  
 */

#include "CATPLMIntegrationAccess.h"
#include "CATErrorDef.h"
#include "CATAdpAttributeSet.h"

/**
 * Class defining a set of attributes identifying a component.
 *
 * <br><b>Role</b>: provide a mean to identify a component in the database though a set of attributes (@href CATAdpQueryServices ).
 */
class ExportedByCATPLMIntegrationAccess CATAdpIdentificationSet : public CATAdpAttributeSet
{
public:

/**
 * Constructs an identification set.
 */
  CATAdpIdentificationSet( void );
/**
 * Destructs an identification set.
 */
  virtual ~CATAdpIdentificationSet( void );
};
#endif
