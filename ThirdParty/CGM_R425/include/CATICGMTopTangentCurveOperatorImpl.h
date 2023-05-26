#ifndef CATICGMTopTangentCurveOperatorImpl_h_
#define CATICGMTopTangentCurveOperatorImpl_h_

// COPYRIGHT DASSAULT SYSTEMES 2006

#include "CATICGMTopTangentCurveOperator.h"
#include "CATCGMItfImplMacrosDefine.h"
#include "CATTopologicalOperators.h"

#define CATCGM_ITF_CONCRETE_CLASS           CATTopTangentCurveOperator
#define CATCGM_ITF_CONCRETE_METACLASS       CATTopTangentCurveOperator_MetaClass

#define CATCGM_ITF_CLASS                    CATICGMTopTangentCurveOperator
#define CATCGM_ITF_METACLASS                CATICGMTopTangentCurveOperator_MetaClass
#define CATCGM_ITF_CLASS_IID                IID_CATICGMTopTangentCurveOperator

#define CATCGM_ITF_IMPL_CLASS               CATICGMTopTangentCurveOperatorImpl
#define CATCGM_ITF_PARENT_ITF_METACLASS     CATICGMTopMultiResultImpl::CATICGMTopMultiResult_MetaClass
#define CATCGM_ITF_EXPORTED_BY              ExportedByCATTopologicalOperators

#include "CATCGMItfImplDeclareBegin.h"
#include "CATICGMTopTangentCurveOperatorImplDeclare.h"
#include "CATCGMItfImplDeclareEnd.h"

#endif
