#ifndef CATTopRibDef_H
#define CATTopRibDef_H

// COPYRIGHT DASSAULT SYSTEMES 1999

#include "CATTopDef.h"


// Support Type
// ------------
typedef int CATTopRibSupp;
#define CATTopRibUnknownSupportType 0  // type inconnu
#define CATTopRibRolling            1  // element de roulement 
#define CATTopRibGuide              2  // element de guidage: spine de rayon variable par exemple
#define CATTopRibRelimit            4  // element relimitant
#define CATTopRibTransit            8  // element de transfer (peut etre Relimit)
// Do not use any more
#define UnknownSupportType 0  // type inconnu
#define Rolling            1  // element de roulement 

// Solution Type
// -------------
typedef int CATTopRibSol;  
#define CATTopRibSolTypeIn             1  // A l'interieur
#define CATTopRibSolTypeOut            2  // A l'exterieur
#define CATTopRibSolTypeConfused       4  // Confusion
#define CATTopRibSolTypeInOrConfused   5  // Confusion ou In
#define CATTopRibSolTypeOutOrConfused  6  // Confusion ou Out
#define CATTopRibSolTypeUnknown        8  // Pas d'importance 
// Do not use any more
#define SolTypeIn             1  // A l'interieur
#define SolTypeOut            2  // A l'exterieur
#define SolTypeConfused       4  // Confusion
#define SolTypeUnknown        8  // Pas d'importance 

// Contact Type
// ------------
typedef int CATTopRibContact; 
#define CATTopRibContactUnknown  128       // Contact inconnu
#define CATTopRibContactStop       1       // Arret sur contact
#define CATTopRibContactRolling    2       // Contact sur element de roulement (donc support)
#define CATTopRibContactContinue   4       // Contact sur element mort menant vers un nouveau support
#define CATTopRibContactEndRolling 8       // Contact avant la fin de l'element rolling  
#define CATTopRibContactBrdrTopo   16      // Contact sur la frontiere topo de l'element de roulement
#define CATTopRibContactBrdrGeo    32      // Contact sur la frontiere geom de l'element de roulement
// Do not use any more
#define ContactUnknown  128
#define ContactStop       1
#define ContactRolling    2
#define ContactContinue   4
#define ContactEndRolling 8
#define ContactBrdrTopo   16
#define ContactBrdrGeo    32


// Connexion Type
// --------------
typedef int CATTopRibConnexion;
#define CATTopRibConnexionKo         0 // Raccord impossible
#define CATTopRibConnexionOk         1 // Connexion ok (eventuelement sous condition) 
#define CATTopRibConnexionOkIfDefGeo 2 // Connexion ok si on sait deformer la geometrie 
#define CATTopRibConnexionOkIfDefTop 4 // Connexion ok si on sait deformer la topologie  
// Do not use any more
#define ConnexionKo         0
#define ConnexionOk         1
#define ConnexionOkIfDefGeo 2
#define ConnexionOkIfDefTop 4


// Sign: signe pour definir une orientation d'elements ou un sens de propagation du ruban
#define CATTopRibSign CATTopSign


// Mode de propagation du ruban : Determine si l'on doit forcer la progression du ruban 
// -----------------------------  quitte a extrapoler des fonds, ou si l'on s'arrete 
//                                des que l'on touche une arete vive non rolling 
enum CATTopRibPropagation {
  PropagStandard,  // arret classique 
  PropagCoarse  ,  // Force la creation 
  PropagMin     ,  // Pas de support out
  PropagMax     ,  // L'un des supports peut etre ou mais pas les deux 
  PropagUnknown    // Propagation inconnue
};

//------------------------------------------------------------------------------
// Define the possible types of CATDraft
//------------------------------------------------------------------------------
enum CATDraftType
{
  CATDraftNeutral,
  CATDraftReflect,
  CATDraftReflectKeepEdge
};
 
// Type de ruban : Specifie si un ruban est ferme ou ouvert
//--------------
//
typedef int CATTopRibType;
#define CATTopRibUnknownRibbonType  0
#define CATTopRibCloseType          1
#define CATTopRibOpenType           2
#define CATTopRibEndedType          4
#define CATTopRibNotEndedType       8
#define CATTopRibInvalidType       16
// Do not use any more
#define UnknownRibbonType  0
#define CloseType          1
#define OpenType           2
#define EndedType          4
#define NotEndedType       8
#define InvalidType       16

typedef int CATTopRibSupportRelimMode;
#define CATTopRibUnknownRelimMode 0
#define CATTopRibRelimAndSew      1
#define CATTopRibRelimandNoSew    2
#define CATTopRibNoRelim          3
#define CATTopRibWithScar         4 //comme RelimandNoSew, mais on genere les wires
                           //poses sur le Support .
