#ifndef CATCurrentCommandPanelHelpNotification_H_
#define CATCurrentCommandPanelHelpNotification_H_
#include "CATAfrFoundation.h"
//------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2015
//------------------------------------------------------------------------------
// fw AfrFoundation
// CATAfrHelpAndDoc.m
// private
//------------------------------------------------------------------------------
// Class CATCurrentCommandPanelHelpNotification
// > CATNotification
// > > CATBaseUnknown
//------------------------------------------------------------------------------
// Abstract: CATCurrentCommandPanelHelpNotification is sent
//------------------------------------------------------------------------------
#include "CATNotification.h"

//-----------------------------------------------------------------------------
class ExportedByCATAfrFoundation CATCurrentCommandPanelHelpNotification : public CATNotification
{
  CATDeclareClass;
  
public:
  
  //------
  // 'tors
  //------
  CATCurrentCommandPanelHelpNotification();
  virtual ~CATCurrentCommandPanelHelpNotification();
};

#endif
