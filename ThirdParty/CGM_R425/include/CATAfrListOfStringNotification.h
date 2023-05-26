#ifndef CATAfrListOfStringNotification_h
#define CATAfrListOfStringNotification_h

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
#include "CATAfrFoundation.h"
#include "CATListOfCATString.h"

class CATCmdWorkshop;
class CATCmdWorkbench;

class ExportedByCATAfrFoundation CATAfrListOfStringNotification : public CATNotification
{
  CATDeclareClass;
  
  public:

    CATAfrListOfStringNotification();
    virtual ~CATAfrListOfStringNotification();
    
    CATListOfCATString _IdList;

  private:
  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
    CATAfrListOfStringNotification (const CATAfrListOfStringNotification &);
    CATAfrListOfStringNotification & operator= (const CATAfrListOfStringNotification &);

};

#endif
