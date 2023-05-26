#ifndef CATEvalSkinExtrapolDistanceDef_H
#define CATEvalSkinExtrapolDistanceDef_H

// ++++ Includes ++++
#include "AdvTrimOpe.h"
#include "CATCrvLimits.h"
#include "CATBoolean.h"
#include "CATMathPoint.h"
#include "CATMathDirection.h"
#include "CATMathOBB.h"

// ++++ Predeclarations ++++
class CATEdge;
class CATFace;
class CATBody;

//=============================================================================
// CATEvalSkinExtrapolDistanceDef
// 
// responsable: ZUT
//=============================================================================

//-----------------------------------------------------------------------------
// ENUMS & STRUCTS
//-----------------------------------------------------------------------------

enum CATESEDMode                                         // Modes exclusifs (soit l'un, soit l'autre)
{
  CATESED_MODE_CLOSEST_INTERSECTION              = 0,    // Distance la plus courte avec le body objectif
  CATESED_MODE_FARTHEST_INTERSECTION             = 1,    // Distance la plus longue avec le body objectif

  CATESED_MODE_NB
};

enum CATESEDIntersectionFilter                           // Filtres cumulatifs
{
  CATESED_IFILTER_NOFILTER                       = 0x00, // Pas de filtre
  CATESED_IFILTER_IGNORE_BELOW_RESOLUTION        = 0x01, // Ne pas prendre en compte les distances inferieures a la resolution
  CATESED_IFILTER_IGNORE_MATTERSIDE_SINGLE_INTER = 0x02, // Pas de filtre sur les matter sides si solution unique

  CATESED_IFILTER_NB
};

enum CATESEDMatterSideFilter                             // Filtres exclusifs
{
  CATESED_MSFILTER_NOFILTER                      = 0,    // Pas de filtre
  CATESED_MSFILTER_MATTERSIDE                    = 1,    // Ignorer les faces traversees dans le sens du cote matiere
  CATESED_MSFILTER_REVERSE_MATTERSIDE            = 2,    // Ignorer les faces traversees a contre-sens du cote matiere
  CATESED_MSFILTER_FORCE_MATTERSIDE              = 3,    // Ignorer les rayons issus de points externes (premiere intersection dans le sens du cote matiere)

  CATESED_MSFILTER_NB
};

enum CATESEDEstimationMode                               // Modes exclusifs (soit l'un, soit l'autre)
{
  CATESED_ESTIMATION_RECURSIVE                   = 0,    // Estimation par appels recursifs sur les subdivisions
  CATESED_ESTIMATION_FAST                        = 1,    // Estimation rapide sans recursion

  CATESED_ESTIMATION_NB
};

enum CATESEDDirectionMode                                // Filtres cumulatifs
{
  CATESED_DMODE_NORMAL                           = 0x00, // Par defaut, calcul en direction normale
  CATESED_DMODE_TANGENT                          = 0x01, // Direction tangente à la direction de l'edge voisine
  CATESED_DMODE_NORMAL_NORMAL_BISECTOR           = 0x02, // Direction bissectrice aux deux normales des edges de part et d'autre du sommet
  CATESED_DMODE_NORMAL_TANGENT_BISECTOR          = 0x04  // Direction bissectrice entre la normale a l'edge a extrapoler et la tangente de l'edge voisine
};

enum CATESEDOrientationMode
{
  CATESED_OMODE_OUTSIDE                          = 0,   // Calcul de distance en partant vers l'exterieur de la skin
  CATESED_OMODE_INSIDE                           = 1    // Calcul de distance en partant vers l'interieur de la skin
};

struct ExportedByAdvTrimOpe CATESEDOptions
{
  unsigned int _Mode;
  unsigned int _IntersectionFilter;
  unsigned int _MatterSideFilter;
  unsigned int _EstimationMode;
  unsigned int _SharpExtremitiesMode[2];
  unsigned int _OrientationMode;

  CATESEDOptions( unsigned int iMode                = CATESED_MODE_CLOSEST_INTERSECTION,
                  unsigned int iIFilter             = CATESED_IFILTER_NOFILTER,
                  unsigned int iMSFilter            = CATESED_MSFILTER_NOFILTER,
                  unsigned int iEstimationMode      = CATESED_ESTIMATION_RECURSIVE,
                  unsigned int iSharpExtremitiesMode1 = CATESED_DMODE_NORMAL,
                  unsigned int iSharpExtremitiesMode2 = CATESED_DMODE_NORMAL,
                  unsigned int iOrientationMode     = CATESED_OMODE_OUTSIDE)
  : _Mode(iMode) , _IntersectionFilter(iIFilter) , _MatterSideFilter(iMSFilter), _EstimationMode(iEstimationMode), _OrientationMode(iOrientationMode)
  {
    _SharpExtremitiesMode[0] = iSharpExtremitiesMode1;
    _SharpExtremitiesMode[1] = iSharpExtremitiesMode2;
  }
};

struct ExportedByAdvTrimOpe CATESEDResult
{
  CATBoolean _IntersectionFound;
  double     _ExtrapolDistance;

  CATESEDResult() : _IntersectionFound(FALSE), _ExtrapolDistance(0.) {}
};

struct CATESEDSubdiv
{
  CATEdge      * _BorderEdge;
  CATFace      * _BoundedFace;
  CATBody      * _ExtrapolBody;
  CATBody      * _TargetBody;
  CATCrvLimits   _ECLimits;

  CATBoolean     _IsFacingTgtBody;
  CATESEDResult  _MaxDist[2];

  CATESEDSubdiv()
  : _BorderEdge(NULL), _BoundedFace(NULL), _ExtrapolBody(NULL), _TargetBody(NULL), _IsFacingTgtBody(FALSE) {}
};

struct CATESEDThickRay
{
  CATMathPoint     _Origin;
  CATMathDirection _MainDir;
  CATMathDirection _SecondDir;
  CATMathOBB       _ThickRay;

  int IsIntersecting(const CATMathOBB & iOBB, double iTol) const { return _ThickRay.IsIntersecting(iOBB, iTol); }
};

#endif /* CATEvalSkinExtrapolDistanceDef_H */
