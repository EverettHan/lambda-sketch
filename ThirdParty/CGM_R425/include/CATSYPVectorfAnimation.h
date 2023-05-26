#ifndef CATSYPVectorfAnimation_H
#define CATSYPVectorfAnimation_H

// COPYRIGHT Dassault Systemes 2010

#include <IntroInfra.h>
#include <CATSYPAnimationTimeline.h>
#include <CATMathVectorf.h>

class ExportedByIntroInfra CATSYPVectorfAnimation : public CATSYPAnimationTimeline
{
  CATDeclareClass;

public:
  // Standard constructor
  // --------------------
  CATSYPVectorfAnimation ();

  void SetFrom(const CATMathVectorf &i_spPropertyValue);
  void SetTo(const CATMathVectorf &i_spPropertyValue);

protected:
  virtual ~CATSYPVectorfAnimation ();
  // Copy constructor and equal operator
  // -----------------------------------
  CATSYPVectorfAnimation (CATSYPVectorfAnimation &);
  CATSYPVectorfAnimation& operator=(CATSYPVectorfAnimation&);

  void UpdateCurrentValue();
  
private:
  void UpdateCrossProduct();
  
private:
  CATMathVectorf _crossProduct;
  double _angle;
  
};
//-----------------------------------------------------------------------

#endif
