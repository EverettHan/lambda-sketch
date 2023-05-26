/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES	2001
#ifndef _CATILightEditCommand_h
#define _CATILightEditCommand_h

#include "CATBaseUnknown.h"
class CATNotification;

/**
 * Interface to manipulate light edit commands.
 * <b>Role</b>: 
 */
#include "CATInteractiveInterfaces.h"
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATInteractiveInterfaces IID IID_CATILightEditCommand;
#else
extern "C" const IID IID_CATILightEditCommand;
#endif
 
class ExportedByCATInteractiveInterfaces CATILightEditCommand : public CATBaseUnknown
{
public:
  CATDeclareInterface;

   /**
    * Display panel with command option, this panel should only have a close button
    * @return
    * The status call
    * <br><b>Legal values</b>: S_OK, E_FAIL
    */
   virtual HRESULT DisplayLighEditOptionPanel() = 0;

   /**
    * Return object edited be command.
    * This method is necessary to avoid to launch several time a command on same object
    * @param oWorkingObject
    *   Your working object, you should perform an AddRef on object
    * @return
    * The status call
    * <br><b>Legal values</b>: S_OK, E_FAIL
    */
   virtual HRESULT GetLightEditWorkingObject(CATBaseUnknown** oWorkingObject) = 0;

   /**
    *  These methods are called if undo are requested in Select command
    * @return
    * The status call
    * <br><b>Legal values</b>: S_OK, E_FAIL
    */
   virtual HRESULT LightEditUndo() = 0;

   /**
    *  These methods are called if redo are requested in Select command
    * @return
    * The status call
    * <br><b>Legal values</b>: S_OK, E_FAIL
    */
   virtual HRESULT LightEditRedo() = 0;

   /**
    *  Notification event for manipulation start
    */
   virtual CATNotification* GetBeginManipulateNotif() = 0;

   /**
    *  Notification event for manipulation end
    */
   virtual CATNotification* GetEndManipulateNotif() = 0;

};

#endif
