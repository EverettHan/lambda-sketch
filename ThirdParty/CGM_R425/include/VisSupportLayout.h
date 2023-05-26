#ifndef VisSupportLayout_H
#define VisSupportLayout_H

// COPYRIGHT DASSAULT SYSTEMES 2010

//
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 2010
//------------------------------------------------------------------------------
// Abstract :   basic class which contains a list of viewpoint to be drawn
// ----------   in a specific way. 
//              Viewpoint contains representations which are materialized differently 
//              in fonction of the kind of CATSupport instance.
//              This specific support is used as a multi-support. The viewpoint are drawn 
//              under several support called sub support. Each sub support/tile is defined in a 
//              global layout.
//
//------------------------------------------------------------------------------
// Usage :      is used for printing with tiling.
// -------      
//
//------------------------------------------------------------------------------
// Main methods :         
// --------------
//                definition of tile position
//
//                viewpoint management
//
//                tile draw 
//
//------------------------------------------------------------------------------
// Class :      VisSupportLayout
// -------        CATVizBaseIUnknown
//
//------------------------------------------------------------------------------

#include "CATVisFoundation.h"
#include "CATVizBaseIUnknown.h"
#include "CATSupport.h"
class CATPixelImage;
class CAT2DCustomRep;
class CAT2DBagRep;
class CAT2DViewpoint;
class VisSupportData;
class CATVisInfiniteEnvPrintOverload;


class ExportedByCATVisFoundation VisSupportLayout : public CATVizBaseIUnknown
{
  friend class CATVisPrintSupport;

public:
  
  /**
   * Constructs the support layout from an initial support.
   * @param iRefSupport
   *  initial support containing the data to draw.
   * @param iZoom
   *  zoom to apply to the initial support.
   */
  VisSupportLayout (const CATSupport& iRefSupport, const float iZoom);
  
  /**
   * Constructs the support layout from an initial support.
   * @param iRefSupport
   *  initial support containing the data to draw.
   * @param iXPosOnRefSupport
   * @param iYPosOnRefSupport
   * @param iWidthOnRefSupport
   * @param iHeightOnRefSupport
   *  selection into the initial support. Only a portion of the initial support will be drawn.
   * @param iZoom
   *  zoom to apply to the initial support.
   */
  VisSupportLayout (const CATSupport& iRefSupport, const int iXPosOnRefSupport, const int iYPosOnRefSupport, const int iWidthOnRefSupport, const int iHeightOnRefSupport, const float iZoom);

  /**
   * Constructs the support layout.
   * @param iWidth
   *  pixel width.
   * @param iHeight
   *  pixelheight.
   */
  VisSupportLayout (const int iWidth, const int iHeight);
  
  /**
   * Destructor.
   */
  virtual ~VisSupportLayout ();

  /**
   * Retrieve the data of the support to draw: viewpoints to draw, draw options...
   * @param opSupportData
   * support data
   * opSupportData should be released by caller
   */
  virtual HRESULT GetSupportData (VisSupportData*& opSupportData);

  /**
   * Modify the zoom applied to the initial support.
   * Call this method between two drawns, so after a EndDraw call.
   * @param iZoom
   *  zoom to apply to the initial support.
   */
  virtual HRESULT SetZoom (const float iZoom);

  /**
   * Set overlapping mode.
   * @param iTileOverlapMode
   *  if set to 0, none tiles overlapping will be used if it is not necessary.
   *  if set to 1, a tiles overlapping will be used, and 
   *  GetTileGrab will return the grab with overlapping.
   *  GetTileLayout enable you ti retrieve overlapping use in order to create a sub image.
   *  If an overlapping is asked, the overlapping will not be efectiv for tiles on the support borders.
   *  The overlaps append only inside the support.
   */
  virtual HRESULT SetTileOverlapMode (const int iTileOverlapMode);

  /**
   * Set the tile size.
   * @param iTileWidth
   * @param iTileHeight
   *  tile size to set before the StartDraw().
   */
  virtual HRESULT SetTileSize (const int iTileWidth, const int iTileHeight);

  /**
   * Get the size of all the tiles layout.
   * @param oGrabWidth
   * @param oGrabHeight
   * total grab size
   */
  virtual HRESULT GetGrabSize (int& oGrabWidth, int& oGrabHeight) const;

  /**
   * Get the layouting of the current tile.
   * @param oXTilePos
   * @param oYTilePos
   * @param oTileWidth
   * @param oTileHeight
   * tile position and size
   */
  virtual HRESULT GetTileLayout (int& oXTilePos, int& oYTilePos, int& oTileWidth, int& oTileHeight) const;

