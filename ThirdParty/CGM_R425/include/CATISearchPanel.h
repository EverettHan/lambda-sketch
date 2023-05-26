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

// H�ritage
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
  // Pour conna�tre la fen�tre de Dialog qui va �mettre les 
  // notifications OK, Cancel, Close.
  //
  //   @param oEmittingWindow
  //       Fen�tre qui �met les notifications.
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
   //        Notifications �mises | Sent notifications
   // --------------------------------------------------------------
   // Pour r�cup�rer (et s'abonner) � la notification �mise lors du OK
   // sur la fen�tre.
   // La notification OK contient le crit�re g�n�r� dans la fen�tre de 
   // Recherche. Le type de cette notification est CATNotificationWithData 
   // (service du framework System).
   // Pour en r�cup�rer les donn�es, la notification doit �tre transform�e 
   // en CATNotificationWithData. Ensuite, un appel � GetNotificationWithData() 
   // retourne la donn�e (void*), mais de v�ritable type CATSearchCriteria. 
   // Apr�s transformation en pointeur sur CATSearchCriteria par l'utilisateur, 
   // un AddRef doit �tre effectu� sur cette donn�e avant utilisation, et un 
   // Release appel� en fin d'utilisation.  
   //
   //   @param oNotification
   //      La notification �mise.
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

   // Pour r�cup�rer (et s'abonner) � la notification �mise lors du Cancel 
   // sur la fen�tre.
   //
   //   @param oNotification
   //      La notification �mise.
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

   // Pour r�cup�rer (et s'abonner) � la notification �mise lors de la fermeture 
   // de la fen�tre.
   //
   //   @param oNotification
   //      La notification �mise.
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
