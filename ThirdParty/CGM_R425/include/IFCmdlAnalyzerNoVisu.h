//==============================================================================================================
// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2000
//==============================================================================================================
// IFCmdlAnalyzerNoVisu
// INRIA 3D Mesher
//==============================================================================================================
// 12-Mar-2004 - JLH - Ramené dans ProtectedInterfaces dans PrivateInterfaces pour problème de compilation des
//                     ODTs + suppression de stl_boolean qui est dans PrivateInterfaces.
// 12-Mar-2004 - JLH - Bug 431555 : ajout de "try&catch" standard pour tenter de récupérer la main lors d'erreur
//                     système comme le stack overflow dans find-conflict (permission de SGT). Hélas, ceci n'est
//                     valable que sur NT et non Unix qui ne fait pas de "throw" natif lors de ce genre d'erreur
//                     Mofification de certaines syntaxes (renvoi de booléen).// 14-Oct-2003 - JLH - Full review.
//                     Déplacement de ProtectedInterfaces dans PrivateInterfaces.
// ??-???-???? - JLH - Creation.
//==============================================================================================================

#ifndef IFCmdlAnalyzerNoVisu_h
#define IFCmdlAnalyzerNoVisu_h

#include "ExportedByCATCldResMeshInria.h"
//#include "stl_boolean.h"

#ifndef NULL
#define NULL 0
#endif

class implicitFunc ;
class IFMesher ;

typedef void (*FctOnStep) () ;

class ExportedByCATCldResMeshInria IFCmdlAnalyzerNoVisu
{
public:

  IFCmdlAnalyzerNoVisu (FctOnStep iIncrementFunction = NULL) ;
  ~IFCmdlAnalyzerNoVisu () ;

//boolean Init (float* iPtrCloudToTriangulate,
  unsigned char Init (float* iPtrCloudToTriangulate,
                      int    iNbPointsInCloud,
                      float* bboxMin,
                      float* bboxMax) ;
  
//boolean Init (float  iMin[3],
  unsigned char Init (float  iMin[3],
                      float  iMax[3],
                      int    iNbPoints,
                      float* iCoords,
                      unsigned char* iToMesh = NULL) ;
  
  unsigned char Run () ;
  unsigned char GetResult (int &oNbVertices, int* &oVertices) ;
  unsigned char GetResult (int &oNbVertices, int* &oVertices, int* &oConnexes) ;
  void SetFctOnStep (FctOnStep iIncrementFunction) ;

  char ParseCommandLine (int   argc,
                         char *argv[]) ;
  
  void allModel () ;
  
  void runApplication () ;

private:
  
  implicitFunc* _IFunc ;
  IFMesher*     _Mesher ;
  FctOnStep     _IncrementFunction ;
  int           _DumpSTLAscii ;
  int           _DumpSTLBinary ;
  int           _DumpVRML ;
} ;

#endif
