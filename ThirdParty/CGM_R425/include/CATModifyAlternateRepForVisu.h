#ifndef CATModifyAlternateRepForVisu_h
#define CATModifyAlternateRepForVisu_h

#include "CATModify.h"

/**
* Notification class to add an alternate rep used for visualization.
* When visualizing a given rep, if it has an attached alternate rep, the visualized rep will be the alternate rep instead of the rep itself.
* To remove an existing alternate rep, use this notification with a NULL alternate rep.
*/

class CATBaseUnknown;

class ExportedByCATVisItf CATModifyAlternateRepForVisu : public CATModify
{
  CATDeclareClass;

public:
  CATModifyAlternateRepForVisu(CATBaseUnknown* iObject, CATBaseUnknown* iAlternativeRep);
  virtual ~CATModifyAlternateRepForVisu();

  // clone the notification
  virtual CATModelNotification* Clone();

  CATBaseUnknown* GetAlternateRep() const;

protected:
  CATBaseUnknown* _AlternateRep;
};

#endif
