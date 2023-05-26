#ifndef VISCOREFACTORY_H
#define VISCOREFACTORY_H

// COPYRIGHT DASSAULT SYSTEMES 2009

#include "VisCore.h"


#include "VisDataType.h"
#include "VisRawBuffer.h"

class VisVerticesDescription;
class VisIndicesDescription;

class ExportedByVisCore VisCoreFactory	
{
  friend class l_VisCoreFactory;

public:

  /**
   * Call this method to retrieve the Core Factory instance.
   * @param opCoreFactory
   *   The Core Factory instance.
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>If query succeeds
   *   <dt><tt>E_INVALIDARG</tt>  <dd>If the provided pointer is null
   *   <dt><tt>E_FAIL</tt>        <dd>If query fails for any other reason.
   *   </dl>
   */
  static HRESULT GetCoreFactory(VisCoreFactory** opCoreFactory);

  /**
   * Call this method to allocate a new Raw Buffer.
   * @param iSizeInBytes
   *   The size of the Raw Buffer to allocate.
   * @param iAllocationMode
   *   The allocation mode of the Raw Buffer.
   * @param iContentHint
   *   The Raw Buffer content.
   * @param ipData
   *   The data to copy into the new Raw Buffer.
   * @param opRawBuffer
   *   The address where the returned pointer to the Raw Buffer is located.
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>If query succeeds
   *   <dt><tt>E_INVALIDARG</tt>  <dd>If the provided pointer is null
   *   <dt><tt>E_OUTOFMEMORY</tt> <dd>If not enough storage is available to complete the creation.
   *   <dt><tt>E_FAIL</tt>        <dd>If query fails for any other reason.
   *   </dl>
   */
  virtual HRESULT AllocateRawBuffer(VisSize iSizeInBytes, VisRawBufferAllocationMode iAllocationMode, VisRawBufferContentHint iContentHint, const void* ipData, VisRawBuffer** opRawBuffer) = 0;

  /**
   * Call this method to allocate a raw buffer that will have NO CPU side. It will allocate only data on the GPU.
   * @param iSizeInBytes
   *   The size of the Raw Buffer to allocate.
   * @param iAllocationMode
   *   The allocation mode of the Raw Buffer.
   * @param iContentHint
   *   The Raw Buffer content.
   * @param ipData
   *   The data to init the new Raw Buffer.
   * @param opRawBuffer
   *   The address where the returned pointer to the Raw Buffer is located.
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>If query succeeds
   *   <dt><tt>E_INVALIDARG</tt>  <dd>If the provided pointer is null
   *   <dt><tt>E_FAIL</tt>        <dd>If query fails for any other reason.
   *   </dl>
   */
  virtual HRESULT AllocateGPUOnlyRawBuffer(VisSize iSizeInBytes, VisRawBufferAllocationMode iAllocationMode, VisRawBufferContentHint iContentHint, const void* ipData, VisRawBuffer** opRawBuffer) = 0;

    /**
   * Call this method to allocate a raw buffer that will have NO CPU side. It will allocate only data on the GPU.
   * @param iSizeInBytes
   *   The size of the Raw Buffer to allocate.
   * @param iAllocationMode
   *   The allocation mode of the Raw Buffer.
   * @param iContentHint
   *   The Raw Buffer content.
   * @param opRawBuffer
   *   The address where the returned pointer to the Raw Buffer is located.
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>If query succeeds
   *   <dt><tt>E_INVALIDARG</tt>  <dd>If the provided pointer is null
   *   <dt><tt>E_FAIL</tt>        <dd>If query fails for any other reason.
   *   </dl>
   */
  virtual HRESULT AllocateGPUOnlyRawBuffer(VisSize iSizeInBytes, VisRawBufferAllocationMode iAllocationMode, VisRawBufferContentHint iContentHint, VisRawBuffer** opRawBuffer) = 0;

  /**
   * Call this method to create an empty vertices description.
   * @param opDescription
   *   The address where the returned pointer to the description is located.
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>If the creation query succeeds
   *   <dt><tt>E_INVALIDARG</tt>  <dd>If the provided pointer is null
   *   <dt><tt>E_OUTOFMEMORY</tt> <dd>If not enough storage is available to complete the creation.
   *   </dl>
   */
  virtual HRESULT CreateVerticesDescription(VisVerticesDescription** opDescription) = 0;

  /**
   * Call this method to create an empty indices description.
   * @param opDescription
   *   The address where the returned pointer to the description is located.
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>If the creation query succeeds
   *   <dt><tt>E_INVALIDARG</tt>  <dd>If the provided pointer is null
   *   <dt><tt>E_OUTOFMEMORY</tt> <dd>If not enough storage is available to complete the creation.
   *   </dl>
   */
  virtual HRESULT CreateIndicesDescription(VisIndicesDescription** opDescription) = 0;

private:

  /**
   * Constructor.
   */
  VisCoreFactory();

  /**
   * Destructor.
   */
  virtual ~VisCoreFactory();

  /**
   * Copy not allowed.
   */
  VisCoreFactory(const VisCoreFactory&);
  VisCoreFactory& operator=(const VisCoreFactory&);

  static VisCoreFactory* _spFactory;
};

#endif // VISCOREFACTORY_H
