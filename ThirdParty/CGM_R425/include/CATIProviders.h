#ifndef CATIProviders_H
#define CATIProviders_H
// COPYRIGHT DASSAULT SYSTEMES 2000
//===================================================================
//
/**
 * @CAA2Required
 *              
 */
#include "CATOMY.h"
#include "CATBaseUnknown.h"
#include "CATLISTP_CATBaseUnknown.h"

extern ExportedByCATOMY IID IID_CATIProviders ;

//------------------------------------------------------------------

/**
 * Interface to manage provider declaration.
 * <b>Role:</b>This interface used in the init of an applicative container
 * enable you to declare a list of providers. Each provider is a component implementing a 
*   specific interfaces: 
 * <ul>
 *    <li>@href CATI3DVisuProvider </li>
 *    <li>@href CATIUpdateProvider </li>
 *    <li>@href CATIParmProvider </li>
 *    <li>@href CATINavigateProvider </li>
 *    <li>CATICtxMenuProvider </li>
 * </ul>  
 * <p>The retrieval of a <tt>CATIProviders </tt> interface pointer is depending on the
 * modeler. </p>
 */
class ExportedByCATOMY CATIProviders: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

    /** Adds a new provider.
	  * @param clsid
	  *     Provider interface name.
	  * @param iProvider
	  *     The provider object.
	  */
	virtual HRESULT AddProvider(const CLSID &clsid, CATBaseUnknown * iProvider) = 0;

	/** Removes a provider.
	  * @param clsid
	  *     Provider interface name.
	  * @param iProvider
	  *     The provider object. 
	  */
	virtual HRESULT RemoveProvider(const CLSID &clsid, CATBaseUnknown * iProvider) = 0;

	/** Lists the providers.
	  * @param clsid
	  *     Provider interface name.
	  * @param oListProviders
	  *     The list of the provider objects declared for the given interface.
	  */
	virtual HRESULT ListProviders(const CLSID &clsid, CATLISTP(CATBaseUnknown) ** oListProviders) = 0;

};

//------------------------------------------------------------------

CATDeclareHandler( CATIProviders, CATBaseUnknown );

#endif
