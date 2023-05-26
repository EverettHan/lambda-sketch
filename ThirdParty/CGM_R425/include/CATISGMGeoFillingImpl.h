#ifndef CATISGMGeoFillingImpl_h_
#define CATISGMGeoFillingImpl_h_

// COPYRIGHT DASSAULT SYSTEMES 2006

#include "CATISGMGeoFilling.h"
#include "CATCGMItfImplMacrosDefine.h"

#define CATCGM_ITF_CONCRETE_CLASS           CATGeoFilling
#define CATCGM_ITF_CONCRETE_METACLASS       CATGeoFilling_MetaClass

#define CATCGM_ITF_CLASS                    CATISGMGeoFilling
#define CATCGM_ITF_METACLASS                CATISGMGeoFilling_MetaClass
#define CATCGM_ITF_CLASS_IID                IID_CATISGMGeoFilling

#define CATCGM_ITF_IMPL_CLASS               CATISGMGeoFillingImpl
#define CATCGM_ITF_PARENT_ITF_METACLASS     CATIPGMOperatorImpl::CATIPGMOperator_MetaClass
#define CATCGM_ITF_EXPORTED_BY

#include "CATCGMItfImplDeclareBegin.h"
#include "CATIPGMGeoFillingImplDeclare.h" // While CATISGMGeoFilling matches CATIPGMGeoFilling, it's useless to create new adapters.
#include "CATCGMItfImplDeclareEnd.h"

#endif
