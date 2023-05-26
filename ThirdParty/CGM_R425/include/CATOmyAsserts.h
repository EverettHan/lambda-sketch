#ifndef CATOmyAsserts_H
#define CATOmyAsserts_H

// COPYRIGHT Dassault Systemes 2008
/**
 * @level Protected 
 * @usage U1
 */
 
#include "CATSysMacros.h"
#include "CATAssert.h"
#include "CATBaseUnknown.h"
#include "CATBaseUnknown_WR.h"
#include "CATtraproto.h"
#include "CATErrorDef.h"
#include "CATUnicodeString.h"
#include "CATOMY.h"
#include "CATOmsXmlTraces.h"
#ifdef _WINDOWS_SOURCE
//4127 : conditional expression is constant
#define WHILE0 \
   __pragma(warning(suppress:4127)) \
    while(0) 
#else
#define WHILE0 while(0)
#endif

class ExportedByCATOMY CATOmyAssertsFlipFlop
{
  public:
    static void SetNoAsserts()
    {
        _asserts = 0;
    }
    static void SetAsserts()
    {
        _asserts = CATDevelopmentStage();
    }
    static inline int DoesAssert()
    {
        return _asserts;
    }
  private:
    static int _asserts;
};


class CATOmyAssertsUnswitch
{
  CATBoolean _prev;
public:
  CATOmyAssertsUnswitch():_prev(CATOmyAssertsFlipFlop::DoesAssert()==0?FALSE:TRUE)
  {
    CATOmyAssertsFlipFlop::SetNoAsserts();
  }
  static int DoesAssert()
  {
    return CATOmyAssertsFlipFlop::DoesAssert();
  }
  ~CATOmyAssertsUnswitch()
  {
    if(_prev)
      CATOmyAssertsFlipFlop::SetAsserts();
  }
};

/**
 * Ensemble de macros et fonctions de test et d'assertion utiles dans ce framework.
 */
ExportedByCATOMY void __OmyAssertionFailed( const char * iFileName, const int iLn, const CATUnicodeString& iMsg );
ExportedByCATOMY void __OmyAssertionFailed( const char * iFileName, const int iLn );
ExportedByCATOMY void __OmyWarningFailure( const char * iFileName, const int iLn, const CATUnicodeString& iMsg );
ExportedByCATOMY void __OmyWarningFailure( const char * iFileName, const int iLn );
ExportedByCATOMY void __OmyWarningMessage( const char * iFileName, const int iLn, const CATUnicodeString& iMsg );
ExportedByCATOMY void __OmyAssertOnSpecificReplay( const char * iFileName, const int iLn, const CATUnicodeString& iMsg );
ExportedByCATOMY CATBaseUnknown* CATPlmSafeStaticCastForWR( const CATBaseUnknown_WR & iObj, const char * iFileName, const int iLn );

#define CAT_STATIC_CAST_WR(iType, iWR)  CAT_STATIC_CAST(iType, (::CATPlmSafeStaticCastForWR(iWR, __FILE__, __LINE__ )) )

/*
* Note pour les paranos : le do{}while(0), qui oblige a mettre un ; apres ces macros est elimine une fois compile en mode release
*/

//=====================================================================
//#define CHK_M(             iItf, iMsg )        do{ if( !(iItf) ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg  ); } } WHILE0
#define CHK_ELSE_RET_M(     iItf, iMsg )        do{ if( !(iItf) ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg  ); return; } } WHILE0
#define CHK_ELSE_CONT_M(    iItf, iMsg )        if( !(iItf) ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg  ); continue; } else do; WHILE0
#define CHK_ELSE_RET_HR_M(  iItf, iMsg )        do{ if( !(iItf) ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg  ); return E_UNEXPECTED; } } WHILE0
#define CHK_ELSE_RET_NULL_M(iItf, iMsg )        do{ if( !(iItf) ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg  ); return 0; } } WHILE0
#define CHK_ELSE_RET_VAL_M( iItf, iVal, iMsg  ) do{ if( !(iItf) ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg  ); return iVal; } } WHILE0

#define CHK_M(             iItf, iMsg )        do{ if( !(iItf) ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg  ); } } WHILE0
#define CHK_AND_RET_M(     iItf, iMsg )        do{ if( !(iItf) ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg  ); return; } } WHILE0// Deprecated replaced by CHK_ELSE_RET_M
#define CHK_AND_CONT_M(    iItf, iMsg )        if( !(iItf) ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg  ); continue; } else do; WHILE0// Deprecated replaced by CHK_ELSE_CONT_M
#define CHK_AND_RET_HR_M(  iItf, iMsg )        do{ if( !(iItf) ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg  ); return E_UNEXPECTED; } } WHILE0// Deprecated replaced by CHK_ELSE_RET_HR_M
#define CHK_AND_RET_NULL_M(iItf, iMsg )        do{ if( !(iItf) ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg  ); return 0; } } WHILE0// Deprecated replaced by CHK_ELSE_RET_NULL_M
#define CHK_AND_RET_VAL_M( iItf, iVal, iMsg  ) do{ if( !(iItf) ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg  ); return iVal; } } WHILE0// Deprecated replaced by CHK_ELSE_RET_VAL_M

