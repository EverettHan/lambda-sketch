/**
 *  Large Range compatibility certified by DNR (2014-05-21)
 */
//==============================================================================================================
// ENTITY : CATCldMeshEnrichment (Adaptation of CATCloudPolygonizeTo3DOper)
// Fichier : CATCldMeshEnrichment.h
// Version 37 - Pb_BORD
//==============================================================================================================
// Usage Notes : Main Operator for computing the tesselation of a 3D CATCloud
// The tesselation algorithm was developped at first by INRIA
// Now, an adaptative filter was implemented before the tesselation
//==============================================================================================================
// 31-Jan-2022 - JLH - Portage Linux :
//                     Suppression des warnings et des erreurs de compilation en mode non-permissif.
// 09-Jul-2009 - TTD - Ajout de constructeur et destructeur pour T_Mesh et T_Cloud
// 23-Nov-2007 - DNR - Ajout de SetMaxRecursivityLevel pour limiter le nombre d'appel recurssif dans CritereFlipEdge.
//                     Ajout de Set/UnSet MaxDistance pour gestion du threshold.
// 14-Sep-2007 - DNR - Nouvelle classe issue de CATCld3DMesherChordError :
//                     - Ajout d'un constructeur vide, et méthodes SetPolygonSeed et SetBodyToMerge pour 
//                       CHIDI (enrichissement).
// 19-Jan-2004 - JLH - Eradication des 'long's.
// 19-Apr-2002 : JLH : Correction des fuites memoire Purify.
//                     Creation de la methode CleanAllStuff.
//                     Suppression de la methode CleanStructTri.
// 27-Mar-2002 : GDD : Graine : Ajout du champ des normales et de 2 tables pour la voxellisation (un seul new)
// 05-Mar-2002 : JLH : Passage du calcul de distance en double.
// Flags de debug dans un fichier a part.
// ??-Sep-2001 : DFB : Creation.
//==============================================================================================================

#ifndef CATCldMeshEnrichment_H
#define CATCldMeshEnrichment_H

#include "ExportedByCATCloudBasicResources.h"
#include "CATCloudProjection.h"
#include "string.h"

#if !defined(PLATEFORME_DS64)
  typedef long CATLONG32 ;
#else
  typedef int CATLONG32 ;
#endif

//class CATGeoFactory ;
//class CATCldPolygon;
//class CATCldBody ;

// Pour l'algo de l'INRIA
class IFCmdlAnalyzerNoVisu ;

typedef void (*fctOnStep)() ;

class ExportedByCATCloudBasicResources CATCldMeshEnrichment
{
public:
  // Constructeur

  class T_Mesh : public CATCloudProjection::T_Mesh {
  public:
    inline T_Mesh() {} ;
    inline virtual ~T_Mesh() {} ;
  };

  class T_Cloud {
  public:
    inline T_Cloud() {} ;
    inline virtual ~T_Cloud() {} ;
    /**
     * GetNbPoints returns the number of points in the cloud.
     */
    virtual int GetNbPoints() const = 0 ;
    /**
     * GetCoords returns the 3D coordinates of the <tt>iNum</tt>'th point.
     */
    virtual void GetCoords (const int iNum, float oCoords[3]) const = 0 ;
    /**
     * isToBeTreated returns 1 if the 'iNum'th point is to be treated else returns 0.
     */
    virtual int isToBeTreated (const int iNum) const = 0 ;
  } ;

  // Constructeur
  CATCldMeshEnrichment ();

  // Destructeur
  virtual ~CATCldMeshEnrichment() ;

  // Erreur de corde : Si nulle tous les points sont maillés.
  void SetChordalError( float ErreurCordeMesher ) ;
  float GetChordalError() ;

  // Run the algorithm : ne sert plus à rien.
  unsigned int Run() ;

  // The result is a table of vertices.
  unsigned int GetResult (int** oTableOfVertices,
                     int &oNbVertices) ;

  // update of initial values
  unsigned int SetInitial (float *iPtCld,
                      int   iNbPtCld) ;

  // SetFonctionCallOn Progress Step
  unsigned int SetfctOnStep (fctOnStep) ;

  // GetError retourne l'erreur detecte
  int GetError() ;

  // Pour setter un maillage Seed, au lieu de le calculer.
  void  SetPolygonSeed(T_Mesh* iMeshSeed);

  // DEPRECATED : to be replaced by SetPolygonSeed(T_Mesh* iMeshSeed).
  //void  SetPolygonSeed(CATCldPolygon* iPolygonSeed);

  // Pour setter les point à merger.
  void SetBodyToMerge(T_Cloud* iToMerge);

