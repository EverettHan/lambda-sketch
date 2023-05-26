#ifndef CATVisuServices_H
#define CATVisuServices_H

//******************************************************************************
//  CATIA Version 5 Release 3 Framework VFW
//  Copyright Dassault Systemes 1999
//******************************************************************************
//  Abstract:
//  ---------
//  services library  
//
//******************************************************************************
//  Usage:   
//  ------
//   
//
//******************************************************************************
class CATRep;
class CATViewpoint;
class CAT2DViewpoint;
class CAT3DViewpoint;
class CATViewer;
class CAT3DFaceGP;
#include "CATErrorDef.h"
#include "CATVisController.h"
#include "CATViewpointEditor.h"
#include "CATViz.h" // JQT : Added for applicative build impact : CATViz --> CATVisFoundation



ExportedByCATVisController HRESULT IsRepVisible( CATRep *rep, CAT2DViewpoint * vpoint);
ExportedByCATVisController HRESULT IsRepVisible( CATRep* rep, CAT3DViewpoint * vpoint);
ExportedByCATVisController HRESULT IsRepVisible( CATRep* rep, CATViewer * viewer);

ExportedByCATVisController HRESULT Get3DFaceVertices( CAT3DFaceGP * iFace,
                                                      float ** oVertices,
                                                      int    * oVerticesArraySize,
                                                      float ** oNormals,
                                                      int    * oNormalsArraySize);

ExportedByCATVisController HRESULT GetRepLayerFilter(CATRep* iRep, unsigned char oFilter[1024]);

// Transformations (translation, rotation, zoom): 1=lock; 0=unlock for touch only
// to remove , use Get/SetTransformationsEventsLocks with TRANSEVTLOCK_TOUCH_ZOOMS_LOCKED ... instead
// or remove the lock as the rotate is not applied if there is move on manipulator
ExportedByCATVisController HRESULT VisGetViewpointTransformationLocks(CATViewpoint * iViewpoint, int & oTranslationLock, int & oRotationLock, int & oZoomLock);
ExportedByCATVisController HRESULT VisSetViewpointTransformationLocks(CATViewpoint * iViewpoint, int   iTranslationLock, int   iRotationLock, int   iZoomLock);

/************************************************************************/
/************************************************************************/

namespace VisuA2X
{
  //=======================================================================
  ExportedByCATVisController HRESULT GetMousePositionLast(int& orX, int& orY, CATViewer* ipViewer);
  //=======================================================================
}

#endif
