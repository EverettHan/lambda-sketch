// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// CATAfrFacetEventManagerServices.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//  Nov 2004  Creation: sru
//===================================================================
#ifndef CATAfrFacetEventManagerServices_H
#define CATAfrFacetEventManagerServices_H

#include "UIModelInterfaces.h"
#include "CATBaseUnknown.h"

class CATEventSubscriber;

class ExportedByUIModelInterfaces CATAfrFacetEventManagerServices
{

public:

  /* Returns an event publisher's callback manager in order to catch PLMCompass quadrant pressed notifications.
   *
   * @param oCallbackManager [out, CATBaseUnknown#Release]
   * @param iBForSearch CallBack dedicated for Search Results
   * @return
   *    An HRESULT value.
   *    <br><b>Legal values</b>:
   *    <dl>
   *      <dt>S_OK</dt>
   *      <dd>if service successful</dd>
   *      <dt>E_FAIL</dt>
   *      <dd>if service failed</dd>
   *    </dl>
   */
  static HRESULT GetAfrFacetEventManager(CATEventSubscriber ** oCallbackManager);

  /**
   * To send the notifiation corresponding to a request to update a refinement facet.
   * 0 refresh property
   * 1 refresh facet
   * 2 model refreshed (==> need to refresh all facets)
   * 3 Facet computation done (refinement panel can ask the facet to the engines
   */
  static HRESULT SendAfrUpdateFacetNotification(CATBaseUnknown *ipiBU, int iRefreshType);

  /**
   * To send the notifiation corresponding to the expand of the Compass quadrant .
   * if TRUE , Maximise notification
   * if FALSE , Minimise notification
   * if Maximise notification then send the refinement panel width
   */
  static HRESULT SendMaximizeFacetNotification(CATBoolean ibMaximise, int iRefinementPanelWidth);

  /**
  * To clean the CallbackManager at the end of the session
  */
  static HRESULT CleanAfrFacetManager();

  /**
   * Notification send when a quadrant becomes hidden (to remove it from combo of BI Essential for ex.)
   */
  static HRESULT SendHiddenFacetNotification();

  /**
   * Notification send when a refresh is requested from applicative quadrant
   */
  static HRESULT SendRefreshFacetNotification(CATBaseUnknown *ipiBU=NULL);

private:
  CATAfrFacetEventManagerServices();
  CATAfrFacetEventManagerServices(CATAfrFacetEventManagerServices &);
  CATAfrFacetEventManagerServices& operator=(CATAfrFacetEventManagerServices&);

  static CATEventSubscriber * _PLMRefinementFacetCallbackManager;
};

#endif