  // DEPRECATED : to be replaced by SetBodyToMerge(T_Cloud* iToMerge).
  //void SetBodyToMerge(CATCldBody* iBodyToMerge);

  // The result is a table of vertices.
  void GetResult(int& oNbVertices, float*& oVerticesCoords, int& oNbTriangles, int*& oTriangles );

  // DEPRECATED : The result CATCldBody.
  //CATCldBody*  GetResult () ;

  // Pour ordonner les donnees
  inline unsigned int GetDataOrdered() ;

  // Pour reordonner les points en sortie du maillage
  inline int* GetTableIndirectionPt() ;

  inline void SetMaxRecursivityLevel(int iMaxLevel);

  inline void SetMaxDistance(double iMaxDistance);
  inline void UnSetMaxDistance();

  // Set mode de projection :
  // iMode = 0, IDerection = NULL -> Normal Projection
  // iMode = 1, idrection = {Xdir,Ydir,Zdir} -> projection suivant direction (Xdir,Ydir,Zdir)
  void SetProjectionMode(int iMode, double* iDirection);

  // For terrain modeling need :
  // If you set iConfusedTolerance > 0. (0. is the default value), all points used for
  // Enrichment which distance with a vertex of the seed mesh is lower than iConfusedTolerance
  // will replace this vertex in the triangle.
  void CheckAndReplaceConfusedPoints(const double iConfusedTolerance) {_ConfusedTolerance = iConfusedTolerance;} ;

private:

  struct cellTri {
    int Vtx[3] ;
    struct cellTri * Cnx[3] ;
    int DMax ;
    int PMax ;
    int ListPt ;
    int FlagTri ;
    int Num[2] ;
  } ;
  struct QVoxels {
    int    _IJK[3] ;
    double _Distance ;
  } ;

  // Data members :
  // Pour le mailleur de l'INRIA
  IFCmdlAnalyzerNoVisu* _Mesher ;

  //CATGeoFactory *_Factory ;

  // Interfacage avec la commande

 // CATCldBody	  * _iptrCloudOfPoints ;		// Le nuage de points
	//int           * _indexesOfSelectedPoints ;	// Les index des points
  T_Cloud* _CloudToMerge;

  // Pour creer le polygone graine
  //CATCldBody *_BodySeed ;
  //CATCldPolygon *_PolygonSeed ;
  T_Mesh* _MeshSeed;

  // Pour le CATCloud des points hors tolerance
  //CATCldBody *_BodyCloud ;

  // Pour creer les polygones a chaque passe
  //CATCldBody **_BodyEvolution ;

  // Erreur de corde du mailleur
  float _ErreurCordeMesher ;
  float _FactorEC ;
  float _ErreurCordeMesherMini; // Erreur de corde minimum accepte
  double _Factor_Dist_Inv;	// C'est l'inverse du FACTOR_DIST_INT permettant d'avoir la distance Pt/Tr en int
  // Erreur du filtre adaptatif
  float _ErreurFiltre ;

  // For the number of the error
  int _NumError ;

  // Opposite points of the Bounding Box
  float _MinPt[3], _MaxPt[3] ;
  // Diagonale of the Bounding Box
  float _Diag ;
  // Distance Moyenne entre 2 points du nuage
  float _Moy2Pt ;
  // Table of points
  float *_TablePt ;
  // Number of points
  int _NbTotalPoint ;
  // The box minmax in 3D of the CATCloud
  //CATCldBox _minBox ;
  // Table of vertices of the tesselation
  int *_tableOfVertices ;
  // Number of vertices of the Tesselation
  int _nbVertices ;

  // GDD : Pour interfacer avec l'appelant pour recuperer les resultats au travers du GetResult
  //	   Une fois charges des la phase d'enrichissement, toutes les autres structures peuvent
  //	   et doivent etre detruites pour liberer la place pour la construction du polygone
  //       avec les structures de donness CATCldPolygon

  int  * _ResultTableOfVertices ; 
  int   _ResultNbVertices ;


  // Size of Point (3 float)
  int _SzPnt ;
  // Flags des points actifs (TRUE)
  unsigned char *_FlagActif ;
  unsigned int _FiltreActif ;
  // Number of Active point
  int _NbPointActif ;
  // Distance between 2 points
  float _DistResolution ;

  // Tolerance points confondus.
  double _ConfusedTolerance;

  // Flags des points actifs du second Filtre (TRUE)
  unsigned char *_FlagActif_SecondFiltre ;
  unsigned int _Second_Filtre_Actif;	// Si TRUE est actif
 
