/* -*-c++-*- */
#ifndef CATCGMEquationDeleteMODE_H
#define CATCGMEquationDeleteMODE_H
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2000
//-----------------------------------------------------------------------------
// Pour Activation d'une gestion de la r�tention des �quations au niveau _Lockcount==0
// 
//  Pr�vu pour tout type d'objet
//      CATCGMEquationsDeleteMode = 0 : r�tention de toutes les �quations si denier Unlock
//      CATCGMEquationsDeleteMode = 1 : ClearEquations � ce niveau (processus pr�c�dent)
//      CATCGMEquationsDeleteMode = 2 : r�tention uniquement pour les NurbsSurfaceCGM 
//                                      (ClearEquations pour tout le reste)
//-----------------------------------------------------------------------------
#include "ExportedByCATCGMFusion.h"
class CATGeometryCGM;
//---------------------------------------------------------------------------
// Pour gerer des transactions avec clear ou retention equations
//------------------------------------------------------------------------
enum   CATCGMEquationsDeleteMode { Always , Never , NurbsMode , ToBeInitiated };

ExportedByCATCGMFusion CATCGMEquationsDeleteMode  CATCGMEquationsDeleteSetMode(const CATCGMEquationsDeleteMode newMode);
ExportedByCATCGMFusion CATCGMEquationsDeleteMode  CATCGMEquationsDelete  (CATGeometryCGM * iGeometryCGM);
ExportedByCATCGMFusion CATCGMEquationsDeleteMode  CATCGMEquationsDelete  ();

#endif

