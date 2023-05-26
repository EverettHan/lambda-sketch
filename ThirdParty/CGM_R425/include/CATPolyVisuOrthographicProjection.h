// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyVisuOrthographicProjection.h
//
//===================================================================
//
// Usage notes: Methods that allows to generate textures (color,
// normal, displacement maps) according to a given orthographic
// frustum/projector CATPolyVisuOrthographicProjector. See this class
// for more details on orthographic projectors or orthographic
// frustum.
//
//===================================================================
//
// Dec 2008  Creation: XXC (from CATPolyVisuFrustumProjection.h)
//===================================================================

#ifndef CATPolyVisuOrthographicProjection_H
#define CATPolyVisuOrthographicProjection_H

#include "CATErrorDef.h"
#include "CATPolyVisuProjectionOper.h"
#include "CATBoolean.h"

class CAT3DRep;
class CATMathPointf;
class CATPixelImage;
class CATPolyBody;
class CATPolyVisuOrthographicProjector;

class ExportedByPolyVisuProjectionOper CATPolyVisuOrthographicProjection
{
public:  
  //constructor and destructor  
  CATPolyVisuOrthographicProjection();
  virtual ~CATPolyVisuOrthographicProjection();

public:
  //main methods

  /** Generates, from a view of a 3D model iOriginalRep, textures to
   *  be mapped to one of the six faces of a box bounding this 3D
   *  model. All required information reporting to the box are
   *  recorded in the projector which has already been initialized
   *  according to this box. The number of the front face iNumFace
   *  then allows to determine an orthographic frustum from this
   *  box. Six orthographic frustums (for the six faces of the box)
   *  are possible from one projector/box. Textures are output in
   *  different images.
   *@param iNumFace: number of the face, from 1 to 6 included, of the
   *box (caracterized by the projector iProjector) according to which
   *textures are supposed to be mapped to the box. The face #iNumFace
   *of the box is considered as the front face of the orthographic
   *frustum. Is of use to filter informations through the projection
   *operator iProjector and then to obtain the appropriate projection.
   *@param iOriginalRep: Original model from which textures are
   *generated.
   *@param iProjector: Projection operator. Contains all data
   *reporting to the box bounding the original 3D model iOriginalRep
   *and to which textures are to be mapped. Projects points from the
   *world view coordinate system to the orthographic frustum system,
   *used to first generate then map textures to the box according to
   *its face #iNumFace.
   *@param ioTextureImage: Output for the color texture. This image
   *must be allocated before this method call.
   *@param ioNormalMapImage: Output for the normal texture. This image
   *must be allocated before this method call.
   *@param ioDisplMapImage: Output for the displacement texture. This
   *image must be allocated before this method call.
   *@return S_OK if everything is right, E_FAIL otherwise.
   */
  HRESULT RunView(const int iNumFace, const CAT3DRep& iOriginalRep,
                  const CATPolyVisuOrthographicProjector& iProjector,
                  CATPixelImage* ioTextureImage,
                  CATPixelImage* ioNormalMapImage,
                  CATPixelImage* ioDisplMapImage) const;

  /** Projects each vertex of each mesh of the given CATPolyBody
   *  iPolyBody in an orthographic frustum, given by the projector
   *  iProjector and the number iNumFace of one of the faces of the
   *  box associated to the projector, then output the result in the
   *  texture coordinates layer of the corresponding mesh. The box
   *  should bounds the given CATPolyBody.
   *@param iNumFace: the number of the face of the bounding box,
   *determining a unique orthographic frustum for the projection.
   *@param iPolyBody: the CATPolyBody to project.
   *@param iProjector: the projector initialized with the appropriate
   *bounding box, from which the orthographic frustum is determined.
   *@return S_OK if everything is right, E_FAIL otherwise.
   */
  HRESULT ProjectPolyBody(const int iNumFace, CATPolyBody& iPolyBody, const CATPolyVisuOrthographicProjector& iProjector) const;

