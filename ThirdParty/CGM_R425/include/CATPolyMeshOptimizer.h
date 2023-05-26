
#pragma once

#include "PolyBodyBoolean.h"
#include "CATIPolyMesh.h"
#include "CATPolyHoleBoundary.h"
#include "CATTolerance.h"
#include <functional>

class CATProgressCallback;


/**
* Operator that given a triangular mesh and a function,
* modifies the mesh to minimize the function.
* It performs a gradient descent algorithm.
*/
class ExportedByPolyBodyBoolean CATPolyMeshOptimizer {

public:
	CATPolyMeshOptimizer();

	/**
	*  Various setters to modify the parameters of the optimization algorithm
	*/
	void SetLaplacianType(int type);
	void SetNbMaxIteFirst(int nbIte);
	void SetEpsChange(double eps);
	void SetNbMaxIteSecond(int nbIte);
	void SetTolerance(const CATTolerance& tolerance);
	void AddGrad(std::function<CATMathVector(CATMathPoint)>* grad);

	/**
	*	Function to add information about the border of the mesh 
	*/
	void AddBoundaryInformation(const CATIPolyHoleBoundary& boundary, const std::vector<int>& idBoundaryToIdMesh);

	/**
	*	Functions for the visualization
	*/
	void SetObserver(std::function<void(CATIPolyMesh&)>* reactToStep);
	void SetProgressCB(CATProgressCallback* progressCB);

public:
	/**
	*  An enum taht describes the type of Laplacian used in the computations
	*/
	enum LaplacianType 
	{ 
		UNIFORM, /**< average of the neighbor's positions*/
		SCALED, /**< weighted average of the neighbors position. The weights are the inverse of the distance*/
		HARMONIC /**< depends of the cotangent of the opposite angles in each adjacent triangles */
	};

	/**
	*  Runs the gradient descent on the mesh.
	* @param mesh 
	*		reference to the mesh we want to optimize.
	* @param boundary
	*		pointer to the boudnary of the mesh if some border conditions must be satisfied.
	* @param reactToStep
	*		function describing what to do after each iteration of the algorithm.
	* @param progressCB
	*		pointer to a progress callback.
	* @retrun 
	*  S_OK on success, E_FAIL otherwise.
	*/
	HRESULT Run(CATIPolyMesh& mesh);

	

private:
	CATIPolyMesh* _mesh;

	std::vector<const CATIPolyHoleBoundary*> _boundaries;
	std::unordered_map<int, std::pair<int, int>> _idMeshToIdBoundary;

	/**
	*  Parameters of the algrithm
	*/
	double EPSILON; /**< If after one step all the points in the mesh move by less than EPSILON, then the algorithm stops.*/
	int MAX_ITER_FIRST; /**< Maximum number of iterations for the first order laplacian.*/
	int MAX_ITER_SECOND; /**< Maximum number of iteration for the second order laplacian*/
	LaplacianType type; /**< Type of laplacain used. */

	const CATTolerance* _tolerance;
	std::function<CATMathVector(CATMathPoint)>* _addGrad;

	std::function<void(CATIPolyMesh&)>* _reactToStep;
	CATProgressCallback* _progressCB;

	std::vector<int> _freeVertices;
	std::unordered_map<int, CATMathVector> _laplacians;


	

private:
	void findFreeVertices();
	bool isInBoundary(int idu);
	void addAdjTriangles(int idu, std::vector<std::pair<CATMathPoint, CATMathPoint>>& adjTriangles);

	CATMathVector computeFirstOrderLaplacian(int idu);
	CATMathVector computeSecondOrderLaplacian(int idu);
	CATMathVector computeLaplacian(int order, int idu);

	void computeWeights(CATMathPoint& orig, std::vector<std::pair<CATMathPoint, CATMathPoint>>& adjTriangles, std::vector<double>& weights);
	void computeLaplacians();

	HRESULT fairing(int order, int MAX_ITER, CATProgressCallback& progressCB);
};



