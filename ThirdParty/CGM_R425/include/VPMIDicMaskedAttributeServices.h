//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2011
//=============================================================================
/**
* @level Private
* @usage U3
*/
#ifndef _VPMIDicMaskedAttributeServices_h
#define _VPMIDicMaskedAttributeServices_h

#include "ExportedByMaskedAttributeItf.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
//#include "CATListOfCATUnicodeString.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByMaskedAttributeItf const IID IID_VPMIDicMaskedAttributeServices;
#else
extern "C" const IID IID_VPMIDicMaskedAttributeServices;
#endif

class VPMIDicMaskedAttribute_var;
#include "CATLISTV_VPMIDicMaskedAttribute_var.h"

/**
* Interface to manage the VPMIDicMaskedAttributeServices.
*/

class ExportedByMaskedAttributeItf VPMIDicMaskedAttributeServices : public CATBaseUnknown
{
  CATDeclareInterface;
 
public:
  virtual HRESULT GetMaskedAttribute ( CATUnicodeString & iAttributeName, CATUnicodeString & iClassName, CATUnicodeString & iOperation, VPMIDicMaskedAttribute_var & oMaskedAttribute ) = 0;
  virtual HRESULT GetMaskedAttributeList ( CATUnicodeString & iClassName, CATUnicodeString & iOperation, CATLISTV_VPMIDicMaskedAttribute_var & oMaskedAttributeList ) = 0;
};

CATDeclareHandler( VPMIDicMaskedAttributeServices, CATBaseUnknown );

#endif
