#ifndef CATIEdgeGRAPHICPROPERTIES_H
#define CATIEdgeGRAPHICPROPERTIES_H
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1997
//
//----------------------------------------------------------------
//
// Abstract :  interface auquelle doit souscrire un objet modele
// ----------  pour pouvoir changer le type de visu des edges
//
//              
//   
//-----------------------------------------------------------------
//
//  Usage :    cette interface est implementee par les objets contenant
//  -------    des edges
//            
//
//-----------------------------------------------------------------
//
//  Inheritance :   CATIEdgeGraphicProperties
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

class CATIEdgeGraphicProperties_var;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATVisItf IID IID_CATIEdgeGraphicProperties;
#else
extern "C" const IID IID_CATIEdgeGraphicProperties;
#endif

class ExportedByCATVisItf CATIEdgeGraphicProperties : public CATBaseUnknown
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

  virtual void SetValue ( CATIEdgeGraphicProperties_var &value ) = 0;

  virtual HRESULT MigrateToVisProperties (int iGeomType) = 0;

}; 

CATDeclareHandler(CATIEdgeGraphicProperties,CATBaseUnknown);

#endif
