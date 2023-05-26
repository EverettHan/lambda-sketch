// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// CATSYPPointfAnimation.h
// Header definition of CATSYPPointfAnimation
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Aug 2008  Creation: jov
//===================================================================
#ifndef CATSYPPointfAnimation_H
#define CATSYPPointfAnimation_H

#include <IntroInfra.h>
#include <CATSYPAnimationTimeline.h>
#include <CATMathPointf.h>

class ExportedByIntroInfra CATSYPPointfAnimation: public CATSYPAnimationTimeline
{
  CATDeclareClass;

public:
  // Standard constructor
  // --------------------
  CATSYPPointfAnimation ();

	void SetFrom (const CATMathPointf &i_spPropertyValue);
  void SetTo (const CATMathPointf &i_spPropertyValue);

protected:
  virtual ~CATSYPPointfAnimation ();
  void UpdateCurrentValue();
private:
  // Copy constructor and equal operator
  // -----------------------------------
  CATSYPPointfAnimation (CATSYPPointfAnimation &);
  CATSYPPointfAnimation& operator=(CATSYPPointfAnimation&);
};
//-----------------------------------------------------------------------

#endif
