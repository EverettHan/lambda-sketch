// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPoly2DRouting.h
//
//===================================================================
//
// Usage notes: Graph tool to draw 2D routing of cables (connectors)
//              between boxes.
//
//===================================================================
//
// Jan 2011 Creation: JXO
//===================================================================

#ifndef CATPoly2DRouting_h
#define CATPoly2DRouting_h

#include "Poly2DRouting.h"

// System
#include "CATBoolean.h"
#include "CATDataType.h"
#include "CATSysErrorDef.h"

// Math
#include "CATMathBox2D.h"

class CATPoly2DRoutingConnector;
class CATCGMProgressBar;


/**
 * Graph tool to draw 2D routing of cables (connectors) between boxes.
 */

class ExportedByPoly2DRouting CATPoly2DRouting
{
public:
  /******************\
   * Box management *
  \******************/

  /**
   * Corners limits. Ports cannot be closer to the corners of the boxes than these minimal distances.
   */
  struct CornerLimits
  {
    CornerLimits(const double & limit)
    {bottomleft = upleft = bottomright = upright = leftup = rightup = leftbottom = rightbottom = limit;}
    CornerLimits()
    {bottomleft = upleft = bottomright = upright = leftup = rightup = leftbottom = rightbottom = 0.;}
    inline CATBoolean operator ==(const CornerLimits &);
    inline CATBoolean operator !=(const CornerLimits &);
    double bottomleft, upleft, bottomright, upright, leftup, rightup, leftbottom, rightbottom;
  };

  /**
   * Add a box. If box is not totally inside root box, root box is inflated accordingly.
   * (Internaly reset all previously computed connectors.)
   * @param id
   *    id of the box. Used in all the other methods.
   *    0 is a reserved id for the root box.
   * @param box
   *    Geometry of the box to be added. Can intersect other boxes.
   * @param limits
   *    Corner limits of the box.
   * @return
   *    S_OK: everything went fine.
   *    E_INVALIDARG: id is already in use.
   */
  virtual HRESULT AddBox(unsigned int id, const CATMathBox2D & box, CornerLimits limits = 0.1) = 0;
  /**
   * Remove a box.
   * (Internaly reset all previously computed connectors.)
   * @param id
   *    id of the box to be removed.
   * @return
   *    S_OK: everything went fine.
   *    E_INVALIDARG: id is 0 or invalid.
   */
  virtual HRESULT RemoveBox(unsigned int id) = 0;
  /**
   * Move a box or change geometry of a box.
   * (Internaly reset all previously computed connectors.)
   * @param id
   *    id of the box to be moved.
   *    You can use 0 to change the root box.
   * @param box
   *    New geometry of the box. Can intersect other boxes.
   * @return
   *    S_OK: everything went fine.
   *    E_INVALIDARG: id is invalid.
   */
  virtual HRESULT MoveBox(unsigned int id, const CATMathBox2D & box) = 0;
  /**
   * Change the corner limits of a box.
   * @param id
   *    id of the box to be changed.
   *    You can use 0 to change the root box.
   * @param limits
   *    New corner limits of the box.
   * @return
   *    S_OK: everything went fine.
   *    E_INVALIDARG: id is invalid.
   */
  virtual HRESULT ChangeBoxCorners(unsigned int id, const CornerLimits & limits) = 0;
  /**
   * Activate or deactivate a box. A deactivated box won't participate in any further computation.
   * Default: boxes are created activated.
   * @param id
   *    id of the box.
   * @param activate
   *    TRUE:  box is activated.
   *    FALSE: box is deactivated.
   * @return
   *    S_OK: everything went fine.
   *    E_INVALIDARG: id is 0 or invalid.
   */
  virtual HRESULT ActivateBox(unsigned int id, CATBoolean activate = TRUE) = 0;
  /**
   * Activate or deactivate all the boxes.
   * Default: boxes are created activated.
   * @param activate
   *    TRUE:  all boxes are activated.
   *    FALSE: all boxes are deactivated.
   * @return
   *    S_OK: everything went fine.
   */
  virtual HRESULT ActivateAllBoxes(CATBoolean activate = TRUE) = 0;
  /**
   * Return wether one particular box is activated or not.
   * @param id
   *    id of the box.
   * @return
   *    TRUE:  box is activated.
   *    FALSE: box is not activated or box does not exist.
   */
  virtual CATBoolean IsBoxActivated(unsigned int id) = 0;


