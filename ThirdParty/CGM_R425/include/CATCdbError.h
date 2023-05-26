/**
 * @level Protected
 * @usage U2
 */

// COPYRIGHT Dassault Systemes 2002
//===================================================================
//
// CATCdbError.h
// Header definition of CATCdbError
//
//===================================================================
//
// Usage notes:
//   This object is used to define an error hapening to a CATIAModel
//===================================================================
//
//  Aou 2002  Creation: OGM
//===================================================================

#ifndef CATCdbError_H
#define CATCdbError_H

#include "ExportedByCATIAEntity.h"
#include "CATBaseUnknown.h"

enum CATCdbErrorType
{
  CATCdbErrorTypeUnknown =0,
  CATCdbErrorTypeCritical = 1,
  CATCdbErrorTypeWarning = 2,
  CATCdbErrorTypeInformation = 3
} ;

class ExportedByCATIAEntity CATCdbError : public CATBaseUnknown
{
  public:
    CATCdbError() ;
    virtual ~CATCdbError() ;

    // To define error severity
    void                          SetErrorType( CATCdbErrorType iErrorType ) ;
    
    // To get error severity
    CATCdbErrorType               GetErrorType() ;


  private :
    CATCdbErrorType               _errorType ;

    // Copy constructor and equal operator
    // -----------------------------------
    CATCdbError(CATCdbError &) ;
    CATCdbError& operator=(CATCdbError&) ;
} ;

#endif
