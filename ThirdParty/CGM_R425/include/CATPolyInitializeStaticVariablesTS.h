// COPYRIGHT DASSAULT SYSTEMES 2010, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyInitializeStaticVariablesTS.h
//
//===================================================================
//
// Septembre 2010 Creation: jxo
//===================================================================
#ifndef CATPolyInitializeStaticVariablesTS_h
#define CATPolyInitializeStaticVariablesTS_h

#include "CATErrorDef.h"  // HRESULT definition.
#include "PolyBodyBVHOperators.h"


/**
 * Calls static functions used during any multi-thread computation
 *
 */

class ExportedByPolyBodyBVHOperators CATPolyInitializeStaticVariablesTS 
{

public:

  CATPolyInitializeStaticVariablesTS () {}
  ~CATPolyInitializeStaticVariablesTS () {}

public:

  // Calls static functions used during any multi-thread computation
  virtual HRESULT InitializeStaticVariables ();


};

#endif
