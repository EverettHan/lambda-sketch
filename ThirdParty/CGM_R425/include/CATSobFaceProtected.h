//=============================================================================
// Copyright Dassault Systemes Provence 2008, All Rights Reserved
//=============================================================================
//
// CATSobFaceProtected.h
//
//=============================================================================
//
// Usage notes: ***************** DON'T INCLUDE THIS HEADER *****************
//              Classe n'exposant en Protected que les m�thodes de CATSobFace
//              dont les services ne sont pas ouverts aux utilisateurs mais
//              utilisables par les frameworks de subdivision
//
//=============================================================================
// September, 2008 : RAQ : Ajout RemoveStaticBuffers
// April,     2008 : RAQ : Cr�ation
//=============================================================================
#ifndef CATSobFaceProtected_H
#define CATSobFaceProtected_H

//Classe m�re
#include "CATSobFace.h"

//Divers
#include "CATSobDiag.h"

class CATSobMesh;

class CATSobFaceProtected: public CATSobFace
{
public:

  //Destructeur
  virtual ~CATSobFaceProtected(){};

  //Pour l'op�rateur de subdivision inverse: buffer statique
  virtual double* GetStaticBufferAtLevelOrInit(const int iLevel) = 0;

  //Suppression des buffers statiques
  virtual void RemoveStaticBuffers() = 0;

  ///////////////////////////////
  // Modification de topologie
  ///////////////////////////////
  virtual CATSobDiag UpdateTopology() = 0;


protected:

  //Constructeur
  CATSobFaceProtected(CATSobMesh* iMesh):CATSobFace(iMesh) {}

private:
  
  //Copy constructor and equal operator
  CATSobFaceProtected(CATSobFaceProtected&);
  CATSobFaceProtected& operator=(CATSobFaceProtected&);

};


#endif

