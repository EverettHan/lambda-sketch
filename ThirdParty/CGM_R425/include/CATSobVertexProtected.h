//=============================================================================
// Copyright Dassault Systemes Provence 2016, All Rights Reserved
//=============================================================================
//
// CATSobVertexProtected.h
//
//=============================================================================
//
// Usage notes: ***************** DON'T INCLUDE THIS HEADER *****************
//              Classe n'exposant en Protected que les m�thodes de CATSobVertex
//              dont les services ne sont pas ouverts aux utilisateurs mais
//              utilisables par les frameworks de subdivision
//
//=============================================================================
// April,      2021 : RJY1: Modif constructeur pour CATSobMeshBase
// 26.10.2016 : RAQ : Creation
//=============================================================================
#ifndef CATSobVertexProtected_H
#define CATSobVertexProtected_H

//Classe m�re
#include "CATSobVertex.h"

//Divers
#include "CATSobDiag.h"

class CATSobMeshBase;

class CATSobVertexProtected : public CATSobVertex
{
public:

  //Destructeur
  virtual ~CATSobVertexProtected() {}

  //Test manifold : le onering des faces est soit hom�omorphe � une disque ferm� ou � un disque ouvert
  virtual CATSobDiag IsManifold(CATBoolean& oIsManifold) const = 0;

  //Test manifold "extended" : le vertex n'est pas consid�r� manifold s'il contient un secteur ferm� et au moins un secteur ouvert
  //Autrement dit, on accepte les vertex avec plusieurs secteurs ouverts mais aucun ferm�
  virtual CATSobDiag IsManifoldExtended(CATBoolean& oIsManifold) const = 0;

  //Test si le vertex contient un secteur ferm� de faces
  virtual CATBoolean HasClosedSector() const = 0;


protected:

  //Constructeur
  CATSobVertexProtected(CATSobMeshBase* ipMesh):
    CATSobVertex(ipMesh) {}

private:

  //Copy constructor and equal operator
  CATSobVertexProtected(CATSobVertexProtected&);
  CATSobVertexProtected& operator=(CATSobVertexProtected&);

};



#endif  //CATSobVertexProtected_H

