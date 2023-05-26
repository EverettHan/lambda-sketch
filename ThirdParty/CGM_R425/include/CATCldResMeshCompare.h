/**
* @quickReview GDD     aa:mm:jj
* @fullReview  GDD ZZZ aa:mm:jj
*/

// COPYRIGHT DASSAULT SYSTEMES PROVENCE 1999-2009
//=============================================================================
//
// CATCldResMeshCompare.h: GDD => Classe gérant l'intérieur de tout ce qui se trouve dans la "boite noire" du QLC
//                                      
//               
//=============================================================================
//  25-06-2009 : GDD - Creation. C'est mon anniversaire, 65ans (et oui!!)
//=============================================================================

#ifndef CATCldResMeshCompare_H
#define CATCldResMeshCompare_H

#include "ExportedByCATCloudBasicResources.h"

#include "CATCloudProjection.h"

#include "CATBoolean.h"

#include "CATListOfInt.h"
#include "CATListOfFloat.h"
#include "CATListOfDouble.h"

class CATQLC_LstResProj;
class CATQLC_LstTriangles;
class CATQLC_MapOfFloatXYZIntI;
class CelQLC_Faces;
class CelQLC_Triangle;

class ExportedByCATCloudBasicResources CATCldResMeshCompare
{
  public:

  // Constructeur & Destructeur
  CATCldResMeshCompare(void);
  virtual ~CATCldResMeshCompare(void);  

  // Chargement du polygone source et reference ainsi que des donnees associees
  int SetMeshes ( CATCloudProjection::T_Mesh**  iSrcMeshes, 
                  int                           iNbSrcMeshes, 
                  double                        iSagSrc,
                  CATCloudProjection::T_Mesh**  iRefMeshes, 
                  int                           iNbRefMeshes, 
                  double                        iSagRef);

  // Recuperation de numeros des faces Differentes
  // Chaque element de la liste contient le numero de la face correspondant au polygone.
  // Toutes les faces dupliquees dans  SRC ou REF ne sont     mises qu'une seule fois
  // Toutes les faces dupliquees entre SRC et REF ne sont pas mises 
  int GetDiferentiateFaces(CATListOfInt &LstDifFacesSrc, CATListOfInt &LstDifFacesRef);

  // Recuperation des resultats SRC/REF au dessus d'une distance Min
  // DistMin   : La distance de reference >= 2 fois la sag moyenne
  // NbrVtx    : Nombre de vertices
  // TabVtx    : Les vertices a raison de 3 par sommets (zone de difference et zone d'egalite)
  // TabVec    : Le vecteur distance de chaque sommet de la SRC à la REF a raison de 3 par sommet
  // NbrTriDif : Le nombre de triangles de la zone de difference
  // TabTriDif : La table des triangles à raison de 3 numeros de sommets par triangle
  //             La numerotation des sommets commence à 0 et est conforme pour la creation d'un CldPolygon
  // NbrTriEqu : Le nombre de triangles de la zone d'egalite
  // TabTriEqu : La table des triangles à raison de 3 numeros de sommets par triangle
  //             La numerotation des sommets commence à 0 et est conforme pour la creation d'un CldPolygon
  // Rem : Les tableaux sont crees par la methode, à la charge de l'utilisateur de les detruire
  int GetDistance_Src_Ref (double DistMin, 
                           int    &NbrVtx, 
                           float* &TabVtx, 
                           float* &TabVec, 
                           int&   NbrTriDif, 
                           int*&  TabTriDif,
                           int&   NbrTriEqu, 
                           int*&  TabTriEqu);

