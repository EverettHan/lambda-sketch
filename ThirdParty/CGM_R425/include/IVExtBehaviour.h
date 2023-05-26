//===================================================================
// COPYRIGHT Dassault Systemes 2022/11/15
//===================================================================
// Header definition of class IVExtBehaviour
//===================================================================
//
// Usage notes: Default Implementation of IVISUIBehaviour
//
//===================================================================
//  2022/11/15 Creation
//===================================================================
#ifndef IVExtBehaviour_H
#define IVExtBehaviour_H

#include "CATSYPEventHandlersSupport.h"
#include "IVInterfaces.h"
#include "IVISUIBehaviour.h"

class CATSYPEvent;
class CATSYPEventHandler;
class CATSYPEventArgs;

//-----------------------------------------------------------------------

class ExportedByIVInterfaces IVExtBehaviour : public IVISUIBehaviour
{
   CATDeclareClass;

public:

  IVExtBehaviour();
  virtual ~IVExtBehaviour();

  virtual int AddHandler(CATSYPEvent* iEvent, CATSYPEventHandler* iHandler, int iHandleConsumedEvents = 0) ;
  virtual int RemoveHandler(CATSYPEvent* iEvent, CATSYPEventHandler* iHandler);

protected:

  //
  void DispatchEvent(CATSYPEventArgs* iEventArgs);

private :
  CATSYPEventHandlersSupport m_handlersSupport;
};
//-----------------------------------------------------------------------
CATDeclareHandler(IVExtBehaviour, CATBaseUnknown);
//-----------------------------------------------------------------------

#endif
