//===========================================================================
// Copyright Dassault Systemes Provence 2004, All Rights Reserved 
//===========================================================================
//
// CATSobSDOIO.h
//
//===========================================================================
//
// Usage notes: Class used to (un)stream base mesh objects to/from SDO files.
//              It's ASCII Mode.
//
//===========================================================================
// October, 2008 : RAQ : D�placement dans ProtectedInterfaces
// April,   2004 : RAQ : Cr�ation
//===========================================================================
#ifndef CATSobSDOIO_H
#define CATSobSDOIO_H

//Pour l'export
#include "CATSobObjects.h"

//Divers
#include "CATSobDiag.h"

class CATSobMeshBase;
class CATSobMesh;
class CATSobMeshCurve;
class CATSobStream;
class CATUnicodeString;


class ExportedByCATSobObjects CATSobSDOIO
{
public:

  //Constructeurs
  CATSobSDOIO(const char* iFileName);

  //Destructeur
  ~CATSobSDOIO();

  //Stream pour le format SDO
  CATSobDiag Stream(const CATSobMesh* iMeshToStream);
  
  //Stream pour le format MRM
  CATSobDiag StreamMRM(CATSobMesh* iMeshToStream);

  //UnStream pour le format SDO
  CATSobDiag UnStream(CATSobMesh** ioMeshBaseRead, CATSobMeshCurve** ioMeshCurveRead);

  //UnStream pour le format MRM  
  CATSobDiag UnStreamMRM(CATSobMesh*& oMeshRead, const int iMaxLODLevelToKeep);

private:

  //Cr�ation des faces et nouvel ordre
  CATSobDiag CreateFaces(CATSobMesh* iMesh, int* iTabOfEdges, const int iNbFaces, const int iMaxNbEdgesPerFace, int* ioNewOrder = 0);

  //Lecture des fichiers MRM
  CATSobDiag CreateMeshStructureFromMRM(CATSobMesh*& oMesh, int*& oNewFacesOrder);

  //Calcul des d�tails � partir d'un fichier MRM
  CATSobDiag ComputeDetailsFromMRMFile(CATSobMesh* iMesh, const int iMaxLevelToKeep, const int* iNewFacesOrder);
  
  //Distance
  virtual double GetDistance(const double* iPt1, const double* iPt2);

  //Data
  CATSobStream* _Stream;
  CATUnicodeString* _FileName;
};

#endif


