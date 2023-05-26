#ifndef CATIPGMTopSilhOperatorImpl_h_
#define CATIPGMTopSilhOperatorImpl_h_

// COPYRIGHT DASSAULT SYSTEMES 2015

#include "CATIPGMTopSilhOperator.h"
#include "CATCGMItfImplMacrosDefine.h"
#include "CATTopologicalOperators.h"

#define CATCGM_ITF_CONCRETE_CLASS           CATTopSilhOperator
#define CATCGM_ITF_CONCRETE_METACLASS       CATTopSilhOperator_MetaClass

#define CATCGM_ITF_CLASS                    CATIPGMTopSilhOperator
#define CATCGM_ITF_METACLASS                CATIPGMTopSilhOperator_MetaClass
#define CATCGM_ITF_CLASS_IID                IID_CATIPGMTopSilhOperator

#define CATCGM_ITF_IMPL_CLASS               CATIPGMTopSilhOperatorImpl
#define CATCGM_ITF_PARENT_ITF_METACLASS     CATIPGMTopOperatorImpl::CATIPGMTopOperator_MetaClass
#define CATCGM_ITF_EXPORTED_BY              ExportedByCATTopologicalOperators

#include "CATCGMItfImplDeclareBegin.h"
#include "CATIPGMTopSilhOperatorImplDeclare.h"
#include "CATCGMItfImplDeclareEnd.h"

#endif
