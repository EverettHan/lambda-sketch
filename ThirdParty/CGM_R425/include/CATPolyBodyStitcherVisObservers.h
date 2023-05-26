// COPYRIGHT DASSAULT SYSTEMES 2016, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyStitcherVisObservers.h
//
//===================================================================
// September 2016 Creation: JXO, from CATPolyBodyJoinDecimateBuilderVisObservers
//===================================================================
#ifndef CATPolyBodyStitcherVisObservers_H
#define CATPolyBodyStitcherVisObservers_H
#include "CATPolyVisuBuildOper.h"
#include "CATErrorDef.h" // HRESULT.
#include "CATBoolean.h"

#include "CATPolyBodyStitcher.h"

class CATPolyBodyVisLayer;
class CATMapOfIntToGraphicAttributeSet;
class CATPolyCell;

/**
 * Observer setting the graphic attributes into a CATPolyBodyVisLayer.
 */
class ExportedByPolyVisuBuildOper CATPolyBodyStitcherVisOutputObserver : public CATPolyBodyStitcher::OutputCellObserver
{

public:

  inline CATPolyBodyStitcherVisOutputObserver (const CATMapOfIntToGraphicAttributeSet& iMapTagToGA, CATPolyBodyVisLayer& iVisLayer);

  ~CATPolyBodyStitcherVisOutputObserver () {}

public:

  // Virtual method from base class.
  void AssociateTagAndPolyCell (const unsigned int iTag, CATPolyCell* iOutputCell);

private:

  const CATMapOfIntToGraphicAttributeSet& _MapTagToGA;
  CATPolyBodyVisLayer& _VisLayer;

};

inline CATPolyBodyStitcherVisOutputObserver::CATPolyBodyStitcherVisOutputObserver (const CATMapOfIntToGraphicAttributeSet& iMapTagToGA,
                                                                                                         CATPolyBodyVisLayer& iVisLayer) :
  _MapTagToGA (iMapTagToGA),
  _VisLayer (iVisLayer)
{
}

#endif
