#ifndef CATICkeConstraintForwards_h
#define CATICkeConstraintForwards_h
//////////////////////////////////////////////////////////////////////////
// Copyright (C) 1996 Dassault-Systemes 
//
// Cke Constraint Manager interface forward definitions
//
//////////////////////////////////////////////////////////////////////////


// failure status
enum FailureStatus { FailureApplyable, FailureNotApplyable, FailureIrrelevant, FailureCorrected }; 


// forwards declaration
class CATICkeExpression_var;
class CATICkeConstraintManipulator_var;
class CATICkeCompose_var;
class CATICkeDesignTable_var;


#include "CATBaseUnknown.h"
#include "CATCollec.h"

// listes
typedef class CATLISTV(CATBaseUnknown_var)* CATCkeListOfExpression;
typedef class CATLISTV(CATBaseUnknown_var)* CATCkeListOfPredicate;
//typedef class CATLISTV(CATBaseUnknown_var)* CATCkeListOfMagnitude;
typedef class CATLISTV(CATBaseUnknown_var)* CATCkeListOfFailure;
typedef class CATLISTV(CATBaseUnknown_var)* CATCkeListOfCompose;

#include "CATICkeExpressionForwards.h"


#endif

