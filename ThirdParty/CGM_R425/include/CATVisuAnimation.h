// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// CATVisuAnimation.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Oct 2004  Creation: jov
//===================================================================
#ifndef CATVisuAnimation_H
#define CATVisuAnimation_H

#include "CATVisFoundation.h"
#include "CATBoolean.h"
class CATVizTimerInteraction;
class CATVisuAnimationWeakRef;

/**
 *
 */
class ExportedByCATVisFoundation CATVisuAnimation
{
  friend class CATVisuAnimationWeakRef;

public:
  
  // Constructors
  // ------------
  CATVisuAnimation (float i_requiredDuration, CATBoolean i_goBackFlag = FALSE, int i_nbLoop = 1, float i_delay = 0.f, CATBoolean i_deteriorateDraw = TRUE);
  // Standard destructor
  // -------------------
  virtual ~CATVisuAnimation ();

  virtual void Start();
  void Step();
  virtual void End();

  void CutShort();
  void CutShortImmediately();
  void FirstValuation(float i_drawToDrawDuration);
  CATBoolean IsSleeping();
  float GetDelay();
  virtual float WakeUp();
  virtual CATBoolean IsRemoveNeeded();
  CATBoolean& IsEnded();

  void DeteriorateDraw(CATBoolean iOnOff);
  CATBoolean IsDrawDeteriorated() const;

  CATVisuAnimationWeakRef *GetWeakRef( void );

protected:
  void Evaluate();
  virtual void GoToStep() {}
  void Sleep();
  float GetProgressPrevision();
  void InitAnimation(float i_requiredDuration, CATBoolean i_goBackFlag = FALSE, unsigned int i_nbLoop = 1, float i_delay = 0.f);

private:
  // Copy constructor and equal operator
  // -----------------------------------
//  CATVisuAnimation(const CATVisuAnimation&);
  CATVisuAnimation& operator=(CATVisuAnimation&){return *this;}
protected:
  void UnreferenceWeakRef( void );


private:
  CATBoolean _sleepingFlag;
  unsigned int        _nbLoop;
  float _requiredDuration;
  unsigned int        _currentLoop;
  float _totalDuration;
  int   _nbStep;
  CATVizTimerInteraction* _pStepToStepInteraction;
  CATVizTimerInteraction* _pSleepingInteraction;
  float _progressPrevision;

  CATVisuAnimationWeakRef* _pWeakRef;
  CATBoolean _goBackFlag;
  CATBoolean _goingBackFlag;
  float      _delay;
  CATBoolean _endedFlag;

  CATBoolean _deteriorateDraw;
};

#include "CATWeakRefTemplate.h"
DeclareWeakRef(CATVisuAnimation, ExportedByCATVisFoundation);

//-----------------------------------------------------------------------
#endif
