// COPYRIGHT DASSAULT SYSTEMES 2015, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyCompareParams.h
//
//===================================================================
//
// Usage notes: This class contains settings for Polybody/polymesh comparisons.
//
//===================================================================
//
// Feb 2015 Creation: D1A
//===================================================================
#ifndef CATPolyCompareParams_h
#define CATPolyCompareParams_h

#include "CATPolyMiscellaneous.h"
#include "CATErrorDef.h" // HRESULT definition on UNIX systems.
#include "CATBoolean.h"

class CATPolyBody;
class CATIPolyMesh;


class ExportedByCATPolyMiscellaneous CATPolyCompareParams
{

public:

  CATPolyCompareParams();

  //Sets the lower limit for ratio of no. of vertices/triangles in two input polymeshes.
  void SetRelativeCountTolerance(double iTol);

  //Sets the tolerance value used for ratio of distance between mass centres of polymeshes and length of bounding box of first mesh.
  void SetRelativeLengthTolerance(double iRelTol);

  //Sets the length : it is used as tolerance value for comparing position of vertices i.e. distance between vertices.
  void SetLengthTolerance(double iTol);

  double GetRelativeCountTolerance() {return _RelativeCountTolerance;}
  double GetRelativeLengthTolerance() {return _RelativeLengthTolerance;}
  double GetLengthTolerance() {return _LengthTolerance;}
  
private:
  double _RelativeCountTolerance;
  double _RelativeLengthTolerance;
  double _LengthTolerance;

};

#endif