//#define CHK(             iItf )       do{ if( !(iItf) ) { __OmyAssertionFailed( __FILE__, __LINE__ ); } } WHILE0
#define CHK_ELSE_RET(     iItf )       do{ if( !(iItf) ) { __OmyAssertionFailed( __FILE__, __LINE__ ); return; } } WHILE0
#define CHK_ELSE_CONT(    iItf )       if( !(iItf) ) { __OmyAssertionFailed( __FILE__, __LINE__ ); continue; } else do; WHILE0
#define CHK_ELSE_RET_HR(  iItf )       do{ if( !(iItf) ) { __OmyAssertionFailed( __FILE__, __LINE__ ); return E_UNEXPECTED; } } WHILE0
#define CHK_ELSE_RET_NULL(iItf )       do{ if( !(iItf) ) { __OmyAssertionFailed( __FILE__, __LINE__ ); return 0; } } WHILE0
#define CHK_ELSE_RET_VAL( iItf, iVal ) do{ if( !(iItf) ) { __OmyAssertionFailed( __FILE__, __LINE__ ); return iVal; } } WHILE0
#define CHK_ELSE_SILENT_EXIT(iItf,iErrorCode )       do{ if( !(iItf) ) { __OmyAssertionFailed( __FILE__, __LINE__ ); CATExit(iErrorCode)return; } } WHILE0

#define CHK(             iItf )       do{ if( !(iItf) ) { __OmyAssertionFailed( __FILE__, __LINE__ ); } } WHILE0
#define CHK_AND_RET(     iItf )       do{ if( !(iItf) ) { __OmyAssertionFailed( __FILE__, __LINE__ ); return; } } WHILE0// Deprecated replaced by CHK_ELSE_RET
#define CHK_AND_CONT(    iItf )       if( !(iItf) ) { __OmyAssertionFailed( __FILE__, __LINE__ ); continue; } else do; WHILE0// Deprecated replaced by CHK_ELSE_CONT
#define CHK_AND_RET_HR(  iItf )       do{ if( !(iItf) ) { __OmyAssertionFailed( __FILE__, __LINE__ ); return E_UNEXPECTED; } } WHILE0// Deprecated replaced by CHK_ELSE_RET_HR
#define CHK_AND_RET_NULL(iItf )       do{ if( !(iItf) ) { __OmyAssertionFailed( __FILE__, __LINE__ ); return 0; } } WHILE0// Deprecated replaced by CHK_ELSE_RET_NULL
#define CHK_AND_RET_VAL( iItf, iVal ) do{ if( !(iItf) ) { __OmyAssertionFailed( __FILE__, __LINE__ ); return iVal; } } WHILE0// Deprecated replaced by CHK_ELSE_RET_VAL
#define CHK_AND_SILENT_EXIT(iItf,iErrorCode )       do{ if( !(iItf) ) { __OmyAssertionFailed( __FILE__, __LINE__ ); CATExit(iErrorCode)return; } } WHILE0// Deprecated replaced by CHK_ELSE_SILENT_EXIT

//=====================================================================
//#define CHK_VAR_M(             iHandler, iMsg )       do{ if( NULL_var == (CATBaseUnknown *) iHandler ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg  ); } } WHILE0
#define CHK_VAR_ELSE_RET_M(     iHandler, iMsg )       do{ if( NULL_var == (CATBaseUnknown *) iHandler ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg  ); return; } } WHILE0
#define CHK_VAR_ELSE_CONT_M(    iHandler, iMsg )       if( NULL_var == (CATBaseUnknown *) iHandler ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg  ); continue; } else do; WHILE0
#define CHK_VAR_ELSE_RET_HR_M(  iHandler, iMsg )       do{ if( NULL_var == (CATBaseUnknown *) iHandler ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg  ); return E_UNEXPECTED; } } WHILE0
#define CHK_VAR_ELSE_RET_NULL_M(iHandler, iMsg )       do{ if( NULL_var == (CATBaseUnknown *) iHandler ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg  ); return 0; } } WHILE0
#define CHK_VAR_ELSE_RET_VAL_M( iHandler, iVal, iMsg ) do{ if( NULL_var == (CATBaseUnknown *) iHandler ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg  ); return iVal; } } WHILE0

#define CHK_VAR_M(             iHandler, iMsg )       do{ if( NULL_var == (CATBaseUnknown *) iHandler ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg  ); } } WHILE0
#define CHK_VAR_AND_RET_M(     iHandler, iMsg )       do{ if( NULL_var == (CATBaseUnknown *) iHandler ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg  ); return; } } WHILE0// Deprecated replaced by CHK_VAR_ELSE_RET_M
#define CHK_VAR_AND_CONT_M(    iHandler, iMsg )       if( NULL_var == (CATBaseUnknown *) iHandler ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg  ); continue; } else do; WHILE0// Deprecated replaced by CHK_VAR_ELSE_CONT_M
#define CHK_VAR_AND_RET_HR_M(  iHandler, iMsg )       do{ if( NULL_var == (CATBaseUnknown *) iHandler ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg  ); return E_UNEXPECTED; } } WHILE0// Deprecated replaced by CHK_VAR_ELSE_RET_HR_M
#define CHK_VAR_AND_RET_NULL_M(iHandler, iMsg )       do{ if( NULL_var == (CATBaseUnknown *) iHandler ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg  ); return 0; } } WHILE0// Deprecated replaced by CHK_VAR_ELSE_RET_NULL_M
#define CHK_VAR_AND_RET_VAL_M( iHandler, iVal, iMsg ) do{ if( NULL_var == (CATBaseUnknown *) iHandler ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg  ); return iVal; } } WHILE0// Deprecated replaced by CHK_VAR_ELSE_RET_VAL_M

