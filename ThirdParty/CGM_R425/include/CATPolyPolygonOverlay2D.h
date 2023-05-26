// COPYRIGHT DASSAULT SYSTEMES 2006, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPolygonOverlay2D.h
//
//===================================================================
// September 2006 Creation: ndo
//===================================================================
#ifndef CATPolyPolygonOverlay2D_H
#define CATPolyPolygonOverlay2D_H

#include "PolygonalBoolean.h"
#include "CATPolyPolygonOverlayOptions2D.h"
#include "CATPolyBarIntersector2D.h"

#include "CATErrorDef.h"   // For the definition of HRESULT.
#include "CATMathPoint2D.h"

#include "CATEventQueue.h"
#include "CATBucketsOfPtr.h"
#include "CATListPV.h"

class CATPolyExactArithmetic;
class CATPolyPolygonCompareEventVertices;
class CATPolyPolygon2D;
class CATPolyFace2D;
class CATPolyVertex2D;
class CATPolyBar2D;
class CATPolyCoBar2D;
class CATPolyActiveBars2D;
class CATPolyPolygonOverlayObserver2D;
class CATPolyPolygonSplitBarsObserver2D;
class CATPolySpatialPartition2D;


/**
 Given a polygon representing an overlay, this operator constructs a valid CATPolyPolygon2D object
 where all intersections between bars, if any, are resolved.  Duplicate vertices and bars are removed.
 Degenerate bars are removed.  New loops and faces are defined.  The overlay has CCW orientation.
 Outer loops of the faces are oriented in the CCW direction.
*/
class ExportedByPolygonalBoolean CATPolyPolygonOverlay2D
{

public:

  /**
   * Constructs the "Polygon Overlay" operator given an instance of exact arithmetic and
   * two optional arguments.
   * @param iExactArithmetic
   *   The instance of exact arithmetic for the operator.
   * @param iSpatialPartition
   *   A spatial partition used as an accelerator to find all the intersecting bars.
   *   When there are many intersecting bars, it is recommended to use a spatial partition
   *   which improves the efficiency of the operator.  This is an optional argument.
   * @param iBarIntersector
   *   The optional bar intersector is called everytime an intersection between two bars is found
   *   It must return the computed intersections between two bars.  When this argument is set, 
   *   it overrides the default bar intersector of the operator.
   */
  CATPolyPolygonOverlay2D (const CATPolyExactArithmetic& iExactArithmetic,
                           const CATPolySpatialPartition2D* iSpatialPartition = 0,
                           CATPolyBarIntersector2D* iBarIntersector = 0);

  CATPolyPolygonOverlay2D (const CATPolyPolygonOverlayOptions2D& iOptions, bool iUseSplitter = true);

  ~CATPolyPolygonOverlay2D ();

  /**
   * Sets a flag to keep full vertices during the boolean operation.
   * The operator removes by default full or free vertices 
   * (vertices that are not adjacent to any bar).
   */
  inline void KeepFullVertices (bool iDoKeep);

  /**
   * Sets the observer for notification of bar splitting events.
   */
  inline void SetObserver (CATPolyPolygonSplitBarsObserver2D* iObserver);

  /**
   * Runs the operator on a CATPolyPolygon2D instance.
   * The CATPolyPolygon2D instance may contain vertices and bars that are not necessarily correctly joined
   * and that intersects.  The operator will find and process all intersections and removes
   * duplicate vertices and bars. It also constructs loops and faces.
   * After the run of the operator, the orientation of the polygon instance is CCW.
   * @param ioOverlay
   *   The input polygon that is updated by the operator.
   * @param ioOverlayObserver
   *   An optional observer for notitfication of specific CATPolyPolygon2D events.
   */
  HRESULT Run (CATPolyPolygon2D& ioOverlay, CATPolyPolygonOverlayObserver2D* ioOverlayObserver = 0);

  CATPolyPolygonOverlayOptions2D const& GetOptions() const;

private:

  typedef CATPolyCoBar2D EventVertex2D;  // Event vertex is the start vertex of a cobar.

  CATPolyPolygonOverlayOptions2D _Options;

  CATPolyPolygon2D* _Overlay;                             // The overlay that is calculated by this operator.
  CATPolyPolygonOverlayObserver2D* _OverlayObserver;      // An observer of events.
  CATPolyPolygonSplitBarsObserver2D* _SplitBarsObserver;  // An observer of split-bars event.

  // Working data.

  CATPolyPolygonCompareEventVertices* _CompareEventVertices;
  CATPolyActiveBars2D* _ActiveBars; // Set of active bars sorted according to the y-coordinate of their
                                    // intersections with the sweep line (vertical line).
  CATEventQueue _EventQueue;        // Event queue sorting the end vertices from left to right.

