#ifndef CATIWorkbenchTransition_h
#define CATIWorkbenchTransition_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U4 CATExtIWorkbenchTransition
 */

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"
#include "CATString.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrItf IID IID_CATIWorkbenchTransition;
#else
extern "C" const IID IID_CATIWorkbenchTransition;
#endif

/**
* Interface to create transition between workbenches.
* <b>Role</b>: Changing the current workbench to another is one of the 
* methods proposed to the end user to go on with his/her job with another set of tools. 
* To avoid discontinuity in the process and ensure smooth transitions between workbenches, 
* these transitions should have been designed and implemented. <br>
* <br>
* The goal of this interface is to answer to this question: the document 1 is activated with
* the workbenchA, the workbench B is selected in the Start menu, what happens ? 
* The workbench B is activated but with which document ?
* <ul>
* <li> The same document ? </li>
* <li> An another document of the same type as the document 1? </li>
* <li> A new document from another type  ?</li>
* <li> What happens if document 1 contains a document which can match the workbench B ?
* </ul>
* 
* You should implement the CATIWorkbenchTransition interface, for each workshop, using an 
* extension of a late type made of the workshop identifier suffixed 
* by <b>_trans</b>, such as <tt>MyWorkshop_trans</tt> for the MyWorkshop'workshop.To do 
* this you should make a class that derives from  @href CATExtIWorkbenchTransition. 
* 
* The aim of this implementation is only to activate the right workshop if needed. Then the
* activation of the requested workbench is done automatically.
* <p><b>BOA information</b>: this interface CANNOT be implemented
* using the BOA (Basic Object Adapter).
* To know more about the BOA, refer to the CAA Encyclopedia home page.
* Click Middleware at the bottom left, then click the Object Modeler tab page.
* Several articles deal with the BOA.</p>
*/
class ExportedByCATAfrItf CATIWorkbenchTransition : public CATBaseUnknown
{
  CATDeclareInterface;
  
public:
  
  /**
  * Handles or not the transition if possible.
  *<br><b>Role</b>: Transitions ( from and) to your workbench should be designed knowing that
  * CATIA calls the workshops involved in the transition on their
  * <tt>DoTransition</tt> methods in the following order:
  * <br>
  * <ol>
  * <li>The active workshop,  <tt>iFromWorkshop</tt></li>
  * <li>The selected workshop, or the workshop to which the selected workbench 
  *     belongs, <tt>iToWorkshop</tt></li>
  * </ol>
  * <br>
  * Any of them can decide what to do when a transition occurs. CATIA calls them in 
  * that order until one of them decides.If the active workshop decides, the selected is not
  * called. However the selected workshop generally decides,  
  * since incoming transitions only should be implemented. If none decides, this means that
  * the transition involves two workbenches of the same workshop, and simply switches 
  * these workbenches.
  * @param iFromWorkshop
  *    The active workshop
  * @param iFromWorkbench
  *    The active workbench
  * @param iToWorkshop
  *    The selected workshop, or the workshop to which the selected workbench 
  *     belongs.
  * @param iToWorkbench
  *    The selected workbench
  * @return 
  *   1 if handled, 0 otherwise
  */
  virtual int DoTransition(const CATString & iFromWorkshop,
			               const CATString & iFromWorkbench,
			               const CATString & iToWorkshop,
			               const CATString & iToWorkbench) = 0;
};
CATDeclareHandler(CATIWorkbenchTransition, CATBaseUnknown);

#endif
