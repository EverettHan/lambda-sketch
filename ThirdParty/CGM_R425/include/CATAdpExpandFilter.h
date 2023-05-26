// COPYRIGHT Dassault Systemes 2013
#ifndef CATAdpExpandFilter_H
#define CATAdpExpandFilter_H

/**
 * @level Protected
 * @usage U1
 */

#include "CATPLMIntegrationAccess.h"
#include "CATBaseUnknown.h"

#include "CATBoolean.h"
class CATAdpExpandSpecification;
class CATAdpPLMExpandFilter;
class CATUnicodeString;
class CATPLMExpandQueryWithAliasBuilder;


class ExportedByCATPLMIntegrationAccess CATAdpExpandFilter
{
public:
  CATAdpExpandFilter();
  virtual ~CATAdpExpandFilter();

  CATAdpExpandFilter(const CATAdpExpandFilter&);
  CATAdpExpandFilter& operator=(const CATAdpExpandFilter& );

  HRESULT BuildFromXMLExpression(const CATUnicodeString & iXMLExpression);
  HRESULT WriteXML(CATUnicodeString& oExpression);

  CATBoolean IsValid() const;

private:
  friend class CATAdpExpandSpecification;
  CATPLMExpandQueryWithAliasBuilder * m_internal_builder;
  void SetBuilder(CATPLMExpandQueryWithAliasBuilder * iBuilder);
};
#endif
