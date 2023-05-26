#ifndef CATICkeParm_h
#define CATICkeParm_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/** 
 * @CAA2Level L1
 * @CAA2Usage U3
 */

/*  CAA2Reviewed by FRH */

// module declaration
#include "CATLifSpecs.h"

// inherited from
#include "CATBaseUnknown.h"

// forward declaration
#include "CATICkeRelationForwards.h"

// interfaces used  
#include "CATICkeInst.h"
#include "CATICkeUnit.h"
#include "CATIParmPublisher.h"
#include "CATIParmValuator.h"
#include "CATICkeNaming.h"
#include "CATTime.h"

// OLE iid
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATLifSpecs IID_CATICkeParm;
#else
extern "C" const IID IID_CATICkeParm;
#endif

/**   
 * Interface dedicated to parameters management.
 * <b>Role</b>: manages informations on parameters.<br>
 * A Parameter is a variable with a name and a content that can be passed as an argument of a Knowledge expression for its evaluation.<br>
 * It can be read or written inside a Knowledge expression (its content is changed or replaced).<br>
 * Several objects are parameters<br>
 * - Literal: a persistent value, owned by a feature. It can be of type Boolean, Integer, Real, String, or any subtype of dimensions and enumerated types that exist in the dictionary.<br>
 * A Literal can be recognized through the following test: p->Type()->IsaKindOf(CATCkeGlobalFunctions::GetParmDictionary()->FindType("Literal")).<br>
 * - Volatile value: a non persistent value. It can be of the same type as persistent values.<br>
 * - List feature: a feature that allows to reference a set of persistent objects or literals.<br>
 * A List can be recognized through the following test:  p->Type()->IsaKindOf(CATCkeGlobalFunctions::GetParmDictionary()->FindType("List")).<br>
 * A List is a sub type of the Feature type (CATCkeGlobalFunctions::GetParmDictionary()->GetFeatureType()).<br>
 * - Volatile List: a non persistent object that allows to reference a set of objects or values.<br>
 * - Geometric datum: a geometrical object provided by GSMModel framework.<br>
 * - Reference to V5 objects: a simple reference to an object which becomes the content of the parameter.<br>
 * A Reference to V5 object can be recognized through the following test: p->Type()->IsaKindOf(CATCkeGlobalFunctions::GetParmDictionary()->GetFeatureType())
 * Some parameters are persistent (Literal, list feature, geometric datum, or reference to V5 persistent object).
 * They can be used in the definition of Knowledge relations.<br>
 * Parameters can be created with a factory @href CATICkeParmFactory <br>
 * This interface is multi implemented
 * @see CATIParmAsStored,CATIParmManipulator
 */
//-----------------------------------------------------------------------------
class ExportedByCATLifSpecs CATICkeParm: public CATBaseUnknown
{

public :

