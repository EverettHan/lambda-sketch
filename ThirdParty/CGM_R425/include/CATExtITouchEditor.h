//===================================================================
// COPYRIGHT Dassault Systemes 2018/05/14
//===================================================================
// CATExtITouchEditor.cpp
// Header definition of class CATExtITouchEditor
//===================================================================
//
// Usage notes: Default Implementation of CATITouchEditor
//              All implementations of CATITouchEditor should inheritate from this class
//              or implement all methods of CATITouchEditor
//
//===================================================================
//  2018/05/14 
//===================================================================
#ifndef CATExtITouchEditor_H
#define CATExtITouchEditor_H

#include "CATVisItf.h"
#include "CATBaseUnknown.h"
#include "CATEventSubscriberTypedefs.h"
#include "CATITouchEditor.h"
#include "CATListOfInt.h"
class CATNotification;
//class CATSubscriberData;
class CATManipulator;


/** @nodoc 
*  WARNING : this class is defined in VisualizationInterfaces framework */

//class ExportedByCATVisItf CATExtITouchEditor: public CATBaseUnknown
class ExportedByCATVisItf CATExtITouchEditor: public CATITouchEditor
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
     CATExtITouchEditor();
    virtual ~CATExtITouchEditor();

    virtual CATTouchDeviceAction GetActionForInteraction ( CATNotification *ievent, CATSubscriberData data, CATManipulator * iPointed,  CATManipulator * iPluged) = 0;
   // virtual CATDeviceAction GetActionForInteraction (CATTouchInteraction_Id ident, CATNotification *ievent, CATSubscriberData data, CATManipulator * iPointed,  CATManipulator * iPluged, int iGeneralModifiers );
    virtual CATITouchEditor::InteractorPriority& GetPriority () = 0;
    virtual CATBoolean IsNeeded (int iGeneralModifiers);
    virtual CATBoolean IsInTransaction ();
    virtual int GetKeyState (int iCATKeyCode);

    virtual void AddModifier (int iModifier);
    virtual void RemoveModifier (int iModifier);
    virtual CATListOfInt& GetListOfModifier ();

private :
  
    //int _currentModifier;
  CATListOfInt _modifiers;

};


#endif
