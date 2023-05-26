//==================================================================-*- C++ -*-
// COPYRIGHT Dassault Systemes 2015
//=============================================================================
//
// Simulia® contact visualization callback for thickness
// interface. Proposes an interface to implement. Allows the user to
// define a thickness for surfaces to take into account in addition to
// the distance contact value. The thickness can be different for each
// triangle of each mesh.
//
//=============================================================================
// 2015-11   XXC: New.
//=============================================================================

#ifndef CATPolyMeshContactThicknessCallback_h
#define CATPolyMeshContactThicknessCallback_h

#include "PolyVisuContact.h"

class CATMathPoint;
class CATRep;
class CATPolyBody;

class ExportedByPolyVisuContact CATPolyMeshContactThicknessCallback
{
 public:
  CATPolyMeshContactThicknessCallback() {}

  virtual ~CATPolyMeshContactThicknessCallback() {}

  /** Virtual method to implement. Returns the thickness of the
   *  geoemtry at the given point for the given object.
   */
  virtual HRESULT Thickness(const CATRep * iTerminalRep, unsigned int iCGMId, const CATMathPoint & iPointOnGeometry,
                            double & oThickness, double & offSet) = 0;

  virtual HRESULT Thickness(const CATPolyBody * iBody, int iFaceId, int iTriangleIndex, const CATMathPoint & iPointOnGeometry,
                            double & oThickness, double & offSet) = 0;

};

#endif //CATPolyMeshContactThicknessCallback_h