 private:

  /** Generation of a texture (color or normal) by a reverse mapping
   *  of a 3D model in an orthographic frustum to a texture, designed
   *  to be mapped to this frustum. Begins with a standard shot
   *  colorShot of the 3D model then maps each pixel of the shot image
   *  to the resulting texture ioTextureImage thanks to the position
   *  of the point of the model corresponding to the pixel, projected
   *  in the frustum.
   *@param iNumFace: number of the face/frustum to use in the
   *projector iProjector.
   *@param iWidth: Width of the positionShot array (see below).
   *@param iHeight: Height of the positionShot array (see below).
   *@param colorShot: Shot of an original 3D model.
   *@param positionShot: Array of positions, of the size of the shot
   *colorShot, which makes a correspondance between each pixel of the
   *shot and the position (in the world space) of the point of the
   *model corresponding to the pixel.
   *@param iProjector: projection operator that determines, with the
   *face number iNumFace, the orthographic frustum used to generate
   *the texture.
   *@param ioTexture: the resulting preallocated texture. A pixel of
   *it with coordinates (i,j) in the image corresponds to any points
   *in the orthographic frustum with coordinates
   *(2*i/iWidth-1,2*j/iHeight-1,w), w from -1 to 1, in the local
   *frustum coordinates system.
   */
  HRESULT PrintTexture(const int iNumFace, int iWidth, int iHeight,
                       const CATPixelImage& colorShot,
                       float* positionShot,
                       const CATPolyVisuOrthographicProjector& iProjector,
                       CATPixelImage& ioTexture)const ;

  /** As PrintTexture but specific for displacement textures. The
   *  displacement is given from the third coordinate (the depth) of
   *  each position found in the position array after its projection
   *  in the orthographic frustum coordinate system.
   *@param iNumFace: number of the face/frustum to use in the
   *projector iProjector.
   *@param iWidth: Width of the positionShot array (see below).
   *@param iHeight: Height of the positionShot array (see below).
   *@param positionShot: A "position shot", as an array of positions,
   *which makes a correspondance between each pixel of a shot of a 3D
   *model and the position (in the world space) of the point of this
   *model corresponding to the pixel.
   *@param iProjector: projection operator that determines, with the
   *face number iNumFace, the orthographic frustum used to generate
   *the texture.
   *@param ioTexture: the resulting preallocated texture. A pixel of
   *it with coordinates (i,j) in the image and with depth value k
   *corresponds to the point, in the orthographic frustum, with
   *coordinates (2*i/iWidth-1,2*j/iHeight-1,2*k/255-1) in the local
   *frustum coordinates system.
   */
  HRESULT PrintDisplacement(const int iNumFace, int iWidth, int iHeight,
                            float* positionShot,
                            const CATPolyVisuOrthographicProjector& iProjector,
                            CATPixelImage& ioDispMap)const ;

  /** Return the coordinates of a point iPos, expressed in the world
   *  coordinates system, in the frustum coordinates system.

   *@param iNumFace: number of the face/frustum to use in the
   *projector iProjector.
   *@param iPos: position, in the world space, of a 3D point.
   *@param iProjector: projection operator that determines, with the
   *face number iNumFace, the orthographic frustum used to project the
   *point iPos.
   *@param oTexX: X coordinate of iPos in the local frustum
   *coordinates system translated in the range [0;1].
   *@param oTexY: Y coordinate of iPos in the local frustum
   *coordinates system translated in the range [0;1].
   *@param oTexZ: Z coordinate of iPos in the local frustum
   *coordinates system translated in the range [0;1].
   *@param ioFound: TRUE if iPos is in the frustum, FALSE otherwise.
   */
  HRESULT FindPositionFromPoint(const int iNumFace, const CATMathPointf& iPos,
                                const CATPolyVisuOrthographicProjector& iProjector,
                                float& oTexX, float& oTexY, float& oTexZ,
                                CATBoolean& ioFound) const;

};

#endif
