#ifndef CATCompMeshDefaultImpl_h_
#define CATCompMeshDefaultImpl_h_

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "SGComposites.h"
#include "CATCompMesh.h"
#include "CATSGComposite.h"
#include "CATSGCompositeHost.h"

class ExportedBySGComposites CATCompMeshDefaultImpl : public CATSGCompositeHost1<CATCompMesh, CATSGComposite>
{
 public:
    CATCompMeshDefaultImpl();
    virtual ~CATCompMeshDefaultImpl();

    HRESULT                 SetPrimitiveType(const CATSGMeshPrimitiveType iPrimitiveType);
    CATSGMeshPrimitiveType  GetPrimitiveType() const;

    HRESULT SetVerticesFromFloats(const float* iSrcValues, const int iSrcValuesSize);
    HRESULT GetVerticesAsFloats(float*& oDstValues, const int iDstValuesSize) const;
    const int GetVerticesSize() const;

    HRESULT SetNormalsFromFloats(const float* iSrcValues, const int iSrcValuesSize);
    HRESULT GetNormalsAsFloats(float*& oDstValues, const int iDstValuesSize) const;
    const int GetNormalCount() const;

    HRESULT   SetIndicesFromUInt32(const CATSG::uint32* iSrcValues, const int iIndexCount);
    HRESULT   GetIndicesAsUInt32(CATSG::uint32*& oDstValues, const int iDstBufferIndexCount) const;
    const int GetIndexCount() const;

    virtual HRESULT SetNormalsIndicesFromUInt32(const CATSG::uint32* iSrcValues, const int iArrayCount);
    virtual HRESULT GetNormalsIndicesAsUInt32(CATSG::uint32*& oDstValues, const int iArrayCount) const;
    virtual const int GetNormalsIndicesCount() const;

private:
    CATSGMeshPrimitiveType     _primitiveType;
    std::vector<float>         _vertices;
    std::vector<float>         _normals;
    std::vector<CATSG::uint32> _indices;
    std::vector<CATSG::uint32> _normalsIndices;
};

#endif // SG_COMPOSITES_MULTIOS
#endif // !CATCompMeshDefaultImpl_h_
