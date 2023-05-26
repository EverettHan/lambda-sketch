#include "CATSysWeakRef.h"
#include "CATAssert.h"
#include "CATBaseUnknown.h"
#include "CATSysDicoString.h"
#include "CATIDelegation.h"
#include "CATDelegation.h"
#include "CATCmpGuid.h"
#include "CATOMInitializer.h"   // CATOMInitializerProlog / CATOMInitializerEpilog

// COPYRIGHT DASSAULT SYSTEMES 2002

#ifdef ENVTIECALL
#undef ENVTIECALL
#endif

#define ENVTIECALL(ENVTIEInterface,ENVTIETypeLetter,ENVTIELetter)  ENVTIELetter->

#define CATImplementBOAForDelegation(interfac,extension,precond)                             \
extern "C" Exported IUnknown *						\
		CreateBOA##interfac##extension(CATBaseUnknown *pt,	\
					       CATBaseUnknown *delegue)	\
{                                                                       \
   return(ToCreateBOA(pt,delegue,extension::MetaObject(),IID_##interfac,\
   		      extension::CreateItself));			\
}                                                                       \
                                                                        \
CATOMInitializerProlog(Dico##interfac##extension)\
  CATFillDictionary Dico##interfac##extension			\
			(extension::MetaObject(),interfac::MetaObject(),\
			(void *)CreateBOA##interfac##extension,		\
			(void*)precond,0);\
CATOMInitializerEpilog(Dico##interfac##extension)

#define DelegatingInterface(interfac,DelegatingObject)\
CATDelegatingInterface(interfac,DelegatingObject)

#define CATDelegatingInterface(interfac,DelegatingObject)\
CATDeclareDelegatingInterface(interfac,DelegatingObject);\
CATImplementDelegatingInterface(interfac,DelegatingObject)

#define CATDeclareDelegatingInterface(interfac,DelegatingObject) \
class DelegatingExtension##interfac##DelegatingObject:public interfac\
{\
private:\
	CATDeclareClass;\
 	interfac*m_RealInterface;\
public:\
	static interfac*TheInterface;\
	ENVTIEdeclare_##interfac(DelegatingExtension##interfac##DelegatingObject,interfac,m_RealInterface)\
	DelegatingExtension##interfac##DelegatingObject();\
	virtual ~DelegatingExtension##interfac##DelegatingObject();\
	void*operator new(size_t iSize);\
	void operator delete(void*iPt);\
	virtual CATBaseUnknown* __stdcall GetImpl(int flag=0) const;\
  virtual HRESULT __stdcall QueryInterface(const IID &iIID,void **oPPV); \
  virtual CATBaseUnknown *QueryInterface(CATClassId iInterface) const; \
};

#define CATImplementDelegatingInterface(interfac,DelegatingObject) \
interfac* DelegatingExtension##interfac##DelegatingObject::TheInterface=NULL;\
ENVTIEdefine_##interfac(DelegatingExtension##interfac##DelegatingObject,interfac,m_RealInterface);\
DelegatingExtension##interfac##DelegatingObject::DelegatingExtension##interfac##DelegatingObject()\
{\
	CATAssert(TheInterface!=NULL);\
	m_RealInterface=TheInterface;\
	TheInterface=NULL;\
}\
DelegatingExtension##interfac##DelegatingObject::~DelegatingExtension##interfac##DelegatingObject()\
{\
	CATAssert(m_RealInterface);\
	m_RealInterface->Release();\
	m_RealInterface=NULL;\
	return;\
}\
extern "C" int is##DelegatingObject##interfac ( CATBaseUnknown*TheObject , const IID & iid)\
{\
	static const char* TheDelegatingObject=NULL;\
	if (!TheDelegatingObject)\
	{\
		TheDelegatingObject=CATSysAddStringInDico(#DelegatingObject);\
	}\
	return (CATDelegation::canDelegate(TheDelegatingObject,TheObject,\
					   (CATBaseUnknown**)&(DelegatingExtension##interfac##DelegatingObject::TheInterface),\
					   IID_##interfac)==S_OK);\
}\
CATImplementBOAForDelegation(interfac,DelegatingExtension##interfac##DelegatingObject,is##DelegatingObject##interfac);\
HRESULT DelegatingExtension##interfac##DelegatingObject::QueryInterface(const IID &iIID,void **oPPV) \
{ \
  if ( CATCmpGuid(&iIID,&IID_CATInterfaceOnDelegate) && oPPV) \
  { \
    *oPPV=(void*)m_RealInterface; \
    m_RealInterface->AddRef(); \
    return S_OK; \
  } \
  return interfac::QueryInterface(iIID,oPPV); \
} \
CATBaseUnknown *DelegatingExtension##interfac##DelegatingObject::QueryInterface(CATClassId iInterface) const \
{ \
  return interfac::QueryInterface(iInterface); \
} \
CATBaseUnknown* __stdcall DelegatingExtension##interfac##DelegatingObject::GetImpl(int flag) const\
{\
	return CATBaseUnknown::GetImpl(flag);\
}\
void*DelegatingExtension##interfac##DelegatingObject::operator new(size_t iSize)\
{\
	return malloc(iSize);\
}\
void DelegatingExtension##interfac##DelegatingObject::operator delete(void* iPt)\
{\
	if (iPt)\
		free(iPt);\
}\
CATBeginImplementClass(DelegatingExtension##interfac##DelegatingObject,CacheExtension,interfac,DelegatingObject); \
CATEndImplementClass(DelegatingExtension##interfac##DelegatingObject) 