  // Nombre de triangles du maillage
  int _NbTriangle ;
  // Nbre de triangles visites lors de la NormalProjectionInTriangle
  int _NbTrianglePredec ;
  // Pointeur sur la liste des triangles visites lors de la NormalProjectionInTriangle
  int* _TrianglePredec ;
  // tableau donnant la distance max du point le + eloigne pour chaque triangle
  // utilise dans AlgoEnrichment a chaque passe pour pouvoir trier les triangles sur les DMax
  //long* _TabDistance ;
  CATLONG32* _TabDistance ;

  // Parametres pour la projection (DNR)
  unsigned int            _NormalProjection;        // Projection Normale ou suivant direction.
  double*                 _ProjectionDirection;    // Driection de projection si ...

  // Compteur sur le nombre de passage
  int _NbNormalProj ;
  int _NbNormalProjVoxel ;
  int _NbNormalProjTri ;
  // Pour le calcul du temps total du Mesher
  double _TpsTotal ;
  // Nombre de passes effectuees sur l'ensemble des triangles
  int _NumPasse ;
  // Statistiques pour l'enrichissement
  int _NbNewProjection ;
  int _ProjectionFalse ;
  int _NbTgleBordLibre ;
  int _ErreurProjection ;
  int _NbFlipEdge ;
  int _TailleTabTriangle ;
  int _TailleIncrementTriangle;	// GDD : 31-07-02 - Pour ne plus incrementer a chaque passe (StructTriNew)
  int _ConnexeCommun ;
  int _ErreurGetCoordBary ;
  int _PbProjectionPMax ;
  int _NbBasculementSurCnx ;
  int _NbInsertionSurVtxInterieur ;
  int _NbGetChoixSupport;

  // Pour ordonner les donnees
  unsigned int _DataOrdered ;

  // Table indirection des points
  int *_TableIndirectionPt ;

  // Pointeur sur la table des pointeurs sur les cellules triangles
  struct cellTri** _Triangle ;

  // Creation d'un triangle Tmp pour la phase d'enrichissement
  struct cellTri* _TrianglePereTmp ;

  // Pour la liste des points chaines par triangles
  int* _LPOfTriangle ;

  int _MaxRecursivityLevel; // Niveau max de recursité pour CritereFlipEdge.
                            // Par defaut 100, -1 -> infini.

  double _MaxDistance;      // Distance maxi (point / graine)au dela de laquelle 1 point n'estpas inserré.
                            // -1 si indifferent ou bien > 0. sinon.

  // For the adaptative Filter
  unsigned int Filter (const float Param) ;

  // Filtrage unitaire avec table de points actif en entree/sortie
  unsigned int Filter_Unit (	float * iXYZPnt, int iNbrePnt,  float Param,
						unsigned char *ioEstActif, int &oNbrActif) ;
 
  // For the enrichment of the Mesher
  unsigned int Enrichment() ;

  // Algorithme d' Enrichissement de la graine
  unsigned int AlgoEnrichment() ;

  // Creation du polygone graine en sortie du maillage de l'INRIA.
  unsigned int CreatePolygonSeed() ;

  // Creation des polygones pour chaque passe
  // unsigned int CreatePolygonEvolution (int No) ;

  // Pour le DataProcess

  // Pre traitement sur les donnees
  unsigned int DataProcess() ;

  // Pour ordonner les donnees
  //unsigned int DataProcessOrdered() ;

  // Computes the number of voxels
  unsigned int DataProcessSizeVoxel() ;

  // Stats sur le nuage de points
  unsigned int DataProcessStats() ;

  // For the Projection
  unsigned int Projection() ;


  unsigned int _OnlyActive ;
  unsigned int _Is_Flip_Edge;
  unsigned int _NbTotVxl ;
  int _NbFullVxl ;
  int _NbVxl[3] ;
  float _Delta[3] ;
  float _Coef[3] ;
  int* _VxlTriRelations ;
  float* _VxlTriNormale;	// GDD Pour les normales de la graine
  char* _FlagTriangles ;

  int*    _NoFullVoxel;
  double* _DistMinVoxel;

  int _Max_Pnts_INRIA;	// Le Nombre de Points maxi pour le mailleur de l'INRIA. On va filtrer 
						// en visant cette valeur en fonction de l'erreur de corde objectif

  // Utilitaires

  // Nettoye tout (enfin presque) !!!
  // Option = TRUE, on fait le maximum
  //        = FALSE, on ne detruit pas le necessaire pour faire le GetResult
  void CleanAllStuff (unsigned int Option = 1) ;

