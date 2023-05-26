//=================================================================================
// Copyright Dassault Systemes Provence 2009, All Rights Reserved
//=================================================================================
//
// CATSobVertexTagVertexHashTable.h
//
//=================================================================================
//
// Usage notes: Hash table VertexTag (key) / Vertex (value)
//
//=================================================================================
// December,  2009 : RAQ : Creation
//=================================================================================
#ifndef CATSobVertexTagVertexHashTable_H
#define CATSobVertexTagVertexHashTable_H

//Pour l'export
#include "ExportedByCATSobUtilities.h"

//Classe m�re
#include "CATSobHashTableWithAssoc.h"

class CATSobVertex;


class ExportedByCATSobUtilities CATSobVertexTagVertexHashTable: public CATSobHashTableWithAssoc
{
public:

  //Constructeur
  CATSobVertexTagVertexHashTable();

  //Destructeur
  virtual ~CATSobVertexTagVertexHashTable();

  /********************* SERVICES *********************/
  //Insertion d'un �l�ment et de sa donn�e associ�e
  void Insert(const unsigned int iVertexTag, const CATSobVertex* iVertex);
  
  //R�cup�ration d'une donn�e associ�e � un �l�ment
  CATSobVertex* GetVertexFromTag(const unsigned int iVertexTag) const;

  //Test d'appartenance
  CATBoolean Contains(const unsigned int iVertexTag) const;

  //Suppression d'un �l�ment
  void Remove(const unsigned int iVertexTag);
  /****************************************************/

protected:

};


#endif

