// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyJoinDecimateBuilderObserver.h
//
//===================================================================
// October 2013  Creation: NDO
//===================================================================
#ifndef CATPolyBodyJoinDecimateBuilderObserver_H
#define CATPolyBodyJoinDecimateBuilderObserver_H

//#include "PolyBodyDecimate.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"

class CATPolyBody;
class CATIPolyBodyFrameLayers;
class CATPolyBodyBarGraph;
class CATMathTransformation;
class CATechExt;


/**
* Observer class of decimation events for CATPolyBodyJoinDecimateBuilder.
* For instance, an observer class can be defined to record all the decimation events and data
* for a replay of the operator later on (Phoenix).
*/
class CATPolyBodyJoinDecimateBuilderObserver
{

public:

  CATPolyBodyJoinDecimateBuilderObserver() {}
  virtual ~CATPolyBodyJoinDecimateBuilderObserver() {}

public:

  /** @name Observing setting events
  @{ */

  virtual void ReactToSetChordalDeviation(const double iChordalDeviation, const double iChordalDeviationEdge) {}

  virtual void ReactToDoFreezeBoundaryBars(CATBoolean iDoFreeze) {}

  virtual void ReactToDoInterpolateNormals(CATBoolean iUseNormalLayer) {}

  virtual void ReactToDoInterpolateTextureCoordinates(CATBoolean iUseTextureLayer) {}

  virtual void ReactToProcessTextureCoordinatesConstraints(const unsigned int iDim, const double iWeight[]) {}

  virtual void ReactToDoStitching(CATBoolean iDoStitching, double iStitchingTolerance) {}

  virtual void ReactToDoCreateBoundaryEdges(CATBoolean iDoCreateBoundaryEdges) {}

  virtual void ReactToDoStitchingInsideFaces(CATBoolean iDoStitching, double iStitchingTolerance) {}

  virtual void ReactToDoFlipBadlyOrientedFaces(CATBoolean iDoFlip) {}

  virtual void ReactToDoMergeFaces(CATBoolean iFlag, double iAngleForSmoothEdges) {}

  virtual void ReactToDoPostProcessSharpEdges(CATBoolean iDoPostProcessSharpEdges, double iAngleForSharpEdges) {}

  /** @} */

public:

  /** @name Observing input data
  @{ */

  virtual void ReactToAddPolyBody(const CATPolyBody& iPolyBody, const CATMathTransformation* iPositionMatrix) {}

  /** @} */

public:

  /** @name Observing decimation events
  @{ */

  /**
  * Method called after creation of a new bar graph.
  */
  virtual void ReactToNewBarGraph(CATPolyBodyBarGraph& iBodyGraph) {}

  /**
  * Method called before deletion of a bar graph.
  */
  virtual void PrepareToDeleteBarGraph(CATPolyBodyBarGraph& iBodyGraph) {}

  /**
  * Method called prior to stitching of the bar graph.
  */
  virtual void PrepareToStitch(const CATPolyBodyBarGraph& iBodyGraph) {}

  /**
  * Method called after stitching of the bar graph.
  */
  virtual void ReactToStitch(const CATPolyBodyBarGraph& iBodyGraph) {}

  /**
  * Method called prior to a decimation step.
  */
  virtual void PrepareToStep() {}

  /**
  * Method called after a decimation step.
  */
  virtual void ReactToStep() {}

  /**
  * Method called after finalization of the decimation.
  */
  virtual void ReactToBuildPolyBody(const CATPolyBody& oPolyBody) {}

  /** @} */

  virtual CATechExt * GetPhoenix() { return 0; }

};

#endif
