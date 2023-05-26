#ifndef __CATOmbRelationMetaData_h__
#define __CATOmbRelationMetaData_h__

/**
 * @level Private
 * @usage U1
 * COPYRIGHT Dassault Systemes 2005
 */

// SpecialAPI
#include "CATSysBoolean.h" // CATBoolean
// SystemTS
#include "IUnknown.h"
// CATPLMIdentificationAccess
#include "CATSemanticRelationMetaData.h"
// ObjectModelerBase
#include "CATObjectModelerBase.h"
#include "CATOmbPLMRelationshipSemantics.h"

class CATUnicodeString;

/**
 * Class that defines a set of properties on a relation.
 * <br><b>Role</b>: A CATOmbRelationMetaData stores the properties on a relation
 * between two components stored in database.
 * Several links may share the same relation.
 */
class ExportedByCATObjectModelerBase CATOmbRelationMetaData
{
public:

  /**
   * Creates an instance of CATOmbRelationMetaData.
   * <br><b>Role</b>: this factory is used to instantiate a CATOmbRelationMetaData from a type, category and a role.
   * @param iType
   *	The type of the relation.
   * @param iCategory
   *	The category of the relation.
   * @param iRole
   *	The role of the relation.
   * @param opRelationMetaData
   *	The instantiated object.
   * @return
   *	An HRESULT value:
   *	<dl>
   *		<dt>S_OK</dt>
   *			<dd>An instance already existed with the same type or a new instance has successfully been created</dd>
   *		<dt>S_FALSE</dt>
   *			<dd>Can't instantiate an object.
   *					There is no existing relation in database for the given type</dd>
   *	</dl>
   */
  static HRESULT GetRelationMetaData(const CATUnicodeString& iType, const CATUnicodeString& iCategory, const CATUnicodeString& iRole, CATOmbRelationMetaData*& opRelationMetaData);

/**
 * Creates an instance of CATOmbRelationMetaData.
 * <br><b>Role</b>: this factory is used to instantiate a CATOmbRelationMetaData from a type, category and a role.
 * @param iSRMD
 *	The CATSemanticRelationMetaData of the relation.
 * @param opRelationMetaData
 *	The instantiated object.
 * @return
 *	An HRESULT value:
 *	<dl>
 *		<dt>S_OK</dt>
 *			<dd>An instance already existed with the same type or a new instance has successfully been created</dd>
 *		<dt>S_FALSE</dt>
 *			<dd>Can't instantiate an object.
 *					There is no existing relation in database for the given type</dd>
 *	</dl>
 */
  static HRESULT GetRelationMetaData(const CATSemanticRelationMetaData & iSRMD, CATOmbRelationMetaData*& opRelationMetaData);

/**
 * Creates an instance of CATOmbRelationMetaData.
 * <br><b>Role</b>: this factory is used to return a default CATOmbRelationMetaData
 * @return
 *	The default metadata.
 */
  static CATOmbRelationMetaData & GetDefaultRelationMetaData();

  /**
   * Returns the pathtype of the sementic relation.
   * @return
   *	The pathtype.
   */
  inline const CATUnicodeString& GetType() const { return _SRMD.GetType(); }

  /**
   * Returns the category of the relation.
   * @return
   *	The category.
   */
  inline const CATUnicodeString& GetCategory() const { return _SRMD.GetCategory(); }

  /**
   * Returns the role of the relation.
   * @return
   *	The role.
   */
  inline const CATUnicodeString& GetRole() const { return _SRMD.GetRole(); }

  /**
   * Returns the role and the category of the relation.
   * @return
   *	The role.
   */
  inline HRESULT GetRoleAndCategory(CATUnicodeString & oRole, CATUnicodeString & oCategory) const { return _SRMD.GetRoleAndCategory(oRole, oCategory); }

  inline const CATSemanticRelationMetaData & GetSemanticRelationMetaData() const { return _SRMD; };

  /**
   * Returns the nls role of the relation.
   * @return
   *	The nls role.
   */
  inline const CATUnicodeString& GetNLSRole() const { return _NLSRole; };

  /**
   * Returns the visibility of the relation.
   * @return
   *	The visibility.
   */
  inline CATOmbPLMRelationshipSemantics::OmbSRVisibility GetVisibility()const { return _Visibility; }

  /**
   * Returns the orientation of the relation.
   * @return
   *	The orientation.
   */
  inline CATOmbPLMRelationshipSemantics::OmbSROrientation GetOrientation() const { return _Orientation; }

  /**
   * Returns the synchro sensitivility of the relation.
   * @return
   *	The orientation.
   */
  inline CATOmbPLMRelationshipSemantics::OmbSRSynchroSensitivity GetSynchroSensitivity() const { return _SynchroSensitivity; }

/**
 * Returns the minor sensitivility of the relation.
 * @return
 *	The minor sensitivity.
 */
  inline CATOmbPLMRelationshipSemantics::OmbSRMinorSensitivity GetMinorSensitivity() const { return _MinorSensitivity; }

  inline int operator== (const CATOmbRelationMetaData& iRelationMetaData) const { return this == &iRelationMetaData; }
  inline int operator!= (const CATOmbRelationMetaData& iRelationMetaData) const { return !this->operator==(iRelationMetaData); }

  /** @nodoc */
  inline CATBoolean IsWeak() const { return _IsWeak; }

  /** @nodoc - internal */
  CATBoolean IsDeclaredAsPermanentlyUnsynch();

private:

  static CATBoolean ComputeWeakness(const CATSemanticRelationMetaData & iSRMD);

  static CATOmbRelationMetaData* GetRelationMetaDataInternal(const CATSemanticRelationMetaData& iSRMD);

  CATOmbRelationMetaData(const CATOmbRelationMetaData&); //not implemented
  CATOmbRelationMetaData& operator=(const CATOmbRelationMetaData&); //not implemented

  CATOmbRelationMetaData(const CATSemanticRelationMetaData & iSRMD);

  CATSemanticRelationMetaData _SRMD;

  CATUnicodeString _NLSRole;

  CATBoolean _IsWeak : 4;

  CATBoolean _IsValidForPLMSave : 4;
  int _IsDeclaredAsPermanentlyUnsynch : 4; /* -1 (Not computed) - 0 (NO) - 1 (YES) */

  CATOmbPLMRelationshipSemantics::OmbSRVisibility         _Visibility : 4;
  CATOmbPLMRelationshipSemantics::OmbSROrientation        _Orientation : 4;
  CATOmbPLMRelationshipSemantics::OmbSRSynchroSensitivity _SynchroSensitivity : 4;
  CATOmbPLMRelationshipSemantics::OmbSRMinorSensitivity   _MinorSensitivity : 4;
};



#endif // __CATOmbRelationMetaData_h__
