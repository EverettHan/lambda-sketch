#ifndef VBAMenuItemHandler_h
#define VBAMenuItemHandler_h
#include "CATVBACodeMacro.h"
#if defined(_WINDOWS_SOURCE) && (!defined(_DS_VBAIntegrationIsOutProcess))

/**
 * Listener class used to catch events sent when the custom
 * menu item added to VBE is clicked.
 * @author: Jean-Francois Doue (JDU)
 * Modified: 2001-07-24
 */

#include "CATdispCommandBarControlEvents.h"

interface IConnectionPointContainer;

class VBAMenuItemHandler : public CATdispCommandBarControlEvents {
	public:

		typedef HRESULT (*VBAMenuItemHandlerCallback)();
		VBAMenuItemHandler(VBAMenuItemHandlerCallback iCallback);
		~VBAMenuItemHandler();

		HRESULT __stdcall CreateConnections(
			IConnectionPointContainer* iPublisher
		);

		HRESULT __stdcall DeleteConnections(
		);

		/* Implementation of the IUnknown interface */
		virtual HRESULT __stdcall QueryInterface(const IID &iIID, void **oPPV);
		virtual ULONG __stdcall AddRef();
		virtual ULONG __stdcall Release();

		/* Implementation of the IDispatch interface */
		virtual HRESULT __stdcall GetTypeInfoCount(unsigned int *oNbOfTypeInfo);
		virtual HRESULT __stdcall GetTypeInfo(unsigned int iIndex, unsigned long iLangId, ITypeInfo **oPtTypeInfo);
		virtual HRESULT __stdcall GetIDsOfNames(const IID &forFutur, CATWCHAR_T **iArrayOfNames, unsigned int iNbNames, unsigned long iLangId, long *oArrayOflong);
		virtual HRESULT __stdcall Invoke(long ilongMember, const IID &forFutur,unsigned long iLangId, unsigned short iFlags, DISPPARAMS *iPdisparams, VARIANT *oPvaresult, EXCEPINFO *oPexcepinfo, unsigned int *oPuArgErr);

		/* Implementation of the CATdispCommandBarControlEvents interface */
		virtual void __stdcall Click(
			IDispatch* msCtrl,
			VARIANT_BOOL* handled,
			VARIANT_BOOL* CancelDefault);

	protected:
		/**
		 * Identifier of the connection.
		 */
		unsigned long _cookie;

		/**
		 * The VBA menu item which publishes the event.
		 */
		IConnectionPointContainer* _publisher;

		/**
		 * The instance reference counter.
		 */
		ULONG _refCount;

		/**
		 * The callback function to invoke when the menu is clicked.
		 */
		VBAMenuItemHandlerCallback _callback;

};

#endif // defined(_WINDOWS_SOURCE) && (!defined(_DS_VBAIntegrationIsOutProcess))
#endif // VBAMenuItemHandler_h

