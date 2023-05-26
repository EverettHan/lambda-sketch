//=================================================================================
// Copyright Dassault Systemes Provence 2009, All Rights Reserved
//=================================================================================
//
// CATSobHashTable.h
//
//=================================================================================
//
// Usage notes: Hash table de pointeurs.
//
//=================================================================================
// December,  2009 : RAQ : Creation
//=================================================================================
#ifndef CATSobHashTable_H
#define CATSobHashTable_H

//Pour l'export
#include "ExportedByCATSobUtilities.h"

//Hash table & cie
#include "CATSobHashTableBase.h"

class CATSobHashTableIterator;


class ExportedByCATSobUtilities CATSobHashTable: public CATSobHashTableBase
{
public:

  //Constructeurs
  CATSobHashTable();
  CATSobHashTable(const unsigned int iEstimatedSize);

  //Destructeur
  virtual ~CATSobHashTable();

  /********************* SERVICES *********************/
  //Insertion d'un �l�ment
  void Insert(const void* iElem);

  //Test d'appartenance
  CATBoolean Contains(const void* iElem) const;

  //Suppression d'un �l�ment
  void Remove(const void* iElem);

  //Acc�s � un �l�ment par rang
  CATBoolean GetElem(const int iIndex, void*& oElem) const;

  //R�cup�ration du rang d'un �l�ment, 0 si pas trouv�
  int GetIndex(const void* iElem) const;
  /****************************************************/

  //Cr�ation d'un it�rateur, il doit �tre d�truit par l'appelant.
  CATSobHashTableIterator* GetIterator() const;


protected:

  /********************* A IMPLEMENTER *********************/
  //Allocation du tableau interne
  CATSobHashTableAtomBase** Allocate(const int iSize) const;

  //Cr�ation d'un �l�ment pour insertion
  CATSobHashTableAtomBase* CreateNewAtom(const CATSobHashTableAtomBase* iAtom) const;
  /*********************************************************/

private:

  //Pas d'impl�mentation par d�faut
  CATSobHashTable(const CATSobHashTable&);
  CATSobHashTable& operator=(const CATSobHashTable&);
 
};


#endif

