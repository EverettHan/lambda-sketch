// COPYRIGHT Dassault Systemes 2009
//==============================================================================
//
//  CATPolyBodySmoothingOper.h
// Header definition of  CATPolyBodySmoothingOper
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
#ifndef  CATPolyBodySmoothingOper_H
#define  CATPolyBodySmoothingOper_H


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
#include "CATMathPoint2D.h"
#include "CATMathPoint.h"

#include <vector>
struct SmoothMeshWithBoundaries 

{

  

 CATIPolyMesh* SMWB_PolyMesh;
 CATIPolyMesh* SMWB_PolyMesh_Init;
 
 CATIPolyMesh* SMWB_PolyMesh_Dup;
 CATIPolyMesh* SMWB_PolyMesh_Guide;
 CATIPolyMesh* SMWB_PolyMesh_Target;

 std::vector<CATIPolySurfaceVertexLine *> SMWB_Bounding_PolyLine;
 std::vector<CATIPolySurfaceVertexLine *> SMWB_Bounding_PolyLine_Init;
  
 std::vector<CATIPolySurfaceVertexLine *> SMWB_Bounding_PolyLine_Dup;
 std::vector<CATIPolySurfaceVertexLine *> SMWB_Bounding_PolyLine_Guide ;
 int SMWB_Count;
  
  
};
struct SmoothStarConform

{
	CATIPolyMesh* SMCONF_PolyMesh;
	int SMCONF_Idx;
	int SMCONF_BadShape;
	CATMathPoint SMCONF_Center3D;

	std::vector<int> SMCONF_NeighborVertex3D;
	std::vector<int> SMCONF_NeighborTriangle3D;
	std::vector<CATMathPoint> SMCONF_Point3D;

	std::vector<CATMathPoint2D> SMCONF_ConformPoint2D;
	std::vector<double> SMCONF_ConformAngle2D;
	std::vector<double> SMCONF_ConformRadius2D;

};
struct BarycCoord

{
	CATIPolyMesh* PolyMesh_Proj;
	
	int Triangle;
	double Alpha;
	double Beta;
	double Gamma;

	CATIPolyMesh* PolyMesh;
	int Vertex;

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

class ExportedByPolyBodyRemeshing  CATPolyBodySmoothingOper  
{
  

    public:

        //======================================================================
        // Constructor
        //======================================================================
         CATPolyBodySmoothingOper( CATPolyBody* iPolyBody );

        //======================================================================
        // Destructor
        //======================================================================
        virtual ~ CATPolyBodySmoothingOper();

public :    
	 
	 
    
	/**
	* Run the Operator .
	*/         
        HRESULT Run();
    /**
	* Get the remeshed polybody .
	*/        
	void GetBodyResult(CATPolyBody *& ioPolyBody,CATMapOfPtrToPtr *& ioInversemap);	 
   /**
	* Get the operator name
	*/  
     const char *  GetOperatorName();

 /**
	* Set guide and target body: projection onto guide body and transfert on target body 
		*/ 

	 HRESULT   SetGuidePolyBody(CATPolyBody* iGuidePolybody, CATPolyBody* iTargetPolybody);

	 /**
	 * Set the number of iteration on laplacian smothing.If =0 do only the projection onto the guide body. 
	 */
	 void   SetNbIter(int& iNbIter);



    private:

		HRESULT  SmoothingCreationFinalBody(SmoothMeshWithBoundaries *TheMeshWithBoundaries) ;

		HRESULT  ConstructMeshWithBoundaries(SmoothMeshWithBoundaries *TheMeshWithBoundaries);

		HRESULT  TheSmoothMeshWithBoundaries(SmoothMeshWithBoundaries *TheMeshWithBoundaries);

		HRESULT  SmoothingInternalMesh(SmoothMeshWithBoundaries &TheMeshWithBoundaries,CATMapOfIntToInt *Map);

		HRESULT SmoothingPolyLine(CATIPolyMesh *iPolyMesh,std::vector<CATIPolySurfaceVertexLine *> Bounding_PolyLine) ;

		HRESULT GetPointFromPolyLine(CATIPolyMesh *iPolyMesh,CATIPolySurfaceVertexLine *PolyLine_New, std::vector<CATMathPoint > &Point,std::vector<int  > &Vertex);

		HRESULT  FitPolyLineToPolyLine(CATIPolyMesh *Mesh_New ,CATIPolySurfaceVertexLine *PolyLine_New,
			CATIPolyMesh *Mesh_Old , CATIPolySurfaceVertexLine *PolyLine_Old,CATIPolyMesh *Mesh_Target =0);

		HRESULT  SmoothingPolyLine(SmoothMeshWithBoundaries & TheMeshWithBoundaries);

		void  SetGlobalFirstSrcVertexToDstVertexMap(CATMapOfIntToInt **ioGlobalMap);

		HRESULT   SetTargetPolyBody(CATPolyBody *iPolyBody);

		 

        CATPolyBody * _InitPolyBody;

		CATPolyBody * _FinalPolyBody;

		CATPolyBody * _TargetPolyBody;

		CATPolyBody * _GuidePolyBody;

		int _Nb_Faces ;

		CATIPolyMesh ** _TheMesh;

		 

		CATIPolyMesh ** _TheMesh_Dup;

		CATIPolyMesh ** _TheMesh_Guide;

		CATIPolyMesh ** _TheMesh_Target;

		CATPolyFace **  _TheFace;
    
		CATMapOfIntToInt ** _FirstSrcVertexToDstVertexMap;

		CATMapOfIntToInt ** _Guide_FirstSrcVertexToDstVertexMap;

		CATMapOfPtrToInt _MeshPosition;
 
        CATMapOfPtrToPtr _InverseMap;

		CATMapOfPtrToPtr _MappingAdaptMeshes; 

		CATMapOfPtrToPtr _MappingAdaptPolyLines;

		int _ExteriorAdaptMapping; 
		CATMapOfPtrToPtr *_MapMeshTarget  ;
		CATMapOfPtrToPtr *_MapMeshProj  ;
	 

		CATMapOfPtrToPtr *_MapPolyLineTarget  ;
		CATMapOfPtrToPtr *_MapPolyLineProj  ;

		int _Nb_Iter;
		SmoothMeshWithBoundaries *_TheMeshWithBoundaries;
		std::vector<BarycCoord  > _TheBaryc;
};

//-----------------------------------------------------------------------

#endif
