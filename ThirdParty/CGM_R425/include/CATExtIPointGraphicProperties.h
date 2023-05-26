#ifndef CATExtIPointGRAPHICPROPERTIES_H
#define CATExtIPointGRAPHICPROPERTIES_H
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1997
//
//----------------------------------------------------------------
//
// Abstract :  implementation par defaut de l'interface
// ----------  CATIPointGraphicProperties, la donnee est stocke
//             via une propriete sur le feature
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
//  Inheritance :   CATExtIPointGraphicProperties
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
#include "CATIVisProperties.h"

class CATIPointGraphicProperties_var;

class ExportedByCATVisItf CATExtIPointGraphicProperties : public CATBaseUnknown
{
  CATDeclareClass;

  public :
  ////////
 
  CATExtIPointGraphicProperties();
  virtual ~CATExtIPointGraphicProperties();
  virtual void SetColor     ( int red,  int green,  int blue); 
  virtual int  GetColor     (int &red, int &green, int &blue); 

  virtual void SetPointType ( int pointtype);
  virtual int  GetPointType ();

  virtual void SetShowMode  ( CATShowMode showmode);
  virtual CATShowMode  GetShowMode ();

  virtual void SetPickMode  ( CATPickMode pickmode);
  virtual CATPickMode  GetPickMode ();

  virtual void SetValue ( CATIPointGraphicProperties_var &value );

  virtual HRESULT MigrateToVisProperties (CATVisGeomType iGeomType = CATVPPoint);

private:
  CATVisGeomType _geomType;
}; 

#endif
