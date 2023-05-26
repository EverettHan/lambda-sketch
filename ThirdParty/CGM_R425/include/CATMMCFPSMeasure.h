#ifndef CATMMCFPSMEASURE_H
#define CATMMCFPSMEASURE_H

#include "CATMMediaCore.h"

#include "CATSysElapseTime.h"

class ExportedByCATMMediaCore CATMMCFPSMeasure
{
public:
  /**
   * Constructor with optional number of second while the instant FPS will be measured.
   */
  CATMMCFPSMeasure(int iNbSecond=1);
  /**
   * Desctructor.
   */
  virtual ~CATMMCFPSMeasure();

  /**
   * Start time and frames count for fps evaluation.
   */
  void  Start();

  /**
   * Increment the number of frames to be divided.
   */
  void  IncrementFrames();

  /**
   * Check if instant fps has changed since last call of this method.
   */
  bool  HasNewInstantFPS();

  /**
   * Return the global fps: since Start, number of frames divided by global duration.
   */
  int   GetGlobalFPS();

  /**
   * Return the instant fps. Depends on input iNbSecond defined through constructor.
   */
  int   GetInstantFPS();

private:
  void  Reset();

  CATSysElapseTime      m_t;
  int                   m_LastInstantFPS;//Per m_secondsForInstant second
  int                   m_CountInstant;//Per m_secondsForInstant second
  int                   m_CountGlobal;//Global
  double                m_tot;
  const int             m_secondsForInstant;
};

#endif
