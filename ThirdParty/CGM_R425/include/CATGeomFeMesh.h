#ifndef CATGeomFeMesh_H
#define CATGeomFeMesh_H
//
// COPYRIGHT DASSAULT SYSTEMES 2003
//
//===================================================================
// Oct 2003  MPS  deplacement des classes imbriquees dans Protected
//                   pb de compil sur UNIX. 
// May 2003 - ALA - Creation
//===================================================================
#include "MathGeomFe.h"

#include "CATLISTP_CATMathPoint.h"
#include "CATListOfInt.h"
class	CATGeomFe3Dof;
class 	CATGeomFeTrian;
class 	CATGeomFeStringBar;
class 	CATGeomFeDirectionalViscosity;
class 	CATGeomFeSoftG1;
class 	CATGeomFeSolver;
class   CATGeomFeMVertex;
class   CATGeomFeMTriangle;
class   CATGeomFeMVertexDList;
class   CATGeomFeMTriangleDList;
class   CATGeomFeQuickMesh;
class   CATMathPoint;

 class ExportedByMathGeomFe CATGeomFeMesh 
{
  public:
	//
	CATGeomFeMesh();
	~CATGeomFeMesh();
	//
	void  SetScale(double iScale);
	int SetTesselation(float* iVertices, float* iNormals,int iNumberOfVertices,
								      int  * iTriangleIndices, int iNbTriangle,float *iTargetNormals=0);
	//
	//int AddInitialSharpLine(int iNumberOfVertices, int  * iVertexIndices, 
	//				float* iLeftNormal, float* iRightNormal);
	//
	int GetCurrentTesselation(float*& oVertices, float*& oNormals,int& oNumberOfVertices,
								      int  *& oTriangleIndices, int& oNbTriangle,float* & oObjectiveNormals) ;
	//
	int GetCurrentValidVertexIndices(int *oValidVertexIndices) const;
	//
	void SetTangentialMode();
	void SetNormalMode();
	void SetFreeMode();
	//
	void SetTension(float iCoefTension);
	void SetPressure(double iPressure);
	void SetBendingStiffness(double iStiffness);
	void SetLambdaStiffness(double iLambdaStiffness);
	//
	void SetBoundaryConstraintOrder(int iContOrder);
	//
	int OneStep(int increment=1);
	int RepairAll();
	int Repair();
	int Undo();
	//
	//
	//
	void setCoefHomotopySoftG1( double iCoefHomotopySoftG1); // between 0 and 1 ...

	void SetK_NormalizedShear(float iK_NormalizedShear);   //
	void SetK_ConvexNormalizedNormal(float iK_ConvexNormalizedNormal);   //

	double GetShift();
	double GetEnergyVariation();
	double GetEnergy();
	double GetMaximumChordalError();
	int EnergyIsLocallyConvex();
	int SplitInitialMesh(const double iCoefLengthMax = 1.5);
	// if consistent normals, i.e. dot product of geometric triangle normals
	// around a same vertex are positive
	int AreNormalsConsistent();
	int IsOrientationConsistent();

	int ImproveMeshConnectivity(const double TresholdSplit,
			const double CoefHauteurSplit,
			const double CoefHauteurSwap ,	
			const double TresholdCollapse, 
			const int ManageOneInternalEdge =0); 
	//
	double AngleMaxNormalesInitTarget() { return _AngleMaxNormalesInitTarget;};
	int UpdateBoundaryList(int G0Constraints=0);
	int SetInitialNormalsFromCurrentNormals();

	void ComputeNewVertex (int & oNumberOfOldVertices, int & oNumberOfVertices, float* & oSplitVertices, float* & oNormals,float*& oObjectiveNormals,
		int &oNbTriangle , int  *  &oSplitTriangleIndices);
	void SetOldVertices(const int ioldVertices);
        
    //manage the level of the code modifications.
    // iLevel=0  original version
    // iLevel=1 : 
    //  ---1) In ImproveMeshConnectivity, the creation of a triangle with 3 vertices on  Boundary 
	//        is not allowed when using EdgeCollapse of CATGeomFeTriangle
    //  ---2) SplitInitialMesh  returns an error  if SmoothNormals returns an error  
    void SetCodeLevel(const int iLevel=0);
	void SetMiddlePoint(float * iMiddlePoint);
 
	//
  protected:
	//
	void NotifyRemoveFromDlist(CATGeomFeMVertexDList *iVDL);  // a deplacer en prive ??
	void NotifyRemoveFromDlist(CATGeomFeMTriangleDList *iTDL);
	int ImproveNormals(int Toutes = 1, int LocalNormalize = 0, int UpdateInitialNormal = 0);
	int LaplacianSmoothing();
	double ComputeObjectiveLength();

	// return >0 if error...
	int SmoothNormals(double iWeight =1); 
	//
	void SetSquarredTension(float iSquarredTension);
	void SetBarStringStiffness(float iBarStringStiffnes); 
	//
	void SetK_NormalizedNormal(float iCoefUnitN); // a remonter dans CATGeomFeSurfElem ???
	void SetViscosity(float iViscosity); //
	//
	void InitMesh();
	//
	void Attach(CATGeomFeMVertex *iVertex);
	void Attach(CATGeomFeMTriangle *iTriangle);
	//
	int UpdateCurrentMesh();
	//
	void AppendAll();
	void UpdateTriangleElements();
    void SmoothValences(int CoefHauteurSwap); 
  


  // void Dump();
	

private:

	friend class CATGeomFeMTriangle;
	friend class CATGeomFeMVertex;

	void AddToBoundaryList(CATGeomFeMVertex *iVertex);

	void UpdateCoefs();
	void UpdateDofsConstraints();
	//int InitializeCurrentMeshAndSolver();
	


	CATGeomFeSolver *_Solver;
	//
	double _K_NormalizedNormal;
	double _CoefTension;
	// stiffness coefficient for internal constitutive energies 
	// of normalization of N and shear (N tends to be normal to the surface tangent plane DU, DV)
	//double	_K_NormalizedNormal;
	//  remarque : en anglais shear signifie cisaillement  (au sens resistance des materiaux)
	double	_K_NormalizedShear; 
	double	_K_ConvexNormalizedNormal;
	//
	double	_Viscosity;	// augments the Hessian with damping terms
	//CATGeomFeDirectionalViscosity::Direction	_DirViscosity;	
	int _DirViscosityIsTangent;
	//
	double _Pressure;
	double _BendingStiffness;
	double _LambdaStiffness;
	double _SquarredTension;
	double _K_BarStringStiffnes;
	double _CoefHomotopySoftG1;
	//
	double _Scale;
	double _InvScale;
	//
	int _BoundaryContinuityOrder;
	//
	//
	CATGeomFeMTriangleDList *_firstTriangle;
	CATGeomFeMTriangleDList *_lastTriangle;
	//
	CATGeomFeMVertexDList *_firstVertex;
	CATGeomFeMVertexDList *_lastVertex;
	//
	CATGeomFeMVertexDList *_firstBoundaryVertex;
	CATGeomFeMVertexDList *_lastBoundaryVertex;
	//
	CATGeomFeQuickMesh **_UndoStack;
	CATGeomFeQuickMesh **_Current_Mesh;
	int _IndexUndoStack;
	double	_ObjectiveLength;
	double  _CoefLongueurMax;
	int _First;
	double _AngleMaxNormalesInitTarget;
	CATListOfInt _ListeNewTriangles;
	int _OldVertices;
	int _LongueurEdgeNulle;
    int _CodeLevel;
	//
	////////////////////////////////////////////////////
	//

	//
};


#endif
