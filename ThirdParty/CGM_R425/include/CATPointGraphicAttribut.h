#ifndef CATPointGraphicAttribut_h
#define CATPointGraphicAttribut_h

// COPYRIGHT DASSAULT SYSTEMES 1999


//********************************************************************
// CATIA Framework CATIAModelVisu (PPE)
// Copyright Dassault Systemes 1997
//********************************************************************
//
//  Abstract:
//  ---------
//    This defines the point graphic attribut 
//    
//
//********************************************************************
//
//  Usage: used by object which implement CATIPointGraphicProperties 
//  ------ 
//
//********************************************************************
//
//  Inheritance:
//  ------------
//              CATPointGraphicAttribut
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
//      Rouge       Vert      Bleu    point type / pick / show 
// !----------!----------!----------!----------!
// ! 11111111 ! 11111111 ! 11111111 ! 00000111 !
// !----------!----------!----------!----------!
//
//  pick            : 1 --> Pick , 0 --> NoPick
//  Show            : 1 --> Vu , 0 non Vu
//  Type Point      : 1 - 32 indice du type de point
//  Rouge           : 0 - 255 valeur du rouge
//  Vert            : 0 - 255 valeur du vert
//  Bleu            : 0 - 255 valeur du bleu

/** @nodoc */
#define SHOWpoint      0x00000001
/** @nodoc */
#define RAZSHOWpoint   0xfffffffe
/** @nodoc */
#define dSHOWpoint     0
/** @nodoc */
#define PICKpoint      0x00000002
/** @nodoc */
#define RAZPICKpoint   0xfffffffd
/** @nodoc */
#define dPICKpoint     1
/** @nodoc */
#define TPOINTpoint    0x000000fc
/** @nodoc */
#define RAZTPOINTpoint 0xffffff03
/** @nodoc */
#define dTPOINTpoint   2
/** @nodoc */
#define ROUGEpoint     0xff000000
/** @nodoc */
#define dROUGEpoint    24
/** @nodoc */
#define VERTpoint      0x00ff0000
/** @nodoc */
#define dVERTpoint     16
/** @nodoc */
#define BLEUpoint      0x0000ff00
/** @nodoc */
#define dBLEUpoint     8
/** @nodoc */
#define RAZRGBpoint    0x000000ff
/** @nodoc */
#define DEFAULTpoint   0xffffff07


#include "CATVisItf.h"
#include "CATBaseUnknown.h"
#include "CATShowMode.h"
#include "CATPickMode.h"
#include "CATIVisProperties.h"

class CATIPointGraphicProperties_var;



/**
* Class CATPointGrahicAttribut.
*
* Manage attributs values for a point representation :
* <ol>
*   <li>Color         </li>
*   <li>Point type    </li>
*   <li>Show          </li>
*   <li>Pick          </li>
* </ol>
*
*/
class ExportedByCATVisItf CATPointGraphicAttribut : public CATBaseUnknown
{
  CATDeclareClass;


   
  /**
  * Default constructor.
  */
  CATPointGraphicAttribut ();

  /**
  * Constructor with a default value.
  *
  * @param iValue
  *        The default attribut value.
  */
  CATPointGraphicAttribut (unsigned long iValue);


  virtual ~CATPointGraphicAttribut () ;
  


  /**
  * Get the attribut value.
  *
  * @return
  *        The attribut value.
  */
  unsigned long GetValue();   
  

  /**
  * Set color attribut.
  * <br><b>Role</b> : set three components of color : red, green, blue.
  *
  * @param iRed
  *        Red value.
  *
  * @param iGreen
  *        Green value.
  *
  * @param iBlue
  *        Blue value.
  */
  virtual void SetColor     (int iRed, int iGreen, int iBlue);


  /**
  * Get color attribut.
  * <br><b>Role</b> : get three components of color : red, green, blue.
  *
  * @param iRed
  *        Red value.
  *
  * @param iGreen
  *        Green value.
  *
  * @param iBlue
  *        Blue value.
  *
  * @return
  *   <br><b>Legal values</b>:
  *   <dl>
  *     <dt>1</dt>
  *     <dd>if the color exist</dd>
  *     <dt>0</dt>
  *     <dd>if the color attribut couldn't be get</dd>
  *   </dl>
  */
  virtual int  GetColor     (int &oRed, int &oGreen, int &oBlue);
  

  /**
  * Set type of point.
  * <br><b>Role</b> : set the attribut type of point.
  *
  * @param iPointType
  *        The type of point.
  */
  virtual void SetPointType (int iPointType);


  /**
  * Get type of point.
  * <br><b>Role</b> : get the attribut type of point.
  *
  * @return
  *        The type of point.
  */
  virtual int  GetPointType ();
  

  /**
  * Set show mode attribut.
  * <br><b>Legal values</b> : see @href CATShowMode.
  */
  virtual void SetShowMode  (CATShowMode showmode);

  /**
  * Get show mode attribut.
  *
  * @return
  *        The show attribut.
  *        <br><b>Legal values</b> : see @href CATShowMode.
  */
  virtual CATShowMode  GetShowMode ();
  

  /**
  * Set pick mode attribut.
  * <br><b>Legal values</b> : see @href CATPickMode.
  */
  virtual void SetPickMode  (CATPickMode pickmode);

  /**
  * Get pick mode attribut.
  *
  * @return
  *        The pick attribut.
  *        <br><b>Legal values</b> : see @href CATPickMode.
  */
  virtual CATPickMode  GetPickMode ();
  

  /**
  * @nodoc
  */
  virtual void SetValue ( CATIPointGraphicProperties_var &value );

  /**
  * @nodoc
  */
  virtual HRESULT MigrateToVisProperties (CATVisGeomType iGeomType);
  
private:
  
  unsigned long _value;

};

#endif

