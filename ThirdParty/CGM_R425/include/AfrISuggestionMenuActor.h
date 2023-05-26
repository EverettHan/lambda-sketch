#ifndef AfrISuggestionMenuActor_H
#define AfrISuggestionMenuActor_H

#include <CATAfrItf.h>
#include <CATBaseUnknown.h>
#include <CATMacForIUnknown.h>

extern ExportedByCATAfrItf IID IID_AfrISuggestionMenuActor;

class CATCmdContainer;

/**
  * Interface to add items into the Suggestion Menu.
  * The Suggestion Menu is the first tab page of the Function Menu.
  * <b>Usages (two possibilities):</b>
  * <ul>
  *   <li>
  *     <b>Implementation for a particular application</b><br>
  *     <p>
  *        To implement the interface for a particular application, an interface inheriting
  *        from this one (AfrISuggestionMenuActor) MUST be created by the application
  *        manager. This other interface MUST be called using the following format:<br>
  *        \<workshop_id\>\<workbench_id\>ISugMenuActor<br>
  *        If the interface does not exist, contact the application manager to ask for it.
  *     </p>
  *   </li>
  *   <li>
  *     <b>Implementation independent of any application</b><br>
  *     <p>
  *        Implement the interface on a latetype and ensure this latetype is registered
  *        at the Function Menu level (see Function Menu APIs).
  *     </p>
  *   </li>
  * </ul>
  */
class ExportedByCATAfrItf AfrISuggestionMenuActor : public CATBaseUnknown
{
	CATDeclareInterface;
public:

	/**
	  * Add items into the Suggestion Menu.
	  * <p>
	  *    To add items inside the given CATCmdContainer, use the APIs provided
	  *    in CATAfrAccessFactory.h (such as CATAfrAccessFactory::NewAccess and
	  *    CATAfrAccessFactory::AddAccessChild).
	  * </p>
	  * @param ip_SuggestionMenuContainer The Suggestion Menu root container in which
	  *                                   items can be added.
	  */
	virtual void FillSuggestionMenu(CATCmdContainer* ip_SuggestionMenuContainer) = 0;
};

#endif
