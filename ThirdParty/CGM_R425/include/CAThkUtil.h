/* -*-C++-*- */

#ifndef CAThkUtil_H
#define CAThkUtil_H

//=============================================================================
//
// RESPONSABLE  : A Deleglise 
//
// DESCRIPTION  : Classe sans membre de donnees regroupant des methodes
//                publiques d'interet general pour shell / thickness
//                (evite d'en faire des fonctions avec une portee globale)
//
//=============================================================================

//=============================================================================
//          CHU Creation
//   /08/98 DPS Ajout de la methode FindWorkingInformations
//              (permettant de trouver la region entre 2
//              bitangences pour un fillet par exemple)
// 23/09/19 NLD ComputeVertexBodyInsideFace() recoit la configuration
//=============================================================================
#include "CATIACGMLevel.h"

#include "CATMathDef.h"
#include "CATTopDef.h"
#include "CATDBGDefine.h"
#include "ListPOfCATCell.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATEdge.h"
#include "CATListOfCATSurfaces.h"
#include "ListPOfCATBody.h"
#include "Thick.h"

class CAThkInitEdgeRep;
class CAThkContext;
class CAThkPoint;
class CAThkAlgoElt;
class CAThkAccuPt;
class CAThkSurfRep;
class CAThkFaceRep;
class CATOffSurAtt;
class CAThkCellRep;
class CAThkEdgeRep;
class CAThkInitVRep;
class CAThkManifoldInitERep;
class CAThkTrimByThickContext;
class CAThkHomotp;
class CAThkECrvToHealAnomaly;
class CAThkTptIteratorContext;
class CAThkEdgeRep;
class CATLISTP(CAThkEdgeRep);
class CATLISTP(CAThkInitVRep);
class CATLISTP(CAThkSurfRep);

class CATBody;
class CATVolume;
class CATFace;
class CATEdge;
class CATVertex;
class CATCell;
class CATBoundedCellsIterator;
class CATShell;
class CATDomain;
class CATCGMJournalList;

class CATSoftwareConfiguration;
class CATGeoFactory;
class CATPoint;
class CATCurve;
class CATSurface;
class CATOffsetSurface;
class CATPCurve;
class CATEdgeCurve;
class CATSurParam;
class CATSurLimits;
class CATCrvLimits;
class CATMathBox;
class CATCrvParam;
class CATPointOnEdgeCurve;
class CATPointOnCurve;

class CATMathPoint;
class CATMathDirection;
class CATMathVector2D;
class CATMathPlane;
class CAThkVertexRep;
class CATMathTransformation2D;



//--------------------------------------------------------------------------

class CAThkUtil
{

public:

  
  // Methode de creation d'un Body mono-vertex
  // a partir d'un vertex, et eventuellement du body s'il existe deja
  static CATBody * CreateBodyMonoVertex(CAThkContext *iContext, CATVertex * iVertex, CATBody * iBody=NULL);

  // Methode de creation d'un Body mono-wire-mono-edge
  // a partir d'une edge, et eventuellement du body s'il existe deja
  static CATBody * CreateBodyMonoWireMonoEdge(CAThkContext *iContext, CATEdge * iEdge, CATBody * iBody=NULL);

  // Methode de creation d'un Body mono-shell-mono-face
  // a partir d'une face, et eventuellement du body s'il existe deja
  static CATBody * CreateBodyMonoShellMonoFace(CAThkContext *iContext, CATFace * iFace, CATBody * iBody=NULL);

  // smart duplication d'un body pour le rendre modifiable.
  // note : on perd le smart.
  static CATBody * SmartDuplicateBody(CAThkContext *iContext, CATBody *iBody, CATLISTP(CATFace) &iFaceList);

  // Methode de creation d'un body mono wire
  // a partir d'une curve et de ses limites
  static CATBody * RunTopWire( CAThkContext * iContext, CATCurve * iCurve, CATCrvLimits * iLimits);

  // Recuperation de l'unique cellule contenue dans le domaine d'un body mono-domaine mono-cellule
  static CATCell * GetSingleTopCell( CATBody   *  iMonoDomainMonoCellBody,
                                     CATVertex ** oVertex = NULL,
                                     CATEdge   ** oEdge   = NULL,
                                     CATFace   ** oFace   = NULL,
                                     CATVolume ** oVolume = NULL );

  // recherche du shell contenant la face dans le volume
  static CATShell * GetOwningShellInBody(CATFace *iFace, CATBody *iBody);
  static CATShell * GetOwningShellInBody(CATFace *iFace, CATBody *iBody, CATSide *oSide);

  // Recuperation du bloc-lim utile specifique a une surface
  // ainsi que les edges frontieres et les surfaces voisines connues
  // (bitangences et appuis pour une surface-fillet par exemple)
  // les 3 derniers arguments sont des tableaux de 4 alloues en dure
  // par l'appelante
  static void FindWorkingBoxInformations(CAThkContext  * iContext,
                                         CATFace       * iFace,
                                         CATOffSurAtt  * iOffAtt,
                                         CATSurLimits  & oWorkingBox,
                                         CATEdgeCurve ** oFrontierEdges,
                                         CATSurface   ** oNeighbourSurf,
                                         short         * oRelativOrient);
  