  /************************\
   *   Ports management   *
  \************************/

  /**
   * Box behavior: side of the box a Port lies on.
   * Note: AnyBoxSide value overloads the port side behavior. If a
   * port is set to AnyBoxSide, its side behavior is ignored and
   * always considered as CanMoveAllAlongSide.
   */
  enum BoxSide
  {
    LeftBoxSide = 0,
    RightBoxSide,
    UpBoxSide,
    BottomBoxSide,
    AnyBoxSide
  };

  /**
   * Side behavior: Behavior of Port on the side.
   *    Fixed: port cannot move at all, default is fixed to the middle of side.
   *           That means several connectors can originate from the exact same geometric point (but different port)
   *    CanMove: port can move, but remains as close as possible to the fixed point (default, middle of side).
   *    CanMoveAllAlongSide: port can move all along the side for a better optimized length of the connector.
   * Note: if a port has the AnyBoxSide box behavior, its side
   * behavior is ignored and considered as CanMoveAllAlongSide.
   * Note concerning multiple connections: if a port is supposed to be
   * attached to many connector, its behaviour must be 'Fixed' (in
   * particular, its box side cannot be 'AnyBoxSide'). If it is not,
   * the attachment of a second connector is refused.
   */
  enum PortBehavior
  {
    Fixed = 0,
    CanMove,
    CanMoveAllAlongSide
  };

  /**
   * Add a port.
   * @param id
   *    id of the port. Used in all the other methods.
   * @param boxid
   *    id of the box the port lies on.
   *    Reserved ids:
   *         0: Root box.
   * @param side
   *    Side of the first box the port lies on.
   * @param behavior
   *    Behavior of port.
   * @param point
   *    Position of point on the box's side. 0.0 is first end of the side and 1.0 is the other.
   *    Counter clockwise rotation around the box.
   * @return
   *    S_OK: everything went fine.
   *    E_INVALIDARG: id is already in use or boxid is invalid.
   */
  virtual HRESULT AddPort(unsigned int id, int boxid,
                          BoxSide side = LeftBoxSide, 
                          PortBehavior behavior = CanMove,
                          double width = 0.0, double height = 0.0,
                          double point = 0.5) = 0;

  /**
   * Modify the behavior of a port.
   * (Internaly reset all previously computed connectors.)
   * @param id
   *    id of the port.
   * @param behavior
   *    Behavior of port.
   * @return
   *    S_OK: everything went fine.
   *    E_INVALIDARG: id is invalid or the port has already multiple
   *    connectors attached to it but the new behaviour is different
   *    from PortBehavior::Fixed.
   */
  virtual HRESULT ModifyPortBehavior(unsigned int id, PortBehavior behavior = CanMove) = 0;

  /**
   * Modify the geometry of the port.
   * (Internaly reset all previously computed connectors.)
   * @param id
   *    id of the port.
   * @param point
   *    Position of point on the box's side. 0.0 is first end of the side and 1.0 is the other.
   *    Counter clockwise rotation around the box.
   * @return
   *    S_OK: everything went fine.
   *    E_INVALIDARG: id is invalid, point is negative, or point is greater that 1.0.
   */
  virtual HRESULT ModifyPortPoint(unsigned int id, double point = 0.5) = 0;