  /**
   * Rights defined on a parameter.
   * Used to define how this parameter can be used through Knowledgeware.<br>
   * <br><b>Legal values</b>:
   * <tt>NotSeen</tt> this parameter is not seen by the user.
   * <tt>ReadOnly</tt> the parameter will be seen but won't be modified, may be used as input of a relation.
   * <tt>ReadWrite</tt> Default value:the parameter can be modified, and used as output of a relation
   * <tt>User</tt> this is a parameter created by a end-user. It can  be destroyed
   * Once defined, this information shouldn't be modified
   */
  enum UserAccessMode  
  {
    NotSeen  	= 0,   
    ReadOnly    = 1,  
    WriteOnly   = 2,  
    ReadWrite	= 3, 
    User        = 4    
  };



/**
 * Returns the type of the parameter.
 */
virtual CATICkeType_var Type () const =0;



/**
 * Returns the name overidden by user (if any).
 * example : "x" .<br>
 */
virtual CATUnicodeString Name () const =0;

/**
 * Overrides name of parameter.
 * (if value == "" the parameter will have no overriden name anymore)<br>
 * @param  iNewName name
 */
virtual void Rename (const CATUnicodeString &iNewName) =0;

/**
 * Indicates if the parameter name has been overidden by a user.
 * @return <b>Legal values</b>:
 * <tt>CATCke::True</tt> if it is renamed.
 * <tt>CATCke::False</tt> if it isn't.
 */
virtual CATCke::Boolean IsNamed () const = 0;

/**
 * Returns the pathname of a parameter from a context.
 * example : "PartBody\Hole.1\Diameter" <br>
 * @param iRoot context object
 * @return The pathname
 */
virtual CATUnicodeString  Pathname (const CATIParmPublisher_var &iRoot = NULL_var) const = 0;

/**
 * Returns the relative name of a parameter from a context.
 * example : "x" or "PartBody\Hole.1\Diameter"
 * If name is overidden, returns this name else returns pathname
 * Should be used to show a literal to the user 
 * @param iRoot context
 * @return The relative name
 */
virtual CATUnicodeString  RelativeName (const CATIParmPublisher_var &iRoot = NULL_var) const = 0;

/**
 * Returns the function of a parameter in its context.
 * The string returns is NLS.
 * @param iRoot CATIParmPublisher that contains the literal and which is able to name it
 * @return The function of a parameter in its context
 */
virtual CATUnicodeString Role (const CATIParmPublisher_var &iRoot = NULL_var) const = 0;


/**
 * Indicates if this parameter is local to a relation set.
 * @return <b>Legal values</b>:
 * <tt>CATCke::True</tt> if it is local.
 * <tt>CATCke::False</tt> if it isn't.
 */
virtual CATCke::Boolean IsLocal () const = 0;


  //----------------------------------------------
  // have a look at a literal
  //----------------------------------------------

/**
 * Returns the way of seeing a parameter in the current unit.
 * This method should not be used to interpret the value. Only for visualization purpose.
 * example : "3mm"
 */
virtual CATUnicodeString Show () const =0; 

/**
 * Returns the content (show without unit suffix).
  * This method should not be used to interpret the value. Only for visualization purpose.
 * example "3". 
 */
virtual CATUnicodeString Content () const =0; 

/**
 * Shows a parameter in a given unit.
 * example "3 km".
 * @param iUnit unit
 * @return a string that enables to show the value of a parameter in a given unit
 */
virtual CATUnicodeString ShowReal (const CATICkeUnit_var &iUnit) const =0; // raises BadUnit 



/**
 * Indicates if a parameter can be valuated or not. 
 * it is read only 
 *  -when the user access say so or when it is valuated by a relation
 *  -or when its visibility is false
 * @return  <b>Legal values</b>:
 * <tt>CATCke::True</tt> if it is read only.
 * <tt>CATCke::False</tt> if it isn't.
 */
virtual CATCke::Boolean IsReadOnly () const =0;


/**
 * @nodoc. Useless in CAA.
 * This format is a non persistent information associated to a parameter that explains how to produce the value returned by the show method.
 * @param pf the format
 */
virtual void SetFormat (const CATIParmFormat_var &pf) = 0;

/** 
 * @nodoc. Useless in CAA.
 * This format is a non persistent information associated to a parameter that explains how to produce the value returned by the show method.
 * @return  the format
 */
virtual CATIParmFormat_var  Format () const = 0;



