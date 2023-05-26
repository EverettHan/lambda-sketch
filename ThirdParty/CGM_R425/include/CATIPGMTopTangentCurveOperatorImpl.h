#ifndef CATIPGMTopTangentCurveOperatorImpl_h_
#define CATIPGMTopTangentCurveOperatorImpl_h_

// COPYRIGHT DASSAULT SYSTEMES 2006

#include "CATIPGMTopTangentCurveOperator.h"
#include "CATCGMItfImplMacrosDefine.h"
#include "CATTopologicalOperators.h"

#define CATCGM_ITF_CONCRETE_CLASS           CATTopTangentCurveOperator
#define CATCGM_ITF_CONCRETE_METACLASS       CATTopTangentCurveOperator_MetaClass

#define CATCGM_ITF_CLASS                    CATIPGMTopTangentCurveOperator
#define CATCGM_ITF_METACLASS                CATIPGMTopTangentCurveOperator_MetaClass
#define CATCGM_ITF_CLASS_IID                IID_CATIPGMTopTangentCurveOperator

#define CATCGM_ITF_IMPL_CLASS               CATIPGMTopTangentCurveOperatorImpl
#define CATCGM_ITF_PARENT_ITF_METACLASS     CATIPGMTopMultiResultImpl::CATIPGMTopMultiResult_MetaClass
#define CATCGM_ITF_EXPORTED_BY              ExportedByCATTopologicalOperators

#include "CATCGMItfImplDeclareBegin.h"
#include "CATIPGMTopTangentCurveOperatorImplDeclare.h"
#include "CATCGMItfImplDeclareEnd.h"

#endif
