#ifndef CAT3DPointCloudRep_H
#define CAT3DPointCloudRep_H


#include "SGInfra.h"
#include "CAT3DRep.h"

#include <list>
#include <string>
// OOCInterfaces (ProtectedInterfaces)
#include "OOCPointCloudInterfaces.h"
#include "OOCPCPickingHelper.h"


class CATRender;
class CAT3DViewpoint;
class CATSupport;
class CATViewer;
class CATMathBox;

class CAT3DPointCloudRepImpl;
class OOCPointCloudVisuProxy;
class CAT3DPointCloudRender;


/**
 *	@brief Point Cloud SG Representation
 *  Could represent an LOD only representation or an Out Of Core Point Cloud
 */
class ExportedBySGInfra CAT3DPointCloudRep : public CAT3DRep
{
    CATDeclareClass;

public:

  /**
  *	Create a 3D PointCloud Representation with an OOCPointCloud model
  */
  static CAT3DPointCloudRep* CreateRep(OOCPointCloudVisuProxy& ipProxy, bool iIsMovable);

  /**
   *	Construct an empty 3D PointCloud Representation
   */
  static CAT3DPointCloudRep* CreateRep();

    /**
     *	@brief Predefined rendering effect
     */
    enum Rendering
    {
        eCOLOR = 0,             ///< Default point rendering from DEF_COLOR RGB data
        eSCALARFIELD,           ///< Temperature rendering from scalar field between min/max bounds
        eSCALARFIELD_PALETTE,   ///< Palette rendering from a scalar field
        eCOLLISION,             ///< Rendering points in collision
        eHILLSHADE,             ///< Render hillshade value if stored in specific metadata (deprecated, kept for compatibility)
        eDYNAMIC_HILLSHADE,     ///< Render hillshade hillshade dynamically
        eCLASSIFICATION,        ///< Deprecated: Dedicated for Lidar data, hide show point from their classification (deprecated, kept for compatibility)
        eHIDEANDCOLOR           ///< Deprecated
    };

    /**
     * @deprecated R422 CAT3DPointCloudRep::CreateRep
     *	@brief ctor called with an OOCPointCloud model by Visu extension
     */
    explicit CAT3DPointCloudRep( OOCPointCloudVisuProxy& ipProxy, bool iIsMovable );

    /**
     * @deprecated R422 CAT3DPointCloudRep::CreateRep
     *	@brief ctor for LOD only, called by unstream
     */
    explicit CAT3DPointCloudRep();

    /**
     *	@brief Draw the point cloud without updating it
     */
    virtual void DrawShading( CATRender &iRender, int iInside );

    /**
     *	@brief Traverse the point cloud and update from the main 3D viewpoint
     */
    void Traverse( CAT3DViewpoint& iMainVP, CATSupport* iSupport );

    virtual void ComputeBoundingElement( int iShowSpace = 1 ) override;

    /**
     * @brief Reset highlight properties
     * Disable shader highlight and frustum query
     *
     */
    virtual void ResetHighlight();

    /**
     * @brief Calls CATPointCloudEffect::FrustumQuery
     */
    virtual void FrustumQuery( const float( &iFrustum )[ 6 ][ 4 ] );

    /**
     * @brief Change rendering of the point cloud with a predefined effect @see Rendering
     * @details For a custom rendering, access to private CATPointCloudEffect is required
     *
     * @param iRender predefined effect
     * @param iName set a specific metadata name ( for example ramp effect on a metadata )
     *
     */
     virtual HRESULT SetRenderingEffect( Rendering iRender, const char* iName = nullptr, oocpc::visu::Type iType = oocpc::visu::Type::eUndefined );

     /**
     * @brief Enable/disable dynamic hillshade for current effect
     */
     virtual void ToggleDynamicHillshade( bool iEnableDynamicHillshade );

    /**
     *	@brief DMU stream
     */
    virtual void Stream( CATStreamer & oStream, int iSaveType = 0 );

    /**
    *	@brief DMU stream
    */
    virtual void UnStream( CATStreamer & iStream );

    // future release,
    // virtual HRESULT AddPoints( const float* ipPosition, const unsigned char* iColor, const unsigned iCount );


    /**
     * @brief GetRepImpl
     *
     *
     */
    CAT3DPointCloudRepImpl* GetRepImpl() const;

