// COPYRIGHT DASSAULT SYSTEMES 2017

#ifndef OOCPointCloudVisuProxy_H
#define OOCPointCloudVisuProxy_H

class OOCPointCloud;
class OOCPCLODNodeCache;
class OOCPCTraverser;

#include "OOCPointCloudInterfaces.h"

#include "CATDataType.h"
#include "CATSysErrorDef.h"

#include <list>
#include <string>
#include <functional>

class OOCPCVisuTraverserProxy;
class CATMathVector;
class CATMathBox;
class OOCPCBuilderObserver;


/**
 *	@brief Visualization wrapper with dynamic loading
 *
 *  @details Minimal set of functionality for rendering
 */
class OOCPointCloudVisuProxy
{
public :

    virtual ~OOCPointCloudVisuProxy() = default;

    virtual HRESULT GetBoundingBox( CATMathBox& oBox ) const = 0;

    virtual HRESULT Traverse( OOCPCVisuTraverserProxy* ipTraverser, const std::list<std::string>& iRequestedData, const oocpc::TraversalConfig& iConfig, oocpc::Algorithm iAlgo ) = 0;

    virtual HRESULT TraverseLOD( OOCPCVisuTraverserProxy* ipTraverser ) = 0;

    virtual HRESULT BuildLOD( bool iPersist, std::function< void() > iEndBuildCB, OOCPCBuilderObserver* ipBuilder = nullptr ) = 0;

    virtual HRESULT FlushLODCache() = 0;

    virtual int GetAcceleratorType() const = 0;

    virtual OOCPointCloud* GetPointCloud() const = 0;

    virtual OOCPCLODNodeCache* GetLODNodeCache() const = 0;

    virtual OOCPCTraverser* GetTraverser() const = 0;

    virtual short GetLODNodeCacheVersion() const = 0;

    virtual bool TranslateOrigin( CATMathVector& oTranslate ) const = 0;

    virtual void DirtyAllNodes() = 0;

    virtual bool Loading() = 0;

    virtual void InitializeCache() = 0;

    virtual CATULONG64 GetPointCount() const = 0;

    virtual CATULONG32 GetLODPoints() const = 0;

    virtual unsigned GetMetaDataSize(const char* iMetaName) const = 0;

    virtual unsigned GetMetaDataOffset( const char* iMetaName ) const = 0;

    virtual unsigned GetMetaDataTotalSize() const = 0;

    virtual std::list<std::string> GetMetaDataName() const = 0 ;

    virtual HRESULT GetExtendedDataFromContainer( const char* iContainerName, void* oData ) const = 0;

    virtual HRESULT SetBlockDimension( float iDx, float iDy, float iDz ) = 0;

    virtual void SetSlicingPlane( const CATMathVector &iNormal, const double iOffset, double iBlockX, double iBlockY, double iBlockZ ) = 0;

    virtual void RemoveSlicingPlane() = 0;

    virtual HRESULT SetUpdateIteration( const CATULONG64 iUpdateIterationID ) = 0;
    /** @deprecated use SetUpdateIteartion instead */
    [[deprecated("Deprecated: use SetUpdateIteration instead (name changed to encourage disambiguation between PLM versions and OOCPointCloud iterations)")]]
    inline HRESULT SetVersion( const CATULONG64 iVersionID ) { return SetUpdateIteration( iVersionID ); }

    virtual double GetSpacing() const = 0;
};

#endif

using FPOOCPCCreateVisuProxy = OOCPointCloudVisuProxy* (*)( OOCPointCloud* );
