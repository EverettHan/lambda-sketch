/* -*-c++-*- */
#ifndef CATLISTP_CATCOMMANDGLOBALUNDO_H_
#define CATLISTP_CATCOMMANDGLOBALUNDO_H_

// COPYRIGHT DASSAULT SYSTEMES 2000

// ==========================================================================
//           Declarations pour les listes de CATCommandGlobalUndo
// ==========================================================================


// --------------------------------------------------------------------------
//                       Clean previous functions requests
// --------------------------------------------------------------------------

#include "CATLISTP_Clean.h"

// --------------------------------------------------------------------------
//                           Require needed functions
// --------------------------------------------------------------------------

#define  CATLISTP_Append
#define  CATLISTP_AppendList

// --------------------------------------------------------------------------
//                                  Get macros
// --------------------------------------------------------------------------

#include "CATLISTP_Declare.h"

// --------------------------------------------------------------------------
//                       Generate interface of collection-class
// --------------------------------------------------------------------------

#include "CATCommandGlobalUndo.h"


CATLISTP_DECLARE( CATCommandGlobalUndo )


#endif


