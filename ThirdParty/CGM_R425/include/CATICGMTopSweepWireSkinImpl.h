#ifndef CATICGMTopSweepWireSkinImpl_h_
#define CATICGMTopSweepWireSkinImpl_h_

// COPYRIGHT DASSAULT SYSTEMES 2006

#include "CATICGMTopSweepWireSkin.h"
#include "CATCGMItfImplMacrosDefine.h"
#include "CATTopologicalOperators.h"

#define CATCGM_ITF_CONCRETE_CLASS           CATTopSweepWireSkin
#define CATCGM_ITF_CONCRETE_METACLASS       CATTopSweepWireSkin_MetaClass

#define CATCGM_ITF_CLASS                    CATICGMTopSweepWireSkin
#define CATCGM_ITF_METACLASS                CATICGMTopSweepWireSkin_MetaClass
#define CATCGM_ITF_CLASS_IID                IID_CATICGMTopSweepWireSkin

#define CATCGM_ITF_IMPL_CLASS               CATICGMTopSweepWireSkinImpl
#define CATCGM_ITF_PARENT_ITF_METACLASS     CATICGMTopMultiResultImpl::CATICGMTopMultiResult_MetaClass
#define CATCGM_ITF_EXPORTED_BY              ExportedByCATTopologicalOperators

#include "CATCGMItfImplDeclareBegin.h"
#include "CATICGMTopSweepWireSkinImplDeclare.h"
#include "CATCGMItfImplDeclareEnd.h"

#endif
