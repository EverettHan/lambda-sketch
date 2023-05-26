/*
*  CATMMPISpec.h
*
*  Created by o1x on 01/03/2013.
*  Copyright 2013 Dassault Systemes. All rights reserved.
*
*/
#ifndef CATMMPISpec_H
#define CATMMPISpec_H
// COPYRIGHT DASSAULT SYSTEMES 2013
#include "CATMMediaPixelImage.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATMMPITypeDesc.h"
#include "CATMMRasterEngineDef.h"
#include "CATPixelImage.h"


class CATMMImageMetadata;
class CATMMColorProfile;
class CATMMPIPixelColorSpec;
class CATMMPIColorSpace;

//enum CATPixelImageFormat;


/**
 * @ingroup groupPixelImageData
 **/
struct ExportedByCATMMediaPixelImage CATMMPISpec
{
public:
  enum CATMMPACKING {CATMMPACKED,CATMMUNPACKED};
  enum CATMMORIENTATION {CATMMTOPDOWN,CATMMBOTTOMUP};


  /*
   * Constructor, destructor
   * copy constructor and assignement operator
   */
  CATMMPISpec ();
  ~CATMMPISpec ();
  CATMMPISpec( const CATMMPISpec& other );
  /**
   * @param ipPixelColorSpec is consumed by CATMMPISpec (no AddRef).
   */
  CATMMPISpec(CATMMPIPixelColorSpec* ipPixelColorSpec);
  CATMMPISpec& operator=( const CATMMPISpec& other );

  void                          SetMetadata(CATMMImageMetadata *iExifData);

  /*
   * @return Returned CATMMPIColorSpace pointer has to be released after use.
   */
  CATMMPIColorSpace*            GetColorSpace();
  /*
   * @return CATMMColorProfile has to be released after use.
   */
  CATMMColorProfile*            GetColorProfile();
  /*
   * @param ipColorProfile. Will be AddRef.
   */
  void                          SetColorProfile(CATMMColorProfile* ipColorProfile);
  /*
   * @return CATMMPIPixelColorSpec has to be released after use.
   */
  CATMMPIPixelColorSpec*        GetPixelColorSpec();
  /*
   * @return const CATMMPIPixelColorSpec. Lifecycle is linked to CATMMISpec.
   */
  const CATMMPIPixelColorSpec*  GetConstPixelColorSpec() const;

  bool                          IsPacked() const;

  /*
   * Compression used like PACKBIT, CCITT G3, LZW etc.
   */
  CATMMImageCompression         _comp;
  /**
   * Image metadata class containing EXIF data
   */
  CATMMImageMetadata           *_pImageData;
  /*
   * Image Top Down or Bottom Up Orientations
   */
  CATMMORIENTATION              _orientation;
  CATBoolean                    _premultiplied_alpha;
  int                           _padding;
private:
  /*
   * Image packing
   * e.g.
   * RGBRGBRGBRGBRGBRGBRGBRGBRGBRGBRGBRGBRGBRGBRGBRGB - for packed components
   * RRRRRRRRRRRRRRRRGGGGGGGGGGGGGGGGBBBBBBBBBBBBBBBB - for unpacked components 
   */
  CATMMPACKING                  _packing;
  CATMMPIPixelColorSpec        *_pPixelColorSpec;
};



#endif  // CATMMPISpec_H
