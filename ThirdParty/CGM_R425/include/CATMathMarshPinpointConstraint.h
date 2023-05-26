#ifndef _CATMathMarshPinpointConstraint_HeaderFile
#define _CATMathMarshPinpointConstraint_HeaderFile
// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2000
/** @level Protected
*  @usage U1
*/




#include "MathMarsh.h"

#include "CATMathVector.h"


/**
* Class representing a punctual constraint for MarshMallow
*
* <br><b>Role</b>: Define a constraint for the MarshMallow solver
* <p>
*
* @example
*  // G0 example
*<br>  CATMathVector P1(x1,y1,z1), P2(x2,y2,z2);
*<br>  CATMathMarshPinpointConstraint ppc1(P1, P2);
*<br>  // ppc1 force a translation of P1 to P2 in the deformation
*<br>  // the F(P1) = P2-P1 where F is the Marshmallow's result function 
*
* @see @href CATMathMarshSolver, @href CATIMathMarshPPCArray
*/
class ExportedByMathMarsh CATMathMarshPinpointConstraint  
{

public:

	// Methodes PUBLIC
/** 
	* default PinPointConstraint Builder.
	*
	* <br><b>Role</b>: Define G0 fixe constraint in (0 ,0, 0).
	*/ 
	CATMathMarshPinpointConstraint();


	/** 
	* PinPointConstraint Builder.
	*
	* <br><b>Role</b>: Define the constraint.
	*
	* @param point [inout]
	*   The 3D point where the constraint is defined.
	* @param ImposedValue [inout]
	*   The target imposed by the target.
	* @param ix [in]
	*   Order derivative along the X direction.
	* @param iy [in]
	*   Order derivative along the Y direction.
	* @param iz [in]
	*   Order derivative along the Z direction.
	*/
	CATMathMarshPinpointConstraint(const CATMathVector &point,
								   const CATMathVector &ImposedValue,
								   const int ix = 0,
								   const int iy = 0,
								   const int iz = 0);


	/** 
	* Get the pinpoint's point.
	* <br><b>Role</b>: Localize the pinpoint.
	*
	*
	* @return
	*   The point where the pinpoint is defined.
	*/
	inline const CATMathVector &Pnt() const;

	inline CATMathPoint PntConverted() const;

	/** 
	* Derivative order in X-direction.
	*
	* <br><b>Role</b>: Information on derivative order.
	*
	* @return
	*   the derivative order of the constraint (in X-directon).
	*/
	inline int Idx() const;

	/** 
	* Derivative order in Y-direction.
	*
	* <br><b>Role</b>: Information on derivative order
	*
	* @return
	*   the derivative order of the constraint (in Y-directon)
	*/
	inline int Idy() const;

	/** 
	* Derivative order in Z-direction.
	*
	* <br><b>Role</b>: Information on derivative order
	*
	* @return
	*   the derivative order of the constraint (in Z-directon)
	*/
	inline int Idz() const;	


	/** 
	* Get the target.
	*
	* <br><b>Role</b>: Get the constraint's target value.
	*
	* @return
	*   The target vector.
	*/
	inline const CATMathVector &Value() const;

	/** 
	* Get and modify the pinpoint's point.
	*
	* <br><b>Role</b>:  To modify the pinpoint localization.
	*
	*
	* @return
	*  A reference to the pinpoint 's point.
	*/
	inline CATMathVector &ChangePnt() ;

/** 
	* Get and modify the pinpoint's value.
	*
	* <br><b>Role</b>:  To modify pinpoint's target.
	*
	* @return
	*  A reference to the pinpoint's value.
	*/
	inline CATMathVector &ChangeValue();



private: 
	// Champs PRIVATE
	CATMathVector value;
	CATMathVector pnt;
	unsigned int idx:2; // 0,1,2,3 !
	unsigned int idy:2;
	unsigned int idz:2;
};



inline  const CATMathVector& CATMathMarshPinpointConstraint::Pnt() const
{
	return pnt;
}

inline CATMathPoint CATMathMarshPinpointConstraint::PntConverted() const
{
	return CATMathPoint(pnt.GetX(), pnt.GetY(), pnt.GetZ());
}

 
inline  int CATMathMarshPinpointConstraint::Idx() const
{
	return idx;
}

 
inline  int CATMathMarshPinpointConstraint::Idy() const
{
	return idy;
}


inline  int CATMathMarshPinpointConstraint::Idz() const
{
	return idz;
}

inline  const CATMathVector& CATMathMarshPinpointConstraint::Value() const
{
	return value;
}


#ifdef MArsh_Modif
inline  int& CATMathMarshPinpointConstraint::ChangeIdx()
{
	return idx;
}

 
inline  int& CATMathMarshPinpointConstraint::ChangeIdy()
{
	return idy;
}

 
inline  int& CATMathMarshPinpointConstraint::ChangeIdz()
{
	return idz;
}
#endif

inline  CATMathVector& CATMathMarshPinpointConstraint::ChangePnt()
{
	return pnt;
}

inline  CATMathVector& CATMathMarshPinpointConstraint::ChangeValue()
{
	return value;
}

#endif