  // Calcule la distance au carre entre 2 points (coord. float en entree)
  inline double Distance2Pnt2Pnt (float X[3],
                                  float Y[3]) ;
  // Recupere les coords float des NbPt points passes en argument
  //unsigned int GetNumCoords (int NbPoint, int* NoPoint, float* oCoords) ;

  // Recupere les numeros NoTri des NbTri passes en argument sous forme de cellTri
  //unsigned int GetNumTriangle (int NbTri, cellTri** ListTri, int* oNoTri) ;

  // Recupere les coords float d'un point (passe avec son numero de vertex)
  //inline unsigned int GetCoordsVertex (int NoVertex, float oCoords[3]) ;

  // Recupere les coords float d'un point (passe avec son numero de vertex)
  inline unsigned int GetPtrCoordsVertex (int NoVertex,
                                     float* &oCoords) ;

  // Recupere les coords float d'un point (passe avec son numero de point)
  //inline unsigned int GetCoordsPoint (int NoPoint, float oCoords[3]) ;

  // Recupere les coords float d'un point (passe avec son numero de point)
  inline unsigned int GetPtrCoordsPoint (int NoPoint,
                                    float* &oCoords) ;

  // Recupere les 3 indices (dans oVtx) des vertices d'un triangle NoTri
  inline unsigned int GetVerticesOfTriangle (int NoTri,
                                        int oVtx[3]) ;

  // Calcul des coord. barycentriques du point projete Proj sur le triangle
  // ayant pour sommets CoordsVtx (table de 9 floats passee en argument) .
  //unsigned int GetCoordBary (int NoPt, float Proj[3], float CoordsVtx[9], float &oU, float &oV) ;

  // Calcule l'aire du triangle (coords float des Vtx passees en argument) .
  inline unsigned int CarreAireTriangle (float P1[3], float P2[3], float P3[3], float &oAire) ;

  // Calcul du support de projection du point Proj se projettant sur le triangle Tri
  unsigned int ChoixSupportProjection (float iToProj[3], cellTri* Tri, int &oNumVtx1, int &oNumVtx2) ;

  // Utilitaires de verification (mode debug only !!!)

  // Verifie que tous les points eradiques sont a une distance inferieure a l'E.C (mode debug)
  // Renvoie le CATCloud des points hors tolerance.
  //unsigned int AlgoProjectionAllPt (CATCldPolygon* Polygon,
  //                             CATCldCloud* Cloud) ;

  // Verifie la coherence des donnees (sollicitee en mode debug only !)
  // unsigned int Verif (int NoTri) ;

  // Verifie que le triangle partage bien une arete avec ses voisins (mode debug only !)
  // unsigned int VerifVoisinageOK (cellTri** Tri, int NbTriangle) ;

  // Verifie que le PMax se projette bien sur le Triangle Tri (mode debug only !)
  // unsigned int VerifProjectionOK (int NoPt, cellTri* Tri) ;

  // Sur les Structures TRIANGLES

  // Structure des Triangles
  unsigned int StructTri() ;

  // Creation et initialisation d'une nouvelle structure triangle
//  unsigned int StructTriNew (int iTailleTabTri) ;
  unsigned int StructTriNew () ;

  // Creation et initialisation d'une nouvelle cellule triangle
  unsigned int AddNewtri (int &oNoTri) ;

  // Restauration de la structure de donnees.
  unsigned int RestoreStrucTri (const int iNbTriangle) ;

  // Mise a Null d'une cellule triangle (PMax et ListPt sont mis a -1)
  unsigned int MiseANullTriangle (cellTri* Triangle) ;

  // Sur les Structures POINTS

  // Mise en place de la liste des points, de taille NbTotalPoint, chaines par triangles
  unsigned int ListPointOfTri (int NbTotalPoint) ;

  // Chainage d'un point dans la Liste Point d'un triangle Tri (donne sous forme de pointeur)
  unsigned int InsertPtInListPt (int NoPt,
                            cellTri* Tri) ;

  // Projection d'un point, connaissant une liste de triangles

  // Projection d'un point NumPoint sur une ListTri de NbTriangle (donne sous forme de pointeur)
  unsigned int ProjectionTriangles ( int NumPoint,
                                     cellTri** ListTri,
                                     int NbTriangle,
                                     float *oProj,
                                     int &oTriPlusProche,
                                     int &oNumVtx1,
                                     int &oNumVtx2,
                                     double &oDist,
                                     const float iTolerance) ;

  // Projection d'un point sur NbTriangle triangles fils
  // et chainage du point dans la cellule triangle
  unsigned int AlgoProjectionTriangles (int NumPoint,
                                   cellTri** ListTri,
                                   int NbTriangle,
                                   const float iTolerance) ;

