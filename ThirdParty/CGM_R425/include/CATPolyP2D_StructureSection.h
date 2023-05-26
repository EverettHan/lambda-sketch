//
//============================================================================================
// Copyright Dassault Systemes Provence 2010 - 2011 All Rights Reserved
//============================================================================================
//
// CATPolyP2D_StructureSection.h
// Header definition of CATPolyP2D_StructureSection
//
//============================================================================================
//
// Usage notes: Structure d'une section de coupe d'un Mesh pour recherche d'un Fillet
//              Necessaire car visible dans 2 classes differentes :
//					CATPolyP2D_RecognizeFilletV_2 et CATPolyP2D_FilletSegmentation_C4R
//
//============================================================================================
// 10/10/2011 : GDD : Creation
//============================================================================================
#ifndef CATPolyP2D_StructureSection_H
#define CATPolyP2D_StructureSection_H

// -------------------------------------------------------------
// Definition de la structure de donnees pour un section du Mesh
// On recupere un pointeur vers la table des structures avec un 
//                 GetPtrStructureSection
// -------------------------------------------------------------
struct SectionOnVertex {
    // On ordonne par taille decroissante du champ
    double          _ErrQua;     // Erreur quadratique sur la reconnaissance du cercle de cette section
    double          _Rayon;      // Rayon du cercle
    CATMathPoint    _Centre;     // Centre du cercle
    CATMathVector   _Normale;    // Normale au plan definissant le cercle ou plan de la section

    int             _NumVtx;     // Numero du vertex sur lequel la section a ete calculee 
                                 // Si <= 0 Cette section n'est pas valide pour qque raison que ce soit
    double          _AngleOuverture; // Angle d'ouverture maximum des section au vertex
    CATListOfDouble *_LstPointResult; // Liste des points de la meilleur section au vertex
    int             _VtxRef;     // Numero de vertex auquel le vertex fait reference
                                 // -1 si c'est un pere, le numero du pere sinon

    // CONSTRUCTOR
    SectionOnVertex() : _ErrQua(-1.), _Rayon(-1.), _NumVtx(-1), _LstPointResult(NULL), _AngleOuverture(-1), _VtxRef(-1) {
    } ;
    // DESTRUCTOR
    ~SectionOnVertex() {
      if(_LstPointResult != NULL && _VtxRef == -1) {
        _LstPointResult ->RemoveAll();
        delete _LstPointResult;
        _LstPointResult = NULL;
      }
    }
} ;

#endif
