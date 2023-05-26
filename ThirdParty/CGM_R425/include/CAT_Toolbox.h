// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CAT_Toolbox_h
#define CAT_Toolbox_h

/**
 * @level Protected
 * @usage U1
 */

#include "stringDef.h"
#include "sequence_octet.h"
#include "CATUnicodeString.h"
#include "AC0XXLNK.h"
#include "CATDataType.h"

// The following definition will disapear as soon as it appeared
// for migration reason
#ifndef NEW_DIEZELE_VERSION
#define NEW_DIEZELE_VERSION
#endif

//
// The AsString functions return a string which has the following
// characteristics :
//    - it must not be modified nor deleted.
//    - it will be destroyed by next call to one of AsString functions.
//    - it has a maximum size of 1024 characters. If more than 
//      1024 characters are needed, then an exception is throw.
//

ExportedByAC0XXLNK char* AsString (int len, const void* data, int convertToPrintable=1) ;

ExportedByAC0XXLNK char* AsString (const char* data, int convertToPrintable=1) ;

ExportedByAC0XXLNK char* AsString (CATUnicodeString data, int convertToPrintable=1) ;


//
// The AsSequence function returns a pointer towards a SEQUENCE(octet) which 
// has the following characteristics :
//    - its data must not be modified nor deleted.
//    - its data will be destroyed by next call to AsSequence function.
//    - it has a maximum size of 1024 octets. If more than 
//      1024 octets are needed, then an exception is throw.
// If compressing is demanded, then the string is analyzed until the
// first ';' character not preceded by a '\\' or string end.
//
// The integer returned contains how many characters have been analyzed.
//
// This function returns a pointer towards a sequence instead of a reference
// to reduce the risk of executing non-needed copy constructors.
//

ExportedByAC0XXLNK const SEQUENCE(octet)* AsSequence (char* data, int* numberOfanalyzedChars) ;
     

//
// little indian <--> big indian
//
ExportedByAC0XXLNK void UnixFormat (int& value) ;
ExportedByAC0XXLNK void WindowsFormat (int& value) ;
     
ExportedByAC0XXLNK void LocalFormat (int& value) ;

#ifndef PLATEFORME_DS64
ExportedByAC0XXLNK void UnixFormat (CATLONG32& value) ;
ExportedByAC0XXLNK void WindowsFormat (CATLONG32& value) ;     

ExportedByAC0XXLNK void LocalFormat (CATLONG32& value) ;
#endif

ExportedByAC0XXLNK void UnixFormat (short& value) ;
ExportedByAC0XXLNK void WindowsFormat (short& value) ;
     
ExportedByAC0XXLNK void LocalFormat (short& value) ;

ExportedByAC0XXLNK void UnixFormat (unsigned short& value) ;
ExportedByAC0XXLNK void WindowsFormat (unsigned short& value) ;
     
ExportedByAC0XXLNK void LocalFormat (unsigned short& value) ;

#endif


