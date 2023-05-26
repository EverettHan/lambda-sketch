
/**
 * @level Private
 * @usage U1
 */

// COPYRIGHT DASSAULT SYSTEMES 2002
//==============================================================================
//
// 
//
//==============================================================================
// Creation : O. GUILLAUME le 29/07/2002
// Modifications :
//==============================================================================

#ifndef PlfManagement_H
#define PlfManagement_H

#include "ExportedByCATIAEntity.h"

class CATIAModel ;
class CATIAEntity ;

int ExportedByCATIAEntity ModifyPlfNumber( CATIAModel* iMnum,
                                           int         iPlfNumBefore,
                                           int         iPlfNumAfter ) ;

int ExportedByCATIAEntity AcceptPlfModification( CATIAModel* iMnum ) ;

int ExportedByCATIAEntity ModifyNuplan( int iViewIgra,
                                        int iNuplan ) ;

// -----------------------------------------------------------
//  This function compares 2 planes mathematical's definition.
//  result :
//    0 : the planes are different
//    1 : the plane have the same equations.
// -----------------------------------------------------------
int ExportedByCATIAEntity PlfEquCompare( const double defPlf1[9], const double defPlf2[9] ) ;

#endif
