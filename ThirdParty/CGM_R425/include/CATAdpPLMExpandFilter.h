// COPYRIGHT DASSAULT SYSTEMES 2013
#ifndef CATAdpPLMExpandFilter_H
#define CATAdpPLMExpandFilter_H

/**
* @CAA2Level L1
* @CAA2Usage U1  
*/

#include "CATPLMIntegrationAccess.h"
#include "IUnknown.h"
#include "CATBoolean.h"
class CATUnicodeString;
class CATAdpExpandFilter;


/**
 * Class defining a filter specification for the Expand algorithm.
 *
 * <b>Role</b> : provide a mean to specify a filter to the Expand algorithm.
 */
class ExportedByCATPLMIntegrationAccess CATAdpPLMExpandFilter
{
public:
  /**
   * Constructs an empty filter.
   */
  CATAdpPLMExpandFilter();
  /**
   * Destructs the filter.
   */
  virtual ~CATAdpPLMExpandFilter();
  /**
   * Constructs a clone filter.
   */
  CATAdpPLMExpandFilter(const CATAdpPLMExpandFilter &);
  /**
   * Affectation operator.
   */
  CATAdpPLMExpandFilter & operator = (const CATAdpPLMExpandFilter &);

  /**
   * Fills the filter with detailed filter from a XML expression.
   */
  HRESULT BuildFromXMLExpression(const CATUnicodeString & iXMLExpression);

  /**
   * Writes back a XML expression.
   */
  HRESULT WriteXML(CATUnicodeString & oExpression);
  /**
   * Checks if the filter is valid.
   */
  CATBoolean IsValid() const;

private:
  friend class CATAdpPLMExpandSpecification;
  CATAdpExpandFilter * m_impl;
};


#endif
