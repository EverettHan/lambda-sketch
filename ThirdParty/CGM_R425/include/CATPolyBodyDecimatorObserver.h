// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyDecimatorObserver.h
//
//===================================================================
// January 2012  Creation: NDO
//===================================================================
#ifndef CATPolyBodyDecimatorObserver_H
#define CATPolyBodyDecimatorObserver_H

#include "PolyBodyDecimate.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"

class CATPolyBody;
class CATIPolyBodyFrameLayers;
class CATPolyBodyBarGraph;
class CATMathTransformation;


/**
 * Observer class of decimation events for CATPolyBodyDecimator.
 * For instance, an observer class can be defined to record all the decimation events and data
 * for a replay of the operator later on (Phoenix).
 */
class ExportedByPolyBodyDecimate CATPolyBodyDecimatorObserver
{

public:

  CATPolyBodyDecimatorObserver () : _Next (0) {}
  virtual ~CATPolyBodyDecimatorObserver () {_Next = 0;}

public:

/** @name Observing setting events
    @{ */

  virtual void ReactToSetChordalDeviation (const double iChordalDeviation, const double iChordalDeviationEdge) {}

  virtual void ReactToDoFreezeBoundaryBars (CATBoolean iDoFreeze) {}

  virtual void ReactToDoInterpolateNormals (CATBoolean iUseNormalLayer) {}

  virtual void ReactToDoInterpolateTextureCoordinates (CATBoolean iUseTextureLayer) {}

  virtual void ReactToProcessTextureCoordinatesConstraints(const unsigned int iDim, const double iWeight[]) {}

  virtual void ReactToDoStitching (CATBoolean iDoStitching) {}

  virtual void ReactToDoCreateBoundaryEdges (CATBoolean iDoCreateBoundaryEdges) {}

/** @} */

public:

/** @name Observing decimation events
    @{ */

  /**
   * Method called after creation of a new bar graph.
   */
  virtual void ReactToNewBarGraph (CATPolyBodyBarGraph& iBodyGraph) {};

  /**
   * Method called before deletion of a bar graph.
   */
  virtual void PrepareToDeleteBarGraph (CATPolyBodyBarGraph& iBodyGraph) {};

  /**
   * Method called prior to initialization of the operator with the given CATPolyBody and layers.
   */
  virtual void PrepareToInitialize (const CATPolyBody& iPolyBody, const CATIPolyBodyFrameLayers* iFrameLayers, const CATMathTransformation* iMatrix) {};

  /**
   * Method called prior to stitching of the bar graph.
   * This call is made after the call to PrepareToInitialize () and before the call to ReactToInitialize ().
   */
  virtual void PrepareToStitch (const CATPolyBodyBarGraph& iBodyGraph) {};

  /**
   * Method called after stitching of the bar graph.
   * This call is made after the call to PrepareToInitialize () and before the call to ReactToInitialize ().
   */
  virtual void ReactToStitch (const CATPolyBodyBarGraph& iBodyGraph) {};

  /**
   * Method called after initialization of the operator.
   */
  virtual void ReactToInitialize (const CATPolyBodyBarGraph& iBodyGraph) {};

  /**
   * Method called prior to a decimation step.
   */
  virtual void PrepareToStep () {};

  /**
   * Method called after a decimation step.
   */
  virtual void ReactToStep () {};

  /**
   * Method called after finalization of the decimation.
   */
  virtual void ReactToFinalize (const CATPolyBody& oPolyBody, CATIPolyBodyFrameLayers* oFrameLayers) {};

/** @} */

public:

/** @name Reserved
    @{ */

  inline CATPolyBodyDecimatorObserver* Next () const {return _Next;}
  inline void SetNext (CATPolyBodyDecimatorObserver* next) {_Next = next;}

/** @} */

protected:

  CATPolyBodyDecimatorObserver* _Next;

};

#endif
