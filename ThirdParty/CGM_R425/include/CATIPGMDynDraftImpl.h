#ifndef CATIPGMDynDraftImpl_h_
#define CATIPGMDynDraftImpl_h_

// COPYRIGHT DASSAULT SYSTEMES 2006

#include "CATIPGMDynDraft.h"
#include "CATCGMItfImplMacrosDefine.h"
#include "CATTopologicalOperators.h"

#define CATCGM_ITF_CONCRETE_CLASS           CATDynDraft
#define CATCGM_ITF_CONCRETE_METACLASS       CATDynDraft_MetaClass

#define CATCGM_ITF_CLASS                    CATIPGMDynDraft
#define CATCGM_ITF_METACLASS                CATIPGMDynDraft_MetaClass
#define CATCGM_ITF_CLASS_IID                IID_CATIPGMDynDraft

#define CATCGM_ITF_IMPL_CLASS               CATIPGMDynDraftImpl
#define CATCGM_ITF_PARENT_ITF_METACLASS     CATIPGMDynOperatorImpl::CATIPGMDynOperator_MetaClass
#define CATCGM_ITF_EXPORTED_BY              ExportedByCATTopologicalOperators

#include "CATCGMItfImplDeclareBegin.h"
#include "CATIPGMDynDraftImplDeclare.h"
#include "CATCGMItfImplDeclareEnd.h"

#endif