//#define CHK_VAR(             iHandler )       do{ if( NULL_var == (CATBaseUnknown *) iHandler ) { __OmyAssertionFailed( __FILE__, __LINE__ ); } } WHILE0
#define CHK_VAR_ELSE_RET(     iHandler )       do{ if( NULL_var == (CATBaseUnknown *) iHandler ) { __OmyAssertionFailed( __FILE__, __LINE__ ); return; } } WHILE0
#define CHK_VAR_ELSE_CONT(    iHandler )       if( NULL_var == (CATBaseUnknown *) iHandler ) { __OmyAssertionFailed( __FILE__, __LINE__ ); continue; } else do; WHILE0
#define CHK_VAR_ELSE_RET_HR(  iHandler )       do{ if( NULL_var == (CATBaseUnknown *) iHandler ) { __OmyAssertionFailed( __FILE__, __LINE__ ); return E_UNEXPECTED; } } WHILE0
#define CHK_VAR_ELSE_RET_NULL(iHandler )       do{ if( NULL_var == (CATBaseUnknown *) iHandler ) { __OmyAssertionFailed( __FILE__, __LINE__ ); return 0; } } WHILE0
#define CHK_VAR_ELSE_RET_VAL( iHandler, iVal ) do{ if( NULL_var == (CATBaseUnknown *) iHandler ) { __OmyAssertionFailed( __FILE__, __LINE__ ); return iVal; } } WHILE0

#define CHK_VAR(             iHandler )       do{ if( NULL_var == (CATBaseUnknown *) iHandler ) { __OmyAssertionFailed( __FILE__, __LINE__ ); } } WHILE0
#define CHK_VAR_AND_RET(     iHandler )       do{ if( NULL_var == (CATBaseUnknown *) iHandler ) { __OmyAssertionFailed( __FILE__, __LINE__ ); return; } } WHILE0// Deprecated replaced by CHK_VAR_ELSE_RET
#define CHK_VAR_AND_CONT(    iHandler )       if( NULL_var == (CATBaseUnknown *) iHandler ) { __OmyAssertionFailed( __FILE__, __LINE__ ); continue; } else do; WHILE0// Deprecated replaced by CHK_VAR_ELSE_CONT
#define CHK_VAR_AND_RET_HR(  iHandler )       do{ if( NULL_var == (CATBaseUnknown *) iHandler ) { __OmyAssertionFailed( __FILE__, __LINE__ ); return E_UNEXPECTED; } } WHILE0// Deprecated replaced by CHK_VAR_ELSE_RET_HR
#define CHK_VAR_AND_RET_NULL(iHandler )       do{ if( NULL_var == (CATBaseUnknown *) iHandler ) { __OmyAssertionFailed( __FILE__, __LINE__ ); return 0; } } WHILE0// Deprecated replaced by CHK_VAR_ELSE_RET_NULL
#define CHK_VAR_AND_RET_VAL( iHandler, iVal ) do{ if( NULL_var == (CATBaseUnknown *) iHandler ) { __OmyAssertionFailed( __FILE__, __LINE__ ); return iVal; } } WHILE0// Deprecated replaced by CHK_VAR_ELSE_RET_VAL

//=====================================================================
//#define CHK_INT_M(             iVal, iRef, iMsg )      do{ if( iRef == iVal ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg ); } } WHILE0
#define CHK_INT_ELSE_RET_M(     iVal, iRef, iMsg )      do{ if( iRef == iVal ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg ); return; } } WHILE0
#define CHK_INT_ELSE_CONT_M(    iVal, iRef, iMsg )      if( iRef == iVal ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg ); continue; } else do; WHILE0
#define CHK_INT_ELSE_RET_HR_M(  iVal, iRef, iMsg )      do{ if( iRef == iVal ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg ); return E_UNEXPECTED; } } WHILE0
#define CHK_INT_ELSE_RET_NULL_M(iVal, iRef, iMsg )      do{ if( iRef == iVal ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg ); return 0; } } WHILE0
#define CHK_INT_ELSE_RET_VAL_M( iVal, iRef, iRC, iMsg ) do{ if( iRef == iVal ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg ); return iRC; } } WHILE0

#define CHK_INT_M(             iVal, iRef, iMsg )      do{ if( iRef == iVal ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg ); } } WHILE0
#define CHK_INT_AND_RET_M(     iVal, iRef, iMsg )      do{ if( iRef == iVal ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg ); return; } } WHILE0// Deprecated replaced by CHK_INT_ELSE_RET_M
#define CHK_INT_AND_CONT_M(    iVal, iRef, iMsg )      if( iRef == iVal ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg ); continue; } else do; WHILE0// Deprecated replaced by CHK_INT_ELSE_CONT_M
#define CHK_INT_AND_RET_HR_M(  iVal, iRef, iMsg )      do{ if( iRef == iVal ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg ); return E_UNEXPECTED; } } WHILE0// Deprecated replaced by CHK_INT_ELSE_RET_HR_M
#define CHK_INT_AND_RET_NULL_M(iVal, iRef, iMsg )      do{ if( iRef == iVal ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg ); return 0; } } WHILE0// Deprecated replaced by CHK_INT_ELSE_RET_NULL_M
#define CHK_INT_AND_RET_VAL_M( iVal, iRef, iRC, iMsg ) do{ if( iRef == iVal ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg ); return iRC; } } WHILE0// Deprecated replaced by CHK_INT_ELSE_RET_VAL_M

