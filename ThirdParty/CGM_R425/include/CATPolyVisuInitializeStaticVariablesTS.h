// COPYRIGHT DASSAULT SYSTEMES 2010, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyVisuInitializeStaticVariablesTS.h
//
//===================================================================
//
// Septembre 2010 Creation: jxo
//===================================================================
#ifndef CATPolyVisuInitializeStaticVariablesTS_h
#define CATPolyVisuInitializeStaticVariablesTS_h

#include "CATErrorDef.h"  // HRESULT definition.
#include "PolyVisuBVH.h"
#include "CATPolyInitializeStaticVariablesTS.h"


/**
 * Calls static functions used during any multi-thread computation
 *
 */

class ExportedByPolyVisuBVH CATPolyVisuInitializeStaticVariablesTS : public CATPolyInitializeStaticVariablesTS
{

public:

  CATPolyVisuInitializeStaticVariablesTS () {}
  ~CATPolyVisuInitializeStaticVariablesTS () {}

public:

  // Calls static functions used during any multi-thread computation
  virtual HRESULT InitializeStaticVariables ();


};

#endif
