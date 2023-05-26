//
// CATIA Version 5 Release 2 Framework Visualization
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract :   used to notify a show attribut modification of an element
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
// Class :      CATModifyShowAttribut
//                 CATModify
//------------------------------------------------------------------------------
#ifndef CATModifyShowAttribut_h
#define CATModifyShowAttribut_h

#include "CATModify.h"
#include "CATShowAttribut.h"

class ExportedByCATVisItf CATModifyShowAttribut : public CATModify
{
  CATDeclareClass;

  public:
    CATModifyShowAttribut(CATBaseUnknown *iObject, CATShowAttribut iShowAttr, unsigned int forceWritting = 1, unsigned int undo = 0);
  
    CATShowAttribut GetShowAttribut() const;
	unsigned int IsWrittingForced() const;
	unsigned int IsUndo() const;

    // clone the notification
    virtual CATModelNotification* Clone ();

  protected:
  CATShowAttribut _ShowAttr;
  unsigned int	_forceWritting : 1;
  unsigned int	_undo : 1;
};

#endif
