// COPYRIGHT Dassault Systemes 2009
//==============================================================================
//
// CATPolyMeshRemeshOper.h
// Header definition of CATPolyMeshRemeshOper
//
//==============================================================================
//
// Usage notes: 
//       Use to apply an Remesh to a CATIPolyMesh CGM Model. A new 
//       representation will be created.
//
//==============================================================================
//
//  Jul 2009  Creation: TG2
//==============================================================================
#ifndef CATPolyMeshRemeshOper_H
#define CATPolyMeshRemeshOper_H


#include "CATMapOfPtrPtrToPtr.h" 
#include "PolyBodyRemeshing.h"
#include "CATPolyBodyVOCOper.h"
#include "CATPolyBuildMeshOper.h"
#include "CATLISTV_CATMathPoint.h"
#include "CATLISTV_CATMathVector.h"
#include "CATMapOfIntIntToInt.h" 
#include "CATMapOfIntToInt.h" 
#include "stdlib.h"
#include <vector> 
#include <list> 
class CATIPolyMesh;
class CATMeshStar;
class CATMathPoint2D;


struct QuadriVertex

{
	int Idx;
	double Alpha;
	double Gamma;
	double Beta;

	CATMathVector N;


	
};
class  ExportedByPolyBodyRemeshing CATPolyMeshRemeshOper 
{

public:
	CATPolyMeshRemeshOper( CATIPolyMesh* iPolyMesh) ;

	//------------------------------------------------------------------------------
	// Destructor
	//------------------------------------------------------------------------------
	virtual~CATPolyMeshRemeshOper();




		/** @name Settings
		@{ */

	/**
	* Sets a flag to allow the decimation only (if true)  or to allow a complete remeshing (if false).
	* @param iOnlyDecimate
	*   The input flag .
	*  
	*/
	void SetOnlyDecimate(bool iOnlyDecimate);

	/**
	* Set a flag to allow the sharpness detection af Vertices .
	* @param iVertexSharpnessDetection 
	*   The input flag .
	*  (by default a vertex is consedered as sharp if its first ring neighborhood has a bar which makes an angle with the normal at the vertex greater than PI/4. )
	* A sharp Vertex will be kept.
	*/
   void ActivateVertexSharpnessDetection(bool iVertexSharpnessDetection);
		
  /**
   * Set the vertex sharpness threshold. It can take values between  0 and  PI/2 .
   * If the first ring neighborhood of a vertex has a bar which makes an angle with the normal at the vertex greater than iMaxVertexSharpnessThreshold , the vertex is said sharp and will be kept. 
   * @param iMaxVertexSharpnessThreshold
   *   The input threshold .
   */
	void SetMaxVertexSharpnessThreshold(const double &iMaxVertexSharpnessThreshold);

   /**
   * Set the differential vertex sharpness threshold. It can take values between  0 and  PI/2 .
   * If the difference of angle  , between the max angle between the bars and the normal , and ,  between the min angle between the bars and the normal,  is greater than iMaxMinVertexSharpnessThreshold , the vertex is said sharp and will be kept. 
   * @param iMaxMin VertexSharpnessThreshold
   *   The input threshold .
   */
   
	void SetMaxMinVertexSharpnessThreshold(const double &iMaxMinVertexSharpnessThreshold);

 

    /**
   * Set the level of Loop subdivision of the mesh after its previous decimation.
   * @param iLevelOfSubdivision
   */
        void SetLevelOfSubdivision(int ilevelOfSubdivision);

	/**
	* Sets a flag to allow the Laplacian smoothing of the resulting mesh (with a following projection of the result onto the original mes).
	* @param iLaplacianSmoothing 
	*   The input flag .
	*/              
        void ActivateLaplacianSmoothing(bool iLaplacianSmoothing);

		void  ActivateTheFlip(bool iActivateTheFlip );

        void  ActivateGetTheReferenceMesh(bool iGetTheReferenceMesh );

        void  SetBoundaryConstraints(CATListOfInt &TheBound,CATListOfInt &TheStatus );

		void FreezeBoundaries(bool iFreeze);

