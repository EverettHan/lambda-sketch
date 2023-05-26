// COPYRIGHT Dassault Systemes 2008
//===================================================================
//  Feb 2012  Creation: jov
//===================================================================
#ifndef CATSYPTimeManagerAbstract_H
#define CATSYPTimeManagerAbstract_H

#include <IntroInfra.h>
#include <CATCommand.h>
#include <CATSYPArray.h>
#include <CATBoolean.h>
#include <CATSYPIntervalCaller.h>

class CATSYPAnimationTimeline;
class CATSYPStoryboard;
class CATSYPAbstractClock;
class CATSYPTimeManager_command;
//-----------------------------------------------------------------------

class ExportedByIntroInfra CATSYPTimeManagerAbstract
{
public:
  /** Constructor */
  CATSYPTimeManagerAbstract ();
  /** Destructor */
  virtual ~CATSYPTimeManagerAbstract ();
  /** Adds a storyboard to the time manager */
  void AddTimeline(CATSYPStoryboard* i_pAnimation);
  /** Removes a storyboard to the time manager */
  void RemoveTimeline(CATSYPStoryboard* i_pAnimation);
	void AddIntervalCaller(CATSYPIntervalCaller* i_pIntervalCaller);
	void RemoveIntervalCaller(CATSYPIntervalCaller* i_pIntervalCaller);
  /** Check if a storyboard is currently in the time manager */
  CATBoolean IsRunning(const CATSYPStoryboard* i_prAnimation) const;
  /**
   * Sets the static time manager used to animate storyboards
   */
  static void SetStaticTimeManager(CATSYPTimeManagerAbstract* i_pTimeManager);
  /** @return the static time manager */
  static CATSYPTimeManagerAbstract& GetStaticTimeManager();
  /** @return the number of running timeline. */
  int GetNbRunningTimelines() const;
  /** Set the _ignoreTransitionTimelineFlag (mostly used in ODT replay) **/
  void SetIgnoreTransitionTimelineFlag(const CATBoolean &i_ignoreTransitionTimelineFlag);
  /** @return _ignoreTransitionTimelineFlag **/
  CATBoolean GetIgnoreTransitionTimelineFlag() const;

protected:
  /** Instanciates a new clock for a given stotyboard */
  virtual CATSYPAbstractClock* InstanciateClock(CATSYPStoryboard* i_pAnimation)=0;
	virtual CATSYPAbstractClock* InstanciateClock(CATSYPIntervalCaller* i_pIntervalCaller);
  /** This method is called when the time manager begin to work (first storyboard added in time manager)*/
  virtual void Begin()=0;
  /** This method is called when the time manager stops to work (last storyboard removed from the time manager)*/
  virtual void Stop() =0;
  /***/
  void UpdateClocks();
public: 
  /** This service could be called to know if the time manager is real-time or simulated by code */
  virtual CATBoolean IsSimulated() { return FALSE; }
private:
  /** no copy constructor*/
  CATSYPTimeManagerAbstract (CATSYPTimeManagerAbstract &);
  /** no operator= */
  CATSYPTimeManagerAbstract& operator=(CATSYPTimeManagerAbstract&);
  /** Cleans the dead clocks, that is destroy clock corresponding to finished storyboard, and remove the storyboards.*/
  void CleanDeadClocks();
protected:
  CATBoolean _ignoreTransitionTimelineFlag;
  CATBoolean _animationOnFlag;
  CATSYPDynArray<CATBaseUnknown_var> _clockList;

  friend class CATVidNotifierTransactionModeRecorder;
};
//-----------------------------------------------------------------------

#endif
