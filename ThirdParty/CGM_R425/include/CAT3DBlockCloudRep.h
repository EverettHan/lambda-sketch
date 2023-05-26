#ifndef CAT3DBlockCloudRep_H
#define CAT3DBlockCloudRep_H


#include "SGInfra.h"
#include "CAT3DRep.h"
#include "CAT3DPointCloudRep.h"
#include "CATMathVector.h"
#include "OOCPointCloudInterfaces.h" // TraversalConfig

//class CAT3DPointCloudRepImpl;
class OOCPointCloudVisuProxy;
class CAT3DBlockCloudRender;
class CATPointCloudEffect;
class CATViewer;

#include <vector>

/**
 *	@brief Block Cloud SG Representation
 */
class ExportedBySGInfra CAT3DBlockCloudRep : public CAT3DPointCloudRep
{
    CATDeclareClass;

public:

    /**
     *	@brief ctor called with an OOCPointCloud model by Visu extension
     */
    explicit CAT3DBlockCloudRep( OOCPointCloudVisuProxy& ipProxy );

    /**
     * @brief Change rendering of the point cloud with a predefined effect @see Rendering
     * @details For a custom rendering, access to private CATPointCloudEffect is required
     *
     * @param iRender predefined effect
     * @param iName set a specific metadata name ( for example ramp effect on a metadata )
     *
     */
    HRESULT SetRenderingEffect( CAT3DPointCloudRep::Rendering iRender, const char* iName = nullptr, oocpc::visu::Type iType = oocpc::visu::Type::eUndefined ) override;

    //OOCPointCloudVisuProxy* GetPointCloudProxy() const;

    void SetBlockDimension( float iDx, float iDy, float iDz );

    void GetBlockDimension( float& oDx, float& oDy, float& oDz );

    void SetClippingPlanes( float* ipPoint, float* ipNormal, int iPlane );

    void GetClippingPlanes( int& oClipPlanes );

    void GetClippingPoints( std::vector<float>& oClipPoints );

    void GetClippingNormals( std::vector<float>& oClipNormals );

    void ToggleBlockOcclusion( bool iEnableOcclusion );

    virtual void ComputeBoundingElement( int iShowSpace = 1 ) override;

    virtual void DrawShading( CATRender &iRender, int iInside ) override;

    void StartLoadingAnimation( CATViewer* ipViewer ) override;

    CATMathBox GetBoundingBox() const override;

    //int Loading();

protected:

    virtual ~CAT3DBlockCloudRep();
    virtual const vDrawInformation* GetDrawInformation();

private:

    float m_Dx, m_Dy, m_Dz;
    
    std::vector<float> _clip_Points;
    std::vector<float> _clip_Normals;
    int _clip_Planes;
    

#ifdef _WINDOWS_SOURCE

    CAT3DBlockCloudRep( CAT3DBlockCloudRep& ) = delete;

    CAT3DBlockCloudRep& operator = ( CAT3DBlockCloudRep& ) = delete;

#else

    CAT3DBlockCloudRep( CAT3DBlockCloudRep& );

    CAT3DBlockCloudRep& operator = ( CAT3DBlockCloudRep& );

#endif

    friend class CATExtI3DGeoVisuOOCBlockCloud;
    friend class EVis3DGeoVisuForOOCBlockCloud; // VisuToolkit.tst
    friend class CATPickingInsideRender;
};

#endif
