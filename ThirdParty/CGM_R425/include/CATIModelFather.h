#ifndef CATIModelFather_H
#define CATIModelFather_H

#include "CATVisItf.h"
#include "CATBaseUnknown.h"
#include "list.h"

// CATIA Version 5 Release 1 Framework VFW2
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------
//
// Abstract : Interface de gestion des peres d un objet
// ---------- 
//            
//            
//              
//   
//------------------------------------------------------------------------
//
// Usage :   
//  
//------------------------------------------------------------------------
//
// Inheritance :  
//
//------------------------------------------------------------------------
//
// Main Methods :  
//             IsFather ( elem )
//             AddSceneGraphEdge ( elem )
//             RemoveSceneGraphEdge ( elem)
//               
//------------------------------------------------------------------------

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATVisItf IID IID_CATIModelFather;
#else
extern "C" const IID IID_CATIModelFather;
#endif

class ExportedByCATVisItf CATIModelFather : public CATBaseUnknown
{
  CATDeclareInterface;

  public :
  ////////
    virtual int IsFather(CATBaseUnknown *elem) = 0 ;
    virtual void AddFather(CATBaseUnknown *elem) = 0 ;
    virtual void RemoveFather(CATBaseUnknown *elem) = 0;
    virtual list<CATBaseUnknown> *GetFathers() = 0;
}
;

CATDeclareHandler(CATIModelFather,CATBaseUnknown);
  
#endif
