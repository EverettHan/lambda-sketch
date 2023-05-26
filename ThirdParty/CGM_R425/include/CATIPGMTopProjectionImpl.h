#ifndef CATIPGMTopProjectionImpl_h_
#define CATIPGMTopProjectionImpl_h_

// COPYRIGHT DASSAULT SYSTEMES 2006

#include "CATIPGMTopProjection.h"
#include "CATCGMItfImplMacrosDefine.h"
#include "TopoOpeLightItf.h"

#define CATCGM_ITF_CONCRETE_CLASS           CATTopProjection
#define CATCGM_ITF_CONCRETE_METACLASS       CATTopProjection_MetaClass

#define CATCGM_ITF_CLASS                    CATIPGMTopProjection
#define CATCGM_ITF_METACLASS                CATIPGMTopProjection_MetaClass
#define CATCGM_ITF_CLASS_IID                IID_CATIPGMTopProjection

#define CATCGM_ITF_IMPL_CLASS               CATIPGMTopProjectionImpl
#define CATCGM_ITF_PARENT_ITF_METACLASS     CATIPGMTopOperatorImpl::CATIPGMTopOperator_MetaClass
#define CATCGM_ITF_EXPORTED_BY              ExportedByTopoOpeLightItf

#include "CATCGMItfImplDeclareBegin.h"
#include "CATIPGMTopProjectionImplDeclare.h"
#include "CATCGMItfImplDeclareEnd.h"

#endif
