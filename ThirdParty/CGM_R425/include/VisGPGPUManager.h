#ifndef VISGPGPUMANAGER_H_
#define VISGPGPUMANAGER_H_

#include "CATVisFoundation.h"
#include "VisGPGPUEncapsulation.h"
#include "CATSysErrorDef.h"
#include "VisGPGPUProgram.h"
#include "CATDataType.h"

#include <vector>
#include <string>
#include <cstdlib>

class VisGPGPUProgramInitializer;
struct VisGPGPUTextureInformation;

class ExportedByCATVisFoundation VisGPGPUManager
{
  friend struct VisGPGPUManagerLifecycle;
  friend class VisGenericProgram;
  friend class VisOpenCLProgram;
  friend class VisGPGPUPrimitive; //Need to know if in OpenCL or Cuda
  friend class VisOpenCLProgramInitializer; //To destroy context and command queues
  friend class VisCudaProgramInitializer; //To destroy context and command queues
  friend class VisGPGPUScheduler; //Need to know if in OpenCL or Cuda to schedule Compute pur
  friend class VisCUDAManagerTstClass;     //Pour les tests.
  friend class VisOpenCLManagerTstClass;  //For tests
  friend class VisOpenCLManager; //For static s_instance
  friend class VisComputeProgram;
protected :

  VisGPGPUManager();
  virtual ~VisGPGPUManager();

public :

  struct ExportedByCATVisFoundation DeviceInfo
  {
    DeviceInfo();
    DeviceInfo(const DeviceInfo & iDeviceInfoToCopy);
    ~DeviceInfo();

    void Fill(const DeviceInfo & iCopy);

    unsigned int   _maxThreadsPerBlock; ///< Gives the max number of threads per block
    unsigned int * _maxGridDim;         ///< Max block per grid. Has 3 components
    unsigned long  _localMemSize;				//CL_DEVICE_LOCAL_MEM_SIZE
    unsigned int   _maxComputeUnits;		//CL_DEVICE_MAX_COMPUTE_UNITS
    unsigned int   _deviceType;		      //CL_DEVICE_TYPE
    CATULONG64     _globalMemCacheSize;	//CL_DEVICE_GLOBAL_MEM_CACHE_SIZE
    unsigned char  _deviceAddressSpace; ///< The address space size.
    char *         _driverVersion;			//CL_DRIVER_VERSION
    char *         _deviceName;         ///<The device Name
  };

  enum ComputingType
  {
    COMPUTE_ONLY,     ///<Define Computing without OpenGL Interoperability
    COMPUTE_AND_DRAW  ///<Define Computing with OpenGL Interoperability
  };

  enum DeviceType
  {
    CPU,
    GPU,
    ACC,
    GPUSERVER
  };

  struct GPGPUApi
  {
    enum Type
    {
      Cuda,
      OpenCL,
	    Compute
    };
  };

public :

  static VisGPGPUManager * GetInstance();

    /** Initialize the first device that match with the parameters. (Cannot handle multi device)
   *  @param iComputingType The Computing type : Enable or disable OpenGL Interoperability
   *  @param iDeviceType The type of device wanted : CL_DEVICE_TYPE_GPU, CL_DEVICE_TYPE_CPU... 
   *  All the OpenCL Type are supported.
   *  By default : CL_DEVICE_TYPE_DEFAULT = GPU, CL_DEVICE_TYPE_ALL = Error
   *  @param oInitializer The structure initialized. 
   *  oInitializer MUST be NULL !
   *  @return S_OK if succeed, E_GPGPU_NO_DEVICE_FOUND if no devices are found with the specified type, E_FAIL otherwise
   *  You can have E_GPGPU_NO_DEVICE_FOUND if you want an accelerator and the machine doesn't have it !
  */
  virtual HRESULT FastInit(const ComputingType & iComputingType, const DeviceType & iDeviceType, 
                           VisGPGPUProgramInitializer *& oInitializer) = 0;


  void GetInformation(const VisDeviceHandle & iDeviceToGetInformation, DeviceInfo & oInformations) const;

  
  /** Give information on all the devices in the computer 
   *  @deprecated Use the other GetInformation method
   *  @return A list of oclDeviceInfo *. You MUST RELEASE each oclDeviceInfo * !
   *  (otherwise it will leak !)
   */
  virtual void GetInformation(DeviceInfo *& oInformations, unsigned int & oNbInformations) const = 0;

