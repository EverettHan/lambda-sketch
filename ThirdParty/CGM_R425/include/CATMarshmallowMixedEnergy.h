// COPYRIGHT DASSAULT SYSTEMES 2002
//=============================================================================
//
// CATMarshmallowSolElem:
//  Class for Plate functions of two variables
//
//=============================================================================
//
// Usage notes:
//
//=============================================================================
// September 2002    Creation                           A. Lieutier
//=============================================================================

#ifndef CATMarshmallowMixedEnergy_H
#define CATMarshmallowMixedEnergy_H
#include "PlateFE.h"

class CATMathNurbsMultiForm;
//
class CATMathMarshExternSolElem;
class CATSoftwareConfiguration;

#define XScale_PMG16072013
//Passage d'une Tolerance : Tres douteux en fait....

class ExportedByPlateFE  CATMarshmallowMixedEnergy
{
public :
#ifdef XScale_PMG16072013
	static CATMathMarshExternSolElem *GetExternSolElem( CATSoftwareConfiguration* iConfig,
																											CATMathMarshExternSolElem::TypeEnergy TE,
		                                                  const double NormalizationCoefficient = 1,
																											CATMathNurbsMultiForm ** oNurbs = 0,
                                                      const CATTolerance* iTolerance = NULL,
                                                      const int iDegreeForApproximation = 6,
                                                      const double iRMax = 20.0);
#else
  static CATMathMarshExternSolElem *GetExternSolElem( CATSoftwareConfiguration* iConfig,
																											CATMathMarshExternSolElem::TypeEnergy TE,
		                                                  const double NormalizationCoefficient = 1,
																											CATMathNurbsMultiForm ** oNurbs = 0);
#endif

//	static CATMathMarshExternSolElem *GetMonomialExternSolElem(const int Order); // for test purpose
};

#endif 
