// COPYRIGHT DASSAULT SYSTEMES 2010, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPoly2DOrthogonalRouting.h
//
//===================================================================
//
// Usage notes: Graph tool to draw 2D routing of cables (connectors)
//              between boxes. This represents orthogonal connectors.
//
//===================================================================
//
// Nov 2010 Creation: JXO
// Jan 2011 Modification: JXO, rewritten
//===================================================================

#ifndef CATPoly2DOrthogonalRouting_h
#define CATPoly2DOrthogonalRouting_h

// Poly
#include "Poly2DRouting.h"
#include "CATPoly2DRoutingBaseImpl.h"
#include "CATMapOfIntToPtr.h"
#include "CATEventQueue.h"

// System
#include "CATBoolean.h"

// Math 
#include "CATMathBox2D.h"

class CATPoly2DOrthogonalRoutingGrid;
class CATPoly2DOrthogonalRoutingBox;
class CATPoly2DOrthogonalRoutingPort;
class CATMapOfPtrToPtr;

#define CURRENT_2D_ORTHO_ROUTING_VERSION 1

/**
 * Graph tool to draw 2D routing of cables (connectors)
 * between boxes. This represents orthogonal connectors.
 */
class ExportedByPoly2DRouting CATPoly2DOrthogonalRouting : public CATPoly2DRoutingBaseImpl
{
public:

  /**
   * Constructor.
   */
  CATPoly2DOrthogonalRouting(const CATMathBox2D & root, int version = CURRENT_2D_ORTHO_ROUTING_VERSION);
  /**
   * Destructor.
   */
  virtual ~CATPoly2DOrthogonalRouting();

  /**
   * Get geometry of a box from its id.
   * @return
   *      S_OK: OK
   *      E_INVALIDARG: if id is not a valid id.
   */
  HRESULT GetBox(unsigned int id, CATMathBox2D & obox);

  /**
   * CATPoly2DRouting implementations
   */
  virtual HRESULT AddBox(unsigned int id, const CATMathBox2D & box, CornerLimits limits = 0.1);
  virtual HRESULT RemoveBox(unsigned int id);
  virtual HRESULT MoveBox(unsigned int id, const CATMathBox2D & box);
  virtual HRESULT ChangeBoxCorners(unsigned int id, const CornerLimits & limits);
  virtual HRESULT ActivateBox(unsigned int id, CATBoolean activate = TRUE);
  virtual HRESULT ActivateAllBoxes(CATBoolean activate = TRUE);
  virtual CATBoolean IsBoxActivated(unsigned int id);

  virtual HRESULT AddPort(unsigned int id, int boxid,
                          BoxSide side = LeftBoxSide, 
                          PortBehavior behavior = CanMove,
                          double width = 0.0, double height = 0.0,
                          double point = 0.5);
  virtual HRESULT ModifyPortBehavior(unsigned int id, PortBehavior behavior = CanMove);
  virtual HRESULT ModifyPortPoint(unsigned int id, double point = 0.5);
  virtual HRESULT ModifyPortBoxSide(unsigned int id, BoxSide side = LeftBoxSide);
  virtual HRESULT GetPortLocation(unsigned int id, double &oPoint, BoxSide &oSide);
  virtual HRESULT GetPort(unsigned int id, CATPoly2DOrthogonalRoutingPort *& opPort);
  virtual HRESULT RemovePort(unsigned int id);


  virtual HRESULT AddConnector(unsigned int id, int portid1, int portid2);
  virtual HRESULT Compute(ConnectorComputeMode mode = WithEverythingElse);
  virtual HRESULT GetConnector(unsigned int id, CATPoly2DRoutingConnector *& opConnector);
  virtual HRESULT GetOneShotConnector(unsigned int id, CATPoly2DRoutingConnector *& opConnector, ConnectorComputeMode mode = WithBoxesAndDistance);
  virtual HRESULT RemoveConnector(unsigned int id);

  /**
   * Debug
   */
  void Dump(const char * filename, ConnectorComputeMode mode = WithEverythingElse);

