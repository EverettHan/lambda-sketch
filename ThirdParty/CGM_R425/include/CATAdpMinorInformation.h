/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2011
#ifndef CATAdpMinorInformation_H
#define CATAdpMinorInformation_H

/**
 * @level Protected
 * @usage U3
 */

#include "CATPLMIntegrationAccess.h"

#include "CATBooleanDef.h"
#include "CATUuid.h"
#include "CATUnicodeString.h"

/**
 * Class giving access to a set of minor version informations.
 */
class ExportedByCATPLMIntegrationAccess CATAdpMinorInformation
{
	friend class CATAdpProtectedVersioningServices;
public:

  /** @nodoc */
  CATAdpMinorInformation ();
  /** @nodoc */
  CATAdpMinorInformation (const CATUuid &Identifier, const CATUnicodeString &iMinorVersionStr,int iInternalOrder,
                          CATBoolean iIsBSF, CATBoolean iIsPublished, CATBoolean iIsBaseMajor, CATBoolean iIsBaseMinor);
  /** @nodoc */
  ~CATAdpMinorInformation ();
  /** @nodoc */
  int operator !=(const CATAdpMinorInformation& iMinorInfo ) const;

  /**
  * Returns if this minor is the best so far or not.
  * A BSF is always published.
  */
  CATBoolean IsBSFMinor ();

  /**
  * Returns if this minor is published or not.
  */
  CATBoolean IsPublishedMinor ();

  /**
  * Returns if this minor is the last one in the major family.
  * It is not linked to V_isLastMinorVersion attribute, it is based on the minororder attribute.
  * It is set to TRUE if minororder=max(minororder) locally in the database.
  * So we can compute this value only if all elements of the major family are returned from the query.
  * @result
  *   S_OK   : the oResult contains if the minor version is the last one locally in the major family in the database or not.
  *   E_FAIL : we can't know if this is the last minor version from the requested query.
  */
  HRESULT IsLastMinor (CATBoolean &oIsLastMinor);

  /**
  * Returns if this minor is the element from which a new major version will be created.
  * There is only one element inside the whole family of minor AND major that can have this flag.
  * In SRM scenario, it might be possible that this flag can't be found.
  */
  CATBoolean IsBaseElementForNewMajorVersion ();

  /**
  * Returns if this minor is the element from which a new minor version will be created.
  * So requesting a new minor version can be OK inside this family.
  * There is only one element inside the minor family that can have this flag.
  * In SRM scenario, it might be possible that this flag can't be found.
  */
  CATBoolean IsBaseElementForNewMinorVersion ();

  /**
  *  Returns the versioning string value of the minor version.
  *  Like m1 or m4 for example.
  */  
  CATUnicodeString GetMinorVersion ();

  /**
  *  Checks if the minor information is from the same minor family.
  *  @return 
  *    TRUE  : minor information are from the same family.
  *    FALSE : if not.
  */
  CATBoolean CheckFamily ( const CATAdpMinorInformation &iComparedMinorVersion );

  /**
  *  Returns a value based on the order in the minor information.
  *  @return
  *    -1 : The current minor is before the compared one.
  *    0  : The current minor is equal to the compared one.
  *    +1 : The current minor is after the compared one.
  */
  int CheckOrder ( const CATAdpMinorInformation &iComparedMinorVersion );
  
  /**
  *  @nodoc
  *  Sets the flag _IsLast if query request allows it.
  */
  void SetIsLastMinor (CATBoolean iIsLast);

private :
  CATUuid _MajorID;
  CATUnicodeString _MinorVersionStr;
  int _InternalOrder;
  CATBoolean _IsBSF, _IsLast, _IsLastComputed, _IsPublished, _IsBaseMajor, _IsBaseMinor ;
};
#endif