    OOCPointCloudVisuProxy* GetPointCloudProxy() const;

    /**
     * @brief Point Cloud is still loading data or all in core rep data has not been created
     *
     * @return bit concatenation 0x1 if all in core has not been visited or 0x2 if point cloud is loading data
     *
     */
    int Loading();

    HRESULT SetParameterFloat(const char* iData, const char* iName);

    /**
    * @brief Getter for the OOCPCPickingHelper interface.
    */
    const OOCPCPickingHelper* GetOOCPCPickingHelper() const;

    /**
    * @brief Setter for the OOCPCPickingHelper interface.
    */
    void SetOOCPCPickingHelper( OOCPCPickingHelper* iPickingHelper );

    enum class FrustumType: int { NONE, InsideRender, PickingRender };
    FrustumType GetFrustumType() const;
    void SetFrustumType( FrustumType const iFrustumType );
    /**
    * @brief Setter for selection frustum in double precision
    * @details Shouldn't really be const as it modifies the data stored stored in the underlying impl,
    * but I didn't feel like changing the signature of DrawPointCloud/BlockCloud methods in CATPickingInsideRender
    * and its hierarchy, nor doing a const_cast.
    */
    void SetSelectionFrustum( double const ( &iFrustum )[ 6 ][ 4 ] ) const;

    /**
    * @brief Getter for selection frustum in double precision
    * @details Validity/Relevance of the frustum to be confirmed from the CATPickPath (the method can return garbage information)
    */
    void GetSelectionFrustum( double( &oFrustum )[ 6 ][ 4 ] ) const;

    /**
     * @brief Compute a new hierarchical lods of the point cloud
     * It can be purely volatile or can be persisted and override the existing one
     * Metadata in LOD can't be volatile.
     * @details If an existing lod is been displayed, it will be destroyed and progressively replaced by the new one
     * Current metadata effect will be taken to compute the new LOD
     *
     * @warning If a different rendering effect is requested from the one currently selected, a call to SetRenderingEffect must be made prior building LODs
     *
     * @param iPersist save or not new lods into point cloud data repository
     *
     */
    HRESULT BuildLOD( bool iPersist );

    virtual void StartLoadingAnimation( CATViewer* ipViewer );

    void StopLoadingAnimation();

    virtual CATMathBox GetBoundingBox() const;

    virtual void SetGraphicMaterial( CATGraphicMaterial* iMaterial );


protected:
    virtual const vDrawInformation* GetDrawInformation();

    virtual void CheckEffectColorOverride( CATRender& iRender );

    explicit CAT3DPointCloudRep( OOCPointCloudVisuProxy& ipProxy, CAT3DPointCloudRender* iRender, bool iIsMovable );

    virtual ~CAT3DPointCloudRep();

    CAT3DPointCloudRepImpl*  m_pImpl;
    OOCPointCloudVisuProxy*  m_PointCloudLODProxy;     ///< only for rendering LOD without an OOCPointCloud model
    OOCPCPickingHelper*      m_OOCPCPickingHelper;
    std::list< std::string > m_Metas;                  ///< list of requested metadata for current effect
    bool                     m_EnableDynamicHillshade;

    CATGraphicMaterial*      m_pDefaultMaterial;
    CATGraphicMaterial*      m_pPLMMaterial;
    bool                     m_EffectColorOverriden;

private:

#ifdef _WINDOWS_SOURCE

    CAT3DPointCloudRep( CAT3DPointCloudRep& ) = delete;

    CAT3DPointCloudRep& operator = ( CAT3DPointCloudRep& ) = delete;

#else

    CAT3DPointCloudRep( CAT3DPointCloudRep& );

    CAT3DPointCloudRep& operator = ( CAT3DPointCloudRep& );

#endif

    friend class CATDmuStream3DOOCPointCloudRep;
    friend class CATExtI3DGeoVisuOOCPointCloud;
    friend class EVis3DGeoVisuForOOCPointCloud; // VisuToolkit.tst
    friend class VisPointCloudBaseBehaviour;    // OOCPointCloud.tst

private:
    // mostly intended for debug purposes
    bool GetRenderFrustum( float( &oFrustum )[ 6 ][ 4 ] ) const;
    bool GetRenderFrustum( double( &oFrustum )[ 6 ][ 4 ] ) const;
};

#endif
