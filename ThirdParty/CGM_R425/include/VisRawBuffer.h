#ifndef VISRAWBUFFER_H
#define VISRAWBUFFER_H

// COPYRIGHT DASSAULT SYSTEMES 2009

#include "VisCore.h"

#include "IUnknown.h"

#include "VisDataType.h"
#include "CATSysErrorDef.h"
#include <memory>
#include <cstdint>

typedef enum _VisRawBufferAllocationMode
{
  RAWBUFFER_READ_ONLY,
  RAWBUFFER_READ_WRITE,
  // This should be typically used for buffers that are updated frequently.
  // You can also use VisRawBuffer::TransferData(VisDataBlob) to set the data instead of using Map/Unmap
  // The type just indicates that buffer should use dynamic streaming.
  RAWBUFFER_DYNAMIC_READ_WRITE,
} VisRawBufferAllocationMode;

typedef enum _VisRawBufferContentHint
{
  RAWBUFFER_VERTICES_AND_INDICES,
  RAWBUFFER_VERTICES_ONLY,
  RAWBUFFER_INDICES_ONLY,
  RAWBUFFER_PRIVATE_DATA,
} VisRawBufferContentHint;

#if defined _WINDOWS_SOURCE || defined _LINUX_SOURCE
using VisDataBlob = std::shared_ptr<std::uint8_t[]>;
#else
// Andriod Clang has problem with the above declaration
using VisDataBlob = std::shared_ptr<std::uint8_t>;
#endif

class ExportedByVisCore VisRawBuffer : public IUnknown
{
  friend class CATVisPrimitiveGroupRepStreamingAdapter; // TO BE REMOVED
  friend class CATVisPrimitiveGroupRepToSurfacicRepAdapter;
  friend class CATVis2DPrimitiveGroupRepTo2DCustomRepAdapter;
  friend class CATSGV6StreamingTests; // TO BE REMOVED
  friend class CATSGV6XMLPrimitiveGroupRepAdapter;

public:

  enum VisMapMode
  {
    READ_ONLY,
    WRITE_ONLY,
    READ_WRITE
  };


#if defined(REMOVE_USELESS_INCLUDE) 
#pragma message ("BADREM : FDT1 2022/06/30 "  __FILE__  " VisRawBuffer::~VisRawBuffer is a forbidden method, please use Release method instead. ")
protected:
#endif

  /**
   * Destructor.
   */
  virtual ~VisRawBuffer();

public:

  virtual VisSize GetSizeInBytes() const = 0;

  virtual HRESULT StartUpdate() = 0;

  /// @brief  This function allows you to set a iData blob on the VisRawBuffer
  /// This is the preferred API for updating dynamic buffers. Internally
  /// this buffer will be persistently mapped.
  /// 
  /// Contract:
  /// The buffer size is the full buffer, and offset is 0.
  /// Once this pointer/blob is set, the contract is, you should not modify the
  /// contents of this pointer, you can still hold on to the blob for reading.
  /// The pointer is a shared_ptr but, the function expects an ownership
  /// transfer of the memory. (unique_ptr is not used because the memory
  /// will be shared internally within render engine) and will be available
  /// in VisRawBuffer for reading via Map/Unmap
  /// Since the function signature expects you move the memory (thus r-value-ref)
  /// you can hold on to a weak_ptr instead. 
  /// If you hold on to the shared_ptr as shared_ptr, keep in mind, unless 
  /// you set it to null yourself, the memory will not be re-usable.
  /// 
  /// Advanced use case: 
  /// You intend to use a memory-pool and reuse memory chunks. But you do not
  /// know when you can reuse the buffer pointer, after first write, because
  /// of the contract.
  /// In this case, use a custom deleter, example:
  /// VisDataBlob blob = VisDataBlob(new std::uint8_t[Size], [&myPool](auto iPtr) { myPool.PushAvailable(iPtr); });
  /// Keep in mind that the VisDataBlob shared_ptr can be destroyed from any thread
  /// So you would want your pool/container class restoring the pointer to be thread safe.
  /// This pattern is applicable if you want to free the memory pointer using a custom method/deleter.
  /// Eg: VisDataBlob((std::uint8_t*)ipRawBuffer, [](auto ptr) { if (ptr) free(ptr); })
  virtual HRESULT TransferData(VisDataBlob&& iData) = 0;

  virtual HRESULT SetData(const void* ipData, VisSize iSizeInBytes, VisSize iOffsetInBuffer) = 0;

  virtual HRESULT EndUpdate() = 0;

  virtual void * MapBuffer(VisMapMode iMapMode, VisSize iOffsetInBuffer, VisSize iSizeInBytes) = 0;

  virtual HRESULT UnmapBuffer(void *& ioPtr) = 0;

  /**
   * Reads at most iSize bytes from the buffer starting at iOffset.
   *
   * Example:
   * \code
   *   char* bufferContent = new char[pBuffer->GetSizeInBytes()];
   *
   *   pBuffer->GetData(bufferContent, pBuffer->GetSizeInBytes()); // reads the entire buffer
   *
   *   pBuffer->GetData(bufferContent, 10);  // reads the 10 first bytes of the buffer
   *
   *   pBuffer->GetData(bufferContent, 20, 10);  // reads the next 20 bytes
   * \endcode
   */
  virtual HRESULT GetData(void* opData, VisSize iSize, VisSize iOffset = 0u) = 0;

protected:

  /**
   * Builds an empty raw buffer.
   */
  VisRawBuffer();

  // used by friend streaming class only
  virtual HRESULT GetContentHint(VisRawBufferContentHint& oContentHint) const = 0;
  virtual HRESULT GetRawPointer(VisSize iOffsetInBuffer, void*& oRawPointer) = 0;

private:

  VisRawBuffer(const VisRawBuffer&);
  VisRawBuffer & operator=(const VisRawBuffer&);

};

#endif // VISRAWBUFFER_H
