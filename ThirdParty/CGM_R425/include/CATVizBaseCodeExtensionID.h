// COPYRIGHT DASSAULT SYSTEMES 2002
//=============================================================================
//
// CATVizBaseCodeExtensionID
// 
//=============================================================================
// Usage Notes:
//	Base Class for Visualization Protocol Extension IDs
// 
//=============================================================================
// Created :
//	November, 22th 2002 :	JQT
//=============================================================================

#ifndef CATVizBaseCodeExtensionID_H
#define CATVizBaseCodeExtensionID_H

#include "SGInfra.h"
#include "CATVizBaseIUnknown.h"

class CATVizBaseCodeExtension;

typedef  CATVizBaseCodeExtension * (*CATVizBaseCodeExtensionCreator)();

#ifndef NULL
#define NULL 0L
#endif

class ExportedBySGInfra CATVizBaseCodeExtensionID : public CATVizBaseIUnknown
{
  CATDeclareClass_Deprec;

  public:

    CATVizBaseCodeExtensionID(  const char* iClassName,
                                const char* iImplClassName,
                                const char* iProtocolName,
                                CATVizBaseCodeExtensionCreator iCreaFunc);
    virtual ~CATVizBaseCodeExtensionID();

    CATVizBaseCodeExtension* GetInstance();
    void ResetInstance(CATVizBaseCodeExtension*);

    const char* GetClassId() const;
    const char* GetImplId() const;
    const char* GetProtocolId() const;

    static CATVizBaseCodeExtensionID* RetrieveID(const char* iImplName, const char* iProtocolName);

  private:

    CATVizBaseCodeExtensionID(const CATVizBaseCodeExtensionID&);
    CATVizBaseCodeExtensionID& operator=(const CATVizBaseCodeExtensionID&);

    class CATVizBaseCodeExtensionIDChain
    {
    public:
      const char* pClassID;
      const char* pImplID;
      const char* pProtocolID;

      CATVizBaseCodeExtensionIDChain* pNextProtocol;
      CATVizBaseCodeExtensionIDChain* pPreviousProtocol;
      CATVizBaseCodeExtensionIDChain* pNextExtension;
      CATVizBaseCodeExtensionIDChain* pPreviousExtension;

      CATVizBaseCodeExtensionID* pExtensionID;

      CATVizBaseCodeExtensionIDChain();
      ~CATVizBaseCodeExtensionIDChain();
    };

    class CATVizBaseCodeExtensionIDInstances
    {
    public:
      CATVizBaseCodeExtension* pInstance;
      CATVizBaseCodeExtensionIDInstances* pNextInstance;

      CATVizBaseCodeExtensionIDInstances();
      ~CATVizBaseCodeExtensionIDInstances();
    };

    CATVizBaseCodeExtensionCreator      _Creator;
    CATVizBaseCodeExtensionIDChain      _Chain;
    CATVizBaseCodeExtensionIDInstances* _pInstances;

    static void ChainExtensionID(CATVizBaseCodeExtensionID* ipExtensionID);
    static CATVizBaseCodeExtensionIDChain* _first;
};


#endif










