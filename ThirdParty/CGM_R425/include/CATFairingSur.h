/*-*-C++-*-*/
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
//
// CATFairingSurCx2 :
// Implementation class for Fairing.
//
//=============================================================================
// Usage notes: Surface Smoothing for Surface
// Note :
// sample of use :
// to provide
//
//=============================================================================
// Mar. 99  Creation
//=============================================================================
#ifndef CATFairingSur_H
#define CATFairingSur_H

#include "FrFOpeSur.h"
#include "CATSkillValue.h"
#include "CATCGMVirtual.h"

class CATNurbsSurface;
class CATGeoFactory;

//-----------------------------------------------------------------------------
class ExportedByFrFOpeSur  CATFairingSur : public CATCGMVirtual
{
 public:
  
  virtual ~CATFairingSur() {};

  virtual void SetSmoothingFactor(double iSmooth) =0;
  
  virtual void Run() =0;
  
};



//-----------------------------------------------------------------------------
ExportedByFrFOpeSur
CATFairingSur * CreateFairingSur(CATGeoFactory   * iFactory      ,
                                 CATNurbsSurface * ioNurbsSurface,
                                 double            iSmoothing    = 1.,
                                 CATSkillValue     iMode         = BASIC);


ExportedByFrFOpeSur void Remove(CATFairingSur *&iFair);

#endif
  
