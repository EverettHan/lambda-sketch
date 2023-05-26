#ifndef CATIPGMDynChamferImpl_h_
#define CATIPGMDynChamferImpl_h_

// COPYRIGHT DASSAULT SYSTEMES 2006

#include "CATIPGMDynChamfer.h"
#include "CATCGMItfImplMacrosDefine.h"
#include "CATTopologicalOperators.h"

#define CATCGM_ITF_CONCRETE_CLASS           CATDynChamfer
#define CATCGM_ITF_CONCRETE_METACLASS       CATDynChamfer_MetaClass

#define CATCGM_ITF_CLASS                    CATIPGMDynChamfer
#define CATCGM_ITF_METACLASS                CATIPGMDynChamfer_MetaClass
#define CATCGM_ITF_CLASS_IID                IID_CATIPGMDynChamfer

#define CATCGM_ITF_IMPL_CLASS               CATIPGMDynChamferImpl
#define CATCGM_ITF_PARENT_ITF_METACLASS     CATIPGMDynOperatorImpl::CATIPGMDynOperator_MetaClass
#define CATCGM_ITF_EXPORTED_BY              ExportedByCATTopologicalOperators

#include "CATCGMItfImplDeclareBegin.h"
#include "CATIPGMDynChamferImplDeclare.h"
#include "CATCGMItfImplDeclareEnd.h"

#endif