  //----------------------------------------------
  // Value Management :
  // ----------------
  // a parm has a value which is a CATICkeInst_var
  // special cases : Real, CATUnicodeString, CATCke::Boolean, int
  //----------------------------------------------

/**
 * Returns its value. 
 */
virtual CATICkeInst_var Value   () const = 0;

/**
 * Valuates the content of this parameter with the content of another parameter in argument.<br>
 * Both parameters must be compatible: <br>
 * If the current parameter is a value, the value in argument must be a subtype of the current value.<br>
 * If the current parameter is a reference to feature, the value in argument must be a subtype of the type of the current value.<br>
 * If the current parameter is a List, the value in argument must be a List also. As the content is copied, it must be compatible also (only persistent objects can be added to a list feature).<br>
 * If the current parameter is a Geometric datum, the value in argument must be a geometry sub type of the current parameter.
 * @param  iValue value to set
 */
virtual void Valuate (const CATICkeInst_var &iValue) = 0; // raises ConstObject, InvalidType 

/**
 * Valuates a literal or volatile value from an integer.<br>
 * Raises an exception if the parameter content is not a sub type of real, an integer or enumerated value.
 * @param iValue value to set
 */
virtual void Valuate (const int iValue) = 0;   // raises InvalidType, ConstObject 
/**
 * Valuates a literal or volatile value from a double (in MKS).<br>
 * Raises an exception if the parameter content is not a sub type of real.
 * @param iValue value to set
 */
virtual void Valuate (const double iValue) = 0;      // raises InvalidType, ConstObject 

/**
 * Valuates a literal or volatile value from a String.<br>
 * Raises an exception if parameter content is not a String or an enumerated value.
 * @param iValue value to set
 */
virtual void Valuate (const CATUnicodeString &iValue) = 0;    // raises InvalidType, ConstObject 

/**
 * Valuates a literal or volatile value from a boolean.<br>
 * Raises an exception if parameter content is not a boolean.
 * @param iValue value to set
 */
virtual void Valuate (const CATCke::Boolean iValue) = 0;   // raises InvalidType, ConstObject 

/**
* Valuates a literal or volatile value from a date.<br>
* Raises an exception if parameter content is not a date.
* @param iValue value to set
*/
virtual void Valuate (const CATTime iValue) = 0;   // raises InvalidType, ConstObject 

/**
 * Sets a parameter or volatile value, sub type of dimension, from a string with unit.
 * (ex "3cm")
 * @param iValue string
 */
virtual void ValuateReal (const CATUnicodeString &iValue) = 0;    // raises InvalidType, ConstObject,
                                                   // BadUnit, UnrecognisedUnit 

/**
 * Indicates if this parameter is set or unset.
 * Default value is always Set 
 * @return <b>Legal values</b>:
 * <tt>CATCke::True</tt> if it is set
 * <tt>CATCke::False</tt> if it isn't.
 */
virtual CATCke::Boolean IsSet () const = 0;

/**
 * Unsets this parameter.
 */
virtual void Unset () = 0;  



  //----------------------------------------------
  // rights
  //----------------------------------------------
/**
 * Indicates if this parameter is const or not.
 * Default value is always not Const 
 * @return <b>Legal values</b>:
 * <tt>CATCke::True</tt> if it is constant
 * <tt>CATCke::False</tt> if it isn't.
 */
virtual CATCke::Boolean IsConst () const = 0;

/**
 * Sets Const facet.
 * Default value is always not Const 
 * @param iConstant
 * <b>Legal values</b>:
 * <tt>CATCke::True</tt> if it is constant
 * <tt>CATCke::False</tt> if it isn't.
 */
virtual void SetConst (const CATCke::Boolean iConstant) = 0; 

/**
 * Returns the rights on this parameter.
 * <b>Legal values</b>:
 * <tt>NotSeen</tt> this parameter is not seen by the user.
 * <tt>ReadOnly</tt> the parameter will be seen but won't be modified, may be used as input of a relation.
 * <tt>ReadWrite</tt> Default value:the parameter can be modified, and used as output of a relation
 * <tt>User</tt> this is a parameter created by a end-user. It can  be destroyed
 */
virtual CATICkeParm::UserAccessMode UserAccess () const = 0;

/**
 * Sets the rights on this parameter.
 * @param iRights: 
 * <b>Legal values</b>:
 * <tt>NotSeen</tt> this parameter is not seen by the user.
 * <tt>ReadOnly</tt> the parameter will be seen but won't be modified, may be used as input of a relation.
 * <tt>ReadWrite</tt> Default value:the parameter can be modified, and used as output of a relation
 * <tt>User</tt> this is a parameter created by a end-user. It can  be destroyed 
 */
virtual void SetUserAccess (const CATICkeParm::UserAccessMode iRights) = 0; 

/**
 * @nodoc to be suppressed
 */
virtual CATCke::Boolean Visibility () const = 0;

/**
 * @nodoc to be suppressed
 */
virtual void SetVisibility (const CATCke::Boolean b) = 0;


