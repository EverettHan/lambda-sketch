/**
 * @level Private
 * @usage U3
 */
/* -*-c++-*- */
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2001
//-----------------------------------------------------------------------------
// 
#ifndef CATIAppliContPersistency_H_
#define CATIAppliContPersistency_H_

#include "CATBaseUnknown.h"
#include "CATObjectModelerItf.h"
extern ExportedByCATObjectModelerItf IID IID_CATIAppliContPersistency ;

/**
  * CATIAppliContPersistency 
  * Manage applicative container behaviour in persistency context :
  * file-based stream, nomad mode, blobbing/mapping in PDM...
  */
class ExportedByCATObjectModelerItf CATIAppliContPersistency : public CATBaseUnknown
{
  CATDeclareInterface;
  public:

  /* Implement this method to change links persistency for Model extensions in Feature stream.
   * S_OK : extensions will point to their base object by symbolic links
   * (i.e. potentially links on exposed objects).
   * Other : extensions will point to their base object by internal links
   * (default behaviour for PDM extensions which override CATILinkableObject)
   */
  virtual HRESULT UsePDMLinksForExtensions() = 0 ; 
  
};


// Macro for Handlers  //
//======================

CATDeclareHandler( CATIAppliContPersistency, CATBaseUnknown );

#endif
