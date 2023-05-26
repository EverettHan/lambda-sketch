#ifndef CATHybTrimInitial_H 
#define CATHybTrimInitial_H 
///**
//*/
////=============================================================================
//// COPYRIGHT    : DASSAULT SYSTEMES 2006
////
////									Boolean Operator For Shell and Wire : 
//// DESCRIPTION  : noyeau Split/Trim  (utilitaires)
////
//// Jan 2007			: Creation                                            R.LOJA
////
////============================================================================
//#include "CATHybDef.h"
//#include "BOHYBOPELight.h"
//#include "CATIAV5Level.h"
//
//class CATError;
////========================================================================
////  Trim de Shell
////========================================================================
///**
//* Constructs an operator that trims a CATShell domain by a CATShell  domain.
//* <br>The body to trim and the triming body must only contain 
//* one shell domain and one (shell or wire) domain respectively.
//* <br><b>Orientation</b>: The orientation of the resulting body is the orientation
//* of the body to cut.
//* <br><b>Journal</b>:
//* <ul>
//* <li>The faces that are kept and not cut are written as <tt>CATCGMJournal::Keep</tt>
//* <li>The faces that are cut are written as <tt>CATCGMJournal::Subdivision</tt> 
//* <li>The new edges are written as <tt>CATCGMJournal::Creation</tt>
//* <li>The faces that are neither cut, nor kept, are written as <tt>CATCGMJournal::Deletion</tt>
//* </ul>
//* @param iFactory
//* A pointer to the factory of the resulting body.
//* @param iData
//* A pointer to the topological data.
//* @param iBodyToTrim
//* A pointer to the body to cut. It must only contain one shell
//* domain.
//* @param iSideToKeep1
//* Side to keep of the resulting parts of Body to trim.
//* @param iCuttingBody
//* A pointer to the cutting body. It must only contain one (wire or shell)
//* domain
//* @param iSideToKeep2
//* Side to keep of the resulting parts of //Operator->SetLevelToReplay(CGM_Versionning_SmartProject_Journal -1);Body .
//* @param iExtrapolMode
//* The way of extrapolation if the cutting body does not cut right along the body to cut.
//*/
//
//
//ExportedByBOHYBOPELight CATBody    * CATHybTrimShellInitial(CATGeoFactory           *iFactory,
//														CATTopData              *iData,
//														CATBody                 *iBodyToTrim,
//                            short                    iSideToKeep1,
//														CATBody                 *iTrimmingBody,
//                            short                    iSideToKeep2,
//														CATHybExtrapolationMode  iExtrapolMode,
//														double                   iTol,
//                            CATTopOpInError         *&InternalWarning );
				

#endif



