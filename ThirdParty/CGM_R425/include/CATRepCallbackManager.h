// COPYRIGHT Dassault Systemes 2015
//===================================================================
//
// CATRepCallbackManager.h
// Header definition of CATRepCallbackManager
//
//===================================================================
//
// Usage notes:
//
//------------------------------------------------------------------------------
// Main methods:    
//
//           DispatchCATRepCallback
//
//------------------------------------------------------------------------------
// Events:    
//	       FONT_NOT_FOUND    (request font not installed)
//===================================================================
//
//  Jan 2015  Creation: NHD
//===================================================================
#ifndef CATRepCallbackManager_H
#define CATRepCallbackManager_H

#include "SGInfra.h"
#include "CATCallbackManager.h"
#include "CATRep.h"

//Reps
#include "CATSurfacicRep.h"
#include "CAT3DLodBagRep.h"
#include "CAT3DCurvedPipeRep.h"
#include "CAT3DCurveRep.h"
#include "CAT3DCylinderRep.h"
#include "CAT3DLodRep.h"
#include "CAT3DBagRep.h"
#include "CAT3DCustomRep.h"
#include "CAT3DLineRep.h"
#include "CAT3DPlanRep.h"
#include "CAT3DPointRep.h"
#include "CATMonoWireRep.h"
#include "CATVizMonoWireRep.h"
#include "CATVizUV3DRep.h"
#include "CATVizVertexBufferRep.h"
#include "CATMutex.h"

#define CATRepCallbackManagerNHD


class ExportedBySGInfra CATRepCallbackManager : public CATCallbackManager
{
public:

   enum  RepEvent {CATRepDeleted                = 0,
                   CATSurfacicRepDeleted        = 1,
                   CAT3DLodBagRepDeleted        = 2, 
                   CAT3DCurvedPipeRepDeleted    = 3,
                   CAT3DCurveRepDeleted         = 4,
                   CAT3DCylinderRepDeleted      = 5,
                   CAT3DLodRepDeleted           = 6,
                   CAT3DBagRepDeleted           = 7,
                   CAT3DCustomRepDeleted        = 8,
                   CAT3DLineRepDeleted          = 9,
                   CAT3DPlanRepDeleted          = 10,
                   CAT3DPointRepDeleted         = 11,
                   CATMonoWireRepDeleted        = 12,
                   CATVizMonoWireRepDeleted     = 13,
                   CATVizUV3DRepDeleted         = 14,
                   CATVizVertexBufferRepDeleted = 15,
                   CATVizVertexBufferDeleted = 16,
                   CATSurfacicRepModified    = 17           // IR-645509-3DEXPERIENCER2019x
                   };

   CATDeclareClass ;

   CATDeclareCBEvent(VISU_MANAGER_REP_DELETED);
   CATDeclareCBEvent(VISU_MANAGER_SURFACIC_REP_DELETED);
   CATDeclareCBEvent(VISU_MANAGER_3DLODBAG_REP_DELETED);
   CATDeclareCBEvent(VISU_MANAGER_3DCURVEDPIPE_REP_DELETED);
   CATDeclareCBEvent(VISU_MANAGER_3DCURVE_REP_DELETED);
   CATDeclareCBEvent(VISU_MANAGER_3DCYLINDER_REP_DELETED);
   CATDeclareCBEvent(VISU_MANAGER_3DLOD_REP_DELETED);
   CATDeclareCBEvent(VISU_MANAGER_3DCUSTOM_REP_DELETED);
   CATDeclareCBEvent(VISU_MANAGER_3DBAG_REP_DELETED);
   CATDeclareCBEvent(VISU_MANAGER_3DLINE_REP_DELETED);
   CATDeclareCBEvent(VISU_MANAGER_3DPLAN_REP_DELETED);
   CATDeclareCBEvent(VISU_MANAGER_3DPOINT_REP_DELETED);
   CATDeclareCBEvent(VISU_MANAGER_MONOWIRE_REP_DELETED);
   CATDeclareCBEvent(VISU_MANAGER_VIZMONOWIRE_REP_DELETED);
   CATDeclareCBEvent(VISU_MANAGER_VIZUV3D_REP_DELETED);
   CATDeclareCBEvent(VISU_MANAGER_VIZVERTEXBUFFER_REP_DELETED);
   CATDeclareCBEvent(VISU_MANAGER_VIZVERTEXBUFFER_DELETED);
   CATDeclareCBEvent(VISU_MANAGER_SURFACIC_REP_MODIFIED);         // IR-645509-3DEXPERIENCER2019x
   


   // Get the singleton of CATRepCallbackManager.
   // -------------------------------------------
   static CATRepCallbackManager* GetCATRepCallbackManager();

   virtual ~CATRepCallbackManager ();

   //HRESULT DispatchCATRepCallbacks(RepEvent iEvent, CATRep * iData );
   HRESULT DispatchCATRepCallbacks(RepEvent iEvent, CATSurfacicRep * iData );
   HRESULT DispatchCATRepCallbacks(RepEvent iEvent, CAT3DLodBagRep * iData );
   HRESULT DispatchCATRepCallbacks(RepEvent iEvent, CAT3DCurvedPipeRep * iData );
   HRESULT DispatchCATRepCallbacks(RepEvent iEvent, CAT3DCurveRep * iData );
   HRESULT DispatchCATRepCallbacks(RepEvent iEvent, CAT3DCylinderRep * iData );
   HRESULT DispatchCATRepCallbacks(RepEvent iEvent, CAT3DLodRep * iData );
   HRESULT DispatchCATRepCallbacks(RepEvent iEvent, CAT3DBagRep * iData );
   HRESULT DispatchCATRepCallbacks(RepEvent iEvent, CAT3DCustomRep * iData );
   HRESULT DispatchCATRepCallbacks(RepEvent iEvent, CAT3DLineRep * iData );
   HRESULT DispatchCATRepCallbacks(RepEvent iEvent, CAT3DPlanRep * iData );
   HRESULT DispatchCATRepCallbacks(RepEvent iEvent, CAT3DPointRep * iData );
   HRESULT DispatchCATRepCallbacks(RepEvent iEvent, CATMonoWireRep * iData );
   HRESULT DispatchCATRepCallbacks(RepEvent iEvent, CATVizMonoWireRep * iData );
   HRESULT DispatchCATRepCallbacks(RepEvent iEvent, CATVizUV3DRep * iData );
   HRESULT DispatchCATRepCallbacks(RepEvent iEvent, CATVizVertexBufferRep * iData );
   HRESULT DispatchCATVizVertexBufferCallbacks(RepEvent iEvent, CATVizVertexBuffer * iBufferBeingDeleted);

private:

   // Standard constructors
   // ---------------------
   CATRepCallbackManager ();

   // Copy constructor and equal operator
   // -----------------------------------
   CATRepCallbackManager (const CATRepCallbackManager & i_original);
   CATRepCallbackManager& operator=(const CATRepCallbackManager & i_original);
};

#endif
