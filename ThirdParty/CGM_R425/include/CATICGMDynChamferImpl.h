#ifndef CATICGMDynChamferImpl_h_
#define CATICGMDynChamferImpl_h_

// COPYRIGHT DASSAULT SYSTEMES 2006

#include "CATICGMDynChamfer.h"
#include "CATCGMItfImplMacrosDefine.h"
#include "CATTopologicalOperators.h"

#define CATCGM_ITF_CONCRETE_CLASS           CATDynChamfer
#define CATCGM_ITF_CONCRETE_METACLASS       CATDynChamfer_MetaClass

#define CATCGM_ITF_CLASS                    CATICGMDynChamfer
#define CATCGM_ITF_METACLASS                CATICGMDynChamfer_MetaClass
#define CATCGM_ITF_CLASS_IID                IID_CATICGMDynChamfer

#define CATCGM_ITF_IMPL_CLASS               CATICGMDynChamferImpl
#define CATCGM_ITF_PARENT_ITF_METACLASS     CATICGMDynOperatorImpl::CATICGMDynOperator_MetaClass
#define CATCGM_ITF_EXPORTED_BY              ExportedByCATTopologicalOperators

#include "CATCGMItfImplDeclareBegin.h"
#include "CATICGMDynChamferImplDeclare.h"
#include "CATCGMItfImplDeclareEnd.h"

#endif
