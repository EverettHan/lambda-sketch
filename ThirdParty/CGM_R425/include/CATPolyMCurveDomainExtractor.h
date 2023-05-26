//===================================================================================
// Copyright Dassault Systemes Provence 2009, All Rights Reserved
//===================================================================================
//
// CATPolyMCurveDomainExtractor.h
//
//===================================================================================
//
// Usage notes: Extraction de tous les triangles compris � l'int�rieur d'une loop
//              d�finie par une CATPolyMCurve ferm�e.
//              /!\ Le maillage doit �tre orient�
//
//===================================================================================
// July,   2009 : RAQ : Cr�ation
//===================================================================================
#ifndef CATPolyMCurveDomainExtractor_H
#define CATPolyMCurveDomainExtractor_H

//Pour l'export
#include "CATPolyTrimOperators.h"

//Structure maillage
#include "CATIPolyMesh.h"
#include "CATPolyMCurve.h"
#include "CATPolyBitSet.h"
#include "CATPolyMPoint.h"

//Divers
#include "CATListOfInt.h"
#include "CATBoolean.h"


class CATUnicodeString;



class ExportedByCATPolyTrimOperators CATPolyMCurveDomainExtractor
{
public:

  //Constructeur
  CATPolyMCurveDomainExtractor(const CATIPolyMesh& iPolyMesh, const CATPolyMCurve& iPolyMCurve, const unsigned int iDebugID = 0);

  //Destructeur
  ~CATPolyMCurveDomainExtractor();

  //R�cup�ration des triangles du domaine
  const CATListOfInt* GetDomain() const;

  //Run de l'op�rateur
  int Run();

  //DEBUG: Activation des print
  void SetVerbose();


protected:



private:

  //Check que la courbe est regular et d�crit un domaine ferm�
  int CheckPolyMCurve();

  //Extraction de tous les triangles se trouvant sous la courbe
  int ExtractTrianglesUnderCurve(CATListOfInt& oSupportTriangles, CATPolyBitSet& oIsSupportTriangle);

  //Extraction des triangles ext�rieur partageant une edge avec la courbe
  int ExtractExternalSupportTriangles(CATPolyBitSet& iIsExternalSupportTriangle, int& oSeedTriangle) const;

  //Extraction des triangles d�limit�s par la bordure d'une courbe non vertex path
  int ComputeDomainForNONVertexPathCurve(CATListOfInt& ioSupportTriangles, CATPolyBitSet& ioIsSupportTriangle);

  //Extraction des triangles d�limit�s par une courbe vertex path
  int ComputeDomainForVertexPathCurve(CATListOfInt& oSupportTriangles, CATPolyBitSet& oIsSupportTriangle);
    
  //Extraction du domaine
  int ExtractDomain(const int iSeedTriangle, CATListOfInt& ioSupportTriangles, CATPolyBitSet& ioIsSupportTriangle);

  //R�cup�ration des segments de courbes traversant un triangle
  int GetAllPolyCurveEdgesInTriangle(const int iTriangleIndex, CATListOfInt& oPolyPointsIndexesOfEdges);

  //Check qu'un PolyMPoint est dans un triangle
  CATBoolean IsInTriangle(const CATPolyMPoint& iPolyMPoint, const int iTriangleIndex, const int* iTriangleVertices) const;

  //Check du nombre de bords libres dans le domaine
  int CheckDomain(CATListOfInt& iSupportTriangles, CATPolyBitSet& iIsSupportTriangle);

  //Calcul du OneRing ordonn� d'un vertex (sens trigo)
  int GetOrderedRing(const int iVertexIndex, CATListOfInt* ioOrderedVerticesRing = 0, CATListOfInt* ioOrderedTrianglesRing = 0) const;

  //Obtention d'un triangle � partir d'une edge orient�e
  int GetTriangleFromOrientedEdge(const int iStartVertex, const int iEndVertex, int* ioThirdVertex = 0) const;

  //Debug: sauvegarde dans un fichier NCGM des triangles actuellement d�couvert + la courbe
  int DEBUGSaveTrianglesAndCurveInNCGM(const CATUnicodeString& iFileName, const CATListOfInt& iTrianglesList) const;


  //--------- Data:
  unsigned int _DebugID;
  int _Error;
  const CATIPolyMesh& _PolyMesh;
  const CATPolyMCurve& _MCurve;
  CATBoolean _MCurveIsClosed, _MCurveIsAVertexPath, _Verbose;
  CATListOfInt _SupportTriangles;
};


#endif

