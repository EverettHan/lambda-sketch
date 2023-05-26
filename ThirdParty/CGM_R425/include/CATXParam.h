// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
//
// CATXParam:
// Polymorph Curve or Surface Parameter
//
//=============================================================================
// Jul. 99   Creation                                     R. Rorato
//=============================================================================
#ifndef CATXParam_H
#define CATXParam_H

/** @c++ansi fbq 2004-08-05.10:18:26 [Replace forward declaration by #include <iosfwd.h>] **/
#ifdef _CAT_ANSI_STREAMS
#include <iosfwd.h>
#else
class ostream;
#endif

//#include "ExportedByCATFDGImpl.h"
#include "ExportedByRIBLight.h"
#include "CATCGMNewArray.h"
#include "CATCrvParam.h"
#include "CATSurParam.h"

#include "CATSafe.h"
CATSafeDefine(CATXParam);

//-----------------------------------------------------------------------------
class ExportedByRIBLight CATXParam 
//-----------------------------------------------------------------------------
{
  public :

  CATXParam  () ;
  CATXParam  (const CATCrvParam & iParam) ;
  CATXParam  (const CATSurParam & iParam) ;
  CATCGMNewClassArrayDeclare; 

  CATXParam& operator=  (const CATCrvParam & iParam) ;
  CATXParam& operator=  (const CATSurParam & iParam) ;

  short        IsEmpty     () const {                 return  _Dimension==0 ; } ;
  int          GetDimension() const {                 return  _Dimension    ; } ;
  CATCrvParam* GetCrvParam ()       { _Dimension = 1; return &_CrvParam     ; } ;
  CATSurParam* GetSurParam ()       { _Dimension = 2; return &_SurParam     ; } ;

  private :

  int         _Dimension ;
  CATSurParam _SurParam  ;
  CATCrvParam _CrvParam  ;


};
//-----------------------------------------------------------------------------
ExportedByRIBLight ostream& operator << (ostream& iS, const CATXParam & iParam);
//-----------------------------------------------------------------------------
#endif








