/**
@vkCallBuffer.h

@COPYRIGHT

@ Nicolas Galinotti
*/

#ifndef __vkCallBuffer_h
#define __vkCallBuffer_h


#if !defined(__vkArgument_h)
  #include "vkArgument.h"
#endif

#include <vector>
#include <cstdint>

namespace VKernel {

class vkCallBufferIter;

#ifdef VK_64BIT
  typedef std::uint64_t StackUnit;
  #define SIZE_SU 8
  #define INC64 1
#else
  typedef std::uint32_t StackUnit;
  #define SIZE_SU 4
  #define INC64 2
#endif

static const uint32 s_cbAlignSize = sizeof(ptrdiff)-1;

/*
-->Pointeur Write Down
Size
Dtor
ObjStart
...
ObjectEnd
Size
Dtor
ObjStart
...
ObjectEnd
-->End of Buffer
*/

class vkCallBuffer
{
  public:
    vkCallBuffer(uint8* iMem,uint32 iSize) :
      m_Buff((StackUnit*)iMem),
      m_BuffWriteUp((StackUnit*) iMem),
      m_BuffWriteDown((StackUnit*)(iMem+iSize))
    {
      memset(m_Buff,0,iSize);
    }

    ~vkCallBuffer(){
        // Call the Dtors of the created Objs
    }

    void* GetBuffer(){
      return m_Buff;
    }

    uint32 GetSize() const {
      return (uint32)(m_BuffWriteUp - m_Buff) * sizeof(StackUnit);
    }

    void PushObject(void* iPtr){
      VKASSERT(m_Buff==m_BuffWriteUp);
      m_hasObject = true;
      PushPointerArg(iPtr);
    }

    bool PushPointerArg(void* iPtr){PushData(iPtr);return true;}
    // Push 8,16,32 Can cause sign extension problem on some platform, need to check on PPC/ARM
    bool PushInt8(uint8 iInt8)    {PushData(iInt8);return true;}
    bool PushInt16(uint16 iInt16) {PushData(iInt16);return true;}
    bool PushInt32(uint32 iInt32) {PushData(iInt32);return true;}
    bool PushInt64(uint64 iInt64) {PushData(iInt64);return true;}
    bool PushFloat(float iFloat)  {PushData(iFloat);return true;}
    bool PushDouble(double iDouble) {PushData(iDouble);return true;}
    void PushType(vkType* /*iStruct*/, void* /*iStructPtr*/){VKASSERT(0);}

    void PushDefaultArgument(const vkArgument& iArg){
      const uint32 f = iArg.flags & (vkArgument::eIsPod);
      switch(f){
        case vkArgument::e8BitPod : PushInt8(*(uint8*)iArg.GetDefaultValueBuffer()); break;
        case vkArgument::e16BitPod: PushInt16(*(uint16*)iArg.GetDefaultValueBuffer()); break;
        case vkArgument::e32BitPod: PushInt32(*(uint32*)iArg.GetDefaultValueBuffer()); break;
        case vkArgument::e64BitPod: PushInt64(*(uint64*)iArg.GetDefaultValueBuffer()); break;
        default:
          if (iArg.IsRef())
            PushPointerArg((void*)0);
          else {
            m_ObjectSizes.push_back(iArg.GetSize());
            iArg.type->CopyConstruct(m_BuffWriteUp,iArg.GetDefaultValueBuffer());
            m_BuffWriteUp += ((iArg.GetSize() + s_cbAlignSize) & ~s_cbAlignSize)/sizeof(StackUnit);
          }
          break;
      }
    }
    void PushArgument(const vkArgument& iArg, void* iBuffer,bool32 bIsRef ){
      const uint32 f = iArg.flags & (vkArgument::eIsPod);

      switch(f){
        case vkArgument::e8BitPod: PushInt8(**(uint8**)iBuffer); break;
        case vkArgument::e16BitPod:PushInt16(**(uint16**)iBuffer); break;
        case vkArgument::e32BitPod:PushInt32(**(uint32**)iBuffer); break;
        case vkArgument::e64BitPod:PushInt64(**(uint64**)iBuffer); break;
        default:
          if (bIsRef)
            PushPointerArg(iBuffer);
          else {
            m_ObjectSizes.push_back(iArg.GetSize());
            iArg.type->CopyConstruct(m_BuffWriteUp,*(ptrdiff**)iBuffer);
            m_BuffWriteUp += ((iArg.GetSize() + s_cbAlignSize) & ~s_cbAlignSize)/sizeof(StackUnit);
          }
          break;
      }
    }

