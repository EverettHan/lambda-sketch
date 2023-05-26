// COPYRIGHT DASSAULT SYSTEMES 2010, ALL RIGHTS RESERVED.
//===================================================================
//
// CATCGMUVCommonSettings.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// July 2010  Creation: ZFI
//===================================================================

#ifndef CATCGMUVCommonSettings_H
#define CATCGMUVCommonSettings_H

#include "ExportedByTessellateCommon.h"
#include "CATErrorDef.h"
#include "CATCGMUVParam.h"

class CATSoftwareConfiguration;
class CATTessellateParam;

class ExportedByTessellateCommon CATCGMUVCommonSettings
{
public:
  CATCGMUVCommonSettings();
  virtual ~CATCGMUVCommonSettings();

public:
  HRESULT SetParam(const CATCGMUVParam& iUVParam);
  HRESULT SetSoftwareConfiguration(CATSoftwareConfiguration * iSoftwareConfiguration);
  
public:
  enum RefinementLevel_T
  {
    L0 = 0,
    L1, 
    L2,
    L3,
    L4,
    L5,
    L6,
    L7,

    L_MAX // for internal use 
          // L_MAX is expected to be 8.
          // If L_MAX increases due to extra additions to enum types in future,
          // then make sure to modify stream/unstream code of CATCGMUVParam
  };

  enum RefinementMode_T
  {
    NonUniform = 0, 
    Uniform,
    NonUniform2,

    Mode_MAX // for internal use
             // Mode_MAX is expected to be 4 or less (currently 3).
             // If Mode_MAX increases to more than 4 due to extra additions to enum types in future,
             // then make sure to modify stream/unstream code of CATCGMUVParam
  };

  enum Format_T
  {
    Static = 0,
    PNT, 
    PNTWithTangents,

    Format_MAX // for internal use
               // Format_MAX is expected to be 4 or less (currently 3).
               // If Format_MAX increases to more than 4 due to extra additions to enum types in future,
               // then make sure to modify stream/unstream code of CATCGMUVParam
  };

  enum Compression_T
  {
    C0,  //no compression
    C1   //compress unit vectors in 32 bits :normals and tangents
  };

public:
  CATSoftwareConfiguration* GetSoftwareConfiguration(){return _SoftwareConfiguration;}
  HRESULT GetParam(CATCGMUVParam& oParam) const{oParam=_Param;return S_OK;}
  static HRESULT GetParam(const CATTessellateParam& iTessParam, CATCGMUVParam& oParam);

public:
  void DoGenerateVertexNormals(CATBoolean iActivate){_GenerateVertexNormals=iActivate;}
  CATBoolean GenerateVertexNormals() const {return _GenerateVertexNormals;}
  
  void DoGenerateVertexUVs(CATBoolean iActivate){_GenerateVertexUVs=iActivate;}
  CATBoolean GenerateVertexUVs()const{return _GenerateVertexUVs;}

  void DoGenerateVertexWs(CATBoolean iActivate){_GenerateVertexWs=iActivate;}
  CATBoolean GenerateVertexWs()const{return _GenerateVertexWs;}
 
  void DoGenerateVertexTangents(CATBoolean iActivate){_GenerateVertexTangents=iActivate;}
  CATBoolean GenerateVertexTangents()const{return _GenerateVertexTangents;}

protected:
  CATSoftwareConfiguration * _SoftwareConfiguration;
  CATCGMUVParam _Param;
  CATBoolean _GenerateVertexNormals, _GenerateVertexUVs,_GenerateVertexWs,_GenerateVertexTangents;
};

#endif
