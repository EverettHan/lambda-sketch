// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPoly2DRoutingBaseImpl.h
//
//===================================================================
//
// Usage notes: Graph tool to draw 2D routing of cables (connectors)
//              between boxes.
//              Base Implementation
//
//===================================================================
//
// Jan 2011 Creation: JXO
//===================================================================

#ifndef CATPoly2DRoutingBaseImpl_h
#define CATPoly2DRoutingBaseImpl_h

// Poly
#include "CATPoly2DRouting.h"
#include "Poly2DRouting.h"

// System
#include "CATBoolean.h"
#include "CATDataType.h"
#include "CATSysErrorDef.h"

// Math
#include "CATMathBox2D.h"

class CATPoly2DRoutingConnector;
class CATCGMProgressBar;
class CATechExt;


/**
 * Graph tool to draw 2D routing of cables (connectors) between boxes.
 * Base Implementation.
 */

class ExportedByPoly2DRouting CATPoly2DRoutingBaseImpl : public CATPoly2DRouting
{
public:
  CATPoly2DRoutingBaseImpl(int version = -1);
  virtual ~CATPoly2DRoutingBaseImpl();

  /******************\
   * Box management *
  \******************/

  virtual HRESULT AddBox(unsigned int id, const CATMathBox2D & box, CornerLimits limits = 0.1);
  virtual HRESULT RemoveBox(unsigned int id);
  virtual HRESULT MoveBox(unsigned int id, const CATMathBox2D & box);
  virtual HRESULT ChangeBoxCorners(unsigned int id, const CornerLimits & limits);
  virtual HRESULT ActivateBox(unsigned int id, CATBoolean activate = TRUE);
  virtual HRESULT ActivateAllBoxes(CATBoolean activate = TRUE);
  virtual CATBoolean IsBoxActivated(unsigned int id);


  /************************\
   *   Ports management   *
  \************************/

  virtual HRESULT AddPort(unsigned int id, int boxid,
                          BoxSide side = LeftBoxSide, 
                          PortBehavior behavior = CanMove,
                          double width = 0.0, double height = 0.0,
                          double point = 0.5);
  virtual HRESULT ModifyPortBehavior(unsigned int id, PortBehavior behavior = CanMove);
  virtual HRESULT ModifyPortPoint(unsigned int id, double point = 0.5);
  virtual HRESULT ModifyPortBoxSide(unsigned int id, BoxSide side = LeftBoxSide);
  virtual HRESULT GetPortLocation(unsigned int id, double &oPoint, BoxSide &oSide);
  virtual HRESULT RemovePort(unsigned int id);

  /************************\
   * Connector management *
  \************************/

  virtual HRESULT AddConnector(unsigned int id, int portid1, int portid2);
  virtual HRESULT Compute(ConnectorComputeMode mode = WithEverythingElse);
  virtual HRESULT GetConnector(unsigned int id, CATPoly2DRoutingConnector *& opConnector);
  virtual HRESULT GetOneShotConnector(unsigned int id, CATPoly2DRoutingConnector *& opConnector, ConnectorComputeMode mode = WithBoxesAndDistance);
  virtual HRESULT RemoveConnector(unsigned int id);

  /************************\
   * Tolerance management *
  \************************/

  virtual void SetTolerance(double tolerance = 0.00001);
  virtual void SetMinimalDistanceBetweenConnectors(double distance = 0.1);
  virtual void GroupTogetherParallelConnections(CATBoolean groupTogether);
  virtual void SetMinimalDistanceBetweenConnectorsAndBoxes(double distance = 0.1);

  /***************************\
   * Progress bar management *
  \***************************/

  virtual void SetProgressBar(CATCGMProgressBar * piBar = 0);

  /**
   * Phoenix, for debug purposes
   */
  void SetPhoenixExtension(CATechExt *iExtension);
  /**
   * Recorder, for debug purposes
   * Record won't be deleted by callee.
   */
  void SetRecorder(CATPoly2DRouting *iRecord);
  /**
   * Get version
   */
  int GetVersion(){return m_Version;}

protected:
  CATCGMProgressBar * m_pBar;
  double m_tolerance;
  double m_connectorstoboxesdistance;
  double m_connectorstoconnectorsdistance;
  int m_Version;
  CATBoolean m_grouptogether;

  // Debug:
  CATechExt * m_Pegase;
  CATPoly2DRouting * m_Record;
};

#endif /* CATPoly2DRoutingBaseImpl_h */
