// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPoly2DRoutingConnector.h
//
//===================================================================
//
// Usage notes: Graph tool to draw 2D routing of cables (connectors)
//              between boxes.
//              Connector element.
//
//===================================================================
//
// Jan 2011 Creation: JXO
//===================================================================

#ifndef CATPoly2DRoutingConnector_h
#define CATPoly2DRoutingConnector_h

#include "Poly2DRouting.h"

// Poly
#include "CATPolyRefCounted.h"
#include "CATPoly2DRouting.h"

// System
#include "CATBoolean.h"
#include "CATDataType.h"

// Math
#include "CATMathPoint2D.h"

class CATPoly2DRoutingConnectorIntersections;


/**
 * Graph tool to draw 2D routing of cables (connectors) between boxes.
 * Connector element.
 */

class ExportedByPoly2DRouting CATPoly2DRoutingConnector : public CATPolyRefCounted
{
public:
  /**
   * Return connector's id.
   */
  virtual unsigned int GetId() = 0;
  /**
   * Return the id of the box the connector originates from.
   */
  virtual unsigned int GetStartPortId() = 0;
  /**
   * Return the id of the box the connector goes to.
   */
  virtual unsigned int GetEndPortId() = 0;
  /**
   * Return the number of points in the connector.
   * Connector has NbPoints - 1 segments.
   */
  virtual int GetNbPoints() = 0;
  /**
   * Return the i-th point.
   * Index begins at 0.
   */
  virtual CATMathPoint2D GetPoint(int index) = 0;
  /**
   * Return the number of segments in the connector.
   * Connector has NbPoints - 1 segments.
   */
  virtual int GetNbSegments() = 0;
  /**
   * Return the possible intersections of connector with other connectors.
   * @param index
   *        Index of first point of segment we are looking at. Intersections
   *        are sorted from first point to end point.
   * @return
   *        See @CATPoly2DRoutingConnectorIntersections. Should be released after use.
   */
  virtual CATPoly2DRoutingConnectorIntersections * GetIntersections(int index = -1) = 0;
  /**
   * Return the computation mode used for this connector.
   * See @CATPoly2DRouting.
   */
  virtual CATPoly2DRouting::ConnectorComputeMode GetComputeMode() = 0;

  /**
   * Debug topology, don't use
   */
  class TopologyIteratorImpl;

  /**
   * Debug topology
   */

  class TopologyIterator
  {
  public:
    TopologyIterator(CATPoly2DRoutingConnector & con):m_impl(con.GetIterator()){}
    virtual ~TopologyIterator(){}
    virtual void Begin(){return m_impl.Begin();}
    virtual CATBoolean End(){return m_impl.End();}
    virtual void operator++(){return ++m_impl;}
    virtual int Geti(){return m_impl.Geti();}
    virtual int Getj(){return m_impl.Getj();}
    virtual CATMathPoint2D GetPoint(){return m_impl.GetPoint();}
    virtual CATMathPoint2D GetPointLeft(){return m_impl.GetPointLeft();}
    virtual CATMathPoint2D GetPointRight(){return m_impl.GetPointRight();}
    virtual int GetZoneLeft(){return m_impl.GetZoneLeft();}
    virtual int GetZoneRight(){return m_impl.GetZoneRight();}
  private:
    TopologyIteratorImpl & m_impl;
  };

protected:
  /**
   * Constructor
   */
  CATPoly2DRoutingConnector(){}
  /**
   * Destructor
   */
  virtual ~CATPoly2DRoutingConnector(){}

  /**
   * Get Iterator
   */
  virtual TopologyIteratorImpl & GetIterator() = 0;

  /**
   * Debug topology
   */

public:

  class TopologyIteratorImpl
  {
  public:
    virtual void Begin(){}
    virtual CATBoolean End(){return TRUE;}
    virtual void operator++(){}
    virtual int Geti(){return -1;}
    virtual int Getj(){return -1;}
    virtual CATMathPoint2D GetPoint(){return CATMathPoint2D();}
    virtual CATMathPoint2D GetPointLeft(){return CATMathPoint2D();}
    virtual CATMathPoint2D GetPointRight(){return CATMathPoint2D();}
    virtual int GetZoneLeft(){return -1;}
    virtual int GetZoneRight(){return -1;}
    TopologyIteratorImpl(CATPoly2DRoutingConnector & con){}
    virtual ~TopologyIteratorImpl(){}
  };


};

#endif /* CATPoly2DRoutingConnector_h */
