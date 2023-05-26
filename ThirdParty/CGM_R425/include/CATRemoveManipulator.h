#ifndef CATRemoveManipulator_h
#define CATRemoveManipulator_h

#include "CATModelEntityNotification.h"
#include "CATBaseUnknown.h"

// CATIA Version 5 Release 1 Framework Model
// Copyright Dassault Systemes 1996
//
//------------------------------------------------------------------------------
//
// Abstract :   used to notify the remove of a manipulator on a model object
//              
//              
//------------------------------------------------------------------------------
//
// Usage :      used by implementation of CATIManipulable to notify the remove
//              of a manipulator on a model object.
//              
//              
//------------------------------------------------------------------------------
//
// Main methods :  GetManipulator()
//                 GetKindOfVisuInterface()
//
//------------------------------------------------------------------------------
//
// Class :      CATRemoveManipulator
//                CATModelEntityNotification
//                 CATModelNotification
//------------------------------------------------------------------------------

class CATManipulator;

class ExportedByCATVisItf CATRemoveManipulator : public CATModelEntityNotification
{
  CATDeclareClass;

  public :
  ////////

  CATRemoveManipulator(CATBaseUnknown *obj, CATManipulator *, 
                       const char *vueIID = NULL);
  CATRemoveManipulator(CATBaseUnknown *obj, CATManipulator *, 
                       const IID &vueIID = CATBaseUnknown::ClassId());
  virtual ~CATRemoveManipulator();
    
  CATManipulator * GetManipulator() const;
  const IID & GetVueIID() const;

  // clone the notification
  virtual CATModelNotification* Clone ();


  protected :
  /////////

  CATManipulator * _manipulator;
  const IID & _vueIID;
    
};

#endif
