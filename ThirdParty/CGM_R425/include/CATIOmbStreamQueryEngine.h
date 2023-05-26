#ifndef __CATOmbQueryStreams_H
#define __CATOmbQueryStreams_H

// System
#include "CATBaseUnknown.h"
// SystemTS
#include "CATILockBytes2.h"
// ObjectModelerCollection
#include "CATOmxSharable.h"
#include "CATOmxSR.h"
// ObjectModelerBase
#include "CATOmbSwitchEngine.h"

/** default behavior*/
#define CATOmbQueryStreams_Default                    0

/** Allow to retrieve "CATIA" streams, by default only CATNonCATIADocument can be retrieved */
#define CATOmbQueryStreams_AllowCATIAStreams          1

/** Allows to retrieve unsynchronized streams (for example, the AuthoringVisu SD of a dirty Authoring SD) */
#define CATOmbQueryStreams_AllowUnsynchronizedStreams 2

/** Retrieves the "last" stream. Do not use LocalSave/Undo operations will cause unspecified behaviors */
#define CATOmbQueryStreams_LastStream                 4

/** Unlocks access to the Authoring stream descriptor */
#define CATOmbQueryStreams_AllowAllFormats            8

/** Unlocks access to the engine during switch transitions for SDs declared in CATSwitchExits */
#define CATOmbQueryStreams_AllowQueryDuringSwitch     16


/**
 * See next interface.
 */
class CATIOmbStreamQuery: public CATOmxSharable
{
public:
  /**
   * Retrieve the stream.
   * Returned CATILockBytes2 object is not opened and can only be opened in READ mode.
   */
  virtual HRESULT GetStream(CATOmxSR<CATILockBytes2>& oILB2) = 0;
};

/**
 * Interface allowing to retrieve the streams for some stream descriptors.
 * You can only retrieve the stream of an unmodified and synchronized stream descriptor.
 * Do not use this interface to bypass switch engine.
 * Do not use without Omb team approval.
 * Try to factorize calls as each call to CATIOmbStreamQueryEngine::Execute may trigger a database query.
 * It is intended for non CATIA document but can work also on CATIA document.
 * Warnings:
 *   - on non CATIA documents, it will not return eventual "projection".
 *   - on non CATIA document managed as large file (session cache not used by default), the document is previously downloaded to session cache.
 * Usage:
 *  CATOmxSR<CATIOmbStreamQuery> hSQE = CATIOmbStreamQueryEngine::Create();
 *  if(hSQE)
 *  {
 *     CATOmxSR<CATIOmbStreamQuery> hSQ = hSQE->AddStreamDescriptor( < some SD > );
 *     hSQE->Execute();
 *     CATOmxSR<CATILockBytes2> hStream;
 *     if(SUCCEEDED(hSQ->GetStream(hStream))
 *     {
 *       //process stream content
 *     }
 *  }
 */
class CATIOmbStreamQueryEngine: public CATOmxSharable
{
public:
  /**
   * Create a CATIOmbStreamQueryEngine instance.
   * @param iFlags:
   *   A combination of CATOmbQueryStreams_XXX flags
   */
  static ExportedByCATOmbSwitchEngine CATOmxSR<CATIOmbStreamQueryEngine> Create(unsigned int iFlags = CATOmbQueryStreams_Default);

  /**
   * Add a stream descriptor (can be retrieved thanks to CATOmbComponentStreamsManager::GetSDByKey for example)
   */
  virtual CATOmxSR<CATIOmbStreamQuery> AddStreamDescriptor(const CATBaseUnknown* iStreamDescriptor) = 0;

  /**
   * Execute the operation.
   * After a call to this method CATIOmbStreamQuery::GetStream can be called on objects previously created by AddStreamDescriptor.
   * @return: 
   *   The first failure HRESULT encountered during execution.
   *   S_OK if everything ran fine
   *   E_XXX at least one of the queries have failed see CATIOmbStreamQuery::GetStream return code for detailed status
   */
  virtual HRESULT Execute() = 0;

  /**
   * Shortcut for single stream query.
   */
  static ExportedByCATOmbSwitchEngine HRESULT QueryOneStream(const CATBaseUnknown* iStreamDescriptor,unsigned int iFlags,CATOmxSR<CATILockBytes2>& oILB2);
};

#endif
