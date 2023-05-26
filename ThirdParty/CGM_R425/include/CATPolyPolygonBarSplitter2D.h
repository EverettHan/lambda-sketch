// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPolygonBarSplitter2D.h
//
//===================================================================
// April 2008 Creation: ndo
//===================================================================
#ifndef CATPolyPolygonBarSplitter2D_H
#define CATPolyPolygonBarSplitter2D_H

#include "PolygonalBoolean.h"

#include "CATErrorDef.h"   // For the definition of HRESULT.
#include "CATBoolean.h"
#include "CATSetOfInt.h"
#include "CATPolyPolygon2D.h"
#include "CATPolyPolygonOverlayOptions2D.h"

class CATPolyOverlayPoint2DIterator;
class CATPolyExactArithmetic;
class CATPolyBarIntersector2D;
class CATPolyPolygonSplitBarsObserver2D;
class CATPolySpatialPartition2D;
class CATPolyBarIntersector2D;
class CATPolyBar2D;
class CATMathPoint2D;
class CATPolyVertex2D;
class CATPolyOverlay2D;
class PixelArrayAndOverlayUpdater;
class CATPolyOverlayBarIntersector2D;
class CATSetOfPtr;
class CATPolyOverlayReclassifier2D;
class CATPolyOverlayPixelGrid2D;
class CATPolyOverlayPixelGrid2DBarIterator;
class CATPolyOverlayListOfVerticesOnBars;
class PolygonVertexEventListManager;
class CATEventQueue;

/**
 * Given a polygon, this operator splits all the bars that are intersecting.
 * It also merges vertices and bars having matching definitions.
 *
 * The operator can be run automatically by directly calling the Run () method
 * (with no need to call the SetPolygon () and the Split () methods.)
 *
 * It can also be run in two steps:
 *   * A first step to find all the intersection between the bars from a polygon by calling
 *     the method SetPolygon ().  An iterator is available to iterate through all the
 *     intersection after this first step.
 *   * A second step to split all the intersecting bars by calling the method Split ().
 * (no need to call the Run () method.)
 */
class ExportedByPolygonalBoolean CATPolyPolygonBarSplitter2D
{

public:

  /**
   * Observer of visited pixels by insertion of the polygon into
   * the spatial partition. (See SetPolygon ().)
   */
  class Observer
  {
  public:

    Observer () {}
    virtual ~Observer () {}

  public:

    /**
     * Call made when a bar is inserted or removed from the pixel array with all the visited pixels.
     */
    virtual void PixelVisited (const CATPolyBar2D& B, unsigned int iPixels[], unsigned int iNbPixels) = 0;

    virtual void PixelVisited (const CATPolyVertex2D& V, unsigned int iPixels[], unsigned int iNbPixels) = 0;

  };

public:

  /**
   * Iterator through all the bars contained within a pixel.
   */
  class BarIterator
  {
  public:

    BarIterator (const CATPolyPolygonBarSplitter2D& splitter, unsigned int pixel);
    ~BarIterator ();

  public:

    BarIterator& Begin ();
    bool End () const;
    BarIterator& operator++ ();

    CATPolyBar2D* operator* ();

  private:

    CATPolyOverlayPixelGrid2DBarIterator& _It;

  };

public:

  /**
   * Iterator through all the intersections found after a SetPolygon ().
   * Prior to using this iterator, first call SetPolygon () to find all
   * the intersections (contacts) between bars and vertices.
   * Then, it iterates through the all intersections.
   */
  class ExportedByPolygonalBoolean IntersectionIterator
  {
  public:

    IntersectionIterator (const CATPolyPolygonBarSplitter2D& splitter);
    ~IntersectionIterator () ;

  public:

    IntersectionIterator& Begin ();
    CATBoolean End ();
    IntersectionIterator& operator++ ();

    /**
     * Given an index (0 or 1), returns the element (vertex or bar) referred to by the contact.
     * @param index
     *   The index of the element: 0 or 1.
     */
    void GetElement (unsigned int index, CATPolyVertex2D*& V, CATPolyBar2D*& B) const;

    /**
     * Returns the constructed position of an intersection or null
     * if the intersection has not been constructed.
     * Do not delete the pointer returned.
     */
    const CATMathPoint2D* GetPoint () const;

  private:

    CATPolyOverlayPoint2DIterator* _PointIt;

  };

public:

  /**
   * Constructor.
   */
  CATPolyPolygonBarSplitter2D (const CATPolyPolygonOverlayOptions2D & iOptions);

  ~CATPolyPolygonBarSplitter2D ();

public:

  /**
   * Sets a polygon (with vertices and bars, no loops and faces) into the splitter.
   * This method finds all the intersections between the bars of the polygon but does not splits
   * the bars.
   */
  HRESULT SetPolygon (CATPolyPolygon2D& ioPolygon, CATPolyPolygonSplitBarsObserver2D* iSplitBarsObs, Observer* iPixelObs = 0);

