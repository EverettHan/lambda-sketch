// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
//
// CATSectionDeformation:
//    Olivier Bellart
//=============================================================================
// Usage notes:
//
//
//   Deformation of evaluated profile to make it G1 on split Points.
//   Vertices is virtually [iVerticesNumber][3] dimensionned
//   iDeformEffectivity must be  between 0. and 1. and arry dimension is
//   isplit Number
//   Comments : The following method is as of today a private method.
//   But its scope may be quite larger .
//   has to be transformed in global function if necessary. It refers to no
//   private Data
//   It is assumed that Vertex [ iSplitIndex[j]] and Vertex [ iSplitIndex[j]+1]
//   are equal .

//=============================================================================
// 30 08 99 CPL Creation
// 12/03/04 MNA : J'ajoute la Factory dans le constructeur de l'objet && _Factory donnee membre.
// 01/04/04 MNA : Mise en place d'une nouvelle methodologie de calcul des deformations
//                  des sections via l'utilisation du SimilarCurve (Deformation globale
//                  de la courbe; differente de la deformation tres localisee effectuee jusqu'a
//                  present) :
//
//                  1-Cacul des tangentes a imposer en fonction de la courbure des courbes adjacentes
//                    Nouvelles donnees membres :_NewTangente (tangente a imposer)
//                                               _SimilarDeformToDo doit on deformer l'extremité (i.e. 
//                                               a-t-on imposé une tangente)
//                  2-La courbure est donne grace a une loi d'effectivité stockée dans CATBreakInfo et calculée
//                    au niveau du SectionDeformEngine.
// 
//  02/2004 MNA ComputeLengthBetweenCPS() : Permet de calculer la longueur du polygone de Controle entre 2 
//              points de controle
//  02/2004 MNA DebugVisuMultiformes() : Dump des multiformes + Visualisation
//  02/2004 MNA Ajout de la SoftwareConfig en argument dans cet objet
// 21/02/04 MNA Ajout de _UpdateCPSNecessary ( i.e. Mise a jour des points de controles apres la methode DeformToG1)
// 24/02/04 MNA Ajout de _GlobalDeformationWithSimilar:
//                          ---0: Deformation Locale,
//                          ---1: Deformation Globale
// 25/02/04 MNA Ajout d'un parametre dans le constructeur: iIsTangent, nous dit s'il y a des tangences imposees (0: non, 1: oui)
// 22/02/04 MNA Ajout de la variable _IsAllocated
// 26/08/04 JSX Ajout de _IsOnGuide pour ne pas deplacer dans les "flatzones" les points en contact d'une guide RI 464000
// 13/07/06 NLD Ajout de DebugConvertMultiFormToBody()
// 31/08/06 JSX Ajout de SetPointDeformation. Permet une deformation préalable des profils, pour qu'ils collent aux guides
// 28 09 06 JSX Ajout de GetPointDeformation et de la variable _PointDeformation
// 25/03/10 JSX Continuité G2 du Profil (Interne et Externe)
//              Ajout DeformToG2 et factorisation avec RunSimilar
// 08 04 10 JSX Deformation G2 + Menage de nomenclature (_DeformEffectivityG1/_DeformEffectivityG2/Balance)
// 27 06 10 JSX Deformation G2: Je veux pouvoir deformer en G1 sans deformer G2 ( deformation trop grande des profils)
//              Suppression de _PointDeformation et ajout de _KindOfDeformation et _DeformationContinuity
//              _ComputeDeformation peut etre activé sur un eval classique (eval complet)
// 28 09 10 JSX Ajout SetExtContCorrectionMode et suppression du code du .h
// 24/12/10 JSX Deformation par domaine par concatenation de multiforme
//              (la concatenation relle n'est faite qu'une fois, ensuite on copie les points de controle
//              ajout de _DeformByDom et _MultiTab
// 18/06/14 NLD Smart indent
// 12/12/22 NLD Mise au clair de GetDeformation()/_ComputedDeformation
//              - ajout de GetLastDeformation() et _LastComputedDeformation
//              - GetDeformation() et _ComputedDeformation restent
//                relatifs au max de toutes les deformations
//=============================================================================

#ifndef CATSectionDeformation_H
#define CATSectionDeformation_H

