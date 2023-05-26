#ifndef CATICGMDynOperatorImpl_h_
#define CATICGMDynOperatorImpl_h_

// COPYRIGHT DASSAULT SYSTEMES 2006

#include "CATICGMDynOperator.h"
#include "CATCGMItfImplMacrosDefine.h"
#include "CATTopologicalOperators.h"

#define CATCGM_ITF_CONCRETE_CLASS           CATDynOperator
#define CATCGM_ITF_CONCRETE_METACLASS       CATDynOperator_MetaClass

#define CATCGM_ITF_CLASS                    CATICGMDynOperator
#define CATCGM_ITF_METACLASS                CATICGMDynOperator_MetaClass
#define CATCGM_ITF_CLASS_IID                IID_CATICGMDynOperator

#define CATCGM_ITF_IMPL_CLASS               CATICGMDynOperatorImpl
#define CATCGM_ITF_PARENT_ITF_METACLASS     CATICGMTopOperatorImpl::CATICGMTopOperator_MetaClass
#define CATCGM_ITF_EXPORTED_BY				ExportedByCATTopologicalOperators

#include "CATCGMItfImplDeclareBegin.h"
#include "CATICGMDynOperatorImplDeclare.h"
#include "CATCGMItfImplDeclareEnd.h"

#endif
