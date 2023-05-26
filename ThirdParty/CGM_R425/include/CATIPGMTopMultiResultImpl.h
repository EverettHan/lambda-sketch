#ifndef CATIPGMTopMultiResultImpl_h_
#define CATIPGMTopMultiResultImpl_h_

// COPYRIGHT DASSAULT SYSTEMES 2006

#include "CATIPGMTopMultiResult.h"
#include "CATCGMItfImplMacrosDefine.h"
#include "CATTopologicalOperatorsLight.h"

#define CATCGM_ITF_CONCRETE_CLASS           CATTopMultiResult
#define CATCGM_ITF_CONCRETE_METACLASS       CATTopMultiResult_MetaClass

#define CATCGM_ITF_CLASS                    CATIPGMTopMultiResult
#define CATCGM_ITF_METACLASS                CATIPGMTopMultiResult_MetaClass
#define CATCGM_ITF_CLASS_IID                IID_CATIPGMTopMultiResult

#define CATCGM_ITF_IMPL_CLASS               CATIPGMTopMultiResultImpl
#define CATCGM_ITF_PARENT_ITF_METACLASS     CATIPGMTopOperatorImpl::CATIPGMTopOperator_MetaClass
#define CATCGM_ITF_EXPORTED_BY              ExportedByCATTopologicalOperatorsLight

#include "CATCGMItfImplDeclareBegin.h"
#include "CATIPGMTopMultiResultImplDeclare.h"
#include "CATCGMItfImplDeclareEnd.h"

#endif
