#ifndef CATIOBufferDefaultImpl_H
#define CATIOBufferDefaultImpl_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS

#include "CATCompositeTPtr.h"
#include "CATSGComposite.h"
#include "CATSGCompositeHost.h"
#include "CATIOBuffer.h"

#include "CATMutex.h"

#include "VisGPGPUTypes.h" // for alignment directives (needed for atomic operaitions)
#include "CATIOAtomics.h"

class CATIOBufferDefaultImpl : public CATSGCompositeHost1<CATIOBuffer, CATSGComposite>
{
public:
	CATIOBufferDefaultImpl();
	~CATIOBufferDefaultImpl();

	virtual unsigned int GetSizeInBytes(const int iIncludeStructuralSize = 1);
	
	virtual HRESULT 		Reserve(const unsigned int iSize);

	virtual HRESULT 		SetSize(const unsigned int iSize);
	virtual unsigned int 	GetSize();
	virtual void*			AsVoid();

    //ownership of iBuffer is taken and it has to be allocated by malloc (NOT by new) before the call  
	virtual HRESULT 		SetInPlace(void* iBuffer, const unsigned int iBufferSize);
	virtual HRESULT 		Append(const void* iBuffer, const unsigned int iBufferSize);
	virtual HRESULT			RemoveSlice(const unsigned iAt, const unsigned iSize);
	virtual HRESULT 		Dump(void* ioBuffer, const unsigned int iBufferSize, unsigned int& oDumpedSize);
private:
	void* 			_buffer;
	unsigned int 	_currentSize;
	unsigned int 	_reservedSize;
};

#endif // SG_COMPOSITES_MULTIOS
#endif // CATIOBuffer_H