  // Projection des points d'une ListPoint sur une liste de triangles
  unsigned int ProjectionPtOfListPt (int ListPt,
                                cellTri** ListTri,
                                int NbTriangle) ;

  // Pour le FLIP EDGE

  // Critere de Flip Edge pour chaque triangle, le flip est active si FLIP = TRUE
  // En entree, le numero de l'edge de Tri1 commune (mis a -1 si on ne le connait pas)
  unsigned int CritereFlipEdge (cellTri* Tri1,
                           cellTri* Tri2,
                           int NoEdge1,
                           int FLIP) ;

  // Flip Edge de l'arete NVtx1-NVtx2 entre les triangles Tri1 et Tri2 si critere de qualite OK
  unsigned int FlipEdge ( int NVtx1,
                          int NVtx2,
                          cellTri* Tri1,
                          cellTri* Tri2) ;

  // Etude de la qualite du triangle (coords float des Vtx passees en argument) .
  unsigned int QualiteTriangle (float P1[3],
                           float P2[3],
                           float P3[3],
                           double &oQualite) ;

  // Etude de la qualite du triangle (Numero de triangle donne).
  unsigned int QualiteTriangle (const int iNoTri, double &oQualite) ;

  // Recherche si 2 triangles ont un ConnexeCommun
  unsigned int ConnexeCommun (cellTri* Tri1, cellTri* Tri2) ;

  // Tests sur les Edges, Vertices et Connexes

  // Returns the next triangle-indice modulo 3.
  inline int Next (const int iTIndex) const ;

  // Returns the previous triangle-indice modulo 3.
  inline int Prev (const int iTIndex) const ;

  // Returns the opposite vertex triangle-indice of an edge given by its triangle-indice.
  inline int OppositeVertex (const int iITEdge) const ;

  // Tests if a point iNoVertex belongs to a given triangle and return its relative indice.
  inline unsigned int IsAVertexOf (int iNoVertex,
                              cellTri* Tri,
                              int &oITVertex) ;

  // Tests if an edge given by its vertices relative indices belongs to a given triangle.
  inline unsigned int IsAnEdgeOf (int iNoVertex1,
                             int iNoVertex2,
                             cellTri* Tri,
                             int &oITEdge,
                             int &oSens) ;

  // Test s'il existe une edge entre les 2 triangles.
  unsigned int IsVoisinOk (cellTri* Tri1,
                      cellTri* Tri2) ;

  // Pour le traitement des bords libres

  // Test s'il existe un triangle Tri2 partageant l'arete IEdge (indice relatif) d'un triangle Tri1
  inline unsigned int ShareEdge (int IEdge,
                            cellTri* Tri1,
                            cellTri* &oTri2) ;

  // Renvoie l'angle en degre fait entre deux vecteurs V1V2-V1V3
  float GetAngle (int iNoVtx1,
                  int iNoVtx2,
                  int iNoVtx3) ;

  // Recupere un triangle oTri2, son edge de bord libre oVtxBord et le sens de l'edge (+/-1)
  // partageant le meme vertex NoVtx1.
  // Le triangle initial Tri1 a l'arete NoVtx1-NoVtx2 de bord libre
  unsigned int GetTriangleBord (int NoVtx1,
                           int NoVtx2,
                           cellTri* Tri1,
                           cellTri* &oTri2,
                           int &oVtxBord,
                           int &oSens) ;

  // Recupere un triangle oTri2, son edge de bord libre oVtxBord et le sens de l'edge (+/-1)
  // partageant le meme vertex NoVtx1.
  // Le triangle initial Tri1 n'est pas forcement de bord libre
  unsigned int GetTriangleVtx (int NoVtx1,
                          cellTri* Tri1,
                          cellTri* &oTri2,
                          int &oVtxBord,
                          int &oSens) ;

  // Recupere une liste de triangles ListTri, partageant le meme vertex NoVtx1.
  // Renvoie le nombre de triangle NbTri et s'ils st connexes (CnxOk a TRUE)
  //unsigned int GetTrianglesVtx (int NoVtx1,
  //                         cellTri* Tri1,
  //                         cellTri** &oListTri,
  //                         int &oNbTri,
  //                         unsigned int &oCnxOk) ;

  // Critere de longueur d'arete pour les triangles de bord (numero vertex passes en argument)
  // Si la distance V0V1 < (V0V2) et (V0V1) < (V1V2) , renvoie TRUE. Sinon, renvoie FALSE.
  unsigned int CritereLongueurArete (int V0, int V1, int V2) ;

