// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// CATPLMClientCorePath.h
// Header definition of CATPLMClientCorePath
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Dec 2008  Creation: Code generated by hand  XVI
//===================================================================
/**
  * @level Protected
  * @usage U1
  */
#ifndef CATPLMClientCorePath_H
#define CATPLMClientCorePath_H

#include "CATBaseUnknown.h"
#include "CATPLMComponentInterfaces.h"
class CATIPLMClientCorePath;

//-----------------------------------------------------------------------

/**
* obsolete
*/
class ExportedByCATPLMComponentInterfaces CATPLMClientCorePath
{
public:
  /**
   * obsolete, use CATIPLMClientCorePath::Create
   */
  static HRESULT GetPLMClientCorePath(CATIPLMClientCorePath *& oPath);
};

//-----------------------------------------------------------------------

#endif
