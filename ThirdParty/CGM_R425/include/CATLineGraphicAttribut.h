#ifndef CATLineGraphicAttribut_h
#define CATLineGraphicAttribut_h

//********************************************************************
// CATIA Framework CATIAModelVisu (PPE)
// Copyright Dassault Systemes 1997
//********************************************************************
//
//  Abstract:
//  ---------
//    This defines line graphic attribut 
//    
//
//********************************************************************
//
//  Usage: used by object which implement CATILineicGraphicProperties 
//  ------ or CATIEdgeGraphicProperties
//
//********************************************************************
//
//  Inheritance:
//  ------------
//              CATLineGraphicAttribut
//                CATBaseUnknown (SYSTEM framework)
//
//********************************************************************
//
//  Main Methods:
//  -------------
//
//********************************************************************
// les attributs sont stockes sur un unsigned long  de la maniere
//  suivante par defaut :
//
//      Rouge       Vert      Bleu    type ligne/epaisseur ligne/pick/show
// !----------!----------!----------!----------!
// ! 11111111 ! 11111111 ! 11111111 ! 00100111 !
// !----------!----------!----------!----------!
//
//  pick            : 1 --> Pick , 0 --> NoPick
//  Show            : 1 --> Vu , 0 non Vu
//  Epaisseur line  : 1 - 8 indice de l epaisseur de la ligne
//  Type line       : 1 - 8 indice du type de ligne
//  Rouge           : 0 - 255 valeur du rouge
//  Vert            : 0 - 255 valeur du vert
//  Bleu            : 0 - 255 valeur du bleu

#define SHOWline       0x00000001
#define RAZSHOWline    0xfffffffe
#define dSHOWline      0
#define PICKline       0x00000002
#define RAZPICKline    0xfffffffd
#define dPICKline      1
#define THLINEline     0x0000001c
#define RAZTHLINEline  0xffffffe3
#define dTHLINEline    2
#define TYLINEline     0x000000e0
#define RAZTYLINEline  0xffffff1f
#define dTYLINEline    5
#define ROUGEline      0xff000000
#define dROUGEline     24
#define VERTline       0x00ff0000
#define dVERTline      16
#define BLEUline       0x0000ff00
#define dBLEUline      8
#define RAZRGBline     0x000000ff
#define DEFAULTline    0xffffff27


#include "CATVisItf.h"
#include "CATBaseUnknown.h"
#include "CATShowMode.h"
#include "CATPickMode.h"
#include "CATDataType.h"

class ExportedByCATVisItf CATLineGraphicAttribut : public CATBaseUnknown
{
  CATDeclareClass;
  public:
  ///////
    
    CATLineGraphicAttribut ();
    CATLineGraphicAttribut (CATULONG32 value);
    virtual ~CATLineGraphicAttribut (void) ;

    CATULONG32 GetValue();   

    virtual void SetColor     (int red, int green, int blue);
    virtual int  GetColor     (int &red, int &green, int &blue);

    virtual void SetLineType (int linetype);
    virtual int  GetLineType ();

    virtual void SetThickness (int thickness);
    virtual int  GetThickness ();

    virtual void SetShowMode  (CATShowMode showmode);
    virtual CATShowMode  GetShowMode ();

    virtual void SetPickMode  (CATPickMode pickmode);
    virtual CATPickMode  GetPickMode ();

    
  private:
  ////////

    CATULONG32 _value;
};

#endif