  // Balayage des edges liant deux sommets donnes dans un body
  // L'iterateur est facultativement donne pour ameliorer les perfos, il doit 
  //    alors avoir ete construit avant le 1er Next et repasse de Next en Next
  //    puis detruit apres le dernier Next, c,a,d qiand le retour est NULL.
  // S'il n'est pas donne, il est construit et detruit dans Next, ce qui
  //    en interdit un usage repetitif (Next trouve alors la 1ere solution)
  // oV1ToV2 = +1 ou -1 en sortie selon que l'edge trouve va de iV1 vers iV2
  // Dans le cas particulier ou iTBTContext est fourni, on admettra comme solution
  // toute edge partant de iV1 et coupe par iV2 par presence d'un lien pose sur.
  static CATEdge * NextBetweenVertices(CATVertex * iV1, CATVertex * iV2,
                                       CATBody * iBody, CATEdge * iPrev, 
                                       short & oV1ToV2,
                                       CATPointOnEdgeCurve *& oPoec1,
                                       CATPointOnEdgeCurve *& oPoec2,
                                       CATBoundedCellsIterator * ioIter=NULL,
                                       CAThkTrimByThickContext * iTBTContext=NULL);

  // Alternative a CATVertex::GetGeometryOnEdgeAndFace. Les differences sont:
  //               1) Cette methode marche meme si la face a plusieurs loops
  //               2) On prend des sides en entree pour lever des ambiguites
  //                  eventuelles (CATSideUnknown si on ne sait pas a priori)
  static void GetVtxGeomOnEdgAndFace(CATVertex * iVtx, CATSide iVtxEdgSide, 
                                CATEdge * iEdg, CATSide iEdgFacSide, 
                                CATFace * iFace, CATPCurve *& oPCrv,  
                                CATCrvParam & oCrvParm);

  // offset d'un CATSurParam
  // iCheckOffsetSurfaceType permet de debrancher le check sur le type
  // de la surface quand on veut reporter de l'offset
  // vers l'originale (SheetMetal par exemple)
  static void WaitingForOffsetParam(CAThkContext*      iContext,
                                    const CATSurParam& iIniParam,
                                    CATSurface       * iIniSur,
                                    CATSurface*        iTargetSurface,
                                    CATSurParam&       oOutputParam,
                                    short              iCheckOffsetSurfaceType=1);

  // Recherche de l'indice de surface (temporaire) correspondant a 1 couple 
  // (Poec, surface) a l'interieur d'1 CAThkPoint
  // permet de lever les ambiguites quand une pcurve fermee a donne naissance
  // a une surface directionnelle temporaire fermee (=> double surparam sur 
  // la meme surface) 
  static short FindBestIndexTemporarySurface(CAThkPoint * iTpt,
                                             CATPointOnEdgeCurve * iPoec, 
                                             CATSurface * iSupportSurf,
                                             CATSurface * iTempoSurf,
                                             CATLONG32 &oBestIndex);

  // Import de la topo d'un body dans les sreps, ereps, vreps (debug), avec une
  // fonction de filtrage qui mange 1 face et un void* (pour transmettre un
  // eventuel contexte de travail) et rend un char=1 si face a ne pas importer
  static void ImportTopo(CATBody * iBody, CAThkContext * iContext,
    char (*ipFilterThisFace)(CATFace* iFace,void * iCtx) = NULL,
    void * iCtxForFiltering = NULL);

  // Controle de validite des reports de crvparams sur edge-curve morte
  // on verifie la validite des 2 crvparams (sur chaque pcurve) et on
  // controle la distance entre les 2 points associes
  static short CAThkECrvOffsetParmCheck(CATCrvParam & iParm1,
                                        CATEdgeCurve * iEdgCrv1, CATCrvParam & iParm2, CATEdgeCurve * iEdgCrv2,
                                        double iExpectedDist, CAThkContext * iContext = NULL);

  // Evaluation d'un point XYZ a partir d'un point sur courbe
  static short GetXYZFromCrvParm(CATCrvParam & iParm, CATCurve * iCrv,
                                 CATMathPoint & resu, CAThkContext * iContext = NULL);

  // Evaluation d'une tangente a une courbe (pas simplement une derivee)
  static void GetCurveTangent(CAThkContext * iContext, CATCurve * iCrv, CATCrvParam & iCrvP,
                              CATMathDirection & oTg);

  // Evaluation de tangente uv
  static void Compute2DTangent(CATVertex * iVtx, CATEdge * iEdg,
                               CATPointOnEdgeCurve * iPoec, CATSide iVtxSide, CATPCurve * iPCrv,
                               CATSurParam & oSurpOnInitSurf, CATMathVector2D & oTgt);

