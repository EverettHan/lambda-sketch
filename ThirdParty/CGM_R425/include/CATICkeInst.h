#ifndef CATICkeInst_h
#define CATICkeInst_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/** 
 * @CAA2Level L1
 * @CAA2Usage U3 
 */

/*  CAA2Reviewed by FRH */

// module declaration
#include "CATLifSpecs.h"

#include "CATBaseUnknown.h"
#include "CATICkeForwards.h"
#include "CATTime.h"

// OLE iid 
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATLifSpecs IID_CATICkeInst;
#else
extern "C" const IID IID_CATICkeInst;
#endif

/**   
 * Interface dedicated to the management of parameters (to read its content).
 * A parameter may be a literal, a volatile value, a list feature or a volatile list, a geometric datum, or a reference to V5 object.<br>
 * Interface similar to CATIValue. But it is not implemented on objects that implements CATICkeParm.<br>
 * Such an interface is returned by @href CATICkeParm#Value method.<br><br>
 * This interface is multi implemented. 
 * @see CATIValue, CATICkeParm.
 */
class CATTime;
//-----------------------------------------------------------------------------
class ExportedByCATLifSpecs CATICkeInst : public CATBaseUnknown
{

public :

/**
 * Returns way of seeing the content of a parameter. To be used when showing a content to a end-user.
 * (example : "3mm").
 */
virtual CATUnicodeString  Show    () const =0; 

/**
 * Returns the type of the parameter.
 * (example : Integer, Angle, etc...) <br>
 */
virtual CATICkeType_var Type    () const =0;



/**
 * Converts the content to an integer.<br> 
 *               enum values  (including booleans) returns rank<br>
 *               real values returns their value converted in integer<br>
 *               integer values return value
 * @return the value converted as an integer
 */
virtual int AsInteger () const =0;

/**
 * Converts the content to a double.<br>
 *               enum values  (including booleans) returns rank<br>
 *               real values and integer return their value <br>
 *               dimensions return their value IN SI units !!!!!
 * @return the value converted as a real value
 */
virtual double AsReal    () const =0;

/**
 * Converts the content to a string.<br>
 *               string values return their value<br>
 *               enum types (including booleans) values return their value
 * @return the value converted as a string
 */
virtual CATUnicodeString    AsString  () const =0;

/**
 * Converts the content to a boolean (for boolean values only).
 * @return the value converted as a boolean
 */
virtual CATCke::Boolean   AsBoolean () const =0;

/**
* Converts the content to a CATTime date (for date values only).
* @return the value converted as a CATTime
*/
virtual CATTime   AsDate () const =0;

/**
 * Compares two parameters from their content.
 * (taking tolerance (epsilon) into account
 * @param   iValue value to be compared
 * @return <b>Legal values</b>:
 * <tt>CATCke::True</tt> if comparison Ok.
 * <tt>CATCke::False</tt> if comparison Ko.
 */
virtual CATCke::Boolean  Compare (const CATICkeInst_var &iValue) const = 0;

/**
 * Converts the value to an object reference.
 * Works for reference to V5 objects: returns the object.<br>
 * Works also for lists: returns the list object.<br>
 * Works for geometric datum: returns the geometric datum itself.<br>
 * @return the value converted as an object
 */
virtual CATBaseUnknown_var   AsObject () const =0;

/**
 * Returns value as it is stored in the model.
 * Only for dimensions values.
 * @return the value converted as a double, as stored in the model
 */
virtual double   AsStored () const =0;

private:
  
  // 2 define ClassName
  CATDeclareInterface;

}; 

CATDeclareHandler(CATICkeInst, CATBaseUnknown);

#endif
