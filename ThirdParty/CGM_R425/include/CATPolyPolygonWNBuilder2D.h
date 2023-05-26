// COPYRIGHT DASSAULT SYSTEMES 2014, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPolygonWNBuilder2D.h
//
//===================================================================
// February 2014 Creation: ndo
//===================================================================
#ifndef CATPolyPolygonWNBuilder2D_H
#define CATPolyPolygonWNBuilder2D_H

#include "PolygonalBoolean.h"
#include "CATPolyPolygonOverlayOptions2D.h"
#include "CATErrorDef.h"   // For the definition of HRESULT.
#include "CATBoolean.h"
#include "CATPolyDeprecatedM.h"

class CATPolyExactArithmetic;
class CATPolySpatialPartition2D;
class CATPolyIntersectionPointConstructor2D;
class CATPolyBarIntersector2D;
class CATPolyPolygon2D;
class CATPolyBooleanOperLayer2D;
class CATPolyPolygonBarSplitter2D;
class CATPolyPolygonSplitBarsObserver2D;

class CATPolyFace2D;
class CATPolyBar2D;
class CATPolyVertex2D;
class CATMathPoint2D;
class CATMathTransformation2D;


/**
 Operator that builds a CATPolyPolygon2D from a set of bars according to winding rules.
*/
class ExportedByPolygonalBoolean CATPolyPolygonWNBuilder2D
{

public:

  /**
   * Constructs a operator to build a CATPolyPolygon2D from bars according to winding number rules.
   * @param iExactArithmetic
   *   The instance of exact arithmetic.
   * @param ioPolygon
   *   The polygon that will be constructed by the operator.
   * @param iSpatialPartition
   *   An optional spatial partition to speed-up the computation for large data sets.
   * @param iObserver
   *   An optional observer to be notified when two bars of the polygon are split by their intersection.
   * @param iWNOptions
   *   Sets specific options.  See Options below.
   *   Use bitwise | operator to set the options.  
   *   For instance: eKeepVertices | eKeepBars.
   */
  CATPolyPolygonWNBuilder2D (const CATPolyExactArithmetic& iExactArithmetic, CATPolyPolygon2D& ioPolygon, const CATPolySpatialPartition2D* iSpatialPartition = 0,
                             CATPolyPolygonSplitBarsObserver2D* iObserver = 0, unsigned int iWNOptions = 0);

  /**
   * Constructs a operator to build a CATPolyPolygon2D from bars according to winding number rules.
   * @param iOptions
   *   The options for the computation of the overlay (arithmetic, tolerant,...).
   * @param ioPolygon
   *   The polygon that will be constructed by the operator.
   * @param iObserver
   *   An optional observer to be notified when two bars of the polygon are split by their intersection.
   * @param iWNOptions
   *   Sets specific options.  See Options below.
   *   Use bitwise | operator to set the options.
   *   For instance: eKeepVertices | eKeepBars.
   */
  CATPolyPolygonWNBuilder2D (const CATPolyPolygonOverlayOptions2D& iOptions, CATPolyPolygon2D& ioPolygon,
                             CATPolyPolygonSplitBarsObserver2D* iObserver = 0, unsigned int iWNOptions = 0);

  ~CATPolyPolygonWNBuilder2D ();

  /**
   * Sets the observer to be notified of events specific to intersecting bars.
   */
  POLY_DEPRECATED ("Do not use SetObserver ().  See constructor instead.", 
                   inline void SetObserver (CATPolyPolygonSplitBarsObserver2D* iObserver););

public:

  /**
   * Options.
   */
  enum Options
  {
    /** Bit 0 set for preventing suppression of vertices. */          eKeepVertices = 0x0001,
    /** Bit 1 set for preventing suppression of bars. */              eKeepBars     = 0x0002,
    /** Bit 2 set for closest-point construction (no new vertex). */  eClosestPoint = 0x0004,
    /** Bit 4: reserved. */                                           eReserved     = 0x0010
  };

public:

  /**
   * Adds a vertex to the polygon.
   */
  HRESULT AddVertex (const CATMathPoint2D& iPoint, CATPolyVertex2D* &oVertex, bool iFullVertex=false);

