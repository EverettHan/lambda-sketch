#ifndef CATIManipulable_h
#define CATIManipulable_h
#include "SceneGraphManager.h"

#include "CATBaseUnknown.h"

// CATIA Version 5 Release 1 Framework VFW2
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------
//
// Abstract : Interface permettant de poser un manipulateur graphique 3D
// ---------- sur un objet modele
//            
//            
//              
//   
//------------------------------------------------------------------------
//
// Usage :    utilise par l'appli pour poser un manipulateur sur un objet 
// -------    modele
//  
//------------------------------------------------------------------------
//
// Inheritance :  CATIManipulable 
// -----------      CATBaseUnknown
//
//------------------------------------------------------------------------
//
// Main Methods :  AddManipulator
// --------------  RemoveManipulator
//                 AddManipulatorOnPath
//                 RemoveManipulatorOnPath
//               
//------------------------------------------------------------------------

class CATManipulator;
class CATPathElement;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedBySceneGraphManager IID IID_CATIManipulable;
#else
extern "C" const IID IID_CATIManipulable;
#endif

class ExportedBySceneGraphManager CATIManipulable : public CATBaseUnknown
{
  CATDeclareInterface;

  public :
  ////////

  virtual void AddManipulator ( CATManipulator *manipulator, 
                                const IID & vueIID ) = 0;
  virtual void RemoveManipulator ( CATManipulator *manipulator, 
                                   const IID & vueIID ) = 0;
  virtual void AddManipulatorOnPath ( CATManipulator *manipulator, 
                                      CATPathElement &modelPath,
                                      const IID & vueIID ) = 0;
  virtual void RemoveManipulatorOnPath ( CATManipulator *manipulator,
                                         CATPathElement &modelPath,
                                         const IID & vueIID ) = 0;
} ; 

CATDeclareHandler(CATIManipulable,CATBaseUnknown);

#endif
