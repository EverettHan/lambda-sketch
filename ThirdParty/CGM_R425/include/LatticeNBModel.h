//===================================================================
// COPYRIGHT Dassault Systemes 2017/03/14
//===================================================================

#ifndef LatticeNBModel_H
#define LatticeNBModel_H

#include "ExportedByLatticeModel.h"

// System
#include "IUnknown.h"

// Lattice
#include "LatticeModel.h"
#include "CATSysErrorDef.h"

class LatticeNBModelConstVisitor;

/**
*	@brief Minimal Lattice Nodes and Beams model
*/
class ExportedByLatticeModel LatticeNBModel
{
public:

    template< typename T >
    struct Node
    {
        T x, y, z;
        T radius; // Maximum radius of incident beams. Should be read
                  // only, do not instanciate or stream it yourself
                  // ( value defined in the AddBeam method)
        unsigned id;
    };

    template< typename T >
    struct Beam
    {
        unsigned n1, n2;
        unsigned id;
        T r1, r2;
    };

public:

    // implementation with boost encapsulated in order to change it if needed

    typedef LatticeModel< Node<double>, Beam<double> >    Type;

    typedef typename Type::vertex_bundled               NodeType;
    typedef typename Type::edge_bundled                 BeamType;
    typedef typename Type::vertex_descriptor            NodeDescriptor;
    typedef typename Type::edge_descriptor              BeamDescriptor;
    typedef typename Type::vertex_iterator              NodeIterator;
    typedef typename Type::edge_iterator                BeamIterator;
    typedef typename Type::adjacency_iterator           AdjacencyIterator;
    typedef typename Type::out_edge_iterator            OutEdgeIterator;

public:

    LatticeNBModel();

    virtual ~LatticeNBModel();

    /**
    * @brief AddNode
    *
    * @param x
    * @param y
    * @param z
    * @param id
    *
    */
    NodeDescriptor AddNode(double x, double y, double z, unsigned id);

    /**
    * @brief AddBeam
    *
    * @param n1 id of the node 1
    * @param n2 id of the node 2
    * @param id id of the beam
    * @param r1 radius of beam node 1
    * @param r2 radius of beam node 2
    *
    */
    std::pair<BeamDescriptor, bool> AddBeam(unsigned n1, unsigned n2, unsigned id, double r1, double r2);


    /**
    * @brief a pair of node iterator begin, end of all nodes
    *
    */
    inline std::pair<NodeIterator, NodeIterator> GetNodes() const
    {
        return m_Model.Vertices();
    }

    /**
    * @brief a pair of node descriptor from the input beam
    *
    * @param iE
    */
    inline std::pair<NodeDescriptor, NodeDescriptor> GetNodes(const BeamDescriptor& iE) const
    {
        return m_Model.Vertices(iE);
    }

    /**
    * @brief look up node descriptor corresponding to a given id
    *
    * @param v
    *
    */
    inline NodeDescriptor GetNodeFromId(unsigned int iId) const
    {
        return m_Model.VertexById(iId);
    }

    /**
    * @brief a pair of beam iterator begin, end of all beams
    *
    */
    inline std::pair<BeamIterator, BeamIterator> GetBeams() const
    {
        return m_Model.Edges();
    }

    /**
    * @brief look up beam descriptor corresponding to given node ids
    */
    inline std::pair<BeamDescriptor, bool> GetBeamFromNodeIds(unsigned int iId1, unsigned int iId2) const
    {
        return m_Model.EdgeByVertexIds(iId1, iId2);
    }

    inline std::pair<AdjacencyIterator, AdjacencyIterator> GetAdjacentNodes(const NodeDescriptor& iNode) const
    {
        return m_Model.AdjacentVertices(iNode);
    }

    inline std::pair<AdjacencyIterator, AdjacencyIterator> GetAdjacentNodesById(unsigned int iId) const
    {
        return m_Model.AdjacentVerticesById(iId);
    }

    inline std::pair<OutEdgeIterator, OutEdgeIterator> GetOutEdges(const NodeDescriptor& iNode) const
    {
        return m_Model.OutEdges(iNode);
    }

    inline std::pair<OutEdgeIterator, OutEdgeIterator> GetOutEdgesById(unsigned int iId) const
    {
        return m_Model.OutEdgesById(iId);
    }

    inline unsigned NumNodes() const
    {
        return m_Model.NumVertices();
    }

    inline unsigned NumBeams() const
    {
        return m_Model.NumEdges();
    }

    inline unsigned NodeSupId() const
    {
        return m_Model.VertexSupId();
    }

    inline unsigned BeamSupId() const
    {
        return m_Model.EdgeSupId();
    }


    /**
    * @brief access node data from its descriptor
    *
    * @param v
    *
    */
    inline NodeType& operator[](const NodeDescriptor& iNode)
    {
        return m_Model[iNode];
    }

    /**
    * @brief access node data from its descriptor
    *
    * @param v
    *
    */
    inline const NodeType& operator[](const NodeDescriptor& iNode) const
    {
        return m_Model[iNode];
    }

    /**
    * @brief access beam data from its descriptor
    *
    * @param e
    *
    */
    inline BeamType& operator[](const BeamDescriptor& iBeam)
    {
        return m_Model[iBeam];
    }

    /**
    * @brief access beam data from its descriptor
    *
    * @param e
    *
    */
    inline const BeamType& operator[](const BeamDescriptor& iBeam) const
    {
        return m_Model[iBeam];
    }

    double GetMinRadius() const;

    double GetMaxRadius() const;

    /**
    * @brief Clamp min radius
    *
    * @param iRadius
    *
    */
    void SetMinRadius(double iRadius);

    void GetBoundingBox(double(&oMin)[3], double(&oMax)[3]) const;

    int GetNbConnectedComponents() const
    {
        int *verticesComponentsMap, *nbVerticesPerComponent;
        int ret = m_Model.GetNbConnectedComponents(verticesComponentsMap, nbVerticesPerComponent);
        if (verticesComponentsMap)
            delete verticesComponentsMap;
        if (nbVerticesPerComponent)
            delete nbVerticesPerComponent;
        return ret;
    }

    int GetNbConnectedComponents(int *& oVerticesComponentsMap, int*& oNbVerticesPerComponent) const
    {
        return m_Model.GetNbConnectedComponents(oVerticesComponentsMap, oNbVerticesPerComponent);
    }

public:

    virtual HRESULT Accept (LatticeNBModelConstVisitor& iV) const;

private:

    LatticeNBModel(LatticeNBModel &) = delete;

    LatticeNBModel& operator=(LatticeNBModel&) = delete;

    double m_MinRadius, m_MaxRadius;
    double m_Min[3];
    double m_Max[3];

    LatticeModel< Node<double>, Beam<double> > m_Model;
};


#endif
