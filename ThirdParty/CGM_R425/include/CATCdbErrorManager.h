/**
 * @level Protected
 * @usage U2
 */

// COPYRIGHT Dassault Systemes 2002
//===================================================================
//
// CATCdbErrorManager.h
// Header definition of CATCdbErrorManager
//
//===================================================================
//
// Usage notes:
//   This object is used to store errors happening to a CATIAModel
//   during execution.
//===================================================================
//
//  Aou 2002  Creation: OGM
//===================================================================

#ifndef CATCdbErrorManager_H
#define CATCdbErrorManager_H

#include "ExportedByCATIAEntity.h"
#include "CATBaseUnknown.h"

class CATCdbError ;

class ExportedByCATIAEntity CATCdbErrorManager : public CATBaseUnknown
{
  public:
    CATCdbErrorManager() ;
    virtual ~CATCdbErrorManager() ;

    // Ajout d'une erreur dans la liste
    // !! Un AddRef est realise sur iCdbError !!
    HRESULT                       AddError( CATCdbError* iCdbError ) ;

    // To get the list of errors
    HRESULT                       GetTabError( int&           oNbError,
                                               CATCdbError**& oTabError ) ;

  private :
    int                           _nbError ;
    int                           _tabErrorDim ;
    CATCdbError**                 _tabError ;

    // Copy constructor and equal operator
    // ------------------------------------
    CATCdbErrorManager(CATCdbErrorManager &) ;
    CATCdbErrorManager& operator=(CATCdbErrorManager&) ;
} ;

#endif
