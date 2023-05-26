/**
* @level Protected 
* @usage U1
*/

/** @quickReview TVQ 01:09:22 */
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 98
//===========================================================================
//
// class CATCkeValueServices
// Offers basic services for applications regarding values
// Will be in Magnitude framework
//
//===========================================================================
// Usage Notes:
//
// 
//===========================================================================
// 2006 Oct. 23   Creation from split of CATCkeParmServices           FRH
//===========================================================================

#ifndef __CATCkeValueServices__
#define __CATCkeValueServices__

#include "CATLifDictionary.h"

#include "CATBaseUnknown.h"
#include "CATICkeRelationForwards.h"
#include "CATUnicodeString.h"
#include "CATICkeParm.h"
#include "CATICkeMagnitude.h"

class CATCkeEvalContext;
class CATIParmPublisher_var;
class CATIType_var;
class CATIContainer_var;

struct ExportedByCATLifDictionary CATCkeValueServices
{
  /**
  * This function checks if the value given as argument is compliant with type given as argument
  * @return CATCke::True if the value is compliant with the type, CATCke::False else
  * @param type
  * the type to be compared
  * @param value
  * the value whose type is to compared
  */
  static CATCke::Boolean TypeIsCompliant(const CATICkeType_var &type, const CATUnicodeString &value);


  /**
  * This function checks if the string given as argument is a numerical value (can be int, double or dimension (i.e:"12 mm")). If 
  * the value is numerical, the mksValue argument is filled with the value in mks
  * @return CATCke::True if the value is numerical
  * @param value
  * the string containing the value to be looked to
  * @param mksValue
  * the double that contains the mks value if the function returns CATCke::True
  */
  static CATCke::Boolean IsNumerical(const CATUnicodeString &value, double &mksValue);



  /**
  * This function looks for the most adapted type for the string value
  * @return the type that was found (IntegerType for "12", RealType for "12.1", LengthType for "12.1m", BooleanType for "true", StringType for "portenaouak")
  * @param value
  * the string containing the value whose type is searched
  */
  static CATICkeType_var TypeOfValue(CATUnicodeString &value);


  /**
  * This function adds the unit extension ot the string containing the value if necessary
  * @return the resulting string
  * @param value
  * the string containing a value ("12" for example)
  * @param unit
  * the string containing a unit ("mm" for example)
  */
  static CATUnicodeString AddUnitExtension(const CATUnicodeString &value, const CATUnicodeString& unit);

  /**
  * This function extracts a unit encapsulated by parenthesis (and returns its symbol) from a string.
  * The given string is modified : the unit extension is removed
  * For example for the string "toto (mm)", it returns "mm", and the string becomes "toto"
  */
  static CATUnicodeString ExtractUnitExtension(CATUnicodeString &string, CATCke::Boolean withParenthesis = 1);

  /**
  * This function returns the current unit symbol of the given parameter (if there is one).
  * @param parm
  * the parameter from whixh you want the current unit symbol
  */
  static CATUnicodeString GetUnitSymbolOfParm(const CATICkeParm_var &parm);


  /*
  * This function converts a value from MKS to 
  * the unit identified by its symbol.
  * @param mksValue
  * the value to convert
  * @param targetUnitSymbol
  * the string which gives the target unit symbol used to identify the unit
  * @param result
  * the double containing the value in the target unit
  * @param magnitude
  * the magnitude which corresponds to the target unit. If null, target unit is
  * identify by scanning all the units for each magnitude (time consuming).
  * @return
  * E_FAIL if targetUnitSymbol does not correspond to any unit, S_OK else
  */
  static HRESULT MKSToUnitGivenBySymbol(const double mksValue, const CATUnicodeString &targetUnitSymbol,
    double &oResult,
    const CATICkeMagnitude_var &magnitude = NULL_var);

  enum ComparisonResult 
  {
    Superior,
    Inferior,
    Equal,
    BadType,
    Error
  };


  /**
  * This method compares two values and returns an enum with the result of the comparison
  * @return CATKweServices::Equal if value1 == value2, CATKweServices::Inferior if value1 < value2, CATKweServices::Superior if value1 > value2. If value1 and value2 don't have the same type (or the same magnitude), returns CATKweServices::BadType. If an error occurs, returns CATKweServices::Error
  * @param value1
  * the first value to compare
  * @param value2
  * the second value to compare
  */
  static CATCkeValueServices::ComparisonResult CompareValues(const CATICkeInst_var &value1, const CATICkeInst_var &value2);

