//====================================================================
// Copyright Dassault Systemes Provence 2005, all rights reserved 
//====================================================================
//
// 
//=============================================================================
// Mai,   2005 : ANR : Creation 
//=============================================================================
#ifndef CATGeomFeDeformBaseMesh_H
#define CATGeomFeDeformBaseMesh_H
//
#include "MathGeomFe.h"
#include "CATBoolean.h"
 
class	CATGeomFe3Dof;
class CATGeomFeElem;

class CATGeomFeTrian; 
class CATGeomFeQuad; 
class CATGeomFeSolver; 
class CATGeomFeStringBar ;
class CATGeomFeDirectionalViscosity ;

class CATMathPoint;
class CATMathVector ; 

class ExportedByMathGeomFe CATGeomFeDeformBaseMesh 
{
public:
  //
  CATGeomFeDeformBaseMesh(int iNumberOfVertices, CATMathPoint *iVertices, CATMathVector* iNormals,
                          int iNbOfFixedVertices, int *iFixedVerticesIndices,
                          int iNbFaces, int **iFacesIndices);
  
  ~CATGeomFeDeformBaseMesh(); 

  // Les set ==========================================================================
  // ==================================================================================
  void SetScale(double iScale);
  
  void SetFixedVerticesButFreeNormals(int iNbOfVertices, int *iVerticesIndices) ;

  void SetSquarredTension(double iSquarredTension);
  void SetBarStringStiffness(double iBarStringStiffnes); 
  
  void SetK_NormalizedNormal(double iCoefUnitN);  
  void SetViscosity(double iViscosity, int iDirViscosityIsTangent = 0); 
  
  void SetTension(double iCoefTension);
  void SetPressure(double iPressure);
  void SetBendingStiffness(double iStiffness);
  void SetLambdaStiffness(double iLambdaStiffness); 
  
  void SetK_NormalizedShear(double iK_NormalizedShear);   
  void SetK_ConvexNormalizedNormal(double iK_ConvexNormalizedNormal);  
  
  void SetStringBarMode(CATBoolean iMode) ;

  // Le Run ==========================================================================
  // ==================================================================================
  
  int Run() ; 


  // Les get ==========================================================================
  // ==================================================================================
  void GetNewVertices(CATMathPoint*& oVertices, CATMathVector*& oNormals ) ; 
  
  double GetShift();
  double GetEnergyVariation();
  double GetEnergy();
  double GetMaximumChordalError();
  int    EnergyIsLocallyConvex();
	 
  CATBoolean DebugNormal(int iT, CATMathPoint *oPt, CATMathVector *oNormal)  ;

private: 

  int    OneRun() ;
  int    IterateRun() ;
  int    InitSolver() ;
  void   UpdateCoefs() ;
  double ComputeObjectiveLength() ;
  double CalcLength(CATGeomFeElem *iElem, int iNbSide, int inumEdge, double iLengthWithNormals) ;
  double CalcMaxSideLength(CATGeomFeElem *iElem, int iNbSide, int & onumEdge, const  int iBoundaryFlag, double iLengthWithNormals) ;
  int    ComputeNewVertex () ;


  CATGeomFeSolver *_Solver ;
  CATGeomFe3Dof * _Vrt3DOf ;
  CATGeomFe3Dof * _Nor3DOf ;
	CATGeomFeElem ** _FeElem ;


  CATGeomFeStringBar **_Bars[4];
  CATGeomFeDirectionalViscosity **_DirViscos[4];


  int _NumberOfVertices ;
  CATMathPoint  * _Vertices;
  CATMathVector * _Normals; 
  int _NbOfFixedVertices;
  int * _FixedVerticesIndices; 
  int _NbFaces;
  int ** _FacesIndices ;

  int _NbOfVerticesWithMixedConstr ;
  int *_VerticesWithMixedConstr ;

  CATMathPoint  * _NewVertices;
  CATMathVector * _NewNormals;

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
  //
  double _Scale;
  double _InvScale;
  //
 
  double	_ObjectiveLength; 

  CATBoolean _OnlyStringBar ;

};


#endif
