#ifndef CATDLGBOX_H
#define CATDLGBOX_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATDialog.h"

class CATString;
class CATDlgContextualMenu;

#ifndef CATDlgBox_ADD
/** @nodoc */
#define CATDlgBox_ADD
#endif

#ifndef CATDlgBox_LateADD
/** @nodoc */
#define CATDlgBox_LateADD
#endif

/** 
 * Base class for all boxes, that is objects that are contained in a given object and that contain other objects.
 * <b>Role</b>:
 * This class is the box object base class to gather dialog components in 
 * consistent sets inside a dialog window. These components are usually controls, 
 * but a box can often contain boxes.<br>
 * This class cannot be instantiated.<br>
 * Its derived classes are @href CATDlgContainer, @href CATDlgSplitter, @href CATDlgTabContainer, 
 * @href CATDlgTabPage, @href CATDlgFrame and @href CATDlgIconBox.<br>
 * The parent of an instance of a class that derives from CATDlgBox must be an instance of a class
 * that derives from @href CATDlgDocument, @href CATDlgDialog or also CATDlgBox.
 */
class ExportedByDI0PANV2 CATDlgBox : public CATDialog
{

 public:

        /**
        * Returns the contextual menu of the box if any.
        */
        CATDlgContextualMenu* GetContextualMenu();

       /**
        * @nodoc
        * Requests the ClassName, IsA, and IsAKindOf methods to be created.
        */
        CATDeclareClass ;

 protected:

        /** 
        * Constructs a CATDlgBox.
        * @param iParent
        *   The parent of the box.
        * @param iObjectName
        *   The name of the box.
        * @param iStyle
        *   The style of the box.
        */
        CATDlgBox( CATDialog *iParent, const CATString& iObjectName, CATDlgStyle iStyle=NULL);

        virtual ~CATDlgBox();

        /** @nodoc */
        CATDlgBox_ADD
};

/** @nodoc */
CATDlgBox_LateADD

#endif
