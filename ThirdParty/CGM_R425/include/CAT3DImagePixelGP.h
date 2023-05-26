#ifndef CAT3DImagePixelGP_H
#define CAT3DImagePixelGP_H

// COPYRIGHT DASSAULT SYSTEMES 1999

#include "SGInfra.h"

#include "CATDynamicGP.h"

class CATPixelImage;
class CATMathPointf;
class CATStreamer;

class ExportedBySGInfra CAT3DImagePixelGP : public CATDynamicGP
{
  friend class SGCGRStreamerFor3DImagePixelGP;
  friend class SGCGRNodesFactoryA;
 CATDeclareClass;

 public :

  CAT3DImagePixelGP ();
	 
  CAT3DImagePixelGP (const CATMathPointf &point, const CATPixelImage *image, const int xPixelOffset = 0, const int yPixelOffset = 0);
  
  inline void Get (float **point, CATPixelImage **image, int *xPixelOffset, int *yPixelOffset);
  
#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 27102022 " __FILE__ " Its forbidden to override Draw function.")
#endif
  virtual void Draw(CATRender& iRender) GP_FUNC_OVERRIDE_FINAL;

#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 27102022 " __FILE__ " Its forbidden to override ImmediateDraw function.")
#endif
  virtual void ImmediateDraw (CATRender &, const CATViewpoint *, const CATViewport *) GP_FUNC_OVERRIDE_FINAL;
 
  void SetAlphaMode (const int OnOff);

  virtual int DetailCulling(CATRender *render);

/** @nodoc
 *  Streams the graphic primitive of a Pixel image.
 * <br><b>Role:</b>This method streams a <tt>CAT3DImagePixelGP</tt> .
 *  @param   oStr
 *    The streamer used to stream the <tt>CAT3DImagePixelGP</tt>.
 *  @param   iSavetype
 *    <br><b>legal values</b>
 *    <ul>
 *         <li>0 the name of the GP will not be saved</li>
 *         <li>1 the name of the GP will be saved</li>
 *    </ul>
 */
   virtual void Stream(CATStreamer& oStr,int iSavetype=0);
   
/** @nodoc
 *  Unstreams the graphic primitive of a Pixel image.
 * <br><b>Role:</b>This method unstreams a <tt>CAT3DImagePixelGP</tt> .
 *  @param   iStr
 *    The streamer used to unstream the <tt>CAT3DImagePixelGP</tt>.
 */
   virtual void UnStream(CATStreamer& iStr);
 
 protected :

   virtual ~CAT3DImagePixelGP ();

 private :

   int _alpha, _xOffset, _yOffset;

   float _point[3];
   //float _ratioWH, _mmInSupportUnit, _supportWidth, _supportHeight;
 
   CATPixelImage *_image;

   CATBoolean ImmediateDrawPrint(CATRender& iRender, const CATViewpoint* iViewpoint, const CATViewport* iViewport);
};

inline void CAT3DImagePixelGP::Get (float **point, CATPixelImage **image, int *xOffset, int *yOffset)
{
 *point = (float *) _point;
 *image = (CATPixelImage*) _image;

 *xOffset = _xOffset;
 *yOffset = _yOffset;
}

#endif
   





