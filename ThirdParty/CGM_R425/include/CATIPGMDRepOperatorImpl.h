#ifndef CATIPGMDRepOperatorImpl_h_
#define CATIPGMDRepOperatorImpl_h_

// COPYRIGHT DASSAULT SYSTEMES 2011

#include "CATIPGMDRepOperator.h"
#include "CATCGMItfImplMacrosDefine.h"
#include "CATTopologicalOperatorsLight.h"

#define CATCGM_ITF_CONCRETE_CLASS           CATDRepOperator
#define CATCGM_ITF_CONCRETE_METACLASS       CATDRepOperator_MetaClass

#define CATCGM_ITF_CLASS                    CATIPGMDRepOperator
#define CATCGM_ITF_METACLASS                CATIPGMDRepOperator_MetaClass
#define CATCGM_ITF_CLASS_IID                IID_CATIPGMDRepOperator

#define CATCGM_ITF_IMPL_CLASS               CATIPGMDRepOperatorImpl
#define CATCGM_ITF_PARENT_ITF_METACLASS     CATIPGMTopOperatorImpl::CATIPGMTopOperator_MetaClass
#define CATCGM_ITF_EXPORTED_BY              ExportedByCATTopologicalOperatorsLight

#include "CATCGMItfImplDeclareBegin.h"
#include "CATIPGMDRepOperatorImplDeclare.h"
#include "CATCGMItfImplDeclareEnd.h"

#endif
