#ifndef CATModifyUpdate_h
#define CATModifyUpdate_h

#include "CATModify.h"

//
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract :   used to notify modifation of an element
//              
//              
//------------------------------------------------------------------------------
// Usage :    forces the computing of the Visu by changing the filter hold in
//            by the visucontroller.
//              
//------------------------------------------------------------------------------
// Class :      CATModifyUpdate
//                CATModify
//                   CATModelEntityNotification
//------------------------------------------------------------------------------



class ExportedByCATVisItf CATModifyUpdate : public CATModify
{
  CATDeclareClass;

  public:
    CATModifyUpdate(void *modelId);
    CATModifyUpdate(CATBaseUnknown *object, 
              const IID &interfaceName=CATBaseUnknown::ClassId());
    virtual ~CATModifyUpdate();
    
    // clone the notification
    virtual CATModelNotification* Clone ();
   

};

#endif
