// COPYRIGHT DASSAULT SYSTEMES 2014, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyJoinDecimateBuilderVisObservers.h
//
//===================================================================
// January 2014 Creation: ndo
//===================================================================
#ifndef CATPolyBodyJoinDecimateBuilderVisObservers_H
#define CATPolyBodyJoinDecimateBuilderVisObservers_H

#include "CATPolyVisuBuildOper.h"
#include "CATErrorDef.h" // HRESULT.
#include "CATBoolean.h"

#include "CATPolyBodyJoinDecimateBuilder.h"
#include "CATMapOfPtrToInt.h"

class CATPolyBodyVisLayer;
class CATMapOfIntToGraphicAttributeSet;
class CATPolyCell;


/**
 * Observer for catching graphic attributes from a CATPolyBodyVisLayer and storing them into a map.
 */
class ExportedByPolyVisuBuildOper CATPolyBodyJoinDecimateBuilderVisInputObserver : public CATPolyBodyJoinDecimateBuilder::InputCellObserver
{

public:

  inline CATPolyBodyJoinDecimateBuilderVisInputObserver (const CATPolyBodyVisLayer& iVisLayer, CATMapOfIntToGraphicAttributeSet& iMapTagToGA);

  ~CATPolyBodyJoinDecimateBuilderVisInputObserver () {}

public:

  // Virtual method from base class.
  void AssociatePolyCellAndTag (CATPolyCell* iInputCell, const unsigned int iTag);

private:

  const CATPolyBodyVisLayer& _VisLayer;
  CATMapOfIntToGraphicAttributeSet& _MapTagToGA;

};


/**
 * Observer setting the graphic attributes into a CATPolyBodyVisLayer.
 */
class ExportedByPolyVisuBuildOper CATPolyBodyJoinDecimateBuilderVisOutputObserver : public CATPolyBodyJoinDecimateBuilder::OutputCellObserver
{

public:

  inline CATPolyBodyJoinDecimateBuilderVisOutputObserver (const CATMapOfIntToGraphicAttributeSet& iMapTagToGA, CATPolyBodyVisLayer& iVisLayer);

  ~CATPolyBodyJoinDecimateBuilderVisOutputObserver () {}

public:

  // Virtual method from base class.
  void AssociateTagAndPolyCell (const unsigned int iTag, CATPolyCell* iOutputCell);

private:

  const CATMapOfIntToGraphicAttributeSet& _MapTagToGA;
  CATPolyBodyVisLayer& _VisLayer;
public:
  CATMapOfPtrToInt m_MapOfCellsToTags;
};


inline CATPolyBodyJoinDecimateBuilderVisInputObserver::CATPolyBodyJoinDecimateBuilderVisInputObserver (const CATPolyBodyVisLayer& iVisLayer, 
                                                                                                       CATMapOfIntToGraphicAttributeSet& iMapTagToGA) :
  _VisLayer (iVisLayer),
  _MapTagToGA (iMapTagToGA)
{
}

inline CATPolyBodyJoinDecimateBuilderVisOutputObserver::CATPolyBodyJoinDecimateBuilderVisOutputObserver (const CATMapOfIntToGraphicAttributeSet& iMapTagToGA,
                                                                                                         CATPolyBodyVisLayer& iVisLayer) :
  _MapTagToGA (iMapTagToGA),
  _VisLayer (iVisLayer)
{
}

#endif
