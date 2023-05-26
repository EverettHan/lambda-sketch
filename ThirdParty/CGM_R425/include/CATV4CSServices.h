/**
* @level Private 
* @usage U1
*/
/* -*-C++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//								   
// CATV4CSServices :
//   Header for declaration of exported services of CATAIX.
//
//=============================================================================
// Information (for developer only) :
//   CATV4CSServices is a global header files.
//
//   Exported FORTRAN Routine are :
//           cvtbyte,
//           cvtcrc,
//           cvti2,
//           cvti4,
//           cvtinit,
//           cvtr4,
//           cvtr8,
//           cvtunused,
//           swapi2,
//           swapi4.
//
//=============================================================================
// November 1998  Creation LJH
// Juillet  1999  Modification du prototypage de cvti2 et cvti4 
//				   le SAVE AS MODEL						
//=============================================================================
#ifndef CATV4CSServices_H
#define CATV4CSServices_H

#include "CATV4CSTypes.h"
#include "CATAIXServices.h"

//-----------------------------------------------------------------------
// Declaration of exported routines that can be called in FORTRAN sources
//-----------------------------------------------------------------------
extern "C" 
{
  ExportedByCATAIXServices integer4 cvtbyte  ( logical * iTabL1, const integer4 & iNbL1 );

  ExportedByCATAIXServices integer4 cvtcrc   ( character * iString, const integer4 & iLength );

  ExportedByCATAIXServices integer4 cvti2    ( integer2 * iTabI2, const integer4 & iNbI2, integer2 * ioTab);

  ExportedByCATAIXServices integer4 cvti4    ( integer4 * iTabI4, const integer4 & iNbI4, integer4 * ioTab);

  ExportedByCATAIXServices void     cvtinit  ( const integer4 & iMrk,        \
					       const integer4 & iFmt,        \
					       const integer4 & iEntier,     \
					       integer4       & oActconv,    \
					       integer4       & oIer );

  ExportedByCATAIXServices integer4 cvtr4    ( real4 * iTabR4, const integer4 & iNbR4 );

  ExportedByCATAIXServices integer4 cvtr8    ( real8 * iTabR8, const integer4 & iNbR8 );

  ExportedByCATAIXServices integer4 cvtunused( logical * iTabL1, const integer4 & iNbL1 );

  ExportedByCATAIXServices integer4 swapi2   ( integer2 * iTabI2, const integer4 & iNbI2 );

  ExportedByCATAIXServices integer4 swapi4   ( integer4 * iTabI4, const integer4 & iNbI4 );

  /*-----------------------------------------------------------------------*/
  /* trcmti : encodage du format et du marquage a partir des donnees du    */
  /*          numero de code page, du codage des reels et du codage        */
  /*          Little/Big Endian.                                           */
  /*                                                                       */
  /*   ENTREES  :                                                          */
  /*   -------                                                             */
  /*           integer4 iCPV4Num        : Numero du code page.             */
  /*           integer4 iCPV4RealCoding : Codage des Reels (IEEE/S370).    */
  /*           integer4 iCPV4LBEndian   : Little/Big Endian.               */
  /*                                                                       */
  /*   SORTIES  :                                                          */
  /*   -------                                                             */
  /*           integer4 oFMT            : Format ASCII/EBCDIC.             */
  /*           integer4 oMRK            : Marquage de code page.           */
  /*           integer4 oIer            : Code d'erreur                    */
  /*                                      0 : Encodage OK,                 */
  /*                                    745 : Code Page Inconnu,           */
  /*                                    747 : Codage Reels et/ou           */
  /*                                          codage LB Endian Inconnus.   */
  /*                                                                       */
  /*   CODE DE RETOUR :                                                    */
  /*   --------------                                                      */
  /*       trcmti = 0 : Encodage reussi.                                   */
  /*       trcmti = 1 : Erreur, consulter oIer.                            */
  /*-----------------------------------------------------------------------*/
  /*ExportedByCATAIXServices integer4 trcmti   ( const integer4 & iCPV4Num,
					       const integer4 & iCPV4RealCoding,
					       const integer4 & iCPV4LBEndian,
					       integer4 & oFMT,
					       integer4 & oMRK,
					       integer4 & oIer );*/
}

#endif