  /**
   * Modify the box side behaviour, deciding on which side of the box
   * the port is attached to. (Internaly reset all previously
   * computed connectors.)
   * @param id
   *    id of the port.
   * @param side
   *    Side of box the port is attached to. Note that AnyBoxSide
   *    discard the port behaviour for the CanMoveAllAlongSide
   *    behaviour.
   * @return
   *    S_OK: everything went fine.
   *    E_INVALIDARG: id is invalid.
   */
  virtual HRESULT ModifyPortBoxSide(unsigned int id, BoxSide side = LeftBoxSide) = 0;

  virtual HRESULT GetPortLocation(unsigned int id, double &oPoint, BoxSide &oSide) = 0;

  /**
   * Remove a port.
   * (Internaly reset all previously computed connectors.)
   * @param id
   *    id of the port to be removed.
   * @return
   *    S_OK: everything went fine.
   *    E_INVALIDARG: id is 0 or invalid.
   */
  virtual HRESULT RemovePort(unsigned int id) = 0;


  /************************\
   * Connector management *
  \************************/

  /**
   * Add a connector.
   * (Internaly reset all previously computed connectors.)
   * @param id
   *    id of the connector. Used in all the other methods.
   * @param portid1
   *    id of the port the connector originates from.
   * @param portid2
   *    id of the port the connector goes to.
   * @return
   *    S_OK: everything went fine.
   *    E_INVALIDARG: id is already in use or portid1 or portid2 are
   *    invalid or one of the two ports already has a connector
   *    attached to it but has a behaviour different to
   *    PortBehavior::Fixed.
   */
  virtual HRESULT AddConnector(unsigned int id, int portid1, int portid2) = 0;

  /**
   * Remove a Connector.
   * (Internaly reset all previously computed connectors.)
   * @param id
   *    id of the connector to be removed.
   * @return
   *    S_OK: everything went fine.
   *    E_INVALIDARG: id is 0 or invalid.
   */
  virtual HRESULT RemoveConnector(unsigned int id) = 0;

  /**
   * Computation modes for connector resolution.
   *    Alone:              Fastest way. Nothing is taken into account but the start box and the end box.
   *                        Equivalent to deactivating all the boxes and using WithBoxesOnly.
   *                        Connector is not put into the list of computed connectors for 'WithEveryThingElse' mode.
   *    WithBoxesOnly:      Only boxes are taken into account for computation. Connector will avoid collisions
   *                        with boxes but not with other connectors.
   *                        Connector is not put into the list of computed connectors for 'WithEveryThingElse' mode.
   *    WithBoxesAndDistance: Only boxes are taken into account for computation. Connector will NOT avoid collisions
   *                          with other connectors, but will try to position itself at the minimum distance from
   *                          other connectors.
   *                          Connector is not put into the list of computed connectors for 'WithEveryThingElse' mode.
   *    WithEverythingElse: Connector avoids collisions with boxes and also tries to avoid collisions with other connectors.
   *                        Minimal distance between connectors should be respected.
   *                        If collision cannot be avoided, it falls back to 'WithBoxesAndDistance' mode.
   *                        First GetConnector is costly because collision detection is overally computed. 
   *                        Order of addition of connectors to the operator will have a heavy influence on the result.
   *                        Default mode.
   */
  enum ConnectorComputeMode
  {
    Alone = 0,
    WithBoxesOnly,
    WithBoxesAndDistance,
    WithEverythingElse
  };
  /**
   * Compute the connector.
   * All connectors are reset after calls to:
   *         - AddBox, RemoveBox, MoveBox, RemovePort, AddConnector, RemoveConnector
   *         - ModifyPortBehavior, ModifyPortPoint,
   *         - SetTolerance, SetMinimalDistanceBetweenConnectors, SetMinimalDistanceBetweenConnectorsAndBoxes.
   * Note that the order of the calls to AddConnector will have a heavy influence on the result.
   * It uses the progress bar (see below.)
   * @param mode
   *    Computation mode. See @ConnectorComputeMode.
   * @return
   *    S_OK: Everything went fine.
   *    Everything else: something bad happened.
   */ 
  virtual HRESULT Compute(ConnectorComputeMode mode = WithEverythingElse) = 0;
  /**
   * Return the computed connector for id 'id'.
   * If not already computed, computation takes place at first call (see above.)
   * @param id
   *    id of the connector.
   * @param opConnector
   *    Returned connector. Has to be released after use.
   * @return
   *    S_OK: Everything went fine and connector meets its contract.
   *    S_FALSE: Connector is returned but there may be collisions.
   *    E_INVALIDARG: id is not valid.
   */
  virtual HRESULT GetConnector(unsigned int id, CATPoly2DRoutingConnector *& opConnector) = 0;
  /**
   * Return the computed connector for id 'id', without using previously computed connectors.
   * @param id
   *    id of the connector.
   * @param opConnector
   *    Returned connector. Has to be released after use.
   * @param mode
   *    Computation mode. See @ConnectorComputeMode. WithEverythingElse is an invalid mode.
   * @return
   *    S_OK: Everything went fine and connector meets its contract.
   *    S_FALSE: Connector is returned but there may be collisions.
   *    E_INVALIDARG: id is not valid.
   */
  virtual HRESULT GetOneShotConnector(unsigned int id, CATPoly2DRoutingConnector *& opConnector, ConnectorComputeMode mode = WithBoxesAndDistance) = 0;


