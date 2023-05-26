#ifndef CATVisUpdatePreviewNotif_h
#define CATVisUpdatePreviewNotif_h

#include "CATModify.h"
#include "CATVisItf.h"


class ExportedByCATVisItf CATVisUpdatePreviewNotif : public CATModify
{
  CATDeclareClass;

public:
	CATVisUpdatePreviewNotif(const CATBaseUnknown *elem);
  ~CATVisUpdatePreviewNotif();

  virtual CATModelNotification* Clone ();

private:

  // NOT implemented, to prevent default
	CATVisUpdatePreviewNotif(const CATVisUpdatePreviewNotif&);
	CATVisUpdatePreviewNotif& operator=(const CATVisUpdatePreviewNotif&);

};

#endif
