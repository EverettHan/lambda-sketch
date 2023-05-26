/**
 * @level Private
 * @usage U1
 */
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
//  CATIReferenceDocument :
//  Class for analysing  a root product
//            
//
//==================================================================
//  Usage notes
//   This class is used to recover the document containing the 
//   reference of a root product instanciation. To use carefully
//
//==================================================================
#ifndef CATIReferenceDocument_H
#define CATIReferenceDocument_H

#include "AD0XXBAS.h"
#include "CATDocument.h"

extern ExportedByAD0XXBAS IID IID_CATIReferenceDocument ;

class ExportedByAD0XXBAS CATIReferenceDocument : public CATBaseUnknown
{
  CATDeclareInterface;

    public:

    virtual CATDocument* GetDocument ()   = 0 ;

};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIReferenceDocument , CATBaseUnknown ) ;


#endif
