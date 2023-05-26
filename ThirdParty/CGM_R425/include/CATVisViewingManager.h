// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATVisViewingManager.h
// Header definition of CATVisViewingManager
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jan 2009  Creation: YWG
//===================================================================
#ifndef CATVisViewingManager_H
#define CATVisViewingManager_H

#include "CATVisImmersivePanel.h"
#include "CATCallbackManager.h"
#include "CATListPV.h"
#include "CATVisViewingUtility.h"

class CATVisViewing;
class CATVidFraDialogBox;
class CATViewer;
class CATViewpoint;

struct ExportedByCATVisImmersivePanel VisViewing
{
   CATViewer              * viewer;
   CATViewpoint           * viewpoint;
   CATVisViewing          * overview;
   CATVidFraDialogBox     * dialogBox;
   CATVisViewingStyle       style;

   VisViewing()
   {
      viewer    = NULL;
      viewpoint = NULL;
      overview  = NULL;
      dialogBox = NULL;
      style     = VIEWING_DEFAULT_STYLE;
   }
} ;

//-----------------------------------------------------------------------

/*
*
* Class CATVisViewingManager
*
*/

class ExportedByCATVisImmersivePanel CATVisViewingManager : public CATCallbackManager
{
   CATDeclareClass;

public:

   CATDeclareCBEvent(VIS_VIEWING_ADDED);
   CATDeclareCBEvent(VIS_VIEWING_REMOVED);

   // Get the singleton of CATVisViewingManager.
   // -------------------------------------------
   static CATVisViewingManager* GetVisViewingManager();

   virtual ~CATVisViewingManager ();

   HRESULT AddViewing(CATViewer * iViewer, CATViewpoint * iViewpoint = NULL, CATVisViewingStyle iStyle = VIEWING_DEFAULT_STYLE);

   HRESULT RemoveViewing(CATViewer * iViewer);
   HRESULT RemoveAllViewing();
   HRESULT ShowViewing(CATViewer * iViewer);
   HRESULT HideViewing(CATViewer * iViewer);

   CATListPV GetVisViewingList();
   VisViewing * GetVisViewing(CATViewer * iViewer);

private:

   // Standard constructors
   // ---------------------
   CATVisViewingManager ();

   // Copy constructor and equal operator
   // -----------------------------------
   CATVisViewingManager (const CATVisViewingManager &i_original);
   CATVisViewingManager& operator=(const CATVisViewingManager& i_original);

   void ViewerCB(CATCallbackEvent event, void * sender, CATNotification * notif, CATSubscriberData data, CATCallback);

private:

   static CATVisViewingManager* _s_pVisViewingManager;

   CATListPV     _visViewingList;

};
//-----------------------------------------------------------------------

#endif