  // Pour l'insertion de points

  // Insertion du point max se projetant sur un VERTEX du triangle NoTri
  unsigned int InsertionSurVertex (int NoTri) ;

  // Insertion du point max se projetant sur une EDGE du triangle NoTri
  unsigned int InsertionSurEdge (int NoTri) ;

  // Insertion du point max se projetant dans un TRIANGLE NoTri
  unsigned int InsertionDansTriangle (int NoTri) ;

  // Split de 1 triangle en 3 triangles
  // On passe en argument les 3 vtx, les 3 cnx et le PtMax du triangle pere,
  // ainsi que les 3 numeros des nouveaux triangles a initialiser.
  unsigned int Split3Triangle (int Vtx[3],
                          cellTri* Cnx[3],
                          int T[3],
                          int PtMax) ;

  // Copie le Triangle NoTri avec ou sans remise a zero des champs de l'emetteur
  unsigned int CopyTriangle (int NoTri,
                        unsigned int MiseANull) ;

  // Restoration du Triangle NoTri avec _TrianglePereTmp (rempli avant chaque insertion
  unsigned int RestoreCopyTriangle (int NoTri);

  fctOnStep _fonctionOnStep ;

  unsigned int IncrementStep() ;

  unsigned int IsABadFlip(float P1[3], float P2[3], float P3[3], float P4[3]);

  unsigned int IsOnEdge(const int iVtx, const int iVtxEdge0, const int iVtxEdge1);
  unsigned int IsNullTriangle(const int iNoTri);

  // DEPRECATED.
  unsigned int _SeedToBeDeleted;
  unsigned int _BodyToMergeToBeDeleted;



} ;

//--------------------------- METHODES INLINE --------------------------

//// Pour la voxelisation
//
////-------------------------------------------------------------------------
//// Function : TestAndFlag (CATCldPartitionPolygon Implementation)
//// Purpose : Tests if the triangle is flagged, if not, flag the triangle.
////-------------------------------------------------------------------------
//
//inline unsigned int CATCldMeshEnrichment::TestAndFlag (const int iNoTri) const
//{
//  unsigned int Flag = _FlagTriangles[iNoTri/8]& (1<<iNoTri%8) ;
//  if (Flag) return Flag ;
//  _FlagTriangles[iNoTri/8] |= (1<<iNoTri%8) ;
//  return Flag ;
//}

//-------------------------------------------------------------------------
// Function : RazFlagTriangles (CATCldPartitionPolygon Implementation)
// Purpose : Sets _FlagTriangle of a Polygon to zero.
//-------------------------------------------------------------------------
//
//inline unsigned int CATCldMeshEnrichment::RazFlagTriangles (CATCldPolygon* Polygon) const
//{
//  if (Polygon == NULL) return FALSE ;
//  int NbTriangles = Polygon->GetNbTriangles() ;
//  memset (_FlagTriangles, 0, (NbTriangles/8+1) *sizeof (char)) ;
//  return TRUE ;
//}
//
//-------------------------------------------------------------------------
// Function : NumVoxel (CATCldPartition Implementation)
// Purpose : Computes the voxel index.
//-------------------------------------------------------------------------
//
//inline int CATCldMeshEnrichment::NumVoxel (const int IVxl,
//                                               const int JVxl,
//                                               const int KVxl) const
//{
//  return (1 + IVxl + _NbVxl[0] * (JVxl + _NbVxl[1] * KVxl)) ;
//}
//
// Pour la projection

//-------------------------------------------------------------------------
// Function : Distance2Pnt2Pnt
// Calcule la distance au carre entre 2 point (coord. float en entree)
//-------------------------------------------------------------------------
inline double CATCldMeshEnrichment::Distance2Pnt2Pnt (float X[3],
                                                          float Y[3])
{
  float Dx = X[0]-Y[0] ;
  float Dy = X[1]-Y[1] ;
  float Dz = X[2]-Y[2] ;
  double Result = (double) (Dx*Dx + Dy*Dy + Dz*Dz) ;
  return Result ;
}

// Pour le FlipEdge

//-------------------------------------------------------------------------
// Function : Next (CATCldPolygonCGM Implementation)
// Purpose : Returns the next triangle-indice modulo 3.
//-------------------------------------------------------------------------

inline int CATCldMeshEnrichment::Next (const int iTIndex) const
{
  return (iTIndex + 1) % 3 ; // (I+1) %N
}

