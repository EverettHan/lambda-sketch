#ifndef CATICkeUnit_H
#define CATICkeUnit_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/** 
 * @CAA2Level L1
 * @CAA2Usage U3
 */


/*  CAA2Reviewed by FRH */

// inherited from
#include "CATBaseUnknown.h"

// module
#include "CATLifSpecs.h"

// Forward declaration
#include "CATICkeRelationForwards.h"


// OLE id
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATLifSpecs IID_CATICkeUnit;
#else
extern "C" const IID IID_CATICkeUnit;
#endif

/**   
 * Interface dedicated to unit management.
 * <b>Role</b>: This interface gives access to unit properties.<br>
 * This interface is based on the International System Magnitude Management
 * called MKS.<br>
 * Each magnitude has a default unit corresponding to the MKS System<br>
 *     for example : the default unit for length is meter<br>
 *                   the default unit for weight is kilogram<br>
 *                   etc...<br>
 * All conversion methods are working with this MKS unit on one side<br> 
 *
 * <br>
 *
 * This interface is mono implemented.
 * @see CATICkeMagnitude
 */
//-----------------------------------------------------------------------------
class ExportedByCATLifSpecs CATICkeUnit : public CATBaseUnknown
{

public:

/**
 * Returns the NLS name of this unit.
 * Example: "Millimeter".
*/
virtual CATUnicodeString Name () const = 0;

/**
 * Returns the internal name of this unit.
 * Example: "Millimeter".
	*/
virtual CATUnicodeString InternalName() const =0;

/**
 * Returns the symbol of this unit.
 * Example: "mm"
 */
virtual CATUnicodeString Symbol () const = 0;

/**
 * Returns a string showing a real (in MKS) in this unit.
 * Example: "2 cm".
 * @param iValueInMKS double in input is in MKS 
 * @param iNbDecimals number of decimals to use to show the number. If equal to zero, default nb of decimals
 * @return the string to show the real in MKS
 */
virtual CATUnicodeString Show (const double iValueInMKS, const int iNbDecimals = 0) const =0;

/**
 * Converts  a real in this unit to MKS.
 * @param  iValueInThisUnit value in this unit
 * @return value converted in MKS
 */
virtual double Convert (const double iValueInThisUnit) const =0;  

/**
 * Converts a real in MKS to this unit.
 * @param  iValueInMKS value in this unit
 * @return value converted in this unit
 */
virtual double Value (const double iValueInMKS) const =0;  

 
/**
 * Tries to decode a string (prefixed with unit or not) to a real.
 * Example: Decode "3mm"<br>
 * @param iStringToDecode string to be decoded.
 * @param oValueInMKS the double in output is in MKS
 * @return <br><b>Legal values</b>: the test can be either
 * <tt>1</tt> if successful in decoding.
 * <tt>0</tt> if it isn't.
 */
virtual CATCke::Boolean DecodeReal (const CATUnicodeString &iStringToDecode,double &oValueInMKS) const =0 ;


/**
*  Returns the magnitude of the unit. It may happen that a unit participate to several magnitudes.<br>
*  In this case, only the first found will be returned.
* @return the magnitude of the unit
*/
virtual CATICkeMagnitude_var GetMagnitude() = 0;


/**
 * Returns the value of the parameter in the current unit while respecting the ISO standard.
 * @param iValue 
 *  Value of the parameter.
 * @param iNbDecimals
 *  Number of decimals to use to show the number. If equal to zero, the setting is used.
 * @return
 *  The value of the parameter in the current unit while respecting the ISO standard, 
 *  <br>i.e. : if the setting called "Decimal places for read/write numbers" (used for the display of units) = 3
 *  <br>and if the parameter's value in current unit (e.g. mm) = 0.001, 
 *  <br> returns "0mm"
 *  <br>otherwise, if parameter's value in current unit (e.g. mm) = 0.001,
 *  <br> returns "0.001mm".
 */
virtual CATUnicodeString ShowIso (const double iValue, const int iNbDecimals = 0) const = 0;

private :  

  // to define ClassName
  CATDeclareInterface;


};


CATDeclareHandler(CATICkeUnit,CATBaseUnknown);


#endif
