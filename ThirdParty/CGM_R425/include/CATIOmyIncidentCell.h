/* -*-c++-*- */
/**
* @level Protected
* @usage U3
*/
// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATIOmyIncidentCell.h
// Define the CATIOmyIncidentCell interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Apr 2009  Creation: Code generated by the CAA wizard  vcs
//===================================================================
#ifndef CATIOmyIncidentCell_H
#define CATIOmyIncidentCell_H

#include "CATOmyIncidentCollect.h"

// System
#include "CATBaseUnknown.h"
#include "CATString.h"
#include "CATUnicodeString.h"

// ObjectModelerCollection
#include "CATOmxSR.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATOmyIncidentCollect IID IID_CATIOmyIncidentCell;
#else
extern "C" const IID IID_CATIOmyIncidentCell ;
#endif

class CATError;
//------------------------------------------------------------------

/**
* Error cell stacked by @href CATIOmyIncidentCollector 
* Instanciable and stacked by  @href CATIOmyIncidentCollector::CreateIncidentCell
* readable from stack by CATIOmyIncidentIterator#Next 
*/
class ExportedByCATOmyIncidentCollect CATIOmyIncidentCell: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

	/**
  * @deprecated  V6R2015
	*/
	virtual HRESULT GetIdEntityType(CATString& oIdEntityType) = 0;

	/**
  * @deprecated  V6R2015 */
	virtual HRESULT GetIdEntity (CATUnicodeString& oUSIdentifier) = 0;

	/**
  * @deprecated  V6R2015 */
	virtual HRESULT GetIdEntity(CATBaseUnknown*& opBUIdentifier) = 0;

	/**
  * @deprecated  V6R2015 */
	virtual HRESULT SetIdEntity (const CATUnicodeString iUsIdEntity, const CATString iEntityType) = 0;

	/**
  * @deprecated  V6R2015 */
	virtual HRESULT SetIdEntity (CATBaseUnknown* ipBUIdEntity, const CATString iEntityType) = 0;

	/**
	* Returns the underlying CATError
	*/
	virtual const HRESULT GetError(CATError** opError)=0;

	/**
	* Returns the underlying CATError
	*/
  virtual CATOmxSR<CATError> GetError()=0;

	/**
	* Returns the NLS message of the underlying CATError
  * Empty parts of composite (Request/Diag/parms) NLS message are skipped.
	*/
  virtual CATUnicodeString GetNLSMessage()=0;

	/**
	* Associated a debugging context to the error
	*/
  virtual void SetErrorContext(const CATUnicodeString& iContext)=0;

	/**
	* Gets the debugging context associated to the error
	*/
  virtual CATUnicodeString GetErrorContext()=0;

  virtual void SetCompiledContext(const CATUnicodeString& iContext)=0;

  virtual CATUnicodeString GetCompiledContext()=0;

};

CATDeclareHandler(CATIOmyIncidentCell, CATBaseUnknown);
//------------------------------------------------------------------

#endif