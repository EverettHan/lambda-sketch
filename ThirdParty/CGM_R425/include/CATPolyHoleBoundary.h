#pragma once

#include "PolyBodyBoolean.h"
#include "CATMathPoint.h"
#include "CATMathVector.h"
#include "CATPolyBody.h"
#include "CATPolyFace.h"
#include "CATIPolyHoleBoundary.h"

#include <vector>
#include <utility>
#include <unordered_map>
#include <memory>


/**
* Class that describes a closed border in a polybody.
* It stores the geometric properties of the points of the loop.
*/
class ExportedByPolyBodyBoolean CATPolyHoleBoundary : public CATIPolyHoleBoundary {
public:
	/**
	* Constructor that takes a CATPolyBody. It will find an Edge that is adjacent
	* to exactly one face and construct the boundary by appending adjacent boundary edges
	* until forming a loop.
	* @param polyBody
	*		pointer to the polybody
	*/
	CATPolyHoleBoundary(CATPolyBody& polyBody);

	/**
	* Constructor that takes a CATPolyBody and information about the number of nodes at border.
	* It will need to add the nodes data to correctly define the boundary.
	* @param polyBody
	*		pointer to the polybody
	*/
	CATPolyHoleBoundary(CATPolyBody & polyBody, int nbNodes,
											bool iWithNormals = false,
											bool iWithAdjTriangle = false);

	/** 
	* Constructor that takes a CATPolyEdge. If this Edge is adjacent
	* to exactly one face, it constructs the boundary by appending adjacent boundary edges
	* until forming a loop.
	* @param edge
	*		an edge of the boundary
	*/
	CATPolyHoleBoundary(CATPolyBody& polyBody, CATPolyEdge& edge);

	/**
	* Constructs all the hole boundaries in the polybody, except the largest one if largest == false and there is more than one boundary.
	* @param polyBody
	*		pointer to the polybody
	* @param boundaries
	*		container for the boundaries
	* @param largest
	*		boolean that determines if the largest boundary is added to the container
	*/
	static void getBoundaries(CATPolyBody& polyBody, std::vector<std::unique_ptr<CATPolyHoleBoundary>>& boundaries, bool keepLargest = false);

	/**
	 * Returns the number of points in the boundary.
	 * @return
	 *   number of points.
	 */
	int GetNbNodes() const;

	/**
	 * Returns the position of a vertex.
	 * @param idx
	 *   The index of the vertex.
	 * @return
	 *   A CATMathPoint with the position of the vertex.
	 */
	CATMathPoint GetPosition(int idx) const;
	CATMathPoint const * GetPositions() const;

	void SetPosition(int idx, const CATMathPoint& pos);

	/**
	 * Returns the normal of a vertex.
	 * @param idx
	 *   The index of the vertex.
	 * @return
	 *   A CATMathVector with the normal of the vertex.
	 */
	CATMathVector GetVertexNormal(int idx) const;
	CATMathVector const * GetNormals() const;
	void SetVertexNormal(int idx, const CATMathVector& n);

	/**
	 * Returns the adjacent triangles of a vertex.
	 * @param idx
	 *   The index of the vertex.
	 * @param adjTriangles
	 *	 The output vector. Each pair of CATMathPositions represents the opposite bar
	 *	 of the vertex for each triangle.
	 */
	void GetAdjTriangles(int idx, std::vector<std::pair<CATMathPoint, CATMathPoint>>& adjTriangles) const;

	/**
	 * Links the mesh to the stored polybody. It adds al the topological information.
	 * @param face
	 *  The topological face that will be represented by the mesh.
	 * @param mesh
	 *  The mesh that we want to add to the polybody.
	 * @param idBoundaryToIdMesh
	 *  Vector that translates the index of a vertex in the boundary to its index in the mesh. 
	 *	idBoundaryToIdMesh[i] gives the index in the mesh of the i-th node in the boundary. 
	 * @return
	 *   S_OK on success or E_FAIL otherwise.
	 */
	HRESULT TopologicalLink(CATPolyFace& face, CATIPolySurface& mesh, const std::vector<int>& idBoundaryToIdMesh) const;

public: 
	/**
	 * Structure to describe a topological edge with informations that are usefull to the boudnary.
	 */
	struct orientedEdge {
		CATPolyEdge* topoEdge; /**< pointer to the CATPolyEdge */
		bool wellOriented; /**< true if the orientation of the CATPolyEdge is the same as the boundary, false otherwise */
		int nbPoints; /**< number of points in the geometrical curve corresponding to the CATPolyEdge */
	};

private:
	int _nbNodes;
	std::vector<CATMathPoint> listOfPositions;
	std::vector<CATMathVector> listOfVertexNormals;
	std::vector<std::vector<std::pair<CATMathPoint, CATMathPoint>>> listAdjTriangles;
	std::vector<orientedEdge> _topoCycle;

	CATPolyBody& _polyBody;

public:
	CATPolyHoleBoundary(CATPolyBody& polyBody, const std::vector<orientedEdge>& topoCycle);
	void readTopoCycle();

private:
	HRESULT addInformationsFromCurve(CATIPolyCurve& curve, bool wellOriented, int& addedPositions);
	void ComputeInformations(std::vector<CATIPolyCurve*>& curves);
	bool isWellOriented(int idEdge) const;	
};
