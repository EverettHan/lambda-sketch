#ifndef CATIMeshGRAPHICPROPERTIES_H
#define CATIMeshGRAPHICPROPERTIES_H
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1997
//
//----------------------------------------------------------------
//
// Abstract :  interface auquelle doit souscrire un objet modele
// ----------  pour pouvoir changer ses attributs de type mesh
//
//              
//   
//-----------------------------------------------------------------
//
//  Usage :    cette interface est implementee par les objets se visualisant
//  -------    sous forme de mesh
//           
//
//-----------------------------------------------------------------
//
//  Inheritance :   CATIGraphicProperties
//  -------------     CATBaseUnknown
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

class CATIMeshGraphicProperties_var;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATVisItf IID IID_CATIMeshGraphicProperties;
#else
extern "C" const IID IID_CATIMeshGraphicProperties;
#endif

class ExportedByCATVisItf CATIMeshGraphicProperties : public CATBaseUnknown
{
  CATDeclareInterface;

  public :
  ////////
 
  virtual void SetColor     ( int red,  int green,  int blue) = 0; 
  virtual int  GetColor     (int &red, int &green, int &blue) = 0; 

  virtual void SetOpacity   ( int coeff) = 0;
  virtual int  GetOpacity   () = 0;

  virtual void SetShowMode  ( CATShowMode showmode) = 0;
  virtual CATShowMode  GetShowMode () = 0;

  virtual void SetPickMode  ( CATPickMode pickmode) = 0;
  virtual CATPickMode  GetPickMode () = 0;

  virtual void SetValue ( CATIMeshGraphicProperties_var &value ) = 0;

  virtual HRESULT MigrateToVisProperties (int iGeomType) = 0;
}; 

CATDeclareHandler(CATIMeshGraphicProperties,CATBaseUnknown);

#endif
