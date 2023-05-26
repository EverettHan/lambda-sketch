#ifndef CATILAYERFILTER_H
#define CATILAYERFILTER_H
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1997
//
//----------------------------------------------------------------
//
// Abstract :  interface auquelle doit souscrire un objet modele
// ----------  pour participer au filtrage par niveau de layer.
//
//             ( permet de definir le fait qu'un element modele
//               peut etre vu en fonction d'un niveau de layer
//              
//   
//-----------------------------------------------------------------
//
//  Usage :    cette interface est derivee de facon a definir les differents
//  -------    types de filtrage layer
//            
//
//-----------------------------------------------------------------
//
//  Inheritance :   CATILayerFilter
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
extern ExportedBySceneGraphManager IID IID_CATILayerFilter;
#else
extern "C" const IID IID_CATILayerFilter;
#endif

class ExportedBySceneGraphManager CATILayerFilter : public CATBaseUnknown
{
  CATDeclareInterface;

  public :
  ////////

  virtual void GetModelFilter(unsigned char filter[255]) = 0;
  virtual unsigned char * GetModelLayer() = 0; 
  virtual int GetElementLayer() = 0;

  private :

}; 

CATDeclareHandler(CATILayerFilter,CATBaseUnknown);

#endif
