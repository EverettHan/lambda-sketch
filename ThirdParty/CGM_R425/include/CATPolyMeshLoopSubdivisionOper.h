// COPYRIGHT Dassault Systemes 2009
//==============================================================================
//
// CATPolyMeshLoopsubdivisionOper.h
// Header definition of CATPolyMeshLoopsubdivisionOper
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
#ifndef CATPolyMeshLoopSubdivisionOper_H
#define CATPolyMeshLoopSubdivisionOper_H


 
#include "PolyBodyRemeshing.h"
#include "CATPolyBodyVOCOper.h"
#include "CATPolyBuildMeshOper.h"
#include "CATLISTV_CATMathPoint.h"
#include "CATLISTV_CATMathVector.h"
#include "stdlib.h"
#include <vector> 
class CATIPolyMesh;
class CATMeshStar;
class CATMathPoint2D;

class  ExportedByPolyBodyRemeshing CATPolyMeshLoopSubdivisionOper 
{

public:
	CATPolyMeshLoopSubdivisionOper( CATIPolyMesh* iPolyMesh,int iLevel) ;

	//------------------------------------------------------------------------------
	// Destructor
	//------------------------------------------------------------------------------
	virtual~CATPolyMeshLoopSubdivisionOper();


	void Set( CATIPolyMesh* iPolyMesh,int iLevel) ;

	


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


private:

	CATIPolyMesh *_PolyMesh; 

	int    _SubdivisionLevel;

	void  LoopSubdivide(CATIPolyMesh *PolyMesh,int Level);

	CATLONG32  LocateTriangle(CATLONG32 NbIt,CATLONG32 *It, CATLONG32 iTri);

	void  GetTriangleAdjacent(CATIPolyMesh *PolyMesh,CATLONG32 it ,int iB ,CATLONG32 &itAdj, int &iBAdj); 

		 


 
    private:
		 

		 
};

//-----------------------------------------------------------------------

#endif
