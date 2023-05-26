#ifndef CATSGStreamBuffer_h_
#define CATSGStreamBuffer_h_

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "CATCompStream.h"
#include "CATIOBuffer.h"

class ExportedBySGComposites CATSGStreamBuffer : public CATSGCompositeHost1<CATCompStream, CATSGComposite>
{
public:
    CATSGStreamBuffer();
    CATSGStreamBuffer(CATIOBufferPtr& iInputBuffer);
    virtual ~CATSGStreamBuffer();

    virtual CATBoolean IsLockedOnWrite() const;
    virtual CATBoolean IsLockedOnRead() const;
    virtual HRESULT SetWriteLock(CATBoolean iLocked);
    virtual HRESULT SetReadLock(CATBoolean iLocked);

    virtual HRESULT DumpAsBuffer(CATIOBufferPtr& oOutputBuffer);
    virtual HRESULT DumpIntoStream(CATCompStreamPtr& iOtherStream, CATSG::uint32& oDumpedLength);
    virtual CATSG::uint32 GetLength();
    virtual HRESULT SetLength(const CATSG::uint32 iLength);
    virtual CATSG::uint32 GetCurrentPosition() const;
    virtual HRESULT SetCurrentPosition(const CATSG::uint32 iNewPos);
    virtual CATSG::uint32 ComputeChecksum(CATSG::uint32 iMaxLength = 0);

    virtual HRESULT WriteGUID(const GUID& iObj);
    virtual HRESULT ReadGUID(GUID& oObj);

    virtual HRESULT WriteRef(const CATSGRef& iObj);
    virtual HRESULT ReadRef(CATSGRef& oObj);

    virtual HRESULT WriteData(const void* iBuffer, const CATSG::uint32 iBufferSize);
    virtual HRESULT ReadData(void* oBuffer, const CATSG::uint32 iBufferSize);

    virtual HRESULT WriteInt8(CATSG::int8 iObj);
    virtual HRESULT WriteInt16(CATSG::int16 iObj);
    virtual HRESULT WriteInt32(CATSG::int32 iObj);
    virtual HRESULT WriteUInt8(CATSG::uint8 iObj);
    virtual HRESULT WriteUInt16(CATSG::uint16 iObj);
    virtual HRESULT WriteUInt32(CATSG::uint32 iObj);
    virtual HRESULT WriteFloat(float iObj);
    virtual HRESULT WriteDouble(double iObj);

    virtual HRESULT ReadInt8(CATSG::int8& oObj);
    virtual HRESULT ReadInt16(CATSG::int16& oObj);
    virtual HRESULT ReadInt32(CATSG::int32& oObj);
    virtual HRESULT ReadUInt8(CATSG::uint8& oObj);
    virtual HRESULT ReadUInt16(CATSG::uint16& oObj);
    virtual HRESULT ReadUInt32(CATSG::uint32& oObj);
    virtual HRESULT ReadFloat(float& oObj);
    virtual HRESULT ReadDouble(double& oObj);

    virtual HRESULT FlushBuffer();

private:
    CATBoolean          _lockedOnWrite;
    CATBoolean          _lockedOnRead;
    CATIOBufferPtr      _innerBuffer;
    CATSG::uint32       _innerBufferReservedSize;
    CATSG::uint32       _lastOffset;

private:
    CATSGStreamBuffer(const CATSGStreamBuffer&);
    CATSGStreamBuffer& operator=(const CATSGStreamBuffer&);
};

#endif // SG_COMPOSITES_MULTIOS
#endif // !CATSGStreamBuffer_h_
