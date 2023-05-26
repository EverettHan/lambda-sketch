#ifndef CATMMMETADATAIMAGE360_H
#define CATMMMETADATAIMAGE360_H

#include "CATMMediaPixelImage.h"
#include "CATMMCPropertyType.h"

struct CATParamDef
{
  CATParamDef(CATUnicodeString iName, CATMMCPropertyType iType) :name(iName), type(iType) {};
  CATUnicodeString    name;
  CATMMCPropertyType  type;
};

//                                                          |                              |   Type       |  Default value   |   Obligatoire*   
//----------------------------------------------------------|------------------------------|--------------|------------------|------------------
  #define meta_s_ProjectionType                 CATParamDef("ProjectionType"               , stringType)//|"equirectangular" |       OUI
  #define meta_b_UsePanoramaViewer              CATParamDef("UsePanoramaViewer"            ,booleanType)//| True             |      (non)
  #define meta_s_CaptureSoftware                CATParamDef("CaptureSoftware"              , stringType)//|""                |       non
  #define meta_s_StichingSoftware               CATParamDef("StichingSoftware"             , stringType)//|""                |       non
//#define meta_d_PoseHeadingDegrees             CATParamDef("PoseHeadingDegrees"           , doubleType)//| 180.0            |pour Google Maps
//#define meta_?_FirstPhotoDate                 CATParamDef("FirstPhotoDate"               ,    ???????)//|                  |       non
//#define meta_?_LastPhotoDat                   CATParamDef("LastPhotoDat"                 ,    ???????)//|                  |       non
  #define meta_i_CroppedAreaImageWidthPixels    CATParamDef("CroppedAreaImageWidthPixels"  ,    intType)//|                  |      (OUI)
  #define meta_i_CroppedAreaImageHeightPixels   CATParamDef("CroppedAreaImageHeightPixels" ,    intType)//|                  |      (OUI)
  #define meta_i_FullPanoWidthPixels            CATParamDef("FullPanoWidthPixels"          ,    intType)//|                  |      (OUI)
  #define meta_i_FullPanoHeightPixels           CATParamDef("FullPanoHeightPixels"         ,    intType)//|                  |      (OUI)
  #define meta_i_CroppedAreaLeftPixels          CATParamDef("CroppedAreaLeftPixels"        ,    intType)//|                  |      (OUI)
  #define meta_i_CroppedAreaTopPixels           CATParamDef("CroppedAreaTopPixels"         ,    intType)//|                  |      (OUI)

// *:Dixit https://developers.google.com/streetview/spherical-metadata?hl=fr

#define kXMP_NS_GPano      "http://ns.google.com/photos/1.0/panorama/"
#define kXMP_Prefix_GPano  "GPano"


class CATMMMetadata;
class CATPixelImage;
class CATMMCConstPropertiesPrototype;

class ExportedByCATMMediaPixelImage CATMMMetadataImage360
{
public:
  CATMMMetadataImage360(CATPixelImage *pPixelImage);
//CATMMMetadataImage360(const SXMPMeta *ipMeta);
  ~CATMMMetadataImage360();

  /**
   * Returned pointer has to be released after use.
   */
  CATMMMetadata* GetMetadata();

  static bool AddImage360Metadata(CATMMMetadata* iopMetadata);
  static bool HasImage360Metadata(CATMMMetadata* ipMetadata);
  static CATMMCConstPropertiesPrototype* GetPrototype();

private:
  CATPixelImage *pPI;

  friend class CATMMMetadataXMPStreaming;
//static CATMMCConstPropertiesPrototype* GetPrototype();//Pas const car AddRef
};

#endif
