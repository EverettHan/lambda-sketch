//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2010
//===================================================================
// CATExtIAfrDnDExternalObject.cpp
// Header definition of class CATExtIAfrDnDExternalObjects
//===================================================================
//
// Usage notes: Adapter for interface CATIAfrDnDExternalObjects
//
//===================================================================
//  2010/12/30 Creation: ERS
//===================================================================

#ifndef CATExtIAfrDnDExternalObject_H
#define CATExtIAfrDnDExternalObject_H

#include "CATAfrItf.h"
#include "CATIAfrDnDExternalObjects.h"

//-----------------------------------------------------------------------

class ExportedByCATAfrItf CATExtIAfrDnDExternalObjects: public CATIAfrDnDExternalObjects
{
  public:

    CATDeclareClass;

    // Standard constructors and destructors
    // -------------------------------------
    CATExtIAfrDnDExternalObjects ();
    virtual ~CATExtIAfrDnDExternalObjects ();

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


  private:

    // Copy constructor and equal operator
    // -----------------------------------
    CATExtIAfrDnDExternalObjects (CATExtIAfrDnDExternalObjects &);
    CATExtIAfrDnDExternalObjects& operator=(CATExtIAfrDnDExternalObjects&);
};

//-----------------------------------------------------------------------

#endif
