#ifndef CATExtIAsmGRAPHICPROPERTIES_H
#define CATExtIAsmGRAPHICPROPERTIES_H
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1997
//
//----------------------------------------------------------------
//
// Abstract :  implementation par defaut de l'interface
// ----------  CATIAsmGraphicProperties, la donnee est stocke
//             via une propriete sur le feature
//              
//   
//-----------------------------------------------------------------
//
//  Usage :  utilise par les objets d'assemblage (pointant sur des
//  -------  pieces a assembler)
//         
//
//-----------------------------------------------------------------
//
//  Inheritance :   CATExtIAsmGraphicProperties
//  -------------     CATBaseUnknown
//
//-----------------------------------------------------------------
//
//  Main Methods :
//  --------------
//
//
//-----------------------------------------------------------------
#include "SceneGraphManager.h"
#include "CATBaseUnknown.h"
#include "CATShowMode.h"
#include "CATPickMode.h"
#include "CATIVisProperties.h"

class CATIAsmGraphicProperties_var;

class ExportedBySceneGraphManager CATExtIAsmGraphicProperties : public CATBaseUnknown
{
  CATDeclareClass;

  public :
  ////////

  CATExtIAsmGraphicProperties();
  virtual ~CATExtIAsmGraphicProperties();
 
  virtual void SetColor     ( int red,  int green,  int blue, 
                              int inheritance = 0); 
  virtual int  GetColor     (int &red, int &green, int &blue); 
  virtual void ResetColor();

  virtual void SetOpacity ( int );
  virtual int  GetOpacity ();

  virtual void SetLineType  ( int linetype, int inheritance = 0 );
  virtual void ResetLineType   ();
  virtual int  GetLineType  ( int &lineType );

  virtual void SetThickness ( int thickness, int inheritance = 0 );
  virtual void ResetThickness   ();
  virtual int  GetThickness ( int &thickness );

  virtual void SetShowMode  ( CATShowMode showmode);
  virtual CATShowMode  GetShowMode ();

  virtual void SetPickMode  ( CATPickMode pickmode);
  virtual CATPickMode  GetPickMode ();

  virtual void SetValue ( CATIAsmGraphicProperties_var &value );

  virtual int IsAssociatedToShape();

  virtual HRESULT MigrateToVisProperties(CATVisGeomType iGeomType = CATVPAsm);  

private:
  CATVisGeomType _geomType;

}; 

#endif
