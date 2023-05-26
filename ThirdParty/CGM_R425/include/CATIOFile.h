#ifndef CATIOFile_H
#define CATIOFile_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS

#include "SGComposites.h"
#include "CATUnicodeString.h"
#include "DSYSysStdIO.h"
#include "CATIOBuffer.h"

class ExportedBySGComposites CATIOFile
{
public:
	CATIOFile();
	~CATIOFile();

	HRESULT Open(const CATUnicodeString& iFilePath, const char* iMode);
	HRESULT Flush();
	HRESULT Close();

    HRESULT GetSize(unsigned int& oFileSize);
    HRESULT Tell(unsigned int& oOffset);
	HRESULT Seek(unsigned int iOffsetWithin);
	HRESULT Append(void* iSrcBuffer, unsigned int iBufferSize, unsigned int& oOffset);
	HRESULT Retrieve(void* iDstBuffer, unsigned int iBufferSize, unsigned int& oReadSize);
	HRESULT ReadAll(CATIOBufferPtr& ioBuffer);

private:
	DSYSysFileDescriptor _fd;
};
#endif // SG_COMPOSITES_MULTIOS
#endif // CATIOFile_H

