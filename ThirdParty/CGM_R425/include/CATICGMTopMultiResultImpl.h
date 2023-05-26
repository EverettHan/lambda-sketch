#ifndef CATICGMTopMultiResultImpl_h_
#define CATICGMTopMultiResultImpl_h_

// COPYRIGHT DASSAULT SYSTEMES 2006

#include "CATICGMTopMultiResult.h"
#include "CATCGMItfImplMacrosDefine.h"
#include "CATTopologicalOperatorsLight.h"

#define CATCGM_ITF_CONCRETE_CLASS           CATTopMultiResult
#define CATCGM_ITF_CONCRETE_METACLASS       CATTopMultiResult_MetaClass

#define CATCGM_ITF_CLASS                    CATICGMTopMultiResult
#define CATCGM_ITF_METACLASS                CATICGMTopMultiResult_MetaClass
#define CATCGM_ITF_CLASS_IID                IID_CATICGMTopMultiResult

#define CATCGM_ITF_IMPL_CLASS               CATICGMTopMultiResultImpl
#define CATCGM_ITF_PARENT_ITF_METACLASS     CATICGMTopOperatorImpl::CATICGMTopOperator_MetaClass
#define CATCGM_ITF_EXPORTED_BY              ExportedByCATTopologicalOperatorsLight

#include "CATCGMItfImplDeclareBegin.h"
#include "CATICGMTopMultiResultImplDeclare.h"
#include "CATCGMItfImplDeclareEnd.h"

#endif