  // Evaluation UV d'un pt sur pcurve avec recalage sur maxlimits en cas de
  // de debordement < CATEpsg. La surface et la surlimits seront deduits de
  // la pcurve si on les omet
  static void EvalUVInsideLim(CATSurParam & oSurParm,
                              const CATCrvParam & iCrvParm, const CATPCurve * iPCrv, 
                              CATSurface ** ipSur = 0, const CATSurLimits * iBox = 0, const CAThkPoint * iTp = 0);  
  
  // Evaluation d'une extremite (indique par le vertex iVtx ou par l'indice 
  // iSideInEdge) d'une edge sur une pcurve, retourne le CrvParam
  //     si ioPcrv==NULL, on recupere la 1ere pcrv posee sur iSurf (qui doit etre
  //        non NULL) que l'on retourne dans ioPcrv
  //     si ioPcrv!=NULL, c'est elle qui est choisie.
  static void EvalEdgOnPCrv(CATEdge * iEdge, CATVertex * iVtx, short iSideInEdge,
                            CATPCurve *& ioPcrv, CATSurface * iSurf, 
                            CATCrvParam & oCrvParam ) ;
  
  // METHODE STATIQUE
  // Calcul de la continuite de 2 mierep incidentes a un iVrep.
  // L'utilisateur peut passer en argument sa tolerance angulaire 
  // (jusqu'a 30 deg mais en radian !!)
  // Si iWithoutTurningPoint = 1  ( != 0 )
  // Alors en prend en compte les orientations des tangentes pour
  // le calcul d'angle et on refuse les rebroussements.

  static void CheckMierepsContinuity(CAThkInitVRep * iIVrep,
                                     CAThkManifoldInitERep * IMEReps[2],
                                     CATTopGeoContinuity &oContinuity,
                                     double * iTolerance           = 0,
                                     short    iWithoutTurningPoint = 0,
                                     short    iForceUserTolerance  = 0, 
                                     double * oCosAngle            = 0,
                                     short  * oIsTurningPoint      = NULL);
  
  // Generation d'un surparam de l'autre cote d'une fermeture
  // iBorder = 0 -> Umin / 1 -> Umax / 2 -> Vmin / 3 -> Vmax
  static void GetCrossClosureSurp(CATSurface * iSurf, CATSurParam & iSurp,
    short iBorderIndex, CATSurParam & oCrossSurp, CATSurLimits * iMaxBox = 0);

  // Inversion d'un CATSide, ou multiplication par un facteur donne
  static CATSide ReverseSide(CATSide iSide);
  static CATSide MultiplySide(short iFactor, CATSide iSide);

  // Combinaison de deux CATSides (Full+x=Left+Right=Full, Unknown=neutre)
  static CATSide CombineSides(CATSide iSide1, CATSide iSide2);

  // Evaluation d'un indice (short) qui mesure la compatibilite de 2 sides,
  // le resultat est compris entre 1 et 5, et d'autant plus grand que la
  // concordance des sides est grande
  // A partir de 3 on n'a pas d'incompatibilite, 2 dans le cas d'une valeur Unknown
  static short CompareSides(CATSide iSid1, CATSide iSid2);

  // Compilation de sides, de pointeurs, ou de signes
  // La valeur initiale du resultat compile doit etre neutre (CATSideUnknown, NULL ou 0)
  // rend zero si le resultat des futures compiles ne peut rien changer, 1 sinon
  // ioAlreadySet doit etre initialise a 0, et reinjecte ensuite sans etre modifie
  // Pour les pointeurs, on dissocie la valeur compilee en entree et en sortie afin de
  // rendre possible un cast en sortie, puisque la valeur compilee est void*.
  static short CompileSides(CATSide iSide, CATSide & ioCompil, short & ioAlreadySet);
  static short CompilePointers(void * iPointer, void * iCompil, void *& oCompil, short & ioAlreadySet);
  static short CompilePointers(CAThkContext * iContext, void * iPointer, void * iCompil, void *& oCompil, short & ioAlreadySet); // Appel versionne
  static short CompileSigns(short iSign, short & ioCompil, short & ioAlreadySet);

  // Calcul le produit scalaire entre la tangente calculee au debut ou a la 
  // fin de l'edge iEdge (suivant iOrient) mais reorientee vers "l'interieur"
  // de l'edge et le vecteur iVect.
  static double ComputeProdScalTgtEdge(CATEdge * iEdge , int iOrient, 
                                       CATMathDirection &iVect);

  // Determination ou creation d'un accupt associe a un crvparam sur pcurve,
  // en prenant en priorite l'accupt initial qui est passe, puis ses jumeaux
  // (methode qui permet de pallier l'imprecision des accupts sur isopares
  // degenerees, en attendant que ceux-ci soient plus precis)
  static CAThkAccuPt * OptimizeEndAccuptIfNeeded(CAThkAccuPt * iRefAcp,
    CATPCurve * iPCrv, CATPointOnEdgeCurve * iPoec, short iForceCheckIfNoTwin = 0);

  // Acces au CATOffSurAtt associe a une surface initiale ou finale
  // (si elle est finale, ou si c'est un offset anticipe pour un cone,
  // on le trouve via la srep)
  static CATOffSurAtt * GetOffSurAtt(CAThkContext * iContext,
    CATSurface * iSurf, short iThrowIfNotFound = 0);

