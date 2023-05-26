// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATIOmbLinkSessionListener.h
// Define the CATIOmbLinkSessionListener interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Jun 2005  Creation: Code generated by the CAA wizard  dem
//===================================================================
#ifndef CATIOmbLinkSessionListener_H
#define CATIOmbLinkSessionListener_H

#include "CATObjectModelerBase.h"
#include "CATBaseUnknown.h"
#include "CATOmxDefaultCollecManager.h"
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATObjectModelerBase IID IID_CATIOmbLinkSessionListener;
#else
extern "C" const IID IID_CATIOmbLinkSessionListener ;
#endif

/**
 * @level Private
 * @usage U1
 */


/** @nodoc */
class ExportedByCATObjectModelerBase CATOmbLinkEventsDescriber
{
public:	

	enum Type { Load, Unload, Reroute, Unset, None, RetrieveAll };
	enum When { Before, After };

	CATOmbLinkEventsDescriber (When iWhen,Type iType ):
	  _What(iType),_When(iWhen){};

	~CATOmbLinkEventsDescriber(){};

	inline When GetTimeOccurence() const {return _When;};
	inline Type GetType () const {return _What;};

private:

	When _When;
	Type _What;
};

//------------------------------------------------------------------

/**
* Interface used as a session link listerner.
*
* <br><b>Implemented by Spec Modeler as a link listener </b>
*/

class ExportedByCATObjectModelerBase CATIOmbLinkSessionListener: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

    /**
     * Method called by OMB after and before load and unload peration..
	 *   @param iEvent
           *      decribe the happening event.
           *   @return
           *      Error code of function.
           * 
     * </pre>
     * </dl>
     */
  
	 virtual HRESULT OnLinkEvent(const CATOmbLinkEventsDescriber& iEvent) = 0 ;
};

CATDeclareHandler( CATIOmbLinkSessionListener, CATBaseUnknown ) ;
template<> CATOmxCollecManager & CATOmxDefaultCollecManager<CATIOmbLinkSessionListener *>::manager();

//------------------------------------------------------------------

#endif
