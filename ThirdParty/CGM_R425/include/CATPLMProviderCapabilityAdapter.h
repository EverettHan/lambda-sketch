// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMProviderCapabilityAdapter.h
// Define the CATPLMProviderCapabilityAdapter interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Feb 2009  Creation: EPB
//===================================================================

/**
* @level Protected
* @usage U2
*/

#ifndef CATPLMProviderCapabilityAdapter_H
#define CATPLMProviderCapabilityAdapter_H

#include "CATIPLMProviderCapability.h"

#include "CATPLMImplAdapterClass.h"// ExportedByCATPLMImplAdapterClass//#include "CATPLMImplAdapterBase.h"
class CATSysSimpleHashTable;
class CATString;

/** 
* Adapter to implement the CATIPLMProviderCapability interface.
* To make an implementation of CATIPLMProviderCapability,
* either you select to use an external XML declaration file
*       - Just give the filename (no path) to parse from /code/providerdef with the GetProviderCapabilityFileName method
*         (The adapter implementation of QueryCapability will parse the file, and use it to answer)
* either you choose to answer by overriding the QueryCapability method
*       - Then, the GetProviderCapabilityFileName will never not be called
* (You can mix both by calling the CATPLMProviderCapabilityAdapter::QueryCapability 
*  in your overidden method and adding behaviors from there, but it will be harder to maintain)
*/
//class ExportedByCATPLMImplAdapterBase CATPLMProviderCapabilityAdapter: public CATIPLMProviderCapability
class ExportedByCATPLMImplAdapterClass CATPLMProviderCapabilityAdapter: public CATIPLMProviderCapability
{
public:
  CATPLMProviderCapabilityAdapter ();
  virtual ~CATPLMProviderCapabilityAdapter ();

  /** 
  * Main entry point from CATPLMAdapter call.
  * This method should not be overriden
  * The default implementation calls the other QueryCapability method by defining a CATIALevelInfo to use
  */
  HRESULT QueryCapability (const CATPLMProviderCapabilityEnum iCapabilityRequest
                          ,CATPLMProviderCapabilityResult &oResult
                          ,int iCheckInstanceLevel );

  /** 
  * Returns the name of the declaration file.
  * The path used to find it is : code/providerref
  */
  virtual void GetProviderCapabilityFileName (CATString &oFileName);

  /** 
  * Returns the result of a QueryCapability request.
  * The adapter implementation is to parse the capability filename in an hash table.
  */
  virtual HRESULT QueryCapability (const CATPLMProviderCapabilityEnum iCapabilityRequest
                                   ,CATIALevelInfo &iMLCLevel
                                   ,CATPLMProviderCapabilityResult &oResult
                                   ,CATUnicodeString *oComment);

private:
  CATPLMProviderCapabilityAdapter (CATPLMProviderCapabilityAdapter &);
  CATPLMProviderCapabilityAdapter& operator=(CATPLMProviderCapabilityAdapter&);


  // Methods for adpater implementation
  void ComputeAnswersTable ();  // Create the Hash table of answers by parsing the Capability Filename
  CATSysSimpleHashTable *_ProviderAnswers;

  /** 
  * Returns a property value.
  * The adapter implementation is to find the property in the connection parameters.
  * So the connection must be enable to have another result than the default value.
  */
  virtual HRESULT GetProperty (const CATPLMPropertyEnum iProperty
                                ,CATOmxAny &oValue );

};
#endif
