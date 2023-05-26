// COPYRIGHT DASSAULT SYSTEMES 2005, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyDecimateOper.h
// Header definition of CATPolyDecimateOper
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Sep 2001/Aug 2005 Creation: NDO
//===================================================================
#ifndef CATPolyDecimateOper_h
#define CATPolyDecimateOper_h

#include "CATPolyDecimateOperators.h"
#include "CATPolyModOper.h"
#include "CATSetOfInt.h"
#include "CATBoolean.h"

class CATIPolyMesh;
class CATPolyBarCollapseOper;
class CATPolyBarCollapseBase;


/*
*** Decimation operator ***
To decimate a polymesh, create an instance of this class, set the decimation parameters, set the mesh
and run the operator.  The decimation is performed in place.
For example, to decimate a mesh, msh, base on chordal deviation to a target triangle count of 10000, run the
operator as follows:
{
CATPolyDecimateOper decimateOper;

decimateOper.SetTriangleCount (10000);
decimateOper.SetDecimationType (CATPolyDecimateOper::ChordalDeviationDecimationType);
decimateOper.SetStoppingCriterion (CATPolyDecimateOper::TriangleCountStoppingCriterion);
decimateOper.SetMesh (msh);

HRESULT hr = decimateOper.Run ();
}
*/
class ExportedByCATPolyDecimateOperators CATPolyDecimateOper : public CATPolyModOper
{

public:

  enum DecimationType
  {
    ChordalDeviationDecimationType,
    BarLengthDecimationType
  };

  enum StoppingCriterion
  {
    PercentageVerticesStoppingCriterion,
    TriangleCountStoppingCriterion,
    ChordalDeviationStoppingCriterion,
    BarLengthStoppingCriterion
  };

  // Standard constructors and destructors
  // -------------------------------------
  CATPolyDecimateOper(CATPolyBarCollapseOper* barCollapseOper = NULL);
  CATPolyDecimateOper(CATIPolyMesh * iPolyMesh, CATPolyBarCollapseOper* barCollapseOper = NULL);

  virtual ~CATPolyDecimateOper();

  /**
  * Sets the percentage of decimation.  The value represents the percentage number of vertices that will be
  * eliminated during decimation.
  * The stopping criterion should also be set to <tt>PercentageVerticesStoppingCriterion</tt>.
  * @param iPercentage
  *   Sets the percentage value (given between 0 and 100).  A value of 60 means that 60% of the vertices
  *   will be eliminated.
  */
  void SetPercentage(const double iPercentage);

  /**
  * Sets the target triangle count to be reached after decimation.
  * The stopping criterion should also be set to <tt>TriangleCountStoppingCriterion</tt>.
  * @param iNbTriangles
  *   Sets the target number of triangles of the mesh after decimation.
  *   If the target number of triangles exceeds the total number of triangles of the polymesh,
  *   no decimation occurs.
  */
  void SetTriangleCount(const int iNbTriangles);

  /**
  * Sets the chordal deviation.  When the chordal deviation stopping criterion is set,
  * decimation of the polymesh stops when further decimation results in a chordal deviation
  * exceeding this parameter.
  * The stopping criterion should also be set to <tt>ChordalDeviationStoppingCriterion</tt>.
  * The decimation type should also be set to <tt>ChordalDeviationDecimationType</tt>.
  * @param iChordalDeviation
  *   Sets the chordal deviation that should not be exceeded during decimation.
  */
  void SetChordalDeviation(const double iChordalDeviation);

  /**
  * Sets the bar length.  The polymesh is decimated until the operator is no longer able
  * to suppress bars of length smaller than the requested bar length.  A model decimated
  * according to the bar length stopping criterion may still have bars smaller than the requested length.
  * The stopping criterion should also be set to <tt>BarLengthStoppingCriterion</tt>.
  * The decimation type should also be set to <tt>BarLengthDecimationType</tt>.
  * @param iBarLength
  *   The length below which all bars are tested for decimation.  A bar of length smaller than iBarLength
  *   is not guaranteed to be removed.
  */
  void SetBarLength(const double iBarLength);

