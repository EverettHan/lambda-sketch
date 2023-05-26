#ifndef CATIPGMTopologicalFillImpl_h_
#define CATIPGMTopologicalFillImpl_h_

// COPYRIGHT DASSAULT SYSTEMES 2008

#include "CATIPGMTopologicalFillLight.h"
#include "CATCGMItfImplMacrosDefine.h"
#include "AdvTopoOpeLightItf.h"

#define CATCGM_ITF_CONCRETE_CLASS           CATTopologicalFill
#define CATCGM_ITF_CONCRETE_METACLASS       CATTopologicalFill_MetaClass

#define CATCGM_ITF_CLASS                    CATIPGMTopologicalFill
#define CATCGM_ITF_METACLASS                CATIPGMTopologicalFill_MetaClass
#define CATCGM_ITF_CLASS_IID                IID_CATIPGMTopologicalFill

#define CATCGM_ITF_IMPL_CLASS               CATIPGMTopologicalFillImpl
#define CATCGM_ITF_PARENT_ITF_METACLASS     CATIPGMTopOperatorImpl::CATIPGMTopOperator_MetaClass
#define CATCGM_ITF_EXPORTED_BY              ExportedByAdvTopoOpeLightItf

#include "CATCGMItfImplDeclareBegin.h"
#include "CATIPGMTopologicalFillImplDeclare.h"
#include "CATCGMItfImplDeclareEnd.h"

#endif
