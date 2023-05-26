// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATTessBodyBuilderCaptureObserver
//
//===================================================================
// May 2012  Creation: NDO
//===================================================================
#ifndef CATTessBodyBuilderCaptureObserver_H
#define CATTessBodyBuilderCaptureObserver_H

#include "TessBodyAdapters.h"
#include "CATTessBodyBuilderObserver.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"

class CATTessBodyBuilder;
class CATBody;
class CATPGMTessBody;
class CATechExt;
class CATString;


/**
 * Observer class that records the events from a CATTessBodyBuilder for the Phoenix.
 */
class ExportedByTessBodyAdapters CATTessBodyBuilderCaptureObserver : public CATTessBodyBuilderObserver
{

public:

  /**
   * Observer constructed by CATTessBodyBuilder if Phoenix capture is enabled.
   */
  CATTessBodyBuilderCaptureObserver (const CATTessBodyBuilder& iBuilder);

  ~CATTessBodyBuilderCaptureObserver ();

public:

/** @name Observing CATTessBodyBuilder events
    @{ */

  void BeforeRun (const CATBody& iBody);

  void AfterRun (const CATPGMTessBody& iTessBody);

/** @} */

public:

  // Access to parameters and data.

  const CATTessBodyBuilder& GetBuilder () const {return _TessBodyBuilder;}

  const CATBody* GetInputBody () const {return _InputBody;}
  const CATPGMTessBody* GetOutputTessBody () const {return _OutputTessBody;}

public:

  /**
   * Returns the name of the Phoenix.
   */
  static const CATString& GetName ();

  /**
   * Returns <tt>TRUE</tt> if the capture of the data has been enabled.
   */
  static CATBoolean IsCaptureEnabled ();

  // Phoenix extension.
  void SetPhoenixExtension (CATechExt* iExtension);
  CATechExt* HasPhoenixExtension (CATBoolean iForceCreation = FALSE);

private:

  CATBoolean _DoJournaling;

  // Phoenix data members.
  CATechExt* _Phoenix;

  // Captured operator (for access to all its parameters.)
  const CATTessBodyBuilder& _TessBodyBuilder;

  // Captured input data.
  const CATBody* _InputBody;

  // Captured output data.
  const CATPGMTessBody* _OutputTessBody;

};

#endif // !CATTessBodyBuilderCaptureObserver_H
