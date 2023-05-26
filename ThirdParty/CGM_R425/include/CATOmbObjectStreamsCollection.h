#ifndef CATOmbObjectStreamsCollection_H
#define CATOmbObjectStreamsCollection_H

// System
#include "CATUuid.h"
#include "CATOmbObjectStreamsCollection.h"
// ObjectModelerCollection
#include "CATOmxAny.h"
#include "CATOmxArray.h"
#include "CATOmxList.h"
#include "CATOmxMapIter.h"
#include "CATOmxOHMap.h"
#include "CATOmxSR.h"
#include "CATOmxQIPtr.h"
// CATVirtualVaultSystem
#include "CATVVSURLConnection.h"
// CATPLMServices
#include "CATPLMStreamDescriptor.h"
// ObjectModelerBase
#include "CATOmbLoadableDataUniqueKey.h"
// CATPLMStreamDescriptor
#include "CATPLMStreamDescriptorForInfraOnly.h"
#include "CATAsyncTrace.h"
#include "CATOmbObjectStreams.h"
#include "CATOmbObjectStreamerServices.h"

class ExportedByCATPLMStreamDescriptor CATOmbObjectStreamsCollection
{
  friend class CATOmbSdsStreamServices;
  friend class CATOmbStreamDescriptorSessionService;
  friend class CATOmbTstLinkableUtilities;
  friend class CATOmbObjectStreamsForDO; // This is needed to do SubsequentDo Generations
  friend class __TA__TestLinkableStreamsGenerationAndUpdate;
  friend class __TA__TestStreamsGenerationForDO;
  friend class __TA__TestLSCloudForDO;
  friend class __TA__TestLSMultipleGen;
public:

  CATOmbObjectStreamsCollection();

  CATOmbObjectStreamsCollection(CATOmxList<CATOmbObjectStreams> iList);

    //SWV1 Power'By
  /**
  * checks and/or generates secondary streams descriptors and returns the list of ALL stream descriptors to would be saved when saving a component
  * at this stage you only have the CATOmbLoadableDataUniquekey information (format, role, persistencytype) but you don't ave yet all the information of a CATPLMStreamDescriptor to be saved
  *
  * @param ioObjectInfos [inout]
  *   The component to be managed hold by a wrapper of type CATOmbObjectStreams.
  *   The component has at least its master StreamDescriptor
  *
  * @param iGenerationContext[in]
  *   context of generation
  *
  * @return
  *   <code>S_OK</code>   list of basic definitions for StreamDescriptor has been successfully generated
  *   <code>E_FAIL</code> something went wrong
  *
  */
  HRESULT GenerateTargetStreams(unsigned int iGenerationContext);
    /**
  * generate or update a file on Rep according to an input XCAD file and Save it only in PLMCache.
  *
  * @param ioObjectInfos [inout]
  *   The list of components to be managed hold by a wrapper of type CATOmbObjectStreams.
  *   Each component has already computed the list of SDs to manage provided by ListSDsToSave
  *
  * @param iInputURL[in]
  *   the url that would provide the path or ILB to the data used to fill each document associated to a StreamDescriptor
  *   this url should be empty for viewable only generation
  *
  * @return
  *   <code>S_OK</code>   each document has been correctly generated/updated and streams saved in PLMCache
  *   <code>E_FAIL</code> something went wrong
  *
  */

  HRESULT UpdateSDsAttributesAndSaveInPLMCache(CATVVSUrl& iInputURL);
  /**
  * associate for a Component the server url to the PLMCache url in order to prepare VVS transaction of upload
  *
  * @param ioObjectInfos [inout]
  *   The list of component to be managed hold by a wrapper of type CATOmbObjectStreams.
  *   Each component has already saved in PLCache the streams associarted to operated SDs provided previously by ListSDsToSave/UpdateSDsAttributesAndSaveInPLMCache
  *
  * @param iTransactionId[in]
  *   The VVS transaction
  *
  * @return
  *   <code>S_OK</code>   the association has been performed and  VVS transaction is ready for upload
  *   <code>CATOmy_E_V5V6_Catalog_Compliance</code> a V5-V6 certification error occurs at CATIAV5INV6 stream load step, but OMBBypassV5V6Certification parameter not set/set to false
  *                                                 on its input aggregating ObjectStreams.
  *                                                (S_OK if OMBBypassV5V6Certification parameter set to true on ALL input ObjectStreams getting the error, and no other fatal/severe error raised)
  *   <code>E_FAIL</code> something went wrong
  */
  HRESULT PrepareUploadOfSDsStreams(const CATUuid& iTransactionId);

  /**
   * @brief 
   * 
   */
  void DumpToTrace();

  /**
   * @brief 
   * 
   * @return HRESULT 
   */
  HRESULT SortObjectStreams();

    /**
   * Append an item to the vector.
   */
  inline void Append(CATOmbObjectStreams* iObj) { _IsSorted=FALSE;_ListOfObjectInfos.Append(iObj); }

  /**
   * Append an item to the vector and opportunistically reserve max size
   * of the vector in order to reduce reallocations.
   */
  inline void QuickAppend(CATOmbObjectStreams* iObj, int iReserve) { _IsSorted=FALSE;_ListOfObjectInfos.QuickAppend(iObj, iReserve); }
  
  /**
   * Append a vector.
   */
  inline void Append(const CATOmxList<CATOmbObjectStreams>& iVect) { _IsSorted=FALSE;_ListOfObjectInfos.Append(iVect); }
  /**
   * Append a vector.
   */
  inline void Append(const CATOmbObjectStreamsCollection& iVect) { _IsSorted=FALSE;_ListOfObjectInfos.Append(iVect._ListOfObjectInfos); }
  
  /**
   * Returns i-th element of the vector.
   * @param i must be in [0;Size()[.
   */
  inline CATOmbObjectStreams* operator[](int i) const {return  _ListOfObjectInfos[i]; }

  inline CATBoolean IsSorted() {return _IsSorted;}

  /**
   * Collection size.
   * @return the collection size.
   */
  inline int Size() const {return _ListOfObjectInfos.Size();}
    /**
   * RemoveAll item in collection.
   * You can specify iKeepAlloc=TRUE to avoid free of used memory.
   */
  inline void RemoveAll() {_ListOfObjectInfos.RemoveAll();}



private:
  CATAsyncTrace _IPCSTracer;
  CATOmxList<CATOmbObjectStreams> _ListOfObjectInfos;
  CATBoolean _IsSorted;

  HRESULT ProcessLinkableAndViewableStreams(
    CATOmxList<CATOmbObjectStreams>& ioObjectInfosm,
    CATOmbObjectStreamerServices& objectStreamerServices
  );

  HRESULT ProcessDerivedOutputStreams(
    CATOmxList<CATOmbObjectStreams>& ioObjectInfos,
    CATOmbObjectStreamerServices& objectStreamerServices
  );

  HRESULT ManageSwitchErrorAtUpdate(HRESULT iRC, OmbComponentFlags& iAskedRetries, OmbComponentErrors& iFoundRetries);


  CATOmbObjectStreamsCollection(CATOmbObjectStreams&);
  CATOmbObjectStreamsCollection& operator=(CATOmbObjectStreams&);
};

#endif // CATOmbObjectStreams_H