	/** 
	* Run the Operator .
	*/         
        HRESULT Run();
    /**
	* Get the operator name
	*/  
         const char *  GetOperatorName();
 /**
	* Set internal edge: the remeshing will keep the nature of these edges  
	*/  
    void  SetInternalEdges(CATLONG32 &NbInternalEdges,CATListOfInt * iInternalEdges) ;    
	void SetBoundaryMapping(CATMapOfIntIntToInt *MapBoundary);


	void SmoothTheMesh(CATIPolyMesh *_polyMesh,CATListOfInt &CornerInit) ;

	void  ProjectMeshOnMesh(CATIPolyMesh *Mesh,CATIPolyMesh *Mesh_Target);
	CATIPolyMesh * _Mesh_Proj;
    private:

		bool   _VertexSharpnessDetection;

		bool   _LaplacianSmoothing;

		int    _SubdivisionLevel;

		bool   _OnlyDecimate;

		double _MaxVertexSharpnessThreshold;

		double _MaxMinVertexSharpnessThreshold;


		CATLONG32 _NbInternalEdges;

		CATListOfInt *_InternalEdges;

		int _Constraints; 

		bool _FreezeBoundaries; 

		CATListOfInt *_TheBound;  

		CATListOfInt *_TheStatus; 

		CATListOfInt *_TrueBoundary;  

		bool _GetTheReferenceMesh;

		bool _ActivateTheFlip; 

		 
		CATMapOfIntIntToInt *_MapBoundary;

        int _Nb_Boundaries;

		std::vector<std::list< QuadriVertex > > _Partition;

		CATMapOfIntToInt _Triangle_Num;

		CATMapOfIntToInt _Num_Triangle;

		CATMapOfIntToInt _TriangleNum;

    private:
		 
        void  BestSimplifyMesh(CATIPolyMesh *_polyMesh,CATIPolyMesh *MeshProj,CATIPolyMesh *MeshInit);
		void CleanMesh(CATIPolyMesh *_polyMesh,CATListOfInt &ListRemoved,CATListOfInt &CornerInit);
		void RegularizeTriangles(CATIPolyMesh *_polyMesh);
		CATIPolyMesh* _FinalMesh;

		CATIPolyMesh * _PolyMesh;
		
		void  SimplifyMesh(CATIPolyMesh *_polyMesh,CATIPolyMesh *MeshProj,CATIPolyMesh *PolyMesh);

        void  SimplifyMeshBis(CATIPolyMesh *_polyMesh,CATIPolyMesh *MeshProj,CATIPolyMesh *PolyMesh);

		void  NewSimplifyMesh(CATIPolyMesh *_polyMesh,CATIPolyMesh *MeshProj,CATIPolyMesh *PolyMesh);

		void FitMesh0ToBoundary(CATIPolyMesh *Mesh_Decime ,int Reconstruct, CATIPolyMesh *Mesh_Projete, CATIPolyMesh *Mesh_Initial);

		

		void SpecialLoopSubdivide(CATIPolyMesh *PolyMesh,CATIPolyMesh *Mesh_Proj,int Nb_Boundaries,CATListOfInt * Boundaries_Decim,CATListOfInt * Boundaries,
			CATListOfInt & NumVertex, CATListOfInt & NumTriangle, CATListOfDouble & ListeAlpha, CATListOfDouble & ListeBeta,CATListOfDouble &ListeGamma);

		 

		void LoopSubdivide(CATIPolyMesh *PolyMesh,int Level);

		void FitMesh0Inside(CATIPolyMesh *Mesh_Decime , int Reconstruct,CATIPolyMesh *Mesh_Projete,CATIPolyMesh *Mesh_Initial);

		int  ProjectOnBoundary(CATMathPoint &P,CATIPolyMesh *Mesh_Projete,int &Num_Tri,double & Alpha,double & Beta,double& Gamma,double &DMin);

		int IsABord(CATIPolyMesh *PolyMesh,CATLONG32 Idx);

		void GetTriangleAdjacent(CATIPolyMesh *PolyMesh,CATLONG32 it ,int iB ,CATLONG32 &itAdj, int &iBAdj);

