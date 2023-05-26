#ifndef CATIPermanentShow_H
#define CATIPermanentShow_H
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1997
//
//----------------------------------------------------------------
//
// Abstract :  interface auquelle doit souscrire un objet modele
// ----------  pour pouvoir toujours etre visible.
//
//              
//   
//-----------------------------------------------------------------
//
//  Usage :    cette interface est implementee par les objets qui veulent
//  -------    etre toujours visible
//           
//
//-----------------------------------------------------------------
//
//  Inheritance :   CATIPermanentShow
//  -------------     CATBaseUnknown
//
//-----------------------------------------------------------------
//
//  Main Methods :
//  --------------
//
//
//-----------------------------------------------------------------
#include "SceneGraphManager.h"
#include "CATBaseUnknown.h"


#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedBySceneGraphManager IID IID_CATIPermanentShow;
#else
extern "C" const IID IID_CATIPermanentShow;
#endif

class ExportedBySceneGraphManager CATIPermanentShow : public CATBaseUnknown
{
  CATDeclareInterface;

  public:
}; 

CATDeclareHandler(CATIPermanentShow,CATBaseUnknown);

#endif
