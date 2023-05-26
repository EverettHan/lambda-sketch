/**
 * @level Protected
 * @usage U5
 */
/* -*-c++-*- */
#ifndef CATIApplicativeV4ToV5Paste_H
#define CATIApplicativeV4ToV5Paste_H

#include "ExportedByAC0UAX.h"
#include "CATBaseUnknowns.h" // Pour le "ListOfVarBaseUnknown"
#include "CATIContainer.h"

extern ExportedByAC0UAX IID IID_CATIApplicativeV4ToV5Paste ;

class ExportedByAC0UAX CATIApplicativeV4ToV5Paste : public CATBaseUnknown
{
  CATDeclareInterface ;

  public :
    virtual ListOfVarBaseUnknown ApplicativeV4ToV5Paste( ListOfVarBaseUnknown object_to_paste, CATIContainer_var ContainerRecepteur ) = 0 ;
} ;

// -----------------------
//         HANDLER
// -----------------------

CATDeclareHandler ( CATIApplicativeV4ToV5Paste, CATBaseUnknown ) ;

#endif 
