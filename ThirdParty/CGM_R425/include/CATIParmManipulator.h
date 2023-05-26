#ifndef CATIParmManipulator_h
#define CATIParmManipulator_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/** 
 * @CAA2Level L1
 * @CAA2Usage U3
 */

/*  CAA2Reviewed by FRH */


#include "CATLifSpecs.h"
#include "CATICkeRelationForwards.h"
#include "CATICkeMagnitude.h"
#include <CATBaseUnknown.h>
#include "CATListOfDouble.h"
#include "CATListOfCATUnicodeString.h"

// OLE
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATLifSpecs IID_CATIParmManipulator;
#else
extern "C" const IID IID_CATIParmManipulator;
#endif


/**   
 * Interface dedicated to parameters manipulator management.
 * <b>Role</b>: A manipulator is an object to be associated to one or several parameters.
 * with CATICkeParm::Setmanipulator (m) method
 * <p> 
 * It gathers informations about how the literal can be modified
 *   - range (min,max)
 * And it collects informations accessible in literals Spinner editors
 *   - step 
 *   - old steps
 *   - old values 
 * Double used in this interface are in Model unit if any (millimeter and degree)
 * <p>
 * It makes sense only on literal and volatile values.
 * @see CATICkeParm
 */
//-----------------------------------------------------------------------------
class ExportedByCATLifSpecs CATIParmManipulator : public CATBaseUnknown
{