//#define CHK_INT(             iVal, iRef )      do{ if( iRef == iVal ) { __OmyAssertionFailed( __FILE__, __LINE__ ); } } WHILE0
#define CHK_INT_ELSE_RET(     iVal, iRef )      do{ if( iRef == iVal ) { __OmyAssertionFailed( __FILE__, __LINE__ ); return; } } WHILE0
#define CHK_INT_ELSE_CONT(    iVal, iRef )      if( iRef == iVal ) { __OmyAssertionFailed( __FILE__, __LINE__ ); continue; } else do; WHILE0
#define CHK_INT_ELSE_RET_HR(  iVal, iRef )      do{ if( iRef == iVal ) { __OmyAssertionFailed( __FILE__, __LINE__ ); return E_UNEXPECTED; } } WHILE0
#define CHK_INT_ELSE_RET_NULL(iVal, iRef )      do{ if( iRef == iVal ) { __OmyAssertionFailed( __FILE__, __LINE__ ); return 0; } } WHILE0
#define CHK_INT_ELSE_RET_VAL( iVal, iRef, iRC ) do{ if( iRef == iVal ) { __OmyAssertionFailed( __FILE__, __LINE__ ); return iRC; } } WHILE0

#define CHK_INT(             iVal, iRef )      do{ if( iRef == iVal ) { __OmyAssertionFailed( __FILE__, __LINE__ ); } } WHILE0
#define CHK_INT_AND_RET(     iVal, iRef )      do{ if( iRef == iVal ) { __OmyAssertionFailed( __FILE__, __LINE__ ); return; } } WHILE0// Deprecated replaced by CHK_INT_ELSE_RET
#define CHK_INT_AND_CONT(    iVal, iRef )      if( iRef == iVal ) { __OmyAssertionFailed( __FILE__, __LINE__ ); continue; } else do; WHILE0// Deprecated replaced by CHK_INT_ELSE_CONT
#define CHK_INT_AND_RET_HR(  iVal, iRef )      do{ if( iRef == iVal ) { __OmyAssertionFailed( __FILE__, __LINE__ ); return E_UNEXPECTED; } } WHILE0// Deprecated replaced by CHK_INT_ELSE_RET_HR
#define CHK_INT_AND_RET_NULL(iVal, iRef )      do{ if( iRef == iVal ) { __OmyAssertionFailed( __FILE__, __LINE__ ); return 0; } } WHILE0// Deprecated replaced by CHK_INT_ELSE_RET_NULL
#define CHK_INT_AND_RET_VAL( iVal, iRef, iRC ) do{ if( iRef == iVal ) { __OmyAssertionFailed( __FILE__, __LINE__ ); return iRC; } } WHILE0// Deprecated replaced by CHK_INT_ELSE_RET_VAL

//=====================================================================
//#define CHK_SUCCESS_M(             iHRDef, iMsg )       do{ if( FAILED(iHRDef) ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg); } } WHILE0
#define CHK_SUCCESS_ELSE_RET_M(     iHRDef, iMsg )       do{ if( FAILED(iHRDef) ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg); return; } } WHILE0
#define CHK_SUCCESS_ELSE_CONT_M(    iHRDef, iMsg )       if( FAILED(iHRDef) ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg); continue; } else do; WHILE0
#define CHK_SUCCESS_ELSE_RET_HR_M(  iHRDef, iMsg )       do{ HRESULT localHrForMacro = iHRDef; if( FAILED(localHrForMacro) ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg); return localHrForMacro; } } WHILE0
#define CHK_SUCCESS_ELSE_RET_NULL_M(iHRDef, iVal )       do{ if( FAILED(iHRDef) ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg); return 0; } } WHILE0
#define CHK_SUCCESS_ELSE_RET_VAL_M( iHRDef, iVal, iMsg ) do{ if( FAILED(iHRDef) ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg); return iVal; } } WHILE0

#define CHK_SUCCESS_M(             iHRDef, iMsg )       do{ if( FAILED(iHRDef) ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg); } } WHILE0
#define CHK_SUCCESS_AND_RET_M(     iHRDef, iMsg )       do{ if( FAILED(iHRDef) ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg); return; } } WHILE0// Deprecated replaced by CHK_SUCCESS_ELSE_RET_M
#define CHK_SUCCESS_AND_CONT_M(    iHRDef, iMsg )       if( FAILED(iHRDef) ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg); continue; } else do; WHILE0// Deprecated replaced by CHK_SUCCESS_ELSE_CONT_M
#define CHK_SUCCESS_AND_RET_HR_M(  iHRDef, iMsg )       do{ HRESULT localHrForMacro = iHRDef; if( FAILED(localHrForMacro) ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg); return localHrForMacro; } } WHILE0// Deprecated replaced by CHK_SUCCESS_ELSE_RET_HR_M
#define CHK_SUCCESS_AND_RET_NULL_M(iHRDef, iVal )       do{ if( FAILED(iHRDef) ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg); return 0; } } WHILE0// Deprecated replaced by CHK_SUCCESS_ELSE_RET_NULL_M
#define CHK_SUCCESS_AND_RET_VAL_M( iHRDef, iVal, iMsg ) do{ if( FAILED(iHRDef) ) { __OmyAssertionFailed( __FILE__, __LINE__, iMsg); return iVal; } } WHILE0// Deprecated replaced by CHK_SUCCESS_ELSE_RET_VAL_M

