#ifndef CAT3DCanonicalCylinderRep_h_
#define CAT3DCanonicalCylinderRep_h_

// SGInfra (PublicInterfaces)
#include "SGInfra.h"
// SGInfra (PrivateInterfaces)
#include "CAT3DCanonicalRep.h"

// Mathematics (PublicInterfaces)
#include "CATMathPoint.h"
#include "CATMathVector.h"

//
// WARNING: LIMITED USE ONLY!
//          YOU NEED TO ASK SCENEGRAPH TEAM (E8C, HQ4) BEFORE USING THIS CLASS!
//

/**
* CAT3DCanonicalCylinderRep represents a canonical cylinder pipe.
*/
class ExportedBySGInfra CAT3DCanonicalCylinderRep final : public CAT3DCanonicalRep
{
    CATDeclareClass;

public:
    /**
    * Constructs a 3D cylinder from its bottom face center coordinates, its top face center coordinates, and its radius.
    *
    * @param iBottomCenterPoint
    *     The coordinates of the cylinder bottom face center.
    * @param iTopCenterPoint
    *     The coordinates of the cylinder top face center.
    * @param iRadius
    *     The radius of the cylinder (iRadius > 0.0).
    */
    static CAT3DCanonicalCylinderRep* CreateRep(const CATMathPoint& iBottomCenterPoint, const CATMathPoint& iTopCenterPoint, const double iRadius);
    static CAT3DCanonicalCylinderRep* CreateRep();

protected:

    virtual ~CAT3DCanonicalCylinderRep();

public:

    virtual CAT3DCanonicalRepType GetCanonicalType() const;

    virtual unsigned int GetSizeInBytes(int iIncludeStructuralSize = 1);

    /**
    * The bottom face center coordinates and top face center coordinates of the cylinder.
    */
    virtual HRESULT GetPoints(CATMathPoint& oBottomCenterPoint, CATMathPoint& oTopCenterPoint) const;

    /**
    * The radius of the cylinder.
    */
    virtual HRESULT GetRadius(double& oRadius) const;

    /**
     *	Compute BBox based on canonical information.
     */
    virtual HRESULT GetBoundingBox(CATMathPoint& oBBoxMin, CATMathPoint& oBBoxMax) const;

    /**
     *	@brief DMU stream
     */
    virtual void Stream(CATStreamer& oStream, int iSaveType = 0);

    /**
    *	@brief DMU stream
    */
    virtual void UnStream(CATStreamer& iStream);

    /**
     *	@brief Render handling
     */
    virtual void DrawShading(CATRender& iRender, int iInside);

protected:
    virtual HRESULT Modify(const CATMathPoint& iBottomCenterPoint, const CATMathPoint& iTopCenterPoint, const double iRadius);

    virtual HRESULT BuildMesh(float const ** oVertices,
                              int          * oVerticesArraySize,
                              float const ** oNormals,
                              int          * oNormalsArraySize,
                              int   const ** oTriangleIndices,
                              int          * oNbTriangle,
                              int   const ** oTriangleStripIndices,
                              int          * oNbTriangleStrip,
                              int   const ** oNbVertexPerTriangleStrip,
                              int   const ** oTriangleFanIndices,
                              int          * oNbTriangleFan,
                              int   const ** oNbVertexPerTriangleFan,
                              int          * oNbVisuEdges,
                              int   const ** oNbVertexPerVisuEdge,
                              int   const ** oVisuEdgeIndices) override;

private:
    CAT3DCanonicalCylinderRep();

    // Canonical data = 28 bytes
    float   _bottomCenter[3];
    float   _topCenter[3];
    float   _radius;
};

#endif // !CAT3DCanonicalCylinderRep_h_
