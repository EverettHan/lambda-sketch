//===================================================================
// COPYRIGHT Dassault Systemes 2020/05/14
//===================================================================
// Header definition of class IVIStylusDeviceEditor
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2020/05/14 Creation
//===================================================================
#ifndef IVIStylusDeviceEditor_H
#define IVIStylusDeviceEditor_H

#include "IVInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATEventSubscriberTypedefs.h"
#include "CATListOfInt.h"
#include "IVGestureRecognizer.h"
#include <vector>
#include <utility>
class CATNotification;
class CATManipulator;
class IVGesture;

extern ExportedByIVInterfaces  IID IID_IVIStylusDeviceEditor;

typedef int (CATBaseUnknown::*IVStylusDeviceAction)(CATNotification * ipEvent, CATManipulator * ipPointedManipulator, CATManipulator * ipPlugedManipulator, const IVGesture* iGesture);

class ExportedByIVInterfaces IVIStylusDeviceEditor : public CATBaseUnknown
{
  
  CATDeclareInterface;

public:


  // _value priority from 0 (lower priority) to higher values (maximum priority)
  enum PriorityType { Undefined = 0, Background = 1, Intermediate = 2, Foreground = 3 };
  struct EditorPriority
  {
    PriorityType _type;
    unsigned short _value;
  };

  /* 
   * GetActionForInteraction returns a function called action that will be executed 
   *  when a given interaction is detected
   */
  virtual std::vector<std::pair<IVStylusDeviceAction, const IVGesture*>> GetActionsForInteraction(CATNotification * ipEvent, CATManipulator * ipPointedManipulator, CATManipulator * ipPlugedManipulator) = 0;

  /*
   * GetActionForBehaviorStep returns a function called action that will be executed
   *  when a given interaction is detected
   */
  virtual IVStylusDeviceAction GetActionForBehaviorStep(CATManipulator * ipPointedManipulator, CATManipulator * ipPlugedManipulator) = 0;
  
  /*
   * GetPriority returns a priority for the editor
   */
  virtual IVIStylusDeviceEditor::EditorPriority& GetPriority() = 0;

  /*
   * IsInTransaction is called after an Action given by this editor is performed.
   * IsInTransaction should answer false every time the editor finished completely 
   * with the given interaction.
   * Please be aware that if IsInTransaction answers true, then this editor becomes 
   * priotary to other editors and no other condition is tested on this. 
   * IsInTransaction is meant for complex editors that need to be activated even 
   * if the activating condition is no more true. Please cf CATMouseEditorForDrill
   */
    virtual CATBoolean IsInTransaction () = 0;

};

//-----------------------------------------------------------------------
CATDeclareHandler(IVIStylusDeviceEditor, CATBaseUnknown );

#endif
