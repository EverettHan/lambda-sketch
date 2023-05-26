#ifndef CATComSidlOutputPacketStreamCommon_H
#define CATComSidlOutputPacketStreamCommon_H

#include "CATComSidl.h"
#include "CATBaseUnknown.h"
#include "CATComSidlOutputStream.h"
#include "CATComSidlTabPacket.h"

class ExportedByCATComSidl CATComSidlOutputPacketStreamCommon : public CATComSidlOutputStream
{
	CATDeclareClass;
	
public :
	CATComSidlOutputPacketStreamCommon(CATComSidlTabPacket * _TabPacket,int MaxPacketSize);
	virtual ~CATComSidlOutputPacketStreamCommon();
	virtual int IsOpen();
	virtual HRESULT BeginStream();
	virtual HRESULT EndStream();
	virtual HRESULT WriteBinary(const char * iSrc , int iLen);

private:
	CATComSidlTabPacket * _TabPacket;
	int _Open;
	int _OpenOnce;
	int _Pos;
	int _Allocated;
	char* _Buffer;
  int _MaxPacketSize;
};

#endif