// remarque: les NurbsMultiForm ont ete reorientees avant l'appel 
// a l'evaluateur de maniere a ce que la fin de l'une soit le debut de
// la suivante

#include "FrFOpeCrv.h"

#include "CATMathDef.h"
#include "CATCGMVirtual.h"
#include "CATFreeFormDef.h"
#include "CATMathPlane.h"
#include "CATListOfInt.h"
class CATGeoFactory;
class CATSoftwareConfiguration;
class CATFrFNurbsMultiForm ;
class CATBreakInfo;
class CATMathPoint;
class CATMathVector;
class CATFrFSimilarCurve;
class CATBody;

class ExportedByFrFOpeCrv CATSectionDeformation : public CATCGMVirtual
{
 public:
 
           CATSectionDeformation   (      CATGeoFactory            * iGeoFactory            ,
                                          CATSoftwareConfiguration * iSoftwareConfig        ,
                                          CATLONG32                  iNbElements            ,
                                          int                        iLocalDeform           );

  virtual ~CATSectionDeformation   ();

  void     SetClosure              (      CATBoolean                 isClosed               );

  void     DeformSection           (      CATFrFNurbsMultiForm    ** ioSection              ,
                                          CATBreakInfo            ** iBreakInfo             );

  void     DeformSection           (      CATFrFNurbsMultiForm    ** iSection               ,
                                          CATFrFNurbsMultiForm    ** oSection               ,
                                          CATBreakInfo            ** iBreakInfo             );

  // To choose External and/or Internal deformation
  // 0: no deformation
  // 1: External
  // 2: Internal
  // 3=1+2 : External + Internal
  void     SetKindOfDeformation    (      CATLONG32                  iKindOfDeformation     = 3);

  // To choose level of continuity (G1 will not correct G0 / G2 is G1 then G2 correction) 
  void     SetDeformationContinuity(      CATFrFContinuity           iDeformationContinuity = CATFrFCurvatureCont);

  // To choose External CorrectionMode
  // 1=>Projection de ptG1 su plan Tangent
  // 2=>Intersection avec le plan du MvFrame passant par G1
  void     SetExtContCorrectionMode(      CATLONG32                  iExtContCorrectionMode = 1);

  // SetDeformByDomain
  //  1 Deformation a l'interieur des domaines seulement
  //  2 Deformation des domaines pour respecter les contraintes externes ou entre domaines
  // commentaires NLD131222
  void     SetDeformByDomain       (      CATLONG32                  iLocalVsGlobal         );

  // Compute and Get the deformation (distance) between Input and Output profile
  void     SetComputeDeformation   (      CATBoolean                 ActiveComputation      = TRUE);
  double   GetDeformation          (); // global max
  double   GetLastDeformation      (); // max pour dernier DeformSection() EN COURS NLD121202

  // Give moving frame plane ( new way of computing profile tangency direction)
  void     SetMovingFramePlane     (const CATMathPlane             & MvFrPlane              );

  void     ComputeDomain           (      CATBreakInfo           **  iBreakInfo             ,
                                          CATLONG32                & oEnableMultiDomaine    );

 private:

   void    DeformToExtConstraints  (      CATLONG32               *  iPseudoOrder           ,
                                          CATBreakInfo           **  iBreakInfo             );
   void    DeformToG1              (      CATLONG32               *  iPseudoOrder           ,
                                          CATBreakInfo           **  iBreakInfo             );
   void    DeformToG2              (      CATFrFNurbsMultiForm   **  ioSection              ,
                                          CATLONG32               *  iPseudoOrder           ,
                                          CATBreakInfo           **  iBreakInfo             );
   void    FlatZoneDeformation     (      CATLONG32                  StartFlatZone          ,
                                          CATLONG32                  EndFlatZone            );
   void    QuadraticZoneDeformation(      CATLONG32                  Vertex                 ,
                                          double                     TargetDX               ,
                                          double                     TargetDY               ,
                                          double                     TargetDZ               ,
                                          double                     DelayedTargetDX        ,
                                          double                     DelayedTargetDY        ,
                                          double                     DelayedTargetDZ        );

