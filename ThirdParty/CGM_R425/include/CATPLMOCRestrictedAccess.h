/* -*-c++-*- */
#ifndef CATPLMOCRestrictedAccess_H
#define CATPLMOCRestrictedAccess_H
//
// CATIA Version 6 Release 208
// Copyright   : Dassault Systemes 2009
//-----------------------------------------------------------------------------
// Description :
// C++ class header file for the class named "CATPLMOCRestrictedAccess"
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// Inheritance : CATPLMOCRestrictedAccess
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//
#include "CATPLMOperationContext.h"

/**
* @level Protected
* @usage U1
*/

#define AuthorizedModule                             999
#define CATPLMModelBuilder              AuthorizedModule
#define CATPLMSessionTester             AuthorizedModule
#define CATPLMModelBuilderTests         AuthorizedModule
#define ENOUniversalScene               AuthorizedModule
#define CATOmbTst_Visca                 AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden Access To CATPLMOCRestrictedAccess
@error
#endif
#undef ENOUniversalScene
#undef CATPLMModelBuilderTests
#undef CATPLMSessionTester
#undef CATPLMModelBuilder

class CATPLMID;
class CATUnicodeString;
class CATPLMQESerializeServices;

class ExportedByCATPLMModelBuilder CATPLMOCRestrictedAccess
{
public:
  CATPLMOCRestrictedAccess(const CATPLMOperationContext* iOC) : m_opContext(iOC) {}
  CATPLMOCRestrictedAccess(const CATPLMOCRestrictedAccess&) = delete;
  CATPLMOCRestrictedAccess(CATPLMOCRestrictedAccess&&) = delete;

  CATPLMOCRestrictedAccess& operator=(const CATPLMOCRestrictedAccess&) = delete;
  CATPLMOCRestrictedAccess& operator=(CATPLMOCRestrictedAccess&&) = delete;

  ~CATPLMOCRestrictedAccess() = default;

  /**
   * Log the loading of a given branch relativly to an operation key.
   * @param ioKey
   *    Key identifying the list of operations.
   *    May be empty in case of creating a brand new occurrence graph.
   * @param iStreamID
   *    Identifier of the stream grammar. Should be:
   *       -"XIRP": for "XML I-R Path"
   * @param iStream
   *    Stream.
   * @param iSpec
   *    Specification used to load the branch.
   *    @see CATPLMLoadingSpec
   * @param iBehavior
   *    Behaviors of the added operation.
   *    @see CATPLMOperationBehavior
   * @return
   *    S_OK                     : Operation has been logged correctly.
   *    PLMOC_S_USELESS_OPERATION: Operation is useless (Expand one level after an Expand all, ...)
   *    E_ACCESSDENIED           : Operation is not authorized for the application associated to iPLMID
   *    E_FAIL                   : Otherwise.
   */
  HRESULT LoadStream(CATPLMOperationKey& ioKey, const char* iStreamID, const char* iStream, const CATPLMLoadingSpec& iSpec, const CATPLMOperationBehavior& iBehavior = CATPLMOCFiltering::Enable);

  /**
   * Stream a log relativly to an operation key.
   * @param iKey
   *    Key identifying the list of operations.
   * @param iFilePath
   *    File Path.
   * @return
   *    S_OK                     : OK.
   *    E_FAIL                   : Otherwise.
   */
  HRESULT StreamLog(const CATPLMOperationKey& iKey, const char* iFilePath) { return m_opContext ? m_opContext->Stream(iKey, iFilePath, DebugMode::NoDebug) : E_INVALIDARG; }

  /**
   * Unstream a log relativly to an operation key.
   * @param ioKey
   *    Key identifying the list of operations.
   *    May be empty in case of creating a brand new occurrence graph.
   * @param iFilePath
   *    File Path.
   * @return
   *    S_OK                     : OK.
   *    E_FAIL                   : Otherwise.
   */
  HRESULT UnstreamLog(CATPLMOperationKey& ioKey, const char* iFilePath) { return m_opContext ? m_opContext->Unstream(ioKey, iFilePath) : E_INVALIDARG; }

  /**
   * Stream a log relativly to an operation key.
   * @param iKey
   *    Key identifying the list of operations.
   * @param oBuffer
   *    Output buffer. Allocated by the method, to be deleted by the caller.
   * @param oBufferSize
   *    Buffer size.
   * @return
   *    S_OK                     : OK.
   *    E_FAIL                   : Otherwise.
   */
  HRESULT StreamLog(const CATPLMOperationKey& iKey, char*& oBuffer, unsigned int& oBufferSize);

  /**
   * Unstream a log relativly to an operation key.
   * @param ioKey
   *    Key identifying the list of operations.
   *    May be empty in case of creating a brand new occurrence graph.
   * @param iBuffer
   *    Buffer to unstream.
   * @param iBufferSize
   *    Size of the buffer.
   * @return
   *    S_OK                     : OK.
   *    E_FAIL                   : Otherwise.
   */
  HRESULT UnstreamLog(CATPLMOperationKey& ioKey, const char* iBuffer, unsigned int iBufferSize);

private:

  HRESULT _GetPLMID(const char* iString, const CATPLMQESerializeServices&, CATPLMID& oPLMID);

  CATOmxSR<CATPLMOperationContext> m_opContext{ nullptr };
};
#endif
