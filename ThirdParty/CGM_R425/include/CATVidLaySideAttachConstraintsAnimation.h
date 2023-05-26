// COPYRIGHT Dassault Systemes 2013
//===================================================================
//
// CATVidLaySideAttachConstraintsAnimation.h
// Header definition of CATVidLaySideAttachConstraintsAnimation
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  July 2013  Creation: efm
//===================================================================
#ifndef CATVidLaySideAttachConstraintsAnimation_H
#define CATVidLaySideAttachConstraintsAnimation_H

#include <VisuDialog.h>
#include <CATSYPAnimationTimeline.h>

class CATVidLaySideAttachConstraints;

class ExportedByVisuDialog CATVidLaySideAttachConstraintsAnimation: public CATSYPAnimationTimeline
{
  CATDeclareClass;

public:
  // Standard constructor
  // --------------------
  CATVidLaySideAttachConstraintsAnimation ();

  void SetFrom(const CATVidLaySideAttachConstraints& i_fromValue);
  void SetTo(const CATVidLaySideAttachConstraints& i_toValue);

protected:
  virtual ~CATVidLaySideAttachConstraintsAnimation ();
  virtual void UpdateCurrentValue();

private:
  // Copy constructor and equal operator
  // -----------------------------------
  CATVidLaySideAttachConstraintsAnimation (CATVidLaySideAttachConstraintsAnimation &);
  CATVidLaySideAttachConstraintsAnimation& operator=(CATVidLaySideAttachConstraintsAnimation&);

};
//-----------------------------------------------------------------------

#endif
