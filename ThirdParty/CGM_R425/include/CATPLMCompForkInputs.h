#ifndef CATPLMCompForkInputs_H
#define CATPLMCompForkInputs_H

#include "CATUnicodeString.h"
#include "CATPLMID_Simple.h"
#include "CATOmxArray.h"
#include "CATOmxKeyValueBlock.h"
#include "CATOmxOHMap.h"
#include "CATPLMTypeH.h"

/**
 * see PES "Meyer Werft_Mass Duplication Project"
 */
class CATPLMCompForkInputs
{
public:
  //unspecified for now
  CATUnicodeString Package;

  //target collab space (should be "current" one)
  CATUnicodeString Scope;

  //Objects to fork:
  //  * standard fork: only references and non "mono-instanciated" references (else it may succeed oon server but with bad result)
  //  * fork completion: only aggregated objects: instance, rep instance, port, connection, mono instanciated rep
  CATOmxArray<CATPLMID_Simple> Objects;

  //Objects to fork along with attribute values to override on clone
  //  key:    id of the object for fork (same as Objects member)
  //  value:  map from leaf extension type (or null for base object) to the set of attributes to override on clone
  //Using this member requires leaving Objects member empty.
  //
  //example:
  //CATPLMID_Simple sourceObjectId = ... ;   //id of the object to fork
  //
  //We want to override "V_Name" attribute on clone
  //CATOmxKeyValueBlock attributesOfBaseObjectToOverrideOnClone;
  //attributesOfBaseObjectToOverrideOnClone.SetValue("V_Name", "clone of ...");
  //
  //use empty CATPLMTypeH() because V_Name is a base object attribute (not an extension attribute)
  //CATOmxOHMap<CATPLMTypeH,CATOmxKeyValueBlock> attributesToOverrideOnClone;
  //attributesToOverrideOnClone.Insert(CATPLMTypeH(), attributesOfBaseObjectToOverrideOnClone);
  //
  //finally add that to CATPLMCompForkInputs
  //forkInputs.ObjectsAndAttributes.Insert(sourceObjectId, attributesToOverrideOnClone);
  CATOmxOHMap<CATPLMID_Simple, CATOmxOHMap<CATPLMTypeH, CATOmxKeyValueBlock> > ObjectsAndAttributes;


  //see server PES (for now: KEEP_ORGANIZATION, KEEP_MATURITY, KEEP_LOCK KEEP_VERSIONNING, associated value must true)
  CATOmxKeyValueBlock Options;

  //ugly: empty for a stand fork, "AGGREGATED_OBJECTS" for a fork completion
  CATUnicodeString Mode;
};

#endif
