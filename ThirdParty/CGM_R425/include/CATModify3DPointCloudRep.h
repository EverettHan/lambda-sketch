
#ifndef CATModify3DPointCloudRep_H
#define CATModify3DPointCloudRep_H


#include "SGInfra.h"

#include "CAT3DPointCloudRep.h"

#include "CATModify.h"
#include "CATBaseUnknown.h"

#include <vector>
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"

class OOCPCIQuery;


/**
*	@brief Notification as a wrapper over the point cloud rep
*/
class ExportedBySGInfra CATModify3DPointCloudRep : public CATModify
{
    CATDeclareClass;

public:
    CATModify3DPointCloudRep( CATBaseUnknown* ipOOCPointCloud );

    virtual ~CATModify3DPointCloudRep();

    /**
    * @brief Clone
    *
    *
    */
    virtual CATModelNotification* Clone();

    // Rendering Parameters

    void SetMaxVisuPoints( const CATULONG64 iValue );

    void SetImpostorMinPointSize( const float iValue );

    void SetImpostorMaxPointSize( const float iValue );

    void SetMinPointSize( const float iValue );

    void SetMaxPointSize( const float iValue );

    void SetPixelAreaThreshold( const float iValue );

    void EnableSplatting( bool iValue );

    void SetSplattingFactor( const float iValue );

    // Rendering

    void DisplayLODOnly( bool iValue );
    
    void SetRenderingEffect( CAT3DPointCloudRep::Rendering iRendering, const char* iName = nullptr, oocpc::visu::Type iType = oocpc::visu::Type::eUndefined, bool iEnableDynamicHillshade = false );

    void SetMovable( int iMovable );

    void SetBlockCloudOcclusion( int iFlag );

    void DirtyAll();

    void HighlightTrap( bool iDoHL );

    void AddVisuFrustumQuery( const float( &iFrustum )[ 6 ][ 4 ], int iOp );

    void AddVisuAABBQuery( const float( &iMinBox )[ 3 ], const float( &iMaxBox )[ 3 ], int iOp );

    void AddVisuSphereQuery( const float &iRadius, const float( &iCenter )[ 3 ], int iOp );

    void AddQuery( OOCPCIQuery* ipQuery );

    void ClearVisuQueries();

    void AddPaletteElement( float iMinValue, float iMaxValue, unsigned int iColor );

    void ClearPalette();

    void SetVersion( const CATULONG64 iVersionID );

    // DSFX Parameters


    /**
    * @brief Change point cloud effect
    *
    * @param iShaderName
    *
    */
    void SetShader( const char* iShaderName );

    void SetParameterUint8( const char* iName, unsigned char iValue );

    void SetParameterUint82( const char* iName, const unsigned char( &iValue )[ 2 ] );

    void SetParameterUint83( const char* iName, const unsigned char( &iValue )[ 3 ] );

    void SetParameterUint84( const char* iName, const unsigned char( &iValue )[ 4 ] );

    void SetParameterFloat( const char* iName, float iValue );

    void SetParameterFloat2( const char* iName, const float( &iValue )[ 2 ] );

    void SetParameterFloat3( const char* iName, const float( &iValue )[ 3 ] );

    void SetParameterFloat4( const char* iName, const float( &iValue )[ 4 ] );

    void SetParameterInt( const char* iName, int iValue );

    void SetParameterInt2( const char* iName, const float( &iValue )[ 2 ] );

    void SetParameterInt3( const char* iName, const float( &iValue )[ 3 ] );

    void SetParameterInt4( const char* iName, const float( &iValue )[ 4 ] );

private:

    CATModify3DPointCloudRep( const CATModify3DPointCloudRep &iOther );

    class Parameter
    {
    public:

        enum class Type
        {
            LOD,
            BUILD_LOD,
            META_DATA,
            SHADER,
            SHADER_PARAM,
            MAX_VISU_POINTS,
            IMPOSTOR_MIN_POINT_SIZE,
            IMPOSTOR_MAX_POINT_SIZE,
            MIN_POINT_SIZE,
            MAX_POINT_SIZE,
            PIXEL_AREA_THRESHOLD,
            EFFECT,
            MOVABLE,
            DIRTY_ALL,
            HIGH_LIGHT,
            FRUSTUM_QUERY,
            SPHERE_QUERY,
            AABB_QUERY,
            QUERY,
            CLEAR_QUERIES,
            PALETTE,
            CLEAR_PALETTE,
            SET_VERSION,
            BLOCK_CLOUD_OCCLUSION,
            SPLATTING,
            SPLATTING_FACTOR,
            NONE
        };

        enum class Data
        {
            BOOL,

            UINT8,
            UINT8_2,
            UINT8_3,
            UINT8_4,

            INT,
            INT_2,
            INT_3,
            INT_4,

            UINT,
            UINT_2,
            UINT_3,
            UINT_4,

            FLOAT,
            FLOAT_2,
            FLOAT_3,
            FLOAT_4,

            UINT64,

            NONE
        };

        union
        {
            bool            _bool[ 4 ];
            int             _int[ 4 ];
            unsigned        _uint[ 4 ];
            unsigned char   _uint8[ 4 ];
            float           _float[ 4 ];
            float           _floatArray[ 6 ][ 4 ];
            CATULONG64      _uint64;
            void*           _ptr;
            struct
            {
                float       _minValue;
                float       _maxValue;
                unsigned    _color;
            };

            char            _blob[ 96 ];
        };

        Parameter() : _blob { 0 }, m_Type( Type::NONE ), m_Data( Data::NONE ), m_LogicalOp( 0 ), m_Name() {}

        Type m_Type;
        Data m_Data;
        int m_LogicalOp; // 0 = AND, 1 = OR, 2 = XOR, 3 = NOT
        oocpc::visu::Type m_MetaType;

        CATUnicodeString m_Name;
    };

    std::vector< Parameter >  m_Parameters;
    CATListOfCATUnicodeString m_MetaData;

    friend class CATExtI3DGeoVisuOOCPointCloud;
    friend class CATExtI3DGeoVisuOOCBlockCloud;
};

#endif
