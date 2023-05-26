// COPYRIGHT Dassault Systemes 2007
//===================================================================
//
// CATPLMSDId.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//CAA2 Wizard Generation Report
//   IMPLEMENTATION
//End CAA2 Wizard Generation Report
//
//  Mai 2007  Creation: Code generated by the CAA wizard  tbf
//===================================================================
#ifndef CATPLMSDId_H
#define CATPLMSDId_H

#include "CATVVSUrl.h"
#include "CATPLMStreamDescriptor.h"
#include "CATPLMID.h"

//-----------------------------------------------------------------------
/**
* @level Protected
* @usage U1
*/

/** @nodoc */
class ExportedByCATPLMServicesItf CATPLMSDId : public CATBaseUnknown
{
  CATDeclareClass;
  
public:
  /** @nodoc */
	CATPLMSDId (  const CATPLMStreamDescriptor  &iStreamDescriptor, 
                  const CATPLMID          &iPLMId);

  /** @nodoc */
	CATPLMSDId& operator=(CATPLMSDId &iSDId);
  /** @nodoc */
  virtual ~CATPLMSDId ();
  /** @nodoc */
  int operator !=(const CATPLMSDId& iSDId ) const;

  /** @nodoc */
  HRESULT GetStreamDescriptor(CATPLMStreamDescriptor  *&oStreamDescriptor) const;
  const CATPLMStreamDescriptor & GetStreamDescriptor() const {return _streamDescriptor;}

  /** @nodoc */
  HRESULT GetPLMId(CATPLMID  *&oPLMId) const;
  const CATPLMID & GetPLMID() const {return _PLMId;}

  /** @nodoc */
  HRESULT GetVVSUrl(CATVVSUrl *&oVVSUrl) const;
  const CATVVSUrl & GetVVSUrl() const {return _VVSUrl;}

  /** @nodoc */
  HRESULT SetVVSUrl(CATVVSUrl *iVVSUrl);

private:
	CATPLMStreamDescriptor _streamDescriptor;
	CATPLMID _PLMId;
	CATVVSUrl _VVSUrl;
};

//-----------------------------------------------------------------------

#endif