#ifndef CATFRM2DCAMERA_H 
#define CATFRM2DCAMERA_H
#include "CATAfrFoundation.h"
//
// COPYRIGHT DASSAULT SYSTEMES 1996
//------------------------------------------------------------------------------
// Abstract: Implementation of 2D Camera
//
//------------------------------------------------------------------------------
// Usage:    Each visualizable Document can have one or more saved viewpoints.
//
//------------------------------------------------------------------------------
// Inheritance: 
//------------------------------------------------------------------------------
// Main methods:    
//
//       
//------------------------------------------------------------------------------
//       
//#include "CATBaseUnknown.h"
//
//#include "CATICamera.h"
#include "CATFrmCamera.h"

#include "CATMathPoint2D.h"
#include "CATMathDef.h"

#include "CATUnicodeString.h"

class ExportedByCATAfrFoundation CATFrm2DCamera: public CATFrmCamera
{
//------------------------------------------------------------------------------
 public:

   CATDeclareClass;

// Constructor / Destructor
// ------------------------
   CATFrm2DCamera(CATUnicodeString name);
   CATFrm2DCamera(CATUnicodeString name, CATMathPoint2D origin, double scale);

   virtual void CopyFrom(CATICamera * camera);

   virtual ~CATFrm2DCamera();
 
// CATICamera data
// ---------------
   virtual void WriteToStream(void ** stream, CATULONG32& length);
   virtual void ReadFromStream(void * stream, CATULONG32  length);

// CATI2DCamera data
// -----------------
   virtual CATMathPoint2D   GetOrigin();
   virtual void             SetOrigin(CATMathPoint2D origin);

   virtual double           GetScale();
   virtual void             SetScale(double scale);

 private:

   CATMathPoint2D           _origin; 
   double                   _scale; 
}; 
#endif





































