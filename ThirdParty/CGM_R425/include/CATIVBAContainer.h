#ifndef CATIVBAContainer_h
#define CATIVBAContainer_h

#include "CATVBACodeMacro.h"
#if defined(_WINDOWS_SOURCE) && (!defined(_DS_VBAIntegrationIsOutProcess)) // -JBX 3.2012 VBA7 Migration 


// COPYRIGHT DASSAULT SYSTEMES 2005

#include "VBAAfx.h"
#include "IUnknown.h"
#include "CATBoolean.h"

class CATIVBAProgram;
class CATIVBAForm;

/**
 * Interface used to manage VBA container.
 */
class CATIVBAContainer : public IUnknown {

	public:

		/**
		 * Retrieves the VBA container name.
		 */
		virtual HRESULT GetName(CString& oName) = 0;

		/**
		 * Returns true is the container is read-only, false otherwise
		 */
		virtual HRESULT IsReadOnly(
			CATBoolean& oReadOnly) = 0;

		/**
		 * Returns the number of VBA programs contained in the container.
		 */
		virtual HRESULT ProgramCount(
			unsigned int& oCount) = 0;

		/**
		 * Returns the name of the index-th VBA program contained by the container.
		 * The first VBA program has index 0.
		 */
		virtual HRESULT GetScriptProgramName(
				unsigned int iIndex, 
				CString& oScriptName) = 0;

		/**
		 * Returns the index-th <tt>CATIVBAProgram</tt> contained by the container.
		 * The first script has index 0.
		 */
		virtual HRESULT GetScriptProgram(
			unsigned int iIndex, 
			CATIVBAProgram*& oProgram) = 0;

		/**
		 * Returns first occurence of <tt>CATIVBAProgram</tt> contained by the container
		 * which matches the supplied name.
		 */
		virtual HRESULT GetScriptProgram(
			const CString& iScriptName, 
			CATIVBAProgram*& oProgram) = 0;
			
		/**
		 * Removes the index-th VBA program from the container.
		 * The first VBA program has index 0.
		 */
		virtual HRESULT RemoveScriptProgram(
			unsigned int iIndex) = 0;

		/**
		 * Renames the index-th VBA program.
		 * The first VBA program has index 0. The supplied name
		 * must be a file name, not a file path (ie: no slash).
		 */
		virtual HRESULT RenameScriptProgram(
			unsigned int iIndex, 
			const CString& iNewScriptName) = 0;

		/** 
		 * Creates a new <tt>CATIVBAProgram</tt> in the container.
		 */
		virtual HRESULT CreateScriptProgram(
			const CString& iScriptName,
			CATIVBAProgram*& oProgram) = 0;

		/**
		 * Save the VBA container.
		 */
		virtual HRESULT Save() = 0;

		/**
		 * Returns true when the container has been closed and cannot be
		 * used any more.
		 */
		virtual HRESULT IsZombied(
			CATBoolean& oZombied) = 0;

		/**
		 * Sets the VBA container zombied.
		 */
		virtual HRESULT SetZombied(
			CATBoolean iZombied) = 0;
		
		/**
		 * Returns the number of forms contained in the container.
		 */
		virtual HRESULT FormCount(
			unsigned int& oCount) = 0;

		/**
		 * Returns the name of the index-th form contained by the container.
		 * The first form has index 0.
		 */
		virtual HRESULT GetFormName(
			unsigned int iIndex, 
			CString& oFormName) = 0;

		/**
		 * Returns the index-th form contained by the container.
		 * The first script has index 0.
		 */
		virtual HRESULT GetForm(
			unsigned int iIndex, 
			CATIVBAForm*& oForm) = 0;

		/**
		 * Returns first occurence of form contained by the container
		 * which matches the supplied name.
		 */
		virtual HRESULT GetForm(
			const CString& iFormName, 
			CATIVBAForm*& oForm) = 0;

		/**
		 * Removes the index-th form from the container.
		 * The first form has index 0.
		 */
		virtual HRESULT RemoveForm(
			unsigned int iIndex) = 0;

		/**
		 * Renames the index-th form.
		 * The first form has index 0. The supplied name
		 * must be a file name, not a file path (ie: no slash).
		 */
		virtual HRESULT RenameForm(
			unsigned int iIndex, 
			const CString& iNewFormName) = 0;

                /**
		 * Returns true is the container is dirty, false otherwise
		 */
		virtual HRESULT IsDirty(
			CATBoolean& oIsDirty) = 0;

};

extern "C" const IID IID_CATIVBAContainer;

#endif // #if defined(_WINDOWS_SOURCE) && (!defined(_DS_VBAIntegrationIsOutProcess)) // -JBX 3.2012 VBA7 Migration 
#endif // CATIVBAContainer_h
