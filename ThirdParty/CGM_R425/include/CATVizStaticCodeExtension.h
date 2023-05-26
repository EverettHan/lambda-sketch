/*
* @quickReview PTO 20220311 R424AssessedForLinux CTF_ENTRYPOINT
*/
#ifndef CATVizStaticCodeExtension_H_
#define CATVizStaticCodeExtension_H_

#include <memory>

#include "CATAssert.h"
#include "SGInfra.h"
#include "CATVisBaseEnv.h"
#include "CATBaseUnknown.h"
#include "DSYSysAtomic.h"
#include "CATUnicodeString.h"
#include "CATQueryDictionary.h"
#include "CATGetEntryPoint.h"
#include "CATLib.h"

/**
*  Services used to create thread-safe code extension without object modeler.
*  NB : GetImpl won't return anything !
*  It still relies on Rtti information contained in CATBaseUnknown.
*
*  In Object modeler terms, it's used to provide an object implementing "Interface" for a class "Implementation"
*
*  CATBaseUnknown
*  /\      |\
*  ||      |_\
*  ||        \\
*  ||         \\
*  ||           Interface
*  ||                |\
*  ||                |_\
*  ||                  \\
*  ||                   \\
*  ||                    \\
*  Implementation <---> InterfaceImplementation
*
*/

/**
*  Object acting like a cache to store the code extension instance for a specific class.
*  It has to be put in the class's cpp file with the macro CATVizStaticCodeExtensionGetter
*/

// Note: in the current usages, 'Interface' is always 'vIDrawable' and 'Impl' is a rep type.
// This is used to associate classes like 'vImplDrawable_CATSurfacicRep' to 'CATSurfacicRep'. For instance,
// when we have a 'CATSurfacicRep', we can retrieve the single instance 'vImplDrawable_CATSurfacicRep'.

class ExportedBySGInfra CATVizStaticCodeExtensionBase
{
public:
  CATVizStaticCodeExtensionBase(char const* iImplName, char const* iItfName)
    : m_ImplName(iImplName),
      m_ItfName(iItfName)
  {
  }

  virtual ~CATVizStaticCodeExtensionBase()
  {
    m_ImplName = NULL;
    m_ItfName = NULL;    
  }

protected:
  const char* m_ImplName;
  const char* m_ItfName;
};


class ExportedBySGInfra CATVizStaticCodeExtensionDictionary
{
public:
  template <class Interface>
  static std::shared_ptr<Interface> GetStaticCodeExtension(CATBaseUnknown const* iObject);

  static void RegisterStaticCodeExtension(std::shared_ptr<CATVizStaticCodeExtensionBase> iClass,
                                          CATMetaClass const* iImplMeta,
                                          CATMetaClass const* iItfMeta);
  
  static std::shared_ptr<CATVizStaticCodeExtensionBase> UnregisterStaticCodeExtension(CATMetaClass const* iImplMeta, CATMetaClass const* iItfMeta);

private:
  static std::shared_ptr<CATVizStaticCodeExtensionBase> GetStaticCodeExtension(CATMetaClass const* iImplMeta, CATMetaClass const* iItfMeta);
};


template <class Interface>
class CATVizStaticCodeExtension : public CATVizStaticCodeExtensionBase
{
  using ItfImplFactory = Interface*(*)();
   
public:
  CATVizStaticCodeExtension(char const* iImplName, char const* iItfName)
    : CATVizStaticCodeExtensionBase(iImplName, iItfName),
      m_ItfImpl(NULL)
  {
  }

  virtual ~CATVizStaticCodeExtension()
  {
  }

