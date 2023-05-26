#ifndef CATIPGMPersistentOperatorImpl_h_
#define CATIPGMPersistentOperatorImpl_h_

// COPYRIGHT DASSAULT SYSTEMES 2009

#include "CATIPGMPersistentOperator.h"
#include "CATCGMItfImplMacrosDefine.h"
#include "CATTopologicalOperatorsLight.h"

#define CATCGM_ITF_CONCRETE_CLASS           CATPersistentOperator
#define CATCGM_ITF_CONCRETE_METACLASS       CATPersistentOperator_MetaClass

#define CATCGM_ITF_CLASS                    CATIPGMPersistentOperator
#define CATCGM_ITF_METACLASS                CATIPGMPersistentOperator_MetaClass
#define CATCGM_ITF_CLASS_IID                IID_CATIPGMPersistentOperator

#define CATCGM_ITF_IMPL_CLASS               CATIPGMPersistentOperatorImpl
#define CATCGM_ITF_PARENT_ITF_METACLASS     CATIPGMAdvancedOperatorImpl::CATIPGMAdvancedOperator_MetaClass
#define CATCGM_ITF_EXPORTED_BY              ExportedByCATTopologicalOperatorsLight

#include "CATCGMItfImplDeclareBegin.h"
#include "CATIPGMPersistentOperatorImplDeclare.h"
#include "CATCGMItfImplDeclareEnd.h"

#endif
