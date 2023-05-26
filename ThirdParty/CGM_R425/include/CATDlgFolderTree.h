#ifndef CATDLGFOLDERTREE_H
#define CATDLGFOLDERTREE_H

// COPYRIGHT DASSAULT SYSTEMES 2003



//------------------------------------------------------------------------------
// Abstract: The base class for folder tree.
//
//------------------------------------------------------------------------------
// Usage:    Assign a CATDlgFolderTree to any other container or window.
//------------------------------------------------------------------------------
// Inheritance: CATDlgFolderTree
//                CATDlgControl
//                  CATDialog
//------------------------------------------------------------------------------
// Main methods:
//
//------------------------------------------------------------------------------
// Styles:
//
//------------------------------------------------------------------------------

//--------------------------------------------------------------------------
#include "CATDlgStandard.h"
#include "CATDlgControl.h"
#ifdef DRIVER_WINDOWS  

//--------------------------------------------------------------------------
class CATDialog;
class CATString;
class l_CATDialog;
class l_CATDlgFolderTree;
class CATUnicodeString;
//--------------------------------------------------------------------------
/**
 * Class to display the folder tree on Windows only.
 * <b>Role</b>: FolderTree displays the folder graph and allows to select
 * one of these folders.
 */

class ExportedByCATDlgStandard CATDlgFolderTree : public CATDlgControl
{

//--------------------------------------------------------------------------
 public:

//      constructor - destructor
/**
 * Constructs a class to display the folder tree on Windows only.
 * <br><b>Role</b>: Constructs a class to display the folder tree on Windows only.
 * @param iParent
 *   The parent class in the CATCommand agregation 
 *   hierarchy. 
 * @param iDialogObjectName
 *   The dialog object name. 
 * @param iStyle
 *   The application window styles. You can cumulate several
 *   styles using a logical or.
 *   <br><b>Legal values</b>: 
 *   <ul>
 *   <li><tt>CATDlgGridLayout</tt> if the 
 *   frame layout is managed using a grid.</li>
 *   </ul>
 */
        CATDlgFolderTree( CATDialog *iParent, const CATString& iDialogObjectName,
                     CATDlgStyle iStyle=NULL);
/**
 * @nodoc 
 */
        virtual ~CATDlgFolderTree();

/**
 * @nodoc
 * Get internal object.
 */
        virtual l_CATDialog* GetLetterObject();

/**
 * @nodoc
 * Resets internal object.
 */
        virtual void ResetLetterObject();

/**
 * @nodoc
 * Set the folder tree to this directory.
 */
		virtual void SetDirectory(const CATUnicodeString& iCurrentDirectory);

/**
 * @nodoc
 * Get the selected directory.
 */
		virtual void GetDirectory(CATUnicodeString& oCurrentDirectory);

/** 
 * Returns the GetFolderSelectNotification event notification.
 * It is sent by CATDlgFolderTree whenever 
 * a directory is selected.
 */
		CATNotification *GetFolderSelectNotification() const;

/**
 * @nodoc
 * Requests the ClassName, IsA, and IsAKindOf methods to be created.
 */
        CATDeclareClass ;

//--------------------------------------------------------------------------
 private:

//      address of internal object.
/**
 * @nodoc 
 */
        l_CATDlgFolderTree* _paFolderTree;

};
#endif
#endif
