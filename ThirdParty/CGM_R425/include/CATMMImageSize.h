/*
 *  CATMMImageSize.h
 *
 *  Created by sx6 on 12/07/2013.
 *  Copyright 2013 Dassault Systemes. All rights reserved.
 *
 */
#ifndef CATMMImageSize_H
#define CATMMImageSize_H


#include "CATMMediaPixelImage.h"

/*
* Structure holding image sizes 
*/
struct ExportedByCATMMediaPixelImage CATMMImageSize
{
  int _width;
  int _height;
  int _xDpm; // Dots per meter
  int _yDpm; // Dots per meter
  int _xPos; 
  int _yPos;

  CATMMImageSize();
};

#endif
