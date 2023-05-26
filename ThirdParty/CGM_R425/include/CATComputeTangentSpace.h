#ifndef CATComputeTangentSpace_H_
#define CATComputeTangentSpace_H_

#include "SGInfra.h"
#include "CATSysDataType.h"
#include "CATSysErrorDef.h"

#include "VisDataType.h"
#include "VisConnectivityType.h"

class ExportedBySGInfra CATComputeTangentSpace
{
public:
  class Attribute
  {
  public:

    inline Attribute(void* iData = NULL, VisDataType  iType = (VisDataType)0, VisSize iNumComponents = 0, VisSize iStride = 0)
      :m_Data(iData), m_Type(iType), m_NumComponents(iNumComponents), m_Stride(iStride){}

    inline void Set(void* iData, VisDataType iType, VisSize iNumComponents, VisSize iStride)
    {
      m_Data = iData;
      m_Type = iType;
      m_NumComponents = iNumComponents;
      m_Stride = iStride;
    }

    inline void* GetData() {return m_Data;}

    inline void const* GetData() const {return m_Data;}

    inline VisDataType GetDataType() const{return m_Type;}
    inline VisSize     GetNumComponents() const{return m_NumComponents;}
    inline VisSize     GetStride() const{return m_Stride;}

  protected:
    void*       m_Data;
    VisDataType m_Type;
    VisSize     m_NumComponents;
    VisSize     m_Stride;
  };

  class Geometry
  {
  public:

    inline Geometry(void* iData = NULL, VisDataType  iType = (VisDataType)0, VisSize iNumIndices = 0, VisConnectivityType iConnecType = 0)
      :m_Data(iData), m_Type(iType), m_NumIndices(iNumIndices), m_ConnecType(iConnecType){}

    inline void Set(void* iData, VisDataType iType, VisSize iNumIndices, VisConnectivityType iConnecType)
    {
      m_Data = iData;
      m_Type = iType;
      m_NumIndices = iNumIndices;
      m_ConnecType = iConnecType;
    }

    inline void* GetData() {return m_Data;}

    inline void const* GetData() const {return m_Data;}

    inline VisDataType GetDataType() const{return m_Type;}
    inline VisSize     GetNumIndices() const{return m_NumIndices;}
    inline VisConnectivityType GetConnectivity() const{return m_ConnecType;}

  protected:
    void*               m_Data;
    VisDataType         m_Type;
    VisSize             m_NumIndices;
    VisConnectivityType m_ConnecType;
  };

  /**
    Compute a tangent space.
    iPosition, iNormal, iUV, oTan, oBinorm must have the same floating point type (VIS_FLOAT at the moment, VIS_DOUBLE are not supported by the SGV6 yet)
    For each attributes, m_Data must be a valid pointer with enough space to be adressed by iIndices (or iNumIndices if iIndices is NULL)
    iGeom is a pointer to an array of Geometry of size iNumGeometries
    For each geometry, m_Data attribute is optional (Attributes will be read as primitives). Supported types are VIS_UNSIGNED_CHAR, VIS_UNSIGNED_SHORT and VIS_UNSIGNED_INT
    Geometry connectivity must be VIS_TRIANGLES, VIS_TRIANGLE_STRIP, VIS_TRIANGLE_STRIP_RESTART, VIS_TRIANGLE_FAN, or VIS_TRIANGLE_FAN_RESTART.
  */
  static HRESULT Compute(Attribute const& iPosition, Attribute const& iNormal, Attribute const& iUV, Geometry const* iGeom, VisSize iNumGeometries, Attribute& oTan, Attribute& oBinorm);
};

#endif
