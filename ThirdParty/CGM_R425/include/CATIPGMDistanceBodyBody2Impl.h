#ifndef CATIPGMDistanceBodyBody2Impl_h_
#define CATIPGMDistanceBodyBody2Impl_h_

// COPYRIGHT DASSAULT SYSTEMES 2009

#include "CATIPGMDistanceBodyBody2Light.h"
#include "CATCGMItfImplMacrosDefine.h"
#include "CATTopologicalOperatorsLight.h"

#define CATCGM_ITF_CONCRETE_CLASS           CATDistanceBodyBody2
#define CATCGM_ITF_CONCRETE_METACLASS       CATDistanceBodyBody2_MetaClass

#define CATCGM_ITF_CLASS                    CATIPGMDistanceBodyBody2
#define CATCGM_ITF_METACLASS                CATIPGMDistanceBodyBody2_MetaClass
#define CATCGM_ITF_CLASS_IID                IID_CATIPGMDistanceBodyBody2

#define CATCGM_ITF_IMPL_CLASS               CATIPGMDistanceBodyBody2Impl
#define CATCGM_ITF_PARENT_ITF_METACLASS     CATIPGMVirtualImpl::CATIPGMVirtual_MetaClass
#define CATCGM_ITF_EXPORTED_BY              ExportedByCATTopologicalOperatorsLight

#include "CATCGMItfImplDeclareBegin.h"
#include "CATIPGMDistanceBodyBody2ImplDeclare.h"
#include "CATCGMItfImplDeclareEnd.h"

#endif
