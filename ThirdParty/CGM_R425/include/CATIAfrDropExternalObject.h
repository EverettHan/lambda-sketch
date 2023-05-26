// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATIAfrDropExternalObject.h
// Define the CATIAfrDropExternalObject interface
//
//===================================================================
//
// Usage notes: see http://codewiki/codewiki/index.php?title=How_to_manage_file_drops_on_a_V6_Application
/* Protocol for a V6 application to subscribe to the drop user action on the application so that the application can realize the right action to manage the dropped document.

== ApplicationFrame infrastructure ==

Only applications that instanciate a CATApplicationDocument may use this protocol. Notice that instanciating a CATApplicationFrame instanciates a CATApplicationDocument.
CATApplicationDocument infrastructure class subscribes to the drop event. In the event management, it calls the application on a specific interface: CATIAfrDropExternalObject, giving the drop notification.
This implementation MUST use the interface adapter: CATExtIAfrDropExternalObject.

== Application ==

Any Workshop and Workbench can implement the interface on its late type
(for example, Part Design workbench may implement CATIAfrDropExternalObject on PrtCfg_AfrDropOnApplication type).
Any class derived from CATInteractiveApplication may also implement the interface.
This implementation will be called if the Drop occurs when no workbench is opened.

If the current workbench implements the interface and returns no error,
the implementation on the current workshop and/or on the current Application is ignored.
The implementation on the Application will be called only if the current Workbench
and the current Workshop have no implementation or their implementation returns an error code.

Please keep in mind you must not implement this interface on a workbench
or on a CATInteractiveApplication if you are not the main responsible for it.
*/
//
//===================================================================
//
//  Feb 2009  Creation: Code generated by the CAA wizard  ERS
//===================================================================
#ifndef CATIAfrDropExternalObject_H
#define CATIAfrDropExternalObject_H

#include "CATAfrItf.h"
#include "CATIAfrDropOnApplication.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrItf IID IID_CATIAfrDropExternalObject;
#else
extern "C" const IID IID_CATIAfrDropExternalObject ;
#endif

class CATNotification;
class CATUnicodeString;

//------------------------------------------------------------------

/**
* Interface representing Protocol for a V6 application to subscribe to the drop user action on the application so that the application can realize the right action to manage the dropped document.
*
* <br><b>Role</b>: see http://codewiki/codewiki/index.php?title=DnD:_How_to_manage_file_drops_on_a_V6_Application
* <br> 
* IMPORTANT: See also CATIAfrDnDExternalObjects interface for enhanced capabilities.
* <br> 
* <b>Important notice</b>: Using the @href CATExtIAfrDropOnApplication as a base class
* when implementing <tt>CATIAfrDropExternalObject</tt> is mandatory. 
*/
class ExportedByCATAfrItf CATIAfrDropExternalObject: public CATIAfrDropOnApplication
{
  CATDeclareInterface;

  public:

    /**
     * This method will be called when a drop occurs on the application.
     * <br> Query the input notification for informations about the dropped object.
     * @param ipDropNotif 
     *   The drop notification. Should be a CATDlgDroppedFileNotification in V6, but please check it before casting.
     * @param oUserFeedback 
     *   A message to be displayed to the user after the drop.
     *   This message could explain an error in the drop process (in case the return code is not 0),
     *   or explain what the drop operation did.
     *   In case your return code is not 0, if another implementations of the interface are found and called,
     *   only the message of the last called implementation will be taken into account.
     * @return
     *   A return code.
     *  <ol>
     *  <li> 0 means you correctly manage the drop operation. No other implementation of this interface will be called.
     *  <li> Any other value means you could not manage the drop operation. Other implementations of this interface will be searched and called.
     *  </ol>
     */
    virtual int DropOnApplication (CATNotification * ipDropNotif, CATUnicodeString & oUserFeedback) = 0;


  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};

//------------------------------------------------------------------

#endif
