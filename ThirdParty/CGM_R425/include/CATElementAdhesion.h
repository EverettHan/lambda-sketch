/* -*-c++-*- */

//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 1997  
//-----------------------------------------------------------------------------
// class CATElementAdhesion :
// 
// 
// This class is an extension providing interfaces : 
// - LifeCycleObject
// - CATImplementationCATIA
// binding for late typed implementation CATElement
//-----------------------------------------------------------------------------
// Usage Notes:
//
// The binding is referenced in Data.d/ObjectModelerCATIA.dic
//-----------------------------------------------------------------------------
// Creation by Users asg & pjo - February 97
//-----------------------------------------------------------------------------
/**
* @level Private 
* @usage U1
*/
#ifndef CATElementAdhesion_h
#define CATElementAdhesion_h

#include "AC0CATPL.h"

class CATBaseUnknown ;
class CATIAModel ;


#include "CATOmcElementAdapter.h"
class ExportedByAC0CATPL CATElementAdhesion : public CATOmcElementAdapter 
{
  CATDeclareClass ;
public:
  CATElementAdhesion() ;
  virtual ~CATElementAdhesion() ;
protected:
  CATElementAdhesion& operator= (const CATElementAdhesion& from) ;
} ;

#endif
