/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2000
/** 
 * @level Protected 
 * @usage U1
*/
//**********************************************************************
//* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS *
//* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME *
//**********************************************************************

#ifndef CAT_MAC_FOR_INTERFACE_H
#define CAT_MAC_FOR_INTERFACE_H

#include "CATBaseUnknown.h"

#ifndef CATDeclareLateTyping

#ifndef CATMetaClassStaticCheck
#define CATMetaClassStaticCheck
#endif

#define CATDeclareLateTyping \
  CATMetaClassStaticCheck \
  public: \
    static CATMetaClass* MetaObject(); \
    static CATClassId	ClassName(); \
    static CATBaseUnknown* CreateItself()

#ifdef IsCodeExtensionImplementation
#define OMY_IsCodeExtensionImplementation(c,t) IsCodeExtensionImplementation(c,t)
#else
#define OMY_IsCodeExtensionImplementation(c,t) 
#endif

#define CATImplementLateTyping( Class, Typeofclass, Basemeta, Impmeta ) \
  OMY_IsCodeExtensionImplementation(Class, Typeofclass) \
  CATMetaClass* Class::MetaObject() \
  { \
    ExportedByJS0CORBA CATMetaClass *fct_RetrieveMetaObject(const char *,TypeOfClass, CATMetaClass *, const char *, const char *,long); \
    static CATMetaClass* sMetaObject = fct_RetrieveMetaObject(#Class,Typeofclass,Basemeta::MetaObject(),#Impmeta,CATLicenseOptionId,sizeof(Class)); \
    return sMetaObject; \
  } \
  CATClassId Class::ClassName()	{return MetaObject()->IsA();} \
  CATBaseUnknown* Class::CreateItself() {return NULL;}
                                       

#endif
#endif
