#ifndef CATEndTransaction_h
#define CATEndTransaction_h

#include "CATModelNotification.h"

//
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract :   used to notify a end of transaction in the model. This is sent
//              when a model buffers modifications and send them together
//              between a begin transaction and an end transaction notification.
//              
//              several modifications are supposed to be sent between a
//              begin transaction and an end transaction.
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
//                
//------------------------------------------------------------------------------
// Main methods :
//              IsAKindOf(const char *) : 
//
//------------------------------------------------------------------------------
// Class :      CATEndTransaction
//                 CATModelNotification
//------------------------------------------------------------------------------



class ExportedByCATVisItf CATEndTransaction : public CATModelNotification
{
  CATDeclareClass;

  public:
    CATEndTransaction();
    virtual ~CATEndTransaction();
};

#endif
