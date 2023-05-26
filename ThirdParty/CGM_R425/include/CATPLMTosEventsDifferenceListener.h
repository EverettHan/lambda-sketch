#ifndef _CATPLMEventsDifferenceListener_H
#define _CATPLMEventsDifferenceListener_H
// COPYRIGHT DASSAULT SYSTEMES 2008
/**
* @COPYRIGHT DASSAULT SYSTEMES 2008
* ----------------------------------------------------------------------------------------------------------------------
*   Origin         : Physical Layer Software Component for local running of remote persistency entity 
*   Specification  : internal small implementation 
*   Remarks : for more detailled specification (UML sequence diagram, statechart, ..)  consult associated Lotus Database 
* ----------------------------------------------------------------------------------------------------------------------
*/

/**
 * @level Protected
 * @usage U1       
 */
#include "IUnknown.h"
#include "CATBoolean.h"
#include "ExportedByCATPLMIdentification.h"

class CATPLMID;

class ExportedByCATPLMIdentification CATPLMTosEventsDifferenceListener
{
public:

  CATPLMTosEventsDifferenceListener() {}

  virtual ~CATPLMTosEventsDifferenceListener() {}

  virtual HRESULT DeclareCreatedObject(const CATPLMID & iPLMIDFrom) = 0;

  virtual HRESULT DeclareDeletedObject(const CATPLMID & iPLMIDFrom) = 0;

};

#endif
