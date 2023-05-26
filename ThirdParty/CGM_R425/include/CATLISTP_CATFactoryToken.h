/**
 * @level Private
 * @usage U1
 */
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATLISTP_CAT_FACTORY_TOKEN_H
#define CATLISTP_CAT_FACTORY_TOKEN_H

///////////////////////////////////////////////////////////////////////////////
//    PROJET:............CNEXT                                               //
//    FRAMEWORK:.........ObjectModeler                                       //
//    AUTEUR:............Jean-Louis MALAVAL                                  //
//    DATE:..............05/07/1996                                          //
//             -----------------------------------------------               //
//    AUTEUR:............                                                    //
//    MODIF:.............                                                    //
//    DATE:..............  /  /1995                                          //
///////////////////////////////////////////////////////////////////////////////

// ==========================================================================
//           Declarations pour les listes de CATFactoryToken
// ==========================================================================


// --------------------------------------------------------------------------
//                              Exported by module
// --------------------------------------------------------------------------

#include "AD0XXBAS.h"

// --------------------------------------------------------------------------
//                       Clean previous functions requests
// --------------------------------------------------------------------------

#include "CATLISTP_Clean.h"

// --------------------------------------------------------------------------
//                           Require needed functions
// --------------------------------------------------------------------------

#define  CATLISTP_Append
#define  CATLISTP_RemovePosition
#define  CATLISTP_ApplyDelete

// --------------------------------------------------------------------------
//                                  Get macros
// --------------------------------------------------------------------------

#include "CATLISTP_Declare.h"

// --------------------------------------------------------------------------
//                       Generate interface of collection-class
// --------------------------------------------------------------------------

class CATFactoryToken ;

#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByAD0XXBAS

CATLISTP_DECLARE( CATFactoryToken )


#endif


