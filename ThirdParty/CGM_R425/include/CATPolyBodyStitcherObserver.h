// COPYRIGHT DASSAULT SYSTEMES 2016, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyStitcherObserver.h
//
//===================================================================
// June 2016  Creation: JXO, from CATPolyBodyJoinDecimateBuilderObserver
//===================================================================
#ifndef CATPolyBodyStitcherObserver_H
#define CATPolyBodyStitcherObserver_H

//#include "PolyBodyDecimate.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"

class CATPolyBody;
class CATIPolyBodyFrameLayers;
class CATPolyBodyBarGraph;
class CATMathTransformation;
class CATechExt;


/**
 * Observer class of decimation events for CATPolyBodyStitcher.
 * For instance, an observer class can be defined to record all the stitch events and data
 * for a replay of the operator later on (Phoenix).
 */
class CATPolyBodyStitcherObserver
{

public:

  CATPolyBodyStitcherObserver () {}
  virtual ~CATPolyBodyStitcherObserver () {}

public:

/** @name Observing setting events
    @{ */

  virtual void ReactToDoInterpolateTextureCoordinates (CATBoolean iUseTextureLayer) {}

  virtual void ReactToProcessTextureCoordinatesConstraints (const unsigned int iDim, const double iWeight[]) {}

  virtual void ReactToSetStitchingTolerance (double iStitchingTolerance) {}

  virtual void ReactToDoCreateBoundaryEdges (CATBoolean iDoCreateBoundaryEdges) {}

  virtual void ReactToDoFlipBadlyOrientedFaces (CATBoolean iDoFlip) {}

/** @} */

public:

/** @name Observing input data
    @{ */

  virtual void ReactToAddPolyBody (const CATPolyBody& iPolyBody, const CATMathTransformation* iPositionMatrix) {}

/** @} */

public:

/** @name Observing decimation events
    @{ */

  /**
   * Method called after creation of a new bar graph.
   */
  virtual void ReactToNewBarGraph (CATPolyBodyBarGraph& iBodyGraph) {}

  /**
   * Method called before deletion of a bar graph.
   */
  virtual void PrepareToDeleteBarGraph (CATPolyBodyBarGraph& iBodyGraph) {}

  /**
   * Method called prior to stitching of the bar graph.
   */
  virtual void PrepareToStitch (const CATPolyBodyBarGraph& iBodyGraph) {}

  /**
   * Method called after stitching of the bar graph.
   */
  virtual void ReactToStitch (const CATPolyBodyBarGraph& iBodyGraph) {}

  /**
   * Method called after finalization of the decimation.
   */
  virtual void ReactToBuildPolyBody (const CATPolyBody& oPolyBody) {}

  /**
   * Method called after finalization of the decimation.
   */
  virtual void ReactToFinalize (const CATPolyBody& oPolyBody) {}

/** @} */

  virtual CATechExt * GetPhoenix(){return 0;}

};

#endif
