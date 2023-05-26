/*
 *  CATMMImageProp.h
 *
 *  Created by sx6 on 12/07/2013.
 *  Copyright 2013 Dassault Systemes. All rights reserved.
 *
 */
#ifndef CATMMImageProp_H
#define CATMMImageProp_H


#include "CATMMediaPixelImage.h"
#include "CATMMRasterEngineDef.h"

/*
* Structure holding image properties 
*/
struct ExportedByCATMMediaPixelImage CATMMImageProp
{
  /*
  * Image format like TIFF, JPEG etc.
  */
  CATMMImageFormat _type;
  /*
  * Compression used like PACKBIT, CCITT G3, LZW etc.
  */
  CATMMImageCompression _comp;
  /*
  * Bits per pixel like BPP_1 for monocrome, BPP_32 for RGBA etc
  */
  CATMMImageBPP _bpp;

  float _frameDelay;

  int _iteration;

  CATMMImageProp();
};

#endif
