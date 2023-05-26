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

#ifndef COS_LIFE_CYCLE_SERVICES_H
#define COS_LIFE_CYCLE_SERVICES_H

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
//        Implementation des Life Cycle Object services de CORBA
// ==========================================================================

#include "CosNaming.h"
#include "CATBaseUnknown.h"

// --------------------------------------------------------------------------
//                            Exceptions
// --------------------------------------------------------------------------

//   --->   NoFactory 
//   --->   NotCopyable 
//   --->   NotMovable
//   --->   NotRemovable
//   --->   InvalidCriteria

// --------------------------------------------------------------------------
//                          Declaration de typedef
// --------------------------------------------------------------------------

class GenericFactory ;
typedef GenericFactory* GenericFactory_ptr ;

// --------------------------------------------------------------------------
//                         Declarations preliminaires
// --------------------------------------------------------------------------

// 
// --> Definition de la sequence en attendant le generateur
//
DEF_SEQUENCE( GenericFactory_ptr, CATOMY )

typedef SEQUENCE( GenericFactory_ptr )  Factories ;

struct NameValuePair { Istring name ;
                       void*   value ; } ;

// 
// --> Definition de la sequence en attendant le generateur
//
DEF_SEQUENCE( NameValuePair, CATOMY )

typedef SEQUENCE( NameValuePair )  Criteria ;

  
#endif





