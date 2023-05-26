/* -*-C++-*-*/
#ifndef CATTessIsoIter_H
#define CATTessIsoIter_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATTessIsoIter 
//
// DESCRIPTION :
/**
  * Parcourt des Isopares d'une CATTessFace
  */
//
// Main Methods :
//  
//=============================================================================
// Abstract Class     : No
// Inline Functions   : Yes
//=============================================================================
//
// History
//
// Fév. 98   Thierry PICARD (tpd)    Création
// Aout 2003 TPD passage en 64 bits 
// Dec. 2005 TPD On teste si on a bien tout rempli dans "GetIsoNuPts" (RI517973)
//
//=============================================================================

// For Windows NT
#include "TessAPI.h"

class CATTessFace;
class CATTessAssCont;
class CATTessContour;

#include "CATIsoParameter.h"
#include "CATCGMNewArray.h"
#include "CATDataType.h"

class ExportedByTessAPI CATTessIsoIter
{
public:
  //=============================================================================
  // CONSTRUCTOR
  //=============================================================================
  CATTessIsoIter();

  /** @nodoc */
  CATCGMNewClassArrayDeclare;
  
  //=============================================================================
  // SET AND GET METHODS
  //=============================================================================

  /**
   * On Initialise l'itérateur pour une Face
   */
  virtual void Initialize(CATTessFace * iFace);

  /**
   * On rend le Nombre d'Isopares et le nombre total de points pour la face
   */
  inline CATLONG32 GetNbIso( CATLONG32 & oNbPtsAll ) const;

  /**
   * On rend le type de l'Isopare courante
   */
  virtual CATIsoParameter GetIsoparam() const;

  /**
   * On rend le Nombre de Points de l'Isopare courante
   */
  virtual CATLONG32 GetIsoNbPts();

  /**
   * On rend les Numéros des Points de l'Isopare courante
   * Rq : Le contour est fermé, le premier et le dernier points sont différents
   * Rq : Le tableau oNuPts doit être correctement dimensionné grace
   *      à la méthode "GetIsoNbPts"
   */
#ifndef PLATEFORME_DS64
  virtual void GetIsoNuPts(CATLONG32 oNuPts[]) const;
#endif
  virtual void GetIsoNuPts(int  oNuPts[]) const;

  /**
   * On rend les Numéros des Points de toutes les Isopares
   * Rq : Les tableaux oNbPts et oNuPts doit être correctement dimensionné grace
   *      à la méthode "GetNbIso" ( oNbPts[GetNbIso()] et oNuPts[oNbPtsAll] ) 
   */
  virtual void GetIsoAllNuPts(int oNbPts[], int oNuPts[]) const;

  /**
   * On passe à l'Isopare courante
   */
  virtual void GoToNext();

  /**
   * On repart au début de la Face
   */
  virtual void Reset();

  /** Returns 1 if the list is exhausted.
 */
  virtual CATLONG32 IsExhausted() const;

  
  //=============================================================================
  // INTERNAL DATAS
  //=============================================================================
protected:
  // Adresse de la Face
  CATTessFace    * _Face;
  // AssCont courant
  CATTessAssCont * _AssContCurrent;
  // Contour courant
  CATTessContour * _ContourCurrent;

  // Nombre d'Isopares
  CATLONG32        _NbIso;
  // Numero de l'isopare courante
  CATLONG32        _iIso;
  // Nombre total de points
  CATLONG32        _NbPtsAll;
  // Nombre de Point pour l'Isopare courante
  CATLONG32        _NbPts;

};

//=============================================================================
// INLINE IMPLEMENTATIONS 
//=============================================================================

inline CATLONG32 CATTessIsoIter::GetNbIso( CATLONG32 & NbPtsAll ) const
{
  NbPtsAll = _NbPtsAll;
  return _NbIso;
}

#endif
