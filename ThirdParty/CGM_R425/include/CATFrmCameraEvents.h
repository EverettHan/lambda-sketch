#ifndef CATFrmCameraEvents_h
#define CATFrmCameraEvents_h
// ========================================================================= 
// COPYRIGHT DASSAULT SYSTEMES  1996                                         
// ========================================================================= 
//                                                                           
// CATFrmCameraEvents :                                                      
//                                                                           
//                                                                           
// Jan  99. Creation                                     Y. WANG             
// Events:    
//	 CAMERA_SELECTED   (selected camera become current camera)
//	 CAMERA_ACTIVATED  (replace the current viewpoint by selected camera)
//	 CAMERA_MODIFIED   (replace the selected camera by current viewpoint)
//	 CAMERA_DELETED    (delete the selected camera)
//	 CAMERA_RENAMED    (change the name of selected camera)
//	 CAMERA_CREATED    (create a new camera from current viewpoint and add to camera list)
// ========================================================================= 
#include "CATAfrFoundation.h"
//#include "CATBaseUnknown.h"
#include "CATCallbackManager.h"
#include "CATEventSubscriber.h"

class  ExportedByCATAfrFoundation CATFrmCameraEvents : public CATEventSubscriber
{
   public:
      // Events define
      // -------------
      CATDeclareCBEvent(CAMERA_SELECTED);
      CATDeclareCBEvent(CAMERA_ACTIVATED);
      CATDeclareCBEvent(CAMERA_MODIFIED);
      CATDeclareCBEvent(CAMERA_DELETED);
      CATDeclareCBEvent(CAMERA_RENAMED);
      CATDeclareCBEvent(CAMERA_CREATED);
  
      // Constructor / Destructor
      // ------------------------
      CATFrmCameraEvents();
      virtual ~CATFrmCameraEvents();
};

#endif