   double  ComputeLengthBetweenCPS  (     CATLONG32                  iIndStartVertex        ,
                                          CATLONG32                  iIndEndVertex          );
   // DEBUG
   void    DebugVisuMultiForm       (     CATFrFNurbsMultiForm    *  iSection               ,
                                          int                        idefault               = 0);
   CATBody* DebugConvertMultiFormToBody(  int                        iNbMulti               ,
                                          CATFrFNurbsMultiForm   **  iSections              ) ;
   void    Alloc                    (     CATFrFNurbsMultiForm   **  iSection               );
   void    RunSimilar               (     CATFrFNurbsMultiForm   **  iSection               ,
                                          CATLONG32                  ICont                  );

   CATLONG32 TransferTabNurbsToMultiNurbs(CATLONG32                  sens                   ,
                                          CATFrFNurbsMultiForm   **  TabOfSection           );

   //==========================================================================================
   // DATA
   //==========================================================================================
 private:

   CATGeoFactory            * _Factory;
   CATSoftwareConfiguration * _SoftwareConfig;
   int                        _CGMLevel;
   double                     _Tol;

   CATLONG32                  _NbElt;
   CATBoolean                 _Closed;
   CATBoolean                 _IsAllocated;


   CATLONG32                  _NbVertices;
   double                   * _Vertices;
   CATLONG32                * _NbCtrlPoints;
   CATMathPoint            ** _CtrlPoints;
   CATLONG32                  _SplitNumber;
   CATLONG32                * _SplitIndex;
   CATMathPoint             * _NewPoint   ;                 // Points    a appliquer au SimilarCurve
   CATMathVector            * _NewTangente;                 // Tangentes a appliquer au SimilarCurve
   CATMathVector            * _NewCurvature;                // Courbures a appliquer au SimilarCurve
   CATLONG32                  _ExtremCurvatureMode[2];      // Indique si les courbure extremes sont de type
                                                            // Crv/Crv (profil fermé) ou Crv/Surf (g2 avec une surface)
   double                     _ExtremCurvatureValue[2];     // Courbure dans les cas Crv/Surf 
   CATMathVector              _ExtremCurvatureFixedDir[2];  // Direction dans laquelle la courbure ne doit pas changer.

   int                      * _IsOnGuide;                   // point a ne pas bouger sur une guide
   double                   * _DeformEffectivityG1;         // effectivité de la deformation G1 a appliquer  (chaque SplitIndex)
   double                   * _DeformEffectivityG2;         // effectivité de la deformation G2 a appliquer  (chaque SplitIndex)
   double                   * _DeformBalance;               // Balance entre la tangente à gauche et la tangente a droite  (chaque SplitIndex)

   CATFrFSimilarCurve      ** _SimilarSection;
   int                        _NbSimilarBySeg;

                                                            // Permet de savoir si on deforme au point donné. Attention à l'ordre.
                                                            // TPC 1=>tangence 2=>Point 4=>Courbure
   int                      * _SimilarDeformToDo;

   int                        _UpdateCPSNecessary;          // Mise a jour des points de Controle apres DeformToG1 (1=>On update)
   int                        _GlobalDeformationWithSimilar;// =1 on effectue une deformation Globale avec SimilarCurve (0 sinon)

// CATBoolean                 _PointDeformation;            // JSX Deformation en point uniquement placage des profils sur le guides avant cheminement

   // Calcul des deformations !
   CATBoolean                 _ComputeDeformation;
   double                     _ComputedDeformation;
   double                     _LastComputedDeformation;


  CATLONG32                   _KindOfDeformation;           //(3); // 0 no deformation 1:  external 2: Internal  3=1+2
  CATFrFContinuity            _DeformationContinuity; 

  // Mode pour la correction du G1 ( et aussi du g2 mais le G2 impose le Mode 2(intersetion avec le plan // au MvFrame)
  CATLONG32                   _ExtContCorrectionMode;       // 1:Projection sur le plan tangent de la guide
                                                            // 2:Intersection plan Tangent avec le plan // au MvFr passant par le point G1)


  CATBoolean                  _MvFrPlaneIsSet;
  CATMathPlane                _MvFrPlane;

  CATLONG32                   _DeformByDom;
  CATFrFNurbsMultiForm     ** _MultiTab;                    // Tableau de MultiForm Multi Elements (courbes entre 2 guides)
  CATListOfInt                _NbMultByDom;

} ;
#endif 
