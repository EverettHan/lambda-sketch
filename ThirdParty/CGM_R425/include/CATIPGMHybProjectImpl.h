#ifndef CATIPGMHybProjectImpl_h_
#define CATIPGMHybProjectImpl_h_

// COPYRIGHT DASSAULT SYSTEMES 2006

#include "CATIPGMHybProject.h"
#include "CATCGMItfImplMacrosDefine.h"
#include "TopoOpeLightItf.h"

#define CATCGM_ITF_CONCRETE_CLASS           CATHybProject
#define CATCGM_ITF_CONCRETE_METACLASS       CATHybProject_MetaClass

#define CATCGM_ITF_CLASS                    CATIPGMHybProject
#define CATCGM_ITF_METACLASS                CATIPGMHybProject_MetaClass
#define CATCGM_ITF_CLASS_IID                IID_CATIPGMHybProject

#define CATCGM_ITF_IMPL_CLASS               CATIPGMHybProjectImpl
#define CATCGM_ITF_PARENT_ITF_METACLASS     CATIPGMHybOperatorImpImpl::CATIPGMHybOperatorImp_MetaClass
#define CATCGM_ITF_EXPORTED_BY              ExportedByTopoOpeLightItf

#include "CATCGMItfImplDeclareBegin.h"
#include "CATIPGMHybProjectImplDeclare.h"
#include "CATCGMItfImplDeclareEnd.h"

#endif
