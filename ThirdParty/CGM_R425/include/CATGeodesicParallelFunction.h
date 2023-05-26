// COPYRIGHT DASSAULT SYSTEMES  2000
//=============================================================================
//
// CATGeodesicParallelFunction:
// Function for implicit marching used for geodesic parallel 
// R-->R2
//
//=============================================================================
//
// Usage notes:
// Evaluation is based on the geodesic Point direction operator
//
//=============================================================================
// May. 2000   Creation                                   N. Barrier
//=============================================================================

#ifndef CATGeodesicParallelFunction_H  
#define CATGeodesicParallelFunction_H  

// TopologicalOperators

//#include "AdvTopoSketch.h"
#include "AdvTopoSketchLight.h"

#include "CATBoolean.h"
#include "CATTopDef.h"
//#include "CATCGMNewArray.h"
//#include "CATMathVectorialFunctionX.h"
#include "CATMathQuickDiscretizeFunctionX.h"
#include "CATListOfCATSurfaces.h"
#include "CATMathSetOfPointsND.h"
#include "CATListOfDouble.h"
#include "ListPOfCATEdge.h"
#include "CATListOfCATMathSetOfPointsND.h"

class CATGeoFactory;
class CATSoftwareConfiguration;
class CATBody;
class CATShell;
class CATFace;
class CATEdge;
class CATEdgeCurve;
class CATLaw;

class CATSketchCheminementCx2;
class CATSketchBaseCx2;
class CATStartPointCx2;
class CATEndPointCx2;
class CATSketchResultIteratorCx2;

class CATParallelConnectTool;

//-----------------------------------------------------------------------------
class ExportedByAdvTopoSketchLight CATGeodesicParallelFunction : public
CATMathQuickDiscretizeFunctionX
//                                                   CATMathVectorialFunctionX
{
public:
	
	CATGeodesicParallelFunction(CATGeoFactory *iFactory, 
	                            CATSoftwareConfiguration *iSoftwareConfiguration,
	                            CATBody *iBodyWire,
	                            CATShell *iSupportShell,
	                            CATFace *iSupportFace, CATFace *iEndFace,
	                            CATEdge *iOriginEdge,
	                            CATOrientation iOrientationEdgeInWire,
	                            CATLaw *iLaw, short iSide, CATParallelConnectTool *iConnectTool,
                              const CATTolerance &iTol=CATGetDefaultTolerance(),                              
                              CATListOfDouble * iListOfOffsets = NULL);
	
	CATCGMNewClassArrayDeclare;
	
	virtual ~CATGeodesicParallelFunction ();
	
	virtual void SetTolerance (double PtDirTol);

	//-----------------------------------------------------------------
	// Evaluation methods
	//-----------------------------------------------------------------
	virtual CATBoolean IsOption(const CATMathOption iOption) const;
	
	//-----------------------------------------------------------------
	// Evaluation methods
	//-----------------------------------------------------------------
	// Evaluators: iX is a point in R.
	//  . oFX = F(iX) is the image of iX by F. oFX is in RN and is already allocated. 
	//  . oDFX is the derivative of F at iX and is in RN and is already allocated. 
	//  . oD2FX is the second derivative of F at iX and is in RN and is already allocated. 
	//  . oTX is the normed tangent at iX and is in RN and is already allocated.
	
	virtual void Eval (const double  iX, double *oFX) const;
	virtual CATBoolean EvalPoint (const double iX, double *oFX,
	                              CATPointLocation *oPosition = NULL ) const;
	
  //For Auto-Parallel
  //Returns a set of MathPoints for a single param on InputCurve at specified offsets
  //along GeodesicCurve.
  CATBoolean EvaluatePoint (const double iX,  CATMathSetOfPointsND ** ioSolutionPts, CATMathSetOfPointsND ** ioGeometryData) const;
  CATMathSetOfPointsND* GetSolutionPoints();
  void SetEndEdgeInformation(double iParam, CATBoolean iSuccess);
  void GetEndEdgeInformation(CATLISTP(CATEdge) & iEdgeList, CATListOfDouble & iParamList);
  void SetSupportFacesList(CATListPV & iSupSurfList);
	virtual void EvalFirstDeriv (const double iX, double *oDFX) const; 
	virtual CATBoolean EvalDerivAtPoint (const double iX, double *oDFX) const;
	/*
	virtual void EvalSecondDeriv (const double	iX, double *oD2FX) const; 
	
	virtual void EvalDeriv (const double  iX, double *oDFX, double *oD2FX) const;
	virtual void EvalTangent (const double iX, double *oTX);
	*/
	
	// Step calculation : find step at point iXcur.
	virtual double EvalStep (const double iX, double iD, double iF );

// Specific to coupling curve validation for geodesic distance
  void CouplingCrvValidationCheckOn();

protected :
	virtual CATBoolean ContinueDichotomy(double iParam0, double iParam1);
	
private :
	
	CATEdge *_OriginEdge;
	CATEdgeCurve * _OriginCurve;
	CATGeoFactory * _ImplicitFactory;
	
	CATShell *_ShellSupport;
	short _Side;
	
	CATSketchCheminementCx2 *_SketchFunction;
	CATSketchBaseCx2 *_SketchBase;
	CATStartPointCx2 *_StartPoint;
	CATEndPointCx2 *_EndPoint;
	CATSketchResultIteratorCx2 *_Tree;

  CATParallelConnectTool *_Tool;
	
	double _Length;
	double _StartParam;
	double _Resolution;
  int _ValidationOn, _NoOfOffsets;
  CATMathSetOfPointsND * _SolPts;
  CATLISTP(CATEdge) _ListOfEndEdges;
  CATListOfDouble _ListOfParamsForIncompleteZone;  
  CATListPV _ListOfListOfSurfaces;
  CATLISTP(CATMathSetOfPointsND) _ListOfGeometryData;
	
};
#endif
