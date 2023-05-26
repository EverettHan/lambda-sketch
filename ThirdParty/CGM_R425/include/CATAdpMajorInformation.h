/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2011
#ifndef CATAdpMajorInformation_H
#define CATAdpMajorInformation_H

/**
 * @level Protected
 * @usage U3
 */

#include "CATPLMIntegrationAccess.h"

#include "CATBooleanDef.h"
#include "CATUuid.h"
#include "CATUnicodeString.h"

/**
 * Class giving access to a set of major version informations.
 */
class ExportedByCATPLMIntegrationAccess CATAdpMajorInformation
{
	friend class CATAdpProtectedVersioningServices;
public:

  /** @nodoc */
  CATAdpMajorInformation ();
  /** @nodoc */
  CATAdpMajorInformation (const CATUuid &Identifier, const CATUnicodeString &iVersionStr, int iInternalOrder);
  /** @nodoc */
  ~CATAdpMajorInformation ();
  /** @nodoc */
  int operator !=(const CATAdpMajorInformation& iMajorInfo ) const;

  /**
  * Returns if this major is the last one in the whole family.
  * It is not linked to V_isLastVersion attribute, it is based on the majororder attribute.
  * It is set to TRUE if majororder=max(majororder) locally in the database.
  * So we can compute this value only if at least one element of all major version are returned from the query.
  * @result
  *   S_OK   : the oResult contains if the major version is the last one locally in the database or not.
  *   E_FAIL : we can't know if this is the last major version from the requested query.
  */
  HRESULT IsLastMajor (CATBoolean &oIsLastMajor);

  /**
  *  Returns the versioning string value of the major version.
  *  Like --A or --C for example.
  */
  CATUnicodeString GetMajorVersion ();

  /**
  *  Checks if the major information are from the same major family.
  *  @return 
  *    TRUE  : major information are from the same family.
  *    FALSE : if not.
  */
  CATBoolean CheckFamily ( const CATAdpMajorInformation &iComparedMajorVersion );

  /**
  *  Returns a value based on the order of major information.
  *  Note : It only has a meaning if Major information are from the same family.
  *  If not sure, use CheckFamily before.
  *
  *  @return
  *    -1 : The current major info is before the compared one.
  *    0  : The current major info is equal to the compared one.
  *    +1 : The current major info is after the compared one.
  */
  int CheckOrder ( const CATAdpMajorInformation &iComparedMajorVersion );

  /**
  *  @nodoc
  *  Sets the flag _IsLast if query request allows it.
  */
  void SetIsLastMajor (CATBoolean iIsLast);

private :
  CATUnicodeString _VersionStr;
  CATUuid _VersionID;
  int _InternalOrder;
  CATBoolean _IsLast, _IsLastComputed;
};
#endif
