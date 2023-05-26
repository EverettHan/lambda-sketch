#ifndef CATICkeParmFactory_H
#define CATICkeParmFactory_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/** 
 * @CAA2Level L1
 * @CAA2Usage U3
 */


/*  CAA2Reviewed by FRH */

// module declaration
#include "CATLifSpecs.h"
#include "CATIVisitor.h"

class CATPathElement;

// inherited from
#include "CATBaseUnknown.h"

// Forward declaration
#include "CATICkeRelationForwards.h"
class CATIList_var;


// interfaces used 
#include "CATICkeMKSUnit.h"
#include "CATICkeMagnitude.h"
#include "CATIParmPublisher.h"
#include "CATIEnumere.h"
#include "CATIType.h"
class CATTime;

// OLE iid
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATLifSpecs IID_CATICkeParmFactory;
#else
extern "C" const IID IID_CATICkeParmFactory;
#endif


/**   
 * Interface dedicated to parameters factory.
 * <b>Role</b>: This interface helps you to create parameters.<br>
 * WATCH OUT : <br>
 * Dont forget to Initialise Literals environnement on the<br> 
 * Literals.feat catalog before any kind of work with parameters<br>
 * This interface is implemented on any Feature containers: thus it creates persistant parameters.<br>
 * It is also implemented on a volatile static object (CATCKEVolatileFactory): thus it creates volatile parameters.<br>
 *   <br>
 *     Usage :<br>
 * //////////////////////////////////////////////////////////////////////////<br>
 *<br>
 *      #include "CATCke.h"<br>
 *
 *      #include "CATICkeUnit.h"<br>
 *      #include "CATICkeMKSUnit.h"<br>
 *      #include "CATICkeMagnitude.h"<br>
 *      #include "CATICkeParmFactory.h"<br>
 *      #include "CATICkeParm.h"<br>
 *
 *      //------------------------------------------------<br>
 *      // Get this factory from your feat container<br>
 *      // to create features (persistent)  <br>
 *      //------------------------------------------------<br>
 *      CATICkeParmFactory_var fact = cont; <br>
 * <br>
 *      //------------------------------------------------<br>
 *      // Or use the Volatile factory<br>
 *      //------------------------------------------------<br>
 *      CATICkeParmFactory_var fact = CATCKEVolatileFactory; <br>
 *     <br>
 *      //------------------------------------------------<br>
 *      // you can create parameters<br>
 *      //------------------------------------------------<br>
 *      CATICkeParm_var p1 = fact->CreateLength ("L",3.3);<br>
 *<br>
 * @see CATICkeMagnitude, CATICkeUnit, CATIEnumere, CATICkeParm, CATICkeRelation
 */


