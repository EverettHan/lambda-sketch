//===================================================================
// COPYRIGHT Dassault Systemes 2013/05/02
//===================================================================
// CATIVVSVaultAccessAsync.cpp
// Header definition of class CATIVVSVaultAccessAsync
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2013/05/02 Creation: Code generated by the 3DS wizard
//===================================================================
#ifndef CATIVVSVaultAccessAsync_H
#define CATIVVSVaultAccessAsync_H

#include "VVSVaultSiteProtocol.h"
#include "CATBaseUnknown.h"
#include "CATIAV5Level.h"

class CATIVVSMassiveCopyAsync;
class CATUuid;
extern ExportedByVVSVaultSiteProtocol  IID IID_CATIVVSVaultAccessAsync ;


class ExportedByVVSVaultSiteProtocol CATIVVSVaultAccessAsync: public CATBaseUnknown
{
CATDeclareInterface;

public:
   /** 
   * Create a massive copy async
   * @param opMassiveCopy [out, IUnknown#Release] 
   * The massive copy.
   * @param iTransactionId [in]
   * The transaction.
   * @return
   * S_OK if the copy was succesfully created, or E_FAIL otherwise
  */  
  virtual HRESULT CreateCopyAsync(CATIVVSMassiveCopyAsync *&opMassiveCopy) const = 0;
};

//-----------------------------------------------------------------------

#endif