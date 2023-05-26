#ifndef CATIPERSISTENTCAMERA_H
#define CATIPERSISTENTCAMERA_H

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATAfrFoundation.h"
//===========================================================================
// General Interface for persistent Viewpoints Manipulation
//===========================================================================
#include "CATBaseUnknown.h"
#include "CATListOfCATICamera.h"

#include "CATICamera.h"
//#include "CATIContainer.h"
#include "CATUnicodeString.h"

class CATIContainer;
class CATIContainer_var;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrFoundation IID IID_CATIPersistentCamera;
#else
extern "C" const IID IID_CATIPersistentCamera;
#endif
class  ExportedByCATAfrFoundation CATIPersistentCamera : public CATBaseUnknown
{
   CATDeclareInterface;
   
   public:
      virtual CATICamera * GetDefaultCamera() =0 ;
      virtual void         SetDefaultCamera(CATICamera * camera)=0 ;

      virtual CATLISTP(CATICamera) & GetCameraList()=0 ;

      virtual void         AddCameraToList(CATICamera * camera)=0 ;
      virtual void         RemoveCameraFromList(CATICamera * camera)=0 ;

      virtual CATICamera * CreateCamera(CATICamera * camera=NULL,int iLocalCamera=0)=0 ;
      virtual void         DeleteCamera(CATICamera * camera)=0 ;

      virtual CATIContainer * GetCameraContainer() =0;

      virtual CATICamera_var CreateExternalCamera( const CATIContainer_var& container, const CATUnicodeString& name ) =0;
};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------
CATDeclareHandler(CATIPersistentCamera, CATBaseUnknown);

#endif
