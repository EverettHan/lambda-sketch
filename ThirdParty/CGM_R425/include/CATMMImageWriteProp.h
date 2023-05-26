/*
 *  CATMMImageSize.h
 *
 *  Created by sx6 on 12/07/2013.
 *  Copyright 2013 Dassault Systemes. All rights reserved.
 *
 */
#ifndef CATMMImageWriteProp_H
#define CATMMImageWriteProp_H


#include "CATMMediaPixelImage.h"
#include "CATMMImageProp.h"
#include "CATMMImageMetadata.h"
#include "CATMMColorProfile.h"

/**
* Structure containing variables to be used while writing bitmap image 
* Default values for CATMMImageProp::_bpp=MMIBPP_BEST and _jpegQuality=80
*/
struct ExportedByCATMMediaPixelImage CATMMImageWriteProp
{
  /**
  * Image properties 
  */
  CATMMImageProp _prop;
  /**
  * Image metadata class containing EXIF data
  */
  const CATMMImageMetadata *_pImageData;
  /**
  * Image writing preferences
  */
  int _preferences;
  /**
  * JPEG quality. Value should be between 0 and 100, including 0 and 100.
  */
  int _jpegQuality;   
  /**
  * Dots per inch value to be written in image file
  */
  int _dpi;
  /**
  * Color profile
  */
 // CATMMColorProfile* _pColorProfile;

  // DRR4: for File Size Restriction
  CATBoolean _restrictSize;

  int _fileSize; // size in KB

  /**
  * For internal use only
  */
  float _private[3];

  CATMMImageWriteProp();
};

#endif
