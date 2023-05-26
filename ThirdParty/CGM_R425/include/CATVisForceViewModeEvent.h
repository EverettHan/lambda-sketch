// COPYRIGHT DASSAULT SYSTEMES 2015
#ifndef CATVisForceViewModeEvent_H
#define CATVisForceViewModeEvent_H

#include "CATVisController.h"
#include "CATTimeStampedEvent.h"
#include "CATUnicodeString.h"
#include "CATPathElement.h"


/**
* Class notification for CATFont events.
*/
//===============================================================================
class ExportedByCATVisController CATVisForceViewModeEvent : public CATTimeStampedEvent
{
   CATDeclareClass;

public :

   /** @nodoc */
  CATVisForceViewModeEvent(CATUnicodeString iEventName, CATPathElement* iRepBeingDeleted);
  /** @nodoc */
   virtual ~CATVisForceViewModeEvent();

   /** @nodoc */
   CATUnicodeString & GetForceViewModeEventName();
   /** @nodoc */
   CATPathElement * GetPathElement();   
   unsigned int GetForceAxis() { return _forceAxis; };
   unsigned int GetForceLines() { return _forceLines; };
   unsigned int GetForcePoints() { return _forcePoints; };

   void SetForceAxis(unsigned int iForcedValue) { _forceAxis = iForcedValue; };
   void SetForceLines(unsigned int iForcedValue) { _forceLines = iForcedValue; };
   void SetForcePoints(unsigned int iForcedValue) { _forcePoints = iForcedValue; };
   

private :

   CATUnicodeString _EventName;
   CATPathElement*        _pathElement;
   unsigned int _forceAxis;
   unsigned int _forceLines;
   unsigned int _forcePoints;
   
};

//===============================================================================
#endif
