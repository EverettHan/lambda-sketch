/* -*-C++-*- */

#ifndef CATVariableParallelLaw_H
#define CATVariableParallelLaw_H

// COPYRIGHT DASSAULT SYSTEMES 1998

//-----------------------------------------------------------------------------
//
// CATVariableParallelLaw 
// Definition of a VariableParallelLaw class 
//
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Usage notes:
//
// The CATVariableParallelLaw is dedicated to Parallel Curve Operator
//
// - With the specification data of Parallel, this object creates and stores
// all the necessary data to variable Parallel computation.
//
// - This object is manipulated by the topological Parallel operator
// 
// - For Parallel Only, 
//   - M (M=number of curves in wire) 'Mapping Laws' are created.
//   . Each 'Mapping Law' contains the necessary data for quick evaluation
//   w (parameter on curve) --> S (curv abs % on wire)
//   . Each 'Mapping Law' is a law that contains degree 5 polynom  
//   - 1 'Radius Law' is created.
//   . The 'Radius Law' contains the necessary data for radius evaluation
//   S (curv abs % on wire) --> Rad
//   . The 'Radius Law' is a law that contains CATCompositeLaw
//   . This CATCompositeLaw is a spline law 
//   . No extrapolation is managed for the moment.
//  
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Aug 1999   Creation                         O. SCHOUTTETEN
// 06/11/08 NLD Ajout iConfig dans constructeur
//-----------------------------------------------------------------------------

#include "ParallelLight.h"
#include "CATVariableLaw.h"

#include "ListPOfCATEdge.h"

class CATGeoFactory;
class CATEdge;
class CATCurve;
class CATLaw;
class CATSplineLaw;
class CATMathFunction;
class CATMathPolynomX;
class CATCrvParam;

class ExportedByParallelLight CATVariableParallelLaw : public CATVariableLaw
{
public:
	
	//---------------------------------------------------------------------------
	// Default Constructor
	//
	//---------------------------------------------------------------------------
	CATVariableParallelLaw ();
	//---------------------------------------------------------------------------
	// Constructor dedicated to Variable Parallel
	//
	//---------------------------------------------------------------------------
	// iEdgeIndex           : CATLONG32 [iNumberOfImpositions]
	// iCurvilinearParam    : double [iNumberOfImpositions]
	//                        on Edge (0. at beginning of edge, 1. at end of edge)
	//   for example :
	//
	//        +1              -1              +1
	//   --*--------*-- ---*-----------*--- ------
	//    .1       .9     .8          .2 
	//
	//
	//
	//
	// iRadius              : double [iNumberOfImpositions]
	// iSlopeDefined        : CATLONG32 [iNumberOfImpositions]
	//                        (0: not imposed, 1: imposed)
	// iSlope               : double [iNumberOfImpositions]
	//                        this slope is given as dR/ds
	//                        (R: radius, s: CurvilinearParam on Edge)
	//                        the value is relevant only if iSlopeDefined = 1
  // iLevel               : niveau de code pour la loi. 0 par default, 1 pour
  //                        une loi plus precise => on veut migrer sur 1
	// 
	//---------------------------------------------------------------------------
	CATVariableParallelLaw
		(CATGeoFactory * iFactory,
      CATSoftwareConfiguration* iConfig,
		CATLONG32 iNumberOfEdges,
		CATLISTP (CATEdge), CATLONG32 * iOrientations, CATLONG32 iClose,
		CATLONG32 iNumberOfImpositions,
		CATLONG32 * iEdgeIndex, double * iCurvilinearParam, double * iRadius,
		CATLONG32 * iSlopeDefined, double * iSlope, CATLONG32 iLevel=0);
	
	//---------------------------------------------------------------------------
	// Destructor
	//---------------------------------------------------------------------------
	
	virtual ~CATVariableParallelLaw ();

//	void SetLevel(CATLONG32 iLevel);
	
protected:
	
	//---------------------------------------------------------------------------
	// Compute Curve Mapping
	//---------------------------------------------------------------------------
	void ComputeCurveMapping ();
	
private:
	
	//---------------------------------------------------------------------------
	// Data
	//---------------------------------------------------------------------------
	CATLONG32 _Level; // _Level = 0 => la loi est construite par CreateSplineLaw
							 // _Level = 1 => on construit la loi de facon exacte (param <=> image)
};
#endif
