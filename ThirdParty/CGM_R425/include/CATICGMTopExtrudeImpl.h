#ifndef CATICGMTopExtrudeImpl_h_
#define CATICGMTopExtrudeImpl_h_

// COPYRIGHT DASSAULT SYSTEMES 2006

#include "CATICGMTopExtrude.h"
#include "CATCGMItfImplMacrosDefine.h"
#include "CATTopologicalOperators.h"

#define CATCGM_ITF_CONCRETE_CLASS           CATTopExtrude
#define CATCGM_ITF_CONCRETE_METACLASS       CATTopExtrude_MetaClass

#define CATCGM_ITF_CLASS                    CATICGMTopExtrude
#define CATCGM_ITF_METACLASS                CATICGMTopExtrude_MetaClass
#define CATCGM_ITF_CLASS_IID                IID_CATICGMTopExtrude

#define CATCGM_ITF_IMPL_CLASS               CATICGMTopExtrudeImpl
#define CATCGM_ITF_PARENT_ITF_METACLASS     CATICGMTopOperatorImpl::CATICGMTopOperator_MetaClass
#define CATCGM_ITF_EXPORTED_BY              ExportedByCATTopologicalOperators

#include "CATCGMItfImplDeclareBegin.h"
#include "CATICGMTopExtrudeImplDeclare.h"
#include "CATCGMItfImplDeclareEnd.h"

#endif
