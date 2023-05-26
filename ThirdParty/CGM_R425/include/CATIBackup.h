/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATIBackup_h
#define CATIBackup_h

/**
 * @level Private
 * @usage U3
 */

#include "CATBaseUnknown.h"
#include "CATDataType.h"

#include "AD0XXBAS.h"
extern ExportedByAD0XXBAS IID IID_CATIBackup ;

class ExportedByAD0XXBAS CATIBackup : public CATBaseUnknown
{
  CATDeclareInterface;

public:
    virtual CATLONG32 Rollout ()=0 ;
    virtual CATLONG32 Rollin ()=0 ;
    //
    // virtual void advise (CATImailBox* mailBox)
    //
};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIBackup, CATBaseUnknown ) ;


#endif



