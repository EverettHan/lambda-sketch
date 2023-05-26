/* -*-c++-*-*/
#ifndef CATGlobalRatio_H
#define CATGlobalRatio_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1999
//
// CATGlobalParam :
/**
 * Type representing the  point on a CATWire.
 */
//
// 
//=============================================================================
//
// History
//
// Nov. 99  J.M.Houdouin               Creation 
//
//=============================================================================

#include "YJ000GSM.h"
#include "CATPGMStaticGlobalRatio.h"

class CATMathPoint;
class CATEdge;
class CATBody;
class CATTopData;

//
// pour toutes les methodes statiques de cette classe,
// le retour 0 signifie que tout s'est bien passe 
// et qu'on a pu realiser le calcul demande.
// retour <> 0 alors quelque chose a cloche
// se reporter qux commentaires pour plus de precision
//
class  ExportedByYJ000GSM CATStaticGlobalRatio
{
public:
  //
  //
  // calculs du global ratio
  //
  // a partir du point 3D
  static int CATGRFromMathPoint(CATBody * Wire, const CATMathPoint & MathPoint, CATGlobalRatio & GR);
  static int CATGRFromMathPoint(CATBody * Wire, CATTopData * iData, const CATMathPoint & MathPoint, CATGlobalRatio & GR);
  // a partir de l'edge local et du ratio local
  static int CATGRFromLocale(CATBody * Wire, CATEdge * LocalEdge,const CATLocalRatio & LR, CATGlobalRatio & GR, CATTopData * iData=0);
  //
  // calculs a partir du ratio global
  //
  // calcul de l'edge et du ratio local sur l'edge
  static int CATLocaleFromGR(CATBody * Wire, const CATGlobalRatio & GR, CATEdge *& LocalEdge, CATLocalRatio & LR, CATTopData * iData=0);
  // calcul du point 3D equivalent
  static int CATMathPointFromGR(CATBody * Wire, const CATGlobalRatio & GR, CATMathPoint & PointXYZ);
  static int CATMathPointFromGR(CATBody * Wire, CATTopData * iData, const CATGlobalRatio & GR, CATMathPoint & PointXYZ);

};

#endif
