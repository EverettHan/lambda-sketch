/* -*-c++-*- */
#ifndef CATISearchPanel_H
#define CATISearchPanel_H
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2001
//=============================================================================
//
// CATISearchPanel
//    CATBaseUnknown
//
//=============================================================================
// Interface used by application to subscribe to the OK, Cancel and Close 
// notifications emitted by the Search Panel.
//=============================================================================
// Module
#include "UIModelInterfaces.h"

// Héritage
#include <CATBaseUnknown.h>


#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByUIModelInterfaces IID IID_CATISearchPanel;
#else
extern "C" const IID IID_CATISearchPanel;
#endif

// Utile
//#include "CATEventSubscriberTypedefs.h"
class CATDlgDialog;
class CATNotification;
class ExportedByUIModelInterfaces CATISearchPanel : public CATBaseUnknown
{
  CATDeclareInterface;

public:
  // Pour connaître la fenêtre de Dialog qui va émettre les 
  // notifications OK, Cancel, Close.
  //
  //   @param oEmittingWindow
  //       Fenêtre qui émet les notifications.
  //       Window that emits notifications.
  //   @return
  //      Code d'erreur de la fonction.
  /**
   * To know the Dialog window which will emit the OK, Cancel
   * and Close notifications.
   *
   *   @param oEmittingWindow
   *       Window that emits notifications.
   *   @return
   *      Error code of function.
   */
  virtual HRESULT GetEmittingWindow(CATDlgDialog *& oEmittingWindow) = 0;

   // --------------------------------------------------------------
   //        Notifications émises | Sent notifications
   // --------------------------------------------------------------
   // Pour récupérer (et s'abonner) à la notification émise lors du OK
   // sur la fenêtre.
   // La notification OK contient le critère généré dans la fenêtre de 
   // Recherche. Le type de cette notification est CATNotificationWithData 
   // (service du framework System).
   // Pour en récupérer les données, la notification doit être transformée 
   // en CATNotificationWithData. Ensuite, un appel à GetNotificationWithData() 
   // retourne la donnée (void*), mais de véritable type CATSearchCriteria. 
   // Après transformation en pointeur sur CATSearchCriteria par l'utilisateur, 
   // un AddRef doit être effectué sur cette donnée avant utilisation, et un 
   // Release appelé en fin d'utilisation.  
   //
   //   @param oNotification
   //      La notification émise.
   //   @return
   //      Code d'erreur de la fonction.
   /**
    * To get (and thus subscribe to) the sent notification when OK is 
    * clicked in the panel.
    * The OK notification contains the criteria that has been built in 
    * the Search panel. The notification's type is CATNotificationWithData. 
    * (service from the System's framework).
    * To retrieve its data, the notification has to be cast into 
    * CATNotificationWithData. Then a call to GetNotificationData() returns 
    * the data (void*), which real type is CATSearchCriteria type. 
    * After a cast, the user needs to AddRef the returned pointer before use, 
    * and must Release it afterwards.
    *
    *   @param oNotification
    *      The notification being sent.
    *   @return
    *      Error code of function.
    */
  virtual HRESULT GetOKNotification(CATNotification*& oNotification) = 0;

   // Pour récupérer (et s'abonner) à la notification émise lors du Cancel 
   // sur la fenêtre.
   //
   //   @param oNotification
   //      La notification émise.
   //   @return
   //      Code d'erreur de la fonction.
   /**
    * To get (and thus subscribe) to the sent notification when Cancel is 
    * clicked in the panel.
    *   @param oNotification
    *      The notification being sent.
    *   @return
    *      Error code of function.
    */
  virtual HRESULT GetCancelNotification(CATNotification*& oNotification) = 0;

   // Pour récupérer (et s'abonner) à la notification émise lors de la fermeture 
   // de la fenêtre.
   //
   //   @param oNotification
   //      La notification émise.
   //   @return
   //      Code d'erreur de la fonction.
   /**
    * To get (and thus subscribe) to the sent notification when the panel is 
    * being closed.
    *
    *   @param oNotification
    *      The notification being sent.
    *   @return
    *      Error code of function.
    */
  virtual HRESULT GetCloseNotification(CATNotification*& oNotification) = 0;

};
// --------------------------------------------------------------------------
//                             pointeur intelligent
// --------------------------------------------------------------------------
//CATDeclareHandler(CATISearchPanel);

#endif
