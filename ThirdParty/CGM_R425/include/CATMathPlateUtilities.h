// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2002
//



#ifndef _CATMathPlateUtilities_HeaderFile
#define _CATMathPlateUtilities_HeaderFile

#include "MathPlate.h"
#include "CATMathVector.h"

class ExportedByMathPlate CATMathPlateUtilities  {

public:

 // Methods PUBLIC
 // 
static int ComputeTolC1(const CATMathVector& DSu,const CATMathVector& DSv, 
												const CATMathVector& DTu,const CATMathVector& DTv,
												double* oTol , const double itolG1, const int iCodeLevel);

};





#endif
