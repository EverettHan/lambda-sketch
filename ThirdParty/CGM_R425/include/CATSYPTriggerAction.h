// COPYRIGHT Dassault Systemes 2007
//===================================================================
//
// CATSYPTriggerAction.h
// Header definition of CATSYPTriggerAction
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Mar 2007  Creation: Code generated by the CAA wizard  jov
//===================================================================
#ifndef CATSYPTriggerAction_H
#define CATSYPTriggerAction_H

#include <IntroInfra.h>
#include <CATBaseUnknown.h>
#include <CATISYPCollection.h>
#include <CATLISTV_CATBaseUnknown.h>
#include <CATUnicodeString.h>
#include <CATSYPHashMap.h>

class CATSYPMappingTablePointerToPointer;

//-----------------------------------------------------------------------

class ExportedByIntroInfra CATSYPTriggerAction: public CATBaseUnknown
{
  CATDeclareClass;

public:
  // Standard constructor
  // --------------------
  CATSYPTriggerAction ();

  virtual bool Start();
  virtual void Stop();
  /**
  * Internal function used by the Style Processor.
  * Initializes a list of named targets.
  */

protected:
  virtual ~CATSYPTriggerAction ();
  unsigned char GetCurrentActionFlag() { return _currentActionFlag; }
private:
  // Copy constructor and equal operator
  // -----------------------------------
  CATSYPTriggerAction (CATSYPTriggerAction &);
  CATSYPTriggerAction& operator=(CATSYPTriggerAction&);
  unsigned char _currentActionFlag;
};
//-----------------------------------------------------------------------

#endif