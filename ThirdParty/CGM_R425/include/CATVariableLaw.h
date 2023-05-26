/* -*-C++-*- */

#ifndef CATVariableLaw_H
#define CATVariableLaw_H

// COPYRIGHT DASSAULT SYSTEMES 1998

//-----------------------------------------------------------------------------
//
// CATVariableLaw 
// Definition of a VariableLaw class 
//
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Usage notes:
//
// The CATVariableLaw 
//
//   
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Aug 1999   Creation                         O. SCHOUTTETEN
// 06/11/08 NLD Ajout _Config, Ajout iConfig dans constructeur
//-----------------------------------------------------------------------------

//#include "Fillet.h"
#include "ParallelLight.h"


#include "ListPOfCATEdge.h"
#include "CATDataType.h"

class CATGeoFactory;
class CATEdge;
class CATCurve;
class CATLaw;
class CATSplineLaw;
class CATMathFunction;
class CATMathPolynomX;
class CATCrvParam;
class CATSoftwareConfiguration;
class ExportedByParallelLight CATVariableLaw
{
public:
	
	//---------------------------------------------------------------------------
	// Default Constructor
	//
	//---------------------------------------------------------------------------
	CATVariableLaw ();

	//	
	//---------------------------------------------------------------------------
	// Constructor
	//
	//---------------------------------------------------------------------------
	CATVariableLaw
		(CATGeoFactory * iFactory,
      CATSoftwareConfiguration* iConfig,
		CATLONG32 iNumberOfEdges,
		CATLISTP (CATEdge), CATLONG32 * iOrientations, CATLONG32 iClose,
		CATLONG32 iNumberOfImpositions,
		CATLONG32 * iEdgeIndex, double * iCurvilinearParam, double * iRadius,
		CATLONG32 * iSlopeDefined, double * iSlope);
	
	//---------------------------------------------------------------------------
	// Destructor
	//---------------------------------------------------------------------------
	virtual ~CATVariableLaw ();
	
	//---------------------------------------------------------------------------
	// Get One Mapping Law 
	//  
	//---------------------------------------------------------------------------
	virtual CATLaw * GetOneMappingLaw (CATLONG32 iCleanedCurveIndex);
        virtual void DontDeleteMappingLaw();
	
	//---------------------------------------------------------------------------
	// Get Radius Law
	//  
	//---------------------------------------------------------------------------
	virtual CATLaw * GetRadiusLaw  ();
	
protected:
	
	//---------------------------------------------------------------------------
	// Compute Partial Lengths
	//---------------------------------------------------------------------------
	void ComputePartialLengths ();
	
	//---------------------------------------------------------------------------
	// Compute Curve Mapping
	//---------------------------------------------------------------------------
	void ComputeCurveMapping ();

	//---------------------------------------------------------------------------
	// Compute Radius Law
	//---------------------------------------------------------------------------
	void ComputeRadiusLaw ();
	
protected:
	
	//---------------------------------------------------------------------------
	// Data
	//---------------------------------------------------------------------------
	// input
	CATGeoFactory * _Factory;
	CATLONG32 _NumberOfEdges;
	CATLISTP(CATEdge) _Edges;
	CATLONG32 * _Orientations;
	CATLONG32 _Close;
	CATLONG32 _NumberOfImpositions;
	CATLONG32 * _EdgeIndex;
	double * _CurvilinearParams;
	double * _Radii;
	CATLONG32 * _SlopeDefined;
	double * _Slope;
	// internal
	CATLaw ** _MappingLaw;
	CATSplineLaw * _SplineLaw;
	CATLaw * _RadiusLaw;
	
	double * _Lengths;
	double * _PartialLengths;
        CATLONG32     _DontDeleteMappingLaw;
   CATSoftwareConfiguration* _Config;
};
#endif