  /** Give information on all the devices with a specified type given by iDeviceType
   *  @deprecated Use the other GetInformation method
   *  @param iDeviceType The type of device wanted : CL_DEVICE_TYPE_GPU, CL_DEVICE_TYPE_CPU... 
   *  All the OpenCL types are supported.
   *  By default : CL_DEVICE_TYPE_DEFAULT = GPU, CL_DEVICE_TYPE_ALL = Error
   *  @return A list of oclDeviceInfo *. You MUST RELEASE each oclDeviceInfo * !
   *  (otherwise it will leak !)
   */
  virtual void GetInformation(DeviceInfo *& oInformations, unsigned int & oNbInformations, const DeviceType & iDeviceType) const = 0;

   /** Initialize the devices wanted (handle multi-device. GPU + GPU, GPU + CPU, GPU+GPU+GPU+Accelerator...)
    *  @param iListDeviceToInit The list of the device that you want to initialize together
    *  List of oclDeviceInfo *. One more time : Don't forget to delete oclDeviceInfo !
    *  @param iType Choose if you want to use interoperability or not
    *  @param oInitializer The structure initialized. 
    *  oInitializer MUST be NULL !
    *  @return S_OK if succeed, E_GPGPU_NO_DEVICE_FOUND if no devices are found with the specified type, E_FAIL otherwise
    *  You can have E_GPGPU_NO_DEVICE_FOUND if you want an accelerator and the machine doesn't have it !
    */
  virtual HRESULT Init(const DeviceInfo & iDeviceInfo, const ComputingType iType, VisGPGPUProgramInitializer *& oInitializer) = 0;

  /** Check if an extension is available for the device
   *  @param iInformation The Information structure of the device that you want to have information
   *  @param iExtension The name of the Extension
   *  @return true if the extension is in the list, else false
   */
  //virtual bool ExtensionAvailable(const OclDeviceInfo & iInformation, char * iExtension) const;

  /** This method tells if you are in Cuda or OpenCL.
   *  Make special care if you use this method, your code may become non generic.
   *  @return true if in Cuda else false.
   */
  GPGPUApi::Type GetGPGPUApi() const
  { return _gpgpuApi; }

  /** Create new command queues for a specific or all devices. The new command queues are add after the current in ioInitializer.
   *  @param iNbCmdQueue The command queue number per device you want to create.
   *  @param iDeviceID The index in VisGPGPUProgramInitializer::_deviceHandleList. Begin to 0. If you set -1, you will create command queues fo all devices.
   *  @param ioInitializer Will contain the new command queues appended to the older one.
   */
  virtual HRESULT AddCommandQueue(unsigned int iNbCmdQueue, int iDeviceID, VisGPGPUProgramInitializer * ioInitializer) const = 0;

  //API abstraction

  virtual HRESULT CreateBuffer(const VisContextHandle & iContext, 
                               const unsigned int & iMemFlag, 
                               const size_t iSizeInBytes, 
                               void * iDataPtr, 
                               VisBufferHandle & oBuffer) const = 0;

  virtual HRESULT CreateBufferFromGraphics(const VisContextHandle & iContext, const VisGPGPUMemFlag & iMemFlag, const unsigned int iGraphicBuffer, VisBufferHandle & oBuffer) const = 0;

  virtual HRESULT CreateImage2D(const VisContextHandle & iContext, 
                                const VisGPGPUMemFlag & iMemFlag, 
                                const VisGPGPUImageChannel & iChannelCOnfiguration,
                                const VisGPGPUImageDataType & iDataType, 
                                const size_t iWidth, 
                                const size_t iHeight, 
                                void * iDataPtr, 
                                VisImageHandle & oImage,
                                const size_t iRowPitch = 0) const = 0;

  virtual HRESULT CreateImage2DFromGraphic(const VisContextHandle & iContext, 
                                           const VisGPGPUMemFlag & iMemFlag, 
                                           const unsigned int iMipLevel, 
                                           const VisGPGPUTextureInformation & iGraphicTexture,
                                           VisImageHandle & oImage) const = 0;

  virtual HRESULT CreateSampler(const VisContextHandle & iContext,
                                const VisProgramHandle & iProgram,
                                const char * iTexRefName,
                                const VisGPGPUAddressingMode & iAddressingMode,
                                const VisGPGPUFilteringMode & iFilteringMode,
                                VisSamplerHandle & oSampler,
                                bool iReadOnly = true,
                                bool iUseNormalizedCoords = false) const = 0;

  virtual HRESULT CreateEvent(const VisContextHandle & iContext,
                              VisEventHandle &oEvent,
                              unsigned int flags = 0u ) const = 0;

