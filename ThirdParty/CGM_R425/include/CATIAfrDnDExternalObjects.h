//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2010/12/30
//===================================================================
// CATIAfrDnDExternalObjects.cpp
// Header definition of class CATIAfrDnDExternalObjects
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2010/12/30 Creation: ERS
//===================================================================
#ifndef CATIAfrDnDExternalObjects_H
#define CATIAfrDnDExternalObjects_H

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"
#include "CATAfrInterfaceAdapter.h"
#include "CATCollec.h"

#ifndef _WINDOWS_SOURCE
#ifndef UIUTIL_H
typedef  struct  _POINTL
{  
        int x;
        int y;
}POINTL;  
#endif
#endif

extern ExportedByCATAfrItf  IID IID_CATIAfrDnDExternalObjects ;

/**
* Interface representing Protocol for a V6 application to subscribe to the drop user action on the application so that the application can realize the right action to manage the dropped document.
*
* <br><b>Role</b>: see http://codewiki/codewiki/index.php?title=DnD:_How_to_manage_file_drops_on_a_V6_Application
* <br> 
* <b>Important notice</b>: Using the @href CATExtIAfrDnDExternalObjects as a base class
* when implementing <tt>CATIAfrDnDExternalObjects</tt> is mandatory. Else your implementation will be ignored.
* <br> A C++ derivation and an Object Modeler derivation (CATImplementClass) are required,
* else your implementation will be ignored.
* <br> Use CATImplementBOA to implement this interface, TIE implementations are not supported.
*/


class ExportedByCATAfrItf CATIAfrDnDExternalObjects: public CATBaseUnknown
{
CATDeclareInterface;
CATDeclareAdapter (CATIAfrDnDExternalObjects);

public:

    /**
     * This method will be called when a drag begins.
     * <br> If your implementation is a visual object the drag begins when entering the object representation.
     * If your implementation is a workbench, a workshop or an application the drag begins when entering the Application Frame.
     * @param iFilePaths 
     *   The dragged objects (file paths).
     * @param iPosition 
     *   The current position.
     * @return
     *   A  return  code. 
     *   <ol> 
     *   <li>  0  means  you  correctly  manage  the  operation.  No  other  implementation  of  this  interface  will  be  called. 
     *   <li>  Any  other  value  means  you  could  not  manage  the  operation.  Other  implementations  of  this  interface  will  be  searched  and  called. 
     *   </ol> 
     */
    virtual int BeginDragExternalObjects (CATListOfCATUnicodeString * iFilePaths, POINTL iPosition) = 0;

    /**
     * This method will be called when a drag continues.
     * @param iFilePaths 
     *   The dragged objects (file paths).
     * @param iPosition 
     *   The current position.
     * <br> If your implementation is a visual object iPosition is not set.
     * @return
     *   A  return  code. 
     *   <ol> 
     *   <li>  0  means  you  correctly  manage  the  operation.  No  other  implementation  of  this  interface  will  be  called. 
     *   <li>  Any  other  value  means  you  could  not  manage  the  operation.  Other  implementations  of  this  interface  will  be  searched  and  called. 
     *   </ol> 
     */
    virtual int DragExternalObjects (CATListOfCATUnicodeString * iFilePaths, POINTL iPosition) = 0;

    /**
     * This method will be called when a drag ends.
     * @param iFilePaths 
     *   The dragged objects (file paths).
     * @return
     *   A  return  code. 
     *   <ol> 
     *   <li>  0  means  you  correctly  manage  the  operation.  No  other  implementation  of  this  interface  will  be  called. 
     *   <li>  Any  other  value  means  you  could  not  manage  the  operation.  Other  implementations  of  this  interface  will  be  searched  and  called. 
     *   </ol> 
     */
    virtual int EndDragExternalObjects (CATListOfCATUnicodeString * iFilePaths) = 0;

    /**
     * This method will be called when a drop occurs.
     * @param iFilePaths 
     *   The dropped objects (file paths).
     * @param iPosition 
     *   The drop position.
     * @param oUserFeedback 
     *   A message to be displayed to the user after the drop.
     *   This message could explain an error in the drop process (in case the return code is not 0),
     *   or explain what the drop operation did.
     *   In case your return code is not 0, if another implementations of the interface are found and called,
     *   only the message of the last called implementation will be taken into account.
     * @return
     *   A return code.
     *   <ol>
     *   <li> 0 means you correctly managed the drop operation. No other implementation of this interface will be called.
     *   <li> Any other value means you could not manage the drop operation. Other implementations of this interface will be searched and called.
     *   </ol>
     */
    virtual int DropExternalObjects (CATListOfCATUnicodeString * iFilePaths, POINTL iPosition, CATUnicodeString & oUserFeedback) = 0;

};

//-----------------------------------------------------------------------

#endif