//#define CHK_SUCCESS(             iHRDef )       do{ if( FAILED(iHRDef) ) { __OmyAssertionFailed( __FILE__, __LINE__ ); } } WHILE0
#define CHK_SUCCESS_ELSE_RET(     iHRDef )       do{ if( FAILED(iHRDef) ) { __OmyAssertionFailed( __FILE__, __LINE__ ); return; } } WHILE0
#define CHK_SUCCESS_ELSE_CONT(    iHRDef )       if( FAILED(iHRDef) ) { __OmyAssertionFailed( __FILE__, __LINE__ ); continue; } else do; WHILE0
#define CHK_SUCCESS_ELSE_RET_HR(  iHRDef )       do{ HRESULT localHrForMacro = iHRDef; if( FAILED(localHrForMacro) ) { __OmyAssertionFailed( __FILE__, __LINE__); return localHrForMacro; } } WHILE0
#define CHK_SUCCESS_ELSE_RET_NULL(iHRDef )       do{ if( FAILED(iHRDef) ) { __OmyAssertionFailed( __FILE__, __LINE__ ); return 0; } } WHILE0
#define CHK_SUCCESS_ELSE_RET_VAL( iHRDef, iVal ) do{ if( FAILED(iHRDef) ) { __OmyAssertionFailed( __FILE__, __LINE__ ); return iVal; } } WHILE0

#define CHK_SUCCESS(             iHRDef )       do{ if( FAILED(iHRDef) ) { __OmyAssertionFailed( __FILE__, __LINE__ ); } } WHILE0
#define CHK_SUCCESS_AND_RET(     iHRDef )       do{ if( FAILED(iHRDef) ) { __OmyAssertionFailed( __FILE__, __LINE__ ); return; } } WHILE0// Deprecated replaced by CHK_SUCCESS_ELSE_RET
#define CHK_SUCCESS_AND_CONT(    iHRDef )       if( FAILED(iHRDef) ) { __OmyAssertionFailed( __FILE__, __LINE__ ); continue; } else do; WHILE0// Deprecated replaced by CHK_SUCCESS_ELSE_CONT
#define CHK_SUCCESS_AND_RET_HR(  iHRDef )       do{ HRESULT localHrForMacro = iHRDef; if( FAILED(localHrForMacro) ) { __OmyAssertionFailed( __FILE__, __LINE__); return localHrForMacro; } } WHILE0// Deprecated replaced by CHK_SUCCESS_ELSE_RET_HR
#define CHK_SUCCESS_AND_RET_NULL(iHRDef )       do{ if( FAILED(iHRDef) ) { __OmyAssertionFailed( __FILE__, __LINE__ ); return 0; } } WHILE0// Deprecated replaced by CHK_SUCCESS_ELSE_RET_NULL
#define CHK_SUCCESS_AND_RET_VAL( iHRDef, iVal ) do{ if( FAILED(iHRDef) ) { __OmyAssertionFailed( __FILE__, __LINE__ ); return iVal; } } WHILE0// Deprecated replaced by CHK_SUCCESS_ELSE_RET_VAL

//=====================================================================
//#define CHK_BOOL_M(             iBool, iMsg )       CHK_M(iBool, iMsg)
#define CHK_BOOL_ELSE_RET_M(     iBool, iMsg )       CHK_AND_RET_M(iBool, iMsg)
#define CHK_BOOL_ELSE_CONT_M(    iBool, iMsg )       CHK_AND_CONT_M(iBool, iMsg)
#define CHK_BOOL_ELSE_RET_HR_M(  iBool, iMsg )       CHK_AND_RET_HR_M(iBool, iMsg)
#define CHK_BOOL_ELSE_RET_NULL_M(iBool, iMsg )       CHK_AND_RET_NULL_M(iBool, iMsg)
#define CHK_BOOL_ELSE_RET_VAL_M( iBool, iVal, iMsg ) CHK_AND_RET_VAL_M(iBool, iVal, iMsg)

#define CHK_BOOL_M(             iBool, iMsg )       CHK_M(iBool, iMsg)
#define CHK_BOOL_AND_RET_M(     iBool, iMsg )       CHK_AND_RET_M(iBool, iMsg)// Deprecated replaced by CHK_BOOL_ELSE_RET_M
#define CHK_BOOL_AND_CONT_M(    iBool, iMsg )       CHK_AND_CONT_M(iBool, iMsg)// Deprecated replaced by CHK_BOOL_ELSE_CONT_M
#define CHK_BOOL_AND_RET_HR_M(  iBool, iMsg )       CHK_AND_RET_HR_M(iBool, iMsg)// Deprecated replaced by CHK_BOOL_ELSE_RET_HR_M
#define CHK_BOOL_AND_RET_NULL_M(iBool, iMsg )       CHK_AND_RET_NULL_M(iBool, iMsg)// Deprecated replaced by CHK_BOOL_ELSE_RET_NULL_M
#define CHK_BOOL_AND_RET_VAL_M( iBool, iVal, iMsg ) CHK_AND_RET_VAL_M(iBool, iVal, iMsg)// Deprecated replaced by CHK_BOOL_ELSE_RET_VAL_M

