#ifndef CATModifyVisuMode_H
#define CATModifyVisuMode_H

#include "CATModify.h"
#include "CATPathElement.h"
#include "list.h"

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
// Class :    CATModifyVisuMode  
//               CATModify
//                 CATModelEntityNotification
//------------------------------------------------------------------------------


enum CATVisuModeType {AS_STANDARD,ADD,REMOVE}; 

class ExportedByCATVisItf CATModifyVisuMode : public CATModify
{
  CATDeclareClass;
  
public:
  CATModifyVisuMode (CATBaseUnknown *object, const IID &iid,
                     CATVisuModeType type=AS_STANDARD, 
                     CATPathElement *ipath=NULL);

  CATModifyVisuMode (CATBaseUnknown *object, IID *iid,
                     CATVisuModeType type=AS_STANDARD, 
                     CATPathElement *ipath=NULL);

  CATModifyVisuMode ( list<CATPathElement> &iPathList,
                      IID *iid,
                      CATVisuModeType type=AS_STANDARD );


  ~CATModifyVisuMode();
  

  // clone the notification
  virtual CATModelNotification* Clone ();
  
  // get the interface iid of the visu mode
  IID * GetVisuModeIID(void);
  CATPathElement * GetPath(void);
  CATVisuModeType& GetVisuModeType ();
  list<CATPathElement>& GetPathList ();

protected:
  IID *_interfIID;
  CATPathElement *_Path;
  CATVisuModeType _VisuModeType;
  list<CATPathElement>* _PathList;
  
};


#endif
