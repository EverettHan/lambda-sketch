#ifndef CATExtIEdgeGRAPHICPROPERTIES_H
#define CATExtIEdgeGRAPHICPROPERTIES_H
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1997
//
//----------------------------------------------------------------
//
// Abstract :  implementation par defaut de l'interface
// ----------  CATIEdgeGraphicProperties, la donnee est stocke
//             via une propriete sur le feature
//              
//   
//-----------------------------------------------------------------
//
//  Usage :  utilise par les objets se visualisant avec des edges
//  ------- 
//         
//
//-----------------------------------------------------------------
//
//  Inheritance :   CATExtIEdgeGraphicProperties
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
#include "CATEdgeGraphicAttribut.h"
#include "CATIVisProperties.h"

class CATIEdgeGraphicProperties_var;

class ExportedByCATVisItf CATExtIEdgeGraphicProperties : public CATBaseUnknown
{
  CATDeclareClass;

public :
  ////////
 
  CATExtIEdgeGraphicProperties();
  virtual ~CATExtIEdgeGraphicProperties();

  virtual void SetColor     ( int red,  int green,  int blue); 
  virtual int  GetColor     (int &red, int &green, int &blue); 

  virtual void SetThickness ( int );
  virtual int  GetThickness ();

  virtual void SetLineType  ( int );
  virtual int  GetLineType  ();

  virtual void SetShowMode  ( CATShowMode showmode);
  virtual CATShowMode  GetShowMode ();

  virtual void SetPickMode  ( CATPickMode pickmode);
  virtual CATPickMode  GetPickMode ();

  virtual void SetValue ( CATIEdgeGraphicProperties_var &value );

  virtual HRESULT MigrateToVisProperties (CATVisGeomType iGeomType = CATVPEdge);

private :
  void Init();  

  /*unsigned long          _value; 
  CORBAAny               _Cvalue;
  CATEdgeGraphicAttribut _att;*/
  int                    _first;
  CATVisGeomType _geomType;
}; 

#endif