  // Recuperation des resultats REF/SRC au dessus d'une distance Min
  // DistMin  : La distance de reference >= 2 fois la sag moyenne
  // NbrVtx   : Nombre de vertices
  // TabVtx    : Les vertices a raison de 3 par sommets (zone de difference et zone d'egalite)
  // TabVec   : Le vecteur distance de chaque sommet de la  à la REF a raison de 3 par sommet
  // NbrTriDif : Le nombre de triangles de la zone de difference
  // TabTriDif : La table des triangles à raison de 3 numeros de sommets par triangle
  //            La numerotation des sommets commence à 0 et est conforme pour la creation d'un CldPolygon
  // Rem : Les tableaux sont crees par la methode, à la charge de l'utilisateur de les detruire
  int GetDistance_Ref_Src (double   DistMin, 
                           int&     NbrVtx, 
                           float*&  TabVtx, 
                           float*&  TabVec, 
                           int&     NbrTriDif, 
                           int*&    TabTriDif,
                           int&     NbrTriEqu, 
                           int*&    TabTriEqu);

private:

  // Initialisation des Strutures de chaque Mesh

  int InitMesh_Data ( int                           iNbrFaces,
                      CATCloudProjection::T_Mesh**  iLstMeshFaces, 
                      CelQLC_Faces *&               oLstFaces, 
                      CATQLC_MapOfFloatXYZIntI *&   MapCdg,
                      int &                         NbrDifVtxTot, 
                      int &                         NbrDifTriTot, 
                      float &                       AireDifTot);

  // Recherche des faces Identiques et Differentes
  int DiferentiateFaces(CATListOfInt &  LstDifFacesSrc, 
                        CATListOfInt &  LstDifFacesRef);

  // Calcul des 2 polygones ne contenant que les faces differentes
  //int ComputePolygonesDifferents ();

  // Repond TRUE si la subdivision d'un triangle est necessaire sur un critere d'aire minimum et de longueur maxi d'arete
  //             Une valeur negative de l'une permet de ne pas utiliser le critere correspondant
  //             Si les 2 sont negatives, la subdivision ne sera jamais realisee
  // Sommet           : Table des 3 sommets
  // LongMinimum  : Longueur minimum d'arete à respecter
  // AireMinimum  : Aire     minimum à respecter
  CATBoolean IsMakeSubdivision ( double Sommet[9], 
                                 double LongMinimum, 
                                 double AireMinimum);

  //CATBoolean IsMakeSubdivision (CATMathPoint * Sommet, double LongMinimum, double AireMinimum);

  // Subdivision d'un seul triangle donne par 3 points et les normales associes par une technique recursive
  // Le LOD final est fonction de l'aire d'un triangle sachant qu'elle est divise en 4 pour chaque niveau
  // Les 2 listes sont en permanance mise a jour et contiennent donc le resultat final.

  int SubdivisionTriangle( double Sommet[9], 
                           double Normale[9], 
                           double DistMin2, 
                           double AireMinimum, 
                           CATQLC_MapOfFloatXYZIntI * MapPntProj, 
                           CATQLC_LstResProj * &LstResProj, 
                           CATQLC_LstTriangles * &LstResTria);
  
  //int SubdivisionTriangle(CATMathPoint * Sommet, CATMathVector * Normale, double DistMin2, double AireMinimum, 
  //                        CATQLC_MapOfFloatXYZIntI * MapPntProj, 
  //                        CATQLC_LstResProj * &LstResProj, CATQLC_LstTriangles * &LstResTria);

  // Calcul Distance entre la Source et la Reference
  int ComputeDistance ( int iNbSrcMesh,
                        CATCloudProjection::T_Mesh** Src_ListOfMeshes, 
                        CATListOfInt Src_LstDifFaces, 
                        /*CelQLC_Faces * LstFacesInfo,*/ 
                        int iNbRefMesh,
                        CATCloudProjection::T_Mesh**  Ref_ListOfMeshes, 
                        double DistMin, 
                        CATQLC_LstResProj *& LstResProj, 
                        CATQLC_LstTriangles *& LstResTria);
  //int ComputeDistance (CATLISTP(CATCldCell) Src_LstPolygonFaces, CATListOfInt Src_LstDifFaces, CelQLC_Faces * _LstFacesSrc, 
  //                     CATCldPolygon * Polygon_REF, double DistMin, 
  //                     CATQLC_LstResProj * &LstResProj, CATQLC_LstTriangles * &LstResTria);

  // Charge les donnees pour la sortie des resultats
  //int GetDistanceResult (CATQLC_LstResProj * LstResVtx, CATQLC_LstTriangles * LstResTri,         
  //                       CATCldBody * &BodyPolygon, CATCldPolygon * &Polygon);

