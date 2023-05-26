#ifndef CATDlgToolsOptionsFrame_H
#define CATDlgToolsOptionsFrame_H

// COPYRIGHT DASSAULT SYSTEMES 2000

/**
 * @CAA2Level L1
 * @CAA2Usage U2
 */

#include "CATDlgStandard.h"
#include <CATDlgFrame.h>

/** @nodoc */
#define CATDlgToolsOptionsNoIcon         (1 << 0)
/** @nodoc */
#define CATDlgToolsOptionsInvisibleIcon  (1 << 1)
/** @nodoc */
#define CATDlgToolsOptionsBottomFrame    (1 << 2)

/**
 * Special frame to be used in the Tools/Options tab pages. 
 * <b>Role</b>:
 * The CATDlgToolsOptionsFrame enables you to define sections of 
 * standardized aspect within a tab page. 
 * <br><br>
 * Beware! The use of the <tt>CATDlgGridConstraints</tt> style is mandatory inside the ToolsOptions frame. 
 * <br>
 * The structure of the frame is as follows:
 * <pre>
 * Title -----Separator-----
 *       ___________________
 * Icon |                   |
 *      |                   |
 *      |   Options Frame   |
 *      |                   |
 *      |                   |
 *      |___________________|
 * ---Invisible Separator---
 * </pre>
 */
class ExportedByCATDlgStandard CATDlgToolsOptionsFrame : public CATDlgFrame
{
  /** @nodoc */
  CATDeclareClass;

public:

  /**
    * Constructs a Tools/Options frame.
    * @param iParent
    *    The parent of the frame.
    * @param iIdentifier
    *    The identifier of the frame. It enables you to set the frame title in a CATNls file. 
	* <pre>iIdentifier.<b>HeaderFrame.Global.</b>Title = "My Frame Title"; </pre>
	* <p>where:
    * <dl>
    * <dt><tt>iIdentifier</tt>
    * <dd>The identifier of the <tt>CATDlgToolsOptionsFrame</tt>
    * <dt><tt>HeaderFrame.Global</tt>
    * <dd>Required keyword
    * <dt><tt>Title</tt>
    * <dd>The keyword for a title
    * </dl>
    * @param iIconFileName
    *    The name of the file containing the associated icon without the extension. This file is stored in one 
	*    of the directories under CNext/resources/graphic.
    * @param iStyle
    *    The style of the frame. There are always a title and a separator at the top of the frame. The style
	*    manages the frame layout depending on whether there is an icon or not, and whether the frame is the last one.
	* <br><b>Legal Values:</b>
    *   <dl>
    *   <dt><tt>Default (NULL)</tt>
	*   <dd> The frame contains a visible icon and a bottom invisible separator.
    *   <dt><tt>CATDlgToolsOptionsNoIcon</tt>
	*   <dd> The frame doesn't contain any icon and the "Options Frame" is aligned with the title. 
	*    Set iIconFileName to "".
    *   <dt><tt>CATDlgToolsOptionsInvisibleIcon</tt>
	*   <dd> The frame doesn't contain any icon but the "Options Frame" is shifted as if there were an icon.
	*    Set iIconFileName to "".
    *   <dt><tt>CATDlgToolsOptionsBottomFrame</tt>
	*   <dd> To be used only for the last frame in the page. It removes the bottom invisible separator. 
    * </dl>
	* <p>The styles <tt>CATDlgToolsOptionsNoIcon</tt> and <tt>CATDlgToolsOptionsInvisibleIcon</tt> are
	* mutually exclusive. Each of them can be combined with 
	* the <tt>CATDlgToolsOptionsBottomFrame</tt> style. 

    */
  CATDlgToolsOptionsFrame(CATDialog *iParent,         const CATString &iIdentifier, 
                          const CATString &iIconFileName, CATDlgStyle iStyle=NULL);


  virtual ~CATDlgToolsOptionsFrame();


  /**
   * Returns the "Options Frame".
   * <br><b>Role</b>: To retrieve the frame into which you can include your own controls.
   * <br><br>If you wish the objects within the <tt>Options Frame</tt> to fit into the 
   * whole width, you need to invoke the command <tt>SetGridColumnResizable</tt> command. 
   * Here is a code example:
   * Let us consider the dialog class that includes <tt>CATDlgToolsOptionFrame</tt> instances. 
   * Suppose this class is named CATxxx   
   * <pre>
   * ...
   * CATDlgToolsOptionsFrame * pFrame1 = 
   *          new CATDlgToolsOptionsFrame(this, <b>"Frame1" </b>, 
   *                                      "I_MyIcon", CATDlgToolsOptionsBottomFrame);
   * CATDlgFrame *pOptionsFrame1 = pFrame1->GetOptionsFrame();
   * CATDlgCheckButton *pCheck1  = new CATDlgCheckButton(pOptionsFrame1,<b>"Check1"</b>);
   * CATDlgMultiList *pMultiList1  = new CATDlgMultiList(pOptionsFrame1,<b>"MultiList1"</b>);
   * //
   * // The retrieved "Options Frame", pOptionsFrame1, is the parent of the created check button, and multiple list. 
   * //
   * //Both components are attached on 4 sides, and laying over 1 column and 1 row in the OptionsFrame1
   * // pCheck1 is in the 0,0 box, pMultiList1 in the 0,1 box.
   * pCheck1       -> SetGridConstraints(0,0,1,1,CATGRID_4SIDES); 
   * pMultiList1   -> SetGridConstraints(0,1,1,1,CATGRID_4SIDES);
   * //Now we want the multiple list to fit the entire OptionsFrame width. Thus the column 1 should be resizable.
   * OptionsFrame1 -> SetGridColumnResizable(1,1);
   * ...
   * </pre>
   * CATDlgFrame *pOptionsFrame1 = pFrame1->GetOptionsFrame();
   * ...
   * </pre>
   * <p>The resources for your controls are set in the <tt>CATxxx.CATNls</tt> and/or 
   * <tt>CATxxx.CATRsc</tt>. For example the text for the created check button is set
   * as follows:
   * <pre>Frame1.<b>IconAndOptionsFrame.OptionsFrame.</b>Check1.Title = "Check this option"; </pre>
   * <p>where:
   * <dl>
   * <dt><tt>Frame1</tt>
   * <dd>The identifier of the <tt>CATDlgToolsOptionsFrame</tt>
   * <dt><tt>IconAndOptionsFrame.OptionsFrame</tt>
   * <dd>Required keyword
   * <dt><tt>Check1</tt>
   * <dd>The identifier of the check button
   * <dt><tt>Title</tt>
   * <dd>The keyword for a title
   * </dl>
   */
  virtual CATDlgFrame* GetOptionsFrame();

  /**
   * Sets the  sensitivity for the whole frame.
   * @param iSensitivity
   * The frame sensitivity.
   * <br><b>Legal Values:</b>
   * <dl>
   *   <dt><tt>CATDlgEnable</tt>
   * <dd> The frame is sensitive
   *   <dt><tt>CATDlgDisable</tt>
   * <dd> The frame is not sensitive
   * </dl>
   */  
  virtual void SetSensitivity(const CATULong& iSensitivity);

private:
  CATDlgFrame  * _HeaderFrame;
  CATDlgFrame  * _IconAndOptionsFrame; 
  CATDlgFrame  * _IconFrame;
  CATDlgFrame  * _OptionsFrame;
};
#endif
