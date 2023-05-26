#ifndef CATIParmTolerance_h
#define CATIParmTolerance_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/** 
 * @CAA2Level L1
 * @CAA2Usage U3 
 */


/*  CAA2Reviewed by FRH */

// inherits from
#include <CATBaseUnknown.h>

// module definition
#include "CATLifSpecs.h"

// OLE iid
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATLifSpecs IID_CATIParmTolerance;
#else
extern "C" const IID IID_CATIParmTolerance;
#endif

/**   
 * Interface dedicated to tolerance management on real values.
 * <b>Role</b>: Minimum and maximum tolerance can be set on real (& dimensions) parameters.<br>
 * This interface is implemented on literal that also implement CATICkeParm.
 * @see CATICkeParm.
 */
class ExportedByCATLifSpecs CATIParmTolerance : public CATBaseUnknown
{
public:

	/**
	 * Sets the minimum tolerance value.
	 * @param  iValue 
	 *   minimum tolerance in model unit.
	 */
	virtual void SetMinimumTolerance( double iValue) = 0;

	/**
	 * Sets the maximum tolerance value.
	 * @param  iValue 
	 *    maximum, tolerance in model unit.
	 */
	virtual void SetMaximumTolerance( double iValue) = 0;

	/**
	 * Returns the minimum tolerance value.
     */
	virtual double GetMinimumTolerance() = 0;

	/**
	 * Returns the maximum tolerance value.
	 */
	virtual double GetMaximumTolerance() = 0;

	/**
	 * Checks the existence of the tolerance on a parameter.
	 * @return :
     * <br><b>Legal values</b>: the test can be either
     * <tt>1</tt> if there is a tolerance.
     * <tt>0</tt> if there isn't.
	 */
	virtual int Exist() = 0;

	/**
	 * Suppresses the tolerance on the parameter.
	 */
	virtual void Suppress() = 0;

private :
 	CATDeclareInterface;
}; 

CATDeclareHandler(CATIParmTolerance,CATBaseUnknown);

#endif



