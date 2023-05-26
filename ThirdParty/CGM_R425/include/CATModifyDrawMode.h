#ifndef CATModifyDrawMode_h
#define CATModifyDrawMode_h

#include "CATModelEntityNotification.h"

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
// Class :      CATModify
//                 CATModelEntityNotification
//------------------------------------------------------------------------------

enum CATVisDrawMode {Normal,Xor};

class ExportedByCATVisItf CATModifyDrawMode : public CATModelEntityNotification
{
  CATDeclareClass;
  
public:
  CATModifyDrawMode(CATBaseUnknown *obj,CATVisDrawMode mode=Normal);
  virtual ~CATModifyDrawMode();
  CATVisDrawMode GetDrawMode(void) const;
  CATModelNotification* Clone (void);
  
protected:
    CATVisDrawMode _DrawMode;

};
 

#endif
