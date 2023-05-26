#ifndef CATVISMACROFORPROTECTEDINTERFACES_H
#define CATVISMACROFORPROTECTEDINTERFACES_H

// COPYRIGHT DASSAULT SYSTEMES 2008

#include "CATVizAllocator.h"

// permanent interfaces
class IVisSGObject;

#define CATVisImplementPublicInterfaceAdhesion(iClass, iInterface, iBOAExtension) \
void *iClass::operator new(size_t iSize)                                          \
{                                                                                 \
  size_t realSize = iSize + sizeof(iBOAExtension);                                \
  char *adress = (char *)CATVizAllocator::PermanentAllocate(realSize);            \
  iBOAExtension *boa = new  (adress) iBOAExtension();                             \
  return adress + sizeof(iBOAExtension);                                          \
}                                                                                 \
void iClass::operator delete(void *iObject)                                       \
{                                                                                 \
  char *realAdress = (char*)iObject - sizeof(iBOAExtension);                      \
  iBOAExtension* boa = (iBOAExtension*)realAdress;                                \
  delete boa;                                                                     \
  CATVizAllocator::PermanentDeallocate(realAdress);                               \
}                                                                                 \
IVisSGObject *iClass::GetInterface() const                                        \
{                                                                                 \
  return (IVisSGObject *)((char *)this - sizeof(iBOAExtension));                  \
}                                                                                 \


#define CATVisDeclarePublicInterfaceImplementation(iClass, iInterface, iBOAExtension) \
void* operator new(size_t,void *);                                                    \
void operator  delete(void* iAddr);                                                   \
virtual void *GetImplementation() const;                                              \
virtual iClass & GetConcreteImplementation() const;                                   \
virtual HRESULT __stdcall QueryInterface(const IID &iIID, void **oPPV);               \
virtual ULONG __stdcall AddRef();                                                     \
virtual ULONG __stdcall Release();                                                    \

#define CATVisImplementPublicInterfaceImplementation(iClass, iInterface, iBOAExtension) \
void *iBOAExtension::operator new(size_t,void *adress)                                  \
{                                                                                       \
  return adress;                                                                        \
}                                                                                       \
void iBOAExtension::operator delete(void *adress)                                       \
{                                                                                       \
}                                                                                       \
iClass & iBOAExtension::GetConcreteImplementation() const                               \
{                                                                                       \
  return *(iClass *)((char *)this + sizeof(iBOAExtension));                             \
}                                                                                       \
void *iBOAExtension::GetImplementation() const                                          \
{                                                                                       \
  return &GetConcreteImplementation();                                                  \
}                                                                                       \
HRESULT __stdcall iBOAExtension::QueryInterface(const IID &iIID, void **oPPV)           \
{                                                                                       \
  return GetConcreteImplementation().QueryInterface(iIID,oPPV);                         \
}                                                                                       \

/*
ULONG __stdcall iBOAExtension::AddRef( void)                                            \
{                                                                                       \
  return GetConcreteImplementation().AddRef();                                          \
}                                                                                       \
ULONG __stdcall iBOAExtension::Release( void)                                           \
{                                                                                       \
  return GetConcreteImplementation().Release();                                         \
}                                                                                       \
*/

// transient interfaces

#define CATVisDeclarePublicTransientInterfaceAdhesion(iClass, iInterface, iTransientExtension)  \
iInterface* GetInterface() const;                                                               \

#define CATVisImplementPublicTransientInterfaceAdhesion(iClass, iInterface, iTransientExtension)  \                                                                     \
iInterface *iClass::GetInterface() const                                                          \
{                                                                                                 \
  return new iTransientExtension(this);                                                           \
}                                                                                                 \

#endif // CATVISMACROFORPROTECTEDINTERFACES_H
