#ifndef CATICGMSolidPrimitiveImpl_h_
#define CATICGMSolidPrimitiveImpl_h_

// COPYRIGHT DASSAULT SYSTEMES 2006

#include "CATICGMSolidPrimitive.h"
#include "CATCGMItfImplMacrosDefine.h"
#include "TopoOpeLightItf.h"

#define CATCGM_ITF_CONCRETE_CLASS           CATSolidPrimitive
#define CATCGM_ITF_CONCRETE_METACLASS       CATSolidPrimitive_MetaClass

#define CATCGM_ITF_CLASS                    CATICGMSolidPrimitive
#define CATCGM_ITF_METACLASS                CATICGMSolidPrimitive_MetaClass
#define CATCGM_ITF_CLASS_IID                IID_CATICGMSolidPrimitive

#define CATCGM_ITF_IMPL_CLASS               CATICGMSolidPrimitiveImpl
#define CATCGM_ITF_PARENT_ITF_METACLASS     CATICGMTopOperatorImpl::CATICGMTopOperator_MetaClass
#define CATCGM_ITF_EXPORTED_BY              ExportedByTopoOpeLightItf

#include "CATCGMItfImplDeclareBegin.h"
#include "CATICGMSolidPrimitiveImplDeclare.h"
#include "CATCGMItfImplDeclareEnd.h"

#endif
