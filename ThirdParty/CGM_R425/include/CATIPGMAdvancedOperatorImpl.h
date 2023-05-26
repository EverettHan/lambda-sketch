#ifndef CATIPGMAdvancedOperatorImpl_h_
#define CATIPGMAdvancedOperatorImpl_h_

// COPYRIGHT DASSAULT SYSTEMES 2018

#include "CATIPGMAdvancedOperator.h"
#include "CATCGMItfImplMacrosDefine.h"
#include "CATTopologicalOperatorsLight.h"

#define CATCGM_ITF_CONCRETE_CLASS           CATAdvancedOperator
#define CATCGM_ITF_CONCRETE_METACLASS       CATAdvancedOperator_MetaClass

#define CATCGM_ITF_CLASS                    CATIPGMAdvancedOperator
#define CATCGM_ITF_METACLASS                CATIPGMAdvancedOperator_MetaClass
#define CATCGM_ITF_CLASS_IID                IID_CATIPGMAdvancedOperator

#define CATCGM_ITF_IMPL_CLASS               CATIPGMAdvancedOperatorImpl
#define CATCGM_ITF_PARENT_ITF_METACLASS     CATIPGMDRepOperatorImpl::CATIPGMDRepOperator_MetaClass
#define CATCGM_ITF_EXPORTED_BY              ExportedByCATTopologicalOperatorsLight

#include "CATCGMItfImplDeclareBegin.h"
#include "CATIPGMAdvancedOperatorImplDeclare.h"
#include "CATCGMItfImplDeclareEnd.h"

#endif
