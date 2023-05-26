#ifndef __CATIInteractiveCommand_h
#define __CATIInteractiveCommand_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATBaseUnknown.h"
#include "CATBoolean.h"
#include "CATAfrItf.h"

/**
  * This flags sets the command's behaviour to the default. The default 
  * behaviour leads the command's cancelation when it has the focus in 
  * an editor that gets deactivated.
  */
#define CATFrmDefaultBehaviour             0

/**
  * When this flag is set on a command, the command will not be 
  * canceled when it has the focus in an editor that gets deactivated. 
  * This is _not_ the default behaviour.
  *
  * This flag is mainly reserved for CATOtherDocumentAgent usages which let
  * people make selection in other editors.
  * Don't use it in other cases as clients are used to the cancellation of
  * commands when leaving an editor which is the standard behavior.
  * Also, it could lead to several issues or inconsistencies with undo/redo
  * capability for example.
  */
#define CATFrmNotCanceledOnEditorDeactivated  (1 << 0)

/**
  * This flag is ignored if CATFrmNotCanceledOnEditorDeactivated
  * is not set. When this flag is set on a command, the command will
  * keep on receive notifications when its editor gets deactivated.
  * This is _not_ the default behaviour.
  */
#define CATFrmNotDumbOnEditorDeactivated      (1 << 1)

extern ExportedByCATAfrItf IID IID_CATIInteractiveCommand;

/**
  * @nodoc
  * Interface allowing information retrieval about a command's ui context.
  * <b>Role : </b> associating a @href CATCommandHeader to a @href CATCommand
  */
class ExportedByCATAfrItf CATIInteractiveCommand: public CATBaseUnknown {

  CATDeclareInterface;

public:

  /**
    * @nodoc
    * Sets the behaviour of a command instanciated under an editor.
    * @param a combination of CATFrmNoXXXOnEditorDeactivated flags.
    */
  virtual void    SetBehaviour   (unsigned long iFlags) = 0;

  /** 
    * @nodoc
    * Tells whether one of the CATFrmNoXXXOnEditorDeactivated flags
    * is set on the command.
    * @return
    * returns TRUE if the passed in flag is set, FALSE otherwise.
    */
  virtual CATBoolean IsBehaviourSet (unsigned long iFlag) = 0; 

};

#endif//__CATIInteractiveCommand_h
