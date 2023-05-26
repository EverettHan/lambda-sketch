/**
* @level Protected 
* @usage U1
*/

#ifndef CATIABindNativeFormat_H
#define CATIABindNativeFormat_H

#include "CATFormat.h"
#include "CATUnicodeString.h"
#include "CATIACBFormat.h"

/**
  * Build time definition that correspond to the \"As Specification\" conversion format
  */
#define CATIA_SPEC_FORMAT "CATIA_SPEC"
/**
  * Build time definition that correspond to the \"As Result\" conversion format
  */
#define CATIA_RESULT_FORMAT "CATIA_RESULT"

/**
  * Service that gives the opportunity to get or create the CATFormat object corresponding to one schema name
  * @param
  *   The name of the schema ( for example \"CATIA_SPEC\", or \"CATIA_RESULT\" )
  *   Usually the define is used instead the real schema name.
  * @return
  *   Created CATFormat object. In term of lifecycle, nothing has to be done on the resulting object.
  */
extern ExportedByCATIACBFormat const CATFormat* CATIABindNativeFormat( const CATUnicodeString schema_name ) ;

#endif
