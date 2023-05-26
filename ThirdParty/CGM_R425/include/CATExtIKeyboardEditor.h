//===================================================================
// COPYRIGHT Dassault Systemes 2016/01/15
//===================================================================
// CATExtIKeyboardEditor.cpp
// Header definition of class CATExtIKeyboardEditor
//===================================================================
//
// Usage notes: Default Implementation of CATIKeyboardEditor
//              All implementations of CATIKeyboardEditor should inheritate from this class
//              or implement all methods of CATIKeyboardEditor
//
//===================================================================
//  2016/01/15 Creation: Code generated by the 3DS wizard
//===================================================================
#ifndef CATExtIKeyboardEditor_H
#define CATExtIKeyboardEditor_H

#include "CATVisItf.h"
#include "CATBaseUnknown.h"
#include "CATEventSubscriberTypedefs.h"
#include "CATIKeyboardEditor.h"
#include "CATListOfInt.h"
class CATNotification;
//class CATSubscriberData;
class CATManipulator;



//class ExportedByCATVisItf CATExtIKeyboardEditor: public CATBaseUnknown
class ExportedByCATVisItf CATExtIKeyboardEditor: public CATIKeyboardEditor
{
 /**@nodoc */
   CATDeclareClass;
public:
  /*
    enum PriorityType {Undefined = 0, Background=1, Intermediate=2, Foreground=3};

    // _intermediateValue priority if from 0 (lower priority) to higher values (maximum priority)
    // WARNING: -1 is for internal usage only
    struct InteractorPriority{
        PriorityType _prioType;
        unsigned short _intermediateValue;
    };*/
     CATExtIKeyboardEditor();
    virtual ~CATExtIKeyboardEditor();

  
  enum PriorityType {Undefined = 0, Background=1, Intermediate=2, Foreground=3};
    struct InteractorPriority{
        PriorityType _prioType;
        unsigned short _intermediateValue;
    };

   virtual CATIKeyboardEditor::InteractorPriority& GetPriority ()=0;
   /*
    * IsNeeded determins if the condition to activate this editor is true.
    * for exemple if this editor is to be be activated with a particular condition,
    * then IsNeeded will test the condition . If IsNeeded returns TRUE then this editor
    * will be called to give an ActionForInteraction (GetActionForInteraction)
    */
    virtual CATBoolean IsNeeded ()=0;

    /*
    * IsInTransaction is called after an Action given by this editor is performed.
    * IsInTransaction should answer FALSE every time the editor finished completely 
    * with the given interaction.
    * Please be aware that if IsInTransaction answers TRUE, then this editor becomes 
    * priotary to other editors and no other condition is tested on this. 
    * IsInTransaction is meant for complex editors that need to be activated even 
    * if the activating condition is no more true. Please cf CATMouseEditorForDrill
    */
    virtual CATBoolean IsInTransaction ();

    /*
    * GetKeyState returns a status for a keyboard key : 1 = pressed, 0 = released
    * iCATKeyCode is a key CAT identifier. 
    */
    virtual int GetKeyState (int iCATKeyCode);

};


#endif
