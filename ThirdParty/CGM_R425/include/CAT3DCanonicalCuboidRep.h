#ifndef CAT3DCanonicalCuboidRep_h_
#define CAT3DCanonicalCuboidRep_h_

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
* CAT3DCanonicalCuboidRep represents a canonical cuboid.
*/
class ExportedBySGInfra CAT3DCanonicalCuboidRep final : public CAT3DCanonicalRep
{
    CATDeclareClass;

public:
    /**
    * Constructs the representation of a box from a corner and 3 orthogonal vectors.
    *
    * @param iCornerPoint
    *     The reference corner of the box.
    * @param iFirstAxis
    *     The orientation and the length of the box along the first direction.
    * @param iSecondAxis
    *     The orientation and the length of the box along the second direction.
    * @param iThirdAxis
    *     The orientation and the length of the box along the third direction.
    */
    static CAT3DCanonicalCuboidRep* CreateRep(const CATMathPoint& iCornerPoint, const CATMathVector& iFirstAxis, const CATMathVector& iSecondAxis, const CATMathVector& iThirdAxis);
    static CAT3DCanonicalCuboidRep* CreateRep();

protected:

    virtual ~CAT3DCanonicalCuboidRep();

public:

    virtual CAT3DCanonicalRepType GetCanonicalType() const;

    virtual unsigned int GetSizeInBytes(int iIncludeStructuralSize = 1);

    /**
    * The reference corner of the box.
    */
    virtual HRESULT GetCornerPoint(CATMathPoint& oCornerPoint) const;

    /**
    * The orientation and the length of the box along the first/second/third directions.
    */
    virtual HRESULT GetAxisSystem(CATMathVector& oFirstAxis, CATMathVector& oSecondAxis, CATMathVector& oThirdAxis) const;

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
    virtual HRESULT Modify(const CATMathPoint& iCornerPoint, const CATMathVector& iFirstAxis, const CATMathVector& iSecondAxis, const CATMathVector& iThirdAxis);

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
    CAT3DCanonicalCuboidRep();

    // Canonical data = 40 bytes
    float   _cornerPoint[3];
    float   _firstAxis[3]; // <- contains FirstLength
    float   _secondAxis[3]; // <- contains SecondLength
    //float _thirdAxis[3]; // <- computed from FirstAxis & SecondAxis
    //float _firstLength; // <- computed from length of FirstAxis
    //float _secondLength; // <- computed from length of SecondAxis
    float   _thirdLength;
};

#endif // !CAT3DCanonicalCuboidRep_h_
