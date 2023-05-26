#include "CATOmyAsserts.h"
/*#ifndef CATPlmUtilsAccess_H
#define CATPlmUtilsAccess_H

// COPYRIGHT Dassault Systemes 2004

#include <stdio.h>
#include "CATSysMacros.h"
#include "CATAssert.h"
#include "CATBaseUnknown.h"
#include "CATBaseUnknown_WR.h"
#include "CATtraproto.h"
#include "CATErrorDef.h"

#undef snprintf
#ifdef _WINDOWS_SOURCE
#define  snprintf _snprintf
#else
#define  snprintf snprintf
#endif


inline void __AssertionFailed( const char * iTitle, const char * iFileName, const int iLn, const char * iMsg )
{
  char msg[350]; msg[349]=0x00;
  ::snprintf(msg, 349, ">> ASSERTION FAILED %.32s: %.80s [File: %.128s:%4d].<<\n", (iTitle!=NULL ? iTitle : ""),
    (iMsg!=NULL ? iMsg : ""), (iFileName!=NULL ? iFileName : ""), iLn);
  if (CATDevelopmentStage())
  {
    ::printf("%s", msg);
    ::CATSysLogAbend(msg);
  }
  else
    ::CATSysLogError(msg);
}

inline const void * __CheckVOIDEntry( const void * iPtr, const char * iFileName, const int iLn, const char * iMsg=NULL )
{
  if ( !iPtr )
    __AssertionFailed("ON POINTER ", iFileName, iLn, iMsg);
  return iPtr;
}

inline int __CheckINTEntry( const int & iVal, const int & iRefVal, const char * iFileName, const int iLn, const char * iMsg=NULL )
{
  int rc=1;
  if ( iVal==iRefVal )
  {
    char val[32];
    ::sprintf(val, "ON INT VALUE (VAL=%.12d)\0x00", iVal);
    __AssertionFailed(val, iFileName, iLn, iMsg);
    rc=0;
  }
  return rc;
}

inline int __CheckHREntry( const HRESULT & iHR, const char * iFileName, const int iLn, const char * iMsg=NULL )
{
  int rc=1;
  if ( FAILED(iHR) )
  {
    __AssertionFailed("Method FAILED", iFileName, iLn, iMsg);
    rc=0;
  }
  return rc;
}

inline int __CheckBOOLEntry( const int iBool, const char * iFileName, const int iLn, const char * iMsg=NULL )
{
  if ( !iBool)
    __AssertionFailed("BOOL is FALSE", iFileName, iLn, iMsg);
  return iBool;
}

inline CATBaseUnknown * CATPlmSafeStaticCastForWR( const CATBaseUnknown_WR & iObj, const char * iFileName, const int iLn )
{
  CATBaseUnknown * pResult = NULL;
  CATBaseUnknown * pWeakRef = iObj.GetComponent();
  if ( pWeakRef)
  {
    pResult = pWeakRef->GetImpl();
    pWeakRef->Release(); pWeakRef=NULL;
  }
  else
    __AssertionFailed("ON WEAK REF", iFileName, iLn, "Object no longer exist");
  return pResult;
}

inline HRESULT __LogError( const char * iTitle, const char * iFileName, const int iLn, const char * iMsg )
{
  __AssertionFailed( iTitle, iFileName, iLn, iMsg );
  return E_FAIL;
}

inline void __WarningFailure( const char * iTitle, const char * iFileName, const int iLn, const char * iMsg )
{
  char msg[288];
  ::sprintf(msg, ">> WARNING FAILURE %.32s: %.40s [File: %.128s:%4d].<<\n", (iTitle!=NULL ? iTitle : ""),
    (iMsg!=NULL ? iMsg : ""), (iFileName!=NULL ? iFileName : ""), iLn);
  ::printf("%s", msg);
  ::CATSysLogError(msg);
}

#define CAT_STATIC_CAST_WR(iType, iWR)  CAT_STATIC_CAST(iType, (::CATPlmSafeStaticCastForWR(iWR, __FILE__, __LINE__ )) )

#define CHK_AND_RET_HR( iItf ) if( !__CheckVOIDEntry(iItf, __FILE__, __LINE__) || !iItf ) return E_UNEXPECTED
#define CHK_AND_RET_VAL( iItf, iVal ) if( !__CheckVOIDEntry(iItf, __FILE__, __LINE__) || !iItf ) return iVal
#define CHK_AND_RET( iItf ) if( !__CheckVOIDEntry(iItf, __FILE__, __LINE__) || !iItf ) return
#define CHK_AND_CONT( iItf ) if( !__CheckVOIDEntry(iItf, __FILE__, __LINE__) || !iItf ) continue

#define CHK_AND_RET_HR_M( iItf, iMsg ) if( !__CheckVOIDEntry(iItf, __FILE__, __LINE__, iMsg) || !iItf ) return E_UNEXPECTED
#define CHK_AND_RET_VAL_M( iItf, iVal, iMsg ) if( !__CheckVOIDEntry(iItf, __FILE__, __LINE__, iMsg) || !iItf ) return iVal
#define CHK_AND_RET_M( iItf, iMsg ) if( !__CheckVOIDEntry(iItf, __FILE__, __LINE__, iMsg) || !iItf ) return
#define CHK_AND_CONT_M( iItf, iMsg ) if( !__CheckVOIDEntry(iItf, __FILE__, __LINE__, iMsg) || !iItf ) continue

#define CHK_VAR_AND_RET_HR( iHandler ) if( !__CheckVOIDEntry((CATBaseUnknown *) iHandler, __FILE__, __LINE__, "NULL handler") || !((CATBaseUnknown *) iHandler) ) return E_UNEXPECTED
#define CHK_VAR_AND_RET( iHandler ) if( !__CheckVOIDEntry((CATBaseUnknown *) iHandler, __FILE__, __LINE__, "NULL handler") || !((CATBaseUnknown *) iHandler) ) return
#define CHK_VAR_AND_RET_VAL( iHandler, iVal ) if( !__CheckVOIDEntry((CATBaseUnknown *) iHandler, __FILE__, __LINE__, "NULL handler") || !((CATBaseUnknown *) iHandler) ) return iVal
#define CHK_VAR_AND_CONT( iHandler ) if( !__CheckVOIDEntry((CATBaseUnknown *) iHandler, __FILE__, __LINE__, "NULL handler") || !((CATBaseUnknown *) iHandler) ) continue

#define CHK_INT_AND_RET_HR( iVal, iRef ) if( !__CheckINTEntry(iVal, iRef, __FILE__, __LINE__, "BAD Integer Value") ) return E_UNEXPECTED
#define CHK_INT_AND_RET( iVal, iRef ) if( !__CheckINTEntry(iVal, iRef, __FILE__, __LINE__, "BAD Integer Value") ) return
#define CHK_INT_AND_RET_VAL( iVal, iRef, iRC ) if( !__CheckINTEntry(iVal, iRef, __FILE__, __LINE__, "BAD Integer Value") ) return iRC
#define CHK_INT_AND_CONT ( iVal, iRef, iRC ) if( !__CheckINTEntry(iVal, iRef, __FILE__, __LINE__, "BAD Integer Value") ) continue

#define CHK_SUCCESS_AND_RET_HR( iHResult ) if( !__CheckHREntry(iHResult, __FILE__, __LINE__)) return E_UNEXPECTED
#define CHK_SUCCESS_AND_RET( iHResult ) if( !__CheckHREntry(iHResult, __FILE__, __LINE__)) return
#define CHK_SUCCESS_AND_RET_VAL( iHResult, iVal ) if( !__CheckHREntry(iHResult, __FILE__, __LINE__)) return iVal
#define CHK_SUCCESS_AND_CONT( iHResult ) if( !__CheckHREntry(iHResult, __FILE__, __LINE__)) continue

#define CHK_BOOL_AND_RET_HR( iBool) if( !__CheckBOOLEntry(iBool, __FILE__, __LINE__) ) return E_UNEXPECTED
#define CHK_BOOL_AND_RET_HR_M( iBool, iMsg ) if( !__CheckBOOLEntry(iBool, __FILE__, __LINE__, iMsg) ) return E_UNEXPECTED
#define CHK_BOOL_AND_RET_VAL( iBool, iVal ) if( !__CheckBOOLEntry(iBool, __FILE__, __LINE__) ) return iVal
#define CHK_BOOL_AND_RET( iBool ) if( !__CheckBOOLEntry(iBool, __FILE__, __LINE__) ) return
#define CHK_BOOL_AND_CONT( iBool ) if( !__CheckBOOLEntry(iBool, __FILE__, __LINE__) ) continue

#define LOG_ABEND( iMsg ) __AssertionFailed( NULL, __FILE__, __LINE__, iMsg )
#define ON_ERROR( iMsg ) __LogError( NULL, __FILE__, __LINE__, iMsg )
#define LOG_FAILURE( iMsg ) __WarningFailure( NULL, __FILE__, __LINE__, iMsg )

#endif*/
