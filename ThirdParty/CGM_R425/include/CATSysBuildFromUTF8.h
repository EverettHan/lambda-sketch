//*===========================================================================*
//* COPYRIGHT DASSAULT SYSTEMES 2004                                         *
//*===========================================================================*
//*                                                                           *
//*  Usage Notes:                                                             *
//*===========================================================================*
//*  Creation juin 2004                                                       *
//*===========================================================================*
#ifndef __CATSYSBUILDFROMUTF8
#define __CATSYSBUILDFROMUTF8

#include "NS0S3STR.h"
#include "CATWTypes.h"
#include "CATUnicodeChar.h"

class CATUnicodeString;


// CATIAR419+: not supported anymore
HRESULT ExportedByNS0S3STR CATSysBuildFromUTF8(const char * iUTF8Data, 
					       size_t iNbBytes, 
					       CATUnicodeString **oStr,
					       int& oModified) ;

HRESULT ExportedByNS0S3STR  CATSysBuildFromUTF8( const char * iUTF8Data,
						 size_t iNbBytes, 
						 CATUnicodeString &oStr,
						 int& oModified);
#endif
