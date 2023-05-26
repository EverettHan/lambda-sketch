#if defined(_IOS_SOURCE)

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATMetaClass.h"
#include "CATMacForIUnknown.h"
#include "CATBaseUnknown.h"
#include "TIE_IClassFactory.h"
#include "CATUuid.h"
#include "CATErrorDef.h"

#define CATClassObject(object) \
class ClassObject##object:public CATBaseUnknown \
{ \
	CATDeclareClass; \
  virtual HRESULT CreateInstance(IUnknown * iUnkOuter, const IID &iIid, void ** oObject); \
  virtual HRESULT LockServer(BOOL iLock); \
}; \
 \
TIE_IClassFactory(ClassObject##object); \
 \
CATImplementClass(ClassObject##object,Implementation,CATNull,CatNull); \
 \
HRESULT ClassObject##object::LockServer(BOOL iLock) {return S_OK;} \
 \
HRESULT ClassObject##object::CreateInstance(IUnknown * iUnkOuter, const IID &iIid, void ** oObject) \
{ \
	if (iUnkOuter != NULL) { \
		return CLASS_E_NOAGGREGATION; \
	} \
	object * p##object = new object(); \
	HRESULT hr = p##object->QueryInterface(iIid, oObject); \
	p##object->Release(); \
	return hr; \
}

#define CATClassObject_Exported DSYExport
#include "DSYExport.h"

#define CATBeginClassObject \

	
#define CATAddClassObject(object) \
extern "C" HRESULT CATClassObject_Exported CATDllGetClassObject##object(const CLSID & rclsid,    const IID & riid, void ** ppv) \
{						\
  HRESULT hr = E_NOTIMPL;			\
  if (CATCmpGuid(&rclsid, &CLSID_##object))	\
    {						\
      ClassObject##object * pClassObject##object = new ClassObject##object; \
      hr = pClassObject##object->QueryInterface(riid, ppv);		\
      pClassObject##object->Release();					\
      return hr;							\
    }						\
  return hr;					\
}

	
#define CATAddClassObjectWithName(object,name) \
extern "C" HRESULT CATClassObject_Exported CATDllGetClassObject##object(const CLSID & rclsid,    const IID & riid, void ** ppv)    \
{						\
  HRESULT hr = E_NOTIMPL;			\
  if (CATCmpGuid(&rclsid, &CLSID_##name))	\
    {									\
      ClassObject##object * pClassObject##object = new ClassObject##object; \
      hr = pClassObject##object->QueryInterface(riid, ppv);		\
      pClassObject##object->Release();					\
      return hr;							\
    }  						\
  return hr;					\
}

#define CATEndClassObject 

#else // _IOS_SOURCE

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATMetaClass.h"
#include "CATMacForIUnknown.h"
#include "CATBaseUnknown.h"
#include "TIE_IClassFactory.h"
#include "CATUuid.h"
#include "CATErrorDef.h"

#define CATClassObject(object) \
class ClassObject##object:public CATBaseUnknown \
{ \
	CATDeclareClass; \
  virtual HRESULT CreateInstance(IUnknown * iUnkOuter, const IID &iIid, void ** oObject); \
  virtual HRESULT LockServer(BOOL iLock); \
}; \
 \
TIE_IClassFactory(ClassObject##object); \
 \
CATImplementClass(ClassObject##object,Implementation,CATNull,CatNull); \
 \
HRESULT ClassObject##object::LockServer(BOOL iLock) {return S_OK;} \
 \
HRESULT ClassObject##object::CreateInstance(IUnknown * iUnkOuter, const IID &iIid, void ** oObject) \
{ \
	if (iUnkOuter != NULL) { \
		return CLASS_E_NOAGGREGATION; \
	} \
	object * p##object = new object(); \
	HRESULT hr = p##object->QueryInterface(iIid, oObject); \
	p##object->Release(); \
	return hr; \
}

#define CATClassObject_Exported DSYExport
#include "DSYExport.h"

#define CATBeginClassObject \
 \
extern "C" HRESULT CATClassObject_Exported CATDllGetClassObject(const CLSID & rclsid,    const IID & riid, void ** ppv) \
{ \
	HRESULT hr = E_NOTIMPL;
	
#define CATAddClassObject(object) \
	if (CATCmpGuid(&rclsid, &CLSID_##object)) \
	{ \
		ClassObject##object * pClassObject##object = new ClassObject##object; \
		hr = pClassObject##object->QueryInterface(riid, ppv); \
		pClassObject##object->Release(); \
		return hr; \
	}
	
#define CATAddClassObjectWithName(object,name) \
	if (CATCmpGuid(&rclsid, &CLSID_##name)) \
	{ \
		ClassObject##object * pClassObject##object = new ClassObject##object; \
		hr = pClassObject##object->QueryInterface(riid, ppv); \
		pClassObject##object->Release(); \
		return hr; \
	}

#define CATEndClassObject \
	return hr; \
}
#endif 
