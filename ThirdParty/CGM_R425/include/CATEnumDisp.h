#ifndef CATEnumDisp_h
#define CATEnumDisp_h

// COPYRIGHT DASSAULT SYSTEMES 2002

// System framework
#include "CATBaseUnknown.h"
#include "CATListPV.h"
#include "CATVariant.h"
#include "IEnumVARIANT.h"
#include "JS0COL.h"

/**
 * Utility class to help implement the get__NewEnum method
 * in Automation collections.
 * <b>Role</b>:
 * This class implements the IEnumVARIANT interface which
 * is used in VB in the <tt>ForEach</tt> construct to traverse
 * collections of objects.
 * @author Jean-Francois DOUE (JDU)
 */

class ExportedByJS0COL CATEnumDisp : public CATBaseUnknown {
	public:
		CATDeclareClass;

		/** @nodoc */ 
		CATEnumDisp(
			IUnknown **iElementArray, 
			const IID & iElementType, 
			unsigned long iArraySize,
			unsigned long iUnusedFlagForCompatibility = 0);

		/**
		 * Destructor.
		 */
		virtual ~CATEnumDisp();

		// Implementation of the IEnumVARIANT interface
		/** @nodoc */ 
 		virtual HRESULT  __stdcall Next(
			ULONG iCelt, 
			CATVariant *oNextCelts,
			ULONG * oCeltFetched);
		/** @nodoc */ 
		virtual HRESULT  __stdcall Skip(
			ULONG iCelt);
		/** @nodoc */ 
		virtual HRESULT  __stdcall Reset();
		/** @nodoc */ 
		virtual HRESULT  __stdcall Clone(
			IEnumVARIANT ** oEnum);

	protected:
		CATListPV	_objects;
		int			_index;
		GUID		_objectType;

};

#endif // CATEnumDisp_h
