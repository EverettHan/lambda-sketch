
//===================================================================
// COPYRIGHT Dassault Systemes 2013/10/30
//===================================================================
// CATAfrGenericCefActorCtxBar.cpp
// Header definition of class CATAfrGenericCefActorCtxBar
//===================================================================
//
// Usage notes:
//
//===================================================================

#ifndef CATAfrGenericCefActorCtxBar_H
#define CATAfrGenericCefActorCtxBar_H

#include "CATAdapterAfrCtxBar.h"

class CATOmxAny;
class CATICAfrComponentElement;

//-----------------------------------------------------------------------

class CATAfrGenericCefActorCtxBar: public CATAdapterAfrCtxBar
{
  CATDeclareClass;
  public:
    // Standard constructors and destructors
    // -------------------------------------
    CATAfrGenericCefActorCtxBar ();
    virtual ~CATAfrGenericCefActorCtxBar ();
    
    virtual HRESULT FillCtxBar(const CATString iId);

    virtual HRESULT FillCtxMenu(const CATString iId);

    void SetModel(const CATUnicodeString & iModel,const CATUnicodeString & iArgument2);

  private:
    // Copy constructor and equal operator
    // -----------------------------------
    CATAfrGenericCefActorCtxBar (CATAfrGenericCefActorCtxBar &);
    CATAfrGenericCefActorCtxBar& operator=(CATAfrGenericCefActorCtxBar&);

    void TranslateModel(CATICAfrComponent* piComponent,CATOmxAny & iAny);

    CATICAfrComponentElement*  AddContainer(CATICAfrComponent* piComponent, const CATUnicodeString& iName, const CATUnicodeString& iTitle); 
    void AddStarter(CATICAfrComponent* piComponent, const CATUnicodeString& iIdName, const CATUnicodeString& iCmdHeaderName); 
    void AddSeparator(CATICAfrComponent* piComponent, const CATUnicodeString& iName); 

    HRESULT CreateCommandHeader(const CATUnicodeString& iHeaderID, 
                                const CATUnicodeString& iLoadName, 
                                const CATUnicodeString& iClassName, 
                                void * iArgument, 
                                const CATUnicodeString& iIconName,
                                const CATUnicodeString& iTitle, 
                                const CATUnicodeString& iHelp,
                                const CATBoolean iDisabled,
                                const CATUnicodeString& cmdId,
                                const CATBoolean iCheckable = FALSE,
                                const CATBoolean iChecked = FALSE);

    const CATUnicodeString& GetModel();

    //Attributs
    CATUnicodeString _jsModel;
    CATUnicodeString _menuID;
    CATUnicodeString _cefComponentName;

};

//-----------------------------------------------------------------------

#endif


