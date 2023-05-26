#ifndef CATICkeType_h
#define CATICkeType_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/** 
 * @CAA2Level L1
 * @CAA2Usage U3
 */


/*  CAA2Reviewed by FRH */

// inherited class 
#include "CATBaseUnknown.h"

// load module
#include "CATLifSpecs.h"

// forwards definition
#include "CATICkeForwards.h"
class CATICkeMKSUnit_var;

// OLE IID
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATLifSpecs IID_CATICkeType;
#else
extern "C" const IID IID_CATICkeType;
#endif

/**   
 * Interface dedicated to Knowledge type management. 
 * <b>Role</b>: This interface is used to classify objects that can be manipulated in Knowledgeware from their types.<br>
 * It concerns types of values like String type, Real type, Boolean type and Integer type<br>
 * or  dimension types such as Angle type, Length type, etc... <br>
 *     that implement specifically CATICkeMagnitude<br>
 * or  enumerated types<br>
 *     that implement specifically CATIEnumere<br>
 * 
 * This interface is similar to CATIType interface.
 *
 * @see CATICkeMagnitude, CATIEnumere, CATIParmDictionary, CATITypeDictionary, CATIType
 */

class ExportedByCATLifSpecs CATICkeType : public CATBaseUnknown
{

public :
  

/**
 * Returns the name of the type (internal identifier).
 * This name is the one used to find a type by its name in CATIParmDictionary and CATITypeDictionary methods.<br>
 */
virtual CATUnicodeString  Name    () const =0;

/**
 * Returns a NLS string that represents the type.
 * Must be used to show the type to the users. 
 */
virtual CATUnicodeString  Show    () const =0; 

/**
* Returns the Knowledge type NLS name.
*/
virtual CATUnicodeString UserName () const = 0;




/**
 * Returns the kind of value which is hidden behind the type (Real for a dimension).
 */
virtual CATICkeType_var    GetValueType () const = 0;

/**
 * Returns the MKS equivalent of this type if any.
 */
virtual CATICkeMKSUnit_var MKS () const = 0;



/** 
 * This method tests the identity of two types. You can also simply compare Knowledge types with the == operator.<br>
 * @param iType type compared to
 * Basic types are available in CATIParmDictionary.
 * @return CATCke::True if identify, CATCke::False instead
 */
virtual CATCke::Boolean Isa       (const CATICkeType_var &iType) const =0;

/**
 * Tests if this Knowledge type is a subtype of the one in argument.
 * @param iType type compared to
 * @return result of the test
 * <br><b>Legal values</b>:return value can be 
 * <tt>CATCke::True</tt> if this type is a sub-type of the other, or
 * <tt>CATCke::False</tt> if it isn't
 */
virtual CATCke::Boolean IsaKindOf (const CATICkeType_var &iType) const =0;

/**
 * Tests is this type is the real type. You can also simply compare this type and CATIParmDictionary::GetRealType with the == operator.
 * @return result of the test
 */
virtual CATCke::Boolean IsaReal   () const =0;

/**
 * Tests is this type is the boolean type. You can also simply compare this type and CATIParmDictionary::GetBooleanType with the == operator.
 * @return result of the test
 */
virtual CATCke::Boolean IsaBoolean() const =0;

/**
 * Tests is this type is the integer type. You can also simply compare this type and CATIParmDictionary::GetIntegerType with the == operator.
 * @return result of the test
 */
virtual CATCke::Boolean IsaInteger() const =0;

/**
 * Tests is this type is the string type. You can also simply compare this type and CATIParmDictionary::GetStringType with the == operator.
 * @return result of the test
 */
virtual CATCke::Boolean IsaString () const =0;

/**
 * Tests if this Knowledge type is a subtype of the one in argument.
 * @param iTypeName name of the type compared to
 * @return result of the test
 * <br><b>Legal values</b>:return value can be 
 * <tt>CATCke::True</tt> if this type is a sub-type of the other, or
 * <tt>CATCke::False</tt> if it isn't
 */
virtual CATCke::Boolean IsaKindOf (const CATUnicodeString &iTypeName) const =0;


 
private:

  CATDeclareInterface;

}; 

CATDeclareHandler(CATICkeType, CATBaseUnknown);

#endif



