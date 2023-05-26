#ifndef CATFilterEventSender_H
#define CATFilterEventSender_H
//
// 
// Copyright Dassault Systemes 2018

#include "SGInfra.h"
#include "CATEventSubscriber.h"
#include "CATFilterNotification.h"

class CATVisFilter;

class ExportedBySGInfra CATFilterEventSender : public CATEventSubscriber
{
  CATDeclareClass;
public :

  CATFilterEventSender(CATVisFilter* iFilter);
  virtual ~CATFilterEventSender();
  void SendFilterNotification(CATFilterNotificationType iType);
  inline CATVisFilter * GetFilter();

private :
  CATVisFilter* _filter;
};

inline CATVisFilter * CATFilterEventSender::GetFilter()
{
  return _filter;
}

#endif 


