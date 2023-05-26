//===================================================================
// COPYRIGHT Dassault Systemes 2020/05/14
//===================================================================
// Header definition of class IVExtIStylusDeviceEditor
//===================================================================
//
// Usage notes: Default Implementation of IVIStylusDeviceEditor
//              All implementations of IVIStylusDeviceEditor should inheritate from this class
//
//===================================================================
//  2020/05/14 Creation
//===================================================================
#ifndef IVExtIStylusDeviceEditor_H
#define IVExtIStylusDeviceEditor_H

#include "IVInterfaces.h"
#include "IVIStylusDeviceEditor.h"
#include "CATLISTP_IVGestureRecognizer.h"
#include "IVGestureRecognizer.h"
#include <vector>
#include <utility>

class IVIStylusDevice;
class CATManipulator;
class CATNotification;
class IVGestureRecognizer;
class IVGesture;

//-----------------------------------------------------------------------

class ExportedByIVInterfaces IVExtIStylusDeviceEditor: public IVIStylusDeviceEditor
{

   CATDeclareClass;

public:

  IVExtIStylusDeviceEditor(IVIStylusDevice * iIpDevice);
  virtual ~IVExtIStylusDeviceEditor();

  /*
   * GetStylusDevice returns the stylus device
   */
  IVIStylusDevice* GetStylusDevice();

  /*
   * GetActionForInteraction returns a function called action that will be executed
   *  when a given interaction is detected
   */
  virtual std::vector<std::pair<IVStylusDeviceAction, const IVGesture*>> GetActionsForInteraction(CATNotification * ipEvent, CATManipulator * ipPointedManipulator, CATManipulator * ipPlugedManipulator);

  /*
   * GetActionForInteraction returns a function called action that will be executed
   *  when a given interaction is detected
   */
  virtual IVStylusDeviceAction GetActionForBehaviorStep(CATManipulator * ipPointedManipulator, CATManipulator * ipPlugedManipulator);
  
  /*
   * GetPriority returns a priority for the editor
   */
  virtual IVIStylusDeviceEditor::EditorPriority& GetPriority();

  /*
   * IsInTransaction is called after an Action given by this editor is performed.
   * IsInTransaction should answer false every time the editor finished completely
   * with the given interaction.
   * Please be aware that if IsInTransaction answers true, then this editor becomes
   * priotary to other editors and no other condition is tested on this.
   * IsInTransaction is meant for complex editors that need to be activated even
   * if the activating condition is no more true. Please cf CATMouseEditorForDrill
   */
  virtual CATBoolean IsInTransaction();

  /*
   * AddGestureRecognizer/RemoveGestureRecognizer/GetGestureRecognizer/GetGestureRecognizerOnDeviceCount manages
   * a list of gestures to recognize for this editor.
   * It adds them to the stylus device.
   */
  void AddGestureRecognizer(IVGestureRecognizer* ipGestureRecognizer);
  void RemoveGestureRecognizer(IVGestureRecognizer* ipGestureRecognizer);
  IVGestureRecognizer* GetGestureRecognizer(int iIndex);
  int GetGestureRecognizerCount();

  /*
   * GetGestureRecognizerOnDevice/GetGestureRecognizerOnDeviceCount gets
   the gestures added on the stylus device.
   */
  IVGestureRecognizer* GetGestureRecognizerOnDevice(int iIndex);
  int GetGestureRecognizerOnDeviceCount();

private :

  IVIStylusDevice * _pIDevice;
  CATLISTP(IVGestureRecognizer) _gestureRecognizerListP;
};

//-----------------------------------------------------------------------

#endif
