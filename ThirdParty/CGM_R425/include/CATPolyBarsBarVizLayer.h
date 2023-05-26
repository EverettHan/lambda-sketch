// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBarsBarVizLayer.h
// Header definition of CATPolyBarsBarVizLayer
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// January 2008 Creation: ndo
//===================================================================
#ifndef CATPolyBarsBarVizLayer_H
#define CATPolyBarsBarVizLayer_H

#include "PolyVizLayers.h"
#include "CATPolyBarsBarSupportLayer.h"
#include "CATErrorDef.h"     // HRESULT definition


class CATPolyVizContainer;
class CATPolyBars;


/*
Implementation class for bar support attributes. 
This class defines a layer of curve support attributes that are associated to each bar of a CATPolyBars object.
*/
class ExportedByPolyVizLayers CATPolyBarsBarVizLayer : public CATPolyBarsBarSupportLayer
{

public:

  CATPolyBarsBarVizLayer (const CATPolyBars& iBars, CATPolyVizContainer& iSupports);

  virtual ~CATPolyBarsBarVizLayer ();

public:

  inline CATPolyVizContainer& GetSupportContainer () const;

private:

  CATPolyVizContainer& _SupportContainer;

};


inline CATPolyVizContainer& CATPolyBarsBarVizLayer::GetSupportContainer () const
{
  return _SupportContainer;
}

#endif