		void 	RemeshNeighboor(CATLONG32 NbVertex,CATLONG32 i ,CATIPolyMesh *_PolyMesh,CATMeshStar **MyMeshStar,CATIPolyMesh *Mesh_Proj,

						CATListOfInt &NumVertex,CATListOfInt &NumTriangle,CATListOfDouble &ListeAlpha,CATListOfDouble &ListeBeta,CATListOfDouble &ListeGamma,CATIPolyMesh *_polyMesh
						,CATLONG32 Nb_Boundaries,CATListOfInt *Boundaries_Decim,CATListOfInt *Boundaries);

		int  NewCheckNewTriangle (int NbNewTri,CATLONG32 *TotalIndex,CATMeshStar &MyMeshStar ,
					  CATIPolyMesh *Mesh_Proj,CATListOfInt &NumVertex,CATListOfInt & NumTriangle,CATListOfDouble &ListeAlpha,CATListOfDouble &ListeBeta,CATListOfDouble &ListeGamma,
					  CATLONG32 Nb_Boundaries,CATListOfInt *Boundaries_Decim,CATListOfInt *Boundaries);

		void GetThePlanarProjection(CATLONG32 NbTri,CATLONG32 *TotalIndex,CATMathPoint2D *Points2D,double U,double V,CATLONG32 &TheTri,double &Alpha,double &Beta,double &Gamma);

        int IsAbarreIsABoundary(CATMeshStar &MyMeshStar,CATLONG32 I1,CATLONG32 I2);

		void FindLocalBoundary(CATLONG32 &Nb_Boundaries,CATListOfInt *Boundaries,CATListOfInt *Boundaries_Decim,CATLONG32 Vertex1,CATLONG32 Vertex2,CATListOfInt &Boundary);

		int   CheckSubdivisibility(CATIPolyMesh* Mesh_Proj,CATListOfInt &Boundary,CATLONG32 Vertex1,CATLONG32 Vertex2,CATLONG32 Vertex3  );

		void MathCheckSubdivisibility(CATLISTV(CATMathPoint) &BoundPoint,CATMathPoint &A,CATMathPoint &B,CATMathPoint &C,int Level,int &Result);

		void  ComputeMiddleFOfBoundary(CATIPolyMesh *Mesh,CATLONG32 Vertex0,CATLONG32 Vertex1,int Nb_Boundaries,CATListOfInt *Boundaries,CATListOfInt *Boundaries_Decim,CATMathPoint &PMidle);

		CATLONG32 LocateTriangle(CATLONG32 NbIt,CATLONG32 *It, CATLONG32 iTri);

		void ComputePointOnMeshProj(CATIPolyMesh *Mesh_Proj,CATIPolyMesh *PolyMesh,CATMathPoint &P,CATLONG32 ItTri1,CATLONG32 ItTri2,
			CATListOfInt &NumVertex, CATListOfInt &NumTriangle, CATListOfDouble &ListeAlpha, CATListOfDouble &ListeBeta,CATListOfDouble &ListeGamma,CATMathPoint &PProj);

		int MeshVerif(CATIPolyMesh *polyMesh);

		void  GetBoundaries(CATIPolyMesh *_PolyMesh,int & nbloops,CATListOfInt *Boundaries);

		void KeepInitialCorner(CATListOfInt &CornerInit,CATLONG32 &NbVertex,CATIPolyMesh*_polyMesh,CATMeshStar **MyMeshStar);

       void  BlockVertexNeighboor(CATLONG32 NbVertex,CATLONG32 &Idx,CATIPolyMesh *_polyMesh, CATMeshStar ** MyMeshStar);

       void FitBoundaries(int Nb_Boundaries,CATIPolyMesh *MeshProj,CATListOfInt *Boundaries_Decim,CATListOfInt *Boundaries ,CATIPolyMesh *_polyMesh,CATListOfInt * Boundaries_Ap
			 , CATIPolyMesh *MeshInit,int &level);

	    void Flipix(CATIPolyMesh *PolyMesh,int Index_Key,int *TheKey);

        int ToFlipix(int Index_Key,CATMathPoint  *Square,double &Rap,double &AngleThreshold);

		 void  UpdateBoundaryMapAfterSuppression(int Nb_Boundaries,CATListOfInt *Boundary,int& iVertex,CATMapOfIntIntToInt *iMapBoundary);

         void  SetTrueBoundary(int iNb_Boundaries,CATListOfInt *Boundary);

};

//-----------------------------------------------------------------------

#endif