  // Calcul du pave UV d'un segment de pcurve (le contexte ne sert qu'a aiguiller
  // vers un calcul precis ou grossier)
  static void GetPCurveBoxBetweenPoecs(CAThkContext * iContext, const CATPCurve * iPCrv, 
    CATPointOnEdgeCurve * iPoecs[2], CATSurLimits & oBox);

  // Calcul du pave UV d'un segment de pcurve sur ses MaxLimit ou un CrvLimits donne
  // ATTENTION, l'option iCrvLimOption devient OBLIGATOIRE si iExactOption est demande
  static void GetPCBoxUV(CAThkContext * iContext, const CATPCurve * iPCrv, CATSurLimits & oBox, 
                         CATCrvLimits * iCrvLimOption = 0, short iExactOption = 0);


  // Extension UV eventuelle pour couper une boite xyz dans les cas ou c'est
  // pas cher (plans, cylindres) - retour = 1 si extension faite
  static short ExtendUVToCutXYZBoxByInfiniteSurfaces(CAThkContext * iContext,CATSurface * iSurf,
    CATSurLimits & iMaxUVBox, short iU_Unbounded, short iV_Unbounded,
    CATMathBox & iXYZBoxToCut, CATSurLimits & ioUVBox);

  // Fonctions STATIQUE  
  // Test si le plan iMthPlane donnee en entree n'est pas egal a une surface
  // contenue dans un des offsuratt de type iDirSurfType;
  // si c'est le cas on retourne cette surface , sinon NULL
  static CATSurface * IsMthPlaneAlreadyExist(CAThkContext * iContext,
                                            CATMathPlane  &iMthPlane,
                                            short          iDirSurfType);

  // rend 1 ou -1 selon que les 2 PCurves vont dans le meme sens ou pas
  static short ComparePCrvOri(CATPCurve * iPCrv1, CATCrvLimits & iLim1,
                              CATPCurve * iPCrv2, CATCrvLimits & iLim2,
                              double iResolution);


  // Rend 1 (ou -1) si iFinalERep va dans le meme sens (ou inverse) que 
  // iInitERep; dans le meme sens signifie : l'InitVRep ancetre
  // du VRep debut est le debut de iInitERep OU l'InitVRep ancetre du VRep 
  // fin est la fin de iInitERep (et sans contradiction entre le debut et la fin)
  // Rend 0 si on n'a pas pu determiner l'orientation relative
  static short GetTopoRelOrientation(CAThkInitEdgeRep * iInitERep,
                                     CAThkEdgeRep * iFinalERep);  

  
  // METHODE STATIQUE
  // S'APPLIQUE AUX EdgeREPS ET AUX FaceREPS UNIQUEMENT !!!
  // Fonction filtre qui determine si la candidature de iCellRep est retenue ou non,
  // suivant le critere de TrustLevel contenue dans la structure passee en argument.
  // La structure "(* iTrustLevelMinAndAllowedStatusChange)" possede 2 champs :
  // struct TrustLevelInfo {
  //      short _TrustLevelMinRequired;
  //      short _AllowedStatusChange;
  // };
  // Si le TrustLevel de iCellRep est SUPERIEURE OU EGALE a _TrustLevelMin,
  // et seulement dans ce cas, la candidature iCellRep est retenue
  // Si le champ _AllowedStatusChange vaut 1, c'est-a-dire si le changement de Status 
  // est autorisee, la methode procede de la maniere suivante :
  // si la candidature est retenue : _Status = CrepFinal, sinon _Status = CrepSleeping
  static short IsTrustLevelEnough(CAThkCellRep * iCellRep, 
                                  void * iTrustLevelMinAndAllowedStatusChange);

  static short IsTrustLevelEnoughAndNoIncoherentMatter(CAThkCellRep * iCellRep, 
                                  void * iTrustLevelMinAndAllowedStatusChange);
  
  // METHODE STATIQUE QUI S'APPLIQUE AUX IEREP UNIQUEMENT !!!
  // Contexte des bissectrices deformees et des superaretes.
  // Fonction filtre qui determine si 2 CAThkInitEdgeReps
  // vont entre dans la meme composante connexe de superarete:
  // - oui si elles sont dans la meme superarete !!!
  // - oui si elles se croisent et que l'une des mierep incidentes
  //   a l'initvrep (info recuperee via une ZTR) est prevue d'etre
  //   reconstruite par bissectrice.
  // la structure iStructData doit etre defini comme suit : 
  // struct InitData {CAThkCellRep * CRepCur;CAThkCellRep * CRepBoundary;
  //                  short BoundariesZTR; void * iMierepOpeTypeComputer;};
  static short AreMierepInSameSuperEdge(CAThkCellRep * iOtherIErep, 
    void * iStructData);
    
  // METHODE STATIQUE S'APPLIQUE AUX IEREP UNIQUEMENT !!!
  // struct InitData {CAThkCellRep * CRepCur;CAThkCellRep * CRepBoundary;
  //                  short BoundariesZTR; void * iDomain;};  
  // Fonction filtre qui determine si la candidature de iOtherIErep est retenue ou
  // non, suivant si elle est tangente au niveau du vertex iCurIVrep a l'IErep iCurIErep
  static short AreIErepsTangent(CAThkCellRep * iOtherIErep, void * iStructData);

