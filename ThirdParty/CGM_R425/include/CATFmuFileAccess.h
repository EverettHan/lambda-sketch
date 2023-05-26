/* -*-c++-*- */
// -------------------------------------------------------------------
// CATIA(c) Copyright Dassault Systemes 2005
//---------------------------------------------------------------------
/**
 * @level Protected
 * @usage U1
 */
//---------------------------------------------------------------------
// Responsable: JBT
//---------------------------------------------------------------------
// CATFmuFileAccess.cpp
//---------------------------------------------------------------------
// 
//  Services for File Access dialog
//
//---------------------------------------------------------------------
// Historique:
// Creation     : October 2005   YPR
// Review       : December2005   JBT
//---------------------------------------------------------------------
#ifndef CATFmuFileAccess_H
#define CATFmuFileAccess_H

#include "ExportedByCATFmuFileAccess.h"
#include "CATString.h"

class CATDialog;
class CATIFmuDialogBox;
class CATUnicodeString;
/**
 * This class has only one function which creates a dialog box of the file menu in the curent document environment.
 */
class ExportedByCATFmuFileAccess CATFmuFileAccess
{
   public :
   /**
   * Creates a dialog box of the file menu in the curent document environment.
   * <br><b>Role</b>: Creates a dialog box of the file menu.
   * @param ipDlgParent
   *   The parent class in the CATCommand agregation
   *   hierarchy. The parent must be an instance of a class that derives
   *   from CATDlgInteractiveApplication or CATDlgDocument.
   *   The notifications are first sent to it.<br>
   *   If the caller is a @href CATCommand and not a @href CATDialog, you should call<pre>
   *      CATCommand *pCmd = pDlgBox->GetEventPublisher();
   *      pCmd->SetFather(<the caller>);</pre>
   *   in order to let the caller recieve the notifications.
   * @param iDialogObjectName
   *   The dialog object name.
   * @param iStyle
   *   The application window styles. You can cumulate several
   *   styles using a logical or.
   *   <br><b>Legal values</b>: <tt>NULL (default)</tt> so that the
   *   file window features the OK and Cancel push buttons (it is dedicated
   *   to opening files), or <tt>CATDlgWndModal</tt> if, in addition to the default
   *   style, the file window is modal (that is, no interaction is possible outside
   *   this window as long as it is displayed), or <tt>CATDlgWndAPPLY</tt>
   *   if, in addition to the default style, the file window features
   *   the Apply push button, or <tt>CATDlgWndHELP</tt>
   *   if, in addition to the default style, the file window features
   *   the Help push button, or <tt>CATDlgFileSave</tt>
   *   if the file window is dedicated to saving files.
   *   (the Open push button is replaced by the Save push button),
   *   or <tt>CATDlgFileMultisel</tt> if the file window enables the
   *   file multiple selection.
   * @param oDialogBox [out, CATBaseUnknown#Release]
   *    The created dialog box.
   * @return
   * The status call
   * <br><b>Legal values</b>: S_OK, E_FAIL,
   */

   static HRESULT CreateDialogBox ( CATDialog        *  iDialogFather,
                                    const CATString  &  iDialogName,
                                    unsigned long       iStyle,
                                    CATIFmuDialogBox *& oDialogBox);
   
   /**
   * Creates a dialog box of the file menu in the curent document environment.
   * CreateUnicodeDialogBox method usage is reserved to Solidworks and any future usage is to be validated by the team in charge.
   * Method usage is FORBIDDEN by default for all CATIA file types (V5 and V4).No check will be made at the implementation level
   * If this rule is broken: this is the caller's responsibility.
   * Method is relevant only for “Save”
   */
   static HRESULT CreateUnicodeDialogBox ( CATDialog        *  iDialogFather,
                                    const CATString  &  iDialogName,
                                    unsigned long       iStyle,
                                    CATIFmuDialogBox *& oDialogBox);
   private :
   CATFmuFileAccess();
   ~CATFmuFileAccess();
};

#endif
