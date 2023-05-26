#ifndef CATRemoveManipulatorOnPath_h
#define CATRemoveManipulatorOnPath_h

// CATIA Framework Visualization
// Copyright Dassault Systemes 1997
//
//------------------------------------------------------------------------------
//
// Abstract :   used to notify the remove of a manipulator on a model path on
//              a kind of CATIVisu interface.
//              
//              
//------------------------------------------------------------------------------
//
// Usage :      used by implementation of CATIManipulable interface to notify
//              the remove of a graphic manipulator on a model path
//              
//              
//------------------------------------------------------------------------------
//
// Main methods : 
//                 GetPathElement()
//               
//
//------------------------------------------------------------------------------
//
// Class :      CATRemoveManipulatorOnPath
//               CATRemoveManipulator
//                CATModelEntityNotification
//                 CATModelNotification
//------------------------------------------------------------------------------
#include "CATRemoveManipulator.h"
#include "CATI3DGeoVisu.h"

class CATManipulator;
class CATPathElement;

class ExportedByCATVisItf CATRemoveManipulatorOnPath : public CATRemoveManipulator
{
  CATDeclareClass;

  public :
  ////////

  CATRemoveManipulatorOnPath(CATPathElement &path, CATManipulator *manipulator, const IID &kind = CATI3DGeoVisu::ClassId());
  virtual ~CATRemoveManipulatorOnPath();
    
  CATPathElement &GetPathElement() const;

  // clone the notification
  virtual CATModelNotification* Clone ();


};

#endif
