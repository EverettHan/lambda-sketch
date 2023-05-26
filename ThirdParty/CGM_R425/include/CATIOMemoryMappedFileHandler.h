#ifndef CATIOMemoryMappedFileHandler_H
#define CATIOMemoryMappedFileHandler_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS

#include "CATIOProtocolHandler.h"
#include "CATIOMemoryMappedFile.h"
#include "CATIOManager.h"
#include "CATIOAtomics.h"

#include <unordered_map>

// std::map[filePath, mappedFile]
typedef std::unordered_map<CATUnicodeString, CATIOMemoryMappedFile*, Hash<CATUnicodeString>> CATIOMappedFiles;
class ExportedBySGComposites CATIOMemoryMappedFileHandler : public CATSGCompositeHost1<CATIOProtocolHandler, CATSGComposite>
{
public:
    CATIOMemoryMappedFileHandler(CATIOManagerWeakPtr iIOManager);
    ~CATIOMemoryMappedFileHandler();

    virtual unsigned int        GetSizeInBytes(const int iIncludeStructuralSize = 1);

    virtual CATIOUri            Save(CATIOBufferPtr iIOBuffer, CATIOUri iUri);
    virtual CATIOUri            Append(CATIOBufferPtr iIOBuffer, CATIOUri iUri);
    virtual CATIOBufferPtr      Load(const CATIOUri iUri);

    virtual CATIOUri            ProtocolPrefix();
private:
    CATIOMappedFiles            _mappedFiles;
    CATIOManagerWeakPtr         _ioManager;
    CATIOAtomicLock             _atomicLock;
};

#endif // SG_COMPOSITES_MULTIOS
#endif // CATIOMemoryMappedFileHandler_H