  /**************************************\
   * Tolerance and distances management *
  \**************************************/

  /**
   * Set the tolerance. Should be set before any other operation.
   * @param tolerance
   *    Points, connector segments and boxes edges are considered equal if distant than less than this tolerance.
   */
  virtual void SetTolerance(double tolerance = 0.00001) = 0;
  /**
   * Set the minimal distance between connectors. Should be set before any other operation.
   * @param distance
   *    Algorithm tries its best to keep the connectors separated by this distance.
   */
  virtual void SetMinimalDistanceBetweenConnectors(double distance = 0.1) = 0;
  /**
   * Try to group together all the parallel connections that can be
   * placed at the same time (the minimal distance between connectors
   * thus became the maximal distance between the grouped connections)
   */
  virtual void GroupTogetherParallelConnections(CATBoolean groupTogether) = 0;
  /**
   * Set the minimal distance between connectors and boxes. Should be set before any other operation.
   * @param distance
   *    Algorithm tries its best to keep the connectors separated from the boxes by this distance.
   */
  virtual void SetMinimalDistanceBetweenConnectorsAndBoxes(double distance = 0.1) = 0;


  /***************************\
   * Progress bar management *
  \***************************/

  /**
   * Set the progress bar.
   * @param piBar
   *    See @CATCGMProgressBar.
   */
  virtual void SetProgressBar(CATCGMProgressBar * piBar = 0) = 0;


protected:
  /**
   * Constructor
   */
  CATPoly2DRouting(){}
  /**
   * Destructor
   */
  virtual ~CATPoly2DRouting(){}
};


inline CATBoolean CATPoly2DRouting::CornerLimits:: operator ==(const CornerLimits & limits)
{
  if(bottomleft != limits.bottomleft)
    return FALSE;
  if(upleft != limits.upleft)
    return FALSE;
  if(bottomright != limits.bottomright)
    return FALSE;
  if(upright != limits.upright)
    return FALSE;
  if(leftup != limits.leftup)
    return FALSE;
  if(rightup != limits.rightup)
    return FALSE;
  if(leftbottom != limits.leftbottom)
    return FALSE;
  if(rightbottom != limits.rightbottom)
    return FALSE;
  return TRUE;
}
inline CATBoolean CATPoly2DRouting::CornerLimits:: operator !=(const CornerLimits & limits)
{
  return !(*this==limits);
}

#endif /* CATPoly2DRouting_h */
