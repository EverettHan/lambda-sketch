#ifndef CATSOVisuEvents_h
#define CATSOVisuEvents_h

#include "CATVisItf.h"
#include "CATModelEntityNotification.h"
#include "CATBaseUnknown.h"
#include "list.h"

//
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract :   used to notify modifation of an element
//              
//              
//------------------------------------------------------------------------------
// Usage :     -these objects are created by model objects, and dispatch by
//              "container". They are supposed to show the evolution of the
//              state of a model. 
//              This family of events is not model dependant. (i.e. the kind
//              of generic operation on "models" is not model type dependant)
//              Only the identification of the model object on which the 
//              operation occured is model dependant.
//             -The notification contains contains the interface name of the
//              object which is modified.
//              
//------------------------------------------------------------------------------
// Main methods :
//              IsAKindOf(const char *) : 
//
//------------------------------------------------------------------------------
// Class :      CATSOVisuEvents
//                 CATModelEntityNotification
//------------------------------------------------------------------------------



class ExportedByCATVisItf CATSOVisuEvents : public CATModelEntityNotification
{
  CATDeclareClass;

  public:
    // default constructor
    CATSOVisuEvents();
  
    // constructor with a single event
    CATSOVisuEvents(CATModelEntityNotification* iFirstNotif);

    // constructor with a list of events
    CATSOVisuEvents(list<CATModelEntityNotification> iAllNotif);

    // destructor
    virtual ~CATSOVisuEvents();


    // to add a notif in the list
    void operator += (CATModelEntityNotification* iNotif);

    // number of events in the list
    const int GetSize ();

    // return the event number i
    CATModelEntityNotification* operator [] (int i);

    // clone the notification
    virtual CATModelNotification* Clone ();

protected:

  list<CATModelEntityNotification> _notifList;

};

#endif
