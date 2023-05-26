// COPYRIGHT DASSAULT SYSTEMES 1999

#ifndef CATIObjectPathListImpl_h
#define CATIObjectPathListImpl_h

#include "CATVisController.h"

#include <CATIObjectPathList.h>
#include <CATListOfCATIObjectPath.h>

class ExportedByCATVisController CATIObjectPathListImpl : public CATIObjectPathList
{
public:
  
  CATIObjectPathListImpl();
  CATIObjectPathListImpl(const CATLISTP(CATIObjectPath) & iList);
  ~CATIObjectPathListImpl();
  
  // IUnknown
  ULONG __stdcall AddRef();
  ULONG __stdcall Release();
  HRESULT __stdcall QueryInterface(const IID & iid, void ** ppv);
  
  // CATIObjectPathList
  HRESULT Count(unsigned int * oCount) const;
  HRESULT Item(const unsigned int iPosition, CATIObjectPath ** oItem) const;
  HRESULT Add(const unsigned int iPosition, CATIObjectPath * iItem);
  HRESULT Remove(CATIObjectPath * iItem);
  
private:
  
  ULONG m_cRef;
  CATLISTP(CATIObjectPath) _list;
};

#endif
