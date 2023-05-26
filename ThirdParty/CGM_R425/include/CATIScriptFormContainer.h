#ifndef CATIScriptFormContainer_h
#define CATIScriptFormContainer_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "IUnknown.h"
#include "CATUnicodeString.h"
#include "CATBoolean.h"

class CATIScriptForm;

/**
 * Interface for scripted form containers.
 * @author: Jean-Francois Doue (JDU)
 */
class CATIScriptFormContainer : public IUnknown {
	public:

		/**
		 * Returns true is the container is read-only, false otherwise
		 */
		virtual HRESULT __stdcall IsReadOnly(
			CATBoolean& oReadOnly) = 0;

		/**
		 * Returns the number of ScriptFroms contained in the container.
		 */
		virtual HRESULT __stdcall FormCount(
			unsigned int& oCount) = 0;

		/**
		 * Returns the position of the supplied form in the container.
		 */
		virtual HRESULT __stdcall FormIndex(
			CATIScriptForm* iForm, 
			unsigned int& oIndex) = 0;

		/**
		 * Returns the position of the supplied form in the container.
		 */
		virtual HRESULT __stdcall FormIndex(
			const CATUnicodeString& iFormName, 
			unsigned int& oIndex) = 0;

		/**
		 * Returns the name of the index-th <tt>CATIScriptForm</tt> contained by the container.
		 * The first form has index 0.
		 */
		virtual HRESULT __stdcall GetFormName(
			unsigned int iIndex, 
			CATUnicodeString& oFormName) = 0;

		/**
		 * Returns the name of the index-th <tt>CATIScriptForm</tt> contained by the container.
		 * The first form has index 0.
		 */
		virtual HRESULT __stdcall GetFormName(
			CATIScriptForm* iForm, 
			CATUnicodeString& oFormName) = 0;

		/**
		 * Returns the index-th <tt>CATIScriptForm</tt> contained by the container.
		 * The first script has index 0.
		 */
		virtual HRESULT __stdcall GetForm(
			unsigned int iIndex, 
			CATIScriptForm*& oForm) = 0;

		/**
		 * Returns first occurence of <tt>CATIScriptForm</tt> contained by the container
		 * which matches the supplied name.
		 */
		virtual HRESULT __stdcall GetForm(
			const CATUnicodeString& iFormName, 
			CATIScriptForm*& oForm) = 0;

		/**
		 * Removes the index-th <tt>CATIScriptForm</tt> from the container.
		 * The first form has index 0.
		 */
		virtual HRESULT __stdcall RemoveForm(
			unsigned int iIndex) = 0;

		/**
		 * Renames the index-th <tt>CATIScriptForm</tt>.
		 * The first form has index 0. The supplied name
		 * must be a file name, not a file path (ie: no slash).
		 */
		virtual HRESULT __stdcall RenameForm(
			unsigned int iIndex, 
			const CATUnicodeString& iNewFormName) = 0;

		/**
		 * Returns true when the container has been closed and cannot be
		 * used any more.
		 */
		virtual HRESULT __stdcall IsZombied(
			CATBoolean& oZombied) = 0;
};

extern "C" const IID IID_CATIScriptFormContainer;

#endif
