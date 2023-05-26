// COPYRIGHT Dassault Systemes 2009
//==============================================================================
//
//  CATPolyBodySubdivisionOper.h
// Header definition of  CATPolyBodySubdivisionOper
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
#ifndef  CATPolyBodySubdivisionOper_H
#define  CATPolyBodySubdivisionOper_H


#include "PolyBodyRemeshing.h"
 
 
#include"CATPolyBody.h"
#include"CATPolyFace.h"
#include"CATIPolyMesh.h"
#include"CATIPolySurfaceVertexLine.h"
#include"CATMapOfPtrToPtr.h"
#include"CATMapOfPtrPtrToPtr.h"
#include "CATMapOfIntToInt.h"
#include "CATMapOfPtrToInt.h"
#include "CATMapOfIntIntToInt.h"

#include <vector>
 


struct MeshWithBoundaries 

{



 CATIPolyMesh* MWB_PolyMesh;
 CATIPolyMesh* MWB_PolyMesh_Init;
 std::vector<CATIPolySurfaceVertexLine *> MWB_Bounding_PolyLine_Init;
 std::vector<CATIPolySurfaceVertexLine *> MWB_Bounding_PolyLine;
  
 int MWB_Count;
  
  
};
struct Barre 

{

int Barre_Id_Triangle;
int Barre_iBarre;

int Barre_Id_Triangle_Neighb;
int Barre_iBarre_Neighb;

std::vector<int > Barre_Vertex;
std::vector<CATMathPoint> Barre_Point;   
  
int Barre_IsUpDated ; 
};
struct TriBarre 

{
int TriBarre_IdxTriangle;
Barre TriBarre_Barre[3];
 
 
  
};
/**
 * Operator that do the remeshing of a  CATPolyBody.
 * It generates a CATIPolyMesh.
 * 
 * Initial CATIPolyBody is first converted in a CATIPloyMesh using  CATPolyBodyToPolyMeshConverter operator
 *
 * 
 *
 */

class ExportedByPolyBodyRemeshing  CATPolyBodySubdivisionOper  
{
  

    public:

        //======================================================================
        // Constructor
        //======================================================================
         CATPolyBodySubdivisionOper( CATPolyBody* iPolyBody ,int & iLevel_Subdivision);

        //======================================================================
        // Destructor
        //======================================================================
        virtual ~ CATPolyBodySubdivisionOper();

public :    
	/** @name Settings
	@{ */

	void  GetAdaptMapping(CATMapOfPtrToPtr *&MapMeshInit, CATMapOfPtrToPtr *&  MapPolyLineInit);
    
	/**
	* Run the Operator .
	*/         
        HRESULT Run();
    /**
	* Get the remeshed polymesh .
	*/        
	void GetBodyResult(CATPolyBody *& ioPolyBody,CATMapOfPtrToPtr *& ioInversemap);	 
   /**
	* Get the operator name
	*/  
     const char *  GetOperatorName();

	 /**
	 * Special for remeshing : Mapping vers le body init et le bodyproj
	 */

	 void SetAdaptMapping(CATMapOfPtrToPtr &MapMeshTarget, CATMapOfPtrToPtr &MapMeshProj,
		 CATMapOfPtrToPtr &MapPolyLineTarget, CATMapOfPtrToPtr &MapPolyLineProj);
    private:
		HRESULT  GetPointFromPolyLine(CATIPolyMesh *iPolyMesh, CATIPolySurfaceVertexLine *PolyLine_New, std::vector<CATMathPoint > &Point, std::vector<int  > &Vertex);
		HRESULT  ConstructMeshWithBoundaries(MeshWithBoundaries *TheMeshWithBoundaries);
		HRESULT  VerifMeshWithBoundaries(MeshWithBoundaries *TheMeshWithBoundaries);
		HRESULT  SubdivideMeshWithBoundaries(MeshWithBoundaries *TheMeshWithBoundaries);

		HRESULT  LoopSubdivideMesh( CATIPolyMesh *iPolyMesh,CATMapOfIntIntToInt &Map_Vertex_Inserted_Prev_OnPolyLine);
			 
		 
		HRESULT  SubdivisionPolyLine( int &iLevel,CATIPolyMesh *iPolyMesh, CATIPolySurfaceVertexLine& Bounding_PolyLine,
														TriBarre *TheTriBarre, CATMapOfIntToInt &Map_Triangle_Rang) ;

		 

		HRESULT SubdivisionSetOfPolyLine(int &iLevel, MeshWithBoundaries  & TheMeshWithBoundaries, TriBarre *TheTriBarre, CATMapOfIntToInt &Map_Triangle_Rang);

		HRESULT  SubdivisionAndAdaptPolyLine(int &iLevel, CATIPolyMesh *iPolyMesh,  CATIPolySurfaceVertexLine & Bounding_PolyLine,
			TriBarre *TheTriBarre, CATIPolyMesh *Mesh_Target,  CATIPolySurfaceVertexLine   & Bounding_PolyLine_Target, CATMapOfIntToInt &Map_Triangle_Rang);

		 

		HRESULT  CreationFinalBody(MeshWithBoundaries *TheMeshWithBoundaries) ;
		 
        
			 
		HRESULT  NewLoopSubdivideMesh(int &iLevel,CATIPolyMesh *TheMesh,CATLONG32 &Nb_Triangles, int *TheTriangle,TriBarre *TheTriBarre,CATMapOfIntToInt &Map_Triangle_Rang) ;

		void     InitializeTriBarre(int iLevel,CATIPolyMesh* iPolyMesh,int &Nb_Triangle,CATLONG32 *TheTriangle,TriBarre *TheTriBarre,
													CATMapOfIntToInt &Map_Rang_Triangle ) ;

		HRESULT  FitLineToLine(std::vector<CATMathPoint > &Point_Old, std::vector<CATMathPoint > &Point_New);

		HRESULT  GetPointFromPolyLine(CATIPolyMesh *iPolyMesh, CATIPolySurfaceVertexLine &PolyLine, std::vector<CATMathPoint > &Point);
		HRESULT  FitPolyLineToPolyLine(CATIPolyMesh *Mesh_New, CATIPolySurfaceVertexLine *PolyLine_New,
			CATIPolyMesh *Mesh_Old, CATIPolySurfaceVertexLine *PolyLine_Old);
		int _Level;

        CATPolyBody * _InitPolyBody;

		CATPolyBody * _FinalPolyBody;
         
		int _Nb_Faces ;

		CATIPolyMesh ** _TheMesh;

		CATPolyFace **  _TheFace;
    
		CATMapOfIntToInt ** _FirstSrcVertexToDstVertexMap;

		CATMapOfPtrToInt _MeshPosition;
 
        CATMapOfPtrToPtr _InverseMap;

		CATMapOfPtrToPtr _MapMeshInit;

		CATMapOfPtrToPtr _MapPolyLineInit;
 

		 int *_IndexPyr[3]; 

		int _DeuxExpLevel; 

		int _ExteriorAdaptMapping;

		MeshWithBoundaries *_TheMeshWithBoundaries;
};

//-----------------------------------------------------------------------

#endif
