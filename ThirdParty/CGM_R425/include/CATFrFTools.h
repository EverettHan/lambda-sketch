//=============================================================================
// Copyright Dassault Systemes Provence 2005, all rights reserved 
//=============================================================================
//
// CATFrFTools :
//
//  Centralisation des outils pratiques pour Free Form et ses utilisateurs
//
//=============================================================================
// 10/11/05 : MMO : Creation
//=============================================================================

#ifndef CATFrFTools_H
#define CATFrFTools_H

#include "CATFrFNetSurface.h"

#include "CATBoolean.h"

#include "CATGeometryType.h"

class CATGeoFactory;
class CATICGMObject;

CATBoolean ExportedByCATFrFNetSurface CATFrFCloneManager(CATGeoFactory    *  Factory, 
                                                         CATICGMObject    *  iObjectToClone,
                                                         CATICGMObject    *& oClonedObject,
                                                         CATGeometricType    iTypeReference);

#endif
