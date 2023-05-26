#ifndef CATIMathMarshLSCArray_h
#define CATIMathMarshLSCArray_h 
// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2001
/** @level Protected
*  @usage U3 
*/

#include "CATBaseUnknown.h"
#include "CATMathDef.h"
#include "CATDataType.h"

class CATMathVector ;
class CATIMathMarshPPCArray;


/**
* Class representing scalar constraint for marshmallow.
*
* <br><b>Role</b>: Provide the basic class to define constraint like 
* <br> It is definied by some combination of scalar product.
* <br>      ->    ->     ->      
* <br> Sum  c  . (F(P) - V ) = 0
* <br>    i  ij   i    i
* <br> Where Pi and Vi are pinpointconstraint 's points and values.
* <br> F can be replaced by one differentiel form accordint to the derivatives order given by the pinpoints
*
* @see @href CATMathMarshSolver, @href CATIMathMarshPPCArray
*/
class CATIMathMarshLSCArray : public CATBaseUnknown
{
public :
/** 
	* Set a linear Scalar Constraint.
	*
	* <br><b>Role</b>: Define a linear scalar constraint.
	*
	* @param iIndex [in]
	*   The rank of the constrain in the array. (begin at 0)
	* @param iPPCArray [in]
	*   The pinpoint used in the constraint
	* @param iCoeffs [in]
	*   The Matrix of vector - coefficient of the constraint
	*
	* @return
	*   <code>S_OK</code> if everything ran ok, otherwise...
	*/
	 // iCoeffs est une matrice de Vector ranges par lignes
 //(i.e. par contrainte lineaire (iNbCST lignes de iPPCArray->Length() vecteurs)
	virtual HRESULT SetLSC(CATLONG32 iIndex,
							 CATIMathMarshPPCArray* iPPCArray,
							 CATMathVector* iCoeffs, // ranges par lignes (i.e. 
							 int iNbCST) = 0;

/** 
	* Acsess to the pinpoint constraints.
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
							CATIMathMarshPPCArray*& oPPC) = 0;


	/** 
	* Get the Tensor contraint.
	*
	* @param iIndex [in]
	*   The rank of the constrain in the array. (begin at 0)
	* @param oCoeffs [out]
	*   The vector 's matrix.
	*
	* @return
	*   <code>S_OK</code> if everything ran ok, otherwise...
	*
	*/
	virtual HRESULT GetCoeffs(CATLONG32 iIndex,
							  CATMathVector*& oCoeffs) const = 0;


	/** 
	* Get the number of scalar constraints at a gven rank.
	*
	* @param iIndex [in]
	*   The rank of the constrain in the array. (begin at 0)
	* @param oNbCST [out]
  *   the number of scalar constraints (ie the number of line in the vector 's matrix)
	*
	* @return
	*   <code>S_OK</code> if everything ran ok, otherwise...
	*/
	virtual HRESULT GetNbCST(CATLONG32 iIndex,
							  int &oNbCST) const = 0;

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

  virtual int NbLSC() const = 0;

};
#endif



