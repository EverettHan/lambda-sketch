#ifndef __FMUTILITES
#define __FMUTILITES

#if !defined(__JS0FM) && !defined(__PLMSidlComCORBASrv) && !defined(__PLMSidlComHTTPChunkedProcessor) \
    && !defined(__tErrNotifierEnv) && !defined(__JS0ERRORT1) && !defined(__JS0ERRORT2) && !defined(__tErrServer)\
    && !defined(__tException00) && !defined(__tException01) && !defined(__tException02) && !defined(__JS0ERROR)
#if defined(_WINDOWS_SOURCE)
#error Inclusion allowed only in authorized modules!
#endif
#endif

#include "CATDataType.h"
#include "CATErrorExit.h"
#include "CATSysErrContext.h"
#include "CATErrorMacros.h"
#include "JS0FM.h"

#if !defined(CATXH_VAR_SUPPRESS_WARN)
#if defined(_MSC_VER)
/** @nodoc Visual C++ options: /W4 /analyze */
#define CATXH_VAR_SUPPRESS_WARN(VarName, /*DeclareInstruction*/...)\
    __pragma(warning( push ))\
    /* 4456: cf. /W4 warning shadows local variable */\
    /* 6246: cf. /analyze warning shadows local variable */\
    __pragma(warning(disable : 4456 6246))\
    __VA_ARGS__\
    __pragma(warning( pop ))\
    /* Suppress warning unused variable */\
    (void)sizeof(VarName)
#else
/** @nodoc GCC/Clang options: -Wall -Wextra -Wshadow (neither -W nor -Wall enables -Wshadow) */
#define CATXH_VAR_SUPPRESS_WARN(VarName, /*DeclareInstruction*/...)\
    _Pragma("GCC diagnostic push")\
    /* Suppress warning shadows local variable */\
    _Pragma("GCC diagnostic ignored \"-Wshadow\"")\
    __VA_ARGS__\
    _Pragma("GCC diagnostic pop")\
    /* Suppress warning unused variable */\
    (void)sizeof(VarName)
#endif
#endif  // CATXH_VAR_SUPPRESS_WARN


#define CATNotifier_LastChanceJmp    // cf. CATRetryAfterAbend support (ODT tErrT1CATError)




// cf. CATSysErrDialogEngServices.h

#if !defined(CATNotifier_LastChanceJmp)

#define CATNotifierSetEnvDeclare()                      /*Nothing to do*/
#define CATNotifierSetEnvDeclareEx(StorageClassSpec)    /*Nothing to do*/
#define __CATNotifierJmpTry                             /*Nothing to do*/
#define __CATNotifierJmpCatch                           /*Nothing to do*/

#else   // CATNotifier_LastChanceJmp

#include <setjmp.h>

#if defined(sigsetjmp)
#define jmp_buf sigjmp_buf
#ifdef setjmp
#undef setjmp
#endif
#define setjmp(buf)  sigsetjmp(buf, /*savemask*/1)
#define longjmp siglongjmp
#endif  // sigsetjmp

#define CATNotifierSetEnvDeclare()                                        jmp_buf  NotifierEnvironment;
#define CATNotifierSetEnvDeclareEx(StorageClassSpec)    StorageClassSpec  jmp_buf  NotifierEnvironment;

#define __CATNotifierJmpTry   CATXH_VAR_SUPPRESS_WARN(_ctxt2_, CATXHContextNotifier _ctxt2_( NotifierEnvironment ););\
                              if ( setjmp( NotifierEnvironment ) == 0 ) 
                              
#define __CATNotifierJmpCatch else {\
                                __CATGetLastSystemError()->raise();\
                              }

ExportedByJS0ERROR CATError *__CATGetLastSystemError();
ExportedByJS0ERROR void CATSetNotifierEnv(jmp_buf *iEnv);

struct CATXHContextNotifier
{
public:
    CATXHContextNotifier(jmp_buf & iBuf) {
        CATSetNotifierEnv(&iBuf);
    }
    ~CATXHContextNotifier() {
        CATSetNotifierEnv(nullptr);
    }
};

#endif  // CATNotifier_LastChanceJmp




#define CATNotifierTry      {\
                                CATXH_VAR_SUPPRESS_WARN(_ctxt_, CATXHContextNotifierCxx _ctxt_;);\
                                try {\
                                    __CATNotifierJmpTry

// ++IK8: CATNotifierCatch expects a CATError object.
// It needs to be able to catch ALL uncaught CATError-derived exceptions
// Special case of CATSystemError exceptions: when a CATNotifierCatch block has been set in a parent stack frame, 
//   the runtime must ensure that CATSystemError exceptions winds all the way up the stack directly to this block. 
//   In other words, in such case, a CATSystemError exception must not be caught by a regular CATCatch/CATCatchOthers block.
// Implementation that meets these constraints:
#define CATNotifierCatch            __CATNotifierJmpCatch\
                                } catch(...) {                                                  \
                                    CATError *_ctxtErr_ = __CATNotifierCatchBlockPrologCxx();   \
                                    (void)(sizeof(_ctxtErr_));
                              

#define CATNotifierEndTry       }\
                            }

// ++IK8: DO NOT rely on a static variable anymore since we have the info in the context of the catch block
#define CATGetLastSystemError()     (_ctxtErr_)

// __CATNotifierCatchBlockPrologCxx MIGHT not return
ExportedByJS0ERROR CATError * __CATNotifierCatchBlockPrologCxx();
ExportedByJS0ERROR void CATSetNotifierEnvCxx(bool bContextInstalled);

struct CATXHContextNotifierCxx
{
public:
    CATXHContextNotifierCxx() {
        CATSetNotifierEnvCxx(true);
    }
    ~CATXHContextNotifierCxx() {
        CATSetNotifierEnvCxx(false);
    }
};



//-------------------------------------------------------------
// sgt fevrier 200
// On se prepare au bypass des CATCatch generique applicatifs
// ----------------------------------
ExportedByJS0FM void  CATNotifierAbort(CATError *err);
ExportedByJS0ERROR void CATDisconnectionReadSettings();


inline  int CATSysFMGetNextId()
{
  static int S_SubscriptionsId=0; // Partagee par Subscribe/AddFileDescriptor/AddTimeout
  S_SubscriptionsId++;
  // on ne veut jamais retourner zero
  if ( S_SubscriptionsId == 0 )S_SubscriptionsId++;
  return S_SubscriptionsId;
}


ExportedByJS0FM void InitAutoLogoff();


#endif


