//
// CATIA Version 5 Release 3 Framework Visualization
// Copyright Dassault Systemes 1999
//------------------------------------------------------------------------------
// Abstract :   used to notify a change with the pick attribut of one element
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
//
// Class :      CATModifyPickAttribut
//                 CATModify
//
// Author : cdt
//
// History : 22 Nov 99 -- creation
//
//------------------------------------------------------------------------------
#ifndef CATModifyPickAttribut_h
#define CATModifyPickAttribut_h

#include "CATModify.h"
#include "CATPickAttribut.h"

class ExportedByCATVisItf CATModifyPickAttribut : public CATModify
{
  CATDeclareClass;

  public:
    CATModifyPickAttribut(CATBaseUnknown *iObject, CATPickAttribut iShowAttr);
  
    CATPickAttribut GetPickAttribut() const;

    // clone the notification
    virtual CATModelNotification* Clone ();

  protected:
  CATPickAttribut _PickAttr;
};

#endif
