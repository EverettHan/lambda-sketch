// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATOmbPLMRelationshipSemantics.h
// Header definition of CATPLMRelationshipSemantics
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  May 2005  Creation:   gdp
//===================================================================
#ifndef CATOmbPLMRelationshipSemantics_H
#define CATOmbPLMRelationshipSemantics_H

#include "CATObjectModelerBase.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"


class CATListValCATOmbPLMRelationshipSemantics;
class CATUnicodeString;
class CATPLMRelationshipSemantics;

/**
 * @level Private
 * @usage U1
 */

/**
* class to expose semantics (behaviors) relative to a category of a semantic relation. 
* The category is defined by its name.
* The semantics are :
*    PropagOnDelete
*    Visibility
*    Orientation
*    SynchroSensitivity
*/
class ExportedByCATObjectModelerBase CATOmbPLMRelationshipSemantics
{
public:

  /**
  * enum defining the possible values for the PropagOnDelete behaviour. 
  */
  enum OmbSRPropagOnDelete {POD_NONE};
  /**
  * enum defining the possible values for the Visibility behaviour. 
  */
  enum OmbSRVisibility {V_NO, V_YES};
  /**
  * enum defining the possible values for the Orientation behaviour. 
  */
  enum OmbSROrientation   {O_NEUTRAL, O_IN, O_OUT, O_INOUT};
  /**
  * enum defining the possible values for the SynchroSensitivity behaviour. 
  */
  enum OmbSRSynchroSensitivity {SS_NONE,SS_LAST,SS_PATH,SS_PATHANDLAST};
	/**
  * enum defining the possible values for the MinorSensitivity behaviour. 
  */
  enum OmbSRMinorSensitivity {MS_NO, MS_YES};

  /**
  * default constructor.
  */
  CATOmbPLMRelationshipSemantics();

  /**
  * constructor.
  * @param iName
  *   The name of the category.
  * @param iPropagOnDelete
  *   The value of the PropagOnDelete behavior.
  * @param iVisibility
  *   The value of the Visibility behavior.
  * @param iOrientation
  *   The value of the Orientation behavior.
  * @param iSynchroSensitivity
  *   The value of the SynchroSensitivity behavior.
	* @param iMinorSensitivity
	*		The value of the MinorSensitivity behavior.
	*		Default is NO.
  */
	CATOmbPLMRelationshipSemantics (const CATUnicodeString& iName, OmbSRPropagOnDelete iPropagOnDelete, OmbSRVisibility iVisibility, OmbSROrientation iOrientation, OmbSRSynchroSensitivity iSynchroSensitivity, OmbSRMinorSensitivity iMinorSensitivity = CATOmbPLMRelationshipSemantics::MS_NO);
  virtual ~CATOmbPLMRelationshipSemantics ();

  /**
  * constructor.
  * @param original
  *   Original object to copy.
  */
  CATOmbPLMRelationshipSemantics (const CATOmbPLMRelationshipSemantics & original);

  /**
  * operator=.
  * @param original
  *   Original object.
  */
  CATOmbPLMRelationshipSemantics& operator=(const CATOmbPLMRelationshipSemantics& original);

  /**
  * operator==.
  * @param iToCompare
  *   Object to compare with this.
  * @return 
  *   1 if iToCompare._Name == this._Name
  *   0 else
  */
  int operator==(const CATOmbPLMRelationshipSemantics& iToCompare) const;

  /**
  * operator!=.
  * @param iToCompare
  *   Object to compare with this.
  * @return 
  *   0 if iToCompare._Name == this._Name
  *   1 else
  */
  int operator!=(const CATOmbPLMRelationshipSemantics& iToCompare) const;

  /**
  * Gets the name of the category, and the semantics associated.
  * @param oName
  *   The name of the category.
  * @param oPropagOnDelete
  *   The value of the PropagOnDelete behavior.
  * @param oVisibility
  *   The value of the Visibility behavior.
  * @param oOrientation
  *   The value of the Orientation behavior.
  * @param oSynchroSensitivity
  *   The value of the SynchroSensitivity behavior.
	* @param iMinorSensitivity
	*		The value of the MinorSensitivity behavior.
	*		Default is NO.
  * @return
  *   E_FAIL if this is not valid, if it has not been affected by the parsing.
  *   S_OK else.
  */
  HRESULT GetSemantics(CATUnicodeString& oName, OmbSRPropagOnDelete& oPropagOnDelete, OmbSRVisibility& oVisibility, OmbSROrientation& oOrientation, OmbSRSynchroSensitivity& oSynchroSensitivity);//, OmbSRMinorSensitivity iMinorSensitivity = CATOmbPLMRelationshipSemantics::MS_NO);

  /**
  * Gets the complete of existing semantics.
  * @param oList
  *   The list of semantics. 
  * @return
  *   HRESULT
  */
  static HRESULT ListAvailableRelationshipSemantics( CATListValCATOmbPLMRelationshipSemantics& oList);

  /**
  * Gets the semantics from a name.
  * @param oSemantics
  *   The semantics. 
  * @return
  *   HRESULT
  */
  static HRESULT GetSemanticsByName( const CATUnicodeString& iName, CATOmbPLMRelationshipSemantics& oSemantics);

protected :

  /**
  * Internal Use Only
  * Used to certify the validity of the object
  */
  void SetValid();

private :

  CATOmbPLMRelationshipSemantics (CATPLMRelationshipSemantics * iSemantics);

  CATPLMRelationshipSemantics * _RelationshipSemantics;
};

//-----------------------------------------------------------------------

#endif
