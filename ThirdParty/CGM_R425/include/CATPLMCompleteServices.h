/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2004
/**
 * @level Protected
 * @usage U1
 */

#ifndef CATPLMCompleteServices_H
#define CATPLMCompleteServices_H

#include "IUnknown.h"

#include "CATCollec.h"
class CATLISTV(CATPLMID);
#include "CATPLMIntegration.h"

/**
 * Class providing static services to complete ids list according specific wishes.
 */
class ExportedByCATPLMIntegration CATPLMCompleteServices
{
public:

  /**
  * Completes and initial ids list with the associated connections and ports.
  * @param iIds 
  *   initial ids list
  * @param oIds 
  *   = iIds + ids of the associated connections and ports
  */
  static HRESULT CompleteWithCnxsAndPorts( const CATLISTV(CATPLMID) & iIds , CATLISTV(CATPLMID) & oIds);

  /**
  * Completes and initial ids list with the RepReference associated with respect to a criteria. Also adds Ports to the selection.
  *  This criteria is based on attribute V_nature valuation.
  * @param iIds 
  *   initial ids list
  * @param iKeyAttrList [in]
  *   The list of attributes (V_nature) on which Query should be made.
  * @param iKeyValueList [in]
  *   The list of value corresponding to attributes.
  *   possible valuation of V_nature attribute ( Specification, Definition, Presentation)
  * @param oIds 
  *   = iIds + ids of the associated connections and ports
  */
  static HRESULT CompleteWithRepRefs( const CATLISTV(CATPLMID) & iIds ,
                                      const CATListValCATString & iKeyAttrList, 
                                      const CATListValCATUnicodeString & iKeyValueList,
                                      CATLISTV(CATPLMID) & oIds);
};
#endif
