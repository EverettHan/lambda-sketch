#ifndef CATAsmGraphicAttribut_h
#define CATAsmGraphicAttribut_h

//********************************************************************
// CATIA Framework CATIAModelVisu (PPE)
// Copyright Dassault Systemes 1997
//********************************************************************
//
//  Abstract:
//  ---------
//    This defines the graphic attribut for instance object ( dittos
//    in V4, or ASM part in CNEXT
//
//********************************************************************
//
//  Usage: used by object which implement CATIAsmGraphicProperties 
//  ------ 
//
//********************************************************************
//
//  Inheritance:
//  ------------
//              CATAsmGraphicAttribut
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
//                    herit+linetype/herit+thickness  heritage couleur/pick/show
// !----------!----------!----------!----------!
// ! 00000000 ! 00000000 ! 00010001 ! 00010111 !
// !----------!----------!----------!----------!
//
//      Rouge       Vert      Bleu      Opacite
// !----------!----------!----------!----------!
// ! 11111111 ! 11111111 ! 11111111 ! 11111111 !
// !----------!----------!----------!----------!
//
//  thickness       : 0 - 7
//  heritage thick  : 1 --> heritage
//  linetype        : 0 - 7
//  heritage linety : 1 --> heritage
//  pick            : 1 --> Pick , 0 --> no Pick
//  Show            : 2 --> CATNeutral, 1 --> CATShow , 0 --> CATNoShow
//  Rouge           : 0 - 255 valeur du rouge
//  Vert            : 0 - 255 valeur du vert
//  Bleu            : 0 - 255 valeur du bleu
//  color           : 1 --> heritage
//  Opacite         : 0 - 255 valeur de la transparence ( 0 ==> 
//                       completement transparent , 255 ==> completement opaque)

#define SHOWasm       0x00000003
#define RAZSHOWasm    0xfffffffc
#define dSHOWasm      0
#define PICKasm       0x00000004
#define RAZPICKasm    0xfffffffb
#define dPICKasm      2
#define LINETHasm     0x00000700
#define RAZLINETHasm  0xfffff8ff
#define dLINETHasm    8
#define herLINETHasm     0x00000800
#define RAZherLINETHasm  0xfffff7ff
#define dherLINETHasm    11
#define LINETYasm     0x00007000
#define RAZLINETYasm  0xffff8fff
#define dLINETYasm    12
#define herLINETYasm     0x00008000
#define RAZherLINETYasm  0xffff7fff
#define dherLINETYasm    15
#define herCOLasm     0x00000010
#define RAZherCOLasm  0xffffffef
#define dherCOLasm    4
#define ROUGEasm      0xff000000
#define dROUGEasm     24
#define VERTasm       0x00ff0000
#define dVERTasm      16
#define BLEUasm       0x0000ff00
#define dBLEUasm      8
#define RAZRGBasm     0x000000ff
#define ALPHAasm      0x000000ff
#define RAZALPHAasm   0xffffff00
#define dALPHAasm     0
#define DEFAULT0asm   0x00001105
#define DEFAULT1asm   0xffffffff


#include "CATVisItf.h"
#include "CATBaseUnknown.h"
#include "CATShowMode.h"
#include "CATPickMode.h"
#include "CATDataType.h"

class CATIAsmGraphicProperties_var;

union DOULL 
    { 
      double dvalue; 
      CATULONG32 ullvalue[2];
    };

class ExportedByCATVisItf CATAsmGraphicAttribut : public CATBaseUnknown
{
  CATDeclareClass;


  public:
  ///////
    CATAsmGraphicAttribut ();
    CATAsmGraphicAttribut (double value);
    virtual ~CATAsmGraphicAttribut (void) ;

    double GetValue();   
    DOULL GetDULLValue();
    virtual void SetColor     (int red, int green, int blue,
                               int inheritance = 0 );

    virtual void ResetColor();
    virtual int  GetColor     (int &red, int &green, int &blue);

    virtual void SetOpacity   (int coeff);
    virtual int  GetOpacity   ();

    virtual void SetLineType  ( int linetype, int inheritance = 0 );
    virtual void ResetLineType   ();
    virtual int  GetLineType  ( int &lineType );
  
    virtual void SetThickness ( int thickness, int inheritance = 0 );
    virtual void ResetThickness   ();
    virtual int  GetThickness ( int &thickness );

    virtual void SetShowMode  (CATShowMode showmode);
    virtual CATShowMode  GetShowMode ();

    virtual void SetPickMode  (CATPickMode pickmode);
    virtual CATPickMode  GetPickMode ();

    virtual void SetValue ( CATIAsmGraphicProperties_var &value );

    virtual int IsAssociatedToShape();
   
    virtual HRESULT MigrateToVisProperties (int iGeomType);

  private:
  ////////

    DOULL _value;
};

#endif
