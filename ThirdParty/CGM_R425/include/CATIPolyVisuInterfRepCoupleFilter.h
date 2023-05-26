// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATIPolyVisuInterfRepCoupleFilter.h
//
//===================================================================
//
// Usage notes:
// Interface defining a filter used to avoid/allow visu couples
// to be treated by the interference process.
//
//===================================================================
//
// Aug 2009 Creation: JS9
//===================================================================

#ifndef CATIPolyVisuInterfRepCoupleFilter_h
#define CATIPolyVisuInterfRepCoupleFilter_h

#include "PolyVisuClash.h"

#include "CATIPolyInterfInputCoupleFilter.h"

// No longer visu dependant actually
class ExportedByPolyVisuClash CATIPolyVisuInterfRepCoupleFilter : public CATIPolyInterfInputCoupleFilter
{
public:

  virtual ~CATIPolyVisuInterfRepCoupleFilter() {}

protected:


  /**
   * Constructor
   */
  CATIPolyVisuInterfRepCoupleFilter() : CATIPolyInterfInputCoupleFilter() {}
};

#endif /* CATIPolyVisuInterfRepCoupleFilter_h */
