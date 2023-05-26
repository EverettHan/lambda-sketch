#ifndef CATPublishNotification_h
#define CATPublishNotification_h

//COPYRIGHT DASSAULT SYSTEMES 2008

//Visualization Framework
#include "CATVisController.h" //For the ExportedByCATVisController

//System Framework
#include "CATNotification.h"

enum PublishMedia
{
	PublishMediaCapture,
	PublishMediaPrint
};

class ExportedByCATVisController CATPublishNotification : public CATNotification
{
  CATDeclareClass;

public:

  CATPublishNotification(const int OnlyGeometry, const PublishMedia=PublishMediaCapture);

  virtual ~CATPublishNotification();

  const int GetOnlyGeometry();

  const PublishMedia GetPublishMedia();

private:

  int _onlyGeometry;
  PublishMedia _publishMedia;
};

#endif
