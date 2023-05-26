/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATIBeforeUndoRedo_h_
#define CATIBeforeUndoRedo_h_


/**
 * @level Private
 * @usage U3
 */

#include "CATBaseUnknown.h"

class CATListValCATBaseUnknown_var;

#include "AD0XXBAS.h"
extern ExportedByAD0XXBAS IID IID_CATIBeforeUndoRedo;

class ExportedByAD0XXBAS CATIBeforeUndoRedo : public CATBaseUnknown
{
  CATDeclareInterface;

  public :
    virtual CATListValCATBaseUnknown_var* GetErasableObjectsForUndoRedo(int transaction_number,int mode) = 0 ; // mode =0 for undo or 1 for redo
} ; 

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIBeforeUndoRedo, CATBaseUnknown ) ;


#endif


