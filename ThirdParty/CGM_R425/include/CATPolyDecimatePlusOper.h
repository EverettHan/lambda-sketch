// COPYRIGHT DASSAULT SYSTEMES 2004, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyDecimatePlusOper.h
// Header definition of CATPolyDecimatePlusOper
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Jul 2004 Creation: dhp
//===================================================================
#ifndef CATPolyDecimatePlusOper_h
#define CATPolyDecimatePlusOper_h

#include "CATPolyDecimateOperators.h"
#include "CATPolyModOper.h"
#include "CATPolyDecimateOper.h"

class CATIPolyMesh;


class ExportedByCATPolyDecimateOperators CATPolyDecimatePlusOper : public CATPolyModOper
{

public:

  CATPolyDecimatePlusOper (CATPolyBarCollapseOper * iBarCollapseOper = NULL);

  ~CATPolyDecimatePlusOper (void);

  /**
  * Sets the percentage of decimation.  The value represents the percentage number of vertices that will be 
  * eliminated during decimation.
  * The decimation mode should also be set to </tt DecimationModePercentage</tt>.
  * @param iPercentage
  *   Sets the percentage value (given between 0 and 100).  A value of 60 means that 60% of the vertices
  *   will be eliminated.
  */
  void SetPercentage (const double iPercentage);

  /**
  * Sets the target triangle count that must be reached after decimation.
  * The decimation mode should also be set to </tt DecimationModeTriangleCount</tt>.
  * @param iNbTriangles
  *   Sets the target number of triangles for the polymesh after decimation. 
  *   If the target number of triangles exceeds the total number of triangles of the polymesh, 
  *   no decimation occurs.
  */
  void SetTriangleCount (const int iNbTriangles);

  /**
  * Sets the chordal deviation.  When the chordal deviation mode is set, decimation of the polymesh stops when
  * further decimation results in chordal deviation exceeding this parameter.
  * The decimation mode should also be set to </tt DecimationModeChordalDeviation</tt>.
  * @param iChordalDeviation
  *   Sets the chordal deviation that should not be exceeded during decimation.
  */
  void SetChordalDeviation (const double iChordalDeviation);

  void SetMinimumBarLength (const double iMinimumBarLength);

  void SetMinimumAngle (const double iMinimumAngle);

  /**
  * Sets the freeze boundary flag.
  * <b>Role</b>: If the freeze boundary flag is on then boundary bars will not be
  * collapsed during decimation.
  * @param iFreezeBoundary
  *   Sets the freeze boundary flag.
  */
  void SetFreezeBoundary (const CATBoolean iFreezeBoundary);

  /**
  * Sets the stopping criterion. Four choices are available:
  *   <tt>PercentageVerticesStoppingCriterion</tt>: The polymesh is decimated until the target percentage of vertices 
  *      is achieved.
  *   <tt>TriangleCountStoppingCriterion</tt>: The polymesh is decimated until the target triangle count is achieved.
  *   <tt>ChordalDeviationStoppingCriterion</tt>: The polymesh is decimated until further decimation cannot be done
  *      without exceeding the chordal deviation.
  * @param iStoppingCriterion
  *   The stopping criterion.
  */
  void SetStoppingCriterion (const CATPolyDecimateOper::StoppingCriterion iStoppingCriterion);

  /**
  * Sets the chordal deviation tolerance for free bars.
  * @param iChordalDeviation
  *   The chordal deviation.
  */
  void SetChordalDeviationForFreeBars (const double iChordalDeviation);

  /**
  * Decimates the polymesh.
  * @param ioCldPolygon
  *   The polymesh to be decimated.
  * @return
  *   TRUE if the operator runs successfully and FALSE otherwise.
  */
  HRESULT Run (void);

  /**
  * Decimates the polymesh.  The operator operates on a selected set of triangles.
  * @param iTriangles
  *   The list of triangles on which to operate.
  * @return
  *   S_OK if the operator runs successfully and E_FAIL otherwise.
  */
  HRESULT RunOnSelectedTriangles (const CATListOfInt& iTriangles);

  /**
  * Decimates the polymesh.  The operator operates on a selected set of triangles.
  * @param iTriangles
  *   The list of triangles on which to operate.
  * @param oDecimatedTriangles
  *   The list of decimated triangles.
  * @return
  *   S_OK if the operator runs successfully and E_FAIL otherwise.
  */
  HRESULT RunOnSelectedTriangles (const CATListOfInt& iTriangles, CATListOfInt& oDecimatedTriangles);

private:

  CATPolyDecimateOper * _DecimateOper;

  double _MinimumBarLength;
  double _MinimumAngle;

};

#endif

