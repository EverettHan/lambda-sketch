#ifndef CATModelGraphicAttribut_h
#define CATModelGraphicAttribut_h

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
//  Usage: used by object which implement CATIGraphicProperties 
//  ------ 
//
//********************************************************************
//
//  Inheritance:
//  ------------
//              CATModelGraphicAttribut
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
//  nocol/NP/S Type Point Epai Ligne Type Ligne
// !----------!----------!----------!----------!
// ! 00000001 ! 00000001 ! 00000001 ! 00000001 !
// !----------!----------!----------!----------!
//
//      Rouge       Vert      Bleu      Opacite
// !----------!----------!----------!----------!
// ! 11111111 ! 11111111 ! 11111111 ! 11111111 !
// !----------!----------!----------!----------!
//
//  NoColor         : 0 --> couleur non herite, 1 --> couleur herite
//  no pick         : 0 --> Pick , 1 --> NoPick
//  Show            : 0 --> Non Vu , 1 --> Neutre, 2 --> Vu
//  Type Point      : 0 - 255 indice du type de point
//  Epaisseur ligne : 0 - 255 indice de l'epaisseur de la ligne
//  Type ligne      : 0 - 255 indice du type de la ligne
//  Rouge           : 0 - 255 valeur du rouge
//  Vert            : 0 - 255 valeur du vert
//  Bleu            : 0 - 255 valeur du bleu
//  Opacite         : 0 - 255 valeur de la transparence ( 0 ==> 
//                       completement transparent , 255 ==> completement opaque)

#define NONECOLOR  0xf0000000
#define RAZNOCOLOR 0x0fffffff
#define SHOW      0x03000000
#define RAZSHOW   0xfcffffff
#define NOPICK    0x0c000000
#define RAZNOPICK 0xf3ffffff
#define TPOINT    0x00ff0000
#define RAZTPOINT 0xff00ffff
#define ELINE     0x0000ff00
#define RAZELINE  0xffff00ff
#define TLINE     0x000000ff
#define RAZTLINE  0xffffff00
#define ROUGE     0xff000000
#define VERT      0x00ff0000
#define BLEU      0x0000ff00
#define RAZRGB    0x000000ff
#define ALPHA     0x000000ff
#define RAZALPHA  0xffffff00
#define DEFAULT0  0x01010101
#define DEFAULT1  0xffffffff
#define MODEVISUsurfacic 0x000000ff
#define UNUMBERsurfacic  0x0000ff00
#define VNUMBERsurfacic  0x00ff0000


#include "SceneGraphManager.h"
#include "CATBaseUnknown.h"
//#include "CORBAAnyDef.h"
#include "CATShowMode.h"
#include "CATPickMode.h"
#include "CATDataType.h" 
class ExportedBySceneGraphManager CATModelGraphicAttribut : public CATBaseUnknown
{
  public:
  ///////
    
    CATModelGraphicAttribut ();
    CATModelGraphicAttribut (double value);
    virtual ~CATModelGraphicAttribut (void) ;

    double GetValue();   
    void SetColor     (int red, int green, int blue);
    void ResetColor();
    int  GetColor     (int &red, int &green, int &blue);

    void SetOpacity   (int coeff);
    int  GetOpacity   ();

    void SetLineType  (int linetype);
    int  GetLineType  ();

    void SetThickness (int thickness);
    int  GetThickness ();

    void SetPointType (int pointtype);
    int  GetPointType ();

    void SetShowMode  (CATShowMode showmode);
    CATShowMode  GetShowMode ();

    void SetPickMode  (CATPickMode pickmode);
    CATPickMode  GetPickMode ();

    void SetVisualizationMode(int mode);
    int  GetVisualizationMode();

    void SetIsoparsNumberInU(int number);
    int  GetIsoparsNumberInU();

    void SetIsoparsNumberInV(int number);
    int  GetIsoparsNumberInV();

    
  private:
  ////////

    union DULL 
    { 
      double dvalue; 
      CATULONG32 ullvalue[2];
    };
    DULL _value;
};

#endif