  CATDeclareInterface;

public :


/**
 * Sets range values (min and max).
 *
 * @param iRmin minimum value in model unit
 * @param iBmin 0 if no minimum defined, 1 if defined and can be reached, 2 if defined and can not be reached, 3 if defined, can be reached and is not modifiable by the final user, 4 if defined, can not be reached and is not modifiable by the final user
 * @param iRmax maximum value in model unit
 * @param iBmax 0 if no maximum defined, 1 if defined and can be reached, 2 if defined and can not be reached, 3 if defined, can be reached and is not modifiable by the final user, 4 if defined, can not be reached and is not modifiable by the final user
 */
virtual void SetAccurateRange (const double iRmin,const int iBmin,
                               const double iRmax,const int iBmax) =0;
/**
 * Gets range values (min and max).
 *
 * @param oRmin minimum value in model unit
 * @param oBmin 0 if no minimum defined, 1 if defined and can be reached, 2 if defined and can not be reached, 3 if defined, can be reached and is not modifiable by the final user, 4 if defined, can not be reached and is not modifiable by the final user
 * @param oRmax maximum value in model unit
 * @param oBmax 0 if no maximum defined, 1 if defined and can be reached, 2 if defined and can not be reached, 3 if defined, can be reached and is not modifiable by the final user, 4 if defined, can not be reached and is not modifiable by the final user
 */
virtual void AccurateRange    (double &oRmin,int &oBmin,double &oRmax,int &oBmax) const =0;


/**
 * @nodoc - to be suppressed
 */
virtual void SetRange (const double rmin,const CATCke::Boolean bmin,
   const double rmax,const CATCke::Boolean bmax) =0;

/**
 * @nodoc deprecated to be suppressed
 */
virtual void Range    (double &rmin,CATCke::Boolean &bmin,double &rmax,CATCke::Boolean &bmax) const =0;


// number of steps remembered by the system

/**
 * Sets the number of steps remembered by the system (contextual menu).
 *
 * @param iNb number of steps to remember
 */
virtual void   SetNbSteps (const int iNb) = 0;

/**
 * Returns the number of steps remembered by the system.
 */
virtual int    NbSteps () const  = 0;


// number of steps remembered by the system

/**
 * Sets the number of old values to remember by the system (contextual menu).
 *
 * @param iNb number of old values to remember
 */
virtual void   SetNbValues (const int iNb) = 0;

/**
 * Returns the number of old values to remember by the system.
 */
virtual int    NbValues () const  = 0;


//------------------------------------------------------
// As a dynamic definition (created by user)
//------------------------------------------------------
  
/**
 * Returns the last step used.
 * @return last step in model unit
 */
virtual double Step () const = 0;

/**
 * Adds a step to the steps remembered.
 * become last step).
 * @param iValue step added in model unit
 */
virtual void   SetStep (const double iValue) = 0;

/**
 * Returns the list of last steps used. 
 * @return list of last steps used in model unit (not to be deallocated)
 */
virtual const  CATListOfDouble *Steps () const = 0;
  
/**
 * Adds a value to the old values remembered.
 * (become last value)
 * @param iValue value added in model unit
 */
virtual void   SetValue (const double iValue) = 0;

/**
 * Returns the ist of last old values.
 * (last entered element is at the end of the list)  
 * @return list of last values used in model unit (not to be deallocated)
 */
virtual const  CATListOfDouble *Values () const = 0;

/**
 * @deprecated V5-6R2016 / 3DEXPERIENCER2016x: DO NOT USE THIS METHOD UNDER ANY CONDITION, use SetEnumerateValues with CATListOfDouble or CATListOfCATUnicodeString input.
 * Initialization of the list of enumerate values.
 * (last entered element is at the end of the list)  
 * For string parameters, iList is a pointer to a CATListOfCATUnicodeString provided as input of the method.<br>
 * For other parameters, iList is a pointer to a CATListOfDouble provided as input of the method.<br>
 * @param iList list of available values
 */
virtual void SetEnumerateValues (void* iList) = 0;

/**
 * Initialization of the list of enumerate values.
 * (last entered element is at the end of the list)  
 * @param iList list of available values
 */
virtual HRESULT SetEnumerateValues(const CATListOfDouble & iList) = 0;

/**
 * Initialization of the list of enumerate values.
 * (last entered element is at the end of the list)  
 * @param iList list of available values
 */
virtual HRESULT SetEnumerateValues(const CATListOfCATUnicodeString & iList) = 0;

/**
 * @deprecated V5-6R2016 / 3DEXPERIENCER2016x: DO NOT USE THIS METHOD UNDER ANY CONDITION, use GetEnumerateValues with CATListOfDouble or CATListOfCATUnicodeString input.
 * Get the list of enumerate values.
 * (last entered element is at the end of the list)  
 * For string parameters, iList is a pointer to a CATListOfCATUnicodeString provided as input of the method. The list if filled by the method<br>
 * For other parameters, iList is a pointer to a CATListOfDouble provided as input of the method.The list if filled by the method<br>
 * @param iList list of available values (not to be deallocated)
 */
virtual void GetEnumerateValues (void* iList) = 0; 

/**
 * Get the list of enumerate values.
 * (last entered element is at the end of the list)  
 * @param oList list of available values
 */
virtual HRESULT GetEnumerateValues(CATListOfCATUnicodeString & oList) const = 0;

/**
 * Get the list of enumerate values.
 * (last entered element is at the end of the list)  
 * @param oList list of available values
 */
virtual HRESULT GetEnumerateValues(CATListOfDouble & oList) const = 0;

enum TestRC 
    {
      Ok            =0,
      MinReached    =1,
      MaxReached    =2,
      NotInEnum     =3,
      NotAuthorized =4
    };
  
/**
 * Tests if a given value is authorized considering bounds, authorized values, etc... 
 * @param iValue value to be tested
 * @param iMag magnitude
 * @return indicates if value is authorized 
 */

virtual CATIParmManipulator::TestRC TestValue (const double iValue,const CATICkeMagnitude_var &iMag = NULL_var) const = 0; 

/**
 * Indicates if the parameter is multiple valuated.
 * @return 0 if one value, 1 if list of values
 */
virtual int  HasMultipleValues () = 0;
  
/**
 * Destroys the list of enumerate values on the parameter.  
 */
virtual void   SuppressEnumerateValues () = 0; 


/**
 * Retrieves the parameter manipulated by the manipulator.
 * @param oParameter  the parameter manipulated
 * @return
 *	<dl>
 *  <dt><tt>S_OK</tt>			<dd>if a parameter has been found
 *  <dt><tt>E_FAIL</tt>			<dd>if no parameter has been found
 *  </dl>
 */
virtual HRESULT GetParameter(CATBaseUnknown_var& oParameter) = 0;

/**
    *
    * <br><b>Role</b>: Indicates whether manipulator is persistent or not.
    * @param oManipIsPersistent
    * oManipIsPersistent is returned as TRUE when the manipulator is persistent else FALSE.
    * @return
    * <dl>
    * <dt><code>S_OK</code> <dd>
    * <dt><code>E_FAIL</code> <dd>
    * </dl>
    */
virtual HRESULT IsManipPersistent(CATBoolean &  oManipIsPersistent) const = 0;
}; 

CATDeclareHandler(CATIParmManipulator,CATBaseUnknown);

#endif


