#ifndef CATISurfacicGRAPHICPROPERTIES_H
#define CATISurfacicGRAPHICPROPERTIES_H
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1998
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
//  -------    sous forme de mesh+isopars
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
#include "CATSurfacicVisualizationMode.h"

class CATISurfacicGraphicProperties_var;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATVisItf IID IID_CATISurfacicGraphicProperties;
#else
extern "C" const IID IID_CATISurfacicGraphicProperties;
#endif

class ExportedByCATVisItf CATISurfacicGraphicProperties : public CATBaseUnknown
{
  CATDeclareInterface;

  public :
  ////////
 
  virtual void SetVisualizationMode(int mode) = 0; 
  virtual int  GetVisualizationMode() = 0; 

  virtual void SetIsoparsNumberInU(int number) = 0;
  virtual int  GetIsoparsNumberInU() = 0;

  virtual void SetIsoparsNumberInV(int number) = 0;
  virtual int  GetIsoparsNumberInV() = 0;

  virtual void SetValue(CATISurfacicGraphicProperties_var &value) = 0;


}; 

CATDeclareHandler(CATISurfacicGraphicProperties,CATBaseUnknown);

#endif
