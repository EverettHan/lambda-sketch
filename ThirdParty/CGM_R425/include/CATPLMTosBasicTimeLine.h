#ifndef _CATPLMTosBasicTimeLine_H
#define _CATPLMTosBasicTimeLine_H

/**
 * @level Protected
 * @usage U1
 */
#include "CATLib.h"
#include "IUnknown.h"
#include "ExportedByCATPLMIdentification.h"
#include "CATErrorMacros.h"
#include "CATErrorMacrosEx.h"
#include "CATPLMTosBasicTimeLineEvents.h"
#include "CATOmxOrderedOHMap.h"
#include "CATComponentId.h"

class CATPLMTosBasicTimeLineVisitor;
class CATOxBasicTimeLine;
class CATOxEntity;
void CATPLMTosBasicTimeLine_OnEvent(class CATOxEntity& iEntity, CATPLMTosBasicTimeLineEvents iEvent);

//==========================================================================
// How using time line
//==========================================================================
//
//    CATPLMTosBasicTimeLine TimeLine;
//    CATPLMTosBasicTimeLine_StartRecording(TimeLine, CATPLMTosBasicTimeLineEvent_ToCreate|CATPLMTosBasicTimeLineEvent_ToDelete);
//    {
//
//    }
//    CATPLMTosBasicTimeLine_StopRecording(TimeLine);
//
//    CATPLMTosBasicTimeLineVisitor Visitor;
//    TimeLine.Visit (Visitor);
//
//===========================================================================
class ExportedByCATPLMIdentification CATPLMTosBasicTimeLine
{
public:

  /**
  * Constructor.
  */
  CATPLMTosBasicTimeLine();

  /**
  * Destructor.
  */
  ~CATPLMTosBasicTimeLine();

  /**
  * Visit registrations
  */
  HRESULT Visit(CATPLMTosBasicTimeLineVisitor & iVisitor) const;

  /**
  * Start registration
  * To be called only by : CATPLMTosBasicTimeLine_StartRecording
  */
  void Macro_StartRecording(CATPLMTosBasicTimeLineEvents);

  /**
  * Stop registration
  * To be called only by : CATPLMTosBasicTimeLine_StopRecording
  */
  void Macro_StopRecording();

private:

  CATPLMTosBasicTimeLine(const CATPLMTosBasicTimeLine & iCopy);
  CATPLMTosBasicTimeLine & operator=(const CATPLMTosBasicTimeLine & iCopy);

  CATOmxOrderedOHMap<CATComponentId, unsigned int> m_events;
  CATPLMTosBasicTimeLineEvents m_mask;

  friend void CATPLMTosBasicTimeLine_OnEvent(class CATOxEntity&, CATPLMTosBasicTimeLineEvents);
};

/**
*  Start time line registration
*/
#define CATPLMTosBasicTimeLine_StartRecording(iTimeLine, iEventMask)  \
  CATXH_ENSURE_DESTRUCTION(iTimeLine); \
  iTimeLine.Macro_StartRecording(iEventMask)

/**
*  End time line registration
*/
#define CATPLMTosBasicTimeLine_StopRecording(iTimeLine) iTimeLine.Macro_StopRecording()

#endif
