#ifndef CATIPGMHybOperatorImpImpl_h_
#define CATIPGMHybOperatorImpImpl_h_

// COPYRIGHT DASSAULT SYSTEMES 2006

#include "CATIPGMHybOperatorImp.h"
#include "CATCGMItfImplMacrosDefine.h"
#include "TopoOpeLightItf.h"

#define CATCGM_ITF_CONCRETE_CLASS           CATHybOperatorImp
#define CATCGM_ITF_CONCRETE_METACLASS       CATHybOperatorImp_MetaClass

#define CATCGM_ITF_CLASS                    CATIPGMHybOperatorImp
#define CATCGM_ITF_METACLASS                CATIPGMHybOperatorImp_MetaClass
#define CATCGM_ITF_CLASS_IID                IID_CATIPGMHybOperatorImp

#define CATCGM_ITF_IMPL_CLASS               CATIPGMHybOperatorImpImpl
#define CATCGM_ITF_PARENT_ITF_METACLASS     CATIPGMHybOperatorImpl::CATIPGMHybOperator_MetaClass
#define CATCGM_ITF_EXPORTED_BY              ExportedByTopoOpeLightItf

#include "CATCGMItfImplDeclareBegin.h"
#include "CATIPGMHybOperatorImpImplDeclare.h"
#include "CATCGMItfImplDeclareEnd.h"

#endif
