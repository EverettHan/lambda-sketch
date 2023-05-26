// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// CATVisu3DViewpointAnimation.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Oct 2004  Creation: jov
//===================================================================
#ifndef CATVisu3DViewpointAnimation_H
#define CATVisu3DViewpointAnimation_H

#include "CATVisFoundation.h"
#include "CATVisuAnimation.h"
#include "CATBoolean.h"
#include "CATMathDirectionf.h"

class CAT3DViewpoint;

/**
 *
 */
class ExportedByCATVisFoundation CATVisu3DViewpointAnimation : public CATVisuAnimation
{
public:
  
  // Constructors
  // ------------
  CATVisu3DViewpointAnimation (float i_duration, CAT3DViewpoint* i_prToModifyViewpoint, CAT3DViewpoint* i_pEndingPositionViewpoint);
  // Standard destructor
  // -------------------
  virtual ~CATVisu3DViewpointAnimation ();

  static void SetAnimationMode(int iAnimMode); // 0: linear animation; 1: non-linear animation
  virtual void Start();
  virtual void End();

protected:
  virtual void GoToStep();

  CATMathDirectionf ComputeRotationTransformation(CATMathDirectionf& i_firstDirection, const CATMathDirectionf& i_secondDirection);

private:
  // Copy constructor and equal operator
  // -----------------------------------
  CATVisu3DViewpointAnimation& operator=(CATVisu3DViewpointAnimation&){return *this;};

  static int Vis3DViewpointAnimationMode; // 0: linear animation; 1: non-linear animation
  int _animationMode; // 0: linear animation; 1: non-linear animation

protected:
  CAT3DViewpoint* _prToModifyViewpoint;
  CAT3DViewpoint* _pEndingPositionViewpoint;
  CAT3DViewpoint* _pBeginningPositionViewpoint;
};

//-----------------------------------------------------------------------
#endif
