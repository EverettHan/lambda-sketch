#ifndef CATSysPCSEventPublisher_H
#define CATSysPCSEventPublisher_H

// COPYRIGHT DASSAULT SYSTEMES 2004

// ==================================================================================
// Abstract class
// -------------
// Class which publishes an event
//
// ==================================================================================


// System Framework
#include "CATBaseUnknown.h"
#include "JS03TRA.h"

class ExportedByJS03TRA CATSysPCSEventPublisher: public CATBaseUnknown 
{
  // Used in conjunction with CATImplementClass in the .cpp file
  CATDeclareClass;
  
  public:
  
    // Create an alarm.
    CATSysPCSEventPublisher ();

    // to delete notifications.
    virtual ~CATSysPCSEventPublisher();

    // EmitNotification
    // -------------
    // Send a notification to state that the PCS stat is activated
    //
    void EmitNotification();


  private:
    // Copy constructor, not implemented
    // Set as private to prevent from compiler automatic creation as public.
    CATSysPCSEventPublisher(const CATSysPCSEventPublisher &iObjectToCopy);
  
    // Assignment operator, not implemented
    // Set as private to prevent from compiler automatic creation as public.
    CATSysPCSEventPublisher & operator = (const CATSysPCSEventPublisher &iObjectToCopy);
};

#endif
