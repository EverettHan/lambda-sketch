#ifndef CATIParmDictionary_H
#define CATIParmDictionary_H

#include "CATLifSpecs.h"
#include "CATBaseUnknown.h"

#include "CATUnicodeString.h"
#include "CATICkeForwards.h"
#include "CATICkeRelationForwards.h"
#include "CATICkeType.h"


// OLE
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATLifSpecs IID_CATIParmDictionary;
#else
extern "C" const IID IID_CATIParmDictionary;
#endif

class CATICkeParmFactory_var;
class CATICkeMagnitude_var;
class CATICkeUnit_var;

// COPYRIGHT DASSAULT SYSTEMES 1999

/** 
 * @CAA2Level L1
 * @CAA2Usage U3 
 */

/*  CAA2Reviewed by FRH */

/**   
 * Interface to manage the dictionary of types of values.
 * <b>Role</b>: It gathers static methods to value type dictionary management.
 * It offers direct access to common types of values and it provides methods to find magnitudes and units by name.<br>
 * @see CATIAddLibrary, CATICkeType, CATICkeMagnitude, CATICkeUnit 
 */
class ExportedByCATLifSpecs CATIParmDictionary : public CATBaseUnknown
{
  CATDeclareInterface;

public:

/** 
 * Use CATCkeGlobalFunctions instead.
 * @return the volatile factory.for values
 */
virtual CATICkeParmFactory_var GetVolatileFactory()=0;


/** 
 * Returns the Real type.
 */
virtual CATICkeType_var GetRealType()=0;
   
/** 
 * Returns the Integer type.
 */
virtual CATICkeType_var GetIntegerType()=0;
   
/** 
 * Returns the String type.
 */
virtual CATICkeType_var GetStringType()=0;
   
/** 
 * Returns the Boolean type.
 */
virtual CATICkeType_var GetBooleanType()=0;
   
/** 
 * Returns the Length type.
 */
virtual CATICkeType_var GetLengthType()=0;
   
/** 
 * Returns the Angle type.
 */
virtual CATICkeType_var GetAngleType()=0;
   
/** 
 * Returns the Void type (used for defining arguments of functions or expressions).
 */
virtual CATICkeType_var GetVoidType()=0;
   
/** 
 * Returns the Feature type: main basic type for objects that can be manipulated by Knowledgeware.
 */
virtual CATICkeType_var GetFeatureType()=0;

/** 
 * Returns the Enum type, which is the basic type for all enumerated types of values.
 */
virtual CATICkeType_var GetEnumType()=0;

/** 
 * Returns the Dimension type, which is the basic type for all magnitudes.
 */
virtual CATICkeType_var GetDimensionType()=0;
 
/** 
 * Returns the basic type for any literal (simple value).
 */
virtual CATICkeType_var GetLiteralType() =0;

/** 
 * Returns the type for lists.
 */
virtual CATICkeType_var GetListType () =0;

/** 
 * Returns the type for dates.
 */
virtual CATICkeType_var GetDateType () =0;

/**
 * Finds a magnitude from its internal coded name. 
 * @param iName name of the magnitude 
 * Unfortunately, there is no way to know the all list of coded name of magnitudes that exist for a V5 release. 
 * @return the magnitude found
 */
virtual CATICkeMagnitude_var FindMagnitude (const CATUnicodeString &iName)=0 ;

/**
 * Finds a unit from its coded name.
 * @param iName name of the unit 
 * Unfortunately, there is no way to know the all list of coded name of units that exist for a V5 release. 
 * @return the unit found
 */
virtual CATICkeUnit_var      FindUnit      (const CATUnicodeString &iName)=0 ;

/**
* Finds a unit from its symbol.
* @param symbol
* the string containing the symbol (eg. "mm" or "m3"). 
* <br>The empty string argument "" is not valid.
* @return
* the unit (NULL_var if the unit wasn't found)
*/
virtual CATICkeUnit_var FindUnitFromSymbol(const CATUnicodeString &symbol)=0;


/**
 * Finds a value type by its coded name.
 * Unfortunately, there is no way to know the all list of coded name of units that exist for a V5 release. 
 * @param iCodedName : name of type to find 
 * @return the type found
 */
virtual CATICkeType_var FindType (const char* iCodedName)=0 ;


/**
 * Returns the list of all magntitudes contained in the value type dictionary.
 * @param ioListOfMagnitudes: a pointer to an empty list of magnitudes.
 */
virtual void Magnitudes (CATCkeListOfMagnitude ioListOfMagnitudes)=0;


/**
* Delete the dictionary of units.
**/
virtual void CloseUnits ()=0;


};

// declaration of Handler
CATDeclareHandler(CATIParmDictionary,CATBaseUnknown);

#endif
