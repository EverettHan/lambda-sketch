//====================================================================
// Copyright Dassault Systemes Provence 2009, All Rights Reserved 
//====================================================================
//
// CATSmoListVOfAncestorFace.h
//
//====================================================================
//
// Usage notes: Liste de faces anc�tres pour le suivi topologique.
//
//====================================================================
// November,   2009 : RAQ : Cr�ation
//====================================================================
#ifndef CATSmoListVOfAncestorFace_H
#define CATSmoListVOfAncestorFace_H

//Pour l'export
#include "CATSmoOperators.h"

//Objet
#include "CATSmoAncestorFace.h"

//D�finition des m�thodes disponibles
#include "CATLISTV_Clean.h"

#define CATLISTV_MinimalFunct //Permet de ne pas avoir � d�finir les op�rateurs == et !=
#undef CATLISTV_eqOP  
#undef CATLISTV_neOP  

#define CATLISTV_Append
#define CATLISTV_AppendList
#define CATLISTV_RemoveAll
#define CATLISTV_RemovePosition
#define CATLISTV_InsertAt

#include "CATLISTV_Declare.h"

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATSmoOperators

CATLISTV_DECLARE(CATSmoAncestorFace)
typedef CATListValCATSmoAncestorFace CATSmoListVOfAncestorFace;

#undef CATCOLLEC_ExportedBy

#endif