  // METHODE STATIQUE S'APPLIQUE AUX IEREP UNIQUEMENT !!!
  // struct InitData {CAThkCellRep * CRepCur;CAThkCellRep * CRepBoundary;
  //                  short BoundariesZTR; void * iDomain;};
  // Fonction filtre qui determine si la candidature de iOtherIErep est retenue ou
  // non pour etre dans le meme subset que CRepCur relativement a l'ivrep CRepBoundary.
  // Le criteres applique est que les 2 aretes doivent etre (au moins localement)
  // mortes au voisinage du vertex partage (iCurIVrep), et continues en tangence.  
  static short AreIErepsSmoothAndTangent(CAThkCellRep * iOtherIErep, void * iStructData);

 
  // METHODE STATIQUE S'APPLIQUE AUX IEREP UNIQUEMENT !!!
  // struct InitData {CAThkCellRep * CRepCur;CAThkCellRep * CRepBoundary;
  //                  short BoundariesZTR; void * iDomain;};
  // Fonction filtre qui determine si la candidature de iOtherIErep est retenue ou
  // non pour etre dans le meme subset que CRepCur relativement a l'ivrep CRepBoundary.
  // le critere est que les pcurves dse Ierep (qui doivent pointer imperativement etre
  // les memes) ne doivent pas avoir de saut parametrique.
  static short IsIErepC1ContinuousWith(CAThkCellRep * iOtherIErep, void * iStructData);

  // METHODE STATIQUE S'APPLIQUE AUX IEREP UNIQUEMENT !!!
  // Fonction filtre qui determine si l'ierep contient une
  // mierpe adherente au domaine iDom.
  static short IsAdherentToDomain(CAThkCellRep * iIErepRep, void * iDom);

  // METHODE STATIQUE S'APPLIQUE AUX IEREP UNIQUEMENT !!!
  // Fonction filtre qui determine si l'ierep contient une
  // mierep adherente au domaine iDomain et dont le type d'operation convient ( different de 0 )
  static short HasCandidateMIERepForSuperEdges(CAThkCellRep * iIErepRep, void * iDomain);
    
   // METHODE STATIQUE S'APPLIQUE AUX IEREP UNIQUEMENT !!!
  // Fonction filtre qui determine si la candidature de iCellRep est retenue ou
  // non, suivant si l'ierep a une mierep attachee au domaine iDom et 
  // d'operationtype==6
  static short IsOperationTypeAllowed(CAThkCellRep * iCellRep, void * iDom);

  // METHODE STATIQUE
  // Fonction filtre qui determine si iEdgeRep est fortement proposee
  // pour etre dans le resultat final.
  // Actuellement, base sur l'ancien code : repond oui si l'erep provient
  // d'un unique ancetre VRep ou si elle a son sideguess defini sur une de
  // ses SurfRep.
  // Si le changement de Status est autorisee, la methode procede de la
  // maniere suivante :
  // si la candidature est retenue : _Status = ErepFinal, sinon _Status = ErepSleeping
  static short IsERepCandidate(CAThkCellRep * iEdgeRep, 
                               void * iAllowedStatusChange);
  
  // METHODE STATIQUE
  // Fonction filtre qui retourne 1 si iEdgeRep a une initedge, 0 sinon.
  static short IsERepWithInitEdge(CAThkCellRep * iEdgeRep, 
                                  void * iNULL);

  // METHODE STATIQUE
  // Fonction filtre qui retourne 1 systematiquement
  static short NoFilterForCellRep(CAThkCellRep * iCellRep, void * iNULL);

  // METHODE STATIQUE
  // Fonction filtre qui retourne 0 si l'ERep a une edge ancetre posee sur un bord a conserver
  static short FilterIfERepWithAncestorOnBdToKeep(CAThkCellRep * iCellRep, void * iNULL);
  
  // METHODE STATIQUE
  // Fonction filtre qui retourne 1 si iEdgeRep un ancetre non bord de skin,
  // 0 sinon
  static short IsERepWithNotSkBdAncestor(CAThkCellRep * iEdgeRep, 
                                         void * iNULL);

  // METHODE STATIQUE
  // Fonction filtre qui determine si iCellRep est contenu dans le subset
  // iSubset
  static short IsInSubset(CAThkCellRep * iCellRep,void * iSubset);
  
  // rend 1 si l'objet passe en 1er operande est + jeune que l'objet
  // (eventuellement deja detruit) dont le numero est passe en 2eme
  static char Newer(CAThkAlgoElt * iEltToCompare, int iRefEltNumber);

  // Verification de validite d'un poec (diametre < resolution donnee en argt)
  static void CheckThisPoec(CAThkContext * iContext, CATPointOnEdgeCurve * iPoec,
                            short iThrowIfTooBig = 0);

