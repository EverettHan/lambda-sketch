//=================================================================================
// Copyright Dassault Systemes Provence 2009, All Rights Reserved
//=================================================================================
//
// CATSobHashTableBaseIterator.h
//
//=================================================================================
//
// Usage notes: It�rateur de base pour les hash tables.
//
//=================================================================================
// December,  2009 : RAQ : Creation
//=================================================================================
#ifndef CATSobHashTableBaseIterator_H
#define CATSobHashTableBaseIterator_H

//Pour l'export
#include "ExportedByCATSobUtilities.h"

//Divers
#include "CATBoolean.h"

class CATSobHashTableBase;
class CATSobHashTableAtomBase;


class ExportedByCATSobUtilities CATSobHashTableBaseIterator
{
public:

  //Gestion r�f�rences
  int AddRef();
  void Release();


protected:

  //Constructeur
  CATSobHashTableBaseIterator(const CATSobHashTableBase* iHashTableBase);

  //Destructeur
  virtual ~CATSobHashTableBaseIterator();

  //Replace l'it�rateur au d�but
  void Begin();

  //Test si l'it�raeur est � la fin
  CATBoolean End() const;

  //Incr�mente l'it�rateur
  virtual void operator++();  //pre increment
  virtual void operator++(int); //post increment

  //R�cup�re l'�lement actuellement point� par l'it�rateur
  CATSobHashTableAtomBase* GetElem() const;

private:

  //Pas d'impl�mentation par d�faut
  CATSobHashTableBaseIterator(const CATSobHashTableBaseIterator&);
  CATSobHashTableBaseIterator& operator=(const CATSobHashTableBaseIterator&);


  //---------- Data:
  int _RefCounter, _CurrentElemRank;
  const CATSobHashTableBase* _HashTableBase;
  CATSobHashTableAtomBase* _CurrentAtom;
};


#endif


