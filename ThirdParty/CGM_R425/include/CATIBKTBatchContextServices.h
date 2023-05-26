// COPYRIGHT Dassault Systemes 2022
//===================================================================
//
// CATIBKTBatchContextServices.h
// Define the CATIBKTBatchContextServices interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Feb 2022  Creation: Code generated by qrl1
//===================================================================
#ifndef CATIBKTBatchContextServices_H
#define CATIBKTBatchContextServices_H

#include "KnowledgeItf.h"
#include "CATBaseUnknown.h"
#include "CATSysBoolean.h"
#include "CATUnicodeString.h"
#include "CATLISTV_CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByKnowledgeItf IID IID_CATIBKTBatchContextServices;
#else
extern "C" const IID IID_CATIBKTBatchContextServices ;
#endif

class CATPathElement;
class CATListValCATIType_var;
class CATIInstance_var;
class CATBKTBatchProcessApplication;
class BatchContextWrapper;

//------------------------------------------------------------------
/**
 * @nodoc
 */

class ExportedByKnowledgeItf CATIBKTBatchContextServices: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

	/**
	 * Get the value of the static boolean
	 */
	virtual CATBoolean GetBatchContext() = 0;

	/**
	 * Get the id of the batch
	 */
	virtual CATUnicodeString GetBatchId() = 0;

  private:

	/**
	 * Set the value of the static boolean
	 */
	virtual void SetBatchContext() = 0;

	/**
	 * Set the Id of the Batch
	 */
	virtual void SetBatchId(const CATUnicodeString &iBatchId) = 0;
	
	friend class CATBKTBatchProcessApplication;
	friend class BatchContextWrapper;
};
CATDeclareHandler(CATIBKTBatchContextServices, CATBaseUnknown);
//------------------------------------------------------------------

#endif