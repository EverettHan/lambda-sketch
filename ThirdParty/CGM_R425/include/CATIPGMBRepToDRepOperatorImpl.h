#ifndef CATIPGMBRepToDRepOperatorImpl_h_
#define CATIPGMBRepToDRepOperatorImpl_h_

// COPYRIGHT DASSAULT SYSTEMES 2008

#include "CATIPGMBRepToDRepOperator.h"
#include "CATCGMItfImplMacrosDefine.h"
#include "CATTopologicalOperators.h"

#define CATCGM_ITF_CONCRETE_CLASS           CATBRepToDRepOperator
#define CATCGM_ITF_CONCRETE_METACLASS       CATBRepToDRepOperator_MetaClass

#define CATCGM_ITF_CLASS                    CATIPGMBRepToDRepOperator
#define CATCGM_ITF_METACLASS                CATIPGMBRepToDRepOperator_MetaClass
#define CATCGM_ITF_CLASS_IID                IID_CATIPGMBRepToDRepOperator

#define CATCGM_ITF_IMPL_CLASS               CATIPGMBRepToDRepOperatorImpl
#define CATCGM_ITF_PARENT_ITF_METACLASS     CATIPGMTopOperatorImpl::CATIPGMTopOperator_MetaClass
#define CATCGM_ITF_EXPORTED_BY              ExportedByCATTopologicalOperators

#include "CATCGMItfImplDeclareBegin.h"
#include "CATIPGMBRepToDRepOperatorImplDeclare.h"
#include "CATCGMItfImplDeclareEnd.h"

#endif
