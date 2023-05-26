// COPYRIGHT DASSAULT SYSTEMES 2002
//=============================================================================
//
// CATVizBaseCodeExtension
//
//=============================================================================
// Usage Notes:
//	Class for Visualization Protocol Extension
//
//=============================================================================
// Created :
//	November, 22th 2002 :	JQT
//=============================================================================

#ifndef CATVizBaseCodeExtension_H
#define CATVizBaseCodeExtension_H

#include "SGInfra.h"
#include "CATVizBaseIUnknown.h"
#include "CATVizBaseCodeExtensionID.h"

#include <atomic>

class ExportedBySGInfra CATVizBaseCodeExtension : public CATVizBaseIUnknown
{
  CATDeclareClass_Deprec;

  public:

    CATVizBaseCodeExtension();
    virtual ~CATVizBaseCodeExtension();

    static CATVizBaseCodeExtension* GetExt(const CATVizBaseCodeExtensionID* iProtocolID, const char* iImplID);
    static CATVizBaseCodeExtension* GetExt(const CATVizBaseCodeExtensionID* iProtocolID, CATVizBaseIUnknown* iVizObject);

    // To delete
    static CATVizBaseCodeExtension* GetExt(const CATVizBaseCodeExtensionID* iProtocolID, CATBaseUnknown* iVizObject);

    void* GetImpl();

    virtual CATVizBaseCodeExtensionID* GetID() = 0;

    virtual ULONG __stdcall Release();

    static int  GetCodeExtensionUseMultiPro();
    /**
    * Call with +1 to increase count.
    * Call with -1 to decrease count.
    * When count is == 0, mutex is not active.
    * When count is > 0, mutex is active.
    */
    static void IncrementUseMultiPro(int iAddedValue);

    static void EnableDictionnary(CATBoolean iEnable=TRUE);

  protected:

    CATVizBaseCodeExtension(const CATVizBaseCodeExtension&);
    void operator=(const CATVizBaseCodeExtension&);

    static CATVizBaseCodeExtension* GetExt(const CATVizBaseCodeExtensionID* iProtocolID, const char* iImplID, CATVizBaseIUnknown* iVizObject);

    // To delete
    static CATVizBaseCodeExtension* GetExt(const CATVizBaseCodeExtensionID* iProtocolID, const char* iImplID, CATBaseUnknown* iVizObject);

    void SetImpl(void* iptr);

    void *_impl;

    static std::atomic<int> _CodeExtensionUseMultiPro;
    static CATBoolean _UseDictionnary;
};

//***************************************************************************************************
// Macros for Protocol definition
//***************************************************************************************************
#define  CATVizDeclareProtocol(ClassName)                                       \
  public :                                                                      \
    virtual CATVizBaseCodeExtensionID* GetID();                                 \
    static  CATVizBaseCodeExtensionID* ClassID() { return &_##ClassName##ID; }; \
  private:                                                                      \
    static CATVizBaseCodeExtensionID _##ClassName##ID



#define  CATVizImplementProtocol(ClassName)                                           \
CATVizBaseCodeExtensionID  ClassName::_##ClassName##ID(NULL, NULL, #ClassName, NULL); \
CATVizBaseCodeExtensionID* ClassName::GetID()                                         \
{ return &_##ClassName##ID; }                                                         \


//***************************************************************************************************
// Macros for Protocol implementation
//***************************************************************************************************
#define  CATVizDeclareExtension(ClassName,Implement,ForProtocol)                \
  public :                                                                      \
    static  ClassName* Create();                                                \
    virtual CATVizBaseCodeExtensionID* GetID();                                 \
    static  CATVizBaseCodeExtensionID* ClassID() { return &_##ClassName##ID; }; \
  private :                                                                     \
    static  CATVizBaseCodeExtensionID _##ClassName##ID



#define  CATVizImplementExtension(ClassName,Implement,ForProtocol)                                                                                  \
ClassName* ClassName::Create() {return new ClassName;};                                                                                             \
CATVizBaseCodeExtensionID ClassName::_##ClassName##ID(#ClassName, #Implement, #ForProtocol, (CATVizBaseCodeExtensionCreator) &ClassName::Create );  \
CATVizBaseCodeExtensionID* ClassName::GetID()                                                                                                       \
{ return &_##ClassName##ID; }                                                                                                                       \

#endif
