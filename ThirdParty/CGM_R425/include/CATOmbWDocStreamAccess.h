/* -*-c++-*- */
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2000
//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
// Usage Notes:
//
// Global functions for ObjectModelerBase 
//
//-----------------------------------------------------------------------------
// Creation by pbv - oct 2004
//-----------------------------------------------------------------------------
#ifndef CATOmbWDocStreamAccess_H
#define CATOmbWDocStreamAccess_H

/**
 * @level Private
 * @usage U1
 */

#include "AD0XXBAS.h"
#include "CATBaseUnknown.h"

class CATVVSURLConnection;
class CATDocument;

class ExportedByAD0XXBAS CATOmbWDocStreamAccess
{
  friend class CATDocument;
  friend class CATContainerStgExt;

public:

  CATOmbWDocStreamAccess(CATDocument &iDoc);

	inline ~CATOmbWDocStreamAccess(){};

 /**
  * Returns URL Connection
  *
  * @result [OUT] 
  *         Not null : if URL connection is found
  */
  CATVVSURLConnection * GetURLConnection();

private:	
	
	CATDocument& _Doc;
};

#endif
