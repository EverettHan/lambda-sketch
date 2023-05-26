// COPYRIGHT DASSAULT SYSTEMES  1999
//=============================================================================
//
// CATIKwePerfo.h:
//	Cette interface a pour but d'ameliorer les performances des processus de recherche de
//	feature specifique. Y adhere un strict minimum d'objets afin de faire un GetDirectChildren
//	le plus rapide possible.
//
//=============================================================================
// Usage Notes:
//
//=============================================================================
// Sept. 99   Creation                                   A. Anquetil
//=============================================================================

#ifndef  CATIKwePerfo_H
#define  CATIKwePerfo_H

#include "KnowledgeItf.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByKnowledgeItf  IID_CATIKwePerfo;
#else
extern "C" const IID IID_CATIKwePerfo;
#endif

class ExportedByKnowledgeItf CATIKwePerfo : public CATBaseUnknown
{

  private :

  CATDeclareInterface;

  public :

};

CATDeclareHandler(CATIKwePerfo,CATBaseUnknown);

#endif


