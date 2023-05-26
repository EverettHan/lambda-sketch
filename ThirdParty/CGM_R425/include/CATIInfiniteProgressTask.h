
#ifndef CATIInfiniteProgressTask_H
#define CATIInfiniteProgressTask_H

// COPYRIGHT DASSAULT SYSTEMES 2010

#include "CATAfrProgressTask.h"
#include "CATBaseUnknown.h"
#include "CATIProgressTaskCusto.h"
#include "CATCallbackManager.h"
#include "CATEventSubscriber.h"
#include "CATProgressTaskCustoEnum.h"

class CATCallbackManager;
class CATUnicodeString;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrProgressTask IID IID_CATIInfiniteProgressTask;
#else
extern "C" const IID IID_CATIInfiniteProgressTask;
#endif


/**
* Interface representing the infinite progress task.
*
*<br> Sample *<br> ...
*<br> ...
*<br> CATIInfiniteProgressTask * piTask = NULL;
*<br> CATInstantiateComponent ("CATInfiniteProgressTask",
*<br>                          IID_CATIInfiniteProgressTask,
*<br>                          (void **)&piTask);
*<br> if( piTask )
*<br> {
*<br>    rc = piTask->Initialize( ..., ..., ...);
*<br>    if( SUCCEEDED(rc) )
*<br>    {
*<br>      piTask->Start( );
*<br>      ...;
*<br>    }
*<br>    piTask->Release(); piTask = NULL,
*<br> }
*<br>
*
*/
//-----------------------------------------------------------------------------
class ExportedByCATAfrProgressTask CATIInfiniteProgressTask: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

    /**
    * Initialize the Progress Task UI.
    * @param iCatalogName
    * <br><b>Role:</b>This NLS file contains the information needed to customize the
    * dialog box. The keywords are the following:
    * <ul>
    * <li>The title : <tt>ProgressTaskUI.Title</tt></li>
    * <li>The comment above the progress bar: <tt>ProgressTaskUI.Comment</tt></li>
    * <li>The Object concerned by the task : <tt>ProgressTaskUI.ObjectName</tt></li>
    * </ul>
    * The comment and object can be customized at run time by using 
    * the @href CATIProgressTaskUI#SetComment and  @href CATIProgressTaskUI#SetObject methods. 
    * @param oCatalogName
    * The NLS filename without the suffix can be found in the 
    * CNext/resources/msgcatalog directory.
    * <ul>
    * @param iIcon
    * The icon displayed in the dialog box symbolizing the task. The
    * name of the icon can be found in the CNext/resources/graphic/icons/normal 
    * directory, without the <tt>".bmp"</tt> suffix. 
    * <ul>
    * @param iPos
    * Define the position of the progress task. 
    */
    virtual HRESULT Initialize( const CATString& iCatalogName, 
                                const CATString& iIcon, 
                                const CATAfrProgressTaskPosition& iPos = ScreenCenter, 
                                const CATBoolean& iInterruptible = FALSE, 
                                const CATAfrProgressTaskCIDType& iCircular = Circular ) = 0;

    /**
    * Start the infinite progress task.
    */  
    virtual HRESULT Start( ) = 0;

    /**
    * Cancel the infinite progress task.
    */  
    virtual HRESULT Cancel( ) = 0;

    /**
    * Sets a runtime comment.
    * <br><b>Role:</b>The default comment is the one set in the NLS file
    * defined by @href CATIProgressTask#GetCatalogName. The keyword associated 
    * with this message is <tt>CATIProgressTask.Comment</tt>. With this method, you can 
    * customize the comment at the beginning of a task or during a step. See the
    * @href CATIProgressTask#PerformTask method.
    */
    virtual HRESULT SetComment( const CATUnicodeString & iComment ) = 0;

    /**
    * Retrieves the Call Back Manager.
    *   @param opManager
    *  @return  
    *  A  <tt>HRESULT</tt>  
    *  <dl>  
    *  <dt>  <tt>S_OK</tt>                        <dd>  Done  
    *  <dt>  <tt>E_FAIL</tt>                        <dd>  Fails. 
    *  </dl>  
    */
    virtual HRESULT GetCallbackManager( CATCallbackManager** opManager ) = 0;

    /**
    * Retrieves the Cancel Event Notification.
    *  </dl>  
    */
    virtual CATCallbackEvent GetCancelNotification( ) = 0;
};
#endif
