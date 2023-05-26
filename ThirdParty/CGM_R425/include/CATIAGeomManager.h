/**
 * @level Protected
 * @usage U2
 */

// COPYRIGHT Dassault Systemes 2002
//===================================================================
//
// CATIAGeomManager.h
// Header definition of CATIAGeomManager
//
//===================================================================
//
// Usage notes:
//  This class should be considered asabstract.
//  One object derivating from this one, can be attach to a Container.
//  This kind of object is responsible for LifeCycle of geometrical
//  and topological objects.
//  Destructor MUST be re-defined !!
//
//===================================================================
//
//  Mar 2002  Creation: OGM
//===================================================================

#include "ExportedByCATIAEntity.h"

class ExportedByCATIAEntity CATIAGeomManager
{
  public :
    CATIAGeomManager() ;
    virtual ~CATIAGeomManager() ;
} ;

