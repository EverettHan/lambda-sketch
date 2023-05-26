#ifndef CATCGMUVTessCodeVersion_H
#define CATCGMUVTessCodeVersion_H

#include "ExportedByTessellateCommon.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"
#include "CATDataType.h"
#include "CATCGMUVTessCodeLevels.h"

class CATMathStream;
class CATSoftwareConfiguration;
class CATCGMUVStreamVersion;

class ExportedByTessellateCommon CATCGMUVTessCodeVersion
{
public:
  static CATCGMUVTessCodeVersion Latest();
 // The returned object will be owned by the caller 
  static CATSoftwareConfiguration* GetLatestRegisteredSoftConfig();
  static CATSoftwareConfiguration* GetSynchronizedSoftConfig(const CATSoftwareConfiguration& iConfig);

public:
  // default constructor sets version to 0 (invalid)
  inline CATCGMUVTessCodeVersion(unsigned short iTessCodeLevel = 0);
  inline CATCGMUVTessCodeVersion(const CATCGMUVTessCodeVersion& iFrom);
  inline const CATCGMUVTessCodeVersion& operator = (const CATCGMUVTessCodeVersion& iFrom);

public:

  // Returns FALSE if TessCodeLevel is 0 or more than max level
  inline CATBoolean IsValid() const;

  // Sets the TessCodeLevel to the max possible level, 
  // such that its mapped CGMLevel is less than or equal to given iCGMLevel
  inline HRESULT SyncWithGivenCGMLevel(short iCGMLevel);
  HRESULT SyncWithGivenCGMLevel(const CATSoftwareConfiguration& iConfig);

  // Get mapped CGMLevel
  inline short GetCGMLevel() const;

  // Sets to the lastest available version
  inline void SetLatest();

  inline CATBoolean operator == (const CATCGMUVTessCodeVersion& iOther) const;
  inline CATBoolean operator != (const CATCGMUVTessCodeVersion& iOther) const;
  inline CATBoolean operator < (const CATCGMUVTessCodeVersion& iOther) const;
  inline CATBoolean operator >= (const CATCGMUVTessCodeVersion& iOther) const;

public:

  void Stream   (CATMathStream& iStream, const CATCGMUVStreamVersion& iCGMUVStreamVersion) const;
  void UnStream (CATMathStream& iStream, const CATCGMUVStreamVersion& iCGMUVStreamVersion);

public:

  // define static methods to get each version by its name
  #undef DefineFor_TessCodeLevel

    #define DefineFor_TessCodeLevel(TessCodeLevel, LevelName, CGMLevel) \
    static CATCGMUVTessCodeVersion LevelName();

    DefineFor_AllTessCodeLevels

  #undef DefineFor_TessCodeLevel

private:

  // returns latest valid tess code level
  inline static unsigned short LatestTessCodeLevel();

  // gets the mapped CGMLevel for the given tess code level
  inline static short GetCGMLevelForGivenTessCodeLevel(unsigned short iTessCodeLevel);

private:
  unsigned short _TessCodeLevel;
};

inline CATCGMUVTessCodeVersion::CATCGMUVTessCodeVersion(unsigned short iTessCodeLevel)
:_TessCodeLevel(iTessCodeLevel)
{
}

inline CATCGMUVTessCodeVersion::CATCGMUVTessCodeVersion(const CATCGMUVTessCodeVersion& iFrom)
{
  _TessCodeLevel = iFrom._TessCodeLevel;
}

inline const CATCGMUVTessCodeVersion& 
CATCGMUVTessCodeVersion::operator = (const CATCGMUVTessCodeVersion& iFrom)
{
  _TessCodeLevel = iFrom._TessCodeLevel;
  return (*this);
}

inline CATBoolean 
CATCGMUVTessCodeVersion::operator == (const CATCGMUVTessCodeVersion& iOther) const
{
  return _TessCodeLevel == iOther._TessCodeLevel;
}

inline CATBoolean 
CATCGMUVTessCodeVersion::operator != (const CATCGMUVTessCodeVersion& iOther) const
{
  return _TessCodeLevel != iOther._TessCodeLevel;
}

inline CATBoolean 
CATCGMUVTessCodeVersion::operator < (const CATCGMUVTessCodeVersion& iOther) const
{
  return _TessCodeLevel < iOther._TessCodeLevel;
}

inline CATBoolean 
CATCGMUVTessCodeVersion::operator >= (const CATCGMUVTessCodeVersion& iOther) const
{
  return _TessCodeLevel >= iOther._TessCodeLevel;
}

inline void 
CATCGMUVTessCodeVersion::SetLatest()
{
  // set _TessCodeLevel to the last index in TessCodeLevels map
  _TessCodeLevel = LatestTessCodeLevel();
}

inline HRESULT 
CATCGMUVTessCodeVersion::SyncWithGivenCGMLevel(short iCGMLevel)
{
  _TessCodeLevel = CATCGMUVTessCodeLevels::GetTessCodeLevel(iCGMLevel);
  return (0 != _TessCodeLevel) ? S_OK : E_FAIL;
}

inline CATBoolean
CATCGMUVTessCodeVersion::IsValid() const
{
  return (_TessCodeLevel >= 1) && (_TessCodeLevel <= LatestTessCodeLevel());
}

inline CATCGMUVTessCodeVersion 
CATCGMUVTessCodeVersion::Latest()
{
  CATCGMUVTessCodeVersion LatestVer;
  LatestVer.SetLatest();
  return LatestVer;
}

inline short 
CATCGMUVTessCodeVersion::GetCGMLevel() const
{
  if (!IsValid())
    return 0;
  
  return GetCGMLevelForGivenTessCodeLevel(_TessCodeLevel);
}

inline unsigned short 
CATCGMUVTessCodeVersion::LatestTessCodeLevel()
{
  return CATCGMUVTessCodeLevels::GetLatestTessCodeLevel();
}

inline short 
CATCGMUVTessCodeVersion::GetCGMLevelForGivenTessCodeLevel(unsigned short iTessCodeLevel)
{
  return CATCGMUVTessCodeLevels::GetCGMLevel(iTessCodeLevel);
}


#endif 