  private:

    template<typename T>
    void PushData(T iData){
      uint32 typeSize = sizeof(T);
      uint32 nbInc    = typeSize/SIZE_SU;
      if (typeSize%SIZE_SU>0)
        nbInc++;
      *(T*)m_BuffWriteUp = iData;
      m_BuffWriteUp += nbInc;
      m_ObjectSizes.push_back(typeSize);
      VKASSERT(m_BuffWriteUp<=m_BuffWriteDown);
    }

    bool                m_hasObject = false;
    std::vector<size_t> m_ObjectSizes;

    StackUnit* m_Buff;
    StackUnit* m_BuffWriteUp;
    StackUnit* m_BuffWriteDown;

    friend class vkCallBufferIter;
    friend class vkCallBufferAccessor;
};

#define CREATE_VK_CALL_BUFFER_ON_STACK(varName,sz) std::int32_t sizeAlloca##varName = sz+sizeof(VKernel::StackUnit); \
                                                   void* mem##varName = alloca(sizeAlloca##varName); \
                                                   VKernel::vkCallBuffer varName((VKernel::uint8*)mem##varName,sizeAlloca##varName);

// Iterator on successive argument stored in a vkCallBuffer.
// Check if the expected sizes are coherent with the stored ones (m_ObjectSizes)
class vkCallBufferIter
{
  private:

    const vkCallBuffer & m_ReferenceBuffer;
    StackUnit          * m_CurStackUnit  = nullptr;
    size_t               m_NumData       = 0;

  public:

  vkCallBufferIter(const vkCallBuffer & iBuffer)
    : m_ReferenceBuffer(iBuffer)
    {
      m_CurStackUnit    = iBuffer.m_Buff;
    }

  // Returns the object on which to apply the method. Should return nullptr for all non static data member methods
  void* GetObj()
  {
    VKASSERT(m_NumData==0);
    if (!m_ReferenceBuffer.m_hasObject)
      return nullptr;
    void ** ptrRet = (void**)Next(SIZE_SU);
    return (ptrRet)?(*ptrRet):(nullptr);
  }

  // Returns the rest of the buffer regardless the number of arguments it contains
  void* NextAsBuffer(int32 & oSize)
  {
    oSize = (int32)(m_ReferenceBuffer.m_BuffWriteUp-m_CurStackUnit) * SIZE_SU;
    void* res      = m_CurStackUnit;
    m_NumData      = m_ReferenceBuffer.m_ObjectSizes.size();
    m_CurStackUnit = m_ReferenceBuffer.m_BuffWriteDown;
    return res;
  }

  // Returns the next argumment. The type is not specified but only its size.
  void* Next(uint32 iDataSize)
  {
    // Check data size coherency
    VKASSERT(m_ReferenceBuffer.m_ObjectSizes[m_NumData]==iDataSize);
    m_NumData++;

    uint32 nbStackUnitDiv = iDataSize/ SIZE_SU;
    uint32 nbStackUnitMod = iDataSize % SIZE_SU;
    if (nbStackUnitMod > 0)
      nbStackUnitDiv++;

    VKASSERT(m_CurStackUnit+ nbStackUnitDiv <=m_ReferenceBuffer.m_BuffWriteDown);
    void* ret = m_CurStackUnit;
    m_CurStackUnit += nbStackUnitDiv;

    return ret;
  }

};

// Accessors on buffer object from their index
// ===========================================
class vkCallBufferAccessor
{
  private:
    std::vector<void*>   m_Objects;
    const vkCallBuffer & m_ReferenceBuffer;

  public:

  vkCallBufferAccessor(const vkCallBuffer & iBuffer) :
    m_ReferenceBuffer(iBuffer)
    {
      vkCallBufferIter iterOnBuffer(iBuffer);
      for (const size_t & sizeCurElt : iBuffer.m_ObjectSizes)
        m_Objects.push_back(iterOnBuffer.Next((uint32)sizeCurElt));
    }

  void* get(size_t iInd, uint32 iDataSize)
    {
      (void)iDataSize;
      VKASSERT(m_ReferenceBuffer.m_ObjectSizes[iInd]==iDataSize);
      return m_Objects[iInd];
    }
};

} // namespace VKernel

#endif // __vkCallBuffer_h

