/* -*-c++-*- */
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
//  CATISaveLoadError:
//  
//  This interface allows to get or set an error raised during
//  save or load operations
//
//==================================================================
//  Usage notes
//    
//
//==================================================================
#ifndef CATISaveLoadError_H
#define CATISaveLoadError_H

/**
 * @level Protected 
 * @usage U3
 */

#include "AD0XXBAS.h"
#include "CATBaseUnknown.h"
class CATSaveLoadError;

extern ExportedByAD0XXBAS IID IID_CATISaveLoadError;

class ExportedByAD0XXBAS CATISaveLoadError : public CATBaseUnknown
{
  CATDeclareInterface;

    public:

    virtual CATSaveLoadError* GetSaveLoadError () = 0 ;
    virtual void SetSaveLoadError(CATSaveLoadError* iSaveLoadError) = 0;

};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler (CATISaveLoadError , CATBaseUnknown) ;


#endif

