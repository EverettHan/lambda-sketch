// COPYRIGHT Dassault Systemes 2009
//==============================================================================
//
//  CATPolyBodySimplifyOper.h
// Header definition of  CATPolyBodySimplifyOper
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
#ifndef  CATPolyBodySimplifyOper_H
#define  CATPolyBodySimplifyOper_H


#include "PolyBodyRemeshing.h"
 
 
#include"CATPolyBody.h"
#include"CATPolyFace.h"
#include"CATIPolyMesh.h"
#include"CATPolySurfaceVertexLine.h"
#include"CATMapOfPtrToPtr.h"
#include"CATMapOfPtrPtrToPtr.h"
#include "CATMapOfIntToInt.h"
#include "CATMapOfPtrToInt.h"
#include "CATMapOfIntIntToInt.h"

#include <vector>
struct Struct_PolySurfaceVertex
{
	CATIPolySurfaceVertexLine * SPSV_Bounding_PolyLine;

    CATLONG32 SPSV_Rang_Neighbor ;

	 
	 
	CATMapOfIntToInt   SPSV_MapToBNeighborVertex;

};

struct Struct_SimplifyMeshWithBoundaries 

{

 CATIPolyMesh* SMWB_PolyMesh_Init; 

 CATIPolyMesh* SMWB_PolyMesh;

 CATIPolyMesh* SMWB_PolyMesh_Work;

 CATIPolyMesh* SMWB_PolyMesh_Proj;

 CATIPolyMesh* SMWB_PolyMesh_Duplic;

 //std::vector<CATIPolySurfaceVertexLine *> SMWB_Bounding_PolyLine;
 std::vector<Struct_PolySurfaceVertex> SMWB_Bounded_PolyLine;

 CATMapOfIntToInt * SMWB_FirstSrcVertexToDstVertexMap  ;

 int SMWB_Count;
  
  
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

class ExportedByPolyBodyRemeshing  CATPolyBodySimplifyOper  
{
  

    public:

        //======================================================================
        // Constructor
        //======================================================================
         CATPolyBodySimplifyOper( CATPolyBody* iPolyBody );

        //======================================================================
        // Destructor
        //======================================================================
        virtual ~ CATPolyBodySimplifyOper();

public :    
	/** @name Settings
	@{ */

	 
    
	/**
	* Run the Operator .
	*/         
        HRESULT Run();
    /**
	* Get the remeshed polymesh .
	*/        
	void GetBodyResult(CATPolyBody *& ioPolyBody,CATMapOfPtrToPtr *& ioInversemap);	 
 
 /**
	* Get the projection polybody .
	*/        
	void GetBodyProjection(CATPolyBody *& ioPolyBody);

	 
	void GetBodyDuplicate(CATPolyBody *& ioPolyBody);
   /**
	* Get the operator name
	*/  
     const char *  GetOperatorName();
	 void  SetTargetLevelOfSubdivision(const int &iLevel);
 
    private:

		HRESULT  ConstructMeshWithBoundaries(Struct_SimplifyMeshWithBoundaries *TheMeshWithBoundaries);

		HRESULT  SimplifyMeshWithBoundaries(Struct_SimplifyMeshWithBoundaries *TheMeshWithBoundaries);

		void  InitialiseWorkingMesh(Struct_SimplifyMeshWithBoundaries &TheMeshWithBoundaries) ;

		HRESULT UpdateMeshWithBoundaries(Struct_SimplifyMeshWithBoundaries & TheMeshWithBoundaries,CATListOfInt &TheBound,CATListOfInt &TheStatus) ;

		HRESULT  CreationFinalBody(Struct_SimplifyMeshWithBoundaries *TheMeshWithBoundaries) ;

		HRESULT  CreationProjectBody(Struct_SimplifyMeshWithBoundaries *TheMeshWithBoundaries) ; 

		HRESULT  CreationDuplicateBody(Struct_SimplifyMeshWithBoundaries *TheMeshWithBoundaries);

		void FillBoundAndStatus(Struct_SimplifyMeshWithBoundaries  &SimplifyMeshWithBoundaries,CATListOfInt& TheBound,CATListOfInt &TheStatus);														
 
		void UpdateMeshProj(CATIPolyMesh *iMesh);

		void SwitchMesh(Struct_SimplifyMeshWithBoundaries &SimplifyMeshWithBoundaries);
         
		HRESULT  UpdateBoundAndSatus(Struct_SimplifyMeshWithBoundaries  * SimplifyMeshWithBoundaries,CATListOfInt *TheBound,CATListOfInt *TheStatus);

		HRESULT  DecimationMeshWithBoundaries(Struct_SimplifyMeshWithBoundaries &SimplifyMeshWithBoundaries);

        HRESULT   DecimationMeshWithBoundaries(Struct_SimplifyMeshWithBoundaries &SimplifyMeshWithBoundaries,CATMapOfPtrToPtr &Map_VertexStatus);

		void  GetMeshAndPolyLine(CATPolyBody *iPolyBody, std::vector<CATIPolyMesh *> &TabMesh, std::vector<CATIPolySurfaceVertexLine *> &TabPolyLine);

		void   GetGlobalFirstSrcVertexToDstVertexMap(CATMapOfIntToInt **&ioGlobalMap);
		 
        CATPolyBody * _InitPolyBody;

		CATPolyBody * _DuplicatePolyBody;

		CATPolyBody * _FinalPolyBody;

		CATPolyBody * _ProjPolyBody;
         
		int _Nb_Faces ;

		CATIPolyMesh ** _TheMesh;

		CATPolyFace **  _TheFace;
    
		CATMapOfIntToInt ** _FirstSrcVertexToDstVertexMap;

		CATMapOfPtrToInt _MeshPosition;
		CATMapOfPtrToPtr _InverseMap;
		CATMapOfPtrToPtr _InverseMap_Proj;
		CATMapOfPtrToPtr _InverseMap_Dup;

		CATMapOfPtrToPtr _MapMeshInit;
		CATMapOfPtrToPtr _MapMeshProj;
		CATMapOfPtrToPtr _MapPolyLineInit;
		CATMapOfPtrToPtr _MapPolyLineProj;

		int _Level;
		Struct_SimplifyMeshWithBoundaries *_MeshWithBoundaries;
};

//-----------------------------------------------------------------------

#endif
