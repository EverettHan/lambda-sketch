#ifndef CATIMathMarshLXYZCArray_h
#define CATIMathMarshLXYZCArray_h 

/// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2000
/** @level Protected
*  @usage U3 
*/

#include "CATBaseUnknown.h"
#include "CATMathDef.h"
#include "CATDataType.h"

class CATMathMxNFullMatrix ;
class CATIMathMarshPPCArray;


/**
* Class representing linear (vectorial) combination of pinpoint constraints.
*
* <br><b>Role</b>: Provide the basic class constriant like
* <br> It is definied by some linear combination of vector.
* <br>         ->     ->
* <br> Sum  c (F(P) - V ) = 0
* <br>    i  ij    i    i
* <br> Where Pi and Vi are pinpointconstraint 's points and values.
* <br> F can be replaced by one differentiel form accordint to the derivatives order given by the pinpoints.
* @see @href CATMathMarshSolver, @href CATIMathMarshPPCArray
*/
class CATIMathMarshLXYZCArray : public CATBaseUnknown
{
public :
	/** 
	* Set a linear XYZ Constraint
	*
	* <br><b>Role</b>: Define a vectorial constraint.
	*
	* @param iIndex [in]
	*   The rank of the constrain in the array. (begin at 0)
	* @param iPPCArray [in]
	*   The pinpoint used in the constraint
	* @param iCoeffs [in]
	*   The Matrix - coefficient of the constraint
	*   The Number of ROW = The number of equation
	*		The Number 0f COL Must be equal to the iPPCArray length
	*
	* @return
	*   <code>S_OK</code> if everything ran ok, otherwise...
	*
	*/
	virtual HRESULT SetLXYZC(CATLONG32 iIndex,
							 CATIMathMarshPPCArray* iPPCArray,
							 CATMathMxNFullMatrix& iCoeffs) = 0;

	/** 
	* Acsess to the pinpoint constraints
	*
	* <br><b>Role</b>: To read and modify the punctual constarints
	*
	* @param iIndex [in]
	*   The rank of the constrain in the array. (begin at 0)
	* @param oPPCArray [out]
	*   The array of pinpoint constraint 
	*
	* @return
	*   <code>S_OK</code> if everything ran ok, otherwise...
	*
	*/
	virtual HRESULT GetPPCs(CATLONG32 iIndex,
							CATIMathMarshPPCArray*& oPPCArray) = 0;


	/** 
	* Get the combination's coefficient of one linear XYZ.
	*
	* <br><b>Role</b>: 
	*   A utiliser comme Accesseur uniquement car le numero de version n'est pas mis a jour en cas de modification
	*
	* @param iIndex [in]
	*   The rank of the constrain in the array. (begin at 0)
	* @param oCoeffs [out]
	*   The matrix of coefficient.
	*
	* @return
	*   <code>S_OK</code> if everything ran ok, otherwise...
	*/
	virtual HRESULT GetCoeffs(CATLONG32 iIndex,
							  CATMathMxNFullMatrix*& oCoeffs) const = 0;

	/** 
	* Get the number of elements.
	*
	* <br><b>Role</b>: Count the number of linear constraints.
	*
	* @param oLength [out]
	*   The number of elements.
	*
	* @return
	*   <code>S_OK</code> if everything ran ok, otherwise...
	*/
	virtual HRESULT GetLength(CATLONG32& oLength) const = 0;


  virtual int NbLXYZC() const = 0;

};
#endif



