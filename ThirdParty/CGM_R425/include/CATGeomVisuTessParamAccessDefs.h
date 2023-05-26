//===================================================================
// CATGeomVisuTessParamAccessDefs.h
//===================================================================

#ifndef CATGeomVisuTessParamAccessDefs_H
#define CATGeomVisuTessParamAccessDefs_H

#include "SGInfra.h"

class ExportedBySGInfra CATGeomVisuTessParamAccessDefs
{
public:

  /**
    * Useful to specify where settings should be taken from when calling CATGeomVisuTessParamAccess::GetParam
    * @param FromCATSettings : settings will be retrieved from CATSettings using CATManageVisuRepository API
    * @param FromOverrideAndCATSettings : settings will be retrieved from overriding CATGeomVisuTessSetting if existing or CATSettings otherwise
    */
  enum GetMode { FromCATSettings, FromOverrideAndCATSettings };

  /**
    * Useful to specify where settings should be set to when calling CATGeomVisuTessParamAccess::SetParam
    * @param ToCATSettings : settings will be set to CATSettings using CATManageVisuRepository API
    */
  enum SetMode { ToCATSettings };

  /**
   * Useful to target settings domains when calling CATGeomVisuTessParamAccess::GetParam and CATGeomVisuTessParamAccess::SetParam
   * Categories can be cumulated : e.g. (Accuracy|MeshQuality|UV)
   * Report to CATGeomVisuTessParam to know which methods will be callable using which category
   * Tip 1 : if you are interested in SAG and CATGeomVisuTessParam::GetComputedXXX methods, use Accuracy tag.
   * Tip 2 : never use Lock, unless you are intersted in getting lock status on CATSettings
   */
  enum Category {
    Undefined = 0x0,
    Lock = 0x1,
    Accuracy = 0x2,
    Angle = 0x4,
    MeshQuality = 0x8,
    Isopars = 0x10,
    SmoothEdges = 0x20,
    UV = 0x40,
    WTT = 0x80,
    Sharpness = 0x100,
    Wysiwyg = 0x200,
    AllNoLock = 0xFFE,
    All = 0xFFF
  };

};

#endif
