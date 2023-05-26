//===================================================================
// COPYRIGHT Dassault Systemes 2017/03/13
//===================================================================


#ifndef LatticeModel_H
#define LatticeModel_H

#include <set>

// Boost
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_traits.hpp>
// $BF Linux compilation bug #include <boost/graph/graphviz.hpp>
#include <boost/graph/connected_components.hpp>
#include <boost/graph/labeled_graph.hpp>

#include <iostream>
#include <fstream>

template< typename VertexProps, typename EdgeProps, typename VertexStorage = boost::mapS, typename EdgeStorage = boost::vecS >
class LatticeModel
{
public:

    typedef VertexProps                                                                                     vertex_type;
    typedef EdgeProps                                                                                       edge_type;
    typedef boost::labeled_graph<
        boost::adjacency_list< VertexStorage, EdgeStorage, boost::undirectedS, VertexProps, EdgeProps >,
        unsigned int >                                                                                      graph_type;

    typedef typename graph_type::vertex_descriptor                                                          vertex_descriptor;
    typedef typename graph_type::edge_descriptor                                                            edge_descriptor;
    typedef typename graph_type::vertex_bundled                                                             vertex_bundled;
    typedef typename graph_type::edge_bundled                                                               edge_bundled;

    typedef typename graph_type::vertex_iterator                                                            vertex_iterator;
    typedef typename graph_type::edge_iterator                                                              edge_iterator;
    typedef typename graph_type::adjacency_iterator                                                         adjacency_iterator;
    typedef typename graph_type::out_edge_iterator                                                          out_edge_iterator;


    LatticeModel() : m_vertex_sup_id(0), m_edge_sup_id(0) {}

    virtual ~LatticeModel() {}

    std::pair<vertex_iterator, vertex_iterator> Vertices() const
    {
        return boost::vertices(m_graph.graph());
    }

    std::pair<vertex_descriptor, vertex_descriptor> Vertices(const edge_descriptor& iE) const
    {
        return std::make_pair(boost::source(iE, m_graph.graph()), boost::target(iE, m_graph.graph()));
    }

    std::pair<edge_iterator, edge_iterator> Edges() const
    {
        return boost::edges(m_graph.graph());
    }

    std::pair<edge_descriptor, bool> Edge(const vertex_descriptor &iV1, const vertex_descriptor &iV2) const
    {
        return boost::edge(iV1, iV2, m_graph.graph());
    }

    std::pair<edge_descriptor, bool> EdgeByVertexIds(unsigned int iId1, unsigned int iId2) const
    {
        return boost::edge_by_label(iId1, iId2, m_graph);
    }

    vertex_descriptor VertexById(unsigned int iId) const
    {
        return m_graph.vertex(iId);
    }

    std::pair<adjacency_iterator, adjacency_iterator> AdjacentVertices(const vertex_descriptor& iV) const
    {
        return boost::adjacent_vertices(iV, m_graph.graph());
    }

    std::pair<adjacency_iterator, adjacency_iterator> AdjacentVerticesById(unsigned int iId) const
    {
        return boost::adjacent_vertices(m_graph.vertex(iId), m_graph.graph());
    }

    std::pair<out_edge_iterator, out_edge_iterator> OutEdges(const vertex_descriptor& iV) const
    {
        return boost::out_edges(iV, m_graph.graph());
    }

    std::pair<out_edge_iterator, out_edge_iterator> OutEdgesById(unsigned int iId) const
    {
        return boost::out_edges(m_graph.vertex(iId), m_graph.graph());
    }

    unsigned NumVertices() const
    {
        return static_cast<unsigned>(boost::num_vertices(m_graph.graph()));
    }

    unsigned NumEdges() const
    {
        return static_cast<unsigned>(boost::num_edges(m_graph.graph()));
    }

    vertex_bundled& operator[](vertex_descriptor v)
    {
        return m_graph.graph()[v];
    }

    const vertex_bundled& operator[](vertex_descriptor v) const
    {
        return m_graph.graph()[v];
    }

    edge_bundled& operator[](edge_descriptor e)
    {
        return m_graph.graph()[e];
    }

    const edge_bundled& operator[](edge_descriptor e) const
    {
        return m_graph.graph()[e];
    }

    unsigned int VertexSupId() const
    {
        return m_vertex_sup_id;
    }

    unsigned int EdgeSupId() const
    {
        return m_edge_sup_id;
    }

    int GetNbConnectedComponents(int *& oVerticesComponentsMap, int*& oNbVerticesPerComponent) const
    {
        oVerticesComponentsMap = new int[boost::num_vertices(m_graph.graph())];
        int nb_components = boost::connected_components(m_graph.graph(), oVerticesComponentsMap);

        oNbVerticesPerComponent = new int[nb_components]();
        for (int i = 0; i < boost::num_vertices(m_graph.graph()); i++)
        {
            oNbVerticesPerComponent[oVerticesComponentsMap[i]]++;
        }

        return nb_components;
    }

protected:

    friend class LatticeNBModel;
    friend class LatticePatternNBModel;

    vertex_descriptor AddVertex(const vertex_type& iVertex)
    {
        vertex_descriptor v = boost::add_vertex(iVertex.id, m_graph);
        m_graph.graph()[v] = iVertex;
        m_vertex_sup_id = iVertex.id > m_vertex_sup_id ? iVertex.id : m_vertex_sup_id;
        m_node_ids.insert(iVertex.id);
        return v;
    }

    /**
     * @brief AddEdge to the graph. 
     * Prerequisites: Nodes need to have been added first.
     * 
     * Warning: It is the responsibility of the caller
     * to check the returned bool in the pair. If false it indicates that the edge
     * was not created all right in which case the edge_descriptor is invalid.
     *
     * @param iEdge, the properties that you want to set on the to be created edge.
     * @return returns to you an edge descriptor.
     */
    std::pair<edge_descriptor, bool> AddEdge(const edge_type& iEdge)
    {
      /*vertex_descriptor v1 = boost::vertex( iEdge.n1, m_graph );
      vertex_descriptor v2 = boost::vertex( iEdge.n2, m_graph );*/
      std::pair<edge_descriptor, bool> e;

      if (m_node_ids.find(iEdge.n1) == m_node_ids.end() || m_node_ids.find(iEdge.n2) == m_node_ids.end()) {
        std::cout << "Error in LatticeModel::AddEdge, Edge with incorrect node provided, check that you graph is not corrupted." << std::endl;
        e.second = false;
        return e;
      }
      
      e = boost::add_edge_by_label(iEdge.n1, iEdge.n2, m_graph);

      if (e.second == true) {
        m_graph[e.first] = iEdge;
        m_edge_sup_id = iEdge.id > m_edge_sup_id ? iEdge.id : m_edge_sup_id;
      }
      
      return e;
    }

    graph_type    m_graph;

    unsigned int  m_vertex_sup_id;
    unsigned int  m_edge_sup_id;

    std::set<unsigned int> m_node_ids;
};

#endif
