#ifndef CATComSidlOutputStreamCommon_H
#define CATComSidlOutputStreamCommon_H
#include "CATComSidl.h"

#include "CATBaseUnknown.h"
#include "CATComSidlOutputStream.h"

class ExportedByCATComSidl CATComSidlOutputStreamCommon : public CATComSidlOutputStream
{
	CATDeclareClass;
	
public :
	CATComSidlOutputStreamCommon(char **oRetour,int *oRetourSize);
	~CATComSidlOutputStreamCommon();
	virtual HRESULT BeginStream();
	virtual HRESULT EndStream();
	virtual HRESULT WriteBinary(const char * iSrc , int iLen);

private:
	int _Open;
	int _OpenOnce;
	int _Pos;
	int _Allocated;
	char* _Buffer;
  //Le buffer de sortie donne a la creation et renseigne a la fermeture
	char** _OutputArray;
  int* _OutputArraySize;

};

#endif
