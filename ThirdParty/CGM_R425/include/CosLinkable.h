/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef COS_LINKABLE_H
#define COS_LINKABLE_H

/** @CAA2Required */ 
/**********************************************************************/
/* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME */
/**********************************************************************/


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

/**
  * Specification for types of symbolic link names.
  */

enum CATNameKind
{
  CATShortestName=1,
  CATTypedName=2,
  CATSafestName=3,
  
  CATRelativeName=100
};

#endif

