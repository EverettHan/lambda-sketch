//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2011
//=============================================================================
/**
* @level Private
* @usage U3
*/
#ifndef _VPMIDicMaskedAttribute_h
#define _VPMIDicMaskedAttribute_h

#include "ExportedByMaskedAttributeItf.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"

//a #include "VPMDicACCESSMODE.h"
//b #include "VPMDicPRIMITIVEType.h"


#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByMaskedAttributeItf const IID IID_VPMIDicMaskedAttribute;
#else
extern "C" const IID IID_VPMIDicMaskedAttribute;
#endif





/**
* Interface to manage the VPMIDicMaskedAttribute.
*/

class ExportedByMaskedAttributeItf VPMIDicMaskedAttribute : public CATBaseUnknown
{
  CATDeclareInterface;

public:
  virtual HRESULT GetAccessMode ( int & oAccessMode ) = 0;
  virtual HRESULT GetAuthorizedValues ( CATListOfCATUnicodeString & oAuthorizedValues, const boolean iNLS = CATFalse ) = 0;
  virtual HRESULT GetDefaultValue ( CATUnicodeString & oDefaultValue, const boolean iNLS = CATFalse ) = 0;
  virtual HRESULT GetHelpValues ( CATListOfCATUnicodeString & oHelpValues ) = 0;
  virtual HRESULT GetMaxLength ( int & oOrder ) = 0;
  virtual HRESULT GetName ( CATUnicodeString & oName, const boolean iNLS = CATFalse ) = 0;
  virtual HRESULT GetOrder ( int & oOrder ) = 0;
  virtual HRESULT GetPrimitiveType ( int & oPrimitiveType ) = 0;
  virtual boolean IsExtendedEnterprise () = 0;
  virtual boolean IsMultiValuated () = 0;
};

CATDeclareHandler( VPMIDicMaskedAttribute, CATBaseUnknown );

#endif
