//=================================================================================
// Copyright Dassault Systemes Provence 2009, All Rights Reserved
//=================================================================================
//
// CATSobHashTableWithAssoc.h
//
//=================================================================================
//
// Usage notes: Hash table de pointeurs + pointeur associ�.
//
//=================================================================================
// December,  2009 : RAQ : Creation
//=================================================================================
#ifndef CATSobHashTableWithAssoc_H
#define CATSobHashTableWithAssoc_H

//Pour l'export
#include "ExportedByCATSobUtilities.h"

//Classe m�re
#include "CATSobHashTableBase.h"


class CATSobHashTableWithAssocAtom;
class CATSobHashTableWithAssocIterator;


class ExportedByCATSobUtilities CATSobHashTableWithAssoc: public CATSobHashTableBase
{
public:

  //Constructeurs
  CATSobHashTableWithAssoc();
  CATSobHashTableWithAssoc(const unsigned int iEstimatedSize);

  //Destructeur
  virtual ~CATSobHashTableWithAssoc();

  /********************* SERVICES *********************/
  //Insertion d'un �l�ment et de sa donn�e associ�e
  void Insert(const void* iElem, const void* iAssoc);
  
  //R�cup�ration d'une donn�e associ�e � un �l�ment.
  //Renvoie TRUE si l'�l�ment a �t� trouv�, FALSE sinon.
  CATBoolean GetAssoc(const void* iElem, void*& oAssoc) const;

  //Test d'appartenance
  CATBoolean Contains(const void* iElem) const;

  //Modification de l'association d'un �l�ment
  CATBoolean ModifyAssoc(const void* iElem, const void* iNewAssoc);

  //Suppression d'un �l�ment
  void Remove(const void* iElem);

  //R�cup�ration d'une donn�e associ�e � un �l�ment et suppression de l'entr�e dans la hash table
  //Renvoie TRUE si l'�l�ment a �t� trouv�, FALSE sinon.
  CATBoolean GetAssocAndRemove(const void* iElem, void*& oAssoc);

  //Acc�s � un �l�ment par rang
  CATBoolean GetElem(const int iIndex, void*& oElem) const;
  CATBoolean GetAssoc(const int iIndex, void*& oAssoc) const;
  CATBoolean GetElemAndAssoc(const int iIndex, void*& oElem, void*& oAssoc) const;

  //R�cup�ration du rang d'un �l�ment, 0 si pas trouv�
  int GetIndex(const void* iElem, const void* iAssoc) const;
  /****************************************************/

  //Cr�ation d'un it�rateur, il doit �tre d�truit par l'appelant.
  CATSobHashTableWithAssocIterator* GetIterator() const;


protected:

  /********************* A IMPLEMENTER *********************/
  //Allocation du tableau interne
  virtual CATSobHashTableAtomBase** Allocate(const int iSize) const;

  //Cr�ation d'un �l�ment pour insertion
  virtual CATSobHashTableAtomBase* CreateNewAtom(const CATSobHashTableAtomBase* iAtom) const;
  /*********************************************************/

private:

  //Pas d'impl�mentation par d�faut
  CATSobHashTableWithAssoc(const CATSobHashTableWithAssoc&);
  CATSobHashTableWithAssoc& operator=(const CATSobHashTableWithAssoc&);

};

#endif


