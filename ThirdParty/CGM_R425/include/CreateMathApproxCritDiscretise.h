#ifndef CreateMathApproxCritDiscretise_h
#define CreateMathApproxCritDiscretise_h


#include "CATSurfacicMathematics.h"
#include "CATTolerance.h"
class CATMathApproxCuttingByWeightDistribution;

class CATMathApproxCritDiscretise;
/*
	To Create Criterion 
*/
 ExportedByCATSurfacicMathematics CATMathApproxCritDiscretise*  CreateCritDiscretise(
                                 const CATTolerance & iTolerance,
																CATMathApproxCuttingByWeightDistribution * iUCut=0,
																CATMathApproxCuttingByWeightDistribution * iVCut=0);


#endif
