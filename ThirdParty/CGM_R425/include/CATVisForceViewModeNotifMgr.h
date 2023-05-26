// COPYRIGHT Dassault Systemes 2015
//===================================================================
//
// CATVisForceViewModeNotifMgr.h
// Header definition of CATVisForceViewModeNotifMgr
//
//===================================================================
//
// Usage notes:
//
//------------------------------------------------------------------------------
// Main methods:    
//
//           
//
//------------------------------------------------------------------------------
// Events:    
//	       
//===================================================================
//
//  Jul 2017  Creation: NHD
//===================================================================
#ifndef CATVisForceViewModeNotifMgr_H
#define CATVisForceViewModeNotifMgr_H

#include "CATVisController.h"
#include "CATPathElement.h"
#include "CATCallbackManager.h"
#include "CATMutex.h"

class ExportedByCATVisController CATVisForceViewModeNotifMgr : public CATCallbackManager
{

public:

   enum  ForceViewModeEvent {EventAddPath           = 0,
                             EventRemovePath        = 1,
			     EventEmpty		    = 2,
                            };

   CATDeclareClass ;

   CATDeclareCBEvent(FORCE_VIEW_MODE_ADD_PATH);
   CATDeclareCBEvent(FORCE_VIEW_MODE_REMOVE_PATH);
   CATDeclareCBEvent(FORCE_VIEW_MODE_EMPTY);
   
   


   // Get the singleton of CATVisForceViewModeNotifMgr.
   // -------------------------------------------
public: 

   static CATVisForceViewModeNotifMgr* GetCATVisForceViewModeNotifMgr();
   static CATVisForceViewModeNotifMgr* _s_pVisForceViewModeNotif;

   virtual ~CATVisForceViewModeNotifMgr();

   //HRESULT DispatchCATRepCallbacks(RepEvent iEvent, CATRep * iData );
   HRESULT DispatchForceViewModeCallbacks(ForceViewModeEvent iEvent);
   HRESULT DispatchForceViewModeCallbacks(ForceViewModeEvent iEvent, CATPathElement * iData);
   HRESULT DispatchForceViewModeCallbacks(ForceViewModeEvent iEvent, CATPathElement * iData, unsigned int iForceAxis, unsigned int iForceLines, unsigned int iForcePoints);

protected:
	static CATMutex _MutexForceViewModeNotifMgr; //Added mutex variable to make singleton creation thread safe
   
private:

   // Standard constructors
   // ---------------------
  CATVisForceViewModeNotifMgr();

   // Copy constructor and equal operator
   // -----------------------------------
   CATVisForceViewModeNotifMgr (const CATVisForceViewModeNotifMgr & i_original);
   CATVisForceViewModeNotifMgr& operator=(const CATVisForceViewModeNotifMgr & i_original);

   
   
};


#endif
