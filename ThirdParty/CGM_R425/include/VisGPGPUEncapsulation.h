#ifndef VISGPGPUENCAPSULATION_H_
#define VISGPGPUENCAPSULATION_H_

struct MotherHandle
{
  int _handle;

  MotherHandle(int iValue)
    :_handle(iValue)
  { }

  MotherHandle()
    :_handle(-1)
  { }

  MotherHandle & operator=(int iValue)
  {
    _handle = iValue;
    return *this;
  }

  bool operator >(int rhs) const
  { return _handle > rhs; }

  bool operator <(int rhs) const
  { return _handle < rhs; }

  bool operator >=(int rhs) const
  { return _handle >= rhs; }

  bool operator <=(int rhs) const
  { return _handle <= rhs; }

  bool operator ==(int rhs) const
  { return _handle == rhs; }

  bool operator !=(int rhs) const
  { return _handle != rhs; }

  bool operator == (const MotherHandle & iRhs) const
  { return _handle == iRhs._handle; }

  bool operator != (const MotherHandle & iRhs) const
  { return _handle != iRhs._handle; }

};

#define CREATE_HANDLE(iName)       \
struct iName : public MotherHandle \
{                                  \
  iName(int iValue)                \
  :MotherHandle(iValue)          \
{ }                              \
  \
  iName()                          \
  :MotherHandle()                \
{ }                              \
  \
  \
};

CREATE_HANDLE(VisPlatformHandle);
CREATE_HANDLE(VisContextHandle);
CREATE_HANDLE(VisDeviceHandle);
CREATE_HANDLE(VisCommandQueueHandle);
CREATE_HANDLE(VisProgramHandle);
CREATE_HANDLE(VisKernelHandle);
CREATE_HANDLE(VisBufferHandle);
CREATE_HANDLE(VisImageHandle);
CREATE_HANDLE(VisSamplerHandle);
CREATE_HANDLE(VisEventHandle);

typedef void* VisComputeContext; ///< This type is used for compute

struct VisPrepareContext ///< This type is used for prepare
{
  int    id;
  void * execContext;
};

typedef void* VisShaderOptions;

// #define PREPARECONTEXT_MIGRATION


enum VisGPGPUMemFlag
{
  READ_WRITE      = 1 << 0,
  WRITE_ONLY      = 1 << 1,
  READ_ONLY       = 1 << 2,
  /*HOST_NO_ACCESS  = 1 << 3, ///OpenCL 1.2, Pas encore supporte en V6 on prevoit quand meme les flags
  HOST_READ_ONLY  = 1 << 4,
  HOST_WRITE_ONLY = 1 << 5,*/
  USE_HOST_PTR    = 1 << 6,
  ALLOC_HOST_PTR  = 1 << 7,
  COPY_HOST_PTR   = 1 << 8
};

enum VisGPGPUImageChannel
{
  CHANNEL_R,
  CHANNEL_A,
  CHANNEL_INTENSITY,
  CHANNEL_LUMINANCE,
  CHANNEL_RG,
  CHANNEL_RA,
  CHANNEL_RGB,
  CHANNEL_RGBA,
  CHANNEL_ARGB,
  CHANNEL_BGRA
};

enum VisGPGPUImageDataType
{
  IMG_SNORM_INT8,
  IMG_SNORM_INT16,
  IMG_UNORM_INT8,
  IMG_UNORM_INT16,
  IMG_UNORM_SHORT_565,
  IMG_UNORM_SHORT_555,
  IMG_UNORM_INT_101010,
  IMG_SIGNED_INT8,
  IMG_SIGNED_INT16,
  IMG_SIGNED_INT32,
  IMG_UNSIGNED_INT8,
  IMG_UNSIGNED_INT16,
  IMG_UNSIGNED_INT32,
  IMG_HALF_FLOAT,
  IMG_FLOAT
};

enum VisGPGPUAddressingMode
{
  ADDRESS_REPEAT,
  ADDRESS_CLAMP_TO_EDGE,
  ADDRESS_CLAMP,
  ADDRESS_NONE
};

enum VisGPGPUFilteringMode
{
  FILTER_NEAREST,
  FILTER_LINEAR
};

enum VisGPGPUMapFlag
{
  MAP_READ  = 1 << 0,
  MAP_WRITE = 1 << 1
};

enum VisGPGPUEventFlag
{
  EVENT_TYPE_USER = 1,
  EVENT_TYPE_COMMAND = 2
};

enum VisGPGPUEventStatus
{
  EVENT_COMPLETE,
  EVENT_NOT_READY
};


#endif //VISGPGPUENCAPSULATION_H_
