//----------------------------------------------------------------------
// 
// Definition of criterion parameters for approximation
//
//----------------------------------------------------------------------
//

#ifndef _CATMathApproxCritDef_HeaderFile
#define _CATMathApproxCritDef_HeaderFile

//#include "MathApprox.h"
//
//
//
//ExportedByMathApprox
enum CATMathApproxCriterionType 
{ 
   CATMathApproxAbsolute,
   CATMathApproxRelative
};

//
//  This parameter is used for cutting management if the criterion is not satisfied
//
//ExportedByMathApprox
enum CATMathApproxCriterionRepartition 
{ 
     CATMathApproxRegular,
     CATMathApproxIncremental,
		 CATMathApproxMixed
};



#endif
