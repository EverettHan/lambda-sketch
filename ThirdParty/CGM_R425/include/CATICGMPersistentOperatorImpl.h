#ifndef CATICGMPersistentOperatorImpl_h_
#define CATICGMPersistentOperatorImpl_h_

// COPYRIGHT DASSAULT SYSTEMES 2013

#include "CATICGMPersistentOperator.h"
#include "CATCGMItfImplMacrosDefine.h"
#include "CATTopologicalOperatorsLight.h"

#define CATCGM_ITF_CONCRETE_CLASS           CATPersistentOperator
#define CATCGM_ITF_CONCRETE_METACLASS       CATPersistentOperator_MetaClass

#define CATCGM_ITF_CLASS                    CATICGMPersistentOperator
#define CATCGM_ITF_METACLASS                CATICGMPersistentOperator_MetaClass
#define CATCGM_ITF_CLASS_IID                IID_CATICGMPersistentOperator

#define CATCGM_ITF_IMPL_CLASS               CATICGMPersistentOperatorImpl
#define CATCGM_ITF_PARENT_ITF_METACLASS     CATICGMAdvancedOperatorImpl::CATICGMAdvancedOperator_MetaClass
#define CATCGM_ITF_EXPORTED_BY              ExportedByCATTopologicalOperatorsLight

#include "CATCGMItfImplDeclareBegin.h"
#include "CATICGMPersistentOperatorImplDeclare.h"
#include "CATCGMItfImplDeclareEnd.h"

#endif
