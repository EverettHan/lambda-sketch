#ifndef CATIPointGRAPHICPROPERTIES_H
#define CATIPointGRAPHICPROPERTIES_H
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1997
//
//----------------------------------------------------------------
//
// Abstract :  interface auquelle doit souscrire un objet modele
// ----------  pour pouvoir changer son type de point
//
//              
//   
//-----------------------------------------------------------------
//
//  Usage :  utilise par les objets se visualisant sous forme de point
//  ------- 
//         
//
//-----------------------------------------------------------------
//
//  Inheritance :   CATIPointGraphicProperties
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

class CATIPointGraphicProperties_var;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATVisItf IID IID_CATIPointGraphicProperties;
#else
extern "C" const IID IID_CATIPointGraphicProperties;
#endif

class ExportedByCATVisItf CATIPointGraphicProperties : public CATBaseUnknown
{
  CATDeclareInterface;

  public :
  ////////
 
  virtual void SetColor     ( int red,  int green,  int blue) = 0; 
  virtual int  GetColor     (int &red, int &green, int &blue) = 0; 

  virtual void SetPointType ( int pointtype) = 0;
  virtual int  GetPointType () = 0;

  virtual void SetShowMode  ( CATShowMode showmode) = 0;
  virtual CATShowMode  GetShowMode () = 0;

  virtual void SetPickMode  ( CATPickMode pickmode) = 0;
  virtual CATPickMode  GetPickMode () = 0;

  virtual void SetValue ( CATIPointGraphicProperties_var &value ) = 0;

  virtual HRESULT MigrateToVisProperties (int iGeomType) = 0;
}; 

CATDeclareHandler(CATIPointGraphicProperties,CATBaseUnknown);

#endif
