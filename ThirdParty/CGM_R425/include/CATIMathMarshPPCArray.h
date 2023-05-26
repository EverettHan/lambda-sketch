#ifndef CATIMathMarshPPCArray_h
#define CATIMathMarshPPCArray_h

// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2000
/** @level Protected
*  @usage U3 
*/

#include "MathMarsh.h"

#include "CATBaseUnknown.h"
#include "CATMathDef.h"

class CATMathVector ;
class CATMathMarshPinpointConstraint;

/**
* Class representing an array of pinpoint constraint.
*
* <br><b>Role</b>: Provide a set of punctual constraint for marshmallow
* <br> - This can be an constraint for the marshmalow solver @href CATMathMarshSolver
* <br> - These constraints can be mixed with @href CATIMathMarshLXYZCArray or @href CATIMathMarshLSCArray
* <p>
* Do not use the @href CATIMathMarshPPCArray constructor to 
* do such and such but instead @href CreateMarshPPCArray .
*

* @see @href CATMathMarshPinpointConstraint, @href CATMathMarshBasicSolver
*/

class CATIMathMarshPPCArray : public CATBaseUnknown
{
public :
	
	/** 
	* Modify the target for one array element.
	*
	* <br><b>Role</b>: Define a new target for one pinpoint
	*    with this method we can generate quickly a family of marshMalow interpolation
	*    @see CATMathMarshBasicSolver#SolveTIagain
	*
	* @param iIndex [in]
	*   The Index of element to modify, must be in [0,.., N-1].
	* @param iValue [in]
	*   The new vector target.
	*
	* @return
	*   <code>S_OK</code> if everything ran ok, otherwise...
	*/
	virtual HRESULT SetPPCValue(const CATLONG32 iIndex, const CATMathVector& iValue) = 0;

	/** 
	* Modify  one array element.
	*
	* <br><b>Role</b>: Define a new  pinpoint
	*    with this method we can generate a family of marshMalow interpolation
	*    but it will be slower than with #SetPPCValue
	*
	* @param iIndex [in]
	*   The Index of element to modify, must be in [0,.., N-1].
	* @param iValue [in]
	*   The new pin point constraint.
	*
	* @return
	*   <code>S_OK</code> if everything ran ok, otherwise...
	*/
	virtual HRESULT SetPPC(const CATLONG32 iIndex, const CATMathMarshPinpointConstraint& iPPC) = 0;


	/** 
	*  Get one array element.
	*
	* <br><b>Role</b>: To decode the constraint
	*
	* @param iIndex [in]
	*   The rank of the element
	* @param oPPC [out]
	*   The pinpoint defined at rank <b>iIndex</b>.
	*
	* @return
	*   <code>S_OK</code> if everything ran ok, otherwise...
	*/
	virtual HRESULT GetPPC(const CATLONG32 iIndex, CATMathMarshPinpointConstraint*& oPPC)  const = 0;


	/** 
	* Get the number of elements.
	*
	* <br><b>Role</b>: Count the number of pinpoints.
	*
	* @param oLength [out]
	*   The number of elements.
	*
	* @return
	*   <code>S_OK</code> if everything ran ok, otherwise...
	*/
	virtual HRESULT GetLength(CATLONG32& oLength) const = 0;

  ExportedByMathMarsh static int NbPCC(CATIMathMarshPPCArray * iTabPPC);
};
#endif