//#define CHK_BOOL(             iBool )       CHK( iBool )
#define CHK_BOOL_ELSE_RET(     iBool )       CHK_AND_RET( iBool )
#define CHK_BOOL_ELSE_CONT(    iBool )       CHK_AND_CONT( iBool )
#define CHK_BOOL_ELSE_RET_HR(  iBool )       CHK_AND_RET_HR( iBool )
#define CHK_BOOL_ELSE_RET_NULL(iBool )       CHK_AND_RET_NULL( iBool )
#define CHK_BOOL_ELSE_RET_VAL( iBool, iVal ) CHK_AND_RET_VAL( iBool, iVal )

#define CHK_BOOL(             iBool )       CHK( iBool )
#define CHK_BOOL_AND_RET(     iBool )       CHK_AND_RET( iBool )// Deprecated replaced by CHK_BOOL_ELSE_RET
#define CHK_BOOL_AND_CONT(    iBool )       CHK_AND_CONT( iBool )// Deprecated replaced by CHK_BOOL_ELSE_CONT
#define CHK_BOOL_AND_RET_HR(  iBool )       CHK_AND_RET_HR( iBool )// Deprecated replaced by CHK_BOOL_ELSE_RET_HR
#define CHK_BOOL_AND_RET_NULL(iBool )       CHK_AND_RET_NULL( iBool )// Deprecated replaced by CHK_BOOL_ELSE_RET_NULL
#define CHK_BOOL_AND_RET_VAL( iBool, iVal ) CHK_AND_RET_VAL( iBool, iVal )// Deprecated replaced by CHK_BOOL_ELSE_RET_VAL

//=====================================================================
// Les macros LOG_*** sont similaires aux CHK_*** sauf qu'elles n'asserte pas,
// elles ne font qu'ajouter une trace d'erreur sur la console et dans les traces OMB
//=====================================================================
#define LOG_ERROR_M( iMsg ) __OmyWarningFailure( __FILE__, __LINE__, iMsg  )

// Cette macro ajoute une trace de warning sur la console et dans les traces OMB.
#define LOG_WARNING_M( iMsg ) __OmyWarningMessage( __FILE__, __LINE__, iMsg )

#define LOG_FALSE_M(             iBool, iMsg )        do{ if( !(iBool) ) { __OmyWarningFailure( __FILE__, __LINE__, iMsg  ); } } WHILE0
#define LOG_FALSE_AND_RET_M(     iBool, iMsg )        do{ if( !(iBool) ) { __OmyWarningFailure( __FILE__, __LINE__, iMsg  ); return; } } WHILE0
#define LOG_FALSE_AND_CONT_M(    iBool, iMsg )        if( !(iBool) ) { __OmyWarningFailure( __FILE__, __LINE__, iMsg  ); continue; } else do; WHILE0
#define LOG_FALSE_AND_RET_HR_M(  iBool, iMsg )        do{ if( !(iBool) ) { __OmyWarningFailure( __FILE__, __LINE__, iMsg  ); return E_UNEXPECTED; } } WHILE0
#define LOG_FALSE_AND_RET_NULL_M(iBool, iMsg )        do{ if( !(iBool) ) { __OmyWarningFailure( __FILE__, __LINE__, iMsg  ); return 0; } } WHILE0
#define LOG_FALSE_AND_RET_VAL_M( iBool, iVal, iMsg  ) do{ if( !(iBool) ) { __OmyWarningFailure( __FILE__, __LINE__, iMsg  ); return iVal; } } WHILE0

#define LOG_FALSE(             iBool )       do{ if( !(iBool) ) { __OmyWarningFailure( __FILE__, __LINE__ ); } } WHILE0
#define LOG_FALSE_AND_RET(     iBool )       do{ if( !(iBool) ) { __OmyWarningFailure( __FILE__, __LINE__ ); return; } } WHILE0
#define LOG_FALSE_AND_CONT(    iBool )       if( !(iBool) ) { __OmyWarningFailure( __FILE__, __LINE__ ); continue; } else do; WHILE0
#define LOG_FALSE_AND_RET_HR(  iBool )       do{ if( !(iBool) ) { __OmyWarningFailure( __FILE__, __LINE__ ); return E_UNEXPECTED; } } WHILE0
#define LOG_FALSE_AND_RET_NULL(iBool )       do{ if( !(iBool) ) { __OmyWarningFailure( __FILE__, __LINE__ ); return 0; } } WHILE0
#define LOG_FALSE_AND_RET_VAL( iBool, iVal ) do{ if( !(iBool) ) { __OmyWarningFailure( __FILE__, __LINE__ ); return iVal; } } WHILE0

//=====================================================================
#define LOG_NULL_VAR_M(             iHandler, iMsg )       do{ if( NULL_var == (CATBaseUnknown *) iHandler ) { __OmyWarningFailure( __FILE__, __LINE__, iMsg  ); } } WHILE0
#define LOG_NULL_VAR_AND_RET_M(     iHandler, iMsg )       do{ if( NULL_var == (CATBaseUnknown *) iHandler ) { __OmyWarningFailure( __FILE__, __LINE__, iMsg  ); return; } } WHILE0
#define LOG_NULL_VAR_AND_CONT_M(    iHandler, iMsg )       if( NULL_var == (CATBaseUnknown *) iHandler ) { __OmyWarningFailure( __FILE__, __LINE__, iMsg  ); continue; } else do; WHILE0
#define LOG_NULL_VAR_AND_RET_HR_M(  iHandler, iMsg )       do{ if( NULL_var == (CATBaseUnknown *) iHandler ) { __OmyWarningFailure( __FILE__, __LINE__, iMsg  ); return E_UNEXPECTED; } } WHILE0
#define LOG_NULL_VAR_AND_RET_NULL_M(iHandler, iMsg )       do{ if( NULL_var == (CATBaseUnknown *) iHandler ) { __OmyWarningFailure( __FILE__, __LINE__, iMsg  ); return 0; } } WHILE0
#define LOG_NULL_VAR_AND_RET_VAL_M( iHandler, iVal, iMsg ) do{ if( NULL_var == (CATBaseUnknown *) iHandler ) { __OmyWarningFailure( __FILE__, __LINE__, iMsg  ); return iVal; } } WHILE0

