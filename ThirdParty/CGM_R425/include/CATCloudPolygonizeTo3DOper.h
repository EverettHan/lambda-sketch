//==============================================================================================================
// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2000
//==============================================================================================================
// File: CATCloudPolygonizeTo3DOper.h
//==============================================================================================================
// Usage:
// Main operator for computing the tesselation of a 3D cloud of points.
// The tesselation algorithm was developped at first by INRIA
//==============================================================================================================
// 19-Feb-2014 - DNR - Relecture du code pour validation compatibilite LR -> RAS
// 23-Mar-2004 - JLH - Eradication des 'long's - fin.
// 12-Mar-2004 - JLH - Bug 431555 : Reformattage + Protection des traitements.
// 19-Jan-2004 - JLH - Eradication des 'long's.
// 21-Dec-2000 - DHU - Création
//==============================================================================================================

#ifndef CATCloudPolygonizeTo3DOper_h
#define CATCloudPolygonizeTo3DOper_h

/**
 * DSECAAFutureExposure_Level L1
 * DSECAAFutureExposure_Usage U3
 */

#include "ExportedByCATCloudBasicResources.h"

class IFCmdlAnalyzerNoVisu ;

typedef void (*FctOnStep) () ;

class ExportedByCATCloudBasicResources CATCloudPolygonizeTo3DOper
{
public:

  CATCloudPolygonizeTo3DOper (const float *iCoords,
                              int          iNbPoints,
                              float       *iMin,
                              float       *iMax) ;

  virtual ~CATCloudPolygonizeTo3DOper () ;

  void Run () ;

  void GetResult (int **oVertices,
                  int &oNbVertices) ;

  void SetInitial (const float *iCoords,
                   int          iNbPoints) ;

  void SetfctOnStep (FctOnStep iFonction) ;

private:

  IFCmdlAnalyzerNoVisu *_Mesher ;

  int _NbPoints ;
  const float *_Coords ;
  float _Min[3] ;
  float _Max[3] ;

  int  _NbVertices ;
  int *_Vertices ;

  void IncrementStep () ;
  FctOnStep _FonctionOnStep ;
} ;

#endif
