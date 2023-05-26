//==============================================================================================================
// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2011
//==============================================================================================================
// CATCldMeshPtCldWithNormal
// Classe pour mailler un nuage de points avec normal
//==============================================================================================================
// 14-Dec-2011 - NUA - Creation
//==============================================================================================================

#ifndef CATCldResMeshExtClassifier_H
#define CATCldResMeshExtClassifier_H

#include "ExportedByCATCldResMeshInria.h"

struct PointToBeClassified_Type {
  float _Coord[3] ;
  int _PointID ;
  int _Flag ; // in/out
  int pad1 ; //
  int pad2 ; // Alignement 16 octets
  int pad3 ; // 
} ;


class ExportedByCATCldResMeshInria CATCldResMeshExtClassifier
{
public:
  CATCldResMeshExtClassifier() {} ;
  virtual ~CATCldResMeshExtClassifier() {} ;

  virtual int Classify (PointToBeClassified_Type * iTabOfPoints, const int iNbPoints) = 0 ;
};

#endif
