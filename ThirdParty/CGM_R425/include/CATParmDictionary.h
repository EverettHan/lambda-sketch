/**  	   	   	 
* @level Protected 	  	  	 
* @usage U1 	  	  	 
*/

#ifndef CATParmDictionary_h
#define CATParmDictionary_h

// COPYRIGHT DASSAULT SYSTEMES 1999
#include "CATIAV5Level.h"
#include "CATLifDictionary.h"

// forwards
#include "CATICkeRelationForwards.h"
class CATIDescendants_var;
class CATIParmPublisher_var;
class CATIContainer_var;


// interface used
#include "CATUnicodeString.h"
#include "CATICkeType.h"

#ifdef CATIAR204
#include "CATIContainer.h"
#else
#include "CATISpecObject.h"
#endif

#include "CATICkeArg.h"
#include "CATICkeParmFactory.h"
#include "CATICkeSignature.h"
#include "CATICkeRelation.h"

//Literal Features
#include "CATCkeListOfInterface.h"
#include "CATListOfCATUnicodeString.h"


class CATCkeEvalContext;
class CATCkeRelationFeatureFactory;
#include "CATICkeFunctionFactory.h"

// standard check magnitude to use when you're using magnitudes as argument types.
// this check will verify that inputs and resultare of good magnitudes
ExportedByCATLifDictionary CATCke::Boolean CATCkeStandardCheckMagnitude (CATCkeListOfParm l,const CATICkeParm_var &res,const CATCkeEvalContext *pevalcontext);

// Volatile factory
#define CATCKEVolatileFactory (CATParmDictionary::GetVolatileFactory ())




/**   
 * Dictionary of types.
 * <b>Role</b>: It gathers static methods to parameters type dictionary management.
 * It offers direct access to common literals types and methods to find magnitudes and units by name<br>
 * It gives a way to create your own functions that can later be used in relations, and add them <br>
 * to the dictionary<br>
 * It gives a way to add own applications that can later be used in applications dialog in the<br>
 * knowledgeware workbench <br>
 * @see CATIAddLibrary
 * @see CATICkeType
 * @see CATICkeMagnitude
 * @see CATICkeUnit
 */
