// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATIOmbMasterSDUpdateStatus.h
// Define the CATIOmbMasterSDUpdateStatus interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  May 2005  Creation: Code generated by the CAA wizard  jxb
//===================================================================

/**
 * @level  Private
 * @usage   U3
 */

#ifndef CATIOmbMasterSDUpdateStatus_H
#define CATIOmbMasterSDUpdateStatus_H

#include "AC0XXLNK.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByAC0XXLNK IID IID_CATIOmbMasterSDUpdateStatus;
#else
extern "C" const IID IID_CATIOmbMasterSDUpdateStatus ;
#endif

//------------------------------------------------------------------

/**
 * Update status of the Master SD associated to the representation.
 * @param MustBeUpdated
 *   The representation needs to be updated.
 * @param Updated
 *   The representation is up to date.
 * @param NotRelevant
 *   The representation has not any relevant update status.
 */
enum PLMRepresentationUpdateStatus { MustBeUpdated, Updated, NotRelevant };


/**
 * Interface dedicated to the representation update mechanism.
 * <b>Role</b>:
 * CATIOmbMasterSDUpdateStatus must be implemented by representation objects which are concerned by the update mechanism.
 */
class ExportedByAC0XXLNK CATIOmbMasterSDUpdateStatus: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

  /**
   * Returns the status of the representation concerning the update mechanism.
   */
  virtual PLMRepresentationUpdateStatus GetUpdateStatus () = 0;

  /**
   * Retrieves the status of the representation concerning the update mechanism.
   * @param oUpdateStatus
   *	The representation update status.
   * @return
   *	An HRESULT.
   *    <br><b>Legal values</b>:
   *    <dl>
   *	  <dt>S_OK
   *	    <dd>The representation update status was successfully computed and returned.
   *	  <dt>E_FAIL
   *	    <dd>The representation update status could not be computed.
   *	</dl>
   */
  virtual HRESULT GetUpdateStatus (PLMRepresentationUpdateStatus & oRepresentationUpdateStatus) = 0;

};

CATDeclareHandler(CATIOmbMasterSDUpdateStatus, CATBaseUnknown);

//------------------------------------------------------------------

#endif
