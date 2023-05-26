#ifndef CATVisPublisher_H
#define CATVisPublisher_H

// COPYRIGHT DASSAULT SYSTEMES 2004

#include "SGInfra.h"
#include <string.h>
#include "CATErrorDef.h"

class CATRep;
class CATBaseUnknown;
class ExportedBySGInfra CATVisPublisher
{
public:
	
	CATVisPublisher(){};
	virtual ~CATVisPublisher(){};
	
	// retourne E_FAIL si le publisher ne connait pas le nouveau type a traiter
	// retourne S_OK sinon
	virtual HRESULT BeginPublish(const char* iType) = 0;
	virtual void EndPublish(char* iType) = 0;
	
	virtual void PublishState(const char* iStateName, int iInt) = 0;
	virtual void PublishState(const char* iStateName, const int* iInt, unsigned int iNum) = 0;
    virtual void PublishState(const char* iStateName, const unsigned char* iUChar, unsigned int iNum) = 0;
	
	virtual void PublishObject(const char* iStateName, void* iObj) = 0;
	
protected:
	inline int IsEqual(const char* name, const char* name2);

private:
	CATVisPublisher( const CATVisPublisher&);
};

inline int CATVisPublisher::IsEqual(const char* name, const char* name2)
{
	if (!name) return 0;
	if (!name2) return 0;
	if (strlen(name)==0) return 0;
	if (strlen(name2)==0) return 0;

	if (!strcmp(name, name2)) return 1;

	return  0;
}

#endif // CATVisPublisher_H
