/// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
//
// CATMathCutting :
// Abstract class for Cutting Choice in Approximations algorithms
// The method Value avoids to choice a Cutting point on a given interval
//=============================================================================
//
//
//=============================================================================
// Avr. 99    Creation                         J. Panciatici
//=============================================================================
#ifndef _CATMathApproxCutting_HeaderFile
#define _CATMathApproxCutting_HeaderFile

#include "CATMathDef.h"
#include "MathApprox.h"

class CATMathApproxFunctionX; 
class CATMathApproxFunctionXY;
class CATMathInterval;

class CATSoftwareConfiguration;

class ExportedByMathApprox CATMathApproxCutting  
{

 public:

 // Methods PUBLIC
 // 
virtual ~CATMathApproxCutting();

/*
**   Find a value of cut beetween iX and iY
**
*/
 virtual CATBoolean Value(const double iX,
  												const double iY,
													double &oCutValue) const = 0;

/*
**   Find iNumber values of cut beetween iX and iY
**   oCutValues have to be array of size iNumber.
*/
 virtual CATBoolean Values(const double iX,
  												const double iY,
													const int iNumber,
													double * oCutValues) const = 0;
 //@KTU20130822: Xscale Compliance :
 // To make comaptible with  the metric scale some hard tolerances used.
 // Set it to 1 by default if you don't know.
 virtual void SetMetricScale(const double iMetricScale)=0;

};
//-------------------------------------------------------------------
// Dichotomical Cutting : returns the middle point of the interval
//-------------------------------------------------------------------
/**
 * Do a new a CATApproxCutting operator from memory.
 */	
ExportedByMathApprox CATMathApproxCutting * CreateDichoCutting ();


/**
 * Removes a CATApproxCutting operator from memory.
 */	
//ExportedByMathApprox void RemoveDichoCutting( CATMathApproxCutting * iCut);

//-------------------------------------------------------------------
// Preferentiel  Cutting : returns if possible the point of the given
// list which is nearest the middle
//-------------------------------------------------------------------
/**
 * Do a new a CATApproxCutting operator from memory.
 */	
ExportedByMathApprox CATMathApproxCutting * CreatePrefCutting (CATSoftwareConfiguration * iConfig,
																															 const int iNbPnt, 
															                  const double* iCutPnts,
                                                const CATBoolean iCheckSymetry=FALSE);


/**
 * Removes a CATApproxCutting operator from memory.
 */	
///ExportedByMathApprox void RemovePrefCutting( CATMathApproxCutting * iCut);
//-------------------------------------------------------------------
// Preferentiel and recommanded Cutting 
//-------------------------------------------------------------------
/**
 * Do a new a CATApproxCutting operator from memory.
 */	
ExportedByMathApprox CATMathApproxCutting * CreatePrefAndRecCutting (
	          CATSoftwareConfiguration* iConfig,
						int iNbRecCut ,const double* iRecomendedCut,
						int iNbPrefCut, const double* iPrefferedCut,
						const double iWeight = 5,
						const CATMathInterval* iZone = 0,
						const double iSymRatio = 0.);


/**
 * Removes a CATApproxCutting operator from memory.
 */	
//ExportedByMathApprox void RemovePrefAndRecCutting( CATMathApproxCutting * iCut);


//-------------------------------------------------------------------
// Geometrical Cutting 
//-------------------------------------------------------------------
/**
 * Do a new a CATApproxCutting operator from memory.
 */	

// isens = 1 on souhaite decouper en U
// isens = 2 on souhaite decouper en V 
// isens = 3 on souhaite decouper dans les deux sens 

#endif
