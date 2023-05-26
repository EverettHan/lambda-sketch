//
// CATIA Version 5 Release 4 Framework Visualization
// Copyright Dassault Systemes 2000
//-----------------------------------------------------------------------------
// Abstract :   used to notify a visibility attribute modification
//              of an element
//              
//              
//-----------------------------------------------------------------------------
// Usage :      these objects are created by model objects, and dispatched by
//              "container". They are supposed to show the evolution of the
//              state of a model. 
//              This family of events is not model dependant. (i.e. the kind
//              of generic operation on "models" is not model type dependant)
//              Only the identification of the model object on which the 
//              operation occured is model dependant.
//              
//-----------------------------------------------------------------------------
// Main methods :
//              
//
//-----------------------------------------------------------------------------
// Class :      CATModifyFilterShowAttribut
//                 CATModify
//-----------------------------------------------------------------------------
#ifndef CATModifyFilterShowAttribut_h
#define CATModifyFilterShowAttribut_h

#include "CATModelEntityNotification.h"


class ExportedByCATVisItf CATModifyFilterShowAttribut : public CATModelEntityNotification
{
  CATDeclareClass;

  public:
    CATModifyFilterShowAttribut(CATBaseUnknown *iObject);

    // clone the notification
    virtual CATModelNotification* Clone ();

  protected:
};

#endif