// Ne plus utiliser:
#define UnknownRelimMode 0
#define RelimAndSew      1
#define RelimandNoSew    2
#define NoRelim          3
#define WithScar         4 //comme RelimandNoSew, mais on genere les wires
                           //poses sur le Support .

// Type de continuite : Specifie la continuite entre deux Nuplets 
// -------------------  
//
enum CATTopRibTypeConnexion {
  LogicalConnexion, // Les deux Nuplets doivent etre connexes 
  UnknownConnexion  // On ne sait pas 
};

enum StrategyForExtrapolation {
    NoStrategy,
    WithCommonEdge,
    WithCommonEdgeForward,
    WithCommonEdgeBackward,
    WithExtrapolatedEdgeForward,
    WithExtrapolatedEdgeBackward,
    IntersectionOfSupportsForward,
    IntersectionOfSupportsBackward
};
// Type dimension de cellule
//--------------------------
//
#define CATTopRibDimension short
// pour faire compiler : mais utiliser plutot CATVertexDimension ... de CATTopDef.h
#define VertexDimension  0
#define EdgeDimension    1
#define FaceDimension    2
#define VolumeDimension  3


// Type vivicite globale d'une arete par rapport a deux faces bordees
//-------------------------------------------------------------------
//
#define CATTopRibGeoContinuity CATTopGeoContinuity
#define CATTopRibConvexity CATTopConvexity
#define CATTopRibSharpness CATTopSharpness
//------------------------------------------------------------------------------
// Remarque: pour tester si une edge est morte:
//                       if (Sharpness._GeoContinuity & CATSmooth) ...
//           pour tester si une edge est vive :
//                       if (!(Sharpness._GeoContinuity & CATSmooth)) ...
//                       ou
//                       if (Sharpness._GeoContinuity == Sharp) ...
//------------------------------------------------------------------------------


// Type d'auto-intersection : Specifie le mode d'auto-intersection:
// ------------------------   soit lancee avant la propagation
//                            soit lancee apres la propagation
//                            soit jamais lancee
//
typedef int CATTopRibSelfIntersectMode;  
#define CATTopRibSelfIntersectNever             0
#define CATTopRibSelfIntersectBeforePropag      1
#define CATTopRibSelfIntersectAfterPropag       2
// Ne plus utiliser:
#define SelfIntersectNever             0
#define SelfIntersectBeforePropag      1
#define SelfIntersectAfterPropag       2

// Valeur de la Vivicite en radian  (0.5 degre)
//--------------------------------
#define CATTopRibSharpAngle CATTopSharpAngle

// Nombre max de supports (taille max de tout tableau de supports)
//----------------------------------------------------------------
#define CATTopRibMaxSupp 4

// Draft : nombre max de directions
//---------------------------------
#define CATTopDraftMaxNbDirections 2

// Info Journal pour le suivi d'edges
//--------------------------------
#define CATTopRibEdgeBordLibre 1
#define CATTopRibEdgeBordInterne 1
// Ne plus utiliser:
#define EdgeBordLibre 1
#define EdgeBordInterne 1

// Twist Type
// ----------
typedef int CATTopRibTwistType;
#define CATTopRibTwistUnknown             -999       // Not computed yet
#define CATTopRibNoTwist                  -99        // Checked, not twisted
#define CATTopRibTwistUndef               -9         // Checked, twisted, undefined type
#define CATTopRibTwistFolding             -1         // Checked, tracks zigzag on both side
#define CATTopRibInnerTwist                0         // Checked, tracks not twisted, twist on the surface only
// i > 0                                             // Checked, track self intersecting due to i support

// CD Macro
//---------
#include "CATTopOpIntError.h"
#define ThrowIfNull(ptr)                                                                                  \
if (!ptr)                                                                                                 \
  {CATThrow(new CATTopOpIntError(TopOpIntRibbonInternalError,"TopOpIntRibbonInternalError",TopOpIntFile));}
#include "CATThrowForNullPointer.h"

#define CATREF(ptr) ((!ptr ? (CATThrow(new CATTopOpIntError(TopOpIntRibbonInternalError,"TopOpIntRibbonInternalError",TopOpIntFile)), 1) : 0), *ptr)


//------------------------------------------------------------------------------
// Definition of the type of support edges for the draft face
//------------------------------------------------------------------------------
enum SupportEdgeType {
  EdgeTypeHigh,      // The support edge is on the "upper" border of the draft face
  EdgeTypeLow,       // The support edge is on the "lower" border of the draft face
  EdgeTypeMiddle,    // The support edge lies on the draft face
  EdgeTypeUnknown,   // We don't know where the edge lies : to be computed   
  EdgeTypeThrow      // La calcul a revele un probleme, il faudra lancer un erreur
};

#endif


