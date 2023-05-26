// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATAfrStartCommandNotification.h
// Header definition of CATAfrStartCommandNotification
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jul 2009  Creation: Code generated by the CAA wizard  LD3
//===================================================================
#ifndef CATAfrStartCommandNotification_H
#define CATAfrStartCommandNotification_H

#include "CATAfrItf.h"
#include "CATNotification.h"

//-----------------------------------------------------------------------

/**
* Class representing the notification for an event simulating the launching of one command.
*
* <br><b>Role</b>: Instanciate this class in your @href CATAfrStarterView implementation to send 
* a notification for the starterRep when an event simulate the action to start a command.
* 
*
* @example
*  SendNotification (GetParent(),new CATAfrStartCommandNotification());
*
*/
class ExportedByCATAfrItf CATAfrStartCommandNotification: public CATNotification
{
  CATDeclareClass;

  public:

  // Standard constructors and destructors
  // -------------------------------------
     CATAfrStartCommandNotification ();
     virtual ~CATAfrStartCommandNotification ();

};

//-----------------------------------------------------------------------

#endif
