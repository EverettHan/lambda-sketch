 //===================================================================
// COPYRIGHT Dassault Systemes 2020/05/14
//===================================================================
// Header definition of class IVStylusDeviceSelectionEditor
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2020/05/14 Creation
//===================================================================
#ifndef IVStylusDeviceSelectionEditor_H
#define IVStylusDeviceSelectionEditor_H

#include "IVInterfaces.h"
#include "IVStylusDeviceEditor.h"

class IVIStylusDevice;
class CATManipulator;
class CATMathTransformation;
class CATMathVector;
class CATPickPathList;
class CATPickPath;

//------------------------------------------------------------------------------

class ExportedByIVInterfaces IVStylusDeviceSelectionEditor : public IVStylusDeviceEditor
{
  CATDeclareClass;

public :

  /** Create a device editor that will modify the interactions.
   *  To be activated, the DeviceEditor has to be declared to the viewer.
   */
  IVStylusDeviceSelectionEditor(IVIStylusDevice * ipIDevice);

  /** Destruction of the stylus editor.
   */
   ~IVStylusDeviceSelectionEditor();
   
  /*
   * GetPriority returns a priority for the editor
   */
  virtual IVIStylusDeviceEditor::EditorPriority& GetPriority() { return _priority; };

  // CATDevice#Leave
  void Leave(); // Leave

  // CATDevice#PreActivation
  void PreActivation(bool iISPickRequested); // Preactivation with or without pick
  void PreActivation(CATManipulator* ipPointedManip, CATPickPathList& iPickPathList, CATPickPath& iPickPath); // Preactivation with pick result provided

  // CATDevice#ActivationAndBeginManipulation
  void ActivationAndBeginManipulation(); // ActivationAndBeginManipulation with pick
  void ActivationAndBeginManipulation(CATManipulator* ipPointedManip, CATPickPathList& iPickPathList, CATPickPath& iPickPath); // ActivationAndBeginManipulation with pick result provided

  // CATDevice#Manipulation
  void Manipulation(); // Manipulation

  // CATDevice#EndManipulation
  void EndManipulation(); // EndManipulation with pick
  void EndManipulation(CATManipulator* ipPointedManip, CATPickPathList& iPickPathList, CATPickPath& iPickPath); // EndManipulation with pick result provided

protected :

  //  
  IVIStylusDeviceEditor::EditorPriority _priority;
};

//-----------------------------------------------------------------------

#endif
