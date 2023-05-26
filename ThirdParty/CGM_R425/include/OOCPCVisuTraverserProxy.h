
// COPYRIGHT DASSAULT SYSTEMES 2017

#ifndef OOCPCVisuTraverserProxy_H
#define OOCPCVisuTraverserProxy_H

#include "CATDataType.h"
#include "CATSysBoolean.h"
#include "CATSysErrorDef.h"

#include "OOCPointCloudInterfaces.h"

#include <list>
#include <string>
#include <vector>
#include <utility>

/**
 *	@brief Interface for visu traverser implementation
 */
class OOCPCVisuTraverserProxy
{
public:

    struct NodePosition
    {
        double m_BBoxMin[ 3 ];
        double m_BBoxMax[ 3 ];
        CATULONG64 m_MortonCode;
        int m_Depth;
    };

    struct NodeData
    {
        const char* mp_Data;
        unsigned m_PointCount;
        unsigned m_PointSize;
    };

public:

    virtual HRESULT NodeIntersection( NodePosition const& i_NodePosition ) = 0;

    virtual HRESULT LoadableNode( NodePosition const& i_NodePosition, double iSpacing, int& oPriority ) = 0;

public:

    virtual HRESULT OnOutOfCoreNode( unsigned i_LODNodeID, NodeData const& i_LODNodeData, NodePosition const& i_LODNodePosition ) = 0;

    virtual HRESULT OnInCoreNode( CATULONG64 i_NodeOOCId, NodeData const& i_NodeData, NodePosition const& i_NodePosition ) = 0;

    virtual HRESULT OnDirtyNode( CATULONG64 i_NodeOOCId, NodeData const& i_NodeData, NodePosition const& i_NodePosition ) = 0;

public:

    virtual bool DiscardNode( NodePosition const& i_NodePosition ) = 0;

    virtual bool DiscardFiltering( CATULONG64 i_NodeOOCId, unsigned iPointCount, bool i_IsDirty ) = 0;

public:

    virtual void Initialize( unsigned i_MaxVisuPrimitive, CATULONG64 i_MaxPoints ) = 0;

    virtual void InitializeCache( bool i_MetaMismatch, unsigned i_MetasVisuSize ) = 0;

    virtual void InitializeImpostorCache( bool i_NeedCast ) = 0;

public:

    virtual void ResetImpostor() = 0;

    virtual void DirtifyImpostor() = 0;

    virtual void DirtifyImpostorNodes( std::vector<unsigned> const& i_LODNodesKeys ) = 0;

    virtual HRESULT DrawDirtyNode( unsigned i_LODNodeKey ) = 0;

public:

    virtual const std::list<std::string>& GetRequestedMetaData() = 0;

    virtual std::list<oocpc::visu::MetaData>& GetRequestedMetaDataLayout() = 0;

    virtual std::list<oocpc::visu::MetaData>& GetRequestedMetaDataLayoutForImpostors() = 0;

};

#endif
