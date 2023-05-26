/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1998
//
//==============================================================================
// Inheritance
// -----------
// CATIFeatCamera
//    CATI3DCamera
//       CATICamera
//
//==============================================================================
// Abstract
// --------
// Interface for DMU camera features
//
//==============================================================================
// Usage
// -----
// 
//
//==============================================================================
// History
// -------
//==============================================================================
#ifndef CATIFeatCamera_H
#define CATIFeatCamera_H

class CATUnicodeString;
class CATISpecObject_var;

#include "CATI3DCamera.h"
#include "CATAfrFoundation.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrFoundation IID IID_CATIFeatCamera;
#else
extern "C" const IID IID_CATIFeatCamera;
#endif

class ExportedByCATAfrFoundation CATIFeatCamera : public CATI3DCamera
{
public:
  // macros
  CATDeclareInterface;
  
  virtual const double GetFocus    () const               = 0;
  virtual void         SetFocus    (const double focus)   = 0;
  virtual const int    GetRepresentation   () const       = 0;
  virtual void         SetRepresentation (const int visu) = 0;
  virtual HRESULT      GetDirectionProjection (float& xDir, float& yDir, float& zDir ) = 0;
  virtual HRESULT      SetDirectionProjection (const float& xDir, const float& yDir, const float& zDir ) = 0;

};

CATDeclareHandler(CATIFeatCamera,CATI3DCamera);

#endif 
