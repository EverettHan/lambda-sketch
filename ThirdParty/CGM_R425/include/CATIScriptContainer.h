#ifndef CATIScriptContainer_h
#define CATIScriptContainer_h

// COPYRIGHT DASSAULT SYSTEMES 2015

#include "IUnknown.h"
#include "CATUnicodeString.h"
#include "CATIScriptProgram.h"
#include "CATScriptLanguage.h"
#include "CATSetOfCATUnicodeString.h"
#include "CATListOfCATIScriptProgram.h"
#include "CATVariant.h"

class CATScriptRef;

/**
 * Interface for script containers. Depending on the implementation, containers
 * can contain zero, one or several <tt>CATIScriptPrograms</tt>. Containers
 * can support one or many scripting languages.
 * Each <tt>CATIScriptPrograms</tt> is identified by a name unique to the container.
 * @author: Jean-Francois Doue (JDU)
 */
class CATIScriptContainer : public IUnknown {
	public:

		/**
		 * Returns the container name.
		 */
		virtual HRESULT __stdcall GetName(
			CATUnicodeString& oContainerName) = 0;

		/**
		 * Returns the expanded container name.
		 * The container name can indeed contain environment variables (ie ${myDir}\subDir).
		 */
		virtual HRESULT __stdcall GetExpandedName(
			CATUnicodeString& oExpandedContainerName) = 0;

		/**
		 * Returns the display container name.
		 * If the expanded name of the container is different from its name, the display name consists in :
		 * "<name> (<expandedName>)", otherwise it consists in its name.
		 */
		virtual HRESULT __stdcall GetDisplayName(
			CATUnicodeString& oDisplayContainerName) = 0;

		/**
		 * Returns true is the container is read-only, false otherwise
		 */
		virtual HRESULT __stdcall IsReadOnly(
			CATBoolean& oReadOnly) = 0;

		/**
		 * Returns the number of ScriptPrograms contained in the container.
		 */
		virtual HRESULT __stdcall ProgramCount(
			unsigned int& oCount) = 0;

		/**
		 * Returns the position of the supplied program in the container.
		 */
		virtual HRESULT __stdcall ProgramIndex(
			CATIScriptProgram* iProgram, 
			unsigned int& oIndex) = 0;

		/**
		 * Returns the position of the supplied program in the container.
		 */
		virtual HRESULT __stdcall ProgramIndex(
			const CATUnicodeString& iScriptName, 
			unsigned int& oIndex) = 0;

		/**
		 * Returns the name of the index-th <tt>CATIScriptProgram</tt> contained by the container.
		 * The first script has index 0.
		 */
		virtual HRESULT __stdcall GetScriptProgramName(
			unsigned int iIndex, 
			CATUnicodeString& oScriptName) = 0;

		/**
		 * Returns the name of the index-th <tt>CATIScriptProgram</tt> contained by the container.
		 * The first script has index 0.
		 */
		virtual HRESULT __stdcall GetScriptProgramName(
			CATIScriptProgram* iProgram, 
			CATUnicodeString& oScriptName) = 0;

		/**
		 * Returns the index-th <tt>CATIScriptProgram</tt> contained by the container.
		 * The first script has index 0.
         * @deprecated R418 Use GetScriptPrograms instead.
		 */
		virtual HRESULT __stdcall GetScriptProgram(
			unsigned int iIndex, 
			CATIScriptProgram*& oProgram) = 0;

		/**
		 * Returns first occurence of <tt>CATIScriptProgram</tt> contained by the container
		 * which matches the supplied name.
		 */
		virtual HRESULT __stdcall GetScriptProgram(
			const CATUnicodeString& iScriptName, 
			CATIScriptProgram*& oProgram) = 0;

		/**
		 * Removes the index-th <tt>CATIScriptProgram</tt> from the container.
		 * The first script has index 0.
         * Returns S_FALSE if the method has succeeded but the modified container cannot be saved (e.g. in database)
		 */
		virtual HRESULT __stdcall RemoveScriptProgram(
			unsigned int iIndex) = 0;

		/**
		 * Renames the index-th <tt>CATIScriptProgram</tt>.
		 * The first script has index 0. The supplied name
		 * must be a file name, not a file path (ie: no slash).
         * Returns S_FALSE if the method has succeeded but the modified container cannot be saved (e.g. in database)
		 */
		virtual HRESULT __stdcall RenameScriptProgram(
			unsigned int iIndex, 
			const CATUnicodeString & iNewScriptName) = 0;

		/**
		 * Creates a new <tt>CATIScriptProgram</tt> in the container.
         * Returns S_FALSE if the method has succeeded but the modified container cannot be saved (e.g. in database)
		 */
		virtual HRESULT __stdcall CreateScriptProgram(
			const CATUnicodeString& iScriptName,
			CATScriptLanguage iLanguage,
			CATIScriptProgram*& oProgram) = 0;

		/**
		 * Returns the list of scripting languages supported by the
		 * container.
		 */
		virtual HRESULT __stdcall GetSupportedLanguages(
			CATSetOfCATUnicodeString& oSet) = 0;

		/**
		 * Sets the script text for the program at the supplied
		 * index.
         * Returns S_FALSE if the method has succeeded but the modified container cannot be saved (e.g. in database)
		 */
		virtual HRESULT __stdcall SetScriptProgramText(
			unsigned int iIndex,
			const CATUnicodeString & iScriptText
			) = 0;

		/**
		 * Returns true when the container has been closed and cannot be
		 * used any more.
		 */
		virtual HRESULT __stdcall IsZombied(
			CATBoolean& oZombied) = 0;

		/**
		 * Returns a new macro name which can be used to
		 * create a new macro with the supplied language
		 * in the container.
		 */
		virtual HRESULT __stdcall NewMacroName(
			CATScriptLanguage iLanguage,
			CATUnicodeString& oMacroName) = 0;

		/**
		 * Returns a reference object which identifies the container.
		 */
		virtual HRESULT __stdcall GetReference(
			CATScriptRef*& oReference) = 0;

		/**
		 * Refresh the contents of the container.
		 */
		virtual HRESULT __stdcall Refresh() = 0;
        
        /**
		 * Returns a list of <tt>CATIScriptProgram</tt> references to programs contained by the container.
		 */
        virtual HRESULT __stdcall GetScriptPrograms(CATListOfCATIScriptProgram& oProgramList) = 0;
};

extern "C" const IID IID_CATIScriptContainer;

#endif // CATIScriptContainer_h
