#ifndef CATPolyComparRaster_H
#define CATPolyComparRaster_H
//====================================================================
// Copyright Dassault Systemes Provence 2010-2011, All Rights Reserved 
//====================================================================


//
//#include "math.h"
#include "CATMathFP.h"
#include "ExportedByCATPolyComparOperators.h"
#include "CATTolerance.h"
static const double SmallVal = CATGetDefaultTolerance().SquareEpsilonForRelativeTest();// 1.e - 40;
static const double EpsilonRoundingTriangle = CATGetDefaultTolerance().GetResolution();

#include "CATMathInline.h"
class CATMathPoint2D;

class ExportedByCATPolyComparOperators CATPolyComparRaster
{
public:
 CATPolyComparRaster(double CornerMinX, double CornerMinY, double DeltaX, double DeltaY, int NbPixelX, int NbPixelY, double iEps = EpsilonRoundingTriangle);

 CATPolyComparRaster();//Pour faire des tableaux de Rasterizer
 ~CATPolyComparRaster();

 void Init(double CornerMinX, double CornerMinY, double DeltaX, double DeltaY, int NbPixelX, int NbPixelY, double iEps = EpsilonRoundingTriangle);
 //
 void GetRasterSpecs(double &oCornerMinX, double &oCornerMinY, double &oDeltaX, double &oDeltaY, int &oNbPixelX, int &oNbPixelY, double &oEps) const;
 
 //
 // return the number of impacted rows = FirstLastY[1] - FirstLastY[0] + 1 
 // FirstLastX is filled by 2 *(FirstLastY[1] - FirstLastY[0] + 1) ints : 
 //  First X for row FirstLastY[0], last X for FirstLastY[0],First X for row FirstLastY[0]+1, last X for FirstLastY[0]+1,etc...
 // if the returned value is positive, oFirstLastX contains, between  oFirstLastX[2*FirstLastY[0]] and  
 // oFirstLastX[2*FirstLastY[1]+1 ] the ;in and max pixel column (in [0, NbPixelX-1]) of the row. 
 //
 int GetPixelsImpactedByTriangle(const float Point1[2], const float Point2[2], const float Point3[2],
	 int FirstLastY[2], int *&oFirstLastX);
 int GetPixelsImpactedByTriangle(const CATMathPoint2D & P1, const CATMathPoint2D & P2, const CATMathPoint2D & P3, int FirstLastY[2], int *&oFirstLastX);

 //

 int GetPixelsImpactedBySegment(const float Point1[2], const float Point2[2], 
	 int FirstLastY[2], int *&oFirstLastX);

private:
	//
	int GetPixelsImpactedByOrderedTriangle(const double Point1[2], const double Point2[2], const double Point3[2],
		int FirstLastY[2], int *&oFirstLastX);
	//
	INLINE int FloorX(const double x, int &oDeltaFloorUpToEpsilon) const
	{
    oDeltaFloorUpToEpsilon = 0;
		if(x< _MinX-_Epsilon) return -1;
    double NumOfColumnAsDouble = _InvDeltaX * (x-_MinX);
		int val = CATFloor (NumOfColumnAsDouble);
    double Delta = NumOfColumnAsDouble - double(val);
		if(val >_NbPixelX) val = _NbPixelX;
    else 
    {
      if (( Delta <  _Epsilon)&& (val>0))
      {
        oDeltaFloorUpToEpsilon = -1;
      }
      else if((Delta > 1. -_Epsilon)&& (val <_NbPixelX))
      {
        oDeltaFloorUpToEpsilon = 1;
      }
    }
		return val;
	}

	INLINE int FloorY(const double y, int &oDeltaFloorUpToEpsilon) const
	{
    oDeltaFloorUpToEpsilon = 0;
		if(y< _MinY-_Epsilon) return -1;
    double NumOfRowAsDouble = _InvDeltaY * (y-_MinY);
    int val = CATFloor (NumOfRowAsDouble);
    double Delta = NumOfRowAsDouble - double(val);
		if(val >_NbPixelY) val = _NbPixelY;
    else 
    {
      if (( Delta <  _Epsilon)&& (val>0))
      {
        oDeltaFloorUpToEpsilon = -1;
      }
      else if((Delta > 1. -_Epsilon)&& (val <_NbPixelY))
      {
        oDeltaFloorUpToEpsilon = 1;
      }
    }
		return val;
	}

	//
	INLINE int FloorX(const double Point[2], int &oDeltaFloorUpToEpsilon) const
	{
		return FloorX(Point[0], oDeltaFloorUpToEpsilon);
	}

	INLINE int FloorY(const double Point[2], int &oDeltaFloorUpToEpsilon) const
	{
		return FloorY(Point[1], oDeltaFloorUpToEpsilon);
	}
	//
	INLINE void AddValue(const int iRow, const int Val)
	{
		if(iRow<0) return;
		if(iRow >= _NbPixelY) return;
		//
		if(_MinMaxValues[2*iRow] > Val) _MinMaxValues[2*iRow] = Val;
		if(_MinMaxValues[2*iRow+1] < Val) _MinMaxValues[2*iRow+1] = Val;
	}


	// fields
	double _MinX,_MinY;
	double _DeltaX,_DeltaY;
	double _InvDeltaX,_InvDeltaY;
	int _NbPixelX,_NbPixelY;
	int *_MinMaxValues;
  double _Epsilon;
	//

};

/////////////////////////////////////////////
  //

#endif



