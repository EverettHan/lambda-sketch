// COPYRIGHT DASSAULT SYSTEMES 2003, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyFuzzyOffset.h
// Header definition of Bridge to use CATPolyFuzzyOffset
//
//  Ne contient que la fonction qui permet a partir d'un CATCldPolygon
//  de faire un offset polyedrique.
//===================================================================
/**
* @required Protected
* @usage U0
**/
//===================================================================
//
//  Sept 2003  Creation: LVL
//===================================================================
#ifndef CATPolyFuzzyOffsetBasicBridge_H
#define CATPolyFuzzyOffsetBasicBridge_H

#include "CATRegularisator.h"
// math

class CATCldPolygon;
class CATGeoFactory;
class CATMathPoint;
class CATPolyFuzzyOffsetBasicBridge;
/**
* This class is used to manage the Polyedral fuzzy offset.<br>
**/

typedef CATPolyFuzzyOffsetBasicBridge* (*CATPolyFuzzyOffsetBasicCreator)
          (CATCldPolygon * iPolygon, CATGeoFactory * iFactory);

class ExportedByCATRegularisator CATPolyFuzzyOffsetBasicBridge
{
	
public:

  static CATPolyFuzzyOffsetBasicBridge * Create(CATCldPolygon * iPolygon, CATGeoFactory * iFactory);
	
	//==============================================================================
	// destructor 
	//==============================================================================
	/**
	* Standard destructor.<br>
	**/
  virtual ~CATPolyFuzzyOffsetBasicBridge () {};

  
  virtual int SetActiveBoundingBox(CATMathPoint &iMinPoint, CATMathPoint &iMaxPoint) = 0;

  virtual int SetPolyInit(CATCldPolygon * iNewPolyInit) = 0;

  virtual int SetOffsetSize(double iOffsetSize) = 0;

  virtual int SetVoxelSize(double iVoxelSize) = 0;


  virtual int Run(int iMode = 0) = 0;

  virtual CATCldPolygon * GetResult() const = 0;
	
  double _offsetSize;

  double _voxelSize;

  CATCldPolygon * _polyInit;

  CATCldPolygon * _polyResult;

  CATGeoFactory * _factory;

  CATMathPoint * _minPoint;

  CATMathPoint * _maxPoint;

};


#endif
