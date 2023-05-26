#ifndef CATICGMDRepOperatorImpl_h_
#define CATICGMDRepOperatorImpl_h_

// COPYRIGHT DASSAULT SYSTEMES 2013

#include "CATICGMDRepOperator.h"
#include "CATCGMItfImplMacrosDefine.h"
#include "CATTopologicalOperatorsLight.h"

#define CATCGM_ITF_CONCRETE_CLASS           CATDRepOperator
#define CATCGM_ITF_CONCRETE_METACLASS       CATDRepOperator_MetaClass

#define CATCGM_ITF_CLASS                    CATICGMDRepOperator
#define CATCGM_ITF_METACLASS                CATICGMDRepOperator_MetaClass
#define CATCGM_ITF_CLASS_IID                IID_CATICGMDRepOperator

#define CATCGM_ITF_IMPL_CLASS               CATICGMDRepOperatorImpl
#define CATCGM_ITF_PARENT_ITF_METACLASS     CATICGMTopOperatorImpl::CATICGMTopOperator_MetaClass
#define CATCGM_ITF_EXPORTED_BY				ExportedByCATTopologicalOperatorsLight

#include "CATCGMItfImplDeclareBegin.h"
#include "CATICGMDRepOperatorImplDeclare.h"
#include "CATCGMItfImplDeclareEnd.h"

#endif
