#ifndef CATIPGMTopCornerImpl_h_
#define CATIPGMTopCornerImpl_h_

// COPYRIGHT DASSAULT SYSTEMES 2006

#include "CATIPGMTopCorner.h"
#include "CATCGMItfImplMacrosDefine.h"
#include "CATTopologicalOperators.h"

#define CATCGM_ITF_CONCRETE_CLASS           CATTopCorner
#define CATCGM_ITF_CONCRETE_METACLASS       CATTopCorner_MetaClass

#define CATCGM_ITF_CLASS                    CATIPGMTopCorner
#define CATCGM_ITF_METACLASS                CATIPGMTopCorner_MetaClass
#define CATCGM_ITF_CLASS_IID                IID_CATIPGMTopCorner

#define CATCGM_ITF_IMPL_CLASS               CATIPGMTopCornerImpl
#define CATCGM_ITF_PARENT_ITF_METACLASS     CATIPGMTopTangentCurveOperatorImpl::CATIPGMTopTangentCurveOperator_MetaClass
#define CATCGM_ITF_EXPORTED_BY              ExportedByCATTopologicalOperators

#include "CATCGMItfImplDeclareBegin.h"
#include "CATIPGMTopCornerImplDeclare.h"
#include "CATCGMItfImplDeclareEnd.h"

#endif