  /**
   * Get the layouting of the current tile.
   * @param oXTilePos
   * @param oYTilePos
   * @param oTileWidth
   * @param oTileHeight
   * @param oTileLeftOverlap
   * @param oTileRightOverlap
   * @param oTileBottomOverlap
   * @param oTileTopOverlap
   * tile position, size and overlapping. The overlapping is to add to tile size.
   */
  virtual HRESULT GetTileLayout (int& oXTilePos, int& oYTilePos, int& oTileWidth, int& oTileHeight, int& oTileLeftOverlap, int& oTileRightOverlap, int& oTileBottomOverlap, int& oTileTopOverlap) const;

  /**
   * Get the tile grab after its draw.
   * @param opPixelImage
   * pixel image generated during the draw of a tile
   * opPixelImage should be released by caller
   * This pixel image could be used for the next drawn
   */
  virtual HRESULT GetTileGrab (CATPixelImage*& opPixelImage);

  /**
   * Get the tile's count.
   * @param oTilesCount
   * tile's count
   * The tile count is computed by StartDraw method.
   * If this method was not called before, GetTileCount will return 0.
   */
  virtual HRESULT GetTilesCount (int& oTilesCount) const;

  /**
   * Start the support layout draw
   */
  virtual HRESULT StartDraw();

  /**
   * Is there another support to draw, switch to next tile
   */
  virtual HRESULT NextTile();

  /**
   * Draw the current tile
   */
  virtual HRESULT DrawTile(CATPixelImage* iTileImage = NULL);

  /**
   * End the layout draw
   */
  virtual HRESULT EndDraw();
  
private:

  /**
   * Constructs the support layout.
   * @param iWidth
   *  pixel width.
   * @param iHeight
   *  pixelheight.
   */
  VisSupportLayout (const CATSupport& iRefSupport, const int iWidth, const int iHeight);

  // release
  HRESULT ReleaseTilesLayout();
  HRESULT ReleaseCurrentTile();
  HRESULT ReleaseGlobalSupport();
  
  // quel mode doit-on utiliser pour le trace
  HRESULT ComputeSupportDrawMode();

  // Set the draw mode of the support.
  /**
    * support drawn mode
    * @param VisDrawMode_SoftwareDriver
    *   the draw is done in generic driver.
    * @param VisDrawMode_OffScreenRenderingWithPixelBuffer
    *   the draw is done with off-screen rendering with OpenGL pixel buffer.
  */
  enum VisSupportDrawMode { VisDrawMode_Default, VisDrawMode_SoftwareDriver, VisDrawMode_OffScreenRenderingWithPixelBuffer };
  HRESULT SetSupportDrawMode(VisSupportDrawMode iSupportDrawnMode);
    
  /**
  * Activate creation of RGBA_f instead of RGBA output pictures
  */
  void ActivateHDROutput(int iOnOff);

  /**
  * Activate/deactivate the output picture alpha channel (active by default)
  */
  void ActivateAlphaOutput(int iOnOff);

  /**
  * Deactivate highlight in output picture
  */
  void DeactivateHighlight();
    
  /**
  * Deactivate prehighlight in output picture
  */
  void DeactivatePreHighlight();

  // Compute tiles size, overlap, layout
  HRESULT ComputeTilesLayout();
  // Compute tiles layout from tile size
  HRESULT ComputeTilesLayout(const int iTileWidthMax, const int iTileHeightMax, const int iTileOverlapSize);

  // Create the big support
  HRESULT CreateGlobalSupport();

  // Create the tile support
  HRESULT CreateTileSupport(int iXTilePosition, int iYTilePosition, int iWidthTile, int iHeightTile, 
                            int iLeftOverlapTile, int iRightOverlapTile, int iBottomOverlapTile, int iTopOverlapTile, CATPixelImage* iTileImage);

private:

  // donnees trace de reference
  VisSupportData* _pRefSupportData;

  // support global a tracer
  CATSupport* _pGlobalSupport;

  // taille du support de reference
  float _RefSupportWidth;
  float _RefSupportHeight;

  // zoom a appliquer par rapport a la reference pour augmenter la taille du trace
  float _Zoom;

  // prise en compte d'une sous-partie du support
  int _XPosOnSupport;
  int _YPosOnSupport;
  int _WidthOnSupport;
  int _HeightOnSupport;

  // tuilage
  int _TileWidth;
  int _TileHeight;
  int _TilesCount;
  int* _pTilesPositionTab;
  int* _pTilesSizeTab;
  char* _pTilesOverlapTab;
  
  // tuile en cours de trace
  int _CurrentTileIndex;
  CATPixelImage* _pCurrentTileImage;
  CATSupport* _pCurrentTileSupport;
  
  // draw mode
  VisSupportDrawMode _DrawnMode;
  
  // tile overlap
  int _TileOverlapMode; // 0 pas d'overlap, 1 overlap car SSAO ou mirroring, 2 overlap demande par l'application
  float _TileOverlapRatio;
  int _TileOverlapSize;
  
  // print overload
  CATVisInfiniteEnvPrintOverload* _pPrintEnvOverload;
  
  int _hdrOutput;
  int _alphaOutput;
  int _highlightDeactivation, _prehighlightDeactivation;
};
#endif
		
