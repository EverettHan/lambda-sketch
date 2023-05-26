//==============================================================================================================
// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2004
//==============================================================================================================
// File: CATCloudPolygonizeTo2DOper.h
//==============================================================================================================
// Usage:
//==============================================================================================================
// 06-May-2005 - JLH - Nettoyage.
// 23-Mar-2004 - JLH - Eradication des 'long's - fin.
// 19-Jan-2004 - JLH - Eradication des 'long's.
// 04-Mar-2003 - JLH - "_trianOp" par valeur (locale) plutot que par pointeur (donnee-membre)
//                       Correction des diagnostics Purify :
//                         MLK-332358, MLK-332359
//                         MLK-331702, MLK-331703, MLK-331705, MLK-331706
//                         MLK-331334, MLK-331335
// 19-Mar-2002 - RBD - MkCheckSource.
// 21-Dec-1999 - RBD - D'après FLZ.
//==============================================================================================================

#ifndef CATCloudPolygonizeTo2DOper_h
#define CATCloudPolygonizeTo2DOper_h

#include "ExportedByCATCloudBasicResources.h"
#include "CATCORBABoolean.h"
#include "CATMathPlane.h"

#ifndef CNEXT_CLIENT
#include "CATTrace.h"
#endif

class CATMathVectorf;

typedef void (*fctOnStep) () ;

class ExportedByCATCloudBasicResources CATCloudPolygonizeTo2DOper

{
public:

  CATCloudPolygonizeTo2DOper (const int    iNbPoints,
                              const float* iCoords) ;

  virtual ~CATCloudPolygonizeTo2DOper() ;

  void Initialize (const int iNbPoints,
                   const float* iCoords) ;
  
  //CATCloudPolygonizeTo2DOper (const float*     iPtrCloudToTriangulate,
  //                            const int        iNbPointsInCloud,
  //                            const CATCldBox &iMinBox,
  //                            const float      iCharactDist) ;
  void Run() ;

  // DEPRECATED Compute the initial plane of projection for the Cloud
  //void GetInitProjectPlane (CATMathPlane &oProjectPlane) ;

  void GetInitProjectPlane (double oOrigine[3], 
                            double oFirstDirection[3],
                            double oSecondDirection[3],
                            double oThirdDirection[3]) ;

  // DEPRECATED : Set the plane of projection for computing the 2D Delaunay tesselation
  //void SetProjectPlane (const CATMathPlane &iProjectPlane) ;

  // Set the plane of projection for computing the 2D Delaunay tesselation
  void SetProjectPlane (const double iOrigine[3], 
                        const double iFirstDirection[3],
                        const double iSecondDirection[3],
                        const double iThirdDirection[3]) ;

  // Set the mode : Auto (split the Cloud and compute the "best" projecting plane each times)
  // Manual (No split and the projecting plane is given by the user
  void SetModeTo2D (boolean iAutoMode) ;

  // The result is a table of vertices.
  void GetResult (int  &oNbVertices,
                  int* &oVertices) ;
  void GetResult (int **oTableOfVertices, int &oNbVertices) ;
  void GetResult (float iNeighDistance, int **oTableOfReducedVertices, int &oNbReducedVertices) ;

  // SetFonctionCallOn Progress Step
  void SetfctOnStep (fctOnStep) ;

private:

  void GetLocalNormal (CATMathVectorf& oLocalNormal);
  boolean GetMinBox ( float oBoxDimension[3],
                      float oBoxLandMarkAxis[9],
                      float oBoxLandMarkCenter[3],
                      float oBoxOrigin[3]);       
  boolean GetMedianPlane (CATMathPlane &oMedianPlane);

  int _NbPoints ;
  const float *_Coords ;

  boolean _UserPlane ;
  CATMathPlane _Plane ;
  //
  double _OriginPlane[3];
  double _FirstPlaneAxis[3];
  double _SecondPlaneAxis[3];
  double _ThirdPlaneAxis[3];
  //
  int  _NbVertices ;
  int* _Vertices ;

  fctOnStep _IncrementFct ;
  void IncrementStep() ;

#ifndef CNEXT_CLIENT
  static CATTrace _Trace ;
#endif

} ;

#endif
