#ifndef CATMshCallbacksMG_h
#define CATMshCallbacksMG_h

//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2022
//=============================================================================
//
// CATMshCallbacks :
// define the callbacks for MG sizemap
//
//=============================================================================
// February 2022  Creation                          Fabien Noblet (FNT1)
//=============================================================================

#include "CATMshMessage.h"
#include "CATMshInterrupt.h"
#include "CATMshThreads.h"
#include "CATMshMDataVertexSize.h"
#include "CATMshComplexDataMeshMatchingFunction.h"
#include "CATMshComplexData3DSizingFunction.h"
#include "CATMshCSMParameters.h"
#include <map>
#include <string>

extern "C" {
#include <meshgems/meshgems.h>
}

//
//==================================================
// Struct containing target size by TopoID
//==================================================
//
typedef struct TopoIDsSize_ {

  std::string *MeshType = nullptr;

  double MeshSize = 0;
  double GeomApp = 0;
  double Sag = 0;
  double Min = 0;
  double Max = 0;
  double Met[6] = { 0 };
  double Propagation = 0;
  double SizeAlong = 0;
  double SizeOrtho = 0;

  int LayerCount = 0;
  int HasMetric = 0;
  int HasAxi = 0;
  int HasBL = 0;

}TopoIDsSize;

//
//==================================================
// Struct for mesh matching functions
//==================================================
//
typedef struct MMatchingFunction_t_ {
  MeshMatchingFunction_t Fun;
  void *UserData;
}MMatchingFunction_t;

//
//==================================================
// Struct for mesh matching spec traduction
//==================================================
//
typedef struct DataForMeshMatching_t_ {
  size_t _ind = 0;
  size_t _indMax = 0;
  MMatchingFunction_t *_Functions = nullptr;
}DataForMeshMatching_t;

//
//==================================================
// Struct for local sizing traduction
//==================================================
//
typedef struct DataForSizemaps_t_ {

  size_t _ind = 0;
  size_t _indMax = 0;
  TopoIDsSize *_SizeArray = nullptr;
  std::map<int, size_t> _TopoIDmap;

  SizingFunction3DIso _FunIso;
  void *_UserDataIso = nullptr;
  SizingFunction3DAniso _FunAniso;
  void *_UserDataAniso = nullptr;

  CATMshVertexIndex *VertexMapping = nullptr;
  CATMshMDataVertexSize *VertexSize = nullptr;

  CATMshCSMParameters *_Param = nullptr;

}DataForSizemaps_t;

//
//==================================================
// Struct for CB traduction
//==================================================
//
typedef struct DataForComponentCB_t_ {

  CATMshInterruptCB _InterruptCB;
  void *_InterruptCBUserData;

  CATMshMessageCB _MessageCB;
  void *_MessageCBUserData;

  CATMshStartThreadCB _StartThreadsCB;
  void *_StartThreadsCBUserData;

  CATMshStopThreadCB _StopThreadsCB;
  void *_StopThreadsCBUserData;

}DataForComponentCB_t;

status_t IsoOnTopoID(integer TopoID, real *Size, void *UserData);
status_t IsoOnTopoIDFace(integer TopoID, real uv[2], real *Size, void *UserData);
status_t IsoOnTopoIDEdge(integer TopoID, real t, real *Size, void *UserData);

status_t GeoOnTopoID(integer TopoID, real *GeomApp, real *Sag, real *Min, real *Max, void *UserData);
status_t GeoOnTopoIDPoint(integer TopoID, real *Min, real *Max, void *UserData);

status_t Iso3D(real p[3], real *size, void *user_data);
status_t Aniso3D(real p[3], real *met, void *user_data);
status_t AnisoOnTopoID(integer TopoID, real *uv, real *oMet, void *UserData);
status_t IsoMeshVertex(integer vertex_id, real *size, void *user_data);
status_t AnisoMeshVertex(integer vertex_id, real *size, void *user_data);
status_t TypeOnFace(integer TopoID, generation_type_t *type, void *UserData);
status_t AxiAlongTopoID(integer TopoID, real *h1, real *h2, void *UserData);
status_t BLAroundTopoID(integer TopoID, integer *Nb, real *h1, real *h2, real *propa, void *UserData);

HRESULT DataForSizemapsMore(DataForSizemaps_t *CBData, int iSize);

status_t MMatchingFun(real xyz[3], real xyz_image[3], void *UserData);

status_t CADSurfStartThreadCB(void *UserData);
status_t CADSurfStopThreadCB(void *UserData);
status_t CADSurfInterruptCB(integer *interrupt_status, void *UserData);
status_t CADSurfMessageCB(message_t *msg, void *UserData);

#endif
