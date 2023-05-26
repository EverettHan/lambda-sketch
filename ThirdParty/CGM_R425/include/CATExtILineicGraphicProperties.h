#ifndef CATExtILineicGRAPHICPROPERTIES_H
#define CATExtILineicGRAPHICPROPERTIES_H
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1997
//
//----------------------------------------------------------------
//
// Abstract :  implementation par defaut de l'interface
// ----------  CATILineicGraphicProperties, la donnee est stocke
//             via une propriete sur le feature
//              
//   
//-----------------------------------------------------------------
//
//  Usage :  utilise par les objets se visualisant sous forme lineique
//  ------- 
//         
//
//-----------------------------------------------------------------
//
//  Inheritance :   CATExtILineicGraphicProperties
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

class CATILineicGraphicProperties_var;

class ExportedByCATVisItf CATExtILineicGraphicProperties : public CATBaseUnknown
{
  CATDeclareClass;

  public :
  ////////
 
  CATExtILineicGraphicProperties();
  virtual ~CATExtILineicGraphicProperties();

  virtual void SetColor     ( int red,  int green,  int blue); 
  virtual int  GetColor     (int &red, int &green, int &blue); 

  virtual void SetThickness ( int );
  virtual int  GetThickness ();

  virtual void SetLineType ( int );
  virtual int  GetLineType ();

  virtual void SetShowMode  ( CATShowMode showmode);
  virtual CATShowMode  GetShowMode ();

  virtual void SetPickMode  ( CATPickMode pickmode);
  virtual CATPickMode  GetPickMode ();

  virtual void SetValue ( CATILineicGraphicProperties_var &value );

  virtual HRESULT MigrateToVisProperties (CATVisGeomType iGeomType = CATVPLine);


private:
  CATVisGeomType _geomType;
}; 

#endif