  /**
   * Splits all the bars with the intersecting points.
   * After this step, no intersection remains in the polygon.
   */
  HRESULT Split ();

  /**
   * Performs the setting of a CATPolyPolygon2D object into the splitter
   * and splits the intersecting bars.
   * @param ioPolygon
   *   The input polygon containing the bars to split.
   * @param iObserver
   *   An optional observer for notification of the bars being split.
   *   May be null.
   */
  HRESULT Run (CATPolyPolygon2D& ioPolygon, CATPolyPolygonSplitBarsObserver2D* iSplitBarsObs = NULL);

public:

  /**
   * Given a point, finds the vertex of matching position if any.
   */
  HRESULT FindMatchingVertex (const CATMathPoint2D& P, CATPolyVertex2D*& oVertex) const;

  /**
   * Only merge vertices and bars, do not compute intersections.
   */
  HRESULT RunMerge();

private:

  CATPolyPolygonOverlayOptions2D _Options;

  bool _ToDelete;
  CATPolyBarIntersector2D * _BarIntersector;
  CATPolyOverlayBarIntersector2D * _DefaultBarIntersector;

  CATPolyOverlay2D* _Overlay;
  CATPolyOverlayPixelGrid2D* _OverlayGrid;

  friend class PixelArrayAndOverlayUpdater;
  PixelArrayAndOverlayUpdater* _Updater;
  CATPolyPolygonSplitBarsObserver2D* _SplitObserver;  // Optional split-bars observer.
  Observer* _PixelObserver;  // Optional pixel observer.

  CATSetOfInt _VisitedBars;  // Working set of visited bars.

private:

  /** Builds the initial overlay by inserting all the polygon bars
      inside the grid and initial contacts in the overlay. */
  HRESULT BuildOverlay ();

  /** Remove faces, loops, merges duplicated vertices and bars from
      the polygon */
  HRESULT PreprocessPolygon ();

  /** Inserts all the vertices inside the grid with vertex/vertex
      contacts for the second phase of the split. */
  HRESULT InsertVertices ();

  HRESULT AddBarBarContactVertex_V0 (CATSetOfPtr & iPoints, CATPolyOverlayListOfVerticesOnBars & ioVerticesOnBars);
  HRESULT ProcessSplitBarForBarBarContacts_V0 (CATPolyOverlayListOfVerticesOnBars & oVerticesOnBars, CATSetOfPtr & oNewBars);
  HRESULT ProcessBarBarContacts_V0 ();
  HRESULT ProcessVertexVertexContacts_V0 (CATSetOfPtr & oBarsToUpdate);
  HRESULT ProcessVertexBarContacts_V0 (CATSetOfPtr & oBarsToUpdate);
  HRESULT ProcessRemainingContactsIteratively_V0 ();

  /** Add the bars split or moved in the different phases inside the
      grid. */
  HRESULT AddNewBars_V1 (CATSetOfPtr & ioNewBars);
  HRESULT ProcessSplitBarForBarBarContacts_V1 (CATPolyOverlayListOfVerticesOnBars & oVerticesOnBars, CATSetOfPtr & oPotentialUnusedVertices);
  HRESULT ProcessRemainingContactsIteratively_V1 (CATSetOfPtr & ioNewBars);
  HRESULT ProcessBarBarContacts_V1 (CATSetOfPtr & ioNewBars);
  HRESULT ProcessVertexVertexContacts_V1 (CATSetOfPtr & oBarsToUpdate, PolygonVertexEventListManager & ioEventLinks);
  HRESULT ProcessVertexBarContacts_V1 (CATSetOfPtr & oBarsToUpdate);

  HRESULT AddBarBarContactVertex_V2 (CATEventQueue & iPoints, CATPolyOverlayListOfVerticesOnBars & ioVerticesOnBars);
  HRESULT ProcessBarBarContacts_V2 (CATSetOfPtr & ioNewBars);

private:

  /**
   * Adds a full vertex to the grid of pixels (and the overlay.)
   */
  HRESULT AddFullVertex (CATPolyVertex2D* V);

  /**
   * Removes a full vertex from the grid of pixels (and the overlay.)
   */
  HRESULT RemoveFullVertex (CATPolyVertex2D* V);

  /**
   * Adds a vertex to the grid of pixels (and the overlay.)
   */
  HRESULT AddVertex (CATPolyVertex2D* V);

  /**
   * Removes a vertex from the grid of pixels (and the overlay.)
   */
  HRESULT RemoveVertex (CATPolyVertex2D* V);

  /**
   * Adds a bar to the grid of pixels (and the overlay.)
   */
  HRESULT AddBar (CATPolyBar2D* B);

  /**
   * Removes a bar from the grid of pixels (and the overlay.)
   */
  HRESULT RemoveBar (CATPolyBar2D* B);

};

#endif
