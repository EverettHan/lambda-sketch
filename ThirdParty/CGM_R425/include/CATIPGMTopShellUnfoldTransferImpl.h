#ifndef CATIPGMTopShellUnfoldTransferImpl_h_
#define CATIPGMTopShellUnfoldTransferImpl_h_

// COPYRIGHT DASSAULT SYSTEMES 2006

#include "CATIPGMTopShellUnfoldTransfer.h"
#include "CATCGMItfImplMacrosDefine.h"
#include "AdvTopoOpeItf.h"

#define CATCGM_ITF_CONCRETE_CLASS           CATTopShellUnfoldTransfer
#define CATCGM_ITF_CONCRETE_METACLASS       CATTopShellUnfoldTransfer_MetaClass

#define CATCGM_ITF_CLASS                    CATIPGMTopShellUnfoldTransfer
#define CATCGM_ITF_METACLASS                CATIPGMTopShellUnfoldTransfer_MetaClass
#define CATCGM_ITF_CLASS_IID                IID_CATIPGMTopShellUnfoldTransfer

#define CATCGM_ITF_IMPL_CLASS               CATIPGMTopShellUnfoldTransferImpl
#define CATCGM_ITF_PARENT_ITF_METACLASS     CATIPGMTopOperatorImpl::CATIPGMTopOperator_MetaClass
#define CATCGM_ITF_EXPORTED_BY              ExportedByAdvTopoOpeItf

#include "CATCGMItfImplDeclareBegin.h"
#include "CATIPGMTopShellUnfoldTransferImplDeclare.h"
#include "CATCGMItfImplDeclareEnd.h"

#endif
