//======================================================================
// Copyright Dassault Systemes Provence 2009, All rights reserved
//======================================================================
//
// CATSobBitSet.h
//
//======================================================================
//
// Usage notes: Champ de bits (inspir� de CATPolyBitSet)
//
//======================================================================
// November,    2009 : RAQ : Cr�ation
//======================================================================
#ifndef CATSobBitSet_H
#define CATSobBitSet_H

//Pour l'export
#include "ExportedByCATSobUtilities.h"

//Divers
#include "CATBoolean.h"

#define STATIC_BIT_FIELD_BYTE_SIZE  8


class ExportedByCATSobUtilities CATSobBitSet
{
public:

  //Constructeur
  CATSobBitSet();
  CATSobBitSet(const unsigned int iEstimatedNbElem);

  //Destructeur
  ~CATSobBitSet();

  //Set d'un bit, l'index commence � 0
  void Set(const unsigned int iBitIndex, const CATBoolean iValue);

  //Etat d'un bit
  CATBoolean Test(const unsigned int iBitIndex) const;

  //Set de tous les bits actuellement allou�s � une valeur donn�e
  void SetAllBits(const CATBoolean iValue);

protected:

  //Redimensionnement, renvoie TRUE si pas d'erreur
  CATBoolean Resize(const unsigned int iMinBytesNumber, const CATBoolean iMoveData = TRUE);

  //Calcul du nombre d'octets n�cessaires pour un nombre d'�l�ments donn�s
  unsigned int GetNbBytes(const int iNbElems);



  //-------- Data:
  unsigned char _StaticBitField[STATIC_BIT_FIELD_BYTE_SIZE];
  unsigned char* _BitField;
  int _MaxByteSize;
  CATBoolean _UseStaticBitField;
};


#endif

