//=================================================================================
// Copyright Dassault Systemes Provence 2009, All Rights Reserved
//=================================================================================
//
// CATSobHashTableBase.h
//
//=================================================================================
//
// Usage notes: Classe de base pour les hash tables.
//
//=================================================================================
// 30.01.2018 : RAQ : Optimisation perfos
// December,  2009 : RAQ : Creation
//=================================================================================
#ifndef CATSobHashTableBase_H
#define CATSobHashTableBase_H

//Pour l'export
#include "ExportedByCATSobUtilities.h"

//Divers
#include "CATBoolean.h"
#include "CATDataType.h"

class CATSobHashTableAtomBase;
class CATSobHashTableBaseIterator;

class ExportedByCATSobUtilities CATSobHashTableBase
{
public:

  //Constructeurs
  CATSobHashTableBase();
  CATSobHashTableBase(const unsigned int iEstimatedSize);

  //Destructeur
  virtual ~CATSobHashTableBase();

  /********************* SERVICES *********************/
  //Test d'appartenance
  virtual CATBoolean Contains(const void* iElem) const;

  //Suppression d'un �l�ment
  virtual void Remove(const void* iElem);

  //Acc�s � un �l�ment par rang
  CATBoolean GetElem(const int iIndex, void*& oElem) const;
  /****************************************************/

  //Suppression de tous les �l�ments
  void RemoveAll();

  //R�cup�ration du nombre d'�l�ments
  int GetNbElems() const { return _NbElems; }

protected:

  /********************* A IMPLEMENTER *********************/
  //Allocation du tableau interne + initialisation du tableau � 0
  virtual CATSobHashTableAtomBase** Allocate(const int iSize) const = 0;

  //Cr�ation d'un �l�ment pour insertion
  virtual CATSobHashTableAtomBase* CreateNewAtom(const CATSobHashTableAtomBase* iAtom) const = 0;

  //Evaluation de l'index, renvoie -1 en cas d'erreur
  virtual int EvalIndex(const void* iElem) const
  {
    CATULONGPTR PtrToInt=(CATULONGPTR) iElem;
    return (PtrToInt % GetHashTableSize());
  }
  /*********************************************************/

  //Taille de la hash table
  inline int GetHashTableSize() const { return _HashTableSize; }

  //Insertion d'un �l�ment
  void InsertAtom(const CATSobHashTableAtomBase* iAtom);

  //R�cup�ration d'un �l�ment
  CATSobHashTableAtomBase* GetAtomFromElem(const void* iElem) const;

  //R�cup�ration d'un �l�ment et extraction de l'atom (il n'est pas d�truit mais n'est plus r�f�renc� dans la liste cha�n�e).
  CATSobHashTableAtomBase* GetAndDetachAtomFromElem(const void* iElem);

  //R�cup�ration d'un �l�ment via un index avec 1<= iIndex <= Max
  CATSobHashTableAtomBase* GetAtom(const int iIndex) const;

  //R�cup�ration du rang d'un �l�ment, 0 si pas trouv�
  int GetIndex(const CATSobHashTableAtomBase* iAtomToFind) const;

  //Changement dynamique de la taille de la hash table
  int Resize();

private:

  //Pas d'impl�mentation par d�faut
  CATSobHashTableBase(const CATSobHashTableBase&);
  CATSobHashTableBase& operator=(const CATSobHashTableBase&);

  friend class CATSobHashTableBaseIterator;

  //---------- Data:
  int _HashTableSize, _NbElems;
  CATSobHashTableAtomBase** _HashTableAtomPointerArray;
  CATSobHashTableAtomBase *_FirstRankAtom, *_LastRankAtom;

};

#endif