  /**
   * Adds a bar to the polygon.
   * Adding the bar (vA, vB) with multiplicity +1 is equivalent to adding the bar (vB, vA) with multiplicity -1.
   * Sets the multiplicity to 0 for wire bars.
   */
  HRESULT AddBar (CATPolyVertex2D* iVertex0, CATPolyVertex2D* iVertex1,
                  CATPolyBar2D*& oBar, const int iMultiplicity = 1);
  /**
   * Adds a new arc between two vertices passing (or not) through point.
   */
  HRESULT AddBar(CATPolyVertex2D* iVertex0, CATPolyVertex2D* iVertex1, CATMathPoint2D const& iPoint, bool iThroughPoint, CATPolyBar2D*& oBar, const int iMultiplicity = 1);

  /**
   * observer that allow for example to create a mapping between original operand and new vertex
   * */
  class ObserverAddOperand
  {
  public:
    virtual void AfterAddVertex(const CATPolyVertex2D& iOriginal, CATPolyVertex2D& iNew) {};
    virtual void AfterAddBar(const CATPolyBar2D& iOriginal, CATPolyBar2D& iNew) {};
  };

  /**
   * Adds a polygon to the operator.
   * The coordinates of the vertices from the polygon will be gridded as required for the computation with the exact arithmetic.
   * @param posMatrix
   *   An optional position matrix.
   */
  HRESULT AddOperand (const CATPolyPolygon2D& polygon, const CATMathTransformation2D* posMatrix = 0, ObserverAddOperand *ipObserver = 0);

public:

  /**
   * Interface defining custom winding rules to keep or eliminate faces of the polygon.
   */
  class ExportedByPolygonalBoolean WindingRule
  {
  public:
    /**
     * Returns <tt>TRUE</tt> for keeping a face according to the value of the winding number.
     */
    virtual CATBoolean Keep (CATPolyFace2D* iFace, const int iWindingNumber) {return Keep (iWindingNumber);}

    /**
     * Do not implement.  Instead implement method just above.
     */
    virtual CATBoolean Keep(const int iWindingNumber) { return TRUE; }
    
    virtual CATBoolean Keep(CATPolyBar2D const &iBar, CATPolyFace2D const& iLeftFace, int iWindingNumberLeft, CATPolyFace2D const& iRightFace, int iWindingNumberRight);
    
    virtual CATBoolean Keep(CATPolyVertex2D const& iVertex, CATPolyFace2D const& iFace) { return FALSE; }

    virtual bool IsCreateFullVertex() { return false; }
  };

  /**
   * Runs the operator with a custom winding number rule.
   */
  HRESULT Run (WindingRule& iRule);

private:

  CATPolyPolygonOverlayOptions2D _Options;
  CATPolyIntersectionPointConstructor2D* _PointConstructor;

  CATPolyPolygon2D& _Polygon;
  CATPolyBooleanOperLayer2D* _BooleanLayer;
  CATPolyPolygonBarSplitter2D* _Splitter;
  CATPolyPolygonSplitBarsObserver2D* _SplitBarsObserver;

  enum 
  {
    eOverlayKO,
    eOverlayToDo,
    eOverlayOK,
    eOverlayOKPropagationFailed
  };

  unsigned int _WNOptions;
  int _OverlayStatus;

private:
  HRESULT AddBar(CATPolyVertex2D* iVertex0, CATPolyVertex2D* iVertex1, CATPolyBar2D*& oBar, CATPolyBar2D const& iOldBar, const int iMultiplicity);

  void Initialize ();

  void Finalize ();

  HRESULT ProcessOverlay (WindingRule& iRule);

  // Set all faces as hole faces. 
  HRESULT ProcessFacesOnFailure ();

  // Replace facets that do not belong to the result by hole faces. 
  void ProcessFaces(WindingRule& iRule);

  // Remove bars that do not belong to the result.
  template<bool CreateFullVertex>
  HRESULT ProcessBars(WindingRule& iRule);

  // Remove vertices that do not belong to the result.
  void ProcessVertices(WindingRule& iRule);
};

inline void CATPolyPolygonWNBuilder2D::SetObserver (CATPolyPolygonSplitBarsObserver2D* iObserver)
{
  _SplitBarsObserver = iObserver;
}

#endif
