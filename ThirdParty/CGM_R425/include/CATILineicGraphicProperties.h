#ifndef CATILineicGRAPHICPROPERTIES_H
#define CATILineicGRAPHICPROPERTIES_H
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1997
//
//----------------------------------------------------------------
//
// Abstract :  interface auquelle doit souscrire un objet modele
// ----------  pour pouvoir changer son type de trait
//
//              
//   
//-----------------------------------------------------------------
//
//  Usage :    cette interface est implente par les objets qui se
//  -------    visualisent sous forme filaire
//           
//
//-----------------------------------------------------------------
//
//  Inheritance :   CATILineicGraphicProperties
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

class CATILineicGraphicProperties_var;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATVisItf IID IID_CATILineicGraphicProperties;
#else
extern "C" const IID IID_CATILineicGraphicProperties;
#endif

class ExportedByCATVisItf CATILineicGraphicProperties : public CATBaseUnknown
{
  CATDeclareInterface;

  public :
  ////////
 
  virtual void SetColor     ( int red,  int green,  int blue) = 0; 
  virtual int  GetColor     (int &red, int &green, int &blue) = 0; 

  virtual void SetLineType  ( int linetype) = 0;
  virtual int  GetLineType  () = 0;

  virtual void SetThickness ( int thickness) = 0;
  virtual int  GetThickness () = 0;

  virtual void SetShowMode  ( CATShowMode showmode) = 0;
  virtual CATShowMode  GetShowMode () = 0;

  virtual void SetPickMode  ( CATPickMode pickmode) = 0;
  virtual CATPickMode  GetPickMode () = 0;

  virtual void SetValue ( CATILineicGraphicProperties_var &value ) = 0;

  virtual HRESULT MigrateToVisProperties (int iGeomType) = 0;

}; 

CATDeclareHandler(CATILineicGraphicProperties,CATBaseUnknown);

#endif