#define LOG_NULL_VAR(             iHandler )       do{ if( NULL_var == (CATBaseUnknown *) iHandler ) { __OmyWarningFailure( __FILE__, __LINE__ ); } } WHILE0
#define LOG_NULL_VAR_AND_RET(     iHandler )       do{ if( NULL_var == (CATBaseUnknown *) iHandler ) { __OmyWarningFailure( __FILE__, __LINE__ ); return; } } WHILE0
#define LOG_NULL_VAR_AND_CONT(    iHandler )       if( NULL_var == (CATBaseUnknown *) iHandler ) { __OmyWarningFailure( __FILE__, __LINE__ ); continue; } else do; WHILE0
#define LOG_NULL_VAR_AND_RET_HR(  iHandler )       do{ if( NULL_var == (CATBaseUnknown *) iHandler ) { __OmyWarningFailure( __FILE__, __LINE__ ); return E_UNEXPECTED; } } WHILE0
#define LOG_NULL_VAR_AND_RET_NULL(iHandler )       do{ if( NULL_var == (CATBaseUnknown *) iHandler ) { __OmyWarningFailure( __FILE__, __LINE__ ); return 0; } } WHILE0
#define LOG_NULL_VAR_AND_RET_VAL( iHandler, iVal ) do{ if( NULL_var == (CATBaseUnknown *) iHandler ) { __OmyWarningFailure( __FILE__, __LINE__ ); return iVal; } } WHILE0

//=====================================================================
#define LOG_DIFF_M(             iVal, iRef, iMsg )      do{ if( iRef == iVal ) { __OmyWarningFailure( __FILE__, __LINE__, iMsg ); } } WHILE0
#define LOG_DIFF_AND_RET_M(     iVal, iRef, iMsg )      do{ if( iRef == iVal ) { __OmyWarningFailure( __FILE__, __LINE__, iMsg ); return; } } WHILE0
#define LOG_DIFF_AND_CONT_M(    iVal, iRef, iMsg )      if( iRef == iVal ) { __OmyWarningFailure( __FILE__, __LINE__, iMsg ); continue; } else do; WHILE0
#define LOG_DIFF_AND_RET_HR_M(  iVal, iRef, iMsg )      do{ if( iRef == iVal ) { __OmyWarningFailure( __FILE__, __LINE__, iMsg ); return E_UNEXPECTED; } } WHILE0
#define LOG_DIFF_AND_RET_NULL_M(iVal, iRef, iMsg )      do{ if( iRef == iVal ) { __OmyWarningFailure( __FILE__, __LINE__, iMsg ); return 0; } } WHILE0
#define LOG_DIFF_AND_RET_VAL_M( iVal, iRef, iRC, iMsg ) do{ if( iRef == iVal ) { __OmyWarningFailure( __FILE__, __LINE__, iMsg ); return iRC; } } WHILE0

#define LOG_DIFF(             iVal, iRef )      do{ if( iRef == iVal ) { __OmyWarningFailure( __FILE__, __LINE__ ); } } WHILE0
#define LOG_DIFF_AND_RET(     iVal, iRef )      do{ if( iRef == iVal ) { __OmyWarningFailure( __FILE__, __LINE__ ); return; } } WHILE0
#define LOG_DIFF_AND_CONT(    iVal, iRef )      if( iRef == iVal ) { __OmyWarningFailure( __FILE__, __LINE__ ); continue; } else do; WHILE0
#define LOG_DIFF_AND_RET_HR(  iVal, iRef )      do{ if( iRef == iVal ) { __OmyWarningFailure( __FILE__, __LINE__ ); return E_UNEXPECTED; } } WHILE0
#define LOG_DIFF_AND_RET_NULL(iVal, iRef )      do{ if( iRef == iVal ) { __OmyWarningFailure( __FILE__, __LINE__ ); return 0; } } WHILE0
#define LOG_DIFF_AND_RET_VAL( iVal, iRef, iRC ) do{ if( iRef == iVal ) { __OmyWarningFailure( __FILE__, __LINE__ ); return iRC; } } WHILE0

