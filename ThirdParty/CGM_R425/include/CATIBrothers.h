#ifndef CATIBrothers_h
#define CATIBrothers_h
#include "SceneGraphManager.h"

#include "CATBaseUnknown.h"

// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1998
//
//----------------------------------------------------------------
//
// Abstract :  interface auquelle doit souscrire un objet modele
// ----------  capable de generer un CATPathElement
//
//            
//   
//-----------------------------------------------------------------
//
//  Usage :    
//  -------   
//           
//
//-----------------------------------------------------------------
//
//  Inheritance :   CATIBrothers
//  -------------     CATBaseUnknown
//
//-----------------------------------------------------------------
//
//  Main Methods :
//  --------------
//                   GetBrothers()
//
//-----------------------------------------------------------------
#include "CATBaseUnknown.h"

class CATSO;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedBySceneGraphManager IID IID_CATIBrothers;
#else
extern "C" const IID IID_CATIBrothers;
#endif

class CATPathElement;

class ExportedBySceneGraphManager CATIBrothers : public CATBaseUnknown
{
  CATDeclareInterface;

  public :
  ////////
 
  virtual CATSO * GetBrothers () = 0 ;

}; 

CATDeclareHandler(CATIBrothers,CATBaseUnknown);

#endif
