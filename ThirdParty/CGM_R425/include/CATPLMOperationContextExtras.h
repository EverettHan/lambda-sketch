/*
 * CATPLMOperationContextExtras.h
 *
 *  Created on: Sep 17, 2013
 *      Author: pjq
 */

#ifndef CATPLMOPERATIONCONTEXTEXTRAS_H_
#define CATPLMOPERATIONCONTEXTEXTRAS_H_

#include "CATPLMModelBuilder.h"
#include "CATPLMID.h"

class CATMathPoint;

/**
 * Collection of services loosely related to CATPLMOperationContext.
 */
class ExportedByCATPLMModelBuilder CATPLMOperationContextExtras
{
public:
  /**
   * Retrieve the bounding box of structure under a given root component.
   * Note that the query is made on the index. It may be out of sync with
   * the official database as the index may not be up to date itself.
   *
   * @param iRoot [in]
   *   the PLMID of the root component.
   * @param oP1 [out]
   *   first corner of the bounding box of the structure under iRoot
   * @param oP2 [out]
   *   second corner of the bounding box of the structure under iRoot
   * @param oLeavesCount [out]
   *   number of leaves under the given iRoot
   */
  static HRESULT GetBoundingBoxAndLeavesCount(const CATPLMID & iRoot,
      CATMathPoint & oP1, CATMathPoint & oP2, int & oLeavesCount);
};
#endif /* CATPLMOPERATIONCONTEXTEXTRAS_H_ */
