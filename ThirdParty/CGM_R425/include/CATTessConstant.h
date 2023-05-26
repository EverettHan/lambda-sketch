#ifndef CATTESSCONSTANT_H
#define CATTESSCONSTANT_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATTESSConstant : special class for defining constants with a limited
// visibility for the framework Tesselate
//
// DESCRIPTION : there is no implementation. This is used to have constants
// by CATTessConstant::...
//
//=============================================================================
// Abstract Class     : Yes
//=============================================================================
//
// History
//
// Jan. 98   Jose CHILLAN (jch)    Creation            
// Mai  2000 TPD ajout de POINTS sur l'autre face
// Oct. 2001 TPD ajout de "PtsUvCal", On differencie les points deja calcules 
// Nov. 2001 TPD Harmonisation de tolerances suppression de "TolCoeff" (RI313379)
// Juin 2002 TPD Pour les Edges degenerees on rend un Point lie a la face (RI_CD_10)
// Jui. 2002 TPD Mise en place de point PtsFictifXXXCal, On differencie les points deja calcules (RI352424)
// Jui. 2002 TPD on genere logiquement des Fans sur les "vertex"
// Dec. 2002 TPD On reutilise les objets supprimes
// Jan. 2003 TPD Il ne faut pas garder toutes les Isopares avec "CalIso" (RI378263)
// Mai  2003 TPD On garde les coordonnees des points des faces dans "CATTessSToreDisplay " pour les edges
//               en fonction des faces 
// Nov. 2003 TPD suppression de "CATTessInfinity.h"
// Dec. 2003 TPD On essaye de simplifier les contours Qcq en fin de traitement (RI421853)
// Jan. 2004 TPD On teste les normales des triangles Adjacents (RI404421)
// Fev. 2004 TPD test dans le mauvais sens pour des "for". Creation de "AssMal" (RI439098)
// Mars 2004 TPD On chaine les Points Bords de faces entre eux par les CATTessPoints correspondants
// Mai  2004 TPD On modifie le Coefficient de TolUv2 dans "BarreInterne" et "ChercBarreConf" (RI445685)
// Juil 2004 TPD mise en place de "Stat" pour la CPU
// Aout 2004 TPD On interpole le XYZ pour les points fictifs (RI461185)
// Sep. 2004 TPD Creation des barres "BarDegenUvFic" (ODT MfgTstZipMillJob_1)
// Nov. 2004 TPD choix du point a garder pour les trous (RI472074)
// Jan. 2005 TPD On calcule le VRAI point sur l'edge (RI489565)
// Juin 2005 TPD Mise en place d'un coefficient pour les barres horizontales (RI491555)
// Oct. 2005 TPD Creation du type de point "PtsVertexAjou" 
// Nov. 2005 TPD Suppression du type "BarIsoRel" (Tess_0002)
// Dec. 2005 MNA Ajout du type AsscontPP2D
// Fev. 2006 TPD Nouveau type PointIso (RI524736)
// Mars 2006 TPD Modification du test de comparaison entre reels
// Avr. 2006 TPD creation de "PtsVertexSing"
//
//=============================================================================

#include "CATMathConstant.h"
#include "CATDataType.h"
 

class CATTessConstant
{
public:
 

  // Type de donnees en sortie de la tessellation de courbes
  //                           0 : liste de "CATMathSetOfPointsND"
  //                           1 : liste de "float"
  //                           2 : liste de "double"
  //                           3 : liste d'indice de points dans une face adjacente ou de "CATMathSetOfPointsND"
  //                           4 : liste d'indice de points dans une face adjacente ou de "float"
  //                           5 : liste d'indice de points dans une face adjacente ou de "double"
  enum CurveOutputFormat { AsPoints, AsFloats, AsDoubles, AsPointsFace, AsPointsFaceP = AsPointsFace
			 , AsPointsFaceF, AsPointsFaceD , AsFloatsUV};
  
  // Type de donnees en sortie de la tessellation de vertex
  //                           0 : "CATMathPoints"
  //                           1 : liste d'indice de points dans les faces adjacentes ou du "CATMathPoints" si pas de Face
  //                           2 : liste d'indice de points dans les faces adjacentes ou de "Poec" si pas de Face
  //                           3 : liste de Xyz des Poec 
  enum VertexOutputFormat { VertexAsPoints, VertexAsPointsFaceM, VertexAsPointsFaceP, VertexAsPoec };
 
  
private:
  // Disable the instanciation of the class
  CATTessConstant();
  ~CATTessConstant();
  
};

//=============================================================================
// UNUSED INLINE IMPLEMENTATION (but needed on NT)
//=============================================================================
inline CATTessConstant::CATTessConstant()
{
  // Nothing to do
}

inline CATTessConstant::~CATTessConstant()
{
  // Nothing to do
}

#endif