  /**
   * Iterator on the boxes
   */
  class ExportedByPoly2DRouting BoxIterator
  {
  public:
    BoxIterator(const CATPoly2DOrthogonalRouting & rout);
    ~BoxIterator();
    const BoxIterator & Begin();
    CATBoolean End();
    const BoxIterator & operator ++();
    CATMathBox2D GetGeometry();
    CornerLimits GetCornerLimits();
    unsigned int GetId();
    CATBoolean IsActivated();
  private:
    CATMapOfIntToPtr::Iterator m_it;
  };
  /**
   * Iterator on the ports
   */
  class ExportedByPoly2DRouting PortIterator
  {
  public:
    PortIterator(const CATPoly2DOrthogonalRouting & rout);
    PortIterator(const CATPoly2DOrthogonalRoutingBox & box);
    ~PortIterator();
    const PortIterator & Begin();
    CATBoolean End();
    const PortIterator & operator ++();
    double GetWidth();
    double GetHeight();
    double GetPoint();
    unsigned int GetId();
    unsigned int GetBoxId();
    BoxSide GetBoxSide();
    PortBehavior GetBehavior();
    double GetComputedPoint();
  private:
    CATMapOfIntToPtr::Iterator m_it;
  };
  /**
   * Iterator on the ports of a box, to be deleted by caller
   */
  PortIterator * GetPorts(unsigned int boxid);
  /**
   * Iterator on the connectors
   */
  class ExportedByPoly2DRouting ConnectorIterator
  {
  public:
    ConnectorIterator(const CATPoly2DOrthogonalRouting & rout);
    ~ConnectorIterator();
    const ConnectorIterator & Begin();
    CATBoolean End();
    const ConnectorIterator & operator ++();
    unsigned int GetId();
    unsigned int GetStartPortId();
    unsigned int GetEndPortId();
  private:
    CATMapOfIntToPtr::Iterator m_it;
  };
  /**
   * Iterator on the grid, X
   */
  class ExportedByPoly2DRouting GridXIterator
  {
  public:
    GridXIterator(const CATPoly2DOrthogonalRouting & rout);
    ~GridXIterator();
    const GridXIterator & Begin();
    CATBoolean End();
    const GridXIterator & operator ++();
    double Get();
  private:
    CATPoly2DOrthogonalRoutingGrid * m_pGrid;
    CATEventQueue::Iterator m_it;
  };
  /**
   * Iterator on the grid, Y
   */
  class ExportedByPoly2DRouting GridYIterator
  {
  public:
    GridYIterator(const CATPoly2DOrthogonalRouting & rout);
    ~GridYIterator();
    const GridYIterator & Begin();
    CATBoolean End();
    const GridYIterator & operator ++();
    double Get();
  private:
    CATPoly2DOrthogonalRoutingGrid * m_pGrid;
    CATEventQueue::Iterator m_it;
  };
  /**
   * Get the tolerance
   */
  double GetTolerance() const;
  /**
   * Get the distance between connectors
   */
  double GetMinimalDistanceBetweenConnectors() const;
  /**
   * Get the option value indicating if connectors pathes have to be
   * grouped together or not
   */
  CATBoolean GetGroupedTogether() const;
  /**
   * Get the distance between connectors and boxes
   */
  double GetMinimalDistanceBetweenConnectorsAndBoxes() const;
  /**
   * Debug
   */
  double GetNodeValue(int i, int j, int valueid = 0) const;
  /**
   * Internal use only
   */
  HRESULT GetBox(int id, CATPoly2DOrthogonalRoutingBox * & pBox);

protected:
  void ResetAll();
  HRESULT UpdateRootBox(const CATMathBox2D & box);
  HRESULT ComputeGrid();
  HRESULT ResetGrid();
  HRESULT RouteFreePorts(CATMapOfPtrToPtr & ioFreePort2TopoSegment);
  HRESULT UpdateVirtualSegmentsIntervals(const CATMapOfPtrToPtr & iFreePort2TopoSegment);
  HRESULT UpdateFreePorts(const CATMapOfPtrToPtr & iFreePort2TopoSegment);
  void ReleaseFreePortsRoutes(CATMapOfPtrToPtr & ioFreePort2TopoSegment);

protected:
  CATMapOfIntToPtr m_boxes;
  CATMapOfIntToPtr m_connectors;
  CATMapOfIntToPtr m_ports;
  ConnectorComputeMode m_mode;
  CATBoolean m_built;
  CATPoly2DOrthogonalRoutingGrid * m_pGrid;

};

#endif /* CATPoly2DOrthogonalRouting_h */
