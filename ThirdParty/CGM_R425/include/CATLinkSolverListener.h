// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATLinkSolverListener_h
#define CATLinkSolverListener_h

#include "IUnknown.h"
#include "CATObjectModelerBase.h"

class CATDocumentEntity;
class CATLinkSolver;

class CATLinkSolverEvent
{
public:	

  enum Type { Bind , Unload, Broken, Rename};
  enum When { Before, After, Now };
  enum LinkNameItem { Rn, UUID, Locator, Doc, None};

  CATLinkSolverEvent (When iWhen,Type iType, LinkNameItem iN = None ):
    _What(iType),_When(iWhen),_NI(iN){};

  ~CATLinkSolverEvent(){};

  inline When GetTimeOccurence() const {return _When;};
  inline Type GetType () const {return _What;};
  inline LinkNameItem GetLinkNameChange () const {return _NI;};

private:
  When _When;
  Type _What;
  LinkNameItem _NI;
};



class ExportedByCATObjectModelerBase CATLinkSolverListener
{
public :
  enum ListnerType{Unknown,Ticket,SolverTable,ListnerType_Size};
  virtual ListnerType GetListenerType() const = 0 ; 
  virtual void OnEvent(const CATLinkSolver&, const CATLinkSolverEvent& ) =0;
};


#endif