  /**Parameters must have exactly the same type.*/
  #define CKE_CPV_STRICT_TYPE        1
  /**Parameters must have the same unset state.*/
  #define CKE_CPV_CHECK_UNSET        2
  /**Use CATCkeValueServices::RelativeCompare for double comparison.*/
  #define CKE_CPV_USE_EPSILON        4
  /**Allow comparison between strings and enumerations.*/
  #define CKE_CPV_ENUM_AND_STRING    8
  /**Allow comparison between numbers and strings*/
  #define CKE_CPV_NUMBER_AND_STRING 16
  /**String comparison is case insensitive*/
  #define CKE_CPV_CASE_INSENSITIVE  32
 /**
  * Compares two parameters values according to iFlags.
  * @param iParm1
  *   First parameter
  * @param iParm2
  *   Second parameter
  * @param iFlags
  *   A composition of CKE_CPV_XXX flags
  */
  static CATCkeValueServices::ComparisonResult CompareParametersValues(const CATICkeParm_var& parm1,const CATICkeParm_var& parm2,unsigned int flags);

  /**
  * This method converts a double in MKS to a double in unit model.
  * Returns the value in unit model
  * @param mksValue
  * the value to convert
  * @param type
  * type of the input value
  */
  static double MKSToModel(double mksValue, const CATICkeType_var &type);

  /**
  * This method converts a double in model unit to a double in mks.
  * Returns the value in mks
  * @param mksValue
  * the value to convert
  * @param type
  * type of the input value
  */
  static double ModelToMKS(double modelValue, const CATICkeType_var &type);

  /** 
  * Get Rid of ` characters in the parameters names shown by RelativeName() when useful
  * this function must be used whenever you want to show parameters names in an editor to 
  * rename them 
  */
  static CATUnicodeString SuppressBackQuote (const CATUnicodeString &iRelativeName); 

  /**
  * @nodoc
  */
  static void ConvertFrenchDoubleToEnglish(CATUnicodeString &doubleString);


  /*
  * Returns the value corresponding to an attribute of an object that has
  * been added by a user (we look at the direct children and if one of this 
  * children is a parameter set we look at its children and so on
  * @param iObject object where the attribute is sought
  * @param iAttributeName name of the attribute
  * @param SearchOption = 1 : Used to Search Attribute in UsersAttribute Before.
  * returns the value NULL_var if not found
  */
  static CATICkeParm_var FindAttributeValue
    (const CATBaseUnknown_var &iObject,
    const CATUnicodeString &iAttributeName,
    const int SearchOption = 0);

  /**
  * Indicates if 2 types are compatible.
  * @param iTypeToValuate type of the parameter to valuate
  * @param iTypeValue type of the parameter that valuates
  * @return True if compatibility
  */
  static CATCke::Boolean IsValuationCompatible (const CATICkeType_var &iTypeToValuate,
    const CATICkeType_var &iTypeValue);

  /**
  * Indicates if a string contains invalid characters that couldn't be used in formulas
  * @param iPathToCheck: string to check
  * @param oReplacingPath: path that can replace (surrounded by `)
  * @return : CATCke::True if the string is valid, CATCke::False instead
  */
  static CATCke::Boolean ValidPathname (const CATUnicodeString &iPathToCheck, CATUnicodeString &oReplacingPath);


  /** 
  * Test if a parameter name is already used in a specific context.
  * @param iName  = newname
  * @return = CATCke::True if the name already exists
  */
  static CATCke::Boolean ParameterNameAlreadyExists  (const CATUnicodeString      &iName,
    const CATIParmPublisher_var &iPublisher);

  /**
  * Adds a message in a log. When application is on idle, this message (with all others fired during the current treatment) will be shown in a messages dialog.
  * @param container
  * used to retrieve CATICkeParmFactory, which implementation has a command that shows the panel and stores messages.
  * @param from
  * name of the feature firing message
  * @param message
  * well explained message.
  * @param summary
  * fast summary of the message. No new line character in it.
  * @param type
  * should be either Warning, Error or Information (NLS). Can be different depending on the context. You can just use E, W, and I that are translated to Error, Warning, and Information
  * @param popup
  * if 1, displays it in a popup, if 0 displays it in the appropriate panel
  * @param stringForFilter
  * this argument is used to filter some messages emitted several times in a transaction. 
  * @param adressForFilter
  * this argument is used to filter some messages emitted several times in a transaction. 
  * @param msgNotShown
  * this argument is used to filter some messages emitted several times in a transaction. If it is different from 0, erases previous messages emitted by objects with the same adress and with same stringForFilter
  */
  static void AddDelayedMessage(const CATIContainer_var &container, const CATUnicodeString &from, const CATUnicodeString &message, const CATUnicodeString &summary, const CATUnicodeString &type, int popup = 0, const CATUnicodeString &stringForFilter = "", CATINTPTR adressForFilter = 0, int msgNotShown = 0);

