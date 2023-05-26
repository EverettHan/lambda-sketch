#ifndef CATICGMTopSilhOperatorImpl_h_
#define CATICGMTopSilhOperatorImpl_h_

// COPYRIGHT DASSAULT SYSTEMES 2015

#include "CATICGMTopSilhOperator.h"
#include "CATCGMItfImplMacrosDefine.h"
#include "CATTopologicalOperators.h"

#define CATCGM_ITF_CONCRETE_CLASS           CATTopSilhOperator
#define CATCGM_ITF_CONCRETE_METACLASS       CATTopSilhOperator_MetaClass

#define CATCGM_ITF_CLASS                    CATICGMTopSilhOperator
#define CATCGM_ITF_METACLASS                CATICGMTopSilhOperator_MetaClass
#define CATCGM_ITF_CLASS_IID                IID_CATICGMTopSilhOperator

#define CATCGM_ITF_IMPL_CLASS               CATICGMTopSilhOperatorImpl
#define CATCGM_ITF_PARENT_ITF_METACLASS     CATICGMTopOperatorImpl::CATICGMTopOperator_MetaClass
#define CATCGM_ITF_EXPORTED_BY              ExportedByCATTopologicalOperators

#include "CATCGMItfImplDeclareBegin.h"
#include "CATICGMTopSilhOperatorImplDeclare.h"
#include "CATCGMItfImplDeclareEnd.h"

#endif
