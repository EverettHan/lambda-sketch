#ifdef TrivialCrit
#ifndef CreateMathApproxCriterion_h
#define CreateMathApproxCriterion_h


#include "MathApprox.h"
#include "CATMathApproxCritDef.h"

class CATMathApproxCriterion;
/*
	To Create "Trivial" Criterion 
	This criterion defined the Repartion of the segmentation
*/
 ExportedByMathApprox CATMathApproxCriterion* 
	 CreateTrivialCrit(const CATMathApproxCriterionRepartition iRepartion);


#endif
#endif


