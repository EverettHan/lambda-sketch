// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATTessBodyBuilderObserver
//
//===================================================================
// May 2012  Creation: NDO
//===================================================================
#ifndef CATTessBodyBuilderObserver_H
#define CATTessBodyBuilderObserver_H

//#include "TessBodyAdapters.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"

class CATBody;
class CATPGMTessBody;


/**
 * Observer interface for the CATTessBodyBuilder.
 * An observer class can be derived from this interface to record for example all the events
 * associated to the construction of a CATPGMTessBody.
*/
class CATTessBodyBuilderObserver
{

public:

  virtual ~CATTessBodyBuilderObserver () {}

public:

/** @name Observing CATTessBodyBuilder events
    @{ */

  virtual void BeforeRun (const CATBody& iBody) {}

  virtual void AfterRun (const CATPGMTessBody& iTessBody) {}

/** @} */

};


#endif // !CATTessBodyBuilderObserver_H
