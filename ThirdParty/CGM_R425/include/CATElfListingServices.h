// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// CATElfListingServices.h
// Header definition of CATElfListingServices
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Sep 2004  Creation: Code generated by the CAA wizard  jup
//===================================================================
#ifndef CATElfListingServices_H
#define CATElfListingServices_H

#ifdef _WINDOWS_SOURCE
#include "io.h" //Pour dup, dup2 et close
#else
#include "unistd.h"
#endif

#include "stdio.h" //Pour fileno
#include "CATErrorDef.h"
#include "CATUnicodeString.h"
#include "CATELFMathKernel.h"

class ExportedByCATELFMathKernel CATElfListingServices
{

public :

  static HRESULT Set ( const CATUnicodeString & iDirectory );
  static HRESULT Reset ();

  static CATUnicodeString & GetDirectory ();
  static CATUnicodeString & GetFileName ();
  static int GetDescriptor ();

private :

  static void ComputeFileName ( CATUnicodeString & oFileName );

  static CATUnicodeString _Directory;
  static CATUnicodeString _FileName;
  static int              _Descriptor;

};

#define CATElfListingRedirDecl                          \
  int tempDesc, stdoutDesc, listingDesc, errorFlag;     \
  tempDesc = stdoutDesc = listingDesc = errorFlag = -1; \

#define CATElfListingRedirStart                                          \
{                                                                        \
  listingDesc = CATElfListingServices::GetDescriptor ();                 \
  if ( listingDesc != -1 )                                               \
  {                                                                      \
    stdoutDesc = fileno ( stdout );                                      \
    tempDesc = dup ( stdoutDesc );                                       \
    if ( tempDesc != -1 ) errorFlag = dup2 ( listingDesc, stdoutDesc );  \
  }                                                                      \
}

#define CATElfListingRedirEnd                                        \
{                                                                    \
  if ( errorFlag != -1 ) dup2 ( tempDesc, stdoutDesc );              \
  if ( tempDesc != -1 ) close ( tempDesc );                          \
}

#endif
