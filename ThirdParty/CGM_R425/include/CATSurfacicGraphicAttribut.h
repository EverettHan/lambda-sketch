#ifndef CATSurfacicGraphicAttribut_H
#define CATSurfacicGraphicAttribut_H

//********************************************************************
// CATIA Framework Visualization 
// Copyright Dassault Systemes 1998
//********************************************************************
//
//  Abstract:
//  ---------
//    This defines the model graphic attribut 
//    
//
//********************************************************************
//
//  Usage: used by object which implement CATISurfacicGraphicProperties 
//  ------ 
//
//********************************************************************
//
//  Inheritance:
//  ------------
//              CATSurfacicGraphicAttribut
//                CATBaseUnknown (SYSTEM framework)
//
//********************************************************************
//
//  Main Methods:
//  -------------
//
//********************************************************************
// les attributs sont stockes sur un long de la maniere
//  suivante par defaut :
//
//             Isopars V  Isopars U  Mode Visu
// !----------!----------!----------!----------!
// ! 00000001 ! 00000001 !000000001 ! 00000001 !
// !----------!----------!----------!----------!
//
//  Mode Visu  : 1 --> SHADING, 2 --> ISOPARS, 4 --> PTCONTROL,
//               3 --> SHADINGAndISOPARS, 5 --> SHADINGAndPTCONTROL,
//               6 --> ISOPARSAndPTCONTROL, 7 --> SHADINGAndISOPARSAndPTCONTROL
//  Isopars U  : 0 - 255 Nombre d'isopar en U
//  Isopars V  : 0 - 255 Nombre d'isopar en V

#define dUNUMBERsurfacic     8
#define dVNUMBERsurfacic    16
#define MODEVISUsurfacic    0x000000ff
#define UNUMBERsurfacic     0x0000ff00
#define VNUMBERsurfacic     0x00ff0000
#define DEFAULTsurfacic     0x01010101
#define RAZMODEVISUsurfacic 0xffffff00
#define RAZUNUMBERsurfacic  0xffff00ff
#define RAZVNUMBERsurfacic  0xff00ffff


#include "SceneGraphManager.h"
#include "CATBaseUnknown.h"
#include "CATSurfacicVisualizationMode.h"
#include "CATDataType.h"

class CATISurfacicGraphicProperties_var;

class ExportedBySceneGraphManager CATSurfacicGraphicAttribut : public CATBaseUnknown
{
  CATDeclareClass;

  public:
    
    CATSurfacicGraphicAttribut();
    CATSurfacicGraphicAttribut(CATULONG32);
    virtual ~CATSurfacicGraphicAttribut();

    CATULONG32 GetValue();

    virtual void SetVisualizationMode(int);
    virtual int  GetVisualizationMode();

    virtual void SetIsoparsNumberInU(int);
    virtual int  GetIsoparsNumberInU();

    virtual void SetIsoparsNumberInV(int);
    virtual int  GetIsoparsNumberInV();

    virtual void SetValue (CATISurfacicGraphicProperties_var &);

  private:

    CATULONG32 _ulValue;
};

#endif
