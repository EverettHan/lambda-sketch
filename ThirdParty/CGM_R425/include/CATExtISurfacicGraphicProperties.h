#ifndef CATExtISurfacicGRAPHICPROPERTIES_H
#define CATExtISurfacicGRAPHICPROPERTIES_H
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1997
//
//----------------------------------------------------------------
//
// Abstract :  implementation par defaut de l'interface
// ----------  CATISurfacicGraphicProperties, la donnee est stocke
//             via une propriete sur le feature
//              
//   
//-----------------------------------------------------------------
//
//  Usage :  utilise par les objets se visualisant avec des meshs (surfacic)
//  -------  + Isopars
//         
//
//-----------------------------------------------------------------
//
//  Inheritance :   CATExtISurfacicGraphicProperties
//  -------------     CATBaseUnknown
//
//-----------------------------------------------------------------
//
//  Main Methods :
//  --------------
//
//
//-----------------------------------------------------------------
#include "CATGraphicProperties.h"
#include "CATBaseUnknown.h"
#include "CATSurfacicVisualizationMode.h"

class CATISurfacicGraphicProperties_var;

class ExportedByCATGraphicProperties CATExtISurfacicGraphicProperties : public CATBaseUnknown
{
  CATDeclareClass;

  public :
  ////////
 
  CATExtISurfacicGraphicProperties();
  virtual ~CATExtISurfacicGraphicProperties();

  virtual void SetVisualizationMode(int);
  virtual int  GetVisualizationMode();

  virtual void SetIsoparsNumberInU(int);
  virtual int  GetIsoparsNumberInU();

  virtual void SetIsoparsNumberInV(int);
  virtual int  GetIsoparsNumberInV();

  virtual void SetValue (CATISurfacicGraphicProperties_var &value);

}; 

#endif
