// CATIPLMLinksEKLBehaviour.cpp
// Header definition of class CATIPLMLinksEKLBehaviour
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2022/12/07 Creation
//===================================================================
#ifndef CATIPLMLinksEKLBehaviour_H
#define CATIPLMLinksEKLBehaviour_H

#include "CATLifSpecs.h"
#include "CATBaseUnknown.h"

class CATUnicodeString;

extern ExportedByCATLifSpecs  IID IID_CATIPLMLinksEKLBehaviour;

/**
 * Interface dedicated to EKL behaviour for Links and Relations.
 * <b>Role</b>: This interface is provided to allow applicative modelers to
 * enable EKL display for their own components.
*/

class ExportedByCATLifSpecs CATIPLMLinksEKLBehaviour : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
  * Checks if the component is to be displayed in EKL function GetLinks for links introspection.
  * Behavior might be similar to Links and Relations UI, see CATIPLMLinksUIBehaviour::IsDisplayableInELR
  *
  * @return
  *   <dt><tt>S_OK</tt><dd>The component is to be displayed in EKL.
  *   <dt><tt>S_FALSE</tt><dd>The component is not to be displayed in EKL.
  *   <dt><tt>E_FAIL</tt><dd>The method failed.
  *   <dt><tt>E_NOTIMPL</tt><dd>The method is not implemented.
  *   </dl>
  */
  virtual HRESULT IsLinkExposedInEKL() = 0;
};

CATDeclareHandler(CATIPLMLinksEKLBehaviour, CATBaseUnknown);

#endif
