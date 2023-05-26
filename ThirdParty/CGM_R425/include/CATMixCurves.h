/* -*-C++-*-*/
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 1997
//=============================================================================
//
// CATMixCurves :
// Interface class of the Mixing Curves operator.
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
// November. 97  Creation                          
//=============================================================================
#ifndef CATMixCurves_H 
#define CATMixCurves_H 

#include "FrFOpeCrv.h"
#include "CreateMixCurves.h"
#include "CATCGMVirtual.h"

class CATNurbsCurve;

//-----------------------------------------------------------------------------
class ExportedByFrFOpeCrv CATMixCurves : public CATCGMVirtual
{
  public :
  
  virtual                   ~CATMixCurves();
   
  virtual void              Run() =0;

  virtual CATNurbsCurve*    GetMixedCurve() const =0;

};

#endif
