#ifndef CATICGMAdvancedOperatorImpl_h_
#define CATICGMAdvancedOperatorImpl_h_

// COPYRIGHT DASSAULT SYSTEMES 2018

#include "CATICGMAdvancedOperator.h"
#include "CATCGMItfImplMacrosDefine.h"
#include "CATTopologicalOperatorsLight.h"

#define CATCGM_ITF_CONCRETE_CLASS           CATAdvancedOperator
#define CATCGM_ITF_CONCRETE_METACLASS       CATAdvancedOperator_MetaClass

#define CATCGM_ITF_CLASS                    CATICGMAdvancedOperator
#define CATCGM_ITF_METACLASS                CATICGMAdvancedOperator_MetaClass
#define CATCGM_ITF_CLASS_IID                IID_CATICGMAdvancedOperator

#define CATCGM_ITF_IMPL_CLASS               CATICGMAdvancedOperatorImpl
#define CATCGM_ITF_PARENT_ITF_METACLASS     CATICGMDRepOperatorImpl::CATICGMDRepOperator_MetaClass
#define CATCGM_ITF_EXPORTED_BY              ExportedByCATTopologicalOperatorsLight

#include "CATCGMItfImplDeclareBegin.h"
#include "CATICGMAdvancedOperatorImplDeclare.h"
#include "CATCGMItfImplDeclareEnd.h"

#endif
