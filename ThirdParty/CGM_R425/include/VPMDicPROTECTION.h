//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2006
//=============================================================================
/**
* @level Private
* @usage U3
*/
#ifndef _VPMDicPROTECTION_h
#define _VPMDicPROTECTION_h


/**
* Data IP Protection setting for Simple, Relationship and Inverse elements of Class and Extension.
* The single value for Protection is actually the merge of the 3 dimensions: "Visibility", "Exposisiton" and "Security".
* @param VPMDicPROTECTION_UNDEFINED
*   The IP Protection is not explicitely defined.
* @param VPMDicPROTECTION_USER
*   The IP Protection is "User": totally free and optional.
* @param VPMDicPROTECTION_FREE
*   The IP Protection is "Free": DS modeler required, free generic edition.
* @param VPMDicPROTECTION_EXTERNAL
*   The IP Protection is "External": DS modeler required, external visibility, direct Read and API Write, modifiable on the client.
* @param VPMDicPROTECTION_EXTERNALRO
*   The IP Protection is "External Read Only": DS modeler required, external visibility, direct Read, not modifiable on the client.
* @param VPMDicPROTECTION_INTERNAL
*   The IP Protection is "Internal": DS modeler required, pure internal, API edition only, API Read and API Write, modifiable on the client.
* @param VPMDicPROTECTION_INTERNALRO
*   The IP Protection is "Internal Read Only": DS modeler required, pure internal, API Read, not modifiable on the client.
* @param VPMDicPROTECTION_PRIVATE
*   The IP Protection is "Private": totally private attribute, server implementation.
*/
enum VPMDicPROTECTION
{
   VPMDicPROTECTION_UNDEFINED=0
  ,VPMDicPROTECTION_USER=1
  ,VPMDicPROTECTION_FREE=2
  ,VPMDicPROTECTION_EXTERNAL=3
  ,VPMDicPROTECTION_EXTERNALIN=4
  ,VPMDicPROTECTION_EXTERNALRO=5
  ,VPMDicPROTECTION_INTERNAL=6
  ,VPMDicPROTECTION_INTERNALRO=7
  ,VPMDicPROTECTION_PRIVATE=8
};


/**
* Deducted from the Protection setting.
* @param VPMDicPLMVISIBILITY_UNDEFINED
*   The PLMVisibility is "Undefined" because the IP Protection is "Undefined".
* @param VPMDicPLMVISIBILITY_USER
*   The PLMVisibility is "User" because the IP Protection is "User".
* @param VPMDicPLMVISIBILITY_MODELER
*   The PLMVisibility is "Modeler" because the IP Protection is either "Free", "External" or "Internal".
*
* NB: it is irrelevant to request the PLMVisibility of a "Private" attribute.
*/
enum VPMDicPLMVISIBILITY
{
   VPMDicPLMVISIBILITY_UNDEFINED=0
  ,VPMDicPLMVISIBILITY_USER=1
  ,VPMDicPLMVISIBILITY_MODELER=2
};


/**
* Deducted from the Protection setting.
* @param VPMDicPLMEXPOSITION_UNDEFINED
*   The PLMExposition is "Undefined" because the IP Protection is "Undefined".
* @param VPMDicPLMEXPOSITION_FREE
*   The PLMExposition is "Free" because the IP Protection is either "User" or "Free".
* @param VPMDicPLMEXPOSITION_EXTERNAL
*   The PLMExposition is "External" because the IP Protection is "External".
* @param VPMDicPLMEXPOSITION_INTERNAL
*   The PLMExposition is "Internal" because the IP Protection "Internal".
*
* NB: it is irrelevant to request the PLMExposition of a "Private" attribute.
*/
enum VPMDicPLMEXPOSITION
{
   VPMDicPLMEXPOSITION_UNDEFINED=0
  ,VPMDicPLMEXPOSITION_FREE=1
  ,VPMDicPLMEXPOSITION_EXTERNAL=2
  ,VPMDicPLMEXPOSITION_INTERNAL=3
};


/**
* Deducted from the Protection setting.
* @param VPMDicPLMCLIENTEDITABILITY_UNDEFINED
*   The PLMClientEditability is "Undefined" because the IP Protection is "Undefined".
* @param VPMDicPLMCLIENTEDITABILITY_RW
*   The PLMClientEditability is "Read/Write" because the IP Protection is either "User", "Free", "External" or "Internal".
* @param VPMDicPLMCLIENTEDITABILITY_RO
*   The PLMClientEditability is "ReadOnly" because the IP Protection is either "ExternalRO", "Internal" or "Private".
*/
enum VPMDicPLMCLIENTEDITABILITY
{
   VPMDicPLMCLIENTEDITABILITY_UNDEFINED=0
  ,VPMDicPLMCLIENTEDITABILITY_RW=1
  ,VPMDicPLMCLIENTEDITABILITY_RO=2
};


/**
* CAAExposition mode (valid only for Simple, Relationship or Inverse elements which Protection is set to either Free, External or External_RO).
* @param VPMDicCAAEXPOSITION_UNDEFINED
*   The CAAEXPOSITION is "Undefined" because .....
* @param VPMDicCAAEXPOSITION_L0
*   The CAAEXPOSITION of the attribute is "L0".
* @param VPMDicCAAEXPOSITION_L1
*   The CAAEXPOSITION of the attribute is "L1".
*/
enum VPMDicCAAEXPOSITION
{
   VPMDicCAAEXPOSITION_UNDEFINED=0
  ,VPMDicCAAEXPOSITION_L0=1
  ,VPMDicCAAEXPOSITION_L1=2
};

/**
* Deducted from the Protection setting and the CustoUserAccess Property
* @param VPMDicCUSTOUSERACCESS_NONE
*   If ( Protection==INTERNAL|INTERNALRO|PRIVATE ), or if ( Protection==FREE|USER && CustoUserAccess Property==None )
* @param VPMDicCUSTOUSERACCESS_READONLY
*   If ( Protection==EXTERNAL|EXTERNALRO ), or if ( Protection==FREE|USER && CustoUserAccess Property==ReadOnly )
* @param VPMDicCUSTOUSERACCESS_READWRITE
*   If ( Protection==EXTERNALIN ), or if ( Protection==FREE|USER && CustoUserAccess Property==ReadWrite )
*/
enum VPMDicCUSTOUSERACCESS
{
   VPMDicCUSTOUSERACCESS_NONE=0
  ,VPMDicCUSTOUSERACCESS_READONLY=1
  ,VPMDicCUSTOUSERACCESS_READWRITE=2
};
#endif
