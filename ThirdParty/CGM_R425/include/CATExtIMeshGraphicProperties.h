#ifndef CATExtIMeshGRAPHICPROPERTIES_H
#define CATExtIMeshGRAPHICPROPERTIES_H
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1997
//
//----------------------------------------------------------------
//
// Abstract :  implementation par defaut de l'interface
// ----------  CATIMeshGraphicProperties, la donnee est stocke
//             via une propriete sur le feature
//              
//   
//-----------------------------------------------------------------
//
//  Usage :  utilise par les objets se visualisant avec des meshs (surfacic)
//  ------- 
//         
//
//-----------------------------------------------------------------
//
//  Inheritance :   CATExtIMeshGraphicProperties
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
#include "CATMeshGraphicAttribut.h"
#include "CATIVisProperties.h"

class CATIMeshGraphicProperties_var;

class ExportedByCATVisItf CATExtIMeshGraphicProperties : public CATBaseUnknown
{
  CATDeclareClass;

public :
 
  CATExtIMeshGraphicProperties();
  virtual ~CATExtIMeshGraphicProperties();

  virtual void SetColor     ( int red,  int green,  int blue); 
  virtual int  GetColor     (int &red, int &green, int &blue); 

  virtual void SetOpacity ( int );
  virtual int  GetOpacity ();

  virtual void SetShowMode  ( CATShowMode showmode);
  virtual CATShowMode  GetShowMode ();

  virtual void SetPickMode  ( CATPickMode pickmode);
  virtual CATPickMode  GetPickMode ();

  virtual void SetValue ( CATIMeshGraphicProperties_var &value );

  virtual HRESULT MigrateToVisProperties (CATVisGeomType iGeomType = CATVPMesh);

private :
  void Init();  

  /*DULL                   _value; 
  unsigned long          _tmp;
  CORBAAny               _Cvalue;
  CORBAAny               _Cvalue1;
  CATMeshGraphicAttribut _att;*/
  int                    _first;
  CATVisGeomType _geomType;
}; 

#endif
