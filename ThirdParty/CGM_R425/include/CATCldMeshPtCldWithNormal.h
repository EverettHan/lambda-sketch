//==============================================================================================================
// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2011
//==============================================================================================================
// CATCldMeshPtCldWithNormal
// Classe pour mailler un nuage de points avec normal
//==============================================================================================================
// 24-Nov-2011 - NUA - Creation
//==============================================================================================================

#ifndef CATCldMeshPtCldWithNormal_H
#define CATCldMeshPtCldWithNormal_H

#include "ExportedByCATCldResMeshInria.h"

#ifndef NULL
#define NULL 0
#endif

class implicitFunc ;
class IFMesher ;
class CATCldResMeshExtClassifier ;

class ExportedByCATCldResMeshInria CATCldMeshPtCldWithNormal
{
public:

  // fournir la boite englobante
  CATCldMeshPtCldWithNormal (const float MinBox[3], const float MaxBox[3]) ;
  ~CATCldMeshPtCldWithNormal () ;

  // renseigne les points a mailler, avec leur normale
  void SetPointCloud (const unsigned int iNbPoints,
                      const float * iPoints ,
                      const float * iNormals) ;

  // renseigne au besoin un classifier externe
  // dont le role est de dire pour chaque point 3D d'un tableau (pas forcement ceux passes en parametre de
  // SetPointCloud) si ce point est dehors ou dedans l'objet dont la peau est a mailler
  void SetClassifier (CATCldResMeshExtClassifier * iClassifier)
  {
    _Classifier = iClassifier ;
  }

  // Lance le calcul du mailleur de l'INRIA
  int Run() ;

  // recupere le maillage.
  int GetResult (int & oNbTriangles, int *& oTriangles) ;

private:
  
  // operateurs
  implicitFunc* _IFunc ;
  IFMesher*     _Mesher ;

  // donnees
  float _MinBox[3], _MaxBox[3] ;
  float * _Points ;
  float * _Normals ;
  unsigned int _NbPoints ;
  double _MaxEdgeLength ;

  CATCldResMeshExtClassifier * _Classifier ;
} ;

#endif
