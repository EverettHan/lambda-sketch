// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyRefinerDefaultParams.h
//
//===================================================================
//
// March 2009  Creation: ndo
//===================================================================
#ifndef CATPolyRefinerDefaultParams_h
#define CATPolyRefinerDefaultParams_h

#include "PolyVizAdapters.h"


class ExportedByPolyVizAdapters CATPolyRefinerDefaultParams 
{

public:

  // Return the maximum level of refinement that cannot be exceeded (adaptive or uniform.)
  static unsigned int GetRefinementLevelMax ();

  // Do not use.
  static unsigned int GetRefinementLevel () {return GetRefinementLevelMax ();}

};


#endif
