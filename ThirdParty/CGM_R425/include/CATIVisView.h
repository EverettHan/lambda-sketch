//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2010/06/21
//===================================================================
// CATIVisView.cpp
// Header definition of class CATIVisView
//===================================================================
#ifndef CATIVisView_H
#define CATIVisView_H

#include "CATVisItf.h"
#include "CATBaseUnknown.h"
#include "CATVisRepresentationRole.h"
#include "CATVisInvalidationToken.h"

extern ExportedByCATVisItf  IID IID_CATIVisView ;

/**
 * Interface to manage a view of representations. 
 * <b>Role</b>: A CATIVisView allows to display and interact with representations.
 */

class ExportedByCATVisItf CATIVisView : public CATBaseUnknown
{
CATDeclareInterface;

public:
  /**
   * Invalidates some parts of the model.
   * It will involve some updates.
   * These invalidations are made most of the time automatically, but can also be called directly 
   * using this method.
   * @param i_invalidationToken the token related to the part of the model to invalidate
   * @param i_repType the type of rep from which the algo is invalidated. 
   * In some cases, this input is ignored (for PickPath, for example).
   */
  virtual HRESULT Invalidate(CATVisInvalidationToken i_invalidationToken, CATVisRepresentationRole i_repType=AllRoles) = 0;
};

//-----------------------------------------------------------------------
CATDeclareHandler( CATIVisView, CATBaseUnknown );

#endif
