#ifndef CATICGMGeoToTopOperatorImpl_h_
#define CATICGMGeoToTopOperatorImpl_h_

// COPYRIGHT DASSAULT SYSTEMES 2006

#include "CATICGMGeoToTopOperator.h"
#include "CATCGMItfImplMacrosDefine.h"
#include "TopoOpeLightItf.h"

#define CATCGM_ITF_CONCRETE_CLASS           CATGeoToTopOperator
#define CATCGM_ITF_CONCRETE_METACLASS       CATGeoToTopOperator_MetaClass

#define CATCGM_ITF_CLASS                    CATICGMGeoToTopOperator
#define CATCGM_ITF_METACLASS                CATICGMGeoToTopOperator_MetaClass
#define CATCGM_ITF_CLASS_IID                IID_CATICGMGeoToTopOperator

#define CATCGM_ITF_IMPL_CLASS               CATICGMGeoToTopOperatorImpl
#define CATCGM_ITF_PARENT_ITF_METACLASS     CATICGMTopOperatorImpl::CATICGMTopOperator_MetaClass
#define CATCGM_ITF_EXPORTED_BY              ExportedByTopoOpeLightItf

#include "CATCGMItfImplDeclareBegin.h"
#include "CATICGMGeoToTopOperatorImplDeclare.h"
#include "CATCGMItfImplDeclareEnd.h"

#endif
