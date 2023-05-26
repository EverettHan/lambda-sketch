#ifndef CATVidNotification_H
#define CATVidNotification_H

#include <VisuDialog.h>
#include <CATNotification.h>
#include <CATVidEventData.h>


class ExportedByVisuDialog CATVidNotification : public CATNotification
{
  CATDeclareClass;
public:
  CATVidNotification();
  virtual ~CATVidNotification();

  CATVidEventData* GetNotificationData ();

  void SetNotificationData(const CATVidEventData& i_eventData);

private:
  CATVidEventData _eventData;
};

class CATVidHyperlinkNotification : public CATVidNotification
{
  CATDeclareClass;
public:
  CATVidHyperlinkNotification(){};
  virtual ~CATVidHyperlinkNotification(){};
};



#endif
