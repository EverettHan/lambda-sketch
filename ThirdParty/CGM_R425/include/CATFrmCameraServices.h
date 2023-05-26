#ifndef CATFRMCAMERASERVICES_H
#define CATFRMCAMERASERVICES_H

// COPYRIGHT DASSAULT SYSTEMES	<1999>
//=============================================================================
// Function:
//
//=============================================================================
// Usage Notes:
//
//=============================================================================
#include "CATAfrFoundation.h"

#include "CATListOfCATICamera.h"
#include "CATUnicodeString.h"
#include "CATViewpoint.h"
#include "CATPathElement.h"
#include "CATMathTransformation.h"
#include "CATICamera.h"

class CATViewer;
class CATFrm3DCamera;

ExportedByCATAfrFoundation CATLISTP(CATICamera) CreateStandardCameraList3DViewer(CATVisWorldOrientation iworldOrientation= CATVis_World_Orientation_ZUp_YRight);

ExportedByCATAfrFoundation CATLISTP(CATICamera) CreateStandardCameraList2DViewer();

ExportedByCATAfrFoundation CATLISTP(CATICamera) CreateStandardCameraListGraphViewer();

ExportedByCATAfrFoundation CATLISTP(CATICamera) CreateStandardCameraList (CATViewer * viewer);     

ExportedByCATAfrFoundation CATICamera * CreateCameraFromViewer (CATViewer * viewer);     

ExportedByCATAfrFoundation CATICamera * CreateCameraFromViewpoint (CATViewpoint & viewpoint);     

ExportedByCATAfrFoundation CATICamera * CreateDefaultCamera (CATCameraType = CAT3DUnknownCamera);     

ExportedByCATAfrFoundation int  ApplyStandardCamera (CATViewer * viewer, CATUnicodeString stdCameraName);     

ExportedByCATAfrFoundation void ApplyCameraToViewer (CATViewer * viewer, CATICamera * camera);     

ExportedByCATAfrFoundation void ApplyCameraToViewpoint (CATViewpoint & viewpoint, CATICamera * camera, int isReframe=0);     

//CATFrm3DCamera * AssociateViewToStandardCamera(int CameraID, CATUnicodeString stdCameraName);

int GetModelTransformation (CATPathElement & iPath, CATMathTransformation & oModelMatrix);

ExportedByCATAfrFoundation CATLISTP(CATICamera) CreateStandardCameraListFromSetting(CATVisWorldOrientation iworldOrientation = CATVis_World_Orientation_ZUp_YRight);

CATICamera * ApplyCameraToAxis(CATICamera * iCamera, CATMathAxis iAxis);

CATMathAxis GetLocalAxis();

CATBoolean IsCameraValid(CATICamera * iCamera);

#endif

