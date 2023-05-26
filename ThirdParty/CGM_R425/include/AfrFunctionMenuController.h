#ifndef AfrFunctionMenuController_H
#define AfrFunctionMenuController_H

#include <CATAfrFoundation.h>
#include <CATMacForIUnknown.h>
#include <CATBaseUnknown.h>
#include <CATUnicodeString.h>
#include <CATSYPHashMap.h>
#include <CATCmdContainer.h>

/**
  * A Function Menu Controller class used in Application Framework internal implementation.
  * <p>
  *     This controller hold methods to interact with the Function Menu model, especially
  *     for the Suggestion Menu.
  * </p>
  */
class ExportedByCATAfrFoundation AfrFunctionMenuController : public CATBaseUnknown
{
	CATDeclareClass;
public:
	AfrFunctionMenuController();
	~AfrFunctionMenuController();

	/**
	  * Subscribe a latetype to fill the Suggestion Menu model.
	  * <p>
	  *     This method allows to register a latetype implementing AfrISuggestionMenuActor
	  *     that will be called when the Suggestion Menu will be required.
	  * </p>
	  * @param i_LateType The latetype implementing the AfrISuggestionMenuActor interface.
	  * @return an HRESULT indicating if the method failed or not.
	  */
	HRESULT SubscribeToSuggestionMenu(const CATUnicodeString& i_LateType);

	/**
	  * Unsubscribe a latetype that does not need to fill the Suggestion Menu model anymore.
	  * <p>
	  *     This method allows to unregister a latetype from the Suggestion Menu
	  *     model creation process.
	  * </p>
	  * @param i_LateType The latetype to unsubscribe.
	  * @return an HRESULT indicating if the method failed or not.
	  */
	HRESULT UnsubscribeToSuggestionMenu(const CATUnicodeString& i_LateType);

	/**
	  * Clear all subscriptions.
	  * <p>
	  *     This method allows to remove all registered latetype.
	  * </p>
	  * @return an HRESULT indicating if the method failed or not.
	  */
	HRESULT ClearSubscriptions();

	/**
	  * Create the Suggestion Menu model.
	  * This method will create the Suggestion Menu model (a CATCmdAccess tree) by:
	  * <ol>
	  *   <li>Calling implementations of the \<iWorkshopName\>\<iWorkbenchName\>ISugMenuActor interface.</li>
	  *   <li>Calling implementations of AfrISuggestionMenuActor implemented on registered latetype.</li>
	  * </ol>
	  * @param iWorkshopName The name of the current workshop.
	  * @param iWorkbenchName The name of the current workbench.
	  * @param The output parameter in which the root Suggestion Menu container will be created.
	  * @return an HRESULT indicating if the method failed or not.
	  */
	HRESULT CreateSuggestionMenu(CATUnicodeString iWorkshopName, CATUnicodeString iWorkbenchName, CATCmdContainer** op_SuggestionMenu);

	// Impossible to copy, move or assign.
	AfrFunctionMenuController(const AfrFunctionMenuController&) = delete;
	AfrFunctionMenuController(AfrFunctionMenuController&& ) = delete;
	AfrFunctionMenuController& operator=(AfrFunctionMenuController) = delete;

private:
	// LateType => Subscription count
	// The same LateType may be register twice (or more) and we
	// need to keep this information in order to know if
	// we need to remove the LateType from the map or keep it
	// when unsubscribe is called.
	CATSYPHashMap<CATUnicodeString, unsigned int> _lateTypeSubscriptions;

	// Entry point for ODTs.
	// To unit test the AfrFunctionMenuController class,
	// please use the AfrFunctionMenuControllerTester and
	// never add ODT only code in the production code.
	friend class AfrFunctionMenuControllerTester;
};

#endif // !AfrFunctionMenuController_H
