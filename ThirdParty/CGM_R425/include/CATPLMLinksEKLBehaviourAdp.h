//===================================================================
// COPYRIGHT [Dassault Systemes] 2022
//===================================================================
// CATPLMLinksEKLBehaviourAdp.cpp
// Header definition of class CATPLMLinksEKLBehaviourAdp
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2022/12/07 Creation
//===================================================================
#ifndef CATPLMLinksEKLBehaviourAdp_H
#define CATPLMLinksEKLBehaviourAdp_H

#include "CATLifSpecs.h"
#include "CATIPLMLinksEKLBehaviour.h"

/**
 * Adapter for the CATIPLMLinksEKLBehaviour interface.
 * <b>Role</b>: This class is provided to make interface modification easiest.
 * No default implementation is provided by this adapter: all methods return E_NOTIMPL.
 * @see CATIPLMLinksEKLBehaviour
*/

class ExportedByCATLifSpecs CATPLMLinksEKLBehaviourAdp : public CATIPLMLinksEKLBehaviour
{
public:
  // Standard constructors and destructors
  CATPLMLinksEKLBehaviourAdp();
  virtual ~CATPLMLinksEKLBehaviourAdp();

  // ---- CATIPLMLinksEKLBehaviour implementation ----

  /**
  * Provides a default implementation for @href CATIPLMLinksEKLBehaviour#IsLinkExposedInEKL.
  * <br><b>Role</b>: The default implementation does nothing and returns E_NOTIMPL.
  */
  virtual HRESULT IsLinkExposedInEKL();

private:
  // Copy constructor and equal operator must not be implemented
  CATPLMLinksEKLBehaviourAdp(const CATPLMLinksEKLBehaviourAdp&);
  CATPLMLinksEKLBehaviourAdp& operator =(const CATPLMLinksEKLBehaviourAdp&);
};

#endif
