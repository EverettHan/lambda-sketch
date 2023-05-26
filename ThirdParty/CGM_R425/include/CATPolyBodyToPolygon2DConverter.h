//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2017
//=============================================================================
//
// CATPolyBodyToPolygon2DConverter
//
// Converts a CATPolyBody to a CATPolyPolygon2D by projecting the surfaces borders onto a plane.
//
//=============================================================================
// 2017-10-25 JXO: New.
// 2021-09-13 JXO: CATSoftwareConfiguration & SetTolerant & try to guess orientation of surface to output a CCW polygon
//=============================================================================
#ifndef CATPolyBodyToPolygon2DConverter_H
#define CATPolyBodyToPolygon2DConverter_H

#include "PolyBodyServices.h"

class CATPolyBody;
class CATPolyFace;
class CATIPolyMesh;
class CATMathPlane;
class CATPolyPolygonVertex3DPositionLayer;
class CATPolyPolygon2D;
class CATMathTransformation;
class CATMathBox2D;
class CATTolerance;
class CATSoftwareConfiguration;

// System
#include "CATListPV.h"
#include "CATErrorDef.h"

/**
 * This class converts a CATPolyBody to a CATPolyPolygon2D by projecting the surfaces borders onto a plane.
 */
class ExportedByPolyBodyServices CATPolyBodyToPolygon2DConverter
{
public:
  /** Constructor */
  CATPolyBodyToPolygon2DConverter ();
  /** Destructor */
  ~CATPolyBodyToPolygon2DConverter ();

public:
  /**
  * Converts a CATPolyBody to a CATPolyPolygon2D by projecting the surfaces borders onto a plane.
  * @param iBody
  *        Input body
  * @param oPolygons
  *        Output polygons, one polygon per face. To be all deleted by caller.
  * @param iPlane
  *        The plane onto which we project
  * @param p3DLayer
  *        Optional 3D layer that will contain the actual 3d positions of the vertices from the 2D polygon. It will be filled up by the operator.
  * @param pPos
  *        Optional transformation applied to the CATPolyBody.
  */
  HRESULT Project(const CATPolyBody & iBody, CATListPV & oPolygons, const CATMathPlane & iPlane, CATPolyPolygonVertex3DPositionLayer * p3DLayer = 0, const CATMathTransformation * pPos = 0, int iTryToGuessOrientation = 0);

  /**
  * Converts a CATPolyFace to a CATPolyPolygon2D by projecting the surface borders onto a plane.
  * @param iFace
  *        Input face
  * @param oPolygon
  *        Output polygon. To be deleted by caller.
  * @param iPlane
  *        The plane onto which we project
  * @param p3DLayer
  *        Optional 3D layer that will contain the actual 3d positions of the vertices from the 2D polygon. It will be filled up by the operator.
  * @param pPos
  *        Optional transformation applied to the surface.
  */
  HRESULT Project(const CATPolyFace & iFace, CATPolyPolygon2D *& oPolygon, const CATMathPlane & iPlane, CATPolyPolygonVertex3DPositionLayer * p3DLayer = 0, const CATMathTransformation * pPos = 0, int iTryToGuessOrientation = 0);

  /**
  * Converts a CATIPolyMesh to a CATPolyPolygon2D by projecting the surface borders onto a plane.
  * @param iMesh
  *        Input mesh
  * @param oPolygon
  *        Output polygon. To be deleted by caller.
  * @param iPlane
  *        The plane onto which we project
  * @param p3DLayer
  *        Optional 3D layer that will contain the actual 3d positions of the vertices from the 2D polygon. It will be filled up by the operator.
  * @param pPos
  *        Optional transformation applied to the mesh.
  */
  HRESULT Project(const CATIPolyMesh & iMesh, CATPolyPolygon2D *& oPolygon, const CATMathPlane & iPlane, CATPolyPolygonVertex3DPositionLayer * p3DLayer = 0, const CATMathTransformation * pPos = 0, int iTryToGuessOrientation = 0);

  /**
   * Activate tolerant mode with provided CATTolerance
   */
  void SetTolerant(const CATTolerance* iTol);

  /**
   * Set software config
   */
  void SetSoftwareConfiguration(CATSoftwareConfiguration* iSoftConfig);

  /**
   * Configure which coordinate will be set in the CATPolyPolygonVertex3DPositionLayer 
   * - if inProjectionPlane==true (default), the coordinate are the one projected on the CATMathPlane ( 2.5D )
   * - if inProjectionPlane==false, the coordinate are the one of the original mesh (or approximation if there is split bar in 2D)
   * */
  void Set3DLayerMode(bool inProjectionPlane = true);

private:
  HRESULT PrivateProject(const CATPolyFace & iFace, CATPolyPolygon2D *& oPolygon, const CATMathPlane & iPlane, CATPolyPolygonVertex3DPositionLayer * p3DLayer, const CATMathTransformation * pPos, CATMathBox2D & biggestbox, int iTryToGuessOrientation);
  HRESULT PrivateProject(const CATIPolyMesh & iMesh, CATPolyPolygon2D *& oPolygon, const CATMathPlane & iPlane, CATPolyPolygonVertex3DPositionLayer * p3DLayer, const CATMathTransformation * pPos, CATMathBox2D & biggestbox, int iTryToGuessOrientation);

  HRESULT PrivateProjectWires (const CATPolyBody& iBody, CATPolyPolygon2D*& iPolygon, const CATMathPlane & iPlane, CATPolyPolygonVertex3DPositionLayer * p3DLayer, const CATMathTransformation * pPos, CATMathBox2D & biggestbox, int iTryToGuessOrientation);

private:
  const CATTolerance* m_tol;
  CATSoftwareConfiguration* m_config;
  bool _3DLayerInProjectionPlane = true;
};


#endif // !CATPolyBodyToPolygon2DConverter_H