//-------------------------------------------------------------------------
// Function : Prev (CATCldPolygonCGM Implementation)
// Purpose : Returns the previous triangle-indice modulo 3.
//-------------------------------------------------------------------------

inline int CATCldMeshEnrichment::Prev (const int iTIndex) const
{
  return (iTIndex + 2) % 3 ; // (I+N-1) %N
}

//--------------------------------------------------------------------------------------------------
// Function : OppositeVertex (CATCldPolygonCGM Implementation)
// Returns the opposite vertex triangle-indice of an edge given by its triangle-indice.
//--------------------------------------------------------------------------------------------------
inline int CATCldMeshEnrichment::OppositeVertex (const int iITEdge) const
{
  return (iITEdge + 2) % 3 ; // Dans le cas d'un triangle = Prev (iITEdge)
}

//------------------------------------------------------------------------------------------
// Function : IsAVertexOf (CATCldPolygonCGM Implementation)
// Tests if a point iNoVertex belongs to a given triangle and return its relative indice.
//------------------------------------------------------------------------------------------
inline unsigned int CATCldMeshEnrichment::IsAVertexOf (int iNoVertex,
                                                      cellTri* Tri,
                                                      int &oITVertex)
{
  if (Tri == NULL) return 0 ;
  for (oITVertex = 0 ; oITVertex < 3 ; oITVertex++)
    if (Tri->Vtx[oITVertex] == iNoVertex) return 1 ;
  return 0 ;
}

//------------------------------------------------------------------------------------------------
// Function : IsAnEdgeOf (CATCldPolygonCGM Implementation)
// Tests if an edge given by its vertices relative indices belongs to a given triangle.
//------------------------------------------------------------------------------------------------
inline unsigned int CATCldMeshEnrichment::IsAnEdgeOf (int iNoVertex1,
                                                     int iNoVertex2,
                                                     cellTri* Tri,
                                                     int &oITEdge,
                                                     int &oSens)
{
  if (Tri == NULL) return 0 ;
  int IVtx, JVtx ;
  for (IVtx = 0 ; IVtx < 3 ; IVtx++) if (Tri->Vtx[IVtx] == iNoVertex1) break ;
  if (IVtx >= 3) return 0 ;
  JVtx = Next (IVtx) ;
  if (Tri->Vtx[JVtx] == iNoVertex2) {
    oITEdge = IVtx ;
    oSens = 1 ;
    return 1 ;
  }
  JVtx = Prev (IVtx) ;
  if (Tri->Vtx[JVtx] == iNoVertex2) {
    oITEdge = JVtx ;
    oSens = -1 ;
    return 1 ;
  }
  return 0 ;
}

//----------------------------------------------------------------------------------------
// Test s'il existe un triangle Tri2 partageant l'arete IEdge (indice relatif) d'un triangle Tri1
//----------------------------------------------------------------------------------------
inline unsigned int CATCldMeshEnrichment::ShareEdge (int IEdge,
                                                    cellTri* Tri1,
                                                    cellTri* &oTri2)
{
  if (Tri1 == NULL) return 0 ;
  if (!Tri1->Cnx[IEdge])
    return 0 ; // c'est un triangle de bord libre

  oTri2 = Tri1->Cnx[IEdge] ;
  return 1 ;
}

//----------------------------------------------------------------------------------------
// Calcul de l'aire du triangle (coords float des Vtx passees en argument) .
//----------------------------------------------------------------------------------------
inline unsigned int CATCldMeshEnrichment::CarreAireTriangle (float P1[3], float P2[3], float P3[3], float &oCarreAire)
{
  float P1P2[3] = {P2[0]-P1[0], P2[1]-P1[1], P2[2]-P1[2]} ;
  //float P2P3[3] = {P3[0]-P2[0], P3[1]-P2[1], P3[2]-P2[2]} ;
  float P3P1[3] = {P1[0]-P3[0], P1[1]-P3[1], P1[2]-P3[2]} ;
/*
  float X1 = P1P2[0] ; float Y1 = P1P2[1] ; float Z1 = P1P2[2] ;
  float X2 = -P3P1[0] ; float Y2 = -P3P1[1] ; float Z2 = -P3P1[2] ;
  float L = Y1*Z2 - Z1*Y2 ;
  float M = Z1*X2 - X1*Z2 ;
  float N = X1*Y2 - Y1*X2 ;
  oAire = (float) (0.5* sqrt (L*L + M*M + N*N)) ;
*/
//  oAire = (float) (0.5* sqrt (  (-P1P2[1]*P3P1[2] + P1P2[2]*P3P1[1]) * (-P1P2[1]*P3P1[2] + P1P2[2]*P3P1[1])
//                              + (-P1P2[2]*P3P1[0] + P1P2[0]*P3P1[2]) * (-P1P2[2]*P3P1[0] + P1P2[0]*P3P1[2])
//                              + (-P1P2[0]*P3P1[1] + P1P2[1]*P3P1[0]) * (-P1P2[0]*P3P1[1] + P1P2[1]*P3P1[0])) ) ;
  oCarreAire = (float) (      (-P1P2[1]*P3P1[2] + P1P2[2]*P3P1[1]) * (-P1P2[1]*P3P1[2] + P1P2[2]*P3P1[1])
                            + (-P1P2[2]*P3P1[0] + P1P2[0]*P3P1[2]) * (-P1P2[2]*P3P1[0] + P1P2[0]*P3P1[2])
                            + (-P1P2[0]*P3P1[1] + P1P2[1]*P3P1[0]) * (-P1P2[0]*P3P1[1] + P1P2[1]*P3P1[0])) ;
//  if (oAire == 0.0) return FALSE ;
  return 1 ;
}