  std::shared_ptr<Interface> GetItf()
  {    
    if (m_ItfImpl != NULL)
      return m_ItfImpl;
    
    const char* libName = NULL;
    HRESULT hr = E_FAIL;
    hr = CATSysGetLibNameFromCtlg(m_ImplName, m_ItfName, libName);
    if (!SUCCEEDED(hr))
    {
      CATAssert(false);
      return nullptr;
    }
    
    CATUnicodeString strFactory("Retrieve");
    strFactory.Append(m_ItfName);
    strFactory.Append("For");
    strFactory.Append(m_ImplName);

    if (CATVisBaseEnv::IsCATVisNoGraphicalAPI())
    {
      CATUnicodeString libTemp1(libName);
      CATUnicodeString libTemp2 = libTemp1.SubString(0, 8);
      if (libTemp2 == "libVisRE")
      {
        return NULL;
      }
    }

    LibraryHandler handler = CATGetEntryPoint(libName, strFactory.CastToCharPtr());

    ItfImplFactory factory = (ItfImplFactory)handler.EntryPoint;
    if (factory != NULL)
    {
      Interface* localInterfacePtr = factory();
          
      std::shared_ptr<Interface> localItf;
      localItf.reset(localInterfacePtr);
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4996)
#endif          
      // If the following fails, this means that another thread has just set 'm_ItfImpl'
      // concurrently. We can then discard 'localItf' when it goes out of scope.
      // If this is successful, then 'm_ItfImpl' will take the value of 'localItf'.          
           std::shared_ptr<Interface> nullInterfacePtr;          
      std::atomic_compare_exchange_strong(&m_ItfImpl, &nullInterfacePtr, localItf);
  #ifdef _MSC_VER
#pragma warning(pop)
#endif
    }
    
    return m_ItfImpl;
  }

private:
  std::shared_ptr<Interface> m_ItfImpl;
};



template <class Implementation, class Interface>
class CATVizStaticCodeExtensionWrapper
{
public:
   CATVizStaticCodeExtensionWrapper(char const* iImplName, char const* iItfName)
      : m_CodeExtension(std::make_shared<CATVizStaticCodeExtension<Interface>>(iImplName, iItfName))
   {
      CATVizStaticCodeExtensionDictionary::RegisterStaticCodeExtension(m_CodeExtension,
                                                                       Implementation::MetaObject(),
                                                                       Interface::MetaObject());
   }

   std::shared_ptr<Interface> GetItf()
   {
      return m_CodeExtension->GetItf();
   }

private:
   std::shared_ptr<CATVizStaticCodeExtension<Interface>> m_CodeExtension;
};


template <class Interface>
std::shared_ptr<Interface> CATVizStaticCodeExtensionDictionary::GetStaticCodeExtension(CATBaseUnknown const* iObject)
{
   if (iObject == nullptr)
      return nullptr;

   auto baseCodeExtension = GetStaticCodeExtension(iObject->GetMetaObject(), Interface::MetaObject());
     
   if (baseCodeExtension != nullptr)
   {
      auto* codeExtension = static_cast<CATVizStaticCodeExtension<Interface>*>(baseCodeExtension.get());      
      return codeExtension->GetItf();
   }
   else
      return nullptr;
}



/**
*  Helper function to retrieve the interface instance.
*/
template <class Interface>
inline std::shared_ptr<Interface> CATVizGetStaticCodeExtension(CATBaseUnknown* iObj)
{
  return CATVizStaticCodeExtensionDictionary::GetStaticCodeExtension<Interface>(iObj);
}


template <class Interface>
inline std::shared_ptr<Interface> CATVizGetStaticCodeExtension(const CATBaseUnknown* iObj)
{
  return CATVizStaticCodeExtensionDictionary::GetStaticCodeExtension<Interface>(iObj);
}


/**
*  Macro used to retrieve the Interface instance int he Implementation's translation unit.
*  It does not go through the hash table to lookup the interface.
*/
#define CATVizGetStaticCodeExtension_InTU(Implementation, Interface) \
 s_LocalCodeExtensionFor##Interface##On##Implementation.GetItf();

#define CATVizStaticCodeExtensionGetter(Implementation, Interface) CATVizStaticCodeExtensionWrapper<Implementation, Interface> s_LocalCodeExtensionFor##Interface##On##Implementation(#Implementation, #Interface);


// Defines the function called by 'CATVizStaticCodeExtension::GetItf'.

#define CATVizImplementStaticCodeExtension(Impl, Interface, InterfaceOnImpl, ExportDef) \
extern "C"                                                                              \
{                                                                                       \
  ExportDef Interface* Retrieve##Interface##For##Impl()                 \
  {                                                                                     \
     return new InterfaceOnImpl();                                      \
  }                                                                     \
}

#endif
