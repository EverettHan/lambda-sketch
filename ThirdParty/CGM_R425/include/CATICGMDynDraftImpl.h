#ifndef CATICGMDynDraftImpl_h_
#define CATICGMDynDraftImpl_h_

// COPYRIGHT DASSAULT SYSTEMES 2006

#include "CATICGMDynDraft.h"
#include "CATCGMItfImplMacrosDefine.h"
#include "CATTopologicalOperators.h"

#define CATCGM_ITF_CONCRETE_CLASS           CATDynDraft
#define CATCGM_ITF_CONCRETE_METACLASS       CATDynDraft_MetaClass

#define CATCGM_ITF_CLASS                    CATICGMDynDraft
#define CATCGM_ITF_METACLASS                CATICGMDynDraft_MetaClass
#define CATCGM_ITF_CLASS_IID                IID_CATICGMDynDraft

#define CATCGM_ITF_IMPL_CLASS               CATICGMDynDraftImpl
#define CATCGM_ITF_PARENT_ITF_METACLASS     CATICGMDynOperatorImpl::CATICGMDynOperator_MetaClass
#define CATCGM_ITF_EXPORTED_BY              ExportedByCATTopologicalOperators

#include "CATCGMItfImplDeclareBegin.h"
#include "CATICGMDynDraftImplDeclare.h"
#include "CATCGMItfImplDeclareEnd.h"

#endif
