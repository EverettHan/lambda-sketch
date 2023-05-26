// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// CATSYPPoint2DfAnimation.h
// Header definition of CATSYPPoint2DfAnimation
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Aug 2008  Creation: jov
//===================================================================
#ifndef CATSYPPoint2DfAnimation_H
#define CATSYPPoint2DfAnimation_H

#include <IntroInfra.h>
#include <CATSYPAnimationTimeline.h>
#include <CATMathPoint2Df.h>

class ExportedByIntroInfra CATSYPPoint2DfAnimation: public CATSYPAnimationTimeline
{
  CATDeclareClass;

public:
  // Standard constructor
  // --------------------
  CATSYPPoint2DfAnimation ();

	void SetFrom (const CATMathPoint2Df &i_spPropertyValue);
  void SetTo (const CATMathPoint2Df &i_spPropertyValue);

protected:
  virtual ~CATSYPPoint2DfAnimation ();
  void UpdateCurrentValue();
private:
  // Copy constructor and equal operator
  // -----------------------------------
  CATSYPPoint2DfAnimation (CATSYPPoint2DfAnimation &);
  CATSYPPoint2DfAnimation& operator=(CATSYPPoint2DfAnimation&);
};
//-----------------------------------------------------------------------

#endif
