#ifndef CATIASystemConfigurationImpl_h
#define CATIASystemConfigurationImpl_h

// COPYRIGHT DASSAULT SYSTEMES 2002

// SpecialAPI framework
#include "CATIAV5Level.h"
#ifdef CATIAV5R10

// System framework
#include "CATBaseObject.h"
#include "CATBSTR.h"
#include "CATSafeArray.h"
#include "CAT_VARIANT_BOOL.h"
// + qay 2008:07:17 InfInterfaces split 
#include "InfOSIDLImpl.h"

/**
 * Class to implement the CATIASystemConfiguration interface
 */
class ExportedByInfOSIDLImpl /* + qay 2008:07:17 InfInterfaces split */ CATIASystemConfigurationImpl : public CATBaseObject {
   CATDeclareClass;

   public:
		/**
		 * Constructor
		 */
		CATIASystemConfigurationImpl();
 		/**
		 * Destructor
		 */
		virtual ~CATIASystemConfigurationImpl();

		// Implementation of the CATIASystemConfiguration interface
		virtual HRESULT __stdcall get_OperatingSystem(
			CATBSTR & oOperatingSystem);

		virtual HRESULT __stdcall get_Version(
			CATLONG & oVersion);

		virtual HRESULT __stdcall get_Release(
			CATLONG & oRelease);

		virtual HRESULT __stdcall get_ServicePack(
			CATLONG & oServicePack);

		virtual HRESULT __stdcall get_ProductCount(
			CATLONG & oProductCount);

		virtual HRESULT __stdcall GetProductNames(
			CATSafeArrayVariant & ioProductNames);

		virtual HRESULT __stdcall IsProductAuthorized(
			const CATBSTR & iProductName, 
			CAT_VARIANT_BOOL & oAuthorized);
};

#endif // CATIAV5R10

#endif //CATIASystemConfigurationImpl_h
