#ifndef _CATMathMarshExternFunction_H
#define _CATMathMarshExternFunction_H
// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2002
/** @level Private
*  @usage U5 
*/


#include "MathMarsh.h"
#include "CATMathDef.h"
#include "CATBoolean.h"
#include "CATMathStream.h"


/**
* Class representing external kernel function for Marshmallow .
*
* <br><b>Role</b>: define a function from IR to IR
*
* @see @href CATMathMarshSolver, @href CATMathMarshExternSolElem, CATMathMarshSolver#SolveTI, @href CreateCATMathMarshWuFunction, @href CreateCATMathMarshWedlandFunction
*/
class ExportedByMathMarsh  CATMathMarshExternFunction 
{

protected:
	virtual ~CATMathMarshExternFunction(){};

public:
  /**
	* Increments the reference count for the given interface. 
	*/
	virtual void SetCodeLevel(const short iCodeLevel) = 0;


	/**
	* Increments the reference count for the given interface. 
	*/
	virtual void AddRef() = 0;

  /**
	* Decrements the reference count for the given interface. 
	*/
  virtual void Release() = 0;


  virtual CATMathMarshExternFunction * Clone() = 0;

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
	virtual CATBoolean IsAKindOf(const char *Type) const=0;

	/** 
	* Function evaluator.
	*
	* <br><b>Role</b>: Compute the value of dnF / dn t (t).
	*
	* @param iR [in]
	*   The parameter where the function must be evaluate.
	* @param iOrderDerivative [in]
	*   The derive order wich the function must be evaluate.
	*
	* @return
	*   The evaluation value
	*
	*/
	virtual double EvaluateDerivative(const double &iR,int iOrderDerivative = 0 ) const = 0;

	/** 
	*  Order of polynomial Part of associate space
	*
	* <br><b>Role</b>: Define the order (degree+1) of the polynomial part of the associate space of solution.
	*
	*
	* @return
	*   The Polynomial order.
	*/
	virtual int GetPolOrder() const = 0;

	// 
	/** 
	* Get the square radius of compact interval.
	*
	* @return
	*   M  like f(R) == 0 if R*R >= M
	*
	*/
	virtual double CompactSquareRadius() const = 0;

	/** 
	* Get the radius of compact interval.
	*
	*
	* @return
	*   M  like f(R) == 0 if R >= M .
	*
	*/
	virtual double CompactRadius() const = 0;



  virtual void SetHasCache(CATBoolean iHascache)=0;
  virtual CATBoolean HasCache() const=0; 

	virtual CATBoolean Streamable()const =0;
	virtual void Stream( CATMathStream& ioStream )const  = 0;

  double EvaluateRootSquareDerivative(const double &iR,int iOrderDerivative = 0 ) const;

  virtual CATBoolean HaveMultiMonomialdefinition() const {return FALSE;}
  virtual double  GetMinRForMultinomial() const {return -666.;}
  virtual double GetCoefMonom(const int iOrder) const {return 0.0;}
};

// 
/** 
* To buil kernel function of type Wu
*
* @param il [in]
*   L parameter must be betwent 2 or 3
* @param iLambda [in]
*   Normalization Coefficient
* @param ik [in]
*   K parameter must be equal to
*<li> 0 if 2=L
*<li> 0,1 or2 if 3=L
*
* @return
*   A compact kernel function (of Wu type.).
*/
ExportedByMathMarsh CATMathMarshExternFunction * CreateCATMathMarshWuFunction(const short il, const double iLambda=1.0,
																																					    const short ik=0);

// functions for building implementation of type Wedland
/** 
*		To build function of type Wedland.
*
* @param il [in]
*   The L parameter, must be uper or equal to 2
* @param iLambda [in]
*   Normalization Coefficient
* @param ik [in]
*   The K parameter.
*
* @return
*   Explain return values
*
*/
ExportedByMathMarsh CATMathMarshExternFunction * CreateCATMathMarshWedlandFunction(const short il, const double iLambda=1.0,
																																					         const short ik=2);

//// functions for building implementation of type spheroidal
///** 
//
//*/
//ExportedByMathMarsh CATMathMarshExternFunction * CreateCATMathMarshSpheroidalFunction(const double iRangeValue, const double iMaxValue=1.0, const double iMinValue=0.0,
//																																					            const short iAlpha=3);
//
//ExportedByMathMarsh CATMathMarshExternFunction * CreateCATMathMarshPartialApproximation(const double iRMin, const double iRMax,
//  const CATMathMarshExternFunction * iESE);

ExportedByMathMarsh CATMathMarshExternFunction * CreateCATMathMarshAsymptoticFunction(const double iCParameter);
  
  

ExportedByMathMarsh CATMathMarshExternFunction * CreateCATMathMarshExternFunction(CATMathStream& ioReadStream);



#endif
