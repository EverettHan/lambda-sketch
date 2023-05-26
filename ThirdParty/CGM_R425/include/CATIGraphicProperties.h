#ifndef CATIGRAPHICPROPERTIES_H
#define CATIGRAPHICPROPERTIES_H
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1997
//
//----------------------------------------------------------------
//
// Abstract :  interface auquelle doit souscrire un objet modele
// ----------  pour participer au moteur de visualisation.
//
//             ( permet de definir le fait qu'un element modele
//               peut etre vue d'une certaine maniere. La maniere etant
//               definie par le type (au sens IsAKindOf) de l'interface de
//               visu )
//            
//              
//   
//-----------------------------------------------------------------
//
//  Usage :    cette interface est derivee de facon a definir les differents
//  -------    types de visu d'un element ( un objet modele peut
//             adherer a plusieurs types d'interfaces de visu )
//
//-----------------------------------------------------------------
//
//  Inheritance :   CATIGraphicProperties
//  -------------     CATInterfaceObject
//
//-----------------------------------------------------------------
//
//  Main Methods :
//  --------------
//
//
//-----------------------------------------------------------------
#include "CATVisItf.h"
#include "CATBaseUnknown.h"
#include "CATShowMode.h"
#include "CATPickMode.h"
#include "list.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATVisItf IID IID_CATIGraphicProperties;
#else
extern "C" const IID IID_CATIGraphicProperties;
#endif

class ExportedByCATVisItf CATIGraphicProperties : public CATBaseUnknown
{
  CATDeclareInterface;

  public :
  ////////
 
  virtual void SetColor     ( int red,  int green,  int blue) = 0; 
  virtual void ResetColor   () = 0;
  virtual int  GetColor     (int &red, int &green, int &blue) = 0; 

  virtual void SetOpacity   ( int coeff) = 0;
  virtual int  GetOpacity   () = 0;

  virtual void SetLineType  ( int linetype) = 0;
  virtual int  GetLineType  () = 0;

  virtual void SetThickness ( int thickness) = 0;
  virtual int  GetThickness () = 0;

  virtual void SetPointType ( int pointtype) = 0;
  virtual int  GetPointType () = 0;

  virtual void SetShowMode  ( CATShowMode showmode) = 0;
  virtual CATShowMode  GetShowMode () = 0;

  virtual void SetPickMode  ( CATPickMode pickmode) = 0;
  virtual CATPickMode  GetPickMode () = 0;

  virtual ::list<IID> *GetVisuInterface() = 0;
  virtual void SetVisuInterface(IID *iid) = 0;
  virtual void AddVisuInterface(IID *iid) = 0;
  virtual void RemVisuInterface(IID *iid) = 0;

}; 

CATDeclareHandler(CATIGraphicProperties,CATBaseUnknown);

#endif
