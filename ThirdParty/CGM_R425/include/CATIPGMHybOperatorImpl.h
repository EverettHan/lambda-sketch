#ifndef CATIPGMHybOperatorImpl_h_
#define CATIPGMHybOperatorImpl_h_

// COPYRIGHT DASSAULT SYSTEMES 2006

#include "CATIACGMLevel.h" // automatic treatment EB_2014_04_16
#include "CATIPGMHybOperator.h"
#include "CATCGMItfImplMacrosDefine.h"
#include "TopoOpeLightItf.h"

#define CATCGM_ITF_CONCRETE_CLASS           CATHybOperator
#define CATCGM_ITF_CONCRETE_METACLASS       CATHybOperator_MetaClass

#define CATCGM_ITF_CLASS                    CATIPGMHybOperator
#define CATCGM_ITF_METACLASS                CATIPGMHybOperator_MetaClass
#define CATCGM_ITF_CLASS_IID                IID_CATIPGMHybOperator

#define CATCGM_ITF_IMPL_CLASS               CATIPGMHybOperatorImpl
#ifdef CATIACGMR214CAA
#define CATCGM_ITF_PARENT_ITF_METACLASS     CATIPGMTopMultiResultImpl::CATIPGMTopMultiResult_MetaClass
#else
#define CATCGM_ITF_PARENT_ITF_METACLASS     CATIPGMTopOperatorImpl::CATIPGMTopOperator_MetaClass
#endif
#define CATCGM_ITF_EXPORTED_BY              ExportedByTopoOpeLightItf

#include "CATCGMItfImplDeclareBegin.h"
#include "CATIPGMHybOperatorImplDeclare.h"
#include "CATCGMItfImplDeclareEnd.h"

#endif
