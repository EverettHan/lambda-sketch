#ifndef CATComSidlInputPacketStreamCommon_H
#define CATComSidlInputPacketStreamCommon_H

#include "CATComSidl.h"
#include "CATBaseUnknown.h"
#include "CATComSidlInputStream.h"
#include "CATComSidlTabPacket.h"


class ExportedByCATComSidl CATComSidlInputPacketStreamCommon : public CATComSidlInputStream
{
	CATDeclareClass;
	
public :
	CATComSidlInputPacketStreamCommon(CATComSidlTabPacket*TabPacket);
	virtual ~CATComSidlInputPacketStreamCommon();
	virtual int IsOpen();
	virtual HRESULT BeginStream();
	virtual int  GetAvailableBytes();
	virtual HRESULT ReadBinary(char* Buffer, unsigned int Size, unsigned int * oLengthRead = NULL);
	virtual HRESULT EndStream();

private :
	CATComSidlTabPacket* _TabPacket;
	int _Open;
	int _OpenOnce;
};

#endif
