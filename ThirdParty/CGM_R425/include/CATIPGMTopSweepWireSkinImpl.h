#ifndef CATIPGMTopSweepWireSkinImpl_h_
#define CATIPGMTopSweepWireSkinImpl_h_

// COPYRIGHT DASSAULT SYSTEMES 2006

#include "CATIPGMTopSweepWireSkin.h"
#include "CATCGMItfImplMacrosDefine.h"
#include "CATTopologicalOperators.h"

#define CATCGM_ITF_CONCRETE_CLASS           CATTopSweepWireSkin
#define CATCGM_ITF_CONCRETE_METACLASS       CATTopSweepWireSkin_MetaClass

#define CATCGM_ITF_CLASS                    CATIPGMTopSweepWireSkin
#define CATCGM_ITF_METACLASS                CATIPGMTopSweepWireSkin_MetaClass
#define CATCGM_ITF_CLASS_IID                IID_CATIPGMTopSweepWireSkin

#define CATCGM_ITF_IMPL_CLASS               CATIPGMTopSweepWireSkinImpl
#define CATCGM_ITF_PARENT_ITF_METACLASS     CATIPGMTopMultiResultImpl::CATIPGMTopMultiResult_MetaClass
#define CATCGM_ITF_EXPORTED_BY              ExportedByCATTopologicalOperators

#include "CATCGMItfImplDeclareBegin.h"
#include "CATIPGMTopSweepWireSkinImplDeclare.h"
#include "CATCGMItfImplDeclareEnd.h"

#endif