  /**
  * Sets the maximum chordal deviation allowed on free bars.
  * This is a geometry test for free bars which is independent of the decimation type and stopping criterion.
  * @param iChordalDeviation
  *   Maximum chordal deviation allowed on free bars.
  */
  void SetChordalDeviationForFreeBars(const double iChordalDeviation);

  /**
  * Sets the decimation type. Two decimation types are available:
  *   <tt>ChordalDeviationDecimationType</tt>: The polymesh is decimated based on resulting chordal deviation.
  *   <tt>BarLengthDecimationType</tt>: The polymesh is decimated based on the length of triangle bars.
  * @param iDecimateType
  *   The decimation type.
  */
  void SetDecimationType(const DecimationType iDecimateType);

  /**
  * Sets the stopping criterion. Four choices are available:
  *   <tt>PercentageVerticesStoppingCriterion</tt>: The polymesh is decimated until the target percentage of vertices
  *      is achieved.
  *   <tt>TriangleCountStoppingCriterion</tt>: The polymesh is decimated until the target triangle count is achieved.
  *   <tt>ChordalDeviationStoppingCriterion</tt>: The polymesh is decimated until further decimation cannot be done
  *      without exceeding the chordal deviation.
  *   <tt>BarLengthStoppingCriterion</tt>: The polymesh is decimated until no bar of length smaller the value
  *      set can be collapsed.
  * @param iStoppingCriterion
  *   The stopping criterion.
  */
  void SetStoppingCriterion(const StoppingCriterion iStoppingCriterion);

  /**
  * Sets the freeze boundary flag.
  * <b>Role</b>: If the freeze boundary flag is on then boundary bars will not be
  * collapsed during decimation.
  * @param iFreezeBoundary
  *   Sets the freeze boundary flag.
  */
  void SetFreezeBoundary(const CATBoolean iFreezeBoundary);

  /**
  * Sets a group of vertices to be left untouched by the decimation.
  * They are treated exactly as boundary vertices when boundary is frozen.
  */
  void SetExcludedVertices(const CATSetOfInt* iExcludedVertices);

  /**
  * Decimates the polymesh.
  * @return
  *   S_OK if the operator runs successfully and E_FAIL otherwise.
  */
  HRESULT Run(void);

  /**
  * Decimates the polymesh.  The operator operates on a selected set of triangles.
  * @param iTriangles
  *   The list of triangles to decimate.
  * @return
  *   S_OK if the operator runs successfully and E_FAIL otherwise.
  */
  HRESULT RunOnSelectedTriangles(const CATListOfInt& iTriangles);

  /**
  * Decimates the polymesh.  The operator operates on a selected set of triangles.
  * @param iTriangles
  *   The list of triangles to decimate.
  * @param oDecimatedTriangles
  *   The list of decimated triangles.
  * @return
  *   S_OK if the operator runs successfully and E_FAIL otherwise.
  */
  HRESULT RunOnSelectedTriangles(const CATListOfInt& iTriangles, CATListOfInt& oDecimatedTriangles);

  /**
  * Decimates the polymesh.  The operator operates on a selected set of vertices.
  * @param iVertices
  *   The list of vertices to decimate.
  * @return
  *   S_OK if the operator runs successfully and E_FAIL otherwise.
  */
  HRESULT RunOnSelectedVertices(const CATListOfInt& iVertices);

private:

  CATPolyBarCollapseBase* ConstructCollapser() const;

  HRESULT RunPrivate(CATPolyBarCollapseBase* collapser);

  void GetDecimatedTriangles(const CATListOfInt& iTriangles, CATListOfInt& oDecimatedTriangles) const;

  DecimationType _DecimationType;
  StoppingCriterion _StoppingCriterion;

  double _Percentage;
  double _ChordalDeviation;
  double _BarLength;
  double _ChordalDeviationForFreeBars;

  int _InitialNumberOfTriangles;
  int _TargetNumberOfTriangles;

  CATBoolean _FreezeBoundary;

  CATPolyBarCollapseOper* _BarCollapseOper;

  const CATSetOfInt* _ExcludedVertices;
};

#endif
