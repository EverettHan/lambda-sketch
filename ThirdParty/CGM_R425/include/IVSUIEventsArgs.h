#ifndef IVSUIEventsArgs_H
#define IVSUIEventsArgs_H

//COPYRIGHT DASSAULT SYSTEMES 2020

#include "IVInterfaces.h"
#include "CATSYPEventArgs.h"
#include "CATMathTransformation.h"

class CATSYPEvent;

/**
* IVSUIEvtArgs - base class for SUI event arguments.
* @see IVSUIEvents
*/
class ExportedByIVInterfaces IVSUIEvtArgs : public CATSYPEventArgs
{

  CATDeclareClass;

public:

  virtual ~IVSUIEvtArgs() {};

  CATULONG64 TStamp() const { return m_ticks; }

protected:

  IVSUIEvtArgs(CATSYPEvent *i_pEvent, CATULONG64 iTicks) : CATSYPEventArgs(i_pEvent), m_ticks(iTicks) {};

private:

  CATULONG64 const m_ticks;
};

/**
 * IVButtonEvtArgs - describes a button modification on the device that
 * emitted the IVDeviceButtonUpdated event.
 */
class ExportedByIVInterfaces IVSUIEntityEvtArgs : public IVSUIEvtArgs
{

  CATDeclareClass;

public:

  /**
  * Describe a modification of the state of the button.
  */
  IVSUIEntityEvtArgs(CATSYPEvent *i_pEvent, CATULONG64 iTicks, const CATMathTransformation& iPose) : IVSUIEvtArgs(i_pEvent, iTicks), m_Pose(iPose) {}

  /**
  * Describe the new state of the button.
  */
  const CATMathTransformation& Pose() const { return m_Pose; }

private:

  CATMathTransformation m_Pose;
};

#endif

