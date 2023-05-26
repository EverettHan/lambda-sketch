#ifndef CATIPGMDynOperatorImpl_h_
#define CATIPGMDynOperatorImpl_h_

// COPYRIGHT DASSAULT SYSTEMES 2006

#include "CATIPGMDynOperator.h"
#include "CATCGMItfImplMacrosDefine.h"
#include "CATTopologicalOperators.h"

#define CATCGM_ITF_CONCRETE_CLASS           CATDynOperator
#define CATCGM_ITF_CONCRETE_METACLASS       CATDynOperator_MetaClass

#define CATCGM_ITF_CLASS                    CATIPGMDynOperator
#define CATCGM_ITF_METACLASS                CATIPGMDynOperator_MetaClass
#define CATCGM_ITF_CLASS_IID                IID_CATIPGMDynOperator

#define CATCGM_ITF_IMPL_CLASS               CATIPGMDynOperatorImpl
#define CATCGM_ITF_PARENT_ITF_METACLASS     CATIPGMTopOperatorImpl::CATIPGMTopOperator_MetaClass
#define CATCGM_ITF_EXPORTED_BY              ExportedByCATTopologicalOperators

#include "CATCGMItfImplDeclareBegin.h"
#include "CATIPGMDynOperatorImplDeclare.h"
#include "CATCGMItfImplDeclareEnd.h"

#endif
