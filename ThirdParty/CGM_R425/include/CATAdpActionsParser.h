#ifndef CATAdpActionsParser_H
#define CATAdpActionsParser_H

// COPYRIGHT DASSAULT SYSTEMES 2009

/**
 * @level Private
 * @usage U3
 */

#include "CATPLMIntegrationAccess.h"
#include "CATBaseUnknown.h"
#include "CATCollec.h"
class CATPLMID;
class CATLISTV(CATPLMID);
class CATAdpPrivateActionsParser;

class ExportedByCATPLMIntegrationAccess CATAdpActionsParser
{
public:
  virtual ~CATAdpActionsParser();

  CATAdpActionsParser();
  CATAdpActionsParser( const CATAdpActionsParser & );
  CATAdpActionsParser & operator=( const CATAdpActionsParser & );

/**
 * Get the next component with associated actions.
 * @param ioPosition [inout]
 *   On input, it's the index of the component (specify 0 for the first component). On output, it will contain the next index.
 * It is self incremented.
 * @param [out] oComponent
 *   The component which actions are associated to.
 * @param [out] oActions
 *   The actions involved in the modifications which occured during its life cycle.
 *
 * @return
 * <dl>
 *   <li><code>S_OK</code> if everything ran ok.</li>
 *   <li><code>S_FALSE</code> if no more component is available. All the components available were parsed.</li>
 *   <li><code>E_INVALIDARG</code> if invalid position is provided.</li>
 *   <li><code>E_FAIL</code> if a fatal error occured during the operation.</li>
 * </dl>  
 */
  HRESULT NextResult( int & ioPosition, CATPLMID & oComponent, CATLISTV(CATPLMID) & oActions );

/**
 * Get all the actions which involved modifications on a set of components provided as entry of a query.
 * @param [out] oActions
 *   The actions
 * @return
 *  An HRESULT value
 * <dl>
 *   <li><code>S_OK</code> if everything ran ok.</li>
 *   <li><code>E_FAIL</code> if a fatal error occured during the operation.</li>
 * </dl>  
 */
  HRESULT GetAllActions( CATLISTV(CATPLMID) & oActions );

private:
  friend class CATAdpChangeHistoryQuery;
  CATAdpActionsParser(CATAdpPrivateActionsParser * iLetter);

private:
  CATAdpPrivateActionsParser * _letter;
};
#endif
