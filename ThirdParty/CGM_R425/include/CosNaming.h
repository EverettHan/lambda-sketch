/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2000
/** 
  * @level Private
  * @usage U1
 */
//**********************************************************************
//* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS *
//* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME *
//**********************************************************************

#ifndef COS_NAMING_H
#define COS_NAMING_H

///////////////////////////////////////////////////////////////////////////////
//    PROJET:............CNEXT                                               //
//    FRAMEWORK:.........Object Modeler                                      //
//    AUTEUR:............Rodolphe AYMARD/Jean-Louis MALAVAL                  //
//    DATE:..............26/01/1996                                          //
//             -----------------------------------------------               //
//    AUTEUR:............                                                    //
//    MODIF:.............                                                    //
//    DATE:..............  /  /1995                                          //
///////////////////////////////////////////////////////////////////////////////

// ==========================================================================
//       Implementation (sous-ensemble) des Naming services de CORBA
// ==========================================================================

#include "CATUnicodeString.h"  
#include "sequence.h"  
#include "CATOMY.h"

typedef CATUnicodeString  Istring ;

struct KeyComponent 
{
  Istring ident ;
  Istring kind ;
} ;

// 
// --> Definition de la sequence en attendant le generateur
//
DEF_SEQUENCE(KeyComponent, CATOMY)

typedef SEQUENCE(KeyComponent)  Key ;

#endif

