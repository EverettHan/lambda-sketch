#ifndef CATIPGMGeoToTopOperatorImpl_h_
#define CATIPGMGeoToTopOperatorImpl_h_

// COPYRIGHT DASSAULT SYSTEMES 2006

#include "CATIPGMGeoToTopOperator.h"
#include "CATCGMItfImplMacrosDefine.h"
#include "TopoOpeLightItf.h"

#define CATCGM_ITF_CONCRETE_CLASS           CATGeoToTopOperator
#define CATCGM_ITF_CONCRETE_METACLASS       CATGeoToTopOperator_MetaClass

#define CATCGM_ITF_CLASS                    CATIPGMGeoToTopOperator
#define CATCGM_ITF_METACLASS                CATIPGMGeoToTopOperator_MetaClass
#define CATCGM_ITF_CLASS_IID                IID_CATIPGMGeoToTopOperator

#define CATCGM_ITF_IMPL_CLASS               CATIPGMGeoToTopOperatorImpl
#define CATCGM_ITF_PARENT_ITF_METACLASS     CATIPGMTopOperatorImpl::CATIPGMTopOperator_MetaClass
#define CATCGM_ITF_EXPORTED_BY              ExportedByTopoOpeLightItf

#include "CATCGMItfImplDeclareBegin.h"
#include "CATIPGMGeoToTopOperatorImplDeclare.h"
#include "CATCGMItfImplDeclareEnd.h"

#endif
