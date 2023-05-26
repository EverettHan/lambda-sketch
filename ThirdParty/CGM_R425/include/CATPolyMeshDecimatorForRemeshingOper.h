// COPYRIGHT Dassault Systemes 2009
//==============================================================================
//
// CATPolyMeshDecimatorForRemeshingOper.h
// Header definition of CATPolyMeshDecimatorForRemeshingOper
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
#ifndef CATPolyMeshDecimatorForRemeshingOper_H
#define CATPolyMeshDecimatorForRemeshingOper_H


 
#include "PolyBodyRemeshing.h"
#include "CATPolyBodyVOCOper.h"
#include "CATPolyBuildMeshOper.h"
#include "CATLISTV_CATMathPoint.h"
#include "CATLISTV_CATMathVector.h"
#include "CATMapOfIntToInt.h" 
 
#include "stdlib.h"
#include <vector> 
class CATIPolyMesh;
class CATMeshStar;
class CATMathPoint2D;

class  ExportedByPolyBodyRemeshing CATPolyMeshDecimatorForRemeshingOper 
{

public:
	CATPolyMeshDecimatorForRemeshingOper( CATIPolyMesh* iPolyMesh ,CATIPolyMesh* iMeshProj ) ;

	//------------------------------------------------------------------------------
	// Destructor
	//------------------------------------------------------------------------------
	virtual~CATPolyMeshDecimatorForRemeshingOper();




		/** @name Settings
		@{ */

	 

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
   * Set the wanted level of Loop subdivisibility  of the mesh  .
   * @param iLevelOfSubdivisibilityon
   */
	void SetLevelOfSubdivisibility(int ilevelOfSubdivisibility);

	  /**
   * Keep all the boundar vertex  .
   * @param iFreeze
   */
	void FreezeBoundaries(bool iFreeze);
	
	  /**
   * Keep some of boundary vertex  .
   * @param iTheBound iTheStatus
   */
	void  SetBoundaryConstraints(CATListOfInt &iTheBound,CATListOfInt &iTheStatus );

	void  ActivateGetTheReferenceMesh(bool iGetTheReferenceMesh );
	/**
	* Run the Operator .
	*/         
        HRESULT Run();

    /**
	* Get the operator name
	*/  
     const char *  GetOperatorName();
  
	
	 
    private:

		bool   _VertexSharpnessDetection;

		double _MaxVertexSharpnessThreshold;

		double _MaxMinVertexSharpnessThreshold;
		 
		int    _SubdivisionLevel;

		bool  _FreezeBoundaries;

		CATListOfInt *_TheBound ;

		CATListOfInt *_TheStatus ;

		bool _Constraints  ;

		CATIPolyMesh *_Mesh_Proj ; 

	    CATIPolyMesh *_PolyMesh ; 

		bool _GetTheReferenceMesh;

		int _NbPoint_Max;

		CATMathPoint2D *_Points2D;

		CATMathPoint2D * _Working_P2D;

		double         *_Theta;

		CATMathPoint   *_Points;

		CATLONG32      *_Num_Index;

		CATLONG32      *_Num_Vertices;

		int _Nb_Boundaries_Max;

		int _Nb_Boundaries;

		CATListOfInt * _Boundaries;
		CATListOfInt * _Boundaries_Decim;

		CATMapOfIntToInt  _Map_VertexToBoundaries;


    private:

		HRESULT   DecimateMesh(CATIPolyMesh *iPolyMesh,CATIPolyMesh *Mesh_Proj );

		HRESULT GetOrderedVertexNeighborsOfVertex(CATIPolyMesh*PolyMesh,CATLONG32 &Idx,CATListOfInt&Neighbours);

		HRESULT GetOrderedTriangleNeighborsOfVertex(CATIPolyMesh*PolyMesh,CATLONG32 &Idx,CATListOfInt &Triangle);

		HRESULT  GetOrderedNeighborsOfVertex(CATIPolyMesh*PolyMesh,CATLONG32 &Idx,CATListOfInt&Neighbours,CATListOfInt &Triangle);
  
		 
		HRESULT ReTriangulationUnderVertex(CATIPolyMesh *iPolyMesh, CATLONG32 &Idx, CATMapOfIntToInt &Map_Attached,
			CATIPolyMesh *Mesh_Proj, CATIPolyMesh *Mesh_Proj_Save, CATLONG32 *Proj_Attached,
			CATLONG32 *Proj_Attached_Save, CATLONG32 *Proj_Numerotation, CATMapOfIntToInt &Map_ShapeFactor,
			CATMapOfIntToInt &Map_Triangle_Proj_Num, std::vector<CATMathVector> &Normal_Triangle_Proj);

		void  TheConformalMesh(int IsBoundary,CATMathPoint &Center, CATLONG32 NbPoint,CATMathPoint Point[] ,CATMathPoint2D *Point2D,double *Theta);

		void TheInternalConformal( CATMathPoint &Center,CATLONG32 NbPoint,CATMathPoint Point[],CATMathPoint2D *Point2D,double *Theta );

		void TheBoundaryConformal( CATMathPoint &Center,CATLONG32 NbPoint,CATMathPoint Point[],CATMathPoint2D *Point2D ,double *Theta );

		int  TheCheckSubdivisibility(CATIPolyMesh* Mesh_Proj,CATListOfInt &Boundary,CATLONG32 Vertex1,CATLONG32 Vertex2,CATLONG32 Vertex3  );

		void TheMathCheckSubdivisibility(CATLISTV(CATMathPoint) &BoundPoint,CATMathPoint &A,CATMathPoint &B,CATMathPoint &C,int Level,int &Result);

		void  MathCheckSubdivisibility(CATLISTV(CATMathPoint) &BoundPoint,CATMathPoint &A,CATMathPoint &B,CATMathPoint &C,int Level,int &Result);

		void FindLocalBoundary(CATLONG32 &Nb_Boundaries,CATListOfInt *Boundaries,CATListOfInt *Boundaries_Decim,CATLONG32 Vertex1,CATLONG32 Vertex2,CATListOfInt &Boundary);

		int  VerifManifold(CATLONG32 Idx,int NbTri,CATLONG32 *TotalVertex);

		int  NumberOfExternalTriangleSharingBar(CATLONG32 i1,CATLONG32 i2);


		void LocatePointInPlane(CATMathPoint2D &P2D,int Nb_NewTriangle,int *Num_Index,CATMathPoint2D *Points2D, CATMathPoint  *Points,int &NumTri, CATMathPoint &P3D);

		void ComputeConformalPoint(CATIPolyMesh *Mesh,int Idx,int h,CATListOfInt &Triangles,CATMathPoint2D *Points2D,CATMathPoint &P_Proj, CATMathPoint2D &P2D) ;

		void MiseAjourMapPro( CATIPolyMesh *PolyMesh,CATIPolyMesh *Mesh_Proj,int Idx_Proj,int IndexTriangle);

		HRESULT IsAGoodVertex(CATIPolyMesh *Mesh,CATLONG32 Idx,CATMapOfIntToInt &TheMapos,
			CATMapOfIntToInt &Map_Triangle_Proj_Num, std::vector<CATMathVector> &Normal_Triangle_Proj);
		HRESULT  CheckAllocPoint(int & NbPoints);

		HRESULT  CheckAllocBoundary(int & NbBoundaries);

		int CheckStarSharpitude(CATListOfDouble &TheVivif,int NbPoint,double &Angle_Sharpifiant,double &Tol_Sharp,int *Indice_Split); 

		void  GetBoundaries(CATIPolyMesh *iPolyMesh ,int &Nb_Boundaries );
};

//-----------------------------------------------------------------------

#endif
