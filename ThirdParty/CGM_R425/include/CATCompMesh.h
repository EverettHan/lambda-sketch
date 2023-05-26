#ifndef CATCompMesh_H
#define CATCompMesh_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "SGComposites.h"
#include "CATCompositeTPtr.h"
#include "CATSGComposite.h"

enum ExportedBySGComposites CATSGMeshPrimitiveType
{
    ECATSGMeshPrimitiveTypeUnset = 0,
    ECATSGMeshPrimitiveTypeTriangleList = 1,
    ECATSGMeshPrimitiveTypeTriangleStrip = 2,
    ECATSGMeshPrimitiveTypeTriangleFan = 3,
    ECATSGMeshPrimitiveTypeLines = 4,
    ECATSGMeshPrimitiveTypeLineStrip = 5,
    ECATSGMeshPrimitiveTypeLineLoop = 6
};

class ExportedBySGComposites CATCompMesh : public CATSGComposite
{
public:
    virtual HRESULT                 SetPrimitiveType(const CATSGMeshPrimitiveType iPrimitiveType) = 0;
    virtual CATSGMeshPrimitiveType  GetPrimitiveType() const = 0;

    /**
     * This method will use iSrcValues to replace the values inside the CATCompMesh.
     * Note: iSrcValuesSize must be the number of float values not the number of vertices.
     */
    virtual HRESULT SetVerticesFromFloats(const float* iSrcValues, const int iSrcValuesSize) = 0;
    /**
     * This method will fill oDstValues with the values inside the CATCompMesh.
     * Note: iDstValuesSize must be the number of float values not the number of vertices.
     */
    virtual HRESULT GetVerticesAsFloats(float*& oDstValues, const int iDstValuesSize) const = 0;
    /**
     * This method returns the number of float values, if you want the number of vertices you need
     * to divide the result by 3.
     */
    virtual const int GetVerticesSize() const = 0;

    virtual HRESULT SetNormalsFromFloats(const float* iSrcValues, const int iSrcValuesSize) = 0;

    virtual HRESULT GetNormalsAsFloats(float*& oDstValues, const int iDstValuesSize) const = 0;

    virtual const int GetNormalCount() const = 0;

    virtual HRESULT   SetIndicesFromUInt32(const CATSG::uint32* iSrcValues, const int iIndexCount) = 0;
    virtual HRESULT   GetIndicesAsUInt32(CATSG::uint32*& oDstValues, const int iDstBufferIndexCount) const = 0;
    virtual const int GetIndexCount() const = 0;

    /**
     * We affact for each vertex of each triangle one normal to allow some vertices to have
     * several normals. It is useful to enlight correctly models with some sharp edges
     * (e.g. a cube).
     */
    virtual HRESULT SetNormalsIndicesFromUInt32(const CATSG::uint32* iSrcValues, const int iArrayCount) = 0;
    virtual HRESULT GetNormalsIndicesAsUInt32(CATSG::uint32*& oDstValues, const int iArrayCount) const = 0;
    virtual const int GetNormalsIndicesCount() const = 0;
};

// {1425DE98-492E-4DBB-86BA-8847E37E4B01}
static const IID GUID_CATCompMeshTrait =
{ 0x1425de98, 0x492e, 0x4dbb, { 0x86, 0xba, 0x88, 0x47, 0xe3, 0x7e, 0x4b, 0x1 } };

template<>
class CATTraitInfo<CATCompMesh>
{
public:
	static const GUID& 			GetTraitGUID()
	{
		return GUID_CATCompMeshTrait;
	}
	static const int			GetTraitTag() {
	    return CATTraitTag(CATECompositeTagMesh);
	}
	static const CATECompositionMode	GetCompositeMode()
	{
		return CATECompositionModeExclusive;
	}
	static const CATTraitRawInfo 		GetRaw()
	{
        DefaultGetRawImplementation;
	}
};

typedef CATCompositeTWeakPtr<CATCompMesh>   CATCompMeshWeakPtr;
typedef CATCompositeTPtr<CATCompMesh>       CATCompMeshPtr;
typedef CATOnStackBorrowPtr<CATCompMesh>    CATCompMeshBorrowPtr;

#endif // SG_COMPOSITES_MULTIOS
#endif // CATCompMesh_H
