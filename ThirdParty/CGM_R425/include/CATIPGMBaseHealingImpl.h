#ifndef CATIPGMBaseHealingImpl_h_
#define CATIPGMBaseHealingImpl_h_

// COPYRIGHT DASSAULT SYSTEMES 2006

#include "CATIPGMBaseHealing.h"
#include "CATCGMItfImplMacrosDefine.h"
#include "CATTopologicalOperators.h"

#define CATCGM_ITF_CONCRETE_CLASS           CATBaseHealing
#define CATCGM_ITF_CONCRETE_METACLASS       CATBaseHealing_MetaClass

#define CATCGM_ITF_CLASS                    CATIPGMBaseHealing
#define CATCGM_ITF_METACLASS                CATIPGMBaseHealing_MetaClass
#define CATCGM_ITF_CLASS_IID                IID_CATIPGMBaseHealing

#define CATCGM_ITF_IMPL_CLASS               CATIPGMBaseHealingImpl
#define CATCGM_ITF_PARENT_ITF_METACLASS     CATIPGMTopOperatorImpl::CATIPGMTopOperator_MetaClass
#define CATCGM_ITF_EXPORTED_BY              ExportedByCATTopologicalOperators

#include "CATCGMItfImplDeclareBegin.h"
#include "CATIPGMBaseHealingImplDeclare.h"
#include "CATCGMItfImplDeclareEnd.h"

#endif
