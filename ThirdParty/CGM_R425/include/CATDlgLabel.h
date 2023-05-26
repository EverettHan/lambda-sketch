#ifndef CATDLGLABEL_H
#define CATDLGLABEL_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


//------------------------------------------------------------------------------
// Abstract: The base class for simple text display
//
//------------------------------------------------------------------------------
// Usage:    Like any control, assign CATDlgLabel to any container or window.
//------------------------------------------------------------------------------
// Inheritance: CATDlgLabel
//                CATDlgControl
//                  CATDialog
//------------------------------------------------------------------------------
// Main methods:
//
//------------------------------------------------------------------------------
// Styles:
//
//           CATDlgLabCenter
//           CATDlgLabLeft
//           CATDlgLabRight
//           CATDlgLabFramed
//------------------------------------------------------------------------------

//--------------------------------------------------------------------------
#include "CATDlgControl.h"

//--------------------------------------------------------------------------
class CATString;
class l_CATDialog;
class l_CATDlgLabel;

#ifndef CATDlgLabel_ADD
/** @nodoc */
#define CATDlgLabel_ADD
#endif

#ifndef CATDlgLabel_LateADD
/** @nodoc */
#define CATDlgLabel_LateADD
#endif

//--------------------------------------------------------------------------

/**
 * Class to add an information text to a control.
 * <b>Role</b>: Adds an information text to a control.
 * The label is dedicated to add an information text or an image to controls 
 * and to other objects as well. The text can be parameterized with data 
 * coming from the application. Some controls, such as a push button, a radio 
 * button, or a check button, and frames, have a text companion you can set 
 * using its Title resource. On the opposite, a combo or a spinner doesn't 
 * display its title. You can then use labels to inform the end user of what 
 * the combo or spinner is intended to do, or which variable it can set. The 
 * labels in the figure beside are associted with a combo (Form Name), and 
 * editors. The other texts are either frame titles, push button titles, or 
 * a bitmap combo line mixing a bitmap and the text "User".
 * <p>
 * Use labels whenever you want to qualify a control or add information to 
 * explain its purpose.
 */

class ExportedByDI0PANV2 CATDlgLabel : public CATDlgControl
{

//--------------------------------------------------------------------------
 public:

//      constructor - destructor
/**
 * Constructs a label.
 * <br><b>Role</b>: Constructs a label. 
 * @param iParent
 *   The parent of the label.
 * @param iDialogObjectName
 *   The dialog object name. 
 * @param iStyle
 *   The application window styles. You can cumulate several
 *   styles using a logical or.
 *   <br><b>Legal values</b>:
 *  <ul>
 *   <li><tt>CATDlgLabLeft</tt> if the label text is left justified</li>
 *   <li><tt>CATDlgLabRight</tt> if the label text is right justified</li>
 *   <li><tt>CATDlgLabCenter</tt> if the label text is centered</li>
 *   <li><tt>CATDlgLabFramed</tt> if the label text is framed</li>
 *  </ul>
 */
        CATDlgLabel( CATDialog *iParent, const CATString& iDialogObjectName, 
                     CATDlgStyle iStyle=NULL);
/**
 * @nodoc 
 */
        virtual ~CATDlgLabel();

//      get internal object
/**
 * @nodoc 
 */
        virtual l_CATDialog* GetLetterObject();

//      resets the internal object.
/**
 * @nodoc 
 */
        virtual void ResetLetterObject();

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
        l_CATDlgLabel* _frameLabel;

        /** @nodoc */
        CATDlgLabel_ADD
};

/** @nodoc */
CATDlgLabel_LateADD

#endif
