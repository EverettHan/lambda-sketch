#ifndef CATIModelUnit_h
#define CATIModelUnit_h
#include "SceneGraphManager.h"

#include "CATBaseUnknown.h"
// CATIA Version 5 Release 1 Framework VFW2
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------
//
// Abstract : Interface permettant de recuperer le facteur de conversion
// ---------- en mm du modele.
//            
//            
//              
//   
//------------------------------------------------------------------------
//
// Usage :   implemente par le modele pour qu'une vue puisse recuperer 
// -------   l'information
//  
//------------------------------------------------------------------------
//
// Inheritance :  CATIModelUnit 
// -----------      CATBaseUnknown
//
//------------------------------------------------------------------------
//
// Main Methods :  GetScale()
// --------------  
//               
//------------------------------------------------------------------------

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedBySceneGraphManager IID IID_CATIModelUnit;
#else
extern "C" const IID IID_CATIModelUnit;
#endif

class ExportedBySceneGraphManager CATIModelUnit : public CATBaseUnknown
{
  CATDeclareInterface;

  public :
  ////////

  virtual double GetScale () const = 0;

} ; 

CATDeclareHandler(CATIModelUnit,CATBaseUnknown);

#endif
