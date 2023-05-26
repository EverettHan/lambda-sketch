#ifndef CATIValue_h
#define CATIValue_h

// COPYRIGHT DASSAULT SYSTEMES 2000

/** 
* @CAA2Level L1
* @CAA2Usage U3
*/
 
/*  CAA2Reviewed by FRH */

//System 
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATTime.h"

// load module
#include "CATLifSpecs.h"

// OLE IID
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATLifSpecs IID_CATIValue;
#else
extern "C" const IID IID_CATIValue;
#endif

class CATIValue_var;

/**
 * Interface dedicated to the management of parameters (to read its content).
 * Interface similar to CATICkeInst.
 * This interface is multi implemented on literal, volatile values, list feature and volatile list, geometric datum, and reference to V5 object.
 * Those objects also implement CATICkeParm
 * @see CATICkeInst, CATICkeParm.
 */

class CATTime;

class ExportedByCATLifSpecs CATIValue : public CATBaseUnknown
{
public :
	/**
	* Returns the status of the content.
	*
 	* @return TRUE if the content is set, else FALSE.
	*/
	virtual boolean GetIsSet () const = 0;
	
	/**
 	* Unsets the content.
	*/
	virtual void  Unset ()  = 0;  
	
	/**
 	* Returns the writability of the content.
	*
	* @return TRUE is read-only, else FALSE.
	*/
	virtual boolean GetReadOnly () const = 0;
	
	/**
 	* Sets the writability of the content.
	*
	* @param iReadOnly TRUE to set read-only, FALSE to set the value writable.
	*/
	virtual void    SetReadOnly (const boolean iReadOnly ) = 0; 
	
	/**
 	* Returns the constantness of the content.
	*
	* @return TRUE if constant, else FALSE.
	*/
	virtual boolean GetConst () const = 0;
	
	/**
 	* Sets the constantness of the content.
	*
	* @param iConst TRUE to set to constant, else FALSE.
	*/
	virtual void    SetConst (const boolean iConst) = 0; 
	
	/**
    * Returns a string showing the content (example : "3mm").
	*
	* @return a string.
	*/
	virtual CATUnicodeString  Show    () const =0; 

	/**
    * Converts the content to an integer.
	*
	* Works on integer values.<br>
	* For enum values (including booleans), it returns the rank.<br>
	* For real values, it converts their value to the nearest lower integer.<br>
	* @return value converted as an integer
	*/
	virtual int AsInteger () const =0;

	/**
	* Converts the content to an integer.
	* Works on integer values.<br>
	* For enum values (including booleans), it returns the rank.<br>
	* For real values, it converts their value to the nearest lower integer.<br>
	* @param oValue value converted as an integer
	* @return classic HRESULT
	*/
	virtual HRESULT AsInteger (int& oValue) const =0;

	/**
	* Converts the content to a double.
	* Works on real values.<br>
	* For enum values (including booleans), it returns the rank.<br>
	* For dimensions, it returns their value in MKS system !
	* @return value converted as a real
	*/
	virtual double AsReal    () const =0;
	
    /**
	* Converts the content to a double.
	* Works on real values.<br>
	* For enum values (including booleans), it returns the rank.<br>
	* For dimensions, it returns their value in MKS system !
	* @param oValue value converted as an integer
	* @return classic HRESULT
	*/
	virtual HRESULT AsReal    (double& oValue) const =0;

	/**
	* Converts the content to a string.
	* Works on string values.<br>
	* For enum types (including booleans), it returns the string corresponding to the rank.
	* @return value converted as a string
	*/
	virtual CATUnicodeString    AsString  () const =0;

	/**
	* Converts the content to a string.
	* Works on string values.<br>
	* For enum types (including booleans), it returns the string corresponding to the rank.
	* @param oValue value converted as a string
	* @return classic HRESULT
	*/
	virtual HRESULT    AsString  (CATUnicodeString& oValue) const =0;

	/**
	* Converts the content to a boolean.
	* for boolean values only.
	* @return value converted as a string
	*/
	virtual boolean   AsBoolean () const =0;

	/**
	* Converts the content to a boolean (for boolean values only).
	* for boolean values only.
	* @param oValue value converted as a boolean
	* @return classic HRESULT
	*/
	virtual HRESULT   AsBoolean (boolean& oValue) const =0;

	/**
	* Return the content as a CATTime date (for date values only).
	* @param oValue value as a date
	* @return classic HRESULT
	*/
	virtual HRESULT   AsDate (CATTime& oValue) const =0;

	/**
	* Converts the content to a CATTime date (for date values only).
	* @return value value as a date
	*/
	virtual CATTime   AsDate () const =0;

	/**
	* Converts the content to an object reference.
	* Works for reference to V5 objects: returns the object.<br>
	* Works also for lists: returns the list object.<br>
	* Works for geometric datum: returns the geometric datum itself.<br>
	* @return value converted as an object
	*/
	virtual CATBaseUnknown_var   AsObject () const =0;
	
	/**
	* Converts the value to an object reference.
	* Works for reference to V5 objects: returns the object.<br>
	* Works also for lists: returns the list object.<br>
	* Works for geometric datum: returns the geometric datum itself.<br>
	* @param oValue value converted as an object
	* @return classic HRESULT
	*/
    virtual HRESULT   AsObject (CATBaseUnknown_var& oValue) const =0;


	/**
	* Compares two values (taking tolerance into account for numerical values).
	* @param iValue Value to be compared to the current one.
	* @return TRUE if equal, else FALSE.
	*/
	virtual boolean  Compare (const CATIValue_var &iValue) const = 0;

private:
  CATDeclareInterface;
}; 

CATDeclareHandler(CATIValue, CATBaseUnknown);

#endif