  CATBucketsOfPtr _PositionsBarLayer;  // Map the left and right cobars of a bar to their positions in the event queue.
                                       // Map also the bar to its position in the active bar set.

  CATPolyVertex2D* _ReferenceVertex;  // Reference vertex that is being processed.

  CATEventQueue::Iterator _CurrentEventPosition;  // The position of the current event vertex.
  EventVertex2D* _CurrentEventVertex;             // The current event vertex.

  CATEventQueue::Iterator _NextEventPosition;     // The position of the next event to process.
  EventVertex2D* _NextEventVertex;                // The next event vertex to process.

  bool _KeepFullVertices;
  bool _UseSplitter;
  CATPolyIntersection::Type _IntersectionType;  // Description of an intersection between two bars.
  CATPolyIntersection::Error _IntersectionError;  // Description of the intersection error if any.  
  CATMathPoint2D _IntersectionPoint;    // Constructed intersection point.

  CATListPV _VertexToBarBelow; // Map of the index of an overlay vertex to the bar immediatly below the vertex.

private:

  HRESULT ClearLinksFromOverlay ();
  void Clear ();

  void SetBarBelow (const CATPolyVertex2D& vertex, CATPolyBar2D* bar);
  CATPolyBar2D* GetBarBelow(const CATPolyVertex2D& vertex) const;

  HRESULT InitializeEventQueue ();
  void FinalizeEventQueue ();

  // Find and compute the intersections between segments of the overlay.
  HRESULT FindAndProcessIntersections ();

  // Link the bars of the overlay once all intersections are processed.
  HRESULT LinkBars(CATListPV& bars, CATPolyVertex2D& vertex, CATPolyBar2D* barBelow);
  HRESULT LinkBars();

  // Returns true if the bar and the vertex intersect and false otherwise.
  bool Intersect (CATPolyBar2D& bar, CATPolyVertex2D& vertex) const;

  // Returns true if Bar 0 and Bar 1 intersect and false otherwise.
  bool Intersect (CATPolyBar2D& bar0, CATPolyBar2D& bar1);

  EventVertex2D* FindEventForSafeGeometryRollBack (CATPolyBar2D& bar0, CATPolyBar2D& bar1) const;
  HRESULT RollBackEvent (EventVertex2D* eventVertex);
  HRESULT RollBackToRightEvent (CATPolyVertex2D* vertex, CATEventQueue::Iterator& eventPosition, EventVertex2D*& eventVertex);
  HRESULT RollBackToSafeEvent (CATPolyBar2D& bar0, CATPolyBar2D& bar1);
  HRESULT RollBackToSafeEventPointIntersection (CATPolyBar2D& bar0, CATPolyBar2D& bar1);
  HRESULT RollBackToSafeEventSegmentIntersection (CATPolyBar2D& bar0, CATPolyBar2D& bar1);

  HRESULT ProcessIntersection (CATPolyBar2D& bar0, CATPolyBar2D& bar1); 
  HRESULT ProcessPointIntersection (CATPolyBar2D& bar0, CATPolyBar2D& bar1);
  HRESULT ProcessSegmentIntersection (CATPolyBar2D& bar0, CATPolyBar2D& bar1);

  // Return true if the point is on the bar and false otherwise.
  bool IsOnBar (CATPolyBar2D& bar, const CATMathPoint2D& point) const;

  /**
   * Splits a bar by an existing vertex.  A new bar is created in this process.
   * @param bar
   *   The bar to split.
   * @param vertex
   *   The split vertex.
   */
  HRESULT SplitBar (CATPolyBar2D* bar, CATPolyVertex2D* vertex);

  /**
   * Splits two bars by a new constructed vertex.
   * @param bar0
   *   The first bar to split.
   * @param bar1
   *   The second bar to split.
   */
  HRESULT SplitBars (CATPolyBar2D* bar0, CATPolyBar2D* bar1);

  /**
   * Removes a bar.
   */
  HRESULT RemoveBar (CATPolyBar2D* bar);

  /**
   * Merges a bar with another one.  The duplicate bar is removed in this process.
   */
  HRESULT MergeBars (CATPolyBar2D* iMergeBar, CATPolyBar2D* iDuplicateBar);
};

inline void CATPolyPolygonOverlay2D::KeepFullVertices (bool iDoKeep)
{
  _KeepFullVertices = iDoKeep;
}

inline void CATPolyPolygonOverlay2D::SetObserver (CATPolyPolygonSplitBarsObserver2D* iObserver)
{
  _SplitBarsObserver = iObserver;
}

inline CATPolyPolygonOverlayOptions2D const& CATPolyPolygonOverlay2D::GetOptions() const
{
  return _Options;
}

#endif