  //----------------------------------------------
  // manipulator
  //----------------------------------------------
/**
 * Creates a persistent manipulator if none is referenced in the parameter (BEWARE).
 * <br>BEWARE: This method returns a persistent manipulator. All the modifications done on the parameter will be saved in the model. To temporarily (from a volatile point of view) change the bounds of a parameter, follow this procedure:
 * <br>1- CATIParmManipulator_var spVolatileManipulator = CATICkeParmFactory::CreateParmManipulator ()
 * <br>2- CATICkeParm::SetManipulator( spVolatileManipulator );
 * <br>3- spVolatileManipulator -> SetRange() or AddMultipleValues()...;
 * <br>Note that just one persistent manipulator can be created on a parameter and the last volatile manipulator's reference can be kept in the parameter.
 * <br>
 * @return
 *  The persistent manipulator referenced in the parameter if any, otherwise, it creates a new one.
 *
 */
virtual CATIParmManipulator_var CreateManipulator () const = 0;

/**
 * References a volatile manipulator in the parameter (BEWARE).
 * <br>BEWARE: This method references a volatile manipulator in the parameter. All the modifications done on the parameter will not be saved in the model. To persistently (from a persistent point of view) change the bounds of a parameter follow this procedure:
 * <br>1- CATIParmManipulator_var spPersitentManipulator = param->CreateManipulator();
 * <br>2- spPersitentManipulator -> SetRange() or AddMultipleValues()...;
 * <br>Note that just one persistent manipulator can be created on a parameter and the last volatile manipulator's reference can be kept in the parameter.
 * <br>
 *  @param iManipulator volatile manipulator.
 */
virtual void SetManipulator (const CATIParmManipulator_var &iManipulator) = 0;

/**
 * Returns the persistent manipulator referenced in the parameter (BEWARE).
 * <br>BEWARE: This method returns the persistent manipulator referenced in the parameter. All the modifications done on the parameter will be saved in the model. To temporarily (from a volatile point of view) change the bounds of a parameter, follow this procedure:
 * <br>1- CATIParmManipulator_var spVolatileManipulator = CATICkeParmFactory::CreateParmManipulator ()
 * <br>2- CATICkeParm::SetManipulator( NULL_var ); ); If you wish to delete the last volatile manipulator. 
 * <br>3- CATICkeParm::SetManipulator( spVolatileManipulator );
 * <br>4- spVolatileManipulator -> SetRange() or AddMultipleValues()...;
 * <br>
 * @return
 *  The manipulator referenced in the parameter. It could have been created using the method @href CATICkeParm#CreateManipulator or set using the method @href CATICkeParm#SetManipulator.
 */
virtual CATIParmManipulator_var Manipulator () const = 0;








