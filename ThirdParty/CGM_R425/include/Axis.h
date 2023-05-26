/**
 * @level Protected
 * @usage U1
 */
// COPYRIGHT DASSAULT SYSTEMES 2002
// CATIA V5 Release 10
//===========================================================================
//
// Usage Notes : Mise a courant d'un triedre
//              
//
//===========================================================================
// Sept 02    Creation       scz
//                   
//===========================================================================
#ifndef Axis_H
#define Axis_H
#include "CATIAEntity.h"

class CATIAModel;

#define LTrue 0xFF
#define LFalse 0x00
   
int ExportedByCATIAEntity MakeCurrentAxis(CATIAModel * ModelV4, int jCurAxs);

#endif


