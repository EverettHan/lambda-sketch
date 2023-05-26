//=======================================================================
// Copyright Dassault Systemes Provence 2007, All Rights Reserved
//=======================================================================
//
// CATSmoEdgeJournalItem.h
//
//=======================================================================
//
// Usage notes: Objet de suivi pour le journal topologique
//              (attribut des edges du base mesh)
//
//=======================================================================
// 25.05.2020 : RAQ : Ajout AddAncestorFace pour meilleur suivi dans le match
// 23.03.2016 : RAQ : Ajout Set/GetInheritSobProperties + duplication pour meilleur suivi
// November,     2007 : RBD : Modif de la signature de GetAncestorEdges
//                            et de GetParentsObjects pour prot�ger 
//                            les donn�es membres de la classe
// November,     2007 : RNO : Nouvelle Gestion des Attributs (Support du Multi Attribut)
// February,     2007 : RAQ : Creation
//=======================================================================
#ifndef CATSmoEdgeJournalItem_H
#define CATSmoEdgeJournalItem_H

//Classe m�re
#include "CATSobAttributes.h"

//Pour l'export
#include "CATSmoOperators.h"

//Divers
#include "CATSmoAncestorFace.h"
#include "CATSmoListVOfAncestorFace.h"
#include "CATDataType.h"
#include "CATListOfULONG32.h"
#include "CATListOfInt.h"
#include "CATListPV.h"

class CATGeometry;


CATDECLARESOBATTRIBUTE(CATSmoEdgeJournalItem, CATSmoEdgeJournalItemID)


class ExportedByCATSmoOperators CATSmoEdgeJournalItem: public CATSobAttributes
{
public:
  
  //Constructeur
  CATSmoEdgeJournalItem(CATSmoEdgeJournalItem* ipToCopy = NULL);

  //Ajout d'une cellule m�re par son tag
  void AddAncestorFaceTag(const CATSmoAncestorFace& iAncestorFace);

  //R�cup�ration des tags des cellules m�res
  int GetAncestorFacesTags(CATSmoListVOfAncestorFace& oAncestorFaces) const;

  // Existe-t-il des faces m�res ?
  CATBoolean HasAncestorFace() const;

  //Ajout d'une edge m�re par les tags de ses vertex extr�mit�s
  void AddAncestorEdge(const CATULONG32 iStartVertexTag, const CATULONG32 iEndVertexTag);

  //R�cup�ration des infos des edges m�res : tags des vertex extr�mit�s des edges m�res, ils sont rang�s � la suite dans la liste
  // ie. SVTagOfParentEdge1, EVTagOfParentEdge1, SVTagOfParentEdge2, EVTagOfParentEdge2, ....
  //La m�thode renvoie le nombre d'EDGES m�res.
  int GetAncestorEdges(CATListOfULONG32& oExtremityVerticesTags);

  // Existe-t-il des edges m�res ?
  CATBoolean HasAncestorEdge() const;

  //Ajout d'un parent topologique
  void AddParentObject(CATGeometry* iParentObject);

  //Obtention des parents topologiques
  int GetParentsObjects(CATListPV& ioParentsObjects);

  //Indique que la cellule doit avoir les m�mes propri�t�s que son parent si c'est une CATSobCell
  inline void SetInheritSobProperties(const CATBoolean iMustInherit = TRUE) { m_inheritSobProperties=iMustInherit; }
  inline CATBoolean GetInheritSobProperties() const { return m_inheritSobProperties; }


protected:

  //Destructeur
  virtual ~CATSmoEdgeJournalItem();

private:


  //------- Data:
  CATSmoListVOfAncestorFace _AncestorFaces;
  CATListOfULONG32 _ExtremityVerticesTags;  
  CATListPV         _TopologicalParents;
  CATBoolean m_inheritSobProperties;
};


//Cr�ation de l'attribut
ExportedByCATSmoOperators
CATSmoEdgeJournalItem* CATSmoCreateEdgeJournalItem(CATSmoEdgeJournalItem* ipToCopy = NULL);


#endif



