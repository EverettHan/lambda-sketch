#ifndef _CATMathMarshExternSolElem_H
#define _CATMathMarshExternSolElem_H
// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2002
/** @level Private
*  @usage U2
*/




#include "MathMarsh.h"
#include "CATMathDef.h"
#include "CATMathMarshExternFunction.h"
#include "CATBoolean.h"



/**
* Class representing kernel function for multi-energy optimization.
*
* <br><b>Role</b>: Define some kind of multi-energy model and provide associate function.
*  
*/
class ExportedByMathMarsh  CATMathMarshExternSolElem : public CATMathMarshExternFunction
{

public:
/**
 * Multi-Energy type for marshmallow.
 * @param E1plus2plus3
 *   Mix of energy of order 1 , 2 and 3
 * @param E1plus2plus4
 *   Mix of energy of order 1,2 and 4
 * @param E1plus3plus4
 *   Mix of energy of order 1 , 3 and 4
 * @param E1plus2plus4
 *   Mix of energy of order 1 , 2, 3 and 4
 * @param E1plus3
 *   Mix of energy of order 1  and 3
 * @param E1plus4
 *   Mix of energy of order 1  and 4
 * @param E2plus3
 *   Mix of energy of order 2  and 3
 * @param E2plus3plus4
 *   Mix of energy of order 2,3  and 4
 * @param E2plus4
 *   Mix of energy of order 2  and 4
 * @param E3plus4
 *   Mix of energy of order 3  and 4
 * @param E1plus2
 *   Mix of energy of order 1  and 2
 */
  //  **************  WARNING This enum is streamed NEVER CHANGE THE ORDER  ****************
	enum TypeEnergy {UNKNOWN, MONOMIAL, E3, E4,  E0plus3, E0plus4, E1plus2plus3, E1plus2plus4, E1plus3plus4, E1plus2plus3plus4, 
		               E1plus3, E1plus4, E2plus3, E2plus3plus4, E2plus4, E3plus4, E1plus2};
	// Methodes PUBLIC

	virtual ~CATMathMarshExternSolElem(){};
	//
	//virtual int GetPolOrder()  const = 0;

	/**
	* Determines whether the given object's class derives from a given class.
	* @param iName
	*   The class name from which the given object's class is supposed to derive.
	* @return 0 if the given object's class doesn't derive from <tt>iName</tt>
	* and a non null value otherwise.
	* @return
	* <br><b>Legal values</b>:
	*   <dl>
	*     <dt> FALSE </dt>
	*        <dd>Current onject does not derive from iName.</dd>
	*     <dt> TRUE </dt>
	*        <dd>Otherwise.</dd>
	*   </dl>
	*/
	virtual CATBoolean IsAKindOf(const char *Type) const;

	//virtual double EvaluateDerivative(const double &iR,int iOrderDerivative = 0 ) const = 0;
	//
	/** 
	* Set a kind of energy.
	*
	* <br><b>Role</b>: Choose the mix of enrgy to use.
	*
	* @param TE [in]
	*   The kind of energy .
	*/
	virtual void SetTypeEnergy(const  TypeEnergy TE)=0;

	/*
	* Define a codelevel 
  * Do nothing !!
	*/
	void SetCodeLevel(const short iCodeLevel) {};

  virtual int SetMultiQuadC(const double iC);

	/** 
	* Get a kind of energy.
	*
	* @return
	*   The kind of energy .
	*/
	virtual const TypeEnergy GetTypeEnergy() const=0;



	/** 
	* Display the kind of energy.
	*
	* <br><b>Role</b>: For debug purpose, it print the name of energy.
	*
	* @param iType [in]
	*   The kind of energy to display.
	*
	*/
	static void DumpType(const TypeEnergy iType);
protected:
	static const TypeEnergy CastToEnergyType(CATLONG32 LVar);
};

// functions for building implementation of type PWP (PieceWise Polynomial)
/**
* @level Private
*/
ExportedByMathMarsh CATMathMarshExternSolElem * CreateCATMathMarshExternSolElemPWP(const int degree,
								const int NbArcs, int PolOrder);
// for test purpose
//ExportedByMathMarsh CATMathMarshExternSolElem * CreateCATMathMarshMonomialExternSolElemPWP(const int iOrder);
/**
* @level Private
*/
ExportedByMathMarsh double *GetKnotsCATMathMarshExternSolElemPWP(CATMathMarshExternSolElem * ESE);
/**
* @level Private
*/
ExportedByMathMarsh double *GetCoefPolCATMathMarshExternSolElemPWP(CATMathMarshExternSolElem * ESE);
/**
* @level Private
*/
ExportedByMathMarsh double *GetShiftPolCATMathMarshExternSolElemPWP(CATMathMarshExternSolElem * ESE);

#endif
