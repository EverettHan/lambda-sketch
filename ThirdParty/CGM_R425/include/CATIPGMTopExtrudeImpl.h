#ifndef CATIPGMTopExtrudeImpl_h_
#define CATIPGMTopExtrudeImpl_h_

// COPYRIGHT DASSAULT SYSTEMES 2006

#include "CATIPGMTopExtrude.h"
#include "CATCGMItfImplMacrosDefine.h"
#include "CATTopologicalOperators.h"

#define CATCGM_ITF_CONCRETE_CLASS           CATTopExtrude
#define CATCGM_ITF_CONCRETE_METACLASS       CATTopExtrude_MetaClass

#define CATCGM_ITF_CLASS                    CATIPGMTopExtrude
#define CATCGM_ITF_METACLASS                CATIPGMTopExtrude_MetaClass
#define CATCGM_ITF_CLASS_IID                IID_CATIPGMTopExtrude

#define CATCGM_ITF_IMPL_CLASS               CATIPGMTopExtrudeImpl
#define CATCGM_ITF_PARENT_ITF_METACLASS     CATIPGMTopOperatorImpl::CATIPGMTopOperator_MetaClass
#define CATCGM_ITF_EXPORTED_BY              ExportedByCATTopologicalOperators

#include "CATCGMItfImplDeclareBegin.h"
#include "CATIPGMTopExtrudeImplDeclare.h"
#include "CATCGMItfImplDeclareEnd.h"

#endif