  //----------------------------------------------
  // Relation management :
  // -------------------
  // a parm can be valuated by a relation 
  // a parm is used by (0 to N) relations in Read mode
  //----------------------------------------------

/**
 * Returns the active relation valuating the parameter.
 */
virtual CATIParmValuator_var Relation() const = 0;

/**
 * Sets the active relation valuating parameter.
 * @param iValuating relation (can be NULL_var)
 * @param iStrong: 
 * <br><b>Legal values</b>:
 * <tt>CATCke::True</tt> sets an input and persistant update link between parameter and valuating.
 * <tt>CATCke::False</tt> .
 * Note that the parameter and the iValuating must be in the same container. This will be enforced in the future to allow
 * only authorized data models.
 */
virtual void SetRelation(const CATIParmValuator_var &iValuating,const CATCke::Boolean &iStrong = 0 ) = 0;

/**
 * Returns the list of relations linked to this parameter corresponding to a criteria.
 * @param iCriteria
 * <br><b>Legal values</b>:
 * <tt>1</tt> returns the relations where this parameter is in input.
 * <tt>2</tt> returns the relations where this parameter is in output.
 * <tt>0</tt> returns the relations where this parameter is in input or output.
 * @return list of relation :  the list is allocated : Please desallocate
 */
virtual CATCkeListOfRelation ImpactedRelations (const int iCriteria = 0) = 0;



/**
 * This method can be used on three kinds of parameters.<br>
 * It valuates a reference to object parameter with a feature.<br>
 * It is used also to valuate a geometrical datum with a the topology result of a feature.<br>
 * Finally, it can be used to valuate a list with another list. In this case, the content of the current list is replaced by the content of the list in argument.<br>
 * Raises an exception if the parameter content is not a sub type of Feature in the first case and if the type of the parameter in argument is not a subtype of the parameter itself.<br>
 * Raises an exception if the feature in argument does not fit with the type of the datum.<br>
 * Raises an exception if the feature in argument is not a list. Finally, note that a volatile list can be valuated by any kind of list.But a list feature must be valuated by a list 
 * where each element is persistent.
 * 
 * @param iFeature value to set
 */
virtual void ValuateObject (const CATBaseUnknown_var  &iFeature) = 0; // raises InvalidType, ConstObject 



/**
 * Indicates if this parameter is hidden or shown.
 * Default value is always Shown 
 * @return <br><b>Legal values</b>: 
 * <tt>CATCke::True</tt> if it is hidden
 * <tt>CATCke::False</tt> if it isn't.
 */
virtual CATCke::Boolean IsHidden () const = 0;

/**
 * Sets HideShow facet.
 * Default value is always Shown
 * @param b <br><b>Legal values</b>: 
 * <tt>CATCke::True</tt> if it is hidden
 * <tt>CATCke::False</tt> if it isn't.
 */
virtual void SetHidden (const CATCke::Boolean b) = 0; 

/**
 * Returns the internal role of parameter in its context.
 * It is the name given to the parameter at its creation
 */
virtual CATUnicodeString InternalRole () const = 0;

/**
 * Sets the internal role of a parameter.
 * This shouldn't be done on a non User parameter
 * @param iRole Internal role
 */
virtual void SetInternalRole (const CATUnicodeString &iRole) = 0;



/**
 * Returns the value of the parameter in the current unit while respecting the ISO standard.
 * @return
 *  The value of the parameter in the current unit while respecting the ISO standard, 
 *  <br>i.e. : if the setting called "Decimal places for read/write numbers" (used for the display of units) = 3
 *  <br>and if the parameter's value in current unit (e.g. mm) = 0.001, 
 *  <br> returns "0mm"
 *  <br>otherwise, if parameter's value in current unit (e.g. mm) = 0.001,
 *  <br> returns "0.001mm".
 */
virtual CATUnicodeString ShowIso () const = 0;

/**
 * Returns the value of the parameter without unit suffix while respecting the ISO standard.
 * @return
 *  The value of the parameter without unit suffix while respecting the ISO standard, 
 *  <br>i.e. : if the setting called "Decimal places for read/write numbers" (used for the display of units) = 3
 *	<br>and if the parameter's value in current unit = 0.001,	
 *	<br> returns "0"
 *	<br>otherwise, if parameter's value in current unit = 0.001,
 *	<br> returns "0.001".
 */
virtual CATUnicodeString ContentIso () const = 0;

/**
 * Returns the value of the parameter in a given unit while respecting the ISO standard.
 * @return
 *  The value of the parameter in the unit given as parameter while respecting the ISO standard, 
 *  <br>i.e. : if the setting called "Decimal places for read/write numbers" (used for the display of units) = 3
 *	<br>and if the parameter's value converts in the given unit (e.g. mm) = 0.001,	
 *	<br> returns "0mm"
 *	<br>otherwise, if parameter's value converts in the given unit (e.g. mm) = 0.001,
 *	<br> returns "0.001mm".
 * @param iUnit
 *   Unit in which the value of the parameter is shown.
 */
virtual CATUnicodeString ShowRealIso (const CATICkeUnit_var & iUnit) const = 0;


private:

  // 2 define ClassName
  CATDeclareInterface;

}; 

CATDeclareHandler(CATICkeParm,CATBaseUnknown);

#endif


