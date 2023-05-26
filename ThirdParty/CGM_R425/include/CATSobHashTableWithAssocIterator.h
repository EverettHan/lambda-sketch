//=================================================================================
// Copyright Dassault Systemes Provence 2009, All Rights Reserved
//=================================================================================
//
// CATSobHashTableWithAssocIterator.h
//
//=================================================================================
//
// Usage notes: It�rateur pour les hash tables de type CATSobHashTableWithAssoc.
//
//=================================================================================
// December,  2009 : RAQ : Creation
//=================================================================================
#ifndef CATSobHashTableWithAssocIterator_H
#define CATSobHashTableWithAssocIterator_H

//Pour l'export
#include "ExportedByCATSobUtilities.h"

//Classe m�re
#include "CATSobHashTableBaseIterator.h"


class ExportedByCATSobUtilities CATSobHashTableWithAssocIterator: public CATSobHashTableBaseIterator
{
public:

  //Replace l'it�rateur au d�but
  virtual void Begin() = 0;

  //Test si l'it�raeur est � la fin
  virtual CATBoolean End() const = 0;

  //Incr�mente l'it�rateur
  virtual void operator++(int) = 0;

  //R�cup�re l'�lement actuellement point� par l'it�rateur
  virtual void* GetElem() const = 0;

  //R�cup�re l'association de l'�lement actuellement point� par l'it�rateur
  virtual void* GetAssoc() const = 0;

  //R�cup�re l'�lement et l'association actuellement point�s par l'it�rateur
  virtual void GetElemAndAssoc(void*& oElem, void*& oAssoc) const = 0;


protected:

  //Constructeur
  CATSobHashTableWithAssocIterator(const CATSobHashTableBase* iHashTableBase):CATSobHashTableBaseIterator(iHashTableBase) {}

  //Destructeur
  virtual ~CATSobHashTableWithAssocIterator() {}

private:

  //Pas d'impl�mentation par d�faut
  CATSobHashTableWithAssocIterator(const CATSobHashTableWithAssocIterator&);
  CATSobHashTableWithAssocIterator& operator=(const CATSobHashTableWithAssocIterator&);

};

#endif

