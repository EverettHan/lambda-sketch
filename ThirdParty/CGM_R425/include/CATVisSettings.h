/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1999
//
//==============================================================================
// Abstract
// --------
// 
//==============================================================================
// Usage
// -----
// 
//==============================================================================
// History
// -------
//     - Mar 4, 1999: Created.
//==============================================================================
#ifndef CATVisSettings_H
#define CATVisSettings_H

#include "BigLittle.h"

#define SHOW_LOD                0x01
#define SHOW_AXIS               0x02
#define SHOW_TESSELATION        0x04
#define SHOW_G2_EDGES           0x08
#define SHOW_EDGES              0x10
#define SHOW_FREE_EDGES         0x20
#define SHOW_SURFACE_POINTS     0x40
#define SHOW_FREE_POINTS        0x80

typedef union
{
  unsigned char basic;
  struct {
#ifdef _ENDIAN_LITTLE
    unsigned showLOD           : 1;
    unsigned showAxis          : 1;
    unsigned showTesselation   : 1;
    unsigned showG2Edges       : 1;
    unsigned showEdges         : 1;
    unsigned showFreeEdges     : 1;
    unsigned showSurfacePoints : 1;
    unsigned showFreePoints    : 1;
#else
    unsigned showFreePoints    : 1;
    unsigned showSurfacePoints : 1;
    unsigned showFreeEdges     : 1;
    unsigned showEdges         : 1;
    unsigned showG2Edges       : 1;
    unsigned showTesselation   : 1;
    unsigned showAxis          : 1;
    unsigned showLOD           : 1;
#endif
  } extend;
} VisSettingsStruct;

#define CATVisuMode   0x11
#define CATDesignMode 0x11
#define CATEditMode   0xFA

//#include "CATBaseUnknown.h"
//#include "list.h"

#include "SceneGraphManager.h"
extern unsigned int ExportedBySceneGraphManager CATVisGetSettings         ();
extern unsigned int ExportedBySceneGraphManager CATVisGetFreePointMode    ();
extern unsigned int ExportedBySceneGraphManager CATVisGetSurfacePointMode ();
extern unsigned int ExportedBySceneGraphManager CATVisGetFreeEdgeMode     ();
extern unsigned int ExportedBySceneGraphManager CATVisGetEdgeMode         ();
extern unsigned int ExportedBySceneGraphManager CATVisGetG2EdgeMode       ();
extern unsigned int ExportedBySceneGraphManager CATVisGetTesselationMode  ();
extern unsigned int ExportedBySceneGraphManager CATVisGetAxisMode         ();
extern unsigned int ExportedBySceneGraphManager CATVisGetLODMode          ();

extern void         ExportedBySceneGraphManager CATVisSetSettings         (const unsigned int);
extern void         ExportedBySceneGraphManager CATVisSetFreePointMode    (const unsigned int);
extern void         ExportedBySceneGraphManager CATVisSetSurfacePointMode (const unsigned int);
extern void         ExportedBySceneGraphManager CATVisSetFreeEdgeMode     (const unsigned int);
extern void         ExportedBySceneGraphManager CATVisSetEdgeMode         (const unsigned int);
extern void         ExportedBySceneGraphManager CATVisSetG2EdgeMode       (const unsigned int);
extern void         ExportedBySceneGraphManager CATVisSetTesselationMode  (const unsigned int);
extern void         ExportedBySceneGraphManager CATVisSetAxisMode         (const unsigned int);
extern void         ExportedBySceneGraphManager CATVisSetLODMode          (const unsigned int);

/*
extern list<IID>  & ExportedBySceneGraphManager CATVisGetMaterialIID();
extern void         ExportedBySceneGraphManager CATVisSetMaterialIID();
*/

extern unsigned int ExportedBySceneGraphManager CATVisGetUVDataMode ();
extern void         ExportedBySceneGraphManager CATVisSetUVDataMode (const unsigned int);

extern void         ExportedBySceneGraphManager CATVisSettingsDump();

#endif // CATVisSettings

