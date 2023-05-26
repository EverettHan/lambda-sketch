//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2012/02/02
//===================================================================
// Header definition of differents map classes
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2010/11/30 Creation: Code generated by the 3DS wizard
//===================================================================

/**
 * @level Protected
 * @usage U1       
 */

#ifndef CATPLMIDMAPADPITER_H
#define CATPLMIDMAPADPITER_H
#include "CATOmxMapIter.h"
#include "CATIAdpPLMIdentificator.h"
#include "CATBoolean.h"
#include "CATOmxOHMap.h"
#include "CATPLMIdentificationAccess.h"

class CATPLMIDMap;

/**
 * iterator on a CATOmxOmap map.
 * usage: (with a map that associates a string to an object
 * CATOmxOMap<CATUnicodeString,IUnknown*> map;
 * CATOmxMapIter<CATUnicodeString,IUnknown*> iter(map.MapIterator());
 * while(iter.Next())
 * {
 *   CATUnicodeString key = iter.Key();
 *   IUnknown* value = iter.Value();
 *   //your code
 * }
 * restriction: you must not alterate the map while using an iterator on it
 */
class ExportedByCATPLMIdentificationAccess CATPLMIDMapAdpIter
{
  typedef CATOmxMapIter<CATPLMID, CATPLMID> CATPLMIDPrivateMapIter;
  CATPLMIDPrivateMapIter *_MapIter;
  CATPLMIDMapAdpIter(const CATOmxOHMap<CATPLMID, CATPLMID> &iMap);
  friend class CATPLMIDMap;
public:
  CATPLMIDMapAdpIter(const CATPLMIDMapAdpIter &);
  ~CATPLMIDMapAdpIter();
 
  /**
  * Value
  * @return CATBaseUnknown#Release
  */
  CATIAdpPLMIdentificator* Value();

 /**
  * Key
  * @return CATBaseUnknown#Release
  */
  CATIAdpPLMIdentificator*   Key();
  CATBoolean Next(); 
};

#endif