// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// CATSYPColorAnimation.h
// Header definition of CATSYPColorAnimation
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Aug 2008  Creation: jov
//===================================================================
#ifndef CATSYPColorAnimation_H
#define CATSYPColorAnimation_H

#include <VisuDialog.h>
#include <CATSYPAnimationTimeline.h>

class ExportedByVisuDialog CATSYPColorAnimation: public CATSYPAnimationTimeline
{
  CATDeclareClass;

public:
  // Standard constructor
  // --------------------
  CATSYPColorAnimation ();

protected:
  virtual ~CATSYPColorAnimation ();
  virtual void UpdateCurrentValue();
private:
  // Copy constructor and equal operator
  // -----------------------------------
  CATSYPColorAnimation (CATSYPColorAnimation &);
  CATSYPColorAnimation& operator=(CATSYPColorAnimation&);
  
};
//-----------------------------------------------------------------------

#endif
