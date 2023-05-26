#ifndef CATExtandSurLimits_h
#define CATExtandSurLimits_h

#include "RibbonLight.h"


// Pour la demo, pour Jean Marc.

class CATSurLimits;
class CATSurface;
class CATSoftwareConfiguration;

// iSideToExtrapol = 1 : en UMin
//                   2 : en UMax
//                   4 : en VMin
//                   8 : en VMax
// et on peut additionner ces valeurs
// ex : iSideToExtrapol = 7 : extrapolation en UMin et UMax et Vmin
// 
// iSideToPrefer : indique � partir de quel(s) c�t�(s) on pr�f�re
// commencer la premi�re extrapolation.
// Cette donn�e n'est remplie que dans les cas o� on souhaite 
// extrapoler a priori dans toutes les directions (c-�-d iSideToExtrapol 
// vaut 0 si iSideToPrefer est diff�rent de 0)

ExportedByRibbonLight void CATExtandSurLimits(CATSoftwareConfiguration *iConfig,
                                             const CATSurLimits & iLimits,
                                             const CATSurLimits & iMaxLimits,
                                             const double iRatio,
                                             CATSurLimits & oLimits,            
                                             CATSurface *iSurface   = 0,
                                             int iSideToExtrapol    = 0,
                                             int iModifiableSurface = 0,
                                             double *iRatioUMin     = 0,
                                             double *iRatioUMax     = 0,
                                             double *iRatioVMin     = 0,
                                             double *iRatioVMax     = 0,
                                             int iSideToPrefer      = 0); 


#endif
