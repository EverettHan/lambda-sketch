//-----------------------------------------------------------------------------
// COPYRIGHT Dassault Systemes 2019
//-----------------------------------------------------------------------------
#ifndef IVSUIExternalBehaviourFactory_H
#define IVSUIExternalBehaviourFactory_H

#include "IVInterfaces.h"

#include "CATBaseUnknown.h"
class IVISUIBehaviour;

//-----------------------------------------------------------------------------
/**
 * IVSUIExternalBehaviourFactory
 */
class IVSUIExternalBehaviourFactory: public CATBaseUnknown
{
public:

  /**
   * Build an IVSUIBehaviour.
   *
   * @return
   *  An new instance of an IVISUIBehaviour. Must be released.
   *  nullptr if error.
   */
  virtual IVISUIBehaviour* Build() const = 0;

  /** */
  virtual ~IVSUIExternalBehaviourFactory() = default;
};

#endif
