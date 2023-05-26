//====================================================================
// Copyright Dassault Systemes Provence 2005, all rights reserved 
//====================================================================
//
// 
//=============================================================================
// Mai,   2005 : ANR : Creation 
//=============================================================================
#ifndef CATGeomFeDeformForBaseMeshOptimization_H
#define CATGeomFeDeformForBaseMeshOptimization_H
//
#include "MathGeomFe.h"
#include "CATBoolean.h"
 
class CATGeomFe3Dof;
class CATGeomFeElem;


class CATGeomFeCCQuality;
class CATGeomFeSquaredPolygonArea;
class CATGeomFeSolver;
class CATGeomFeStringBar ;
class CATGeomFeDiagonalDistance ;

class CATMathPoint;
class CATMathVector ;

class ExportedByMathGeomFe CATGeomFeDeformForBaseMeshOptimization{
public:
	//
	CATGeomFeDeformForBaseMeshOptimization(int iNumberOfVertices, CATMathPoint *iVertices, 
							int iNbOfFixedVertices, 
							int iNbFaces, int iNbBorderFaces, int **iFacesIndices);
	  
	~CATGeomFeDeformForBaseMeshOptimization();

	// Les set ==========================================================================
	// ==================================================================================
	void SetScale(double iScale);
	  
	inline void SetBarStringStiffness(double iBarStringStiffnes){
		_K_BarStringStiffnes = iBarStringStiffnes; 
	}

	inline void SetOrthogonalCornerStiffness(double iOrthogonalCornerStiffness){
		_OrthogonalCornerStiffness = iOrthogonalCornerStiffness;
	}
	inline void SetOrthogonalDiagonalStiffness(double iOrthogonalDiagonalStiffness){
		_OrthogonalDiagonalStiffness = iOrthogonalDiagonalStiffness;
	}
	inline void SetDiagonalDistanceStiffness(double iDiagonalDistanceStiffness){
		_DiagonalDistanceStiffness = iDiagonalDistanceStiffness;
	}

	inline void SetSquaredPolygonArea(double iSquaredPolygonArea){
		_SquaredPolygonArea = iSquaredPolygonArea;
	}

	inline void SetStringBarMode(CATBoolean iMode){
		_OnlyStringBar = iMode ;
	}

	// Le Run ==========================================================================
	// ==================================================================================
	  
	int Run() ; 


	// Les get ==========================================================================
	// ==================================================================================
	inline void GetNewVertices(CATMathPoint*& oVertices) const {
		oVertices = _NewVertices ;
	}
	  
	double GetShift();
	double GetEnergyVariation();
	double GetEnergy();
//	double GetMaximumChordalError();
	int    EnergyIsLocallyConvex();
	
	double GetDetailedEnergy(double oDetails[5]);
		 
private: 

	void   DeleteData();
	int    OneRun() ;
	int    IterateRun() ;
	int    InitSolver() ;
	void   UpdateCoefs() ;
	double ComputeObjectiveLength() ;
	double CalcLength(CATGeomFeElem *iElem, int iNbSide, int inumEdge, double iLengthWithNormals) ;
	double CalcMaxSideLength(CATGeomFeElem *iElem, int iNbSide, int & onumEdge, const  int iBoundaryFlag, double iLengthWithNormals) ;
	int    ComputeNewVertices () ;


	CATGeomFeSolver *_Solver ;
	CATGeomFe3Dof * _Vrt3DOf ;
	CATGeomFeCCQuality ** _CCQualityElem ;
	CATGeomFeSquaredPolygonArea ** _Areas;
	CATGeomFeDiagonalDistance ** _DiagDist;
	CATGeomFeStringBar **_Bars[4];

	int _NumberOfVertices ;
	CATMathPoint  * _Vertices;
	int _NbOfFixedVertices;
	int _NbFaces;
	int _NbBorderFaces;
	int _NbQuads;
	int ** _FacesIndices ;

	CATMathPoint  * _NewVertices;

	double _K_BarStringStiffnes; 
	//
	double _Scale;
	double _InvScale;
	//
	double _OrthogonalCornerStiffness;
	double _OrthogonalDiagonalStiffness;
	double _DiagonalDistanceStiffness;
	 
	double _SquaredPolygonArea;

	double	_ObjectiveLength; 

	CATBoolean _OnlyStringBar ;

};

#endif
