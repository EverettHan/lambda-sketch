#ifndef CATICkeMKSUnit_h
#define CATICkeMKSUnit_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/** 
 * @CAA2Level L1
 * @CAA2Usage U3
 */

/*  CAA2Reviewed by FRH */

// inherited class
#include <CATBaseUnknown.h>

// module
#include "CATLifSpecs.h"

// Forwords 
#include <CATICkeRelationForwards.h>

// OLE id
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATLifSpecs IID_CATICkeMKSUnit;
#else
extern "C" const IID IID_CATICkeMKSUnit;
#endif

/**   
 * Interface dedicated to MKS equivalent management.
 * <b>Role</b>: Magnitudes are equivalent to a combination of primitive magnitudes<br>
 * (for example : a speed is equivalent to Length divided by time).<br>
 * This class gives the list of exponent (positive or negative) for each primitive magnitude<br>
 *<br>
 * The primitives are :<br>
 *     M : Length<br>
 *     K : Mass <br>
 *     S : Time<br>
 *     A : Ampere<br>
 *     T : Temperature<br> 
 *     C : Candela <br>
 *     O : Mole<br>
 *     P : Price<br>
 *     R : Angle<br>
 *     E : Solid angle<br>
 *     Scalar : scalar<br>
 *<br>
 *  Usage :<br>   
 *    <br>
 *   #include "CATICkeParmFactory.h"<br>
 *   #include "CATICkeMKSUnit.h"<br>
 *<br>
 *   //------------------------------------------------<br>
 *   // MKS Units<br>
 *   //------------------------------------------------<br>
 *   // you can create mks unit equivalent to a scalar<br>
 *   CATICkeMKSUnit_var mk1 = fact->CreateMKSUnit ();<br>
 *   Assume (mk1->Get(MKSUnitM) == 0);<br>
 *<br>
 *   // you can create mks unit equivalent to a simple standard unit<br>
 *   CATICkeMKSUnit_var area = fact->CreateMKSUnit (MKSUnitM,2);<br>
 *   Assume (area->Get(MKSUnitM) == 2);<br>
 *     <br>
 *   // you can create mks unit equivalent to a combination of units<br>
 *   CATICkeMKSUnit_var density = fact->CreateMKSUnit (-3,1,0,0,0,0,0,0,0,0);<br>
 *   Assume (density->Get(MKSUnitM) == -3);<br>
 * <p>
 * This interface is mono implemented by a C++ object. This object is created by the volatile factory CATICkeParmFactory.  
 * @see CATICkeMagnitude, CATICkeParmFactory
 *
 */
class ExportedByCATLifSpecs CATICkeMKSUnit : public CATBaseUnknown
{

public :

/** 
 * List of existing MKS primitive magnitudes.
 * <br><b>Legal values</b>: 
 * <tt>M</tt> for meter
 * <tt>K</tt> for kilogram 
 * <tt>S</tt> for second
 * <tt>A</tt> for amper
 * <tt>T</tt> for temperature
 * <tt>C</tt> for candela
 * <tt>O</tt> for number of mole
 * <tt>P</tt> for price
 * <tt>R</tt> for radian
 * <tt>E</tt> for steradian
 */
enum Basic { M, K, S, A, T, C, O, P, R, E, Scalar};


/**
 * Sets a basic primitive exponent.
 * @param iPrimitiveMagnitude primitive magnitude
 * @param iCoeff exponent
 * This method is supposed to be used only at definition stage of a magnitude.
 */
virtual void Set (const CATICkeMKSUnit::Basic iPrimitiveMagnitude,const int iCoeff) =0;

/**
 * Reads the exponent of a basic primitive.
 * @param iPrimitiveMagnitude  primitive magnitude
 * @return the exponent for a basic primitive
 */
virtual int  Get (const CATICkeMKSUnit::Basic iPrimitiveMagnitude) const =0;

/**
 * Shows a view of the MKS equivalent in NLS.
 * @return a view of the MKS equivalent in NLS.
 */
virtual CATUnicodeString Show () const = 0;

/**
 * Compares one mks with another.
 * @param iMKSToCompare MKS to compare
 * @return <br><b>Legal values</b>: 
 * <tt>CATCke::True</tt> if same MKS
 * <tt>CATCke::False</tt> if not 
 */
virtual CATCke::Boolean Compare (const CATICkeMKSUnit_var &iMKSToCompare) const = 0;

/**
 * Multiply 2 MKSunit (example a Length multiplied with a Length produces an area). 
 * @param iMKSMultipliedWith the parameter with which the multiplication occurs.  
 * @param oResult The resulting unit.
 * @return <br><b>Legal values</b>: 
 * <tt>CATCke::True</tt> if multiplication Ok
 * <tt>CATCke::False</tt> if error in MKS multiplication
 */
virtual CATCke::Boolean Multiply (const CATICkeMKSUnit_var &iMKSMultipliedWith, CATICkeMKSUnit_var &oResult) const =0;

/**
 * Divides 2 mks unit (example a Length divided by a Length produces a scalar). 
 * @param iMKSDividedBy  the unit that must divide the current unit
 * @param oResult the resulting unit
 * @return <br><b>Legal values</b>: 
 * <tt>CATCke::True</tt> if division Ok
 * <tt>CATCke::False</tt> if error in MKS division
 */
virtual CATCke::Boolean Divide   (const CATICkeMKSUnit_var &iMKSDividedBy, CATICkeMKSUnit_var &oResult) const =0;


/**
 * Power  (example a Length power 3 produces a volume). 
 * @param iCoeff exponent (positive or negative)
 * @param oResult the resulting unit
 * @return <br><b>Legal values</b>: 
 * <tt>CATCke::True</tt> if operation Ok
 * <tt>CATCke::False</tt> if error in MKS operation
 */
virtual CATCke::Boolean Power (const int iCoeff, CATICkeMKSUnit_var &oResult) const =0;


private:

  // 2 define ClassName
  CATDeclareInterface;


}; 

CATDeclareHandler(CATICkeMKSUnit,CATBaseUnknown);

#endif


