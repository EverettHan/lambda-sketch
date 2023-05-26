/**
 *  Large Range compatibility certified by DNR (2014-05-21)
 */
//==============================================================================================================
// ENTITY : CATCld3DMesherChordError (Adaptation of CATCloudPolygonizeTo3DOper)
// Fichier : CATCld3DMesherChordError.h
// Version 37 - Pb_BORD
//==============================================================================================================
// Usage Notes : Main Operator for computing the tesselation of a 3D CATCloud
// The tesselation algorithm was developped at first by INRIA
// Now, an adaptative filter was implemented before the tesselation
//==============================================================================================================
// 10-Mar-2009 - JLH - Nettoyage dans les déclarations (architecture, forward, ...)
// 13-Oct-2005 - JLH - Référence à GeoFactoryProtected suite à la suppression des "public L0".
// 19-Jan-2004 - JLH - Eradication des 'long's.
// 19-Apr-2002 : JLH : Correction des fuites memoire Purify.
//                     Creation de la methode CleanAllStuff.
//                     Suppression de la methode CleanStructTri.
// 27-Mar-2002 : GDD : Graine : Ajout du champ des normales et de 2 tables pour la voxellisation (un seul new)
// 05-Mar-2002 : JLH : Passage du calcul de distance en double.
// Flags de debug dans un fichier a part.
// ??-Sep-2001 : DFB : Creation.
//==============================================================================================================

#ifndef CATCloudMesher_H
#define CATCloudMesher_H

/**
 * DSECAAFutureExposure_Level L1
 * DSECAAFutureExposure_Usage U3
 */

#include "ExportedByCATCloudBasicResources.h"
#include "CATCldMeshEnrichment.h"

// Pour l'algo de l'INRIA
class IFCmdlAnalyzerNoVisu ;

typedef void (*fctOnStep)() ;

class ExportedByCATCloudBasicResources CATCld3DMesherChordError
{
public:
  // Constructeur
  CATCld3DMesherChordError(CATCldMeshEnrichment::T_Cloud* iCloud) ;

  // Destructeur
  virtual ~CATCld3DMesherChordError() ;

  void SetChordalError( float ErreurCordeMesher ) ;
  float GetChordalError() ;

  // Run the algorithm
  unsigned int Run() ;

  // The result is a table of vertices.
  unsigned int GetResult (int** oTableOfVertices,
                          int &oNbVertices) ;

  unsigned int SetfctOnStep (fctOnStep fct);

  // GetError retourne l'erreur detecte
  int GetError() ;

private:

  CATCldMeshEnrichment::T_Cloud*  _TCloud;
  CATCldMeshEnrichment*           _EnrichmentOper ;
  float                           _ChordalError ;
  int                             _NumError ;
  fctOnStep                       _fonctionOnStep ;

};

#endif
