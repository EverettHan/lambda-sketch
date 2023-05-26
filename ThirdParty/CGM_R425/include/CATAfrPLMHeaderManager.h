// -------------------------------------------------------------------
// IMO(c) Copyright Dassault Systemes 2004
//---------------------------------------------------------------------
// Responsable: IMO
//---------------------------------------------------------------------
// Source:  CATAfrPLMHeaderManager
//---------------------------------------------------------------------
//
// Contenu du source CATAfrPLMHeaderManager
//
//---------------------------------------------------------------------
// Historique:
// Creation         : 2004/04/10 > JDP
//---------------------------------------------------------------------
#ifndef CATAfrPLMHeaderManager_H_
#define CATAfrPLMHeaderManager_H_

#include "CATCallbackManager.h"
#include "CATAfrFoundation.h"

#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"

class CATSysPreferenceRepository;

class ExportedByCATAfrFoundation CATAfrPLMHeaderManager : public CATCallbackManager
{
public:

  CATDeclareClass;

   //----------------------------------------------------------------
   //   Recuperation des settings
   //----------------------------------------------------------------
   static CATAfrPLMHeaderManager* GetPLMSessionPreferences();
   
   //----------------------------------------------------------
   //  Environment Management
   //----------------------------------------------------------
   const CATListOfCATUnicodeString& GetListAvailableEnvironment();
   //Current Environment
   CATUnicodeString GetPreferredEnvironment();
   CATUnicodeString GetCurrentEnvironment();
   HRESULT SetCurrentEnvironment(const CATUnicodeString& iEnv);
   CATUnicodeString GetInternalCurrentEnvironment();
   //Environment Declaration
   HRESULT AddEnvironment(const CATUnicodeString& iEnv,const CATUnicodeString& iEnvInternal,int iCurrent);
   HRESULT RemoveEnvironment(const CATUnicodeString& iEnv);
   //Modification Callback
   CATDeclareCBEvent(EnvironmentChange);
   void EnvironmentModify();
   //Disconnect/serverDown Callback
   void Disconnect();

private:
   CATAfrPLMHeaderManager();
   CATAfrPLMHeaderManager(const CATAfrPLMHeaderManager&);
   CATAfrPLMHeaderManager& operator = (const CATAfrPLMHeaderManager&);
   ~CATAfrPLMHeaderManager();

   void RefreshVisu();
   
   //Stockage des settings crees
   static CATAfrPLMHeaderManager*        _MyThis;
   static CATSysPreferenceRepository*      _Repository;
   
   static CATUnicodeString          _CurrentEnv;
};

#endif

