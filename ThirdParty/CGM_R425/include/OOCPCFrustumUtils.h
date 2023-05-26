#ifndef OOCPCFrustumUtils_h_
#define OOCPCFrustumUtils_h_

#include "SGInfra.h"

class CAT3DPointCloudRep;
class CATViewpoint;
class CATMathPoint;

// SpecialAPI (PublicInterfaces)
#include "CATDataType.h"
#include "CATSysErrorDef.h"

class ExportedBySGInfra OOCPCFrustumUtils
{
public:

    ////////////////////
    // GetBoundingBox //
    ////////////////////

    // Construct a BoundingBox around one point of the PointCloud
    static HRESULT GetBoundingBoxAroundPoint( const float( &iPoint )[ 3 ], const float( &iDimDiv2 )[ 3 ], float( &oBoxMin )[ 3 ], float( &oBoxMax )[ 3 ] );

    // Return the BoundingBox of the entire PointCloud
    static HRESULT GetBoundingBoxFullPointCloud( const CAT3DPointCloudRep* iPointCloudRep, float( &oBoxMin )[ 3 ], float( &oBoxMax )[ 3 ] );

    ///////////////////
    // ComputeTarget //
    ///////////////////

    // Compute the maximum distance (between the camera and any point of the PointCloud) based on the camera position and the PointCloud's BoundingBox
    static HRESULT ComputeTargetDistance( const CAT3DPointCloudRep* iPointCloudRep, const float( &iCameraPos )[ 3 ], float& oTargetDistance );

    // Construct a target point at the specified distance from the camera based on the average direction of the frustum planes
    static HRESULT ComputeTargetFromFrustum( const float( &iFrustum )[ 6 ][ 4 ], const float( &iCameraPos )[ 3 ], const float iTargetDistance, float( &oTarget )[ 3 ] );

    ////////////////
    // SetFrustum //
    ////////////////

    // Construct 6 planes equations around a given BoundingBox (those planes can be used as a kind of frustum in PointCloud queries)
    static HRESULT SetFrustumFromBox( const float( &iBoxMin )[ 3 ], const float( &iBoxMax )[ 3 ], float( &oFrustum )[ 6 ][ 4 ] );

    // Construct a frustum that contains 2 points (origin and target) with a given width
    static HRESULT SetFrustumFromRay( const float( &iOrigin )[ 3 ], const float( &iTarget )[ 3 ], float iHalfWidth, float( &oFrustum )[ 6 ][ 4 ] );

    // Return the viewport's frustum of a given viewpoint
    static HRESULT SetFrustumFromViewpoint( const CATViewpoint* iViewpoint, float( &oFrustum )[ 6 ][ 4 ] );

    // Construct a "frustum" around the BoundingBox of the entire PointCloud (can be used to select the whole PointCloud)
    static HRESULT SetFrustumFromPointCloud( const CAT3DPointCloudRep* iPointCloudRep, float iHalfWidth, float( &oFrustum )[ 6 ][ 4 ] );

    // Construct a frustum from 8 corners, index bit interpretation: far-right-bottom
    static HRESULT SetFrustumFromCorners( CATMathPoint const ( &iCorners )[ 8 ], float( &oFrustum )[ 6 ][ 4 ] );
    static HRESULT SetFrustumFromCorners( CATMathPoint const ( &iCorners )[ 8 ], double( &oFrustum )[ 6 ][ 4 ] );

    //////////////////////////
    // FrustumBBoxIntersect //
    //////////////////////////

    // Compute bbox frustum intersection
    // -1: no intersection
    // 0: intersection
    // 1: bbox is entirely inside frustom
    static int BboxFrustumIntersect( const float( &iFrustum )[ 6 ][ 4 ], const double( &iBBoxMin )[ 3 ], const double( &iBBoxMax )[ 3 ] );
    static int BboxFrustumIntersect( const double( &iFrustum )[ 6 ][ 4 ], const double( &iBBoxMin )[ 3 ], const double( &iBBoxMax )[ 3 ] );

    ///////////////////////////
    // ComputeFrustumCorners //
    ///////////////////////////
    static HRESULT ComputeFrustumCorners( double const( &iFrustum )[ 6 ][ 4 ], CATMathPoint( &oCorners )[ 8 ] );
};


/**
 * @brief Class to easily manipulates frustum while respecting the (implicit) conventions in OOCPC
 * Overkill?
 */
//class ExportedBySGInfra OOCPCFrustum
//{
//    double m_Frustum[ 6 ][ 4 ]; // plane equations
//
//public:
//    enum class Planes
//    {
//        eTOP    = 0,
//        eBOTTOM = 1,
//        eFAR    = 2,
//        eNEAR   = 3,
//        eRIGHT  = 4,
//        eLEFT   = 5
//    };
//
//    enum class Corners
//    {
//        FLAG_BOTTOM = 0x1,
//        FLAG_RIGHT  = 0x2,
//        FLAG_FAR    = 0x4,
//
//        NEAR_TOP_LEFT       = 0,
//        NEAR_BOTTOM_LEFT    = FLAG_BOTTOM,
//        NEAR_TOP_RIGHT      = FLAG_RIGHT,
//        NEAR_BOTTOM_RIGHT   = FLAG_RIGHT | FLAG_BOTTOM,
//        FAR_TOP_LEFT        = FLAG_FAR,
//        FAR_BOTTOM_LEFT     = FLAG_FAR | FLAG_BOTTOM,
//        FAR_TOP_RIGHT       = FLAG_FAR | FLAG_RIGHT,
//        FAR_BOTTOM_RIGHT    = FLAG_FAR | FLAG_RIGHT | FLAG_BOTTOM,
//    };
//
//    OOCPCFrustum( double const ( &iFrustum )[ 6 ][ 4 ] );
//    OOCPCFrustum( CATMathPoint const ( &iCorners )[ 8 ] );
//
//    // enable implicit conversions to arrays of double
//    using RawFrustumReference = double( &)[ 6 ][ 4 ];
//    using RawFrustumConstReference = double const ( &)[ 6 ][ 4 ];
//    operator RawFrustumReference() { return m_Frustum; }
//    operator RawFrustumConstReference() const { return m_Frustum; }
//
//    template <Planes plane>
//    double const ( &GetPlane() const )[ 4 ] { return m_Frustum[ plane ]; }
//    template <Planes plane>
//    double ( &GetPlane() )[ 4 ] { return m_Frustum[ plane ]; }
//
//    // the below needs to include CATMathPoint.h
////private:
////    struct CornersProxy
////    {
////        CATMathPoint m_Corners[ 8 ];
////        CATMathPoint& operator[]( size_t idx ) { return m_Corners[ idx ]; }
////        CATMathPoint const& operator[]( size_t idx ) const { return m_Corners[ idx ]; }
////    };
////public:
////    CornersProxy GetCorners() const { CornersProxy proxy; OOCPCFrustumUtils::ComputeFrustumCorners( m_Frustum, proxy.m_Corners ); return proxy; }
////    void GetCorners( CATMathPoint( &oCorners )[ 8 ] ) const { OOCPCFrustumUtils::ComputeFrustumCorners( m_Frustum, oCorners ); }
//};

#endif // !OOCPCFrustumUtils_h_