//-----------------------------------------------------------------------------
class ExportedByCATLifSpecs CATICkeParmFactory : public CATBaseUnknown
{

public:



/**
 * Initialise LiteralFeatures environnement.<br>
 * It finds all startups needed in this container.<br>
 * This method should be used on Literals.feat catalog container only.
 */
virtual void InitStartUps () = 0;
  
/**
 * Please do not use it.
 * @nodoc to be suppressed
 */
virtual void SetCurrent () = 0;



/**
 * Creates string parameter.
 * @param iParameterName parameter name (never changed)
 * @param iParameterValue parameter value
 * In case of a persistent object, this parameter must be aggregated.
 * @return parameter created
 */
virtual CATICkeParm_var CreateString  (const CATUnicodeString &iParameterName,
									   const CATUnicodeString &iParameterValue) = 0;

/**
 * Creates integer parameter.
 * @param iParameterName  parameter name (never changed)
 * @param iParameterValue parameter value
 * In case of a persistent object, this parameter must be aggregated.
 * @return parameter created
 */
virtual CATICkeParm_var CreateInteger (const CATUnicodeString &iParameterName,
									   const int iParameterValue) = 0;

/**
 * Creates boolean parameter.
 * @param iParameterName parameter name (never changed)
 * @param iParameterValue parameter value
 * In case of a persistent object, this parameter must be aggregated.
 * @return parameter created
 */
virtual CATICkeParm_var CreateBoolean (const CATUnicodeString &iParameterName,
									   const CATCke::Boolean iParameterValue) = 0;

/**
 * Creates real parameter.
 * @param iParameterName parameter name (never changed)
 * @param iParameterValue parameter value
 * In case of a persistent object, this parameter must be aggregated.
 * @return parameter created
 */
virtual CATICkeParm_var CreateReal    (const CATUnicodeString &iParameterName,
									   const double    iParameterValue) = 0;


/**
 * Creates length parameter.
 * @param iParameterName parameter name (never changed)
 * @param iParameterValue parameter value in MKS !!! (i.e. meters)
 * In case of a persistent object, this parameter must be aggregated.
 * @return parameter created
 */
virtual CATICkeParm_var CreateLength  (const CATUnicodeString &iParameterName,
									   const double    iParameterValue) = 0;

									   
/**
 * Creates angle parameter.
 * @param iParameterName parameter name (never changed)
 * @param iParameterValue parameter value in MKS !!! (i.e. radian)
 * In case of a persistent object, this parameter must be aggregated.
 * @return parameter created
 */
virtual CATICkeParm_var CreateAngle   (const CATUnicodeString &iParameterName,
									   const double    iParameterValue) =0;

/**
 * Do not use it. Use CreateDimension (CATParmDictionary::FindMagnitude("TIME")) instead
 * Creates time parameter.
 * @param iParameterName parameter name (never changed)
 * @param iParameterValue parameter value in MKS !!! (i.e. second)
 * @return parameter created
 */
virtual CATICkeParm_var CreateTime   (const CATUnicodeString &iParameterName,
									  const double    iParameterValue) =0;

/**
 * Do not use it. Use CreateDimension (CATParmDictionary::FindMagnitude("MASS")) instead
 * Creates mass parameter.
 * @param iParameterName parameter name (never changed)
 * @param iParameterValue parameter value in MKS !!! (i.e. gram)
 * @return parameter created
 */
virtual CATICkeParm_var CreateMass   (const CATUnicodeString &iParameterName,
									  const double    iParameterValue) =0;

/**
 * Creates dimension parameter.
 * @param iMagnitude parameters type
 * @param iParameterName parameter name (never changed)
 * @param iParameterValue parameter value in MKS !!! 
 * @return parameter created
 */
virtual CATICkeParm_var CreateDimension (const CATICkeMagnitude_var &iMagnitude,
                                         const CATUnicodeString &iParameterName,
                                         const double iParameterValue) =0;  // raises InvalidType

/**
 * Creates dimension parameter.
 * @param iMagnitude parameters type
 * @param iParameterName parameter name (never changed)
 * @param iParameterValue parameter value 
 * @return parameter created
 */
virtual CATICkeParm_var CreateDimension (const CATICkeMagnitude_var &iMagnitude,
                                         const CATUnicodeString &iParameterName,
                                         const CATICkeInst_var &iParameterValue) =0; // raises InvalidType, UnrecognisedUnit

/**
 * Creates an enumerated parameter from rank name (1 to n).
 * @param iEnumereType enumerated type 
 * @param iParameterName parameter name
 * @param iParameterRank parameter rank (from 1 to n)
 * @return parameter created
 */
virtual CATICkeParm_var CreateEnumere (const CATIEnumere_var   &iEnumereType,
                                       const CATUnicodeString  &iParameterName,
                                       const int                iParameterRank) = 0; 
/**
 * Creates a literal from its type.
 * @param iParameterType parameter type
 * @param iParameterName parameter name
 * @return parameter created
 */
virtual CATICkeParm_var CreateLiteral (const CATICkeType_var   &iParameterType,
                                       const CATUnicodeString  &iParameterName) = 0;
  


/**
 * Creates a MKS Unit equivalent to a scalar.
 * This is a C++ object in any case.
 * @return pMKS equivalent created
 */
virtual CATICkeMKSUnit_var   CreateMKSUnit () = 0;

/**
 * Creates a MKS Unit equivalent to a primitive magnitude.<br>
 * (example m2, s-1).
 * @param iBasicMagnitude primitive magnitude
 * @param iCoeff exponent
 * @return CATICkeMKSUnit_var  MKSUnit created
 * This is a C++ object in any case.
 */
virtual CATICkeMKSUnit_var   CreateMKSUnit (const CATICkeMKSUnit::Basic iBasicMagnitude,
											const int iCoeff) = 0;

/**
 * Creates a MKS Unit equivalent to a combination of primitive magnitude.<br>
 * (example kgxs-2)
 * @param iMeterCoeff exponent for length
 * @param iKilogramCoeff exponent for mass
 * @param iSecondCoeff exponent for time
 * @param iAmperCoeff exponent for amper
 * @param iTemperatureCoeff exponent for temperature
 * @param iCandelaCoeff exponent for candela
 * @param iMoleNumberCoeff exponent for mole number
 * @param iPriceCoeff exponent for price
 * @param iRadianCoeff exponent for radian
 * @param iSteradianCoeff exponent for steradian
 * This is a C++ object in any case.
 * @return pMKS equivalent created
 */
virtual CATICkeMKSUnit_var   CreateMKSUnit (const int iMeterCoeff,
                                            const int iKilogramCoeff,
                                            const int iSecondCoeff,
                                            const int iAmperCoeff,
                                            const int iTemperatureCoeff,
                                            const int iCandelaCoeff,
                                            const int iMoleNumberCoeff,
                                            const int iPriceCoeff,
                                            const int iRadianCoeff,
                                            const int iSteradianCoeff) = 0;
     


/**
 * @nodoc to be suppressed in V5R15. Critical because we cannot support the creation of enumere types in any container! To be managed by FSA.
 * Creates an enumerated type (startup). Watch out. This should be used only to define Catalogs
 * @param iEnumName enum type name
 * @param iValues list of possible values
 * @return enumere type created
 */
virtual CATIEnumere_var CreateEnumereType (const CATUnicodeString &iEnumName,
                                           const CATListOfCATUnicodeString &iValues) = 0;
  

/**
 * Creates an enumerated parameter from value.
 * @param iEnumereType enumerated type 
 * @param iParameterName parameter name
 * @param iParameterValue parameter value
 * @return parameter created
 */
virtual CATICkeParm_var CreateEnumere (const CATIEnumere_var &iEnumereType,
                                       const CATUnicodeString          &iParameterName,
                                       const CATUnicodeString          &iParameterValue) = 0; 

 

/**
 * Creates a parm manipulator. This manipulator will not change the persistent parameters range.
 * This method is used to build a manipulator that will block temporarily the user manipulations.
 * In no case this manipulator will change the persistent bounds of the parameter.
 * If you want to persistently change the bounds of the parameter refer to the CATICkeParm interface.
 * <br>
 * Use only on Volatile Factory.
 * @return parameter manipulator created
 */
virtual CATIParmManipulator_var  CreateParmManipulator () = 0;



/**
 * Creates object reference.<br>
 * An object reference is a way to see an object as a parameter in order to use it in Knowledge expressions or Knowledge relations,<br>
 * Such an object reference can only be used in input of Knowledgeware relations or expressions.<br>
 * @param iFeature feature to be referenced : should implement @href CATICkeFeature or @hret CATICkeObject.
 * @return CATICkeParm_var object reference created
 */
virtual CATICkeParm_var CreateObjectReference  (const CATBaseUnknown_var &iFeature) = 0;

/**
 * Initialise Literals Catalog and wakes up all relations.<br>
 * Should be done when creating a new container or loading it.<br>
 * This method replaces InitStartups. It loads the Literals.feat catalog and does InitStartups on it.<br>
 * This should be used on the feature container where relations have been stored.<br>
 */
    virtual void InitAndWakeUp () = 0;
  

/**
 * Creates an empty object reference of a given type.<br>
 * We recommend not to use this method.<br>
 * @param iType type of the object reference
 * @param iName name of the object reference
 * @return parameter created
 */
	virtual CATICkeParm_var CreateObjectReference  (const CATICkeType_var &iType,const CATUnicodeString &iName ) = 0;



/**
 * Creates a literal from another by copying its value.
 * Note that at the end, the parameter is not aggregated.
 * One option is to copy the existing formula that valuates the literal if any,<br>
 * The formula is also not aggregated. It will reference the same input parameters as the original formula.
 * @param iParameterToCopy parameter to copy
 * @param iWithFormula indicates if we wish to copy the formula (note that the formula copied won't be agregated to anything).
 * <br><b>Legal values</b>: 
 * <tt>0</tt> No copy of the formula.
 * <tt>1</tt> Copy of the formula.
 * @return literal copied
 */
virtual CATICkeParm_var Copy (const CATICkeParm_var     &iParameterToCopy,
					          const CATCke::Boolean     &iWithFormula = 0) = 0 ;


/**
* @nodoc Use CATICkeRelationFactory::Copy method instead.<br>
 * Creates a relation from another by copying it.
 * Works on formula only
 * Note that second relation will reference the same parameters, so il will be deactivated.
 * The copied relation is not aggregated.
 * @param iRelationToCopy parameter to copy
 * @return CATICkeRelation_var relation copied
 */
virtual CATICkeRelation_var Copy (const CATICkeRelation_var     &iRelationToCopy) = 0 ;


/**
* @nodoc to be suppressed
*/
virtual void InitFactory() = 0;

/**
 * Creates a List object.<br>
 * @param iName name of the list.
 * The object must be aggregated.
 * @return list created
 */
virtual CATIList_var   CreateList (const CATUnicodeString &iName) = 0;
     

/**
 * Creates a date parameter.
 * @param iParameterName parameter name (never changed)
 * @param iParameterValue parameter value in MKS !!! (i.e. radian)
 * In case of a persistent object, this parameter must be aggregated.
 * @return parameter created
  */
virtual CATICkeParm_var CreateDate (const CATUnicodeString& iParameterName,const CATTime& iParameterValue) = 0;


private :  

  // 2 define ClassName
  CATDeclareInterface;

};


CATDeclareHandler(CATICkeParmFactory,CATBaseUnknown);


#endif

