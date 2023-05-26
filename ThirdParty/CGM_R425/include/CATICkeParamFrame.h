#ifndef CATICkeParamFrame_h
#define CATICkeParamFrame_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/** 
 * @CAA2Level L1
 * @CAA2Usage U3
 */

/*  CAA2Reviewed by FRH */

// module declaration
#include "KnowledgeItf.h"

// inherited from
#include "CATBaseUnknown.h"

// Forward declaration
#include "CATICkeRelationForwards.h"
class CATDlgFrame;
class CATDialog;

// interfaces used
#include "CATIParmPublisher.h"

// OLE iid
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByKnowledgeItf IID_CATICkeParamFrame;
#else
extern "C" const IID IID_CATICkeParamFrame;
#endif

/**   
 * Interface to create an editor from a parameter (literal or volatile value).
 * <b>Role</b>: From this interface you'll get an editor of the parameter that you will integrate in a complex dialog.
 * <br>It can be used on persistant literals or volatile values.<br>
 * This frame will offer a way to show a parameter value or to modify it.<br>
 *  <li> All informations are available on the parameter</li>
 *  <li> if the parameter is ReadOnly, or with a Visibility equal to false or</li>
 *  is valuated by a relation, the frame sensitivity will be false<br>
 *=============================================================================<br>
 * Depending on the type of the parameter, the frame will contain an editor, a combo<br> 
 * (for enumere parameters), or a spinner<br>
 *<br>
 * The frame style is used to detail the frame look :<br>
 *   <li> CATCkeNoLabel / CATCkeLabel : indicates if you want to have a label before your editor</li>
 *   <li> CATCkeWithSpinner : to have a spinner and not an editor on real parameters</li>
 *   <li> CATCkeNoRename : not to have the rename command available on contextual menu</li>
 *   <li> CATCkeNoFormula : not to have the Edit formula command available on contextual menu</li>
 *   method is triggered on the CATDlgFrame.<br>
 *<br>
 * To customise the NLS, all you have to know is the ressources structure<br>
 * The returned CATDlgFrame is a frame named "ParamFrame"<br>
 * The children of this frame are :   <br>
 *   <li>if CATCkeLabel option is chosen, the name of the label is "Label", and its value defaults to "Label",
 *       if not given by NLS tag "ParamFrame.EnglobingFrame.IntermediateFrame.Label.Title" .</li>
 *   <li>if CATCkeWithSpinner option is chosen, the name of the editor is "Spinner" .</li>
 *   <li>if it is a combo, its name is "Combo"</li>
 *   <li>if not, it's an editor whose name is "Value"</li>
 *<br>
 * If the last argument is different from "", then the name of the CATDlgFrame will<br>
 * be the name in argument instead of "ParamFrame" <br>   
 *<br>
 *=============================================================================<br>
 * Usage Note <br>
 *  //  Imagine you have a parameter p <br>
 *  CATICkeParm_var p = ...;<br>
 *  // and a CATDialog d<br>
 *  CATDialog *d = ...<br>
 *  <br>
 *  // QI on CATICkeParamFrame <br>
 *  CATICkeParamFrame_var pf = p;<br>
 *<br>
 *  // Get the frame (spinner, No formulas, and no label<br>
 *  CATDlgFrame *fr = pf->GetInPanelEdition (NULL_var,d,CATCkeNoLabel | CATCkeNoFormula | CATCkeNoRename | CATCkeWithSpinner);<br>
 *<br>
 * @see CATICkeParm
 */
//-----------------------------------------------------------------------------
class ExportedByKnowledgeItf CATICkeParamFrame : public CATBaseUnknown
{

  CATDeclareInterface;

public :

  /**
   * Creates a frame-editor linked to a parameter (literal or volatile value) to include in your panel.
   * 
   * @param iRoot the place where formulas will be added (can be NULL_var if no formulas) 
   * @param iFather the father CATDialog object
   * @param iStyle  the frame style 
   * @param iLabelName if <> from "", it's the name (CATString) of the frame
   * @return a frame containing the editor associated to the literal
   */
  virtual CATDlgFrame * GetInPanelEdition (const CATIParmPublisher_var  &iRoot,
					   CATDialog           *iFather,
					   CATCkeFrameStyle     iStyle = CATCkeLabel,
					   const CATUnicodeString       &iLabelName = "") = 0;

}; 

CATDeclareHandler(CATICkeParamFrame,CATBaseUnknown);

#endif
