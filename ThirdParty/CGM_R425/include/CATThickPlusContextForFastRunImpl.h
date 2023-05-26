#ifndef CATIPGMImplThickPlusContextForFastRunImpl_h_
#define CATIPGMImplThickPlusContextForFastRunImpl_h_

// COPYRIGHT DASSAULT SYSTEMES 2010

#include "CATThickPlusContextForFastRun.h"
#include "CATThickPlusContextForFastRunExt.h"

#undef CATCGM_ITF_CONCRETE_CLASS
#undef CATCGM_ITF_CLASS
#undef CATCGM_ITF_IMPL_CLASS
#undef CATCGM_ITF_EXPORTED_BY

#define CATCGM_ITF_CONCRETE_CLASS           CATThickPlusContextForFastRunExt
#define CATCGM_ITF_CLASS                    CATThickPlusContextForFastRun
#define CATCGM_ITF_IMPL_CLASS               CATThickPlusContextForFastRunImpl
#define CATCGM_ITF_EXPORTED_BY              //ExportedByCATGMOperatorsInterfaces

#include "CATContextForFastRunImplDeclareBegin.h"
#include "CATThickPlusContextForFastRunImplDeclare.h"
#include "CATContextForFastRunImplDeclareEnd.h"

#endif
