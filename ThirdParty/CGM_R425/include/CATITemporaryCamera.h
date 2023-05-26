#ifndef CATITemporaryCamera_H
#define CATITemporaryCamera_H

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATAfrFoundation.h"
//===========================================================================
// General Interface for temporary Viewpoints Manipulation
//===========================================================================
#include "CATBaseUnknown.h"
#include "CATListOfCATICamera.h"

class CATICamera;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrFoundation IID IID_CATITemporaryCamera;
#else
extern "C" const IID IID_CATITemporaryCamera;
#endif
class  ExportedByCATAfrFoundation CATITemporaryCamera : public CATBaseUnknown
{
   CATDeclareInterface;
   
   public:
      virtual CATLISTP(CATICamera) & GetCameraList()=0 ;

      virtual void         AddCameraToList(CATICamera * camera)=0 ;
      virtual void         RemoveCameraFromList(CATICamera * camera)=0 ;
};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------
CATDeclareHandler(CATITemporaryCamera, CATBaseUnknown);

#endif
