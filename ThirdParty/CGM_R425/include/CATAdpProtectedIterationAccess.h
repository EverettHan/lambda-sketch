/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2010
/**
 * @level Protected
 * @usage U1
 */
#ifndef CATAdpProtectedIterationAccess_H
#define CATAdpProtectedIterationAccess_H

#include "CATBaseUnknown.h"
#include "CATCollec.h"
#include "CATIAdpErrorMonitor.h"
#include "CATPLMIntegrationAccess.h"
#include "CATPLMID.h"

class CATIAdpPLMIdentificator;
class CATAdpBasicQueryResult;
class CATLISTP(CATAdpBasicQueryResult);

class ExportedByCATPLMIntegrationAccess CATAdpProtectedIterationAccess
{
public:
  /**
   * @param iErrorMonitor [in]
   * The Error Monitor dedicated to store and handle all PLM Errors raised during the execution of this operation.
   * <ul>
   * <li>It can be created through the @href CATAdpErrorMonitorFactory#CreateErrorMonitor entry point.</li>
   * <li>It is mandatory, else an <code>E_UNEXPECTED</code> return should be expected on each entry point.</li>
   * </ul>
   */
  CATAdpProtectedIterationAccess(CATIAdpErrorMonitor * iErrorMonitor);
  virtual ~CATAdpProtectedIterationAccess();

  /**
   * Retrieve Iterations of a representation reference object.
   * <br><b>Role:</b>This method returns informations and identification of iterations for browsing/restoration.
   *
   * @param iRepReferenceId [in]
   * The identifier of the input representation.
   *
   * @param oIterationResult [out]
   * The iterations found for the input representation. Can be empty if no iteration is found.<br>
   * Each basic query result contains an hardcoded list of attribute not related to any type.
   * <ul>
   * <li>DISPLAYNAME : The computed name of the iteration</li>
   * <li>ITERCREATIONDATE : The value is a numerical string that gives the number of second since 1/1/1970.</li>
   * <li>ITERCREATIONUSER : The user that have leads to the iteration creation. </li>
   * </ul>
   *
   * @return
   *   <ul>
   *   <li><tt>S_OK</tt> if the operation could be performed. Results are then available.</li>
   *   <li><tt>E_INVALIDARG</tt> if at least one parameter was invalid.</li>
   *   <li><tt>E_FAIL</tt> if the operation failed. Errors encountered can be read on the @href CATIAdpErrorMonitor.</li>
   *  </ul>
   */
  HRESULT RetrieveIterations(CATIAdpPLMIdentificator * iRepReferenceId
    , CATLISTP(CATAdpBasicQueryResult) & oIterationResult
    /*, CATTime iStartingDate = (CATTime) -1, CATTime iEndingDate = (CATTime) -1, CATUnicodeString iSearchedUser = "" */
  );

  /**
   * Restore a specific iteration to the main timeline.
   *
   * @param iRepIterationId [in]
   * The identifier of the representation iteration to restore.
   *
   * @return
   *   <ul>
   *   <li><tt>S_OK</tt> if the operation could be performed.</li>
   *   <li><tt>E_INVALIDARG</tt> if at least one entry was invalid.</li>
   *   <li><tt>E_FAIL</tt> if the operation failed. Errors encountered can be read on the @href CATIAdpErrorMonitor.</li>
   *  </ul>
   */
  HRESULT RestoreIteration(CATIAdpPLMIdentificator * iRepIterationId);

protected:
  CATPLMID _WSPIdForTesting;
  CATPLMID _ActionIdForTesting;

private:
  CATAdpProtectedIterationAccess(const CATAdpProtectedIterationAccess &);
  CATAdpProtectedIterationAccess & operator =(const CATAdpProtectedIterationAccess &);

private:
  CATIAdpErrorMonitor_var _ErrorMonitor;
};
#endif
