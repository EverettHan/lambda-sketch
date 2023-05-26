#ifndef VISCOMPUTEDRAWINDIRECT_H_
#define VISCOMPUTEDRAWINDIRECT_H_

#include "VisGPGPUEncapsulation.h"
#include "VisComputeBaseProgram.h"

#include <vector>
#include <memory>

class VisComputeManager;
class CATString;

class VisRawBuffer;
class IVisTexture;

class ExportedByCATVisFoundation VisComputeDrawIndirect : public VisComputeBaseProgram
{
  friend class VisIndirectPrimitive;
  friend class vVolRender;
  struct Internal;
public:

  // structures for indirect buffer 
  struct DrawElementsIndirectCommand
  {
    unsigned int  count;
    unsigned int  instanceCount;
    unsigned int  firstIndex;
    unsigned int  baseVertex;
    unsigned int  baseInstance;
  };

  struct DrawArraysIndirectCommand
  {
    unsigned int count;
    unsigned int instanceCount;
    unsigned int first;
    unsigned int baseInstance;
  };

  struct ExportedByCATVisFoundation BufferDesc
  {
    BufferDesc(const CATString& iBufferName, unsigned int iNbDifferentElements = 0);
    BufferDesc(const CATString& iBufferName, VisRawBuffer* iIndirectCommandBuffer, unsigned int iNbDifferentElements);

    CATString bufferName;
    unsigned int nbDifferentElements;
    VisRawBuffer* indirectCommandBuffer;
  };

  class ExportedByCATVisFoundation PrimitiveBufferInfo
  {
  public:
    HRESULT IsValid() const;

  private:
    friend class VisIndirectPrimitive;
    friend struct Internal;

    CATString bufferName;
    unsigned int nbDifferentElements;
    VisRawBuffer* rawBuffer;
    VisComputeDrawIndirect* owningProgram;
  };

public:

  /**
  * Create a VisComputeDrawIndirect program exposing multidraw indirect output buffer
  * @param iEffectFileName the name the PDSFX defining of the compute effect
  * @param iBufferDesc contains a struct defining the effect buffer declared in the effect that
  *        should be interpreted as multidraw indirect buffer.
  *          iBufferDesc.bufferName must match to the name of the effect declared unordered_buffer
  *        otherwise the result is undefined.
  *          iBufferDesc.nbDifferentElements must be different from 0 otherwise the program is not
  *        valid and nullptr is returned.
  * @param iBufferDescs is a pointer to an array of BufferDesc.
  *        every element of this array have to respect the same condition than iBufferDesc
  * @param iNumIndirectBuffers is the number of elements contained in this array
  * @param iComputeFrequency defined the frequency at which the compute program is launched
  *            ePerPrimitive: each time a primitive is draw, the associated VisComputeDrawIndirect is executed
  *            ePerFrame: each time a primitive is draw, only the first associated VisComputeDrawIndirect is executed each frame
  */
  enum class EComputeFrequency { ePerPrimitive, ePerFrame };

  static VisComputeDrawIndirect* Create(const CATString& iEffectFileName, BufferDesc iBufferDesc, EComputeFrequency iComputeFrequency = EComputeFrequency::ePerPrimitive);
  static VisComputeDrawIndirect* Create(const CATString& iEffectFileName, const BufferDesc* iBufferDescs, std::size_t iNumIndirectBuffers, EComputeFrequency iComputeFrequency = EComputeFrequency::ePerPrimitive);


  /**
  * Returns information on the multidraw indirect buffer used to construct an IndirectPrimitive
  * @noparam If no param is provided, returns information concerning the first declared buffer
  * @param iBufferName name of a multidraw indirect buffer declared during the construction of
  *        the program.
  *        If the name do not match any previously declared buffer, an invalid PrimitiveBufferInfo
  *        is returned.
  */
  const PrimitiveBufferInfo& GetPrimitiveBufferInfo() const;
  const PrimitiveBufferInfo& GetPrimitiveBufferInfo(const CATString& iBufferName) const;


  /** Specify the content of the indirect buffer. The size is automatically computed. Be sure you have the right size
  *  (depend if you have index and the number of objects) or you have correctly defined iDataByteSize.
  *  The size formule is : nbDifferentObjects * (HasIndices ? sizeof(VisIndirectPrimitive::DrawElementsIndirectCommand) : sizeof(VisIndirectPrimitive::DrawArraysIndirectCommand));
  *  @param iDrawIndirectBufferName: if specified only set the content of the target iDrawIndirectBufferName,
  *         otherwise all target content are set to the same value.
  *  @param iFrequency is the refresh frequency of the buffer.
  *             eEachCall: Instancing buffer data will be set before each compute if the compute occurs
  *             ePerFrame: Instancing buffer data will be set before each compute if the compute occurs and only once per frame in case of shared buffer
  *             eOnDemand: Instancing buffer data will be set only while the next compute occurs
  *             eNone: Instancing buffer data will not be set (default)
  *  @param iData: the data to set. If not nullptr, the content is copied into an internal container, otherwise 0 is stored.
  *  @param iDataByteSize: size in byte of memory pointed by iData.
  */
  enum EFrequency { eEachCall, ePerFrame, eOnDemand, eNone };
  enum class ERefreshFrequency  { eEachCall = EFrequency::eEachCall, eOnDemand = EFrequency::eOnDemand };

  HRESULT SetInstancingBufferData(EFrequency iFrequency, const void* iData = nullptr, std::size_t iDataByteSize = -1);
  HRESULT SetInstancingBufferData(const CATString& iDrawIndirectBufferName, EFrequency iFrequency, const void* iData = nullptr, std::size_t iDataByteSize = -1);

  HRESULT SetInstancingBufferData(ERefreshFrequency iFrequency = ERefreshFrequency::eEachCall, const void* iData = nullptr, std::size_t iDataByteSize = -1);
  HRESULT SetInstancingBufferData(const CATString& iDrawIndirectBufferName, ERefreshFrequency iFrequency = ERefreshFrequency::eEachCall, const void* iData = nullptr, std::size_t iDataByteSize = -1);

private:
  //Following calls are used internally.
  VisComputeDrawIndirect(HRESULT& oError, const CATString& iEffectFileName, const CATString & iDrawIndirectBufferName, unsigned int iNbDifferentElements, EComputeFrequency iComputeFrequency);
  VisComputeDrawIndirect(HRESULT& oError, const CATString& iEffectFileName, const BufferDesc& iIndirectBuffer, EComputeFrequency iComputeFrequency);
  VisComputeDrawIndirect(HRESULT& oError, const CATString& iEffectFileName, const BufferDesc* iIndirectBuffers, std::size_t iNumIndirectBuffers, EComputeFrequency iComputeFrequency);
  virtual ~VisComputeDrawIndirect();
  virtual HRESULT Compute(void* iProgramArgument) override;

  Internal* m_Internal;
};

#endif /* VISCOMPUTEDRAWINDIRECT_H_ */
