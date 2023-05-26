#ifndef CATIPGMDistanceBodyBodyImpl_h_
#define CATIPGMDistanceBodyBodyImpl_h_

// COPYRIGHT DASSAULT SYSTEMES 2014

#include "CATIPGMDistanceBodyBody.h"
#include "CATCGMItfImplMacrosDefine.h"
#include "CATTopologicalOperatorsLight.h"

#define CATCGM_ITF_CONCRETE_CLASS           CATDistanceBodyBody
#define CATCGM_ITF_CONCRETE_METACLASS       CATDistanceBodyBody_MetaClass

#define CATCGM_ITF_CLASS                    CATIPGMDistanceBodyBody
#define CATCGM_ITF_METACLASS                CATIPGMDistanceBodyBody_MetaClass
#define CATCGM_ITF_CLASS_IID                IID_CATIPGMDistanceBodyBody

#define CATCGM_ITF_IMPL_CLASS               CATIPGMDistanceBodyBodyImpl
#define CATCGM_ITF_PARENT_ITF_METACLASS     CATIPGMTopOperatorImpl::CATIPGMTopOperator_MetaClass
#define CATCGM_ITF_EXPORTED_BY              ExportedByCATTopologicalOperatorsLight

#include "CATCGMItfImplDeclareBegin.h"
#include "CATIPGMDistanceBodyBodyImplDeclare.h"
#include "CATCGMItfImplDeclareEnd.h"

#endif
