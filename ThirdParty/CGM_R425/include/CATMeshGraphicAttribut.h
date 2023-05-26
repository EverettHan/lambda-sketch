#ifndef CATMeshGraphicAttribut_h
#define CATMeshGraphicAttribut_h

//********************************************************************
// CATIA Framework CATIAModelVisu (PPE)
// Copyright Dassault Systemes 1997
//********************************************************************
//
//  Abstract:
//  ---------
//    This defines the model graphic attribut 
//    
//
//********************************************************************
//
//  Usage: used by object which implement CATIMeshGraphicProperties 
//  ------ 
//
//********************************************************************
//
//  Inheritance:
//  ------------
//              CATMeshGraphicAttribut
//                CATBaseUnknown (SYSTEM framework)
//
//********************************************************************
//
//  Main Methods:
//  -------------
//
//********************************************************************
// les attributs sont stockes sur un double de la maniere
//  suivante par defaut :
//                pick                   show
// !----------!----------!----------!----------!
// ! 00000000 ! 00000010 ! 00000000 ! 00000010 !
// !----------!----------!----------!----------!
//
//      Rouge       Vert      Bleu      Opacite
// !----------!----------!----------!----------!
// ! 11111111 ! 11111111 ! 11111111 ! 11111111 !
// !----------!----------!----------!----------!
//
//  pick            : 0 --> No Pick , 1 --> Pick
//  Show            : 0 --> Non Vu , 1 --> Vu
//  Rouge           : 0 - 255 valeur du rouge
//  Vert            : 0 - 255 valeur du vert
//  Bleu            : 0 - 255 valeur du bleu
//  Opacite         : 0 - 255 valeur de la transparence ( 0 ==> 
//                       completement transparent , 255 ==> completement opaque)

#define SHOWmesh      0x00000002
#define RAZSHOWmesh   0xfffffffd
#define dSHOWmesh     1
#define PICKmesh      0x00020000
#define RAZPICKmesh   0xfffdffff
#define dPICKmesh     17
#define ROUGEmesh     0xff000000
#define dROUGEmesh    24
#define VERTmesh      0x00ff0000
#define dVERTmesh     16
#define BLEUmesh      0x0000ff00
#define dBLEUmesh     8
#define RAZRGBmesh    0x000000ff
#define ALPHAmesh     0x000000ff
#define RAZALPHAmesh  0xffffff00
#define dALPHAmesh    0
#define DEFAULT0mesh  0x00020002
#define DEFAULT1mesh  0xffffffff


#include "CATVisItf.h"
#include "CATBaseUnknown.h"
#include "CATShowMode.h"
#include "CATPickMode.h"
#include "CATDataType.h"

class CATIMeshGraphicProperties_var;

union DULL 
{ 
  double dvalue; 
  CATULONG32 ullvalue[2];
};

class ExportedByCATVisItf CATMeshGraphicAttribut : public CATBaseUnknown
{
  CATDeclareClass;
  public:
  ///////
    
    CATMeshGraphicAttribut ();
    CATMeshGraphicAttribut (double value);
    virtual ~CATMeshGraphicAttribut (void) ;

    double GetValue();   
    DULL GetDULLValue();

    virtual void SetColor     (int red, int green, int blue);
    virtual int  GetColor     (int &red, int &green, int &blue);

    virtual void SetOpacity   (int coeff);
    virtual int  GetOpacity   ();

    virtual void SetShowMode  (CATShowMode showmode);
    virtual CATShowMode  GetShowMode ();

    virtual void SetPickMode  (CATPickMode pickmode);
    virtual CATPickMode  GetPickMode ();

    virtual void SetValue ( CATIMeshGraphicProperties_var &value );

    virtual HRESULT MigrateToVisProperties (int iGeomType);

    
  private:
  ////////

    DULL _value;
};

#endif
