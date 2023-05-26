#ifndef CATGhostingNotification_h
#define CATGhostingNotification_h

// COPYRIGHT DASSAULT SYSTEMES 2014

//     
//===========================================================================
//  Abstract of the class:
//  ----------------------
//
//  Notification class with list of strings as a data member. Can be used to communicate a list of command header Ids.

//===========================================================================
//  Inheritance:
//  ------------
//            CATNotification  ( System Framework)
//               CATBaseUnknown (System Framework).
//
//===========================================================================

#include "CATNotification.h" 
#include "ExportedByCATGhosting.h"

#include "CATModelIdentificator.h"






class ExportedByCATGhosting CATGhostingNotification : public CATNotification
{
  CATDeclareClass;
  
  public:

    CATGhostingNotification();
    virtual ~CATGhostingNotification();
    
    const CATModelIdentificator *_Id;
    int _ghostingOn;

  private:
  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
    CATGhostingNotification (const CATGhostingNotification &);
    CATGhostingNotification & operator= (const CATGhostingNotification &);

};

#endif
