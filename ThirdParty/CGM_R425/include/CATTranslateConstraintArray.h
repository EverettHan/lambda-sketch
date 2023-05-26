#ifndef CATTranslateConstraintArray_h
#define CATTranslateConstraintArray_h


#include "MathPlate.h"
#include "CATMathPoint.h"


class CATIMathPlatePPCArray;
class CATIMathPlateLXYZCArray;
class CATIMathPlateLScalarCArray;
class CATMathFunctionXY;


// ==============================================
// ==  Translate arrays constraint for Plate   ==
// ==============================================

 ExportedByMathPlate CATIMathPlatePPCArray* 
	 TranslateConstraint(const CATMathFunctionXY * iFx,
											 const CATMathFunctionXY * iFy,
											 const CATMathFunctionXY * iFz,
											 CATMathPoint& iP,
											 CATIMathPlatePPCArray* iPPCA);


ExportedByMathPlate CATIMathPlateLXYZCArray* 
	 TranslateConstraint(const CATMathFunctionXY * iFx,
											 const CATMathFunctionXY * iFy,
											 const CATMathFunctionXY * iFz,
											 CATMathPoint& iP,
											 CATIMathPlateLXYZCArray* iLXYZ);

ExportedByMathPlate CATIMathPlateLScalarCArray* 
	 TranslateConstraint(const CATMathFunctionXY * iFx,
											 const CATMathFunctionXY * iFy,
											 const CATMathFunctionXY * iFz,
											 CATMathPoint& iP,
											 CATIMathPlateLScalarCArray* iLSCA);

#endif