  virtual HRESULT DeleteBuffer(VisBufferHandle & iBuffer) const = 0;
  virtual HRESULT DeleteImage(VisImageHandle & iImage) const = 0;
  virtual HRESULT DeleteSampler(VisSamplerHandle & iSampler) const = 0;
  virtual HRESULT DeleteEvent(VisEventHandle & iEvent) const = 0;

  virtual HRESULT CreateKernel(const VisProgramHandle & iProgram, const char * iKernelName, VisKernelHandle & oKernel) const = 0;
  virtual HRESULT DeleteKernel(VisKernelHandle & iKernel) const = 0;

  virtual HRESULT LaunchKernel(const VisCommandQueueHandle & iCmdQueue,
                               const VisKernelHandle & iKernel,
                               unsigned int iDim,
                               const size_t * iNbBlocksPerGrid,
                               const size_t * iNbThreadsPerBlock,
                               const VisEventHandle & iEvent = VisEventHandle(-1) ) const = 0;

  virtual HRESULT SetKernelArgument(const VisKernelHandle & iKernel, const unsigned int iPosition, const VisBufferHandle & iArgument) const = 0;
  virtual HRESULT SetKernelArgument(const VisKernelHandle & iKernel, const unsigned int iPosition, const VisSamplerHandle & iSampler, const VisImageHandle & iImage) const = 0;
  virtual HRESULT SetKernelArgument(const VisKernelHandle & iKernel, const unsigned int iPosition, const VisSamplerHandle & iSampler, const VisBufferHandle & iBuffer) const = 0;
  virtual HRESULT SetKernelArgument(const VisKernelHandle & iKernel, const unsigned int iPosition, void * iArgument, const unsigned int & iSizeInBytes) const = 0;

  virtual HRESULT AcquireGraphicAPIObjects(const VisCommandQueueHandle & iCmdQueue, 
                                           VisBufferHandle * listOfObjects, 
                                           unsigned int iNbObjects) const = 0;

  virtual HRESULT AcquireGraphicAPIObjects(const VisCommandQueueHandle & iCmdQueue, 
                                           VisImageHandle * listOfObjects, 
                                           unsigned int iNbObjects) const = 0;

  virtual HRESULT ReleaseGraphicAPIObjects(const VisCommandQueueHandle & iCmdQueue, 
                                           VisBufferHandle * listOfObjects, 
                                           unsigned int iNbObjects) const = 0;

  virtual HRESULT ReleaseGraphicAPIObjects(const VisCommandQueueHandle & iCmdQueue, 
                                           VisImageHandle * listOfObjects, 
                                           unsigned int iNbObjects) const = 0;

  virtual HRESULT CopyBufferToBuffer(const VisCommandQueueHandle & iCmdQueue, 
                                     const VisBufferHandle & iSrc, 
                                     const VisBufferHandle & iDst, 
                                     const size_t iSrcOffset, 
                                     const size_t iDstOffset, 
                                     const size_t iSizeInBytes,
                                     const VisEventHandle & iEvent = VisEventHandle(-1)) const = 0;

  virtual HRESULT CopyBufferToImage(const VisCommandQueueHandle & iCmdQueue, 
                                    const VisBufferHandle & iSrc, 
                                    const VisImageHandle & iDst, 
                                    const size_t iSrcOffset, 
                                    const size_t * iDstOrigin, 
                                    const size_t * iRegion,
                                    const VisEventHandle & iEvent = VisEventHandle(-1)) const = 0;

  virtual HRESULT CopyImageToBuffer(const VisCommandQueueHandle & iCmdQueue, 
                                    const VisImageHandle & iSrc, 
                                    const VisBufferHandle & iDst, 
                                    const size_t * iSrcOrigin, 
                                    const size_t iDstOffset, 
                                    const size_t * iRegion,
                                    const VisEventHandle & iEvent = VisEventHandle(-1)) const = 0;

  virtual HRESULT MapBuffer(const VisCommandQueueHandle & iCmdQueue, 
                            const VisBufferHandle & iBuffer,
                            bool iIsBlocking, 
                            const VisGPGPUMapFlag & iMapFlag, 
                            size_t iOffset, 
                            size_t iSizeInBytes, 
                            void *& oPtrBuffer) const = 0;

  virtual HRESULT MapImage(const VisCommandQueueHandle & iCmdQueue, 
                           const VisImageHandle & iImage, 
                           bool iIsBlocking, 
                           const VisGPGPUMapFlag & iMapFlag, 
                           const size_t * iOrigin, 
                           const size_t * iRegion, 
                           size_t & oRowPitch, 
                           size_t & oSlicePitch, 
                           void *& oPtrBuffer) const = 0;

