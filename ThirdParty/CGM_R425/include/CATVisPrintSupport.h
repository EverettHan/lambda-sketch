/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2009


#ifndef CATVisPrintSupport_H
#define CATVisPrintSupport_H

//#include "SceneGraphManager.h"
#include "CATVisFoundation.h"
#include "CATSysDataType.h" // NULL definition
#include "list.h"

class CATSupport;
class CATPixelImage;
class CATVisInfiniteEnvPrintOverload;
class CATVisInfiniteEnvironmentOverload;
class VisSupportLayout;

class ExportedByCATVisFoundation CATVisPrintSupport
{
public:
  CATVisPrintSupport();
  virtual ~CATVisPrintSupport();

  // Define the maximum size of each tile when the size of the output picture is very big
  // By default, it is disable (tilesize=0). It means there is only one tile with the same size than the ouput.
  void SetTilingSize          (unsigned int iTileSize);

  // Allow to generate a hdr output (RGBA_f or RGB_f)
  // By default, it isn't enable
  void SetHDROutput           (int iOnOff); 

  // Allow to add an alpha chanel to the outpout
  // In this cas output is RGBA instead of RGB
  // By default, it isn't enable
  void SetTransparentMode     (int iOnOff); 

  // Force the background to be uniform and white
  // By default, it isn't enable
  void SetWhiteBackgroundMode (int iOnOff);

  void AddOverload(CATVisInfiniteEnvironmentOverload* iOverload);

  // Remove all viewpoints other than main viewpoint in the output picture
  // By this way, it is possible to filter graph, CID, ...
  // By default, only main viewpoint is visible
  void ShowOnlyMainViewpoint  (int iOnOff);

  // Deactivate highlight in the output picture
  // By this was, if an object is selected, it won't be highlighted in the picture.
  // By default, highlight is deactivated
  void DeactivateHighlight    (int iOnOff);
  
  // Deactivate prehighlight in the output picture
  // By this was, if an object is preselected, it won't be highlighted in the picture.
  // By default, prehighlight is deactivated
  void DeactivatePreHighlight (int iOnOff);

  // Deactivate graduated background on output picture
  // By default, it is enable
  void DeactivateGraduatedBackground(int iOnOff);
  
  // Generate a picture from a specific support
  // iPicWidth: width of the output picture
  // iPicHeight: height of the output picture
  CATPixelImage* GeneratePicture(CATSupport& iSupport, unsigned int iPicWidth, unsigned int iPicHeight);

  // Generate a picture from a specific support
  // iZoom: ratio between the size of input support and size of the output picture
  CATPixelImage* GeneratePicture(CATSupport& iSupport, float iZoom);
  
  // Generate a picture from a specific support
  // ioOutImg is used to directly generate the picture inside without any memory allocation.
  // its size a and its format are directly used.
  // Format must be RGB, RGBA, RGB_f, or RGBA_f
  bool GeneratePicture(CATSupport& iSupport, CATPixelImage* ioOutImg);

private:
  CATPixelImage* _GeneratePicture(CATSupport& iSupport, unsigned int iPicWidth, unsigned int iPicHeight, float iZoom, CATPixelImage* iOutImg = NULL);

  unsigned int  _tilingSize;
  unsigned int  _whiteMode;
  unsigned int  _pBufferMode;
  unsigned int  _showOnlyMainViewpoint;
  unsigned int  _transparentMode;
  unsigned int  _hdrOutput;
  unsigned int  _highlightDeactivation, _prehighlightDeactivation;
  unsigned int  _graduatedBgDeactivaton;
  list<CATVisInfiniteEnvironmentOverload> _overloads;
};

#endif // CATVisPrintSupport_H
