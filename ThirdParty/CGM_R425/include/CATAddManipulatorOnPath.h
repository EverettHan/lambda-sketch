#ifndef CATAddManipulatorOnPath_h
#define CATAddManipulatorOnPath_h

// CATIA Framework Visualization
// Copyright Dassault Systemes 1997
//
//------------------------------------------------------------------------------
//
// Abstract :   used to notify the add of a manipulator on a model path on
//              a kind of CATIVisu interface.
//              
//              
//------------------------------------------------------------------------------
//
// Usage :      used by implementation of CATIManipulable interface to notify
//              the add of a graphic manipulator on a model path
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
// Class :      CATAddManipulatorOnPath
//               CATAddManipulator
//                CATModelEntityNotification
//                 CATModelNotification
//------------------------------------------------------------------------------
#include "CATAddManipulator.h"
#include "CATI3DGeoVisu.h"

class CATManipulator;
class CATPathElement;

class ExportedByCATVisItf CATAddManipulatorOnPath : public CATAddManipulator
{
  CATDeclareClass;

  public :
  ////////

  CATAddManipulatorOnPath(CATPathElement &path, CATManipulator *manipulator, const IID &kind = CATI3DGeoVisu::ClassId());
  virtual ~CATAddManipulatorOnPath();
    
  CATPathElement &GetPathElement() const;

  // clone the notification
  virtual CATModelNotification* Clone ();


};

#endif
