#ifndef CATTosCATSessionListener_H
#define CATTosCATSessionListener_H

/**
* Listener on CATSession events
*/
#include "ExportedByCATPLMTos.h"
#include "CATBaseUnknown.h"

class CATSession;

class CATTosCATSessionListener
{
public:
  enum DeletionEvent { BeforeDeletion, EffectiveDeletion };

  ExportedByCATPLMTos static void OnCATSessionDeleted(DeletionEvent iEvent);
};




#endif
