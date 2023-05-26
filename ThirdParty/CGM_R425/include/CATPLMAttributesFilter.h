/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2009
#ifndef CATPLMAttributesFilter_H
#define CATPLMAttributesFilter_H

/**
 * @level Protected
 * @usage U4       
 */

#include "ExportedByCATPLMTos.h"
#include "CATErrorDef.h"
#include "CATListOfCATString.h"

/**
 * Class defining an attribute filter for attributes introspection.
 */
class ExportedByCATPLMTos CATPLMAttributesFilter
{
public:

/**
 * Defines a context of enumeration for a set of attributes.
 * <br><b>Role:</b>Enables to define what kind of attributes are requested to be filtered through this kind of filter.
 * <dt> <code><b>PARTIAL</b></code>     <dd> The only attributes required to be part of the filter are the one defined by the user of the filter.
 * <dt> <code><b>FULL</b></code>     <dd> All the attributes are required to be part of the filter.
 * <dt> <code><b>PUBLIC</b></code>     <dd> All the public attributes are part of the filter.
 * <dt> <code><b>PUBLIC_READONLY</b></code>      <dd> The public read only attributes are part of the filter.
 * <dt> <code><b>PUBLIC_READWRITE</b></code>      <dd> The public read write attributes are part of the filter.
 * <dt> <code><b>FULL_READONLY</b></code>      <dd> All the read only attributes are part of the filter.
 * <dt> <code><b>FULL_READWRITE</b></code>      <dd> All the read write attributes are part of the filter.
 */
  enum PLMAttributesIntrospectionContext { PARTIAL=0, FULL=1, PUBLIC=2, PUBLIC_READONLY=3, PUBLIC_READWRITE=4, FULL_READONLY=5, FULL_READWRITE=6 };

  CATPLMAttributesFilter( PLMAttributesIntrospectionContext iContext, const CATLISTV(CATString) & iFilteredAttributes );
  virtual ~CATPLMAttributesFilter( void );

/**
 * Returns the context of attributes filtering defined through this filter.
 * <br><b>Role:</b>This entry point enables to know the context that will be used to introspect the attributes of a component.
 * @param oContext [out]
 *   The context of this instance of filter. If the context is set to <code>PARTIAL</code>, the attributes being part of the filter
 * are described through the @href CATPLMAttributesFilter#GetFilteredAttributes entry point.
 * @return
 *   <ul>
 *   <li><tt>S_OK</tt>: Success.</li> 
 *   <li><tt>E_FAIL</tt>: Failure.</li>
 *   </ul>
 */
  const HRESULT GetContext( PLMAttributesIntrospectionContext & oContext );

/**
 * Returns the attributes specified by the user if context is set to <code>PARTIAL</code>.
 * <br><b>Role:</b>Enables to obtain the set of attributes asked to be filtered by the user.
 * @param oAttributeIds [out]
 *   The attribute identifiers.
 * @return
 *   <ul>
 *   <li><tt>S_OK</tt>: Success.</li> 
 *   <li><tt>S_FALSE</tt>: The context is not set to <code>PARTIAL</code>. No attribute is available.</li> 
 *   <li><tt>E_FAIL</tt>: Failure.</li>
 *   </ul>
 */
  const HRESULT GetFilteredAttributes( CATLISTV(CATString) & oAttributeIds );

private:
  PLMAttributesIntrospectionContext _IntrospectionContext;
  CATLISTV(CATString) _FilteredAttributes;

};
#endif
