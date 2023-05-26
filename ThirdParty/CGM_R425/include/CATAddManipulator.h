#ifndef CATAddManipulator_h
#define CATAddManipulator_h

#include "CATModelEntityNotification.h"
#include "CATBaseUnknown.h"
// CATIA Version 5 Release 1 Framework Model
// Copyright Dassault Systemes 1996
//
//------------------------------------------------------------------------------
//
// Abstract :   used to notify the add of a manipulator on a model object on
//              a kind of CATIVisu interface.
//              
//              
//------------------------------------------------------------------------------
//
// Usage :      used by implementation of CATIManipulable interface to notify
//              the add of a graphic manipulator on a model object
//              
//              
//------------------------------------------------------------------------------
//
// Main methods :  GetManipulator()
//                 GetKindOfVisuInterface()
//
//------------------------------------------------------------------------------
//
// Class :      CATAddManipulator
//                CATModelEntityNotification
//                 CATModelNotification
//------------------------------------------------------------------------------

class CATManipulator;

class ExportedByCATVisItf CATAddManipulator : public CATModelEntityNotification
{
  CATDeclareClass;

  public :
  ////////

  CATAddManipulator(CATBaseUnknown  *obj, CATManipulator *, 
                    const char *vueIID = NULL );
  CATAddManipulator(CATBaseUnknown *obj, CATManipulator *, 
                    const IID &vueIID = CATBaseUnknown::ClassId());
  virtual ~CATAddManipulator();
    
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
