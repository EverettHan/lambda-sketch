
#ifndef CATIProgressTaskCusto_H
#define CATIProgressTaskCusto_H

// COPYRIGHT DASSAULT SYSTEMES 2010

#include "CATAfrProgressTask.h"
#include "CATIProgressTask.h"
#include "CATProgressTaskCustoEnum.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrProgressTask IID IID_CATIProgressTaskCusto;
#else
extern "C" const IID IID_CATIProgressTaskCusto;
#endif


/**
* Interface describing an interruptible task.
* <b>Role</b>:Objects executing a long process implement this interface
* to benefit from a user interface indicating the progression 
* of the task. The process must be launched by the 
* @href CATTaskController#Schedule method.
* <br>The user interface is a dialog box which contains:
* <ul>
* <li>A title</li>
* <li>A Progress bar</li>
* <li>An icon symbolizing the task</li>
* <li>The name of the object concerned  by the task</li>
* <li>A comment just above the progress bar</li>
* <li>If the task is interruptible, a Cancel button is added 
* and the end user can stop the process.</li>
* <li>A percentage indicating the progression</li>
* <li>An estimate of the remaining time</li>
* </ul>
* @see CATIProgressTaskUI, CATTaskController
*/
//-----------------------------------------------------------------------------
class ExportedByCATAfrProgressTask CATIProgressTaskCusto: public CATIProgressTask
{
  CATDeclareInterface;

  public:

    /**
    * Returns the progress task mode.
    * @param oTaskMode
    */  
    virtual HRESULT GetProgressTaskMode( CATAfrProgressTaskMode& oTaskMode ) = 0;

    /**
    * Returns the window mode.
    * @param oTaskMode
    */  
    virtual HRESULT GetTaskWindMode( CATAfrProgressTaskWindMode& oTaskMode ) = 0;

    /**
    * Returns the Panel style.
    * @param oTaskMode
    */  
    virtual HRESULT GetPanelStyle( CATAfrProgressTaskPanelStyle& oTaskMode ) = 0;

    /**
    * Returns the Panel style.
    * @param oTaskMode
    */  
    virtual HRESULT GetImmersiveInfinitePosition( CATAfrProgressTaskPosition& oPosition ) = 0;

    /**
    * Returns the infinite progress task type.
    * @param oType
    */  
    virtual HRESULT GetInfiniteType( CATAfrProgressTaskCIDType& oType ) = 0;

    /**
    * Call when the progress task is Interrupted.
    */  
    virtual HRESULT OnInterrupt( ) = 0;

    /**
    * Returns the remaining display status.
    * Default Value is TRUE.
    * @param oDisplay
    */  
    virtual HRESULT GetRemaining( CATBoolean& oDisplay ) = 0;

};
#endif
