/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATIBindParameters_h
#define CATIBindParameters_h

/**
 * @level Private
 * @usage U3
 */

#include "CATBaseUnknown.h"
#include "CATDataType.h"


enum CATParameterKind 
{
  CATSessionParameters=1,
  CATOnlyAmongLoadedObjects=2,
  CATGetMinimumObjectData=3
};



//
// Possible values of CATSessionParameters
//
const CATLONG32 CATIgnore = -1 ;
const CATLONG32 CATLowPriority = 0 ;
const CATLONG32 CATHighPriority = 1 ;


#include "CATObjectModelerBase.h"
extern ExportedByCATObjectModelerBase IID IID_CATIBindParameters ;

class ExportedByCATObjectModelerBase CATIBindParameters : public CATBaseUnknown
{
  CATDeclareInterface;

public:
  virtual CATLONG32 Get (CATParameterKind kind) const =0 ;
  virtual void Set (CATParameterKind kind, CATLONG32 value)=0 ;
};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIBindParameters, CATBaseUnknown ) ;


#endif