//=====================================================================
#define LOG_FAILURE_M(             iHRDef, iMsg )       do{ if( FAILED(iHRDef) ) { __OmyWarningFailure( __FILE__, __LINE__, iMsg); } } WHILE0
#define LOG_FAILURE_AND_RET_M(     iHRDef, iMsg )       do{ if( FAILED(iHRDef) ) { __OmyWarningFailure( __FILE__, __LINE__, iMsg); return; } } WHILE0
#define LOG_FAILURE_AND_CONT_M(    iHRDef, iMsg )       if( FAILED(iHRDef) ) { __OmyWarningFailure( __FILE__, __LINE__, iMsg); continue; } else do; WHILE0
#define LOG_FAILURE_AND_RET_HR_M(  iHRDef, iMsg )       do{ HRESULT localHrForMacro = iHRDef; if( FAILED(localHrForMacro) ) { __OmyWarningFailure( __FILE__, __LINE__, iMsg); return localHrForMacro; } } WHILE0
#define LOG_FAILURE_AND_RET_NULL_M(iHRDef, iVal )       do{ if( FAILED(iHRDef) ) { __OmyWarningFailure( __FILE__, __LINE__, iMsg); return 0; } } WHILE0
#define LOG_FAILURE_AND_RET_VAL_M( iHRDef, iVal, iMsg ) do{ if( FAILED(iHRDef) ) { __OmyWarningFailure( __FILE__, __LINE__, iMsg); return iVal; } } WHILE0

#define LOG_FAILURE(             iHRDef )       do{ if( FAILED(iHRDef) ) { __OmyWarningFailure( __FILE__, __LINE__ ); } } WHILE0
#define LOG_FAILURE_AND_RET(     iHRDef )       do{ if( FAILED(iHRDef) ) { __OmyWarningFailure( __FILE__, __LINE__ ); return; } } WHILE0
#define LOG_FAILURE_AND_CONT(    iHRDef )       if( FAILED(iHRDef) ) { __OmyWarningFailure( __FILE__, __LINE__ ); continue; } else do; WHILE0
#define LOG_FAILURE_AND_RET_HR(  iHRDef )       do{ HRESULT localHrForMacro = iHRDef; if( FAILED(localHrForMacro) ) { __OmyWarningFailure( __FILE__, __LINE__); return localHrForMacro; } } WHILE0
#define LOG_FAILURE_AND_RET_NULL(iHRDef )       do{ if( FAILED(iHRDef) ) { __OmyWarningFailure( __FILE__, __LINE__ ); return 0; } } WHILE0
#define LOG_FAILURE_AND_RET_VAL( iHRDef, iVal ) do{ if( FAILED(iHRDef) ) { __OmyWarningFailure( __FILE__, __LINE__ ); return iVal; } } WHILE0

//=====================================================================
#define LOG_NULL_M(             iItf, iMsg )       LOG_BOOL_M(iItf, iMsg)
#define LOG_NULL_AND_RET_M(     iItf, iMsg )       LOG_BOOL_AND_RET_M(iItf, iMsg)
#define LOG_NULL_AND_CONT_M(    iItf, iMsg )       LOG_BOOL_AND_CONT_M(iItf, iMsg)
#define LOG_NULL_AND_RET_HR_M(  iItf, iMsg )       LOG_BOOL_AND_RET_HR_M(iItf, iMsg)
#define LOG_NULL_AND_RET_NULL_M(iItf, iMsg )       LOG_BOOL_AND_RET_NULL_M(iItf, iMsg)
#define LOG_NULL_AND_RET_VAL_M( iItf, iVal, iMsg ) LOG_BOOL_AND_RET_VAL_M(iItf, iVal, iMsg)

#define LOG_NULL(             iItf )       LOG_BOOL( iItf )
#define LOG_NULL_AND_RET(     iItf )       LOG_BOOL_AND_RET( iItf )
#define LOG_NULL_AND_CONT(    iItf )       LOG_BOOL_AND_CONT( iItf )
#define LOG_NULL_AND_RET_HR(  iItf )       LOG_BOOL_AND_RET_HR( iItf )
#define LOG_NULL_AND_RET_NULL(iItf )       LOG_BOOL_AND_NULL_HR( iItf )
#define LOG_NULL_AND_RET_VAL( iItf, iVal ) LOG_BOOL_AND_RET_VAL( iItf, iVal )

//=====================================================================
#define LOG_ABEND( iMsg )   __OmyAssertionFailed( __FILE__, __LINE__, iMsg )

inline HRESULT __OmyLogError( const char * iFileName, const int iLn, const CATUnicodeString& iMsg )
{
  __OmyAssertionFailed( iFileName, iLn, iMsg );
  return E_FAIL;
}
#define ON_ERROR( iMsg )    __OmyLogError( __FILE__, __LINE__, iMsg )

// Specialized abends.
#define LOG_ITG_ABEND(  iMsg ) LOG_ABEND( iMsg )
#define LOG_OM_ABEND(   iMsg ) LOG_ABEND( iMsg )
#define LOG_SESS_ABEND( iMsg ) LOG_ABEND( iMsg )
#define LOG_ID_ABEND(   iMsg ) LOG_ABEND( iMsg )
#define LOG_APP_ABEND(  iMsg ) LOG_ABEND( iMsg )
#define LOG_ADP_ABEND(  iMsg ) LOG_ABEND( iMsg )
#define LOG_SRV_ABEND(  iMsg ) LOG_ABEND( iMsg )
#define LOG_MOD_ABEND(  iMsg ) LOG_ABEND( iMsg )
#define LOG_OMY_ABEND(  iMsg ) LOG_ABEND( iMsg )
#define LOG_PXn_ABEND(  iMsg ) LOG_ABEND( iMsg )
#define LOG_ITGERR_ABEND( iMsg ) LOG_ABEND( iMsg )
#define LOG_TODO_ABEND(iMsg) __OmyAssertOnSpecificReplay(__FILE__, __LINE__ , iMsg );

#endif