  // Positionnement d'un poc par rapport aux max-limits d'une courbe, a une
  // tolerance de parametre pres (resolution par defaut)
  // rend 0 si loin des bords, -1 si au debut, 1 si a la fin
  static short IsOnCrvBorder(CATPointOnCurve * iPoc, double * iTolW = 0);

  // Diagnostic de fermeture en xyz sur ses max-limits d'une CATCurve, a une
  // tolerance xyz pres egale a la resolution par defaut. 
  // Rend 1 si fermee, 0 sinon
  static short IsCrvClosed(CATCurve * iCrv, double * iTolXYZ = 0);  

  // Dilatation de boite UV avant calcul d'intersection
  // Permet d'eviter les effets nefastes des max-limits sur le cheminement
  // Si la boite initiale *ipBox n'est pas fournie, on la lit sur la srep
  // associee a la surface iSurf par GetUVSRepBox
  static void GetScaledBox(CAThkContext * iContext,CATSurface * iSurf,
                           CATSurLimits * ipBox,
                           CATSurLimits & iMaxBox,double iScaling, 
                           CATSurLimits & oBox,
                           short iOptimizeScaleAccordingToSurfaceType = 0);

  // Methodes d'acces aux coordonnees associees aux accupts pour CAThkVRepGen
  static void ThkPtGiveXYZCoord(void * inputData, int nupt, double *& oCoord);
  static void ThkPtGiveUVCoordIndirect(void * inputData, int nupt, double *& oCoord);

  // Lecture des infos de fermeture d'une surface, tenant compte des fermetures non
  // periodiques (sweeps fermes) si une srep et / ou un ofsuratt attcahe a la surface
  // permet d'obtenir cette information. iContext est un CAThkContext* par convention.
  // iUorV=0 <=> IsClosedU (axe U et autres iso-V cycliques),
  // iUorV=1 <=> IsClosedV (axe V et autres iso-U cycliques),
  // oMinClosedParm (resp.Max) pointeront en sortie les valeurs extremes du parametre
  // de fermeture, s'ils ne sont pas nuls en entree
  static short InvestigateClosedSurf(CATSurface * iSurf, short iUorV, void * iContext,
    double * oMinClosedParm, double * oMaxClosedParm);

  // retourne la liste de faces correspondant à des parois internes dans le body.
  static void GetInternalFacesInBody(CAThkContext * iContext, CATBody *iBody, CATLISTP(CATFace) &oInternalFaceList);

  //---------------------------------------------------------------------------
  // Teste si l'edge iEdge est strictement pose sur l'edge iEdgeSupport
  // i.e. elle repond oui a iEdge->IsLyingOn(iEdgeSupport) et ses vertex
  // extremites sont poses sur les vertex extremites de iEdgeSupport.
  static CATBoolean IsStrictlyLyingOn(CAThkContext * iContext,
                                      CATEdge      * iEdge, 
                                      CATEdge      * iEdgeSupport);
  
  // pour calcul du facteur servant au calcul de la boite des faces a offsetter :
  // taille moyenne des faces du body
  static double GetSumBodyBoxes(CATDomain *iDomain, CATBody *iInitBody, CATLONG32 &oNbF);

  // Pour extrapoler une CATSurface jusqu'au surparam souhaité.
  static void ExtrapolateSurface(CATSurface * iSurf, CATSurParam & iSurparam, CAThkContext & iContext);

  // propagation des edges a leur composante G1.
  static void PropagateEdgeList(CATBody *iBody,
                                CATLISTP(CATEdge) &iInitEdgesToRemove, 
                                CATLISTP(CATEdge) &ioEdgesAfterPropag);

  // propagation d'un edge a sa composante G1.
  // methode recursive.
  static void PropagateSingleEdge(CATBody *iBody, CATEdge *iEdge, 
                                  CATLISTP(CATEdge) &ioEdgesAfterPropag,
                                  CATVertex * iNoPropagVertex=NULL);

  static void GetAllBorderEdges(CATBody *iBody, CATShell *iShell, CATLISTP(CATEdge) &oBorderEdgeList);
  static void GetAllBorderEdges(CATBody *iBody, CATLISTP(CATCell) &oBorderEdgeList);

  static int AllCx2dHaveOneCx1D(CAThkContext *iContext, CATLISTP(CATFace) &iFaceList);
  static int GetNbBoundaries(CAThkContext *iContext, CATBody *iBody);

  static CATBody * CreateBody(CAThkContext *iContext, CATLISTP(CATCell) &iCellList, CATBody * iBody=NULL, short iCloseBody = 0);
  static CATBody * CreateBody(CAThkContext *iContext, CATLISTP(CATFace) &iFaceList);

  // Renvoie l'angle max d'une edge
  // return TRUE , if compute is OK
  // return FALSE, if compute is KO
  static CATBoolean ComputeMaxAngleOnEdge(CAThkEdgeRep * iERep, double  & oMinAngle, double  & oMaxAngle);

  // Recherche d'edge initiale morte entre 2 faces initiales de SReps
  // iCheckConfusedSReps : 1 pour propager la recherche aux SReps confondues, 0 sinon
  static short SearchSmoothInitialCurveBetween(CAThkContext *iContext, CAThkSurfRep *iSReps[2], short iCheckConfusedSReps = 0);

