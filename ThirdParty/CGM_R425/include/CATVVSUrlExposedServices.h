#ifndef __CATVVSExposedServices__
#define __CATVVSExposedServices__

/**
* @level Protected
* @usage U4 CATVVSExposedServices
*/


// Exposed, but restricted
#if defined (private) || defined(friend) || defined (protected)
#error Forbidden re-define of 'private', 'friend' or 'protected'
// Fatal error on solaris
@error 
#endif

#define AuthorizedModule     999
#define VVSUtils								               AuthorizedModule	// For Definition
#define VVSUrlUtils								             AuthorizedModule	// For FromUrlToNativeFilePath
#define CATOmbPersistency				               AuthorizedModule	// For NonSpec doc persistency (Load/Stream) 
#define SelectiveLoadingTST_RepRefTSTImpl		   AuthorizedModule	// Omb TST Converter
#define CATOmbSelectiveLoading					       AuthorizedModule	// RepRefServices For SheetMetal
#define CATOMYPowerIO							             AuthorizedModule	// For PowerIO
#define CATOMYPowerIOMPComm						         AuthorizedModule	// For VVS Async
#define CATPLMAsync              						   AuthorizedModule	// For VVS Async

#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden access to link services from a non-infrastructure module
// Fatal error on solaris
@error 
#endif

#undef VVSUtils
#undef CATOmbPersistency
#undef SelectiveLoadingTST_RepRefTSTImpl
#undef CATOmbSelectiveLoading
#undef CATOMYPowerIO
#undef CATOMYPowerIOMPComm
#undef CATPLMAsync

#undef AuthorizedModule     

#include "CATVVSUrl.h"
#include "CATListOfCATVVSUrl.h"
#include "VVSUtils.h"
#include "CATOmxArray.h"

struct ExportedByVVSUtils CATFCSUrlData
{
    CATUnicodeString PhysicalId;
    CATUnicodeString MajorId; 
    CATUnicodeString LogicalId; 
    CATUnicodeString TypeId; 
    CATUnicodeString Repository;
    CATUnicodeString Store;
    CATUnicodeString SD;
};

class ExportedByVVSUtils CATVVSUrlExposedServices
{
public:

	HRESULT GetPhysicalUrlPath(CATVVSUrl& iUrl, CATVVSUrl& oUrl);
	HRESULT GetPhysicalUrlPath(CATListOfCATVVSUrl& iUrl, CATListOfCATVVSUrl& oUrl);
  HRESULT CreateFCSUrlFromData(const CATFCSUrlData& iUrlData, CATVVSUrl &oUrl);
};

#endif

