// COPYRIGHT DASSAULT SYSTEMES 2002

#ifndef CATLoadModeListenerAdapter_H
#define CATLoadModeListenerAdapter_H
//
// adapter for CATILoadModeListener
//
/**
 * @level Private
 * @usage U1
 */

#include "CATBaseUnknown.h"
#include "AC0XXLNK.h"


class CATUnicodeString;
class CATIContainer;
class CATDocument;
// adapter for CATILoadModeListener



class ExportedByAC0XXLNK CATLoadModeListenerAdapter : public CATBaseUnknown
{
  public:
  
  CATDeclareClass;
  
  //--------------
  // 'tors
  //--------------
  CATLoadModeListenerAdapter () ;
  virtual ~CATLoadModeListenerAdapter() ;
 
  //------------------------------
  // CATILoadModeListener bindings
  //------------------------------
    virtual HRESULT  ContainerLoaded(CATIContainer* iCont);// to be deleted
    virtual HRESULT  ContainerLoaded(CATDocument* iDoc,CATIContainer* iCont);

    virtual HRESULT  ContainerUnloaded(CATDocument* iDoc,CATIContainer* iCont);

    virtual HRESULT  ModeChanged(CATDocument* iDoc,const CATUnicodeString& iInitialMode,const CATUnicodeString& iFinalMode);

    virtual HRESULT  DocumentRemoved(CATDocument* iDoc);

    virtual HRESULT  SpecificChange(CATDocument* iDoc,CATIContainer* icont, const char* iCode);

};

#endif
