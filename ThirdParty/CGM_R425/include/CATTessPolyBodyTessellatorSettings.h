//=============================================================================
// COPYRIGHT Dassault Systemes 2007
//=============================================================================
//
// Settings for CATTessPolyBodyTessellator.
//
//=============================================================================
//  2007-10-23  BPG: New.
//=============================================================================
#ifndef CATTessPolyBodyTessellatorSettings_H
#define CATTessPolyBodyTessellatorSettings_H

#include "CATErrorDef.h"

#include "CATBoolean.h"

//
class CATTessPolyBodyTessellatorSettings
{
public:
  CATTessPolyBodyTessellatorSettings():
    _GenerateSurfaceVertexNormalLayer(FALSE),
    _GenerateSurfaceVertexUVLayer(FALSE),
    _GenerateSurfaceSupport(FALSE),

    _GenerateCurveVertexWLayer(FALSE),
    _GenerateCurveVertexTangentLayer(FALSE),
    _GenerateCurveSupport(FALSE),

    _GeneratePointSupport (FALSE)
  {
  }

public:
  inline HRESULT DoGenerateSurfaceVertexNormalLayer(CATBoolean iFlag = TRUE);
  inline CATBoolean GenerateSurfaceVertexNormalLayer() const;

  inline HRESULT DoGenerateSurfaceVertexUVLayer(CATBoolean iFlag = TRUE);
  inline CATBoolean GenerateSurfaceVertexUVLayer() const;

  inline HRESULT DoGenerateSurfaceSupport(CATBoolean iFlag = TRUE);
  inline CATBoolean GenerateSurfaceSupport() const;

public:
  inline HRESULT DoGenerateCurveVertexWLayer(CATBoolean iFlag = TRUE);
  inline CATBoolean GenerateCurveVertexWLayer() const;

  inline HRESULT DoGenerateCurveVertexTangentLayer(CATBoolean iFlag = TRUE);
  inline CATBoolean GenerateCurveVertexTangentLayer() const;

  inline HRESULT DoGenerateCurveSupport(CATBoolean iFlag = TRUE);
  inline CATBoolean GenerateCurveSupport() const;

public:
  inline HRESULT DoGeneratePointSupport(CATBoolean iFlag = TRUE);
  inline CATBoolean GeneratePointSupport() const;

protected:
  CATBoolean _GenerateSurfaceVertexNormalLayer;
  CATBoolean _GenerateSurfaceVertexUVLayer;
  CATBoolean _GenerateSurfaceSupport;

  CATBoolean _GenerateCurveVertexWLayer;
  CATBoolean _GenerateCurveVertexTangentLayer;
  CATBoolean _GenerateCurveSupport;

  CATBoolean _GeneratePointSupport;
};

//

inline HRESULT
CATTessPolyBodyTessellatorSettings::DoGenerateSurfaceVertexNormalLayer(CATBoolean iFlag)
{
  _GenerateSurfaceVertexNormalLayer = iFlag;
  return S_OK;
}
inline CATBoolean
CATTessPolyBodyTessellatorSettings::GenerateSurfaceVertexNormalLayer() const
{
  return _GenerateSurfaceVertexNormalLayer;
}

inline HRESULT
CATTessPolyBodyTessellatorSettings::DoGenerateSurfaceVertexUVLayer(CATBoolean iFlag)
{
  _GenerateSurfaceVertexUVLayer = iFlag;
  return S_OK;
}
inline CATBoolean
CATTessPolyBodyTessellatorSettings::GenerateSurfaceVertexUVLayer() const
{
  return _GenerateSurfaceVertexUVLayer;
}

inline HRESULT
CATTessPolyBodyTessellatorSettings::DoGenerateSurfaceSupport(CATBoolean iFlag)
{
  _GenerateSurfaceSupport = iFlag;
  return S_OK;
}
inline CATBoolean
CATTessPolyBodyTessellatorSettings::GenerateSurfaceSupport() const
{
  return _GenerateSurfaceSupport;
}

//

inline HRESULT
CATTessPolyBodyTessellatorSettings::DoGenerateCurveVertexWLayer(CATBoolean iFlag)
{
  _GenerateCurveVertexWLayer = iFlag;
  return S_OK;
}
inline CATBoolean
CATTessPolyBodyTessellatorSettings::GenerateCurveVertexWLayer() const
{
  return _GenerateCurveVertexWLayer;
}

inline HRESULT
CATTessPolyBodyTessellatorSettings::DoGenerateCurveVertexTangentLayer(CATBoolean iFlag)
{
  _GenerateCurveVertexTangentLayer = iFlag;
  return S_OK;
}
inline CATBoolean
CATTessPolyBodyTessellatorSettings::GenerateCurveVertexTangentLayer() const
{
  return _GenerateCurveVertexTangentLayer;
}

inline HRESULT
CATTessPolyBodyTessellatorSettings::DoGenerateCurveSupport(CATBoolean iFlag)
{
  _GenerateCurveSupport = iFlag;
  return S_OK;
}
inline CATBoolean
CATTessPolyBodyTessellatorSettings::GenerateCurveSupport() const
{
  return _GenerateCurveSupport;
}

inline HRESULT
CATTessPolyBodyTessellatorSettings::DoGeneratePointSupport(CATBoolean iFlag)
{
  _GeneratePointSupport = iFlag;
  return S_OK;
}
inline CATBoolean
CATTessPolyBodyTessellatorSettings::GeneratePointSupport() const
{
  return _GeneratePointSupport;
}

#endif // !CATTessPolyBodyTessellatorSettings_H