  virtual HRESULT UnmapBuffer(const VisCommandQueueHandle & iCmdQueue, 
                              const VisBufferHandle & iBuffer, 
                              void * iMapedMemory) const = 0;

  virtual HRESULT UnmapImage(const VisCommandQueueHandle & iCmdQueue, 
                             const VisImageHandle & iImage, 
                             void * iMapedMemory) const = 0;

  virtual HRESULT ReadBuffer(const VisCommandQueueHandle & iCmdQueue,
                             const VisBufferHandle & iBuffer, 
                             bool iIsBlocking,
                             size_t iOffset, 
                             size_t iSizeInBytes, 
                             void * oPtrBuffer,
                             const VisEventHandle & iEvent = VisEventHandle(-1)) const = 0;

  virtual HRESULT ReadImage(const VisCommandQueueHandle & iCmdQueue, 
                            const VisImageHandle & iImage, 
                            bool iIsBlocking, 
                            const size_t * iOrigin, 
                            const size_t * iRegion, 
                            size_t iRowPitch, 
                            size_t iSlicePitch, 
                            void * oPtrBuffer,
                            const VisEventHandle & iEvent = VisEventHandle(-1)) const = 0;

  virtual HRESULT WriteBuffer(const VisCommandQueueHandle & iCmdQueue,
                              const VisBufferHandle & iBuffer, 
                              bool iIsBlocking,
                              size_t iOffset, 
                              size_t iSizeInBytes, 
                              const void * iPtrBuffer,
                              const VisEventHandle & iEvent = VisEventHandle(-1)) const = 0;

  virtual HRESULT WriteImage(const VisCommandQueueHandle & iCmdQueue,
                             const VisImageHandle & iImage, 
                             bool iIsBlocking, 
                             const size_t * iOrigin, 
                             const size_t * iRegion, 
                             size_t iRowPitch, 
                             size_t iSlicePitch, 
                             const void * iPtrBuffer,
                             const VisEventHandle & iEvent = VisEventHandle(-1)) const = 0;

  virtual HRESULT RecordEvent(const VisCommandQueueHandle & iCmdQueue,
                              const VisEventHandle & iEvent) const = 0;

  virtual HRESULT QueryEvent(const VisEventHandle & iEvent,
                             VisGPGPUEventStatus & oStatus ) const = 0;

  virtual HRESULT SynchronizeEvent(const VisEventHandle & iEvent, 
                                   bool now=true) const = 0;

  virtual HRESULT Finish(const VisCommandQueueHandle & iCmdQueue) const = 0;

  virtual HRESULT Flush(const VisCommandQueueHandle & iCmdQueue) const = 0;

  virtual const char * GetLastError() const = 0;

protected :

  /** Init the manager. Get all the devices in the computer and fill class member
   *  @return S_OK or E_FAIL
   */
  virtual HRESULT InitManager() = 0;

  /** Permet de compiler les kernels. Cette methode n'est accessible que pour les classes suivantes : VisGenericProgram, VisOpenCLProgram.
   *
   */
  virtual HRESULT Compile(const std::vector<VisGPGPUProgram::moduleInputType*> & iKernelList, const std::string & iCompilingOptions, 
                          std::vector<std::string> & oErrorList, std::vector<VisProgramHandle> & oProgramList,
                          VisGPGPUProgramInitializer & iInitializer) const = 0;

  virtual HRESULT LoadBinaries(const std::vector<VisGPGPUProgram::moduleInputType*> & iKernelList,
                               const std::string & iCompilingOptions,
                               std::vector<std::string> & oErrorList,
                               std::vector<VisProgramHandle> & oProgramList,
                               VisGPGPUProgramInitializer & iInitializer) const = 0;

  virtual HRESULT CreateBinaries(const std::vector<VisGPGPUProgram::moduleInputType*> & iKernelList, 
                                 const std::string & iCompilingOptions, 
                                 VisGPGPUProgramInitializer & iInitializer,
                                 const std::vector<VisProgramHandle> & iProgramList) const = 0;


  virtual HRESULT DeleteProgram(VisProgramHandle & iProgram) const = 0;

  virtual HRESULT DeleteCommandQueue(VisCommandQueueHandle & iCommandQueue) const = 0;

  virtual HRESULT DeleteContext(VisContextHandle & iContext) const = 0;

protected:

  GPGPUApi::Type _gpgpuApi;

  std::vector<DeviceInfo*> _informations;

  static VisGPGPUManager * s_instance;

};


#endif // VISGPGPUMANAGER_H_
