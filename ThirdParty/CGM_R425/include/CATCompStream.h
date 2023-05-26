#ifndef CATCompStream_H
#define CATCompStream_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "CATSGCompositeHost.h"
#include "CATCompositeTPtr.h"
#include "CATCompositePtrList.h"
#include "CATIOBuffer.h"

class CATCompStream;
typedef CATCompositeTWeakPtr<CATCompStream> CATCompStreamWeakPtr;
typedef CATCompositeTPtr<CATCompStream>     CATCompStreamPtr;
typedef std::vector<CATCompStreamPtr>       CATCompStreams;
typedef CATOnStackBorrowPtr<CATCompStream>  CATCompStreamBorrowPtr;

class ExportedBySGComposites CATCompStream : public CATSGComposite
{
public:
    virtual CATBoolean IsLockedOnWrite() const = 0;
    virtual CATBoolean IsLockedOnRead() const = 0;
    virtual HRESULT SetWriteLock(CATBoolean iLocked) = 0;
    virtual HRESULT SetReadLock(CATBoolean iLocked) = 0;

    virtual HRESULT DumpAsBuffer(CATIOBufferPtr& oOutputBuffer) = 0;
    virtual HRESULT DumpIntoStream(CATCompStreamPtr& iOtherStream, CATSG::uint32& oDumpedLength) = 0;
    virtual CATSG::uint32 GetLength() = 0;
    virtual HRESULT SetLength(const CATSG::uint32 iLength) = 0;
    virtual CATSG::uint32 GetCurrentPosition() const = 0;
    virtual HRESULT SetCurrentPosition(const CATSG::uint32 iNewPos) = 0;
    /**
     * Warning: By default, this will compute the checksum from the current position to the end of the stream.
     * If you want to, you can use the iMaxLength argument and the SetCurrentPosition method to compute on a
     * specific part of the stream.
     */
    virtual CATSG::uint32 ComputeChecksum(CATSG::uint32 iMaxLength = 0) = 0;

    virtual HRESULT WriteGUID(const GUID& iObj) = 0;
    virtual HRESULT ReadGUID(GUID& oObj) = 0;

    virtual HRESULT WriteRef(const CATSGRef& iObj) = 0;
    virtual HRESULT ReadRef(CATSGRef& oObj) = 0;

    virtual HRESULT WriteData(const void* iBuffer, const CATSG::uint32 iBufferSize) = 0;
    virtual HRESULT ReadData(void* oBuffer, const CATSG::uint32 iBufferSize) = 0;

    virtual HRESULT WriteInt8(CATSG::int8 iObj) = 0;
    virtual HRESULT WriteInt16(CATSG::int16 iObj) = 0;
    virtual HRESULT WriteInt32(CATSG::int32 iObj) = 0;
    virtual HRESULT WriteUInt8(CATSG::uint8 iObj) = 0;
    virtual HRESULT WriteUInt16(CATSG::uint16 iObj) = 0;
    virtual HRESULT WriteUInt32(CATSG::uint32 iObj) = 0;
    virtual HRESULT WriteFloat(float iObj) = 0;
    virtual HRESULT WriteDouble(double iObj) = 0;

    virtual HRESULT ReadInt8(CATSG::int8& oObj) = 0;
    virtual HRESULT ReadInt16(CATSG::int16& oObj) = 0;
    virtual HRESULT ReadInt32(CATSG::int32& oObj) = 0;
    virtual HRESULT ReadUInt8(CATSG::uint8& oObj) = 0;
    virtual HRESULT ReadUInt16(CATSG::uint16& oObj) = 0;
    virtual HRESULT ReadUInt32(CATSG::uint32& oObj) = 0;
    virtual HRESULT ReadFloat(float& oObj) = 0;
    virtual HRESULT ReadDouble(double& oObj) = 0;

    virtual HRESULT FlushBuffer() = 0;
};

// {2AE5AE07-D137-4535-BAB7-5574225E0A4C}
static const IID GUID_CATCompStreamTrait =
{ 0x2ae5ae07, 0xd137, 0x4535, { 0xba, 0xb7, 0x55, 0x74, 0x22, 0x5e, 0xa, 0x4c } };


template<>
class CATTraitInfo<CATCompStream>
{
public:
    static const GUID&               GetTraitGUID()
    {
        return GUID_CATCompStreamTrait;
    }
    static const int                 GetTraitTag() {
        return CATTraitTag(-1);
    }
    static const CATECompositionMode GetCompositeMode()
    {
        return CATECompositionModeExclusive;
    }
    static const CATTraitRawInfo     GetRaw()
    {
        DefaultGetRawImplementation;
    }
};

#endif // SG_COMPOSITES_MULTIOS
#endif // CATCompStream_H
