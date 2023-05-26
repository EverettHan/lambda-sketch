#ifndef CATIAsmGRAPHICPROPERTIES_H
#define CATIAsmGRAPHICPROPERTIES_H
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1997
//
//----------------------------------------------------------------
//
// Abstract :  interface auquelle doit souscrire un objet modele
// ----------  de type Asm ( feuille d'assemblage ) et qui pointe
//             sur une part multi instanciee.
//            
//             la gestion des attributs graphiques se fait par heritage 
//             pour ces objets specifiques . ( l'information n'est pas
//             propagee sur les fils car les donnees d'une part ( qui
//             est multi referencee ) ne doivent pas etre touchees )
//
//-----------------------------------------------------------------
//
//  Usage :    cette interface est implemente sur les feuilles
//  -------    d'assemblage 
//           
//
//-----------------------------------------------------------------
//
//  Inheritance :   CATIAsmGraphicProperties
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

#define AsmNoHeritage -1

class CATIAsmGraphicProperties_var;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATVisItf IID IID_CATIAsmGraphicProperties;
#else
extern "C" const IID IID_CATIAsmGraphicProperties;
#endif

class ExportedByCATVisItf CATIAsmGraphicProperties : public CATBaseUnknown
{
  CATDeclareInterface;

  public :
  ////////
 
  virtual void SetColor     ( int red,  int green,  int blue, 
                              int inheritance = 0 ) = 0; 

  virtual void ResetColor   () = 0;
  virtual int  GetColor     (int &red, int &green, int &blue) = 0; 

  virtual void SetOpacity   ( int coeff) = 0;
  virtual int  GetOpacity   () = 0;

  virtual void SetLineType  ( int linetype, int inheritance = 0 ) = 0;
  virtual void ResetLineType   () = 0;
  virtual int  GetLineType  ( int &lineType ) = 0;

  virtual void SetThickness ( int thickness, int inheritance = 0 ) = 0;
  virtual void ResetThickness   () = 0;
  virtual int  GetThickness ( int &thickness ) = 0;

  virtual void SetShowMode  ( CATShowMode showmode) = 0;
  virtual CATShowMode  GetShowMode () = 0;

  virtual void SetPickMode  ( CATPickMode pickmode) = 0;
  virtual CATPickMode  GetPickMode () = 0;

  virtual void SetValue ( CATIAsmGraphicProperties_var &value ) = 0;

  virtual int IsAssociatedToShape() = 0;

  virtual HRESULT MigrateToVisProperties (int iGeomType) = 0;
}; 

CATDeclareHandler(CATIAsmGraphicProperties,CATBaseUnknown);

#endif
