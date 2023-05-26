/**  	   	   	 
* @level Protected 	  	  	 
* @usage U1 	  	  	 
*/

// Copyright Dassault Systemes 2000
#ifndef CATCkeContext_h
#define CATCkeContext_h
/**
 * DO NOT USE, DO NOT INCLUDE, JUST STAY AWAY
 */

// module
#include "CATLifDictionary.h"


#include "CATCke.h"
#include "CATIAV5Level.h"
#include "CATErrors.h" 
#include "CATCkeContextDefs.h"
#include "CATCkeForwards.h"

#include "CATParmDictionary.h"

// exceptions
#include "CATCkeExc.h"
#include "CATCkeExcDefs.h"
#include "CATCkeDefs.h"
#include "CATCkeStream.h"

class ExportedByCATLifDictionary CATCkeContext : public CATCke
{
public:

  /**
   * PLEASE DO NOT USE THESE HORRIBLE STATICS...
   * THEY ARE INITIALIZED/RELEASED THROUGH UNUNDERSTANDABLE INIT STUFF
   * USE CATParmDictionary::FindType INSTEAD
   */
  static CATICkeType_var ObjectType;
  static CATICkeType_var HolderType;
  static CATICkeType_var AtomType;
  static CATICkeType_var EnumType;
  static CATICkeType_var DimensionType;
  static CATICkeType_var DictionnaryType;
  static CATICkeType_var UndefinedType;
  static CATICkeType_var ValidEntitiesTypes;
  static CATICkeType_var TermType;
  static CATICkeType_var ExprType;
  static CATICkeType_var FormalVarType;
  static CATICkeType_var ConstantType;
  static CATICkeType_var ClauseType;
  static CATICkeType_var ProcedureType;
  static CATICkeType_var FunctionnalExprType;
  static CATICkeType_var InstructionType;
  static CATICkeType_var ComposedInstrType;
  static CATICkeType_var StatementType;
  static CATICkeType_var IfThenDType;
  static CATICkeType_var RuleType;
  static CATICkeType_var ConstraintType;
  static CATICkeType_var ProgramType;
  static CATICkeType_var ValuationType;
  static CATICkeType_var SetOfEquationType;
  static CATICkeType_var RelationType;
  static CATICkeType_var RelationSymType;
  static CATICkeType_var RelationExpType;
  static CATICkeType_var RelationExpFctType;
  static CATICkeType_var RelationExpPgType;
  static CATICkeType_var SeverityType;
  static CATICkeType_var RelationExpCtrType;
  static CATICkeType_var RelationSetType;
  static CATICkeType_var OptimizationSetType;
  static CATICkeType_var ParameterSetType;
  static CATICkeType_var RelationExpEquType;
  static CATICkeType_var OptConstraintType;
  static CATICkeType_var OptConstraintExpType;
  static CATICkeType_var LawType;
  static CATICkeType_var PredicateType;
  static CATICkeType_var CkeActionType;
  static CATICkeType_var SignatureType;
  static CATICkeType_var BlockType;
  static CATICkeType_var MethodType;
  static CATICkeType_var CompoundType;
  static CATICkeType_var OperatorType;
  static CATICkeType_var FunctionType;
  static CATICkeType_var DesignTableType;
  static CATICkeType_var DTSheetType;
  static CATICkeType_var DTTextSheetType;
  static CATICkeType_var DTLotusSheetType;
  static CATICkeType_var DTModelSheetType;
  static CATICkeType_var FeatureType;
  static CATICkeType_var BehaviourType;
  static CATICkeType_var BehaviourBaseType;
  static CATICkeType_var GradientType;
  static CATICkeType_var SimAnnealingType;
  static CATICkeType_var GradientApproxType;
  static CATICkeType_var DoeType;
  static CATICkeType_var OptApproxAlgoType;
  static CATICkeType_var OptLocalWPrioritiesAlgoType;
#ifndef CATIAR203
  static CATISpecObject_var OptMultiConstraintType;
  static CATISpecObject_var OptSolutionsType;
  static CATISpecObject_var OptFreeParameterType;
  static CATISpecObject_var OptGoalType;
  static CATISpecObject_var OptProblemType;
  static CATISpecObject_var OptOptimizationType;
  static CATISpecObject_var DeletedFeatureStartUp;
#else
  static CATBaseUnknown_var DeletedFeatureStartUp;
#endif
  static CATICkeType_var ListType;
  static CATICkeType_var MacroWithArgsType;
  static CATICkeType_var ActionType;
  static CATICkeType_var ReactionType;
  static CATICkeType_var ConstraintSatisfactionType;
  static CATICkeType_var UndeterminedType;
  static CATICkeType_var EquivalentDimensionsType;
  static CATICkeType_var KwePatternType;

  // factories
  static CATCkeUsrFactory* UsrFactory;

  // methods 

  // to convert a string into an integer
  static int AtoI (CATUnicodeString);

  // to convert an integer into a string
  static CATUnicodeString  ItoA (int);

  // to convert a real into a string
  static CATUnicodeString  RtoA (double);

  // to convert a string into a real : return value indicates if conversion succeeds 
  static CATCke::Boolean AtoR (const CATUnicodeString,double &);
  static CATCke::Boolean Convert (const CATUnicodeString,double &);

  // eliminates french stresses to be able to parse a string 
  // converts space into underscore
  static CATUnicodeString  LexxCleanUp (const CATUnicodeString &s);


  // to replace double quotes
  static void RemoveDoubleCote (CATUnicodeString& chaine);

protected:

  CATCkeContext ();
  CATCkeContext (const CATCkeContext&);
  virtual ~CATCkeContext() ;
};

#endif




