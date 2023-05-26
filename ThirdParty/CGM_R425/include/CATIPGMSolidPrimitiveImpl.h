#ifndef CATIPGMSolidPrimitiveImpl_h_
#define CATIPGMSolidPrimitiveImpl_h_

// COPYRIGHT DASSAULT SYSTEMES 2006

#include "CATIPGMSolidPrimitive.h"
#include "CATCGMItfImplMacrosDefine.h"
#include "TopoOpeLightItf.h"

#define CATCGM_ITF_CONCRETE_CLASS           CATSolidPrimitive
#define CATCGM_ITF_CONCRETE_METACLASS       CATSolidPrimitive_MetaClass

#define CATCGM_ITF_CLASS                    CATIPGMSolidPrimitive
#define CATCGM_ITF_METACLASS                CATIPGMSolidPrimitive_MetaClass
#define CATCGM_ITF_CLASS_IID                IID_CATIPGMSolidPrimitive

#define CATCGM_ITF_IMPL_CLASS               CATIPGMSolidPrimitiveImpl
#define CATCGM_ITF_PARENT_ITF_METACLASS     CATIPGMTopOperatorImpl::CATIPGMTopOperator_MetaClass
#define CATCGM_ITF_EXPORTED_BY              ExportedByTopoOpeLightItf

#include "CATCGMItfImplDeclareBegin.h"
#include "CATIPGMSolidPrimitiveImplDeclare.h"
#include "CATCGMItfImplDeclareEnd.h"

#endif
