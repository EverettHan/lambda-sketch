#ifndef CATIScriptContainers_h
#define CATIScriptContainers_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "IUnknown.h"
#include "CATScriptLanguage.h"
#include "CATUnicodeString.h"

class CATDocument;
class CATIScriptContainer;
class CATScriptRef;

/**
 * Interface to manage script containers. Script containers are objects
 * which contain one or several scripts (depending upon the container type).
 * They are in charge of script persistence. The <tt>CATIScriptContainers</tt>
 * maintains a list of available script containers.
 * @author: Jean-Francois Doue (JDU)
 */
class CATIScriptContainers : public IUnknown {
	public:
		/**
		 * Opens a new container with the specified reference.
		 */
		virtual HRESULT __stdcall CreateContainer(
			CATScriptRef* iReference,
			CATIScriptContainer*& oContainer) = 0;

		/**
		 * Opens a new container with the specified reference.
		 */
		virtual HRESULT __stdcall OpenContainer(
			CATScriptRef* iReference,
			CATIScriptContainer*& oContainer) = 0;
		/**
		 * Removes a container from the list of available containers.
		 */
		virtual HRESULT __stdcall CloseContainer(
			CATIScriptContainer* iContainer) = 0;

		/**
		 * Returns the count of containers.
		 */
		virtual HRESULT __stdcall Count(
			unsigned int& oCount) = 0;

		/**
		 * Returns the iIndexth container in the list.
		 */
		virtual HRESULT __stdcall Item(
			unsigned int iIndex, 
			CATIScriptContainer*& oContainer) = 0;

		/**
		 * TODO RM. E_NOTIMPL.
		 */
		virtual HRESULT __stdcall Item(
			const CATUnicodeString& iContainerName, 
			CATIScriptContainer*& oContainer) = 0;

		/**
		 * Returns the index of the container in the list.
		 */
		virtual HRESULT __stdcall Index(
			CATIScriptContainer* iContainer, 
			unsigned int& oIndex ) = 0;

		/**
		 * TODO RM. E_NOTIMPL.
		 */
		virtual HRESULT __stdcall Index(
			const CATUnicodeString& iName, 
			unsigned int& oIndex ) = 0;
};

extern "C" const IID IID_CATIScriptContainers;

#endif

