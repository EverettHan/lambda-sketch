#ifndef CATICGMDynFilletImpl_h_
#define CATICGMDynFilletImpl_h_

// COPYRIGHT DASSAULT SYSTEMES 2006

#include "CATICGMDynFillet.h"
#include "CATCGMItfImplMacrosDefine.h"
#include "CATTopologicalOperators.h"

#define CATCGM_ITF_CONCRETE_CLASS           CATDynFillet
#define CATCGM_ITF_CONCRETE_METACLASS       CATDynFillet_MetaClass

#define CATCGM_ITF_CLASS                    CATICGMDynFillet
#define CATCGM_ITF_METACLASS                CATICGMDynFillet_MetaClass
#define CATCGM_ITF_CLASS_IID                IID_CATICGMDynFillet

#define CATCGM_ITF_IMPL_CLASS               CATICGMDynFilletImpl
#define CATCGM_ITF_PARENT_ITF_METACLASS     CATICGMDynOperatorImpl::CATICGMDynOperator_MetaClass
#define CATCGM_ITF_EXPORTED_BY				ExportedByCATTopologicalOperators

#include "CATCGMItfImplDeclareBegin.h"
#include "CATICGMDynFilletImplDeclare.h"
#include "CATCGMItfImplDeclareEnd.h"

#endif
