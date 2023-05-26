#ifndef CATSysErrDialogEngServices_H
#define CATSysErrDialogEngServices_H
// COPYRIGHT DASSAULT SYSTEMES 2003
/** 
 * special exceptions services reserved for DialogEngine use
 */
#include "CATErrors.h"

#if !defined( __DI0STATE ) && !defined( __CATSysErrTstDiaEngEnv ) && !defined( __JS0ERROR ) && !defined( __CATDialogEngine )
#if defined(_WINDOWS_SOURCE)
#error Inclusion allowed only in authorized modules!
#endif
#endif



// cf. FMUtilities.h

#define CATSysDialogEngDeclare()                    /*Nothing to do*/
#define CATSysDialogEngDeclareEx(StorageClassSpec)  /*Nothing to do*/

#define CATSysDialogEngTry      {\
                                    CATXHContextDialogEngine _ctxt_;\
                                    try {

// ++IK8: CATNotifierCatch expects a CATError object.
// It needs to be able to catch ALL uncaught CATError-derived exceptions 
// But it MUST let pass "CATSystemErrorStdException" exceptions no matter what
// 20:05:27: catch(CATError *errobj) => catch(...) + rethrow if necessary in __CATDialogEngineCatchBlockPrologCxx
//           Performance is not a problem here since it is a last chance catch block
#define CATSysDialogEngCatch        } catch(...) {         \
                                      CATError *_ctxtErr_ = __CATDialogEngineCatchBlockPrologCxx(nullptr);\
                                      (void)(sizeof(_ctxtErr_));

#define CATSysDialogEngEndTry       }\
                                }

// ++IK8: DO NOT rely on a static variable anymore since we have the info in the context of the catch block
#define CATSysGetLastUncaughtError()     (_ctxtErr_)

ExportedByJS0ERROR CATError * __CATDialogEngineCatchBlockPrologCxx(CATError *errobj);
ExportedByJS0ERROR void CATSysSetDialogEngineEnvCxx(bool bContextInstalled);

struct CATXHContextDialogEngine
{
public:
    CATXHContextDialogEngine() {
        CATSysSetDialogEngineEnvCxx(true);
    }
    ~CATXHContextDialogEngine() {
        CATSysSetDialogEngineEnvCxx(false);
    }
};



#endif
