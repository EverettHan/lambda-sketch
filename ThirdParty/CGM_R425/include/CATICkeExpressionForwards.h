#ifndef CATICkeExpressionForwards_h
#define CATICkeExpressionForwards_h

//////////////////////////////////////////////////////////////////////////
// Copyright (C) 1996 Dassault-Systemes 
//
// Cke Expression Manager interface forward definitions
//
//////////////////////////////////////////////////////////////////////////

// forwards
class CATICkeFvar_var;
class CATICkeTerm_var;
class CATICkeRelationFactory_var;
class CATICkeExpression_var;
class CATICkeEvaluator_var;
class CATICkeFeature_var;

#include "CATICkeForwards.h"
#include "CATCkeListOfInterface.h"
#include "CATICkeRelationForwards.h"


typedef class CATLISTV(CATBaseUnknown_var)* CATCkeListOfFvar;
//typedef class CATLISTV_CATICkeTerm_var* CATCkeListOfTerm;
typedef class CATLISTV(CATBaseUnknown_var)* CATCkeListOfProc;

#define CATCkeListOfTerm CATListValCATICkeTerm_var* 



typedef class CATICkeTerm_var CATICkeProc_var;

// alias......
#define CATICkeMethod_var    CATICkeSignature_var
#define CATICkeProcedure_var CATICkeProc_var


#endif

