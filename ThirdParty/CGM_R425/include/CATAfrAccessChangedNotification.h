#ifndef CATAfrAccessChangedNotification_h
#define CATAfrAccessChangedNotification_h

// COPYRIGHT DASSAULT SYSTEMES 1999

//===========================================================================
//  Abstract of the sample:
//  ----------------------
//
//  Application using a new document (CAAGeometry) with its own workshop and 
//  commands.
//     
//===========================================================================
//  Abstract of the class:
//  ----------------------
//
//  Notification base class.

//===========================================================================
//  Inheritance:
//  ------------
//            CATNotification  ( System Framework)
//               CATBaseUnknown (System Framework).
//
//===========================================================================
//  Main Method:
//  ------------
//
//===========================================================================

#include "CATNotification.h"          // Needed to derive from CATNotification
#include "CATAfrFoundation.h"

class CATCmdWorkshop;
class CATAfrApp;
class CATCmdWorkbench;

class ExportedByCATAfrFoundation CATAfrAccessChangedNotification : public CATNotification
{
  CATDeclareClass;
  
  public:

    CATAfrAccessChangedNotification();
    virtual ~CATAfrAccessChangedNotification();
    
    CATCmdWorkbench* GetWorkbench ();
    void SetWorkbench ( CATCmdWorkbench* workbench );

    CATCmdWorkshop* GetWorkshop ();
    void SetWorkshop ( CATCmdWorkshop* workshop );

    /** Sets App */
    void SetApp(CATAfrApp *i_app);

    /** Gets App */
    CATAfrApp * GetApp( );

  private:
  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
    CATAfrAccessChangedNotification (const CATAfrAccessChangedNotification &);
    CATAfrAccessChangedNotification & operator= (const CATAfrAccessChangedNotification &);

    CATCmdWorkbench* _workbench;
    CATCmdWorkshop* _workshop;
    CATAfrApp *     _app;
};

#endif