  // une face est-elle bord ?
  static short IsABorderFace(CAThkContext *iContext, CATFace *iFace);

  static CAThkECrvToHealAnomaly * GetECrvToHealAnomaly(CAThkContext *iContext, CATEdgeCurve *iEdgeCurve);

  static void RemoveDeletionOrdersInJournal(CATCGMJournalList *&ioJournal);
  static void CleanJournal(CATBody *iInputBody, CATBody *iResultBody, CATCGMJournalList *&ioJournal);
  static CATFace *GetImageFaceInJournal(CATCGMJournalList *iJournal, CATFace *iFace);

  // est ce que les Vreps proviennent de deux ivreps distincts et en confusion
  // si iCheckTwinIVLO on verifiera si on est dans une configuration TwinIVLO et on renverra FALSE si tel est le cas
  static CATBoolean AreIVRepsConfused(CAThkInitVRep* iIVRep1, CAThkInitVRep* iIVRep2, CATBoolean iCheckTwinIVLO);

  // Conversion de SurParam pour 2 surfaces confondues mais distinctes
  static short ConvertSurParam(CAThkContext *iContext, CATSurface *iInputSurface,
    CATSurParam &iInputSurParam, CATSurface *iConfusedTargetSurface, CATSurParam &oOutputSurParam);

  // surface twistee a l'interieur de la face ?
  static short IsTwisted(CAThkContext *iContext, CATFace *iFace, CATMathPoint &oMathPoint);

  // surface en pointe (outil de DBS) ?
  static short IsPeaked(CAThkContext *iContext, CATFace *iFace, CATVertex *iVertex=NULL);

  static short IsPeaked(CAThkContext *iContext, CATSurface *iSurface, CATSurParam &iSurParam);

  // calcul de masse d'un body 
  static double GetBodyMass(CAThkContext *iContext, CATBody *iBody, double iTol);

  // calcul de masse d'un domaine 
  static double GetDomainMass(CAThkContext *iContext, CATBody *iBody, double iTol, CATDomain *iDomain);

  // Tolerance lineaire pour reconnaissance fillet (cas NURBS)
  ExportedByThick
  static double    GetLinearTol               (CATSoftwareConfiguration *iConfig, double iResolution);

  static int       ComputeProjectionDistance  (CATSoftwareConfiguration *iConfig,
                                               CATBody *iVertexBody, CATBody *iSkinBody, CATMathDirection &iDir, double &oDist);
  static CATBody * ComputeVertexBodyInsideFace(CATGeoFactory            *iFactory,
                                               CATSoftwareConfiguration *iConfig,
                                               CATFace *iFace, CATMathDirection &oNormal);
  static CATBody * ComputeSkinBodyWithoutFace (CATGeoFactory *iFactory, CATSoftwareConfiguration *iConfig,
                                               CATBody *iBody, CATFace *iFace);

  // calcul de l'épaisseur minimale d'un body volumique
  static double GetMinThickness(CATSoftwareConfiguration *iConfig, CATBody *iBody);
  
  // Teste si une face possède une LoopSwapAnomaly
  static CATBoolean IsPartOfLoopSwapAnomaly(CATFace *iFace, CAThkContext *iContext);

  static CATBoolean IsPartOfNoInterGeomAnomaly(CAThkEdgeRep *iErep, CAThkContext *iContext);

  static double GetDistanceBetweenVertices(CATVertex *iVertex1, CATVertex *iVertex2);

  static int ComputeERepsConnexity(CATLISTP(CAThkEdgeRep) &iERepList);

  static int ComputeEdgesConnexity(CATLISTP(CATEdge) &iEdgeList);

  static int ComputeCellsMaxGap(CATGeoFactory * iFactory, CATSoftwareConfiguration * iConfig,
                                CATBody * iBody, CATLISTP(CATCell) & iListOfCells, double & oMaxGap);

  static CATBoolean AreThereDisjointFRepsOnSameSRep(CAThkContext *iContext);

  static void CheckForDifferentStagesOffsetOfNurbs(CATSurface *iSurf1, CATSurface *iSurf2, short &oResult);

  static int ComputeOffsetSurfaceDepth(CATSurface *iSurface, CATSurface *&oLastSurface);

  static CATBody * BooleanDiffBetweenBodies(CAThkContext      *  iContext,
                                            CATBody           *  iInputBody,
                                            CATBody           *  iBodyToRemove,
                                            CATCGMJournalList *& oJournal,
                                            short                iThicknessBackUp = 0,
                                            short iAvoidSimplif = 0);

  static CATBody * CompatibleBetweenBodies(CAThkContext * iContext, CATBody *iFirstBody, CATBody *iSecondBody);

  static CATBody * RunUnion(CAThkContext *iContext, CATBody *iFirstBody, CATBody *iSecondBody);

  static CATBody * ExtractCellsOnNonManifoldBody(CAThkContext *iContext, CATBody *iBody, CATLISTP(CATCell) &iCellList, short iComplementaryMode = 0);

