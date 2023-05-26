// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// CATSYPQuaternionAnimation.h
// Header definition of CATSYPQuaternionAnimation
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Aug 2008  Creation: qf1
//===================================================================
#ifndef CATSYPQuaternionAnimation_H
#define CATSYPQuaternionAnimation_H

#include <IntroInfra.h>
#include <CATSYPAnimationTimeline.h>
#include <CATMathQuaternion.h>

class ExportedByIntroInfra CATSYPQuaternionAnimation: public CATSYPAnimationTimeline
{
  CATDeclareClass;

public:
  // Standard constructor
  // --------------------
  CATSYPQuaternionAnimation ();
  
  void SetFrom (const CATMathQuaternion &i_spPropertyValue);
  void SetTo (const CATMathQuaternion &i_spPropertyValue);
  

protected:
  virtual ~CATSYPQuaternionAnimation ();
  virtual void UpdateCurrentValue();
private:
  // Copy constructor and equal operator
  // -----------------------------------
  CATSYPQuaternionAnimation (CATSYPQuaternionAnimation &);
  CATSYPQuaternionAnimation& operator=(CATSYPQuaternionAnimation&);
  
};
//-----------------------------------------------------------------------

#endif
