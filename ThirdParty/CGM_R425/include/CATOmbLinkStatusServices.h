/* -*-c++-*- */
//=================================================================================================================================
// COPYRIGHT DASSAULT SYSTEMES  2005
//=================================================================================================================================
//
// CATOmbLinkStatusServices:
//    provides static services to retrieve the reason why a given link resolution failed. 
//
//=================================================================================================================================
// Usage Notes:
//	A link resolution corresponds to the sequencial resolution of :
//		1) a relation (public part of a link toward a component) 
//		2) a private path (path toward the pointed target inside/relatively to this component)
//
// The given resolution status are:
//
//	For the pointed component 
//	-> Found
//	-> Not Found 	-> broken relation
//					-> component not in session
//
// for the target inside the component:
//	-> Found
//	-> Not Found   	-> broken link
//					-> target not in session
//
// Thus the global link resolution status is :
//
//		Link Status					CATOmbLinkStatusServices enum value				Resolution
//	->  OK							Target_Found						component Found, target found
//	->  component not in session	Component_NotInSession 				component not in session,  private path resolution N/A	
//	->  broken relation				Component_Broken 					broken relation, private path resolution N/A	
//	->  broken link					Link_Broken 						component Found, broken link
//	->  target not in session		Target_NotInSession					component Found, target not in session
//	->	Invalid Link				InvalidLink							impossible
// 
//=================================================================================================================================
// Nov. 2005   Creation                                  DEM
//=================================================================================================================================


/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */ 



/**
 * Class to interpret the return code of link resolution methods.
 * 
 * <b>Role</b>: This class provides a static method to interpret the return code of link resolution methods.
 *
 */

#ifndef CATOmbLinkStatusServices_H
#define CATOmbLinkStatusServices_H

#include "CATObjectModelerBase.h"
#include "IUnknown.h"


class ExportedByCATObjectModelerBase CATOmbLinkStatusServices
{
public:


	/**
	* Link status corresponding to the return code of a link resolution. 
	* @param Target_Found
	*   The link resolution succeeded
	* @param Component_NotInSession
	*   The pointed component is not in session.
	* @param Relation_Broken
	*   The relational part of the link corresponds to a destroyed/inexistant component
	* @param Link_Broken
	*   The pointed component is in session
	*   The private path of the link corresponds to a destroyed/inexistant target
	* @param Target_NotInSession
	*	The pointed component is in session but not the target inside the component.
	* @param InvalidLink
	*	The link is corrupted due to an unsupported format. This link will never be solved.
	*/

	enum LinkResolutionStatus 
	{ Target_Found, Component_NotInSession, Relation_Broken, Link_Broken, Target_NotInSession, InvalidLink};

	/**
	 * Retrieves the link resolution status from the rc. 
     * @param irc
	 *	The return code given by the link resolution method.
     * @param oStatus
 	 *	the corresponding link status.
     * @return 
	 *	An HRESULT value: 
	 *	<dl>
	 *		<dt>S_OK</dt>
	 *			<dd> irc is a known link resolution return code.</dd>
	 *		<dt>E_INVALIDARG</dt>
	 *			<dd> otherwise.</dd>
 	 *	</dl>
     */

	static  HRESULT GetLinkStatusFromRc(HRESULT irc, LinkResolutionStatus& oStatus);

private:

	/** @nodoc */
	CATOmbLinkStatusServices();

	/** @nodoc */
	~CATOmbLinkStatusServices();

};


#endif      

