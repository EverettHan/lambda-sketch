#ifndef CATIPGMDynFilletImpl_h_
#define CATIPGMDynFilletImpl_h_

// COPYRIGHT DASSAULT SYSTEMES 2006

#include "CATIPGMDynFillet.h"
#include "CATCGMItfImplMacrosDefine.h"
#include "CATTopologicalOperators.h"

#define CATCGM_ITF_CONCRETE_CLASS           CATDynFillet
#define CATCGM_ITF_CONCRETE_METACLASS       CATDynFillet_MetaClass

#define CATCGM_ITF_CLASS                    CATIPGMDynFillet
#define CATCGM_ITF_METACLASS                CATIPGMDynFillet_MetaClass
#define CATCGM_ITF_CLASS_IID                IID_CATIPGMDynFillet

#define CATCGM_ITF_IMPL_CLASS               CATIPGMDynFilletImpl
#define CATCGM_ITF_PARENT_ITF_METACLASS     CATIPGMDynOperatorImpl::CATIPGMDynOperator_MetaClass
#define CATCGM_ITF_EXPORTED_BY              ExportedByCATTopologicalOperators

#include "CATCGMItfImplDeclareBegin.h"
#include "CATIPGMDynFilletImplDeclare.h"
#include "CATCGMItfImplDeclareEnd.h"

#endif
