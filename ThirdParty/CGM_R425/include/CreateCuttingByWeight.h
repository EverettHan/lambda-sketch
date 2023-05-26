#ifndef CreateCuttingByWeight_h
#define CreateCuttingByWeight_h

class CATGeoFactory; 
class CATBuildPlateDeform; 
#include "PlateFE.h"

// ***********************************
// method to build a  CATMathApproxCuttingByWeightDistribution
// ***********************************
 

ExportedByPlateFE  CATMathApproxCuttingByWeightDistribution *
CreateCuttingByWeight(const CATLONG32 NbDigits, const double a, const double b, const double ratiomax); 



#endif