//----------------------------------------------------------------------------------------
// Recupere les coords float d'un Vertex
//----------------------------------------------------------------------------------------
inline unsigned int CATCldMeshEnrichment::GetPtrCoordsVertex (int NoVertex, float* &oCoords)
{
  oCoords = _TablePt + 3*(NoVertex-1) ;
  return 1 ;
}

//----------------------------------------------------------------------------------------
// Recupere les coords float d'un point (non vertex)
//----------------------------------------------------------------------------------------
inline unsigned int CATCldMeshEnrichment::GetPtrCoordsPoint (int NoPoint, float* &oCoords)
{
  oCoords = _TablePt + 3*NoPoint ;
  return 1 ;
}

//----------------------------------------------------------------------------------------
// Recupere les 3 indices (de la table des points) des vertices d'un triangle NoTri
//----------------------------------------------------------------------------------------
inline unsigned int CATCldMeshEnrichment::GetVerticesOfTriangle (int NoTri, int oVtx[3])
{
  if (_Triangle == NULL) return 0 ;
  if ((_Triangle[NoTri]->Vtx[0] <= 0) || (_Triangle[NoTri]->Vtx[0] > _NbTotalPoint) ||
      (_Triangle[NoTri]->Vtx[1] <= 0) || (_Triangle[NoTri]->Vtx[1] > _NbTotalPoint) ||
      (_Triangle[NoTri]->Vtx[2] <= 0) || (_Triangle[NoTri]->Vtx[2] > _NbTotalPoint)) {
    return 0 ;
  }
  // (!) Les vertices vont de 1 a _NbTotalPoint, les NoPt varient de 0 a _NbTotalPoint-1.
  // On recupere donc les NoVtx-1 pour avoir les bons numeros de points.
  oVtx[0] = _Triangle[NoTri]->Vtx[0]-1 ;
  oVtx[1] = _Triangle[NoTri]->Vtx[1]-1 ;
  oVtx[2] = _Triangle[NoTri]->Vtx[2]-1 ;

  return 1 ;
}

//----------------------------------------------------------------------------------------
// Pour ordonner les donnees
//----------------------------------------------------------------------------------------
inline unsigned int CATCldMeshEnrichment::GetDataOrdered()
{
  return _DataOrdered ;
}

//----------------------------------------------------------------------------------------
// Pour reordonner les points en sortie du maillage
//----------------------------------------------------------------------------------------
inline int* CATCldMeshEnrichment::GetTableIndirectionPt()
{
  return _TableIndirectionPt ;
}

//----------------------------------------------------------------------------------------
// Pour jouer avec le niveau de recursivité de CritereFlipEdge (...) 
//----------------------------------------------------------------------------------------
inline void  CATCldMeshEnrichment::SetMaxRecursivityLevel(int iMaxLevel)
{
  _MaxRecursivityLevel = iMaxLevel;
}
//----------------------------------------------------------------------------------------
// Pour jouer avec le niveau de recursivité de CritereFlipEdge (...) 
//----------------------------------------------------------------------------------------
inline void  CATCldMeshEnrichment::SetMaxDistance(double iMaxDistance)
{
  if (iMaxDistance >= 0.) _MaxDistance = iMaxDistance;
  else _MaxDistance = -1.;
}
//----------------------------------------------------------------------------------------
// Pour jouer avec le niveau de recursivité de CritereFlipEdge (...) 
//----------------------------------------------------------------------------------------
inline void  CATCldMeshEnrichment::UnSetMaxDistance()
{
  _MaxDistance = -1.;
}

#endif
