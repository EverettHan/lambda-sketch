#ifndef CATUFOServiceOutput_H
#define CATUFOServiceOutput_H

/**
* @level Protected
* @usage U1
*/

#include "CATOmxSharable.h"
#include "CATObjectModelerBase.h"
#include "CATError.h"

class CATUnicodeString;
class CATUFOServiceOutputForEditLinks;
class CATOmbOutputRelation;
class CATComponentId;

/**
 * Class to manage output from the UFO Reroute service. Basically a list of all the relations that UFO could not reroute, with a few tidbits of info (if available) for each.
 */
class ExportedByCATObjectModelerBase CATUFOServiceOutput: public CATOmxSharable
{
public:
  /**
   * Create a UFO service output handler. You should release this once you're done with it !
   */
  static CATUFOServiceOutput* Create();

  // Move to next UFO Reroute impact.
  virtual void Next() = 0;

  // Reset iteration to the first impacted relation.
  virtual void Reset() = 0;

  // Get the relation we were trying to reroute.
  // NB : NULL means we're done iterating over the output of UFO Reroute !
  virtual CATOmbOutputRelation* GetImpactedRelation() = 0;

  // Get the UFO substitution information:
  // source is the occurrence that was entered into the UFO Log as being replaced
  // target is its replacement according to the UFO Log
  // Either or both could be the NULL component (!oSource == TRUE or !oTarget == TRUE) if the log
  // had no solution to offer or did not even known about the occurrence.
  virtual void GetSubstitutionForRelation(CATComponentId& oSource, CATComponentId& oTarget) = 0;

  // Get the context for the source and target occurrences
  // This is the original context occurrence for the relation for source and the rerouted context
  // for target
  virtual void GetSubstitutionContextsForRelation(CATComponentId& oSourceContext, CATComponentId& oTargetContext) = 0;

  // set a flag indicating that UFO failed to reroute a Master relation for SIMULIA ReplaceDAG;
  // this will be used to signal a critical failure to SIMULIA, instead of handling this as "simple"
  // UFO failure which might be handled by EditLinks.
  virtual void FlagAsErrorForSIMULIA() = 0;
  virtual CATBoolean UFOSucceededForSIMULIA() = 0;

  // Get error message (only used for SIMULIA at this time)
  virtual CATUnicodeString GetNLSMessage();

  virtual void RegenerateDescriptors() = 0;

protected:
  CATUFOServiceOutput(const CATUnicodeString& iErrorMessage="");
  virtual ~CATUFOServiceOutput();

  CATError *_Error;
};

class CATUFOServiceOutputError: public CATError
{
protected:
  friend class CATUFOServiceOutputImpl;
  CATDeclareErrorClass(CATUFOServiceOutputError, CATError);

  CATUFOServiceOutputError(const char * msgId);

private:
  static const CATUnicodeString Catalog;
  static const CATErrorId ErrorId;
};


#endif
