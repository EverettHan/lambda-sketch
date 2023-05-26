//=================================================================================
// Copyright Dassault Systemes Provence 2009, All Rights Reserved
//=================================================================================
//
// CATSobHashTableIterator.h
//
//=================================================================================
//
// Usage notes: It�rateur pour les hash tables de type CATSobHashTable.
//
//=================================================================================
// December,  2009 : RAQ : Creation
//=================================================================================
#ifndef CATSobHashTableIterator_H
#define CATSobHashTableIterator_H

//Pour l'export
#include "ExportedByCATSobUtilities.h"

//Classe m�re
#include "CATSobHashTableBaseIterator.h"

//Divers
#include "CATBoolean.h"


class ExportedByCATSobUtilities CATSobHashTableIterator: public CATSobHashTableBaseIterator
{
public:

  //Replace l'it�rateur au d�but
  virtual void Begin() = 0;

  //Test si l'it�raeur est � la fin
  virtual CATBoolean End() const = 0;

  //Incr�mente l'it�rateur
  virtual void operator++() = 0;  //pre increment
  virtual void operator++(int) = 0; //post increment

  //R�cup�re l'�lement actuellement point� par l'it�rateur
  virtual void* GetElem() const = 0;


protected:

  //Constructeur
  CATSobHashTableIterator(const CATSobHashTableBase* iHashTableBase):CATSobHashTableBaseIterator(iHashTableBase) {}

  //Destructeur
  virtual ~CATSobHashTableIterator() {}

private:

  //Pas d'impl�mentation par d�faut
  CATSobHashTableIterator(const CATSobHashTableIterator&);
  CATSobHashTableIterator& operator=(const CATSobHashTableIterator&);

};

#endif

