#ifndef CATModifyGeometry_h
#define CATModifyGeometry_h

#include "CATModify.h"

//
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract :   used to notify a geometric modification of an element
//              
//              
//------------------------------------------------------------------------------
// Usage :      these objects are created by model objects, and dispatch by
//              "container". They are supposed to show the evolution of the
//              state of a model. 
//              This family of events is not model dependant. (i.e. the kind
//              of generic operation on "models" is not model type dependant)
//              Only the identification of the model object on which the 
//              operation occured is model dependant.
//              
//------------------------------------------------------------------------------
// Main methods :
//              IsAKindOf(const char *) : 
//
//------------------------------------------------------------------------------
// Class :      CATModifyGeometry
//                 CATModify
//------------------------------------------------------------------------------

class ExportedByCATVisItf CATModifyGeometry : public CATModify
{
  CATDeclareClass;

  public:
    CATModifyGeometry(void * modelId);
    virtual ~CATModifyGeometry();

    // clone the notification
    virtual CATModelNotification* Clone ();

};

#endif
