// COPYRIGHT Dassault Systemes 2009
//==============================================================================
//
// CATPolyMeshSubdivisionOper.h
// Header definition of CATPolyMeshSubdivisionOper
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
#ifndef CATPolyMeshSubdivisionOper_H
#define CATPolyMeshSubdivisionOper_H


 
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

class  ExportedByPolyBodyRemeshing CATPolyMeshSubdivisionOper 
{

public:
	CATPolyMeshSubdivisionOper( CATIPolyMesh* iPolyMesh,int iLevel) ;

	//------------------------------------------------------------------------------
	// Destructor
	//------------------------------------------------------------------------------
	virtual~CATPolyMeshSubdivisionOper();


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
