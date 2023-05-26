// COPYRIGHT Dassault Systemes 2013
//===================================================================
//
// CATIPLMRecordReadExtraInfo.h
// Define the CATIPLMRecordReadExtraInfo interface
//
//===================================================================
//
// Usage notes:
//   Need to give access to attribute(s) that doesn't (don't) belong to the dictionary
//
//===================================================================
// July 2013  Creation: EPB
//===================================================================
/**
* @level Protected
* @usage U3
*/
#ifndef CATIPLMRecordReadExtraInfo_H
#define CATIPLMRecordReadExtraInfo_H


#if defined (private) || defined(friend) || defined (protected)

  #error Forbidden re-define of 'private', 'friend' or 'protected'
    // Fatal error on solaris
    @error 
#endif


#define AuthorizedModule669     669

// Check no one makes a declaration to by-pass our control. 
#if _MK_MODNAME_ == AuthorizedModule669  
  #error Module declared as authorized by another header  
  // Fatal error on solaris
  @error 
#endif  


// List of authorized infrastructure modules 
#define TransitionEngine                      AuthorizedModule669
#define CATPLMVP5ProviderImpl                 AuthorizedModule669
#define CATPLMServicesItf                     AuthorizedModule669
#define CATPLMServicesUUID                    AuthorizedModule669
#define CATPLMImplAdapterQLBase               AuthorizedModule669
#define CATPLMxQueryDataSet                   AuthorizedModule669
#define CATPLMIndexSimilarServices            AuthorizedModule669
#define CAT3DAppSimilarSearch                 AuthorizedModule669
#define CATPLMImplAdapterClass                AuthorizedModule669
#define CATPLMImplRecordReadSetVPMV4          AuthorizedModule669
#define CATPLMDebugProviderImpl               AuthorizedModule669
#define RecordManagement                      AuthorizedModule669

#if _MK_MODNAME_ == AuthorizedModule669
#else
      #error Forbidden Access To CATPLMServicesLimitedAccess Services from a non-authorized module
        // Fatal error on solaris
        @error 
#endif

#undef TransitionEngine
#undef CATPLMVP5ProviderImpl
#undef CATPLMServicesItf
#undef CATPLMServicesUUID
#undef CATPLMImplAdapterQLBase
#undef CATPLMxQueryDataSet
#undef CATPLMIndexSimilarServices
#undef CAT3DAppSimilarSearch
#undef CATPLMImplAdapterClass              
#undef CATPLMImplRecordReadSetVPMV4         
#undef CATPLMDebugProviderImpl
#undef RecordManagement

#if _MK_MODNAME_ == AuthorizedModule669
  #error Declared Module has not been undeclared correctly
  // Fatal error on solaris
  @error 
#endif


#if defined(__CATPLMServicesItf)
#define ExportedByCATPLMServicesItf DSYExport
#else
#define ExportedByCATPLMServicesItf DSYImport
#endif
#include "DSYExport.h"


#include "CATBaseUnknown.h"

#include "CATPLMIdentificationAccessMacros.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMRecordReadExtraInfo;
#else
extern "C" const IID IID_CATIPLMRecordReadExtraInfo ;
#endif

class CATOmxKeyValueBlock;

class ExportedByCATPLMServicesItf CATIPLMRecordReadExtraInfo: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

  virtual HRESULT GetAttributeBlock (CATOmxKeyValueBlock& oAttrAccess) =0;
};

CATDeclareHandler( CATIPLMRecordReadExtraInfo, CATBaseUnknown );

#endif
