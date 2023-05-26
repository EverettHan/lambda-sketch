//=================================================================================
// Copyright Dassault Systemes Provence 2009, All Rights Reserved
//=================================================================================
//
// CATSobFaceTagFaceHashTable.h
//
//=================================================================================
//
// Usage notes: Hash table FaceTag (key) / Face (value)
//
//=================================================================================
// December,  2009 : RAQ : Creation
//=================================================================================
#ifndef CATSobFaceTagFaceHashTable_H
#define CATSobFaceTagFaceHashTable_H

//Pour l'export
#include "ExportedByCATSobUtilities.h"

//Classe m�re
#include "CATSobHashTableWithAssoc.h"

class CATSobFace;


class ExportedByCATSobUtilities CATSobFaceTagFaceHashTable: public CATSobHashTableWithAssoc
{
public:

  //Constructeur
  CATSobFaceTagFaceHashTable();

  //Destructeur
  virtual ~CATSobFaceTagFaceHashTable();

  /********************* SERVICES *********************/
  //Insertion d'un �l�ment et de sa donn�e associ�e
  void Insert(const unsigned int iFaceTag, const CATSobFace* iFace);
  
  //R�cup�ration d'une donn�e associ�e � un �l�ment
  CATSobFace* GetFaceFromTag(const unsigned int iFaceTag) const;

  //Test d'appartenance
  CATBoolean Contains(const unsigned int iFaceTag) const;

  //Suppression d'un �l�ment
  void Remove(const unsigned int iFaceTag);
  /****************************************************/

protected:

};


#endif

