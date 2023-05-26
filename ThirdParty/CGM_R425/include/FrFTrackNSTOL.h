#ifndef FrFTrackEpsilon_H
#define FrFTrackEpsilon_H
//=============================================================================
//
// COPYRIGHT   : DASSAULT SYSTEMES 2007
/** @CAA2Required */
//**********************************************************************
//* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS *
//* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME *
//**********************************************************************
// 
// DESCRIPTION : track (transparent) des utilisations directes des tolerances sans scale
//
// 20/02/07 NLD Creation
//=============================================================================
//#define FrFTrackNSTOLActivation "A n'activer que pour test; cout supplementaire du aux appels de fonctions"
//
#ifdef FrFTrackNSTOLActivation
#include <FrFAdvancedObjects.h> 
#include <CATMathLimits.h> // vraie definition de CATEpsilon CATEps, ...
//
#define TrackDec(NAME)                                              \
static int  FrFCount##NAME = 0 ;                                    \
extern "C" double ExportedByFrFAdvancedObjects FrFFunction##NAME(); //

#define TrackDef(NAME)                                              \
extern "C" double ExportedByFrFAdvancedObjects FrFFunction##NAME()  \
{ FrFCount##NAME++ ;                                                \
  FrFFunctionNSTOL(FrFValue##NAME);                                 \
 return FrFValue##NAME ;}                                           //

#define NSTOLDef                                                    \
  static int  FrFCountNSTOL = 0 ;                                   \
  extern "C" void FrFFunctionNSTOL(double iTol)                     \
  { FrFCountNSTOL++;                                                \
      return;}                                                      //
//
// pour CATEpsilon & family
// ------------------------
/*extern ExportedByFrFAdvancedObjects*/ const double FrFValueEpsilon = CATEpsilon;
TrackDec(Epsilon)
#define CATEpsilon FrFFunctionEpsilon()
//
/*extern ExportedByFrFAdvancedObjects*/ const double FrFValueSqrtEpsilon = CATSqrtEpsilon;
TrackDec(SqrtEpsilon)
#define CATSqrtEpsilon FrFFunctionSqrtEpsilon()
//
/*extern ExportedByFrFAdvancedObjects*/ const double FrFValueSquareEpsilon = CATSquareEpsilon;
TrackDec(SquareEpsilon)
#define CATSquareEpsilon FrFFunctionSquareEpsilon()
//
// pour CATEpsg  & family
// ----------------------
/*extern ExportedByFrFAdvancedObjects*/ const double FrFValueEpsg = CATEpsg;
TrackDec(Epsg)
#define CATEpsg FrFFunctionEpsg()
//
/*extern ExportedByFrFAdvancedObjects*/ const double FrFValueSqrtEpsg = CATSqrtEpsg;
TrackDec(SqrtEpsg)
#define CATSqrtEpsg FrFFunctionSqrtEpsg()
//
/*extern ExportedByFrFAdvancedObjects*/ const double FrFValueSquareEpsg = CATSquareEpsg;
TrackDec(SquareEpsg)
#define CATSquareEpsg FrFFunctionSquareEpsg()
//
// Bilan pour toutes les tolerances
// --------------------------------
extern "C" ExportedByFrFAdvancedObjects int TrackNSTOLSummary(int iTrace=1) ;
//
#endif
#endif