  /**
  * @nodoc
  */
  static CATUnicodeString RemoveBackQuotes (const CATUnicodeString &s) ;

  /**
  * All new value introduced inside a parameter is considered as a new value.
  * This flag affects the behavior of  CATCkeUsrAnyTest::Compare2 which 
  * returns always TRUE when the flag is 1.
  * ppg 21.05.2002.
  */   
  static void ForceChangeValueR14(const unsigned int flag);

  /**
  * @deprecated V5R14SP2 due to RI correction (see function source code)
  * Use static void ForceChangeValue(const unsigned int flag);
  */ 
  static void ForceChangeValue(const short flag);
  static int IsChangeValueForced();

  /**
  * Returns true if parm1 and parm2 are equals.
  */
  static int AbsoluteCompare (double d1,double d2,double epsilon);

  /**
  * @nodoc
  */
  static int RelativeCompare (double d1,double d2,double epsilon = 1e-8);

  /**
  * @nodoc
  */
  static int  RelativeCompare (const CATICkeInst_var &d1, const CATICkeInst_var &d2);

  /** 
  * Returns the main type of an object
  * The object can be a value, a list or a datum (CATICkeParm:Type)
  * It can be a CATICkeFeature or a CATIInstance
  * If it is none of that, we say it is a CATParmDictionary::FeatureType
  * If it is NULL, we say it is CATCkeContext::UndefinedType
  *
  * MainTypeOfObject tests only CATICkeFeature/CATIInstance
  */
  static CATIType_var MainType (const CATBaseUnknown_var &iUnk);

  /**
  * @nodoc
  */
  static CATIType_var MainTypeOfObject (const CATBaseUnknown_var &iUnk);

  /** 
  * Indicates if an object supports a given type
  * The object can be a value, a list or a datum (CATICkeParm:Type)
  * It can be a CATICkeFeature or a CATIInstance
  * On CATIInstance, we consider all supported types if MultiTypeSupport==1
  */
  static CATCke::Boolean IsSupporting (const CATIType_var &,const CATBaseUnknown_var &iUnk,const int MultiTypeSupport= 1);

  /**
  * @nodoc
  */
  static int SetFacet(const CATBaseUnknown_var& iFromParm, const CATBaseUnknown_var& iToParm);

  /**
  * @nodoc
  */
  static void EnableKWEMessages(const int flag);

  /**
  * @nodoc
  */
  static int AreKWEMessagesEnabled();

  /**
  * Simulates a Enovia environment in file mode.
  * Returns 1 if the enovia environment if simulated.
  * Returns 0 otherwise.
  */
  static int IsEnoviaODTReplay();

  /**
  * Returns the entire part of a double
  * @param iValue The value from which the entire part is returned
  **/
  static double  CATCkeGetEntirePart(const double iValue);

  /**
      * creates a parm manipulator and set step if iParm is not NULL
      */
  static CATIParmManipulator_var CreateManipulator(const CATBaseUnknown* iParm=NULL); 

  /**
     *  @nodoc
     */
  static CATICkeUnit_var CreateUnit(const CATUnicodeString& name,const CATUnicodeString& symbol,double factor);
  
  //fonction d'accès a KWEUIEvents
  static void EnableKWEUIEvents(const int flag);

  static int AreKWEUIEventsEnabled();

  static void  ForceDictionaryInit();

  /**
   *  @nodoc
   */
  static double GetEpsilonAsStored(const CATICkeMagnitude* mag);

  /**
    *  creates a new volatile enumeration type with input values/nls values
    */
  static CATIEnumere_var CreateEnumereType(const CATUnicodeString &name,const CATUnicodeString& nlsName,const CATListOfCATUnicodeString &listValues,const CATListOfCATUnicodeString &listNlsValues);
};

#endif
