// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// CATIPLMFilterConditionRestricted.h
// Define the CATIPLMFilterConditionRestricted interface
//
//===================================================================
//  Apr 2004  Creation:  jvm
//===================================================================
/**
* @level Protected
* @usage U3
*/

#ifndef CATIPLMFilterConditionRestricted_H
#define CATIPLMFilterConditionRestricted_H

// ----------------------------------------------------------------------
// List  of  forbidden  re-define  
// ----------------------------------------------------------------------
#if  defined  (private)  ||  defined(friend)  ||  defined  (protected)  
#error  Forbidden  re-define  of  'private',  'friend'  or  'protected'  
//  Fatal  error  on  solaris  
@error
#endif  

#define  AuthorizedModule  999  

// ----------------------------------------------------------------------
// Define  List  of    authorized  modules  using  CATIPLMFilterConditionRestricted  protected  intefaces  
// ----------------------------------------------------------------------
#define CATPLMServicesItf                    AuthorizedModule
#define CATPLMImplAdapterBase                AuthorizedModule
#define CATPLMQL_Visitor                     AuthorizedModule
#define TSTCATPLMxNav                        AuthorizedModule

//  Check  authorization  
#if  _MK_MODNAME_  ==  AuthorizedModule  
#else  
#error  Forbidden  Access  To  CATIPLMFilterConditionRestricted  Services  from  a  non-authorized  module    
//  Fatal  error  on  solaris  
@error
#endif  

// ----------------------------------------------------------------------
// Restore context (don t forget to do that!!!!!!):
// delete macros, de-associate module name  from int value above
// ----------------------------------------------------------------------
#undef CATPLMServicesItf
#undef CATPLMImplAdapterBase
#undef CATPLMQL_Visitor
#undef TSTCATPLMxNav

// ----------------------------------------------------------------------
// ExportedBy
// ----------------------------------------------------------------------
#undef  ExportedByCATPLMServicesItf

#if defined __CATPLMServicesItf
#define ExportedByCATPLMServicesItf DSYExport
#else
#define ExportedByCATPLMServicesItf DSYImport
#endif
#include "DSYExport.h"

#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMFilterConditionRestricted;
#else
extern "C" const IID IID_CATIPLMFilterConditionRestricted;
#endif

class CATIPLMFilterAttribute;
class CATUnicodeString;
class CATString;
class CATPLMType;

class ExportedByCATPLMServicesItf CATIPLMFilterConditionRestricted : public CATBaseUnknown
{
  CATDeclareInterface;

public:
  virtual HRESULT AddFilterAttributeNoCheckOp(CATPLMType * iType,
    CATString * iAttrName,
    CATUnicodeString * iOperator,
    CATIPLMFilterAttribute **  oFilterAttribute) = 0;
};

#endif
