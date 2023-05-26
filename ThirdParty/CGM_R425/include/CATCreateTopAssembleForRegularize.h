#ifndef CATCreateTopAssembleForRegularize_H 
#define CATCreateTopAssembleForRegularize_H 

#include "BOHYBOPELight.h"

class CATHybAssemble;
class CATGeoFactory;
class CATListPtrCATBody;
class CATTopData;

/** @nodoc @nocgmitf
*
*/
ExportedByBOHYBOPELight CATHybAssemble * CATCreateTopAssembleForRegularize(CATGeoFactory * iFactory,
                                                                           CATTopData * iData,
                                                                           CATListPtrCATBody * iBodiesToAssemble);

#endif
