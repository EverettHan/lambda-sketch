#ifndef CATOMBADAPTERPROTECTIONFORLEGACY_H
#define CATOMBADAPTERPROTECTIONFORLEGACY_H
#include "AD0XXBAS.h"

#define AtLeastOneAuthorization           0
#define AuthorizedModule                  999
#define AD0XXBAS                          AuthorizedModule

class ExportedByAD0XXBAS CATOmbAdapterProtectionForLegacy {
public:

  //CATIStream2
#define AD0LegacyTests                    AuthorizedModule
#define CGMV5Interop                      AuthorizedModule
//#define CATScriptContainers               AuthorizedModule
#if _MK_MODNAME_ == AuthorizedModule
#undef AtLeastOneAuthorization
#define AtLeastOneAuthorization 1
  static void* GetOmbProtectionAdressForCATIStream2();
#endif
#undef AD0LegacyTests
#undef CGMV5Interop
//#undef CATScriptContainers

};




#if AtLeastOneAuthorization == 0
#error Forbidden access to CATOmbAdapterProtectionForLegacy from not authorized module
#endif


#endif
