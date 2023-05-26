// COPYRIGHT DASSAULT SYSTEMES 2016, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyDecimatorEdgeQuery.h
//
//===================================================================
// July 2016  Creation NDO
//===================================================================
#ifndef CATPolyBodyDecimatorEdgeQuery_H
#define CATPolyBodyDecimatorEdgeQuery_H

#include "PolyBodyDecimate.h"
#include "CATBoolean.h"

class CATPolyEdge;


/**
  * Interface to make queries about the edges of a CATPolyBody during decimation.
  */
class ExportedByPolyBodyDecimate CATPolyBodyDecimatorEdgeQuery
{

public:

  /**
    * Makes a query about the removal of an edge.
    * @param iEdge
    *   The input CATPolyEdge.
    * @return
    * <ul>
    *   <li> <tt>TRUE</tt> for an edge to remove.
    *   <li> <tt>FALSE</tt> for an edge to keep.
    * </ul>
    */
  virtual CATBoolean RemoveQuery (CATPolyEdge* iEdge) = 0;

};

#endif