  // Permet de faire un arrondi a une valeur fixee dans CATQLC_Types_And_Errors (_Arround_Value)
  float Arround (float iVal);

  // Calcul du point et de la normale interpole sur la bezier calculee sur un segment avec ses normales aux extremites
  // On evalue le point milieu et la normale associee en considerant la courbe de bezier passant par les 2 points
  // et ayant la normale donnee en chaque point
  //int EvalMilieu_PNB (CATMathPoint PntA, CATMathPoint PntB, CATMathVector NorA,  CATMathVector NorB, 
  //                    CATMathPoint & oPntMilieu, CATMathVector & oNorMilieu);
#ifdef QLC_INTERPOLATION_CUBIQUE
  int EvalMilieu_PNB (double PntA[3], 
                      double PntB[3], 
                      double NorA[3],  
                      double NorB[3], 
                      double oPntMilieu[3], 
                      double oNorMilieu[3]);
#endif
  // Get Number of the Next connected Triangle or vertex or bar or .... (+1 modulo 3)
  int Next(int k); 

  // Get Number of the Previous connected Triangle or vertex or bar or .... (-1 modulo 3)
  int Prev(int k);

  // Indicateur si les initialisations sont faites avant les projections
  CATBoolean _IsInit_OK;

  // Interpolation cubique Subdivision ou Projection
  CATBoolean _Interpolation_Cubique;

  // Les donnees d'entree en tant que champ de la classe
#ifdef UNUSED_CODE
  CATGeoFactory * _GeoFactorySrc;
  CATGeoFactory * _GeoFactoryRef;
  CATCldPolygon * _MyPolygonSrc;
  CATCldPolygon * _MyPolygonRef;
#endif

  double                          _SagSrc, _SagRef;
  CATBoolean                      _Distance_Src_Ref;  // = TRUE si calculee
  CATBoolean                      _Distance_Ref_Src;  // = TRUE si calculee

  // Table des Faces
  CATCloudProjection::T_Mesh**    _LstPolygonFaces_SRC ;
  int                             _NbrFacesSrc;
  CelQLC_Faces *                  _LstFacesSrc;
  CATQLC_MapOfFloatXYZIntI *      _MapXYZI_Src;
  CATListOfInt                    _LstDifFaces_SRC;
  int                             _NbrVtxTotDif_SRC;
  int                             _NbrTriTotDif_SRC;
  float                           _AireDifTot_SRC;

  CATCloudProjection::T_Mesh**    _LstPolygonFaces_REF ;
  int                             _NbrFacesRef;
  CelQLC_Faces *                  _LstFacesRef;
  CATQLC_MapOfFloatXYZIntI *      _MapXYZI_Ref;
  CATListOfInt                    _LstDifFaces_REF;
  int                             _NbrVtxTotDif_REF;
  int                             _NbrTriTotDif_REF;
  float                           _AireDifTot_REF;

  // Les 2 polygones ne contenant que les faces differentes
  //CATCldBody * _BodyPolygon_SRC;
  //CATCldBody * _BodyPolygon_REF;
  //CATCldPolygon * _Polygon_SRC; 
  //CATCldPolygon * _Polygon_REF;

  // Pour la Recuperation des informations du polygone dans un tableau  
  float * _TabVtx; int _NbrVtx;
  float * _TabNor; int _NbrNor;
  int *   _TabTri; int _NbrTri;

  CATBoolean                      _ActifOnly;

  // La Map de gestion des point doublons
  CATQLC_MapOfFloatXYZIntI *      _MapDoublons;

  // Pour l'operateur de projection
  CATCloudProjection *            _MyProjOper;

  // Les deux listes contenant les resultats de la projection et les listes des triangles
  CATQLC_LstResProj   *           _LstResVtx_SRC;
  CATQLC_LstResProj   *           _LstResVtx_REF;
  CATQLC_LstTriangles *           _LstResTri_SRC;
  CATQLC_LstTriangles *           _LstResTri_REF;
};

#endif

