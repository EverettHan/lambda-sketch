#ifndef CATExtIWorkbenchTransition_h
#define CATExtIWorkbenchTransition_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U2
 */

#include <CATAfrFoundation.h>
#include <CATBaseUnknown.h>
#include <CATString.h>

/**
* Adapter for the CATIWorkbenchTransition interface.
* <b>Role</b> : To implement the @href CATIWorkbenchTransition interface, for each workshop, 
* you should create a class as a data extension of a late type made of the workshop identifier
* suffixed by <b>_trans</b>, such as  <tt>MyWorkshop_trans</tt> for the MyWorkshop'workshop.
* This class derives from this adapter and is used when the user chooses a new 
* workbench to manage the transition between the current workbench and the new one.
* However the aim of this class is only to activate the right workshop if needed. Then the
* activation of the requested workbench is done automatically. In general, activating 
* workshop consists in creating a document linked to this workshop. 
* <br><br>
* <ul>
* <li>Value in the constructor the @href #_newDoc data member with the type of the
* document to create if the user chooses the workshop extended 
* by this class as the new current workshop.</li>
* <li>Override the @href #DoTransition method if the default one ( the one implemented 
* in the CATExtIWorkbenchTransition) doesn't fit your need.</li>
* </ul>
* 
*/
class ExportedByCATAfrFoundation CATExtIWorkbenchTransition : public CATBaseUnknown
{
  CATDeclareClass;
  
public:
  
  /**
  * Constructs the class.
  */
  CATExtIWorkbenchTransition();
  ~CATExtIWorkbenchTransition();
  
  /**
  * Handles or not the transition.
  * <br><b>Role</b>: This default implementation creates a document of the @href #_newDoc 
  * type if:
  * <ul>
  * <li>The selected workshop (<tt>iToWorkshop</tt>) is the workshop extended by this
  * class and it is not already the current one</li>
  * <li>The selected workshop is the current one, and workbenches From and To are the same </li>
  * </ul>
  * <br>
  * This implementation should be sufficient if the document associated to the extended   
  * workshop is :
  * <ul>
  * <li>Standalone, that is doesn't contain or is not linked to, or 
  * that isn't contained or linked by documents</li>
  * <li>an embedding or linking document</li>
  *</ul><br>
  * On the opposite, if the document associated to the extended workshop is embedded or
  * linked, you may need to override the <tt>DoTransition</tt> method, knowing that CATIA calls the 
  * workshop involved in  the transition on their DoTransition method in the following
  * order: the active workshop and next the selected workshop.
  * <br>
  * <u>For Example</u>: if the document linked to the extended workshop is the current
  * document (ex: Part) and the user selects a workshop ( or a workbench belonging 
  * to a workshop) linked to an embedding document ( ex: Product), DoTransition will have 
  * to UIActivate the embedding document ( ex Product). Otherwise, if the DoTransition 
  * method of the active workshop (ex Part) doesn't handle the transition, the DoTransition
  * method of the selected workshop ( ex Product) is called and creates a new 
  * product document instead of activating the existing one.
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
			               const CATString & iToWorkbench);
  
protected:
  
  /**
  * Document's name to open.
  * <br><b>Role</b>: This variable is initialized in the constructor and used in the
  * @href #DoTransition method. 
  */
  CATString _newDoc;


private:

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATExtIWorkbenchTransition (const CATExtIWorkbenchTransition &);
  CATExtIWorkbenchTransition & operator= (const CATExtIWorkbenchTransition &);
};

#endif