//-----------------------------------------------------------------------------
class ExportedByCATLifDictionary CATParmDictionary
{

public:

   
/** 
 * Returns the volatile factory.
 */
static CATICkeParmFactory_var GetVolatileFactory ();
   
/** 
 * Real type.
 */
static CATICkeType_var RealType;
   
/** 
 * Integer type.
 */
static CATICkeType_var IntegerType;
   
/** 
 * String type.
 */
static CATICkeType_var StringType;
   
/** 
 * Boolean type.
 */
static CATICkeType_var BooleanType;
   
/** 
 * Length type.
 */
static CATICkeType_var LengthType;
   
/** 
 * Angle type.
 */
static CATICkeType_var AngleType;
   
/** 
 * Void type.
 */
static CATICkeType_var VoidType;
   
/** 
 * Feature type: main basic class for feature references.
 */
static CATICkeType_var FeatureType;
 
/** 
 * Law type: basic type for laws.
 */
static CATICkeType_var LawType;

/** 
 * Enum type.
 */
static CATICkeType_var EnumType;

/** 
 * Dimension type.
 */
static CATICkeType_var DimensionType;

/** 
 * ListType.
 */
static CATICkeType_var ListType;
 
/**
 * Finds a magnitude from its coded name.
 */
static CATICkeMagnitude_var FindMagnitude (const CATUnicodeString &s) ;

/**
 * Finds a unit from its coded name.
 */
static CATICkeUnit_var      FindUnit      (const CATUnicodeString &s) ;




/**
 * Creates a signature and add it to the dictionary.
 * @param iFunctionName :  function name (example : "sin") It is the name
 * that will be used in formulas
 * @param iReturnedType: returned type of the function (example : CATParmDictionary::RealType in our sinus example) 
 * @param iEvalFuncPtr : function evaluator 
 * @param iCheckMagnitudeFuncPtr : function evaluator
 * @param iNotation: notation
 */
static CATICkeSignature_var CreateFunction (const CATUnicodeString &iFunctionName,
					                        const CATICkeType_var  &iReturnedType,
							                CATCkeFunctionEvaluator iEvalFuncPtr = NULL,
											CATCkeCheckMagnitude iCheckMagnitudeFuncPtr = NULL,
											const CATICkeSignature::Mode iNotation = CATICkeSignature::Function);
									
					      
/**
 * Creates an argument to be added to a signature. 
 * @param iArgName : argument name (example : "x") 
 * @param iArgType : argument type (example : CATParmDictionary::RealType in our example)
 * @param iMode : indicates if the argument is In, Out or InOut
 */
static CATICkeArg_var       CreateArg (const CATUnicodeString &iArgName,
                                       const CATICkeType_var  &iArgType,
				                       const CATICkeArg::Mode iMode = CATICkeArg::In);
					      

/**
 * Returns the list of visible literals from a CATIParmPublisher.
 * uses GetDirectChildren and GetAllChildren on CATIParmPublisher and filters the NotSeen literals<br>
 * @param iRoot : root object
 * @param iListToBeFilled: literals are added to this list already allocated
 * @param recursif : indicates if we only scan the direct children or all the children
 * @param withFeatures : indicates if we scan the CATICkeFeature or not
 */
static void VisibleParms (const CATIParmPublisher_var &iRoot,
                          CATCkeListOf(Parm)        &iListToBeFilled,
			  const CATCke::Boolean      iRecursive = 1, int withFeatures = 0);


// how to get all relationss that belong (in a direct way or not) to a feature
//-----------------------------------

/**
 * Returns the list of visible relations from a CATIParmPublisher.
 * uses GetDirectChildren and GetAllChildren on CATIParmPublisher and filters the non expressional relation
 * @param iRoot : root object
 * @param iListToBeFilled : relations are added to this list already allocated
 * @param  iRecursive : indicates if we only scan the direct children or all the children
 */
static void VisibleRelations (const CATIParmPublisher_var &root,
							  CATCkeListOf(Relation)    &iListToBeFilled,
			                  const CATCke::Boolean     iRecursive = 1);


/**
 * Tries to find a parameter by its name.
 * @param iParameterName : name of the parameter.
 * @param iRecursive : indicates if we only scan the direct children or all the children
 */
static CATICkeParm_var FindParm (const CATIParmPublisher_var &iRoot,
				                 const CATUnicodeString      &iParameterName,
                                 const CATCke::Boolean        iRecursive = 1);
  
					      
/**
 * Creates an argument to be added to a signature. 
 * @param iArgName : argument name (example : "x") 
 * @param iArgType: argument type (example : "Real" in our example)
 * @param Mode iArgMode: indicates if the argument is In, Out or InOut
 */
static CATICkeArg_var       CreateArg (const CATUnicodeString &iArgName,
                                       const CATUnicodeString &iArgType,
				       const CATICkeArg::Mode iArgMode = CATICkeArg::In);
					      

/**
 * Creates a signature and add it to the dictionary..
 * @param iFunctionName:  function name (example : "sin") It is the name
 * that will be used in formulas
 * @param iReturnedType: returned type of the function (example : CATParmDictionary::RealType in our sinus example) 
 * @param iEvalFuncPtr : function evaluator 
 * @param iCheckMagnitudePtr : check magnitude evaluator
 * @param iNotation: notation
 */
static CATICkeSignature_var CreateFunction (const CATUnicodeString      &iFunctionName,
											const CATUnicodeString      &iReturnedType,
											CATCkeFunctionEvaluator      iEvalFuncPtr = NULL,
											CATCkeCheckMagnitude         iCheckMagnitudePtr = NULL,
											const CATICkeSignature::Mode iNotation = CATICkeSignature::Function);




/**
 * Finds a type by its coded name.
 * @param iCodedName : name of type to find 
 */
static CATICkeType_var FindType (const char* iCodedName) ;

/**
 * Create a C++ type (or find it if already exists) and add it to dictionary.
 * @param iCodedName : name of type to create 
 * @param iFatherType: father type if any 
 * @param iNLSName   : NLS name for the type if any 
 * @return  CATICkeType_var : type found or created 
 */
static CATICkeType_var CreateType (const char *iCodedName,
							       const CATICkeType_var &iFatherType = NULL_var,
								   const CATUnicodeString &iNLSName = "") ;

/**
 * Adds a type to the dictionnary.
 * @param iType: type to add 
 */
static void            AddType (const CATICkeType_var &iType);

/**
 * Asks to load a library by its name.
 * @param iLibraryName: C++ class name of the library
 * @return   : CATCke::True if succeeded
 */
static CATCke::Boolean LoadLibrary (const char *iLibraryName);

/**
 * Removes a type to the dictionnary.
 * @param iType: type to remove : USE WITH CARE 
 */
static void            RemoveType (const CATICkeType_var &iType);
	
/**
* Creates an event signature and add it to the dictionary.
* @param iEventName :  event name (example : "Instanciation")
*/
static CATICkeSignature_var CreateEvent (const CATUnicodeString &iEventName);

  /**
   * Returns the list of available magnitudes.
   */
  static CATCkeListOfMagnitude Magnitudes();

  static void Clear();
  static CATBoolean IsRelationFeatureFactoryInitialized();

  static void SetRelationFeatureFactoryInitialized(CATBoolean flag);
};
#endif


