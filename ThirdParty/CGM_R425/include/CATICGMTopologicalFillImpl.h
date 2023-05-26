#ifndef CATICGMTopologicalFillImpl_h_
#define CATICGMTopologicalFillImpl_h_

// COPYRIGHT DASSAULT SYSTEMES 2008

#include "CATICGMTopologicalFillLight.h"
#include "CATCGMItfImplMacrosDefine.h"
#include "AdvTopoOpeLightItf.h"

#define CATCGM_ITF_CONCRETE_CLASS           CATTopologicalFill
#define CATCGM_ITF_CONCRETE_METACLASS       CATTopologicalFill_MetaClass

#define CATCGM_ITF_CLASS                    CATICGMTopologicalFill
#define CATCGM_ITF_METACLASS                CATICGMTopologicalFill_MetaClass
#define CATCGM_ITF_CLASS_IID                IID_CATICGMTopologicalFill

#define CATCGM_ITF_IMPL_CLASS               CATICGMTopologicalFillImpl
#define CATCGM_ITF_PARENT_ITF_METACLASS     CATICGMTopOperatorImpl::CATICGMTopOperator_MetaClass
#define CATCGM_ITF_EXPORTED_BY              ExportedByAdvTopoOpeLightItf

#include "CATCGMItfImplDeclareBegin.h"
#include "CATICGMTopologicalFillImplDeclare.h"
#include "CATCGMItfImplDeclareEnd.h"

#endif
