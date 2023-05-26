//=========================================================================
// Copyright Dassault Systemes Provence 2010, All Rights Reserved
//=========================================================================
//
// CATSobListVOfGraphicMaterial.h
//
//=========================================================================
//
// Usage notes: List of CATSobGraphicMaterial objects (graphic materials).
//
//=========================================================================
// May,   2010 : RAQ : Cr�ation
//=========================================================================
#ifndef CATSobListVOfGraphicMaterial_H
#define CATSobListVOfGraphicMaterial_H

//Pour l'export
#include "CATSobObjects.h"

//Objets � mettre dans la liste
#include "CATSobGraphicMaterial.h"

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

#ifdef CATCOLLEC_ExportedBy
  #undef CATCOLLEC_ExportedBy
#endif  //CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATSobObjects

CATLISTV_DECLARE_TN(CATSobGraphicMaterial, CATSobGraphicMaterial)

typedef CATListValCATSobGraphicMaterial CATSobListVOfGraphicMaterial;


#endif



