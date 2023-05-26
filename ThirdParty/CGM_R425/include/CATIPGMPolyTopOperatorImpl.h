#ifndef CATIPGMPolyTopOperatorImpl_h_
#define CATIPGMPolyTopOperatorImpl_h_

// COPYRIGHT DASSAULT SYSTEMES 2017

#include "CATIPGMPolyTopOperator.h"
#include "CATCGMItfImplMacrosDefine.h"
#include "GMPolyOperItf.h"

#define CATCGM_ITF_CONCRETE_CLASS           CATGMPolyTopOperator
#define CATCGM_ITF_CONCRETE_METACLASS       CATGMPolyTopOperator_MetaClass

#define CATCGM_ITF_CLASS                    CATIPGMPolyTopOperator
#define CATCGM_ITF_METACLASS                CATIPGMPolyTopOperator_MetaClass
#define CATCGM_ITF_CLASS_IID                IID_CATIPGMPolyTopOperator

#define CATCGM_ITF_IMPL_CLASS               CATIPGMPolyTopOperatorImpl
#define CATCGM_ITF_PARENT_ITF_METACLASS     CATIPGMTopOperatorImpl::CATIPGMTopOperator_MetaClass
#define CATCGM_ITF_EXPORTED_BY              ExportedByGMPolyOperItf

#include "CATCGMItfImplDeclareBegin.h"
#include "CATIPGMPolyTopOperatorImplDeclare.h"
#include "CATCGMItfImplDeclareEnd.h"

#endif