  static CATBody * ApplyComplementaryThickness(CAThkContext *iContext, CATBody *iInputBody, CATCGMJournalList *&oJournal);

  static CATBody * BooleanSplitBetweenBodies(CAThkContext * iContext, CATBody *iInputBody, CATBody *iSplittingBody, CATCGMJournalList *&oJournal);

  static int       ComputeExtrapolationLengthByIntersenctingTangents( CAThkContext *iContext,CATEdge *iFirstEdge, CAThkInitVRep *iFirstIVRep, 
                                                                      CATEdge *iSecondEdge, CAThkInitVRep *iSecondIVRep,
                                                                      double &oAngleQuality, double &oLength, short iMustIntersect = 0 );
  static int       ComputeExtrapolationLengthByIntersenctingMIERepsCurves( CAThkContext *iContext,
                                                                           CATEdge *iFirstEdge, 
                                                                           CAThkInitVRep *iFirstIVRep, 
                                                                           CATLISTP(CATEdge) &iIncidentEdges, 
                                                                           CATLISTP(CAThkInitVRep) & iRelatedIVReps,
                                                                           double iMaxValue,
                                                                           double &oLength );

  // Mise à jour des limites UV de travail de SRep par projection de points
  static int StaticUpdateEquivSRepsUVBox( CAThkContext *iContext, CATPoint * iPointToProject, CATLISTP(CAThkSurfRep) & ioListsOfEquivSupportSReps );

  // Projection point surface
  static int StaticProjectPointOnSurface( CAThkContext     * iContext,
                                          CATPoint         * iPointToProject,
                                          CATSurface       * iSurface,
                                          CATSurLimits     & iSurLimits,
                                          CATSurParam      & oSurParam,
                                          double           & oDistToSurf,
                                          CATMathDirection * iProjDir = NULL,
                                          CATBoolean         iSignedDist = FALSE );

  static short GetFactoryBodySize(CATGeoFactory *iFactory);


protected :

  // Ancienne version (buggee) de CompilePointers
  static short CompilePointers_old(void * iPointer, void * iCompil, void *& oCompil, short & ioAlreadySet);

};

//----------------------------------------------------------------------------
// Fonctions globales utilisees en entree de FindPtConfusions(..)
char CAThkUtilAlwaysFalse(void* idata, int nupt1, int nupt2);
char CAThkUtilAlwaysTrue(void* idata, int nupt1, int nupt2);
char CAThkUtilAcPtNotOnSeparateVReps(void* idata, int nupt1, int nupt2);
char CAThkUtilAcPtOnSameVRep(void* idata, int nupt1, int nupt2);
char CAThkUtilAcPtFromSameBigInitVRep(void* idata, int nupt1, int nupt2);
char CAThkUtilAcPtNotFromConfusedIVReps(void* idata, int nupt1, int nupt2);

//----------------------------------------------------------------------------
// Fonctions globales utilisees pour iterer sur les tpts pour la methode
// statique CAThkHomotp::ComputeVertices()
CAThkPoint * CAThkUtilScanAllTpts(CAThkContext * iContext, CAThkTptIteratorContext *& ioData);
CAThkPoint * CAThkUtilScanCollisionTpts(CAThkContext * iContext, CAThkTptIteratorContext *& ioData);

//----------------------------------------------------------------------------
// Fonctions globales utilisees par CATOrderedCellsIter
short CAThkUtilHasAttribute(CATCell * iCell, void* iData);

//----------------------------------------------------------------------------
// Fonction globale de comparaison de 2 pcurves, adaptee au qsort (void*)
// rend -1 si iPC1 < iPC2, 0 si egalite, +1 si iPC1 > iPC2
// on considere que pline < pcircle < pspline et on ordonne les psplines par degres
int CAThkPCurveCmp( const void* iPC1, const void* iPC2);

//----------------------------------------------------------------------------
// Fonctions globales utilisees par CATThick.
// Test si l'edge est bord de la skin initiale ou si elle est posee
// (strictement!) sur une edge bord de la skin initiale.
// Si oui retourne l'edge bord, si non genere une exception.

CATEdge *  FindBoundingEdgeInBody(CAThkContext * iContext,
                                  CATEdge      * iBoundaryEdge);

// idem ci-dessus mais perfos !
CATEdge * FindBoundingEdgeInList(CAThkContext * iContext,
                                  CATEdge      * iEdge,
                                  CATLISTP(CATCell) &iListOfBoundaryCells);

//-------------------------------------------------------------------------
// Calcul de l'orientation d'une face par rapport a l'orientation "exterieur" 
// d'un body 2D ou 3D. En 2D, "exterieur" signifie dans le meme sens que le
// CATShell.
//
// Si iForceComputationVsCATShell=1, l'orientation retournee n'est pas 
// relative au body mais au CATShell auquel appartient la face ( ce qui ne 
// change rien en 2D)
ExportedByThick int GetFaceOriVsOutwardBodyOri(CATFace* iFac, CATBody* iBody, short iForceComputationVsCATShell = 0);

#endif
