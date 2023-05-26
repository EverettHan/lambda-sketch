// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATAfrCreateSubContainerViewNotification.h
// Header definition of CATAfrCreateSubContainerViewNotification
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Sep 2009  Creation: Code generated by the CAA wizard  LD3
//===================================================================
#ifndef CATAfrCreateSubContainerViewNotification_H
#define CATAfrCreateSubContainerViewNotification_H

#include "CATAfrItf.h"
#include "CATNotification.h"

class CATCommand;

//-----------------------------------------------------------------------

/**
* Class representing the notification for an event simulating the display of a sub container view
*
* <br><b>Role</b>: Instanciate this class in your @href CATAfrContainerView implementation to send 
* a notification for the containerRep when an event simulate the display of a sub container view.
* 
*
* @example
*  SendNotification (GetFather(),new CATAfrCreateSubContainerViewNotification());
*
*/
class ExportedByCATAfrItf CATAfrCreateSubContainerViewNotification: public CATNotification
{
  CATDeclareClass;

  public:

  // Standard constructors and destructors
  // -------------------------------------
     CATAfrCreateSubContainerViewNotification (CATCommand *pSelectedUIObject);
     virtual ~CATAfrCreateSubContainerViewNotification ();

  CATCommand *_pSelectedUIObject;


  private:

  // Copy constructor and equal operator
  // -----------------------------------
  CATAfrCreateSubContainerViewNotification (CATAfrCreateSubContainerViewNotification &);
  CATAfrCreateSubContainerViewNotification& operator=(CATAfrCreateSubContainerViewNotification&);
};

//-----------------------------------------------------------------------

#endif