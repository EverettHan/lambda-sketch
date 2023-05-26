// COPYRIGHT DASSAULT SYSTEMES 2004-2010, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPolygon2D.h
//
//===================================================================
// August 2004 Creation: ndo
//===================================================================
#ifndef CATPolyPolygon2D_H
#define CATPolyPolygon2D_H

#include "PolygonalModel.h"
#include "CATRefCounted.h"
#include "CATErrorDef.h"     // HRESULT definition (for compil under UNIX)
#include "CATListOfInt.h"
#include "CATListPV.h"
#include "CATBoolean.h"
#include "CATPolyDeprecatedM.h"

class CATPolyVertex2D;
class CATPolyCoBar2D;
class CATPolyBar2D;
class CATPolyArc2D;
class CATPolyLoop2D;
class CATPolyFace2D;
class CATPolyPolygonObserver2D;
class CATMathPoint2D;
class CATCGMOutput;
class CATPolyVertexBuckets2D;
class CATPolyBarBuckets2D;
class CATPolyLoopBuckets2D;
class CATPolyFaceBuckets2D;
class CATPolyAllocator2D;
template<class> class CATPolyProcessOverlay;

/**
 This class represents a cellular partition of the plane.  The cells of the partition (faces) are polygons
 that may contain one or more boundaries (loops).  The boundaries consist of vertices connected by bars.

 The CATPolyPolygon2D object defines a set of connected planar graphs to which geometry and attributes can 
 be associated.

 The following properties apply to a CATPolyPolygon2D object:
 <ul>
   <li> All faces have at least one loop defining the outer boundary of the face.
   <li> Faces may have zero or more inner loops (inner boundaries of the face).
   <li> A loop may be empty.
   <li> A loop may be composed of a single vertex.  Such a vertex is a full vertex.
 </ul>

 A valid CATPolyPolygon2D object satisfies Euler-Poincare's formula given in this context by:
   V + 2F - L - B = 1
 where
 <ul>
   <li> V: Number of vertices
   <li> F: Number of faces
   <li> L: Number of loops
   <li> B: Number of bars
 </ul>

 (A valid instance has an empty loop that defines the outer loop of an infinite face and hence when this 
  loop is counted, there is an offset of one compared to the standard formula.)

 A valid CATPolyPolygon2D object has at least one face (an infinite face).  
 This face has an empty outer loop (a loop with no vertex and no bar).  
 A valid empty CATPolyPolygon2D object has no vertex (V=0), one face (F=1), one loop (L=1) and no bar (B=0);
 and therefore satisfies Euler's formula.

 Note that not all CATPolyPolygon2D object are valid. An object with no vertex, no face, no loop
 and no bar as constructed by the default constructor is not valid.  Invalid states of the data
 structure enable fast edits.  It is the responsibility of the operators to construct valid 
 CATPolyPolygon2D objects.  

 The following member methods can be classified in several groups;
 <ol>
    <li> Query methods to find characteristics of the instance.
    <li> Methods to set or get the vertex geometry (a 2D position is embedded in each vertex.)
    <li> Methods that add, remove or modify the relationships among the entities (vertex, bar, loop and face) 
         of the instance with no respect of the Euler's formula.  When editing in this manner, intermediate states
         may be invalid CATPolyPolygon2D objects.  (Euler's formula will not necessarily be satisfied.)
    <li> Euler methods that add, remove and modify the relationships among the entities of the instance
         while keeping the intermediate states all valid.  (Euler methods are just topological operators.)
  </ol>

  @see CATPolyPolygonObserver2D
  @see CATPolyPolygonTools2D
  @see CATPolyPolygonIO2D
*/
class ExportedByPolygonalModel CATPolyPolygon2D
//class ExportedByPolygonalModel CATPolyPolygon2D : public CATRefCounted
{

public :

  /**
   * Creates an instance of a CATPolyPolygon2D.
   * CATPolyPolygon2D objects should be released.
   */
  inline static CATPolyPolygon2D* New ();

  /**
   * Releases an instance of a CATPolyPolygon2D.
   */
  inline void Release ();

public:

/** @name Vertex Services
    @{ */

  /**
   * Returns the number of vertices in the polygon.
   */
  inline int GetNbVertices () const ;

  /**
   * Adds a new vertex to the polygon.
   * @param oVertex
   *   The vertex that has been added.
   * @return
   *   S_OK if the vertex is added successfully; E_FAIL otherwise.
   */
  HRESULT AddVertex (CATPolyVertex2D*& oVertex) ;

  /**
   * Removes (and deletes) a vertex from the polygon.
   * @return
   *   S_OK if the vertex is removed; E_FAIL otherwise.
   */
  void RemoveVertex(CATPolyVertex2D& iVertex);
  HRESULT RemoveVertex (CATPolyVertex2D* iVertex) ;

  /**
   * Sets the coordinates of a vertex.
   * @param iVertex
   *   The vertex.
   * @param iPoint
   *   The position of the vertex.
   * @return
   *   S_OK upon success; E_FAIL otherwise.
   */
  HRESULT SetVertexPosition (CATPolyVertex2D* iVertex, const CATMathPoint2D& iPoint) ;

  /**
   * Returns the coordinates of a vertex.
   * @param iVertex
   *   The vertex.
   * @return
   *   The position of the vertex.
   */
  const CATMathPoint2D& GetVertexPosition (const CATPolyVertex2D* iVertex) const;

  /**
   * Returns the largest index of the vertices.  
   * This is the largest value a call to CATPolyPolygonTools2D::GetVertexIndex () may return.
   */
  int GetMaxVertexIndex () const ;

/** @} */

public:

/** @name Bar Services
    @{ */

  /**
   * Returns the number of bars in the polygon.
   */
  inline int GetNbBars () const ;

  /**
   * Returns the number of arcs in the polygon.
   */
  inline int GetNbArcs() const;
  
  /**
   * Returns the number of bars and full vertices in the polygon.
   */
  inline int GetNbBarsAndFullVertices() const;

  /**
   * Adds a new bar between two vertices.
   */
  HRESULT AddBar (CATPolyVertex2D* iVertex0, CATPolyVertex2D* iVertex1, CATPolyBar2D*& oBar);

  /**
   * Adds a new arc between two vertices passing (or not) through point.
   */
  HRESULT AddBar(CATPolyVertex2D* iVertex0, CATPolyVertex2D* iVertex1, CATMathPoint2D const& iPoint, bool iThroughPoint, CATPolyBar2D*& oBar);

  /**
   * Removes (and deletes) a bar from the polygon.
   */
  HRESULT RemoveBar(CATPolyBar2D* iBar);
  void RemoveBar (CATPolyBar2D& iBar) ;

  /**
   * Returns the largest index of the bars.  
   * This is the largest value a call to CATPolyPolygonTools2D::GetBarIndex () may return.
   */
  int GetMaxBarIndex () const;

/** @} */

public:

/** @name Full Vertex Services
    @{ */

  /**
   * Returns the number of full vertices in the polygon.
   */
  inline int GetNbFullVertices () const;

  /**
   * Adds a full vertex.
   * If a vertex is a full vertex, then it cannot belong to any bar.
   * (A full vertex is associated to a unique full vertex bar that defines it.)
   */
  HRESULT AddFullVertex (CATPolyVertex2D* iVertex);

  /**
   * Removes a full vertex.
   * The full vertex is removed but not the vertex.  Use RemoveVertex to remove it completely.
   * @return
   *   S_OK if the full vertex is removed; E_FAIL otherwise.
   */
  HRESULT RemoveFullVertex (CATPolyVertex2D* iVertex);

  /**
   * Checks if a vertex is full.
   */
  CATBoolean IsFullVertex (const CATPolyVertex2D* iVertex) const;

/** @} */

public:

/** @name Loop Services
    @{ */

  /** 
   * Returns the number or loops in the polygon.
   */
  inline int GetNbLoops () const ;

  /**
   * Adds a new loop to the polygon.
   * @param vertex
   *   The start vertex of the initial bar of the loop.
   * @param bar
   *   An initial bar of the loop.
   * @param oLoop
   *   The loop that has been added.
   * @return
   *   S_OK if the loop is added successfully; E_FAIL otherwise.
   */
  HRESULT AddLoop (CATPolyVertex2D* vertex, CATPolyBar2D* bar, CATPolyLoop2D*& oLoop);

  /**
   * Adds a new loop to the polygon in the case of a full vertex.
   * @param vertex
   *   The full vertex to which the loop is associated.
   * @param bar
   *   An initial bar of the loop.
   * @param oLoop
   *   The loop that has been added.
   * @return
   *   S_OK if the loop is added successfully; E_FAIL otherwise.
   */
  HRESULT AddLoop (CATPolyVertex2D* vertex, CATPolyLoop2D*& oLoop) ;

  /**
   * Adds a new empty loop to the polygon.
   * @param oLoop
   *   The loop that has been added.
   * @return
   *   S_OK if the loop is added successfully; E_FAIL otherwise.
   */
  HRESULT AddLoop (CATPolyLoop2D*& oLoop) ;

  /**
   * Grows a loop at a vertex by addition of a bar where "vertex" is the start vertex of the bar.
   * @param iLoop
   *   The loop to grow.
   * @param barFrom
   *   The bar where the loop is grown from.
   * @param vertex
   *   The vertex where the barFrom is linked to barTo.
   * @param barTo
   *   The bar that grows the loop.
   */
  HRESULT GrowLoop (CATPolyLoop2D* iLoop, CATPolyBar2D* barFrom, CATPolyVertex2D* vertex, CATPolyBar2D* barTo) ;

  /**
   * Removes (and deletes) a loop from the polygon.
   * @param iLoop
   *   The loop to remove.
   * @return
   *   S_OK if the loop is removed successfully; E_FAIL otherwise.
   */
  void RemoveLoop(CATPolyLoop2D& iLoop);
  HRESULT RemoveLoop (CATPolyLoop2D* iLoop) ;

/** @} */

public:

/** @name Face Services
    @{ */

  /**
   * Returns the total number of faces in the polygon.
   */
  inline int GetNbFaces () const ;

  /**
   * Returns the number of faces in the polygon.
   * @param iSkipHoleFaces
   *   A flag set to <code>TRUE</code> to ignore the hole faces.
   */
  int GetNbFaces (const CATBoolean iSkipHoleFaces) const ;

  /**
   * Adds a new face to the polygon.
   * @param iLoop
   *   The outer loop of the face.
   * @param oFace
   *   The output face that is created.
   * @return
   *   S_OK if the face is added successfully; E_FAIL otherwise.
   */
  HRESULT AddFace (CATPolyLoop2D* iLoop, CATPolyFace2D*& oFace) ;

  /**
   * Removes (and deletes) a face from the polygon.
   * @param iFace
   *   The face to be deleted.
   * @return
   *   S_OK if the face is removed; E_FAIL otherwise.
   */
  void RemoveFace(CATPolyFace2D& iFace);
  HRESULT RemoveFace (CATPolyFace2D* iFace);

  /**
   * Adds a loop to a face.  This method does not create a loop.
   * @param iFace
   *   The face to which the loop must be added.
   * @param iLoop
   *   The loop that is added.  It must not belong to any face.
   * @return
   *   S_OK if the loop is added successfully; E_FAIL otherwise.
   */
  HRESULT FaceAddLoop (CATPolyFace2D* iFace, CATPolyLoop2D* iLoop);

  /**
   * Removes a loop from a face.  This method does not delete the loop.
   * @param iFace
   *   The face from which the loop must be removed.
   * @param iLoop
   *   The loop that is removed.  The loop must belong to the face.
   * @return
   *   S_OK if the loop is added successfully; E_FAIL otherwise.
   */
  HRESULT FaceRemoveLoop (CATPolyFace2D* iFace, CATPolyLoop2D* iLoop);

  /**
   * Gets the number of loops for a given face.
   * @param iFace
   *   The face.
   * @return
   *   The number of loops the face has.  A face has at least one loop: the outer loop.
   */
  int GetNbLoops (const CATPolyFace2D* iFace) const ;

  /**
   * Returns the largest index of the faces.  
   * This is the largest value a call to CATPolyPolygonTools2D::GetFaceIndex () may return.
   */
  int GetMaxFaceIndex () const ;

/** @} */

public:

/** @name Hole Face Services
    Hole faces are identified by a flag.
    @{ */

  /**
   * Defines or undefines a face as a hole face.
   * @param iFace
   *   The face to be set.
   * @param iIsHoleFace
   *   An input boolean set to <code>TRUE</code> for a hole face and <code>FALSE</code> otherwise.
   */
  void SetHoleFace (CATPolyFace2D* iFace, const CATBoolean iIsHoleFace);

  /**
   * Returns <code>TRUE</code> if the face is a hole face and <code>FALSE</code> otherwise.
   */
  CATBoolean IsHoleFace (const CATPolyFace2D* iFace) const;

/** @} */

public:

  /**
   * Enumerator that specifies the orientation of the CATPolyPolygon2D object.
   * Orientation is counter-clockwise (CCW) when outer loops have counter-clockwise orientation and 
   * inner loops, clockwise orientation.  Orientation is clockwise (CW) for the opposite.
   */
  enum Orientation 
  {
    /** Orientation is unknown. */            eOrientationUnknown = 0,  
    /** Orientation is counter-clockwise. */  eOrientationCCW = 1,      
    /** Orientation is clockwise. */          eOrientationCW = 2        
  };

/** @name Orientation
    @{ */

  /**
   * Sets the orientation of the polygon.
   * @see Orientation
   */
  inline void SetOrientation (const Orientation iOrientation);

  /**
   * Gets the orientation of the polygon.
   * @see Orientation
   */
  inline Orientation GetOrientation () const;

/** @} */

public:

/** @name Merge and Split Services
    @{ */

  /**
   * Merges a vertex with another one.  All the bars referring to the duplicate vertex are updated.
   * The bar or bars between the two vertices are removed.
   * The duplicate vertex is removed.
   *
   * Limitation: The method does not handle loops and faces.  It should therefore be called for on an instance that contains
   * only vertices and bars.  (It cannot update the loops if there is no bar between the two vertices.)
   *
   * See also CollapseBar for a method that handles loops and faces.
   * See also Euler methods.
   *
   * @param iMergeVertex
   *   The vertex that remains after the merge
   * @param iDuplicateVertex
   *   The duplicate vertex that is removed after the merge.
   * @return
   *   S_OK upon success; E_FAIL otherwise.
   */
  HRESULT MergeVertices (CATPolyVertex2D* iMergeVertex, CATPolyVertex2D* iDuplicateVertex);

  /**
   * Splits a bar by a vertex.
   * @param iSplitBar
   *   The bar that is split.  This bar is modified: its end vertex is replaced by the new vertex.
   * @param iVertex
   *   The (new) vertex that split the bar. 
   * @param iNewBar
   *   The new bar created by this process.  Its start vertex is the new vertex. 
   *   Its end vertex is the end vertex of the split bar.
   * @param iReverse
   *   Swap start and end vertices in previous comments
   * @param iKeepOrder
   *   Keep same previous and next bar around start (or end for reverse) vertex for iSplitBar
   *   Bar ordering around start (resp end) vertex is invariant
   * @return
   *   S_OK upon success; E_FAIL otherwise.
   */
  HRESULT SplitBar (CATPolyBar2D* iSplitBar, CATPolyVertex2D* iVertex, CATPolyBar2D*& oNewBar,
                    int iReverse = 0, bool iKeepOrder = false);

  /**
   * Merges a bar with another one. The duplicate bar is removed.  
   * @param iMergeBar
   *   The bar that remains after the merge.
   * @param iDuplicateBar
   *   The duplicate bar that is removed after the merge.
   * @return
   *   S_OK upon success; E_FAIL otherwise.
   */
  HRESULT MergeBars (CATPolyBar2D* iMergeBar, CATPolyBar2D* iDuplicateBar);

  /**
   * Collapses and removes a bar from the polygon.
   * The optional argument is a vertex from the bar on which to collapse the bar.
   * The other vertex of the bar is not deleted by this operation.
   * This method updates loops (unlike MergeVertices.)
   */
  HRESULT CollapseBar (CATPolyBar2D* iBar, CATPolyVertex2D* iVertex = NULL);

/** @} */

public:

/** @name Euler's Operators
    Euler's operators edit a valid CATPolyPolygon2D object by adding or removing elements 
    (vertices, bars, loops and faces) while maintaining the Euler-Poincare formula
    (A valid CATPolyPolygon2D object satisfies the Euler-Poincare formula. More specifically,
    the Euler characteristic V + 2F - L - B is invariant while applying these operators.)
    @{ */

  /**
   * Adds a vertex and a loop to a face. 
   * @param iFace
   *   The face to which the vertex and the loop are added.
   * @param oVertexFull
   *   The new vertex.  This is a full vertex.
   * @param oLoop
   *   The output loop.
   */
  HRESULT EulerAddVertexAndLoop (CATPolyFace2D* iFace, CATPolyVertex2D*& oVertexFull, CATPolyLoop2D*& oLoop);

  /**
   * Removes a full vertex and a loop from a face.
   * @param iVertex
   *   The full vertex to remove from the face.
   * @param iLoop
   *   The loop to remove. 
   */
  HRESULT EulerRemoveVertexAndLoop (CATPolyVertex2D* iVertexFull, CATPolyLoop2D* iLoop);

  /**
   * Adds a vertex and a bar to a loop.
   * @param iVertexFrom
   *   The input start vertex of the new bar.  This should be a full vertex.
   * @param oVertex
   *   The added vertex.
   * @param oBar
   *   The added bar.
   */
  HRESULT EulerAddVertexAndBar (CATPolyVertex2D* iVertexFrom,
                                CATPolyVertex2D*& oVertex, CATPolyBar2D*& oBar);

  /**
   * Adds a vertex and a bar to a loop.
   * @param iBarFrom
   *   The input bar that will attach to the beginning of the new bar.
   * @param iVertexFrom
   *   The input start vertex of the new bar.
   * @param oVertex
   *   The added vertex.
   * @param oBar
   *   The added bar.
   */
  HRESULT EulerAddVertexAndBar (CATPolyBar2D* iBarFrom, CATPolyVertex2D* iVertexFrom,
                                CATPolyVertex2D*& oVertex, CATPolyBar2D*& oBar);

  /**
   * Removes a vertex and a bar (from a loop).
   * @param iVertex
   *   The vertex to remove.
   * @param iBar
   *   The bar to remove.
   */
  HRESULT EulerRemoveVertexAndBar (CATPolyVertex2D* iVertex, CATPolyBar2D* iBar);

  /**
   * Adds a bar, a loop and a face.
   * There are four input arguments (none should be null) and three returned arguments.
   * The pair (iBarFrom, iVertexFrom) and (iVertexTo, iBarTo) must belong to the same loop.
   * @param iBarFrom
   *   The input bar that will attach to the beginning of the new bar.
   * @param iVertexFrom
   *   The input start vertex of the new bar.
   * @param iVertexTo
   *   The input end vertex of the new bar.
   * @param iBarTo
   *   The input bar that will attach to the end of the new bar. 
   * @param oBar
   *   The new bar between iVertexFrom and iVertexTo.
   * @param oLoop
   *   The new loop.  The new loop contains the sequence (iBarFrom, iVertexFrom, oBar, iVertexTo, iBarTo).
   * @param oFace
   *   The new face defined by the new loop.
   * @return
   *   S_OK upon success; E_FAIL otherwise.
   */
  HRESULT EulerAddBarLoopAndFace (CATPolyBar2D* iBarFrom, CATPolyVertex2D* iVertexFrom,
                                  CATPolyVertex2D* iVertexTo, CATPolyBar2D* iBarTo,
                                  CATPolyBar2D*& oBar, CATPolyLoop2D*& oLoop, CATPolyFace2D*& oFace);

  /**
   * Removes a bar, a loop and a face.
   * There are three input arguments (none should be null).
   * @param iBar
   *   The bar to remove.
   * @param iLoop
   *   The loop to remove.
   * @param iFace
   *   The face to remove.
   * @return
   *   S_OK upon success; E_FAIL otherwise.
   */
  HRESULT EulerRemoveBarLoopAndFace (CATPolyBar2D* iBar, CATPolyLoop2D* iLoop, CATPolyFace2D* iFace);

  /**
   * Adds a bar and removes a loop.
   * There are five input arguments (none should be null) and one output argument.
   * @param iBarFrom
   *   The bar to which the start of the new bar will be connected.
   * @param iVertexFrom
   *   The vertex defining the start of the new bar.
   * @param iVertexTo
   *   The vertex defining the end of the new bar.
   * @param iBarTo
   *   The bar to which the end of the new bar will be connected.
   * @param iLoop
   *   The loop that will be removed.
   * @param oBar
   *   The new bar that is added.
   */
  HRESULT EulerAddBarRemoveLoop (CATPolyBar2D* iBarFrom, CATPolyVertex2D* iVertexFrom,
                                 CATPolyVertex2D* iVertexTo, CATPolyBar2D* iBarTo, CATPolyLoop2D* iLoop,
                                 CATPolyBar2D*& oBar);

  /**
   * Adds a bar and removes a loop.  Case of a full vertex.
   * There are four input arguments (none should be null) and one output argument.
   * @param iBarFrom
   *   The bar to which the start of the new bar will be connected.
   * @param iVertexFrom
   *   The vertex defining the start of the new bar.
   * @param iVertexFull
   *   The vertex defining the end of the new bar.  This vertex is a full vertex.
   * @param iLoop
   *   The loop that will be removed.
   * @param oBar
   *   The new bar that is added.
   */
  HRESULT EulerAddBarRemoveLoop (CATPolyBar2D* iBarFrom, CATPolyVertex2D* iVertexFrom,
                                 CATPolyVertex2D* iVertexFull, CATPolyLoop2D* iLoop,
                                 CATPolyBar2D*& oBar);

  /**
   * Adds a bar and removes a loop.  Case of two full vertices.
   * There are three input arguments (none should be null) and one output argument.
   * @param iVertexFullFrom
   *   The vertex defining the start of the new bar.  This vertex is a full vertex.
   * @param iVertexFullTo
   *   The vertex defining the end of the new bar.  This vertex is a full vertex.
   * @param iLoop
   *   The loop that will be removed.
   * @param oBar
   *   The new bar that is added.
   */
  HRESULT EulerAddBarRemoveLoop (CATPolyVertex2D* iVertexFullFrom, CATPolyVertex2D* iVertexFullTo, 
                                 CATPolyLoop2D* iLoop,
                                 CATPolyBar2D*& oBar);

  /**
   * Removes a bar and adds a loop.
   * There is one input argument and one output argument.
   * @param iBar
   *   The bar to remove.
   * @param oLoop
   *   The added loop.
   */
  HRESULT EulerRemoveBarAddLoop (CATPolyBar2D* iBar, CATPolyLoop2D*& oLoop);

  /**
   * Adds a vertex and splits a bar with this new vertex.
   * @param iVertexFrom
   *   The start or end vertex of the bar.
   * @param iBar
   *   The bar being split. After the split, this bar refers to iVertexFrom and the new vertex.
   * @param oVertex
   *   The new vertex created by the split.
   * @param oBar
   *   The new bar resulting from the split; this bar refers to the new vertex and the other bar vertex.
   */
  HRESULT EulerAddVertexSplitBar (CATPolyVertex2D* iVertexFrom, CATPolyBar2D* iBar, 
                                  CATPolyVertex2D*& oVertex, CATPolyBar2D*& oBar);

  /**
   * Merges two vertices and removes a bar.
   * This methods removes a vertex and a bar.
   * @param bar
   *   The bar to remove.
   * @param vertex
   *   The vertex of the bar to keep.  The other vertex of the bar is removed.
   */
  HRESULT EulerMergeVerticesRemoveBar (CATPolyBar2D* iBar, CATPolyVertex2D* iVertex);

/** @} */

public:

/** @name Removal Services
    @{ */

  /** 
   * Removes all faces.
   */
  HRESULT RemoveFaces ();

  /** 
   * Removes all loops.
   */
  HRESULT RemoveLoops ();

  /**
   * Removes all bars.
   */
  HRESULT RemoveBars ();

  /**
   * Removes all vertices.
   */
  HRESULT RemoveVertices ();

  /**
   * Removes all vertices, bars, loops and faces from the polygon.
   */
  inline HRESULT RemoveAll ();

/** @} */

public:

/** @name Observers
    @{ */

  /**
   * Registers an observer.
   */
  HRESULT RegisterObserver (CATPolyPolygonObserver2D& iObserver);

  /**
   * Unregisters an observer.
   */
  HRESULT UnregisterObserver (CATPolyPolygonObserver2D& iObserver);

/** @} */

  CATPolyAllocator2D& GetAllocator() const;

public:

/** @name Print Services
    To print the data structure on a CGM output, the environment variable <code>CATDevelopmentStage<\code> must
    be set to <code>TRUE<\code>.
    @{ */

  void Print (CATCGMOutput& stream) const;
  void PrintVertices (CATCGMOutput& stream) const;
  void PrintFullVertices (CATCGMOutput& stream) const;
  void PrintBars (CATCGMOutput& stream) const;
  void PrintFacesAndLoops (CATCGMOutput& stream) const;
  void PrintLoops (CATCGMOutput& stream, CATPolyFace2D* face) const;
  void PrintLoop (CATCGMOutput& stream, CATPolyLoop2D* loop) const;

/** @} */

protected:

  friend class CATPolyVertexIter2D;
  friend class CATPolyBarIter2D;
  friend class CATPolyLoopIter2D;
  friend class CATPolyFaceIter2D;
  friend class CATPolyPolygon2DStreamer;

  // Do not use the buckets services below outside this module.
  // Reserved for iterators.

  /**
   * @nodoc
   */
  inline CATPolyVertexBuckets2D* GetVertexBuckets () const;

  /**
   * @nodoc
   */
  inline CATPolyBarBuckets2D* GetBarBuckets () const;

  /**
   * @nodoc
   */
  inline CATPolyLoopBuckets2D* GetLoopBuckets () const;

  /**
   * @nodoc
   */
  inline CATPolyFaceBuckets2D* GetFaceBuckets () const;

protected:
  CATPolyAllocator2D *_Allocator;

  CATPolyVertexBuckets2D* _Vertices;
  CATPolyBarBuckets2D* _Bars;
  CATPolyLoopBuckets2D* _Loops;
  CATPolyFaceBuckets2D* _Faces;

  int _NbVertices;
  int _NbFullVertices;
  int _NbBarsAndFullVertices;
  int _NbArcs;
  int _NbLoops;
  int _NbFaces;

  Orientation _Orientation;  // Orientation of the object.

  CATPolyPolygonObserver2D* _Observer;  // Pointer to first observer.

private:
  template<class> friend class CATPolyProcessOverlay;

  CATPolyVertex2D* NewVertex () ;
  void DeleteVertex (CATPolyVertex2D& vertex) ;

  CATPolyBar2D* NewBar (CATPolyVertex2D& vertex0, CATPolyVertex2D& vertex1) ;  // Standard bar.
  CATPolyBar2D* NewBar (CATPolyVertex2D& vertex) ;  // Bar for full vertex.
  CATPolyBar2D* NewBar(CATPolyVertex2D& vertex0, CATPolyVertex2D& vertex1, CATMathPoint2D const& iPoint, bool iThroughPoint);  // Arc
  void FastRemoveBar(CATPolyBar2D& iBar);
  void DeleteBar (CATPolyBar2D& bar) ;

  CATPolyLoop2D* NewLoop (CATPolyCoBar2D* cobar) ;
  void DeleteLoop (CATPolyLoop2D& loop) ;

  CATPolyFace2D* NewFace (CATPolyLoop2D* loop) ;
  void DeleteFace (CATPolyFace2D& face) ;

  /**
   * Merges two distinct loops.  The loops must belong to the same face.
   */
  HRESULT MergeLoops (CATPolyLoop2D& loop0, CATPolyLoop2D& loop1) ;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private :

  // Forbidden.
  CATPolyPolygon2D (CATPolyPolygon2D& iOther) ;
  CATPolyPolygon2D& operator= (CATPolyPolygon2D& iOther) ;

public:

  // To become protected.
  CATPolyPolygon2D();
  CATPolyPolygon2D(CATPolyAllocator2D &iAllocator);

  // To become protected.
  ~CATPolyPolygon2D ();

public:

  // DEPRECATED. ** DO NOT USE **

  /**
   * @deprecated
   * See CATPolyVertexIter2D
   */
  POLY_DEPRECATED("Use CATPolyVertexIter2D for iterate over vertices.",
    CATPolyVertex2D* GetVertex(const int index) const);

  /**
   * @deprecated
   * See CATPolyBarIter2D
   */
  POLY_DEPRECATED("Use CATPolyBarIter2D for iterate over bars.",
    CATPolyBar2D* GetBar(const int index) const);

  /**
   * @deprecated
   * See CATPolyFaceIter2D
   */
  POLY_DEPRECATED("Use CATPolyFaceIter2D for iterate over faces.",
    CATPolyFace2D* GetFace(const int index) const);

  /**
   * @deprecated 
   * See CATPolyPolygonTools2D::GetVertexIndex.
   */
  static int GetVertexIndex (const CATPolyVertex2D* iVertex);

  /**
   * @deprecated 
   * See CATPolyPolygonTools2D::GetBarIndex.
   */
  static int GetBarIndex (const CATPolyBar2D* iBar);

  /**
   * @deprecated 
   * See CATPolyPolygonTools2D::GetFaceIndex.
   */
  static int GetFaceIndex (const CATPolyFace2D* iFace);

public:

  /**
   * @deprecated 
   * @see FaceAddLoop.
   */
  POLY_DEPRECATED ("Replace by a call to FaceAddLoop ().", 
    HRESULT AddInnerLoop (CATPolyFace2D* iFace, CATPolyLoop2D* iLoop););

  /**
   * @deprecated 
   * @see FaceRemoveLoop.
   */
  POLY_DEPRECATED ("Replace by a call to FaceRemoveLoop ().", 
    HRESULT RemoveInnerLoop (CATPolyLoop2D* iLoop););

public:

  /**
   * @deprecated
   */
  HRESULT AddOuterHoleFace (CATPolyFace2D*& oFace);

  /**
   * @deprecated
   * @see Poly::GetOuterFace ()
   * CATPolyPolygonServices2D.h
   */
  HRESULT GetOuterHoleFace (CATPolyFace2D*& oFace) const;

  /**
   * @deprecated
   * @see Poly::GetOuterFace ()
   * CATPolyPolygonServices2D.h
   */
  CATBoolean IsOuterHoleFace (const CATPolyFace2D* iFace) const;

public:

  /**
   * @deprecated
   */
  HRESULT GetVertices (CATListPV &oVertices) const ;

  /**
   * @deprecated
   */
  static HRESULT GetVertexPosition (const CATPolyVertex2D* iVertex, CATMathPoint2D& oPoint) ;

  /**
   * @deprecated
   */
  CATPolyLoop2D* NextLoop (const CATPolyLoop2D* iLoop) const ;

  /**
   * @deprecated
   */
  HRESULT GetLoops (const CATPolyFace2D* iFace, CATListPV &oLoops) const ;

  /** 
   * @deprecated
   * See CATPolyFaceLoopIter2D.
   */
  static CATPolyLoop2D* GetLoop (const CATPolyFace2D* iFace);

public: 

  /**
   * @deprecated
   */
  void Clear ();

  /**
   * @deprecated
   */
  HRESULT AddVertex (const CATMathPoint2D  &iPoint, CATPolyVertex2D*& oVertex) ;

  /**
   * @deprecated
   */
  inline HRESULT GetVertices (int &oNbVertices, 
                              double*& oCoords) const {return E_FAIL;}

  /**
   * @deprecated
   */
  inline HRESULT GetFace (const CATPolyFace2D* iFace,
                          CATListOfInt &oIdxVertices) const {return E_FAIL;}

  /**
   * @deprecated
   * See CATPolyPolygonTools2D::GetFace.
   */
  static CATPolyFace2D* GetFace (const CATPolyLoop2D* iLoop) ;

  /**
   * @deprecated
   */
  HRESULT GetLoop (const CATPolyLoop2D*   iLoop,
                   CATListOfInt          &oIdxVertices) const ;

  /**
   * @deprecated
   */
  HRESULT GetTriangle (const CATPolyFace2D* iFace,
                       int oIdxVertices[3]) const;

  /**
   * @deprecated
   */
  HRESULT GetFace (const CATPolyFace2D* iFace,
                   CATListPV           &oVertices) const ;

  /**
   * @deprecated
   */
  HRESULT AddLoop (CATPolyCoBar2D* iCoBar, CATPolyLoop2D*& oLoop) ;

  /**
   * @deprecated
   */
  HRESULT GetLoop (const CATPolyLoop2D*  iLoop,
                   CATListPV            &oVertices) const ;

  /**
   * @deprecated
   */
  static CATPolyBar2D* GetBar (const CATPolyVertex2D* vertex0, const CATPolyVertex2D* vertex1) ;

  /**
   * @deprecated
   */
  HRESULT GetCoBars (const CATPolyFace2D*  iFace,
                     int                  &oNbCoBars, 
                     CATPolyCoBar2D**     &oCoBars) const ;

  /**
   * @deprecated
   */
  HRESULT AddFace (const CATListPV         &iVertices,
                   CATPolyFace2D*          &oFace) ;

  /**
   * @deprecated
   */
  HRESULT GetFaces (CATListPV &oFaces) const ;

  /**
   * @deprecated
   */
  HRESULT GetCoBars (CATListPV &oCoBars, const CATBoolean iSkipTwin = TRUE) const ;

  /**
   * @deprecated
   */
  CATPolyVertex2D* GetStartVertex (CATPolyCoBar2D* iCoBar) const;

  /**
   * @deprecated
   */
  CATPolyVertex2D* GetEndVertex (CATPolyCoBar2D* iCoBar) const;

  /**
   * @deprecated
   */
  static HRESULT GetBarVertices (const CATPolyBar2D* iBar, CATPolyVertex2D*& oVertex0, CATPolyVertex2D*& oVertex1);

  /**
   * @deprecated
   */
  static HRESULT GetBar (const CATPolyBar2D* iBar, CATPolyVertex2D*& oVertex0, CATPolyVertex2D*& oVertex1);

  /**
   * @deprecated
   */
  static CATPolyVertex2D* GetVertex (const CATPolyCoBar2D* cobar) ;

  /**
   * @deprecated
   */
  static CATPolyBar2D* GetBar (const CATPolyCoBar2D* cobar) ;

  /**
   * @deprecated
   * Adds a bar between two cobars in a face.  The new bar may split the loop of a face into two loops.
   * The bar may also merge two loops into one loop.
   * Both cobars must belong to the same face, but not necessarily to the same loop.
   * @param iFace
   * The face.
   * @param iCoBarPrev
   * The previous cobar.  Its next cobar will be the bar added.
   * @param iCoBarNext
   * The next cobar.  Its previous cobar will be the bar added.
   * @param oCoBar
   * The new cobar that is added.
   * @return
   * S_OK if the bar is added successfully.
   * E_FAIL otherwise.
   */
  HRESULT AddBar (CATPolyFace2D*    iFace, 
                  CATPolyCoBar2D*   iCoBarPrev, 
                  CATPolyCoBar2D*   iCoBarNext, 
                  CATPolyCoBar2D*  &oCoBar) ;

  /**
   * @deprecated
   * Adds a bar between a cobar and a free vertex in a face. 
   * @param iFace
   * The face.
   * @param iCoBarPrev
   * The previous cobar.  Its next cobar will be the bar added.
   * @param iVertex
   * The end vertex of the cobar added.
   * @param oCoBar
   * The new cobar that is added.
   * @return
   * S_OK if the bar is added successfully.
   * E_FAIL otherwise.
   */
  HRESULT AddBar (CATPolyFace2D*    iFace, 
                  CATPolyCoBar2D*   iCoBarPrev, 
                  CATPolyVertex2D*  iVertex, 
                  CATPolyCoBar2D*  &oCoBar) ;

  /**
   * @deprecated
   * Adds a bar between a free vertex and a cobar in a face. 
   * @param iFace
   * The face.
   * @param iVertex
   * The start vertex of the cobar added.
   * @param iCoBarNext
   * The next cobar.  Its previous cobar will be the bar added.
   * @param oCoBar
   * The new cobar that is added.
   * @return
   * S_OK if the bar is added successfully.
   * E_FAIL otherwise.
   */
  HRESULT AddBar (CATPolyFace2D*    iFace, 
                  CATPolyVertex2D*  iVertex, 
                  CATPolyCoBar2D*   iCoBarNext, 
                  CATPolyCoBar2D*  &oCoBar) ;

  /**
   * @deprecated
   * Adds a bar between vertex0 and vertex1.
   * This method assumes that a bar can be added between the two vertices without 
   * creating non-manifold vertices or bars.
   * @param iFace
   * The face to which the returned cobar belongs.  
   * NULL if the bar is added to hole.
   * @param iCoBar0
   * A cobar from the face (or the hole) whose destination vertex is Vertex 0 and to which the new cobar will be
   * connected.  NULL if none is specified.
   * @param iVertex0
   * The first vertex.
   * @param iVertex1
   * The second vertex.
   * @param iCoBar1
   * A cobar from the face (or the hole) whose origin vertex is Vertex 1 and to which the new cobar will be connected.
   * NULL is none is specified.
   * @param oCoBar
   * The new cobar that is added.
   * @return
   * The cobar going from vertex0 to vertex1.
   */
  HRESULT AddBar (CATPolyFace2D*    iFace,
                  CATPolyCoBar2D*   iCoBar0, 
                  CATPolyVertex2D*  iVertex0, 
                  CATPolyVertex2D*  iVertex1, 
                  CATPolyCoBar2D*   iCoBar1,
                  CATPolyCoBar2D*  &oCoBar) ;

  /**
   * @deprecated
   */
  HRESULT DumpVertices () const ;

  /**
   * @deprecated
   */
  HRESULT DumpLoops () const ;

  /**
   * @deprecated
   */
  HRESULT Dump () const ;

#endif

};

inline CATPolyPolygon2D* CATPolyPolygon2D::New ()
{
  return new CATPolyPolygon2D;
}

inline void CATPolyPolygon2D::Release ()
{
  delete this;
}

inline CATPolyAllocator2D& CATPolyPolygon2D::GetAllocator() const
{
  return *_Allocator;
}

inline int CATPolyPolygon2D::GetNbVertices () const
{
  return _NbVertices;
}

inline int CATPolyPolygon2D::GetNbFullVertices () const
{
  return _NbFullVertices;
}

inline int CATPolyPolygon2D::GetNbBars () const
{
  return _NbBarsAndFullVertices - _NbFullVertices;
}

inline int CATPolyPolygon2D::GetNbArcs() const
{
  return _NbArcs;
}

inline int CATPolyPolygon2D::GetNbBarsAndFullVertices() const
{
  return _NbBarsAndFullVertices;
}

inline int CATPolyPolygon2D::GetNbLoops () const
{
  return _NbLoops;
}

inline int CATPolyPolygon2D::GetNbFaces () const
{
  return _NbFaces;
}

inline CATPolyVertexBuckets2D* CATPolyPolygon2D::GetVertexBuckets () const
{
  return _Vertices;
}

inline CATPolyBarBuckets2D* CATPolyPolygon2D::GetBarBuckets () const
{
  return _Bars;
}

inline CATPolyLoopBuckets2D* CATPolyPolygon2D::GetLoopBuckets () const
{
  return _Loops;
}

inline CATPolyFaceBuckets2D* CATPolyPolygon2D::GetFaceBuckets () const
{
  return _Faces;
}

inline void CATPolyPolygon2D::SetOrientation (const Orientation iOrientation) 
{
  _Orientation = iOrientation;
}

inline CATPolyPolygon2D::Orientation CATPolyPolygon2D::GetOrientation () const
{
  return _Orientation;
}

inline HRESULT CATPolyPolygon2D::RemoveAll ()
{
  Clear ();
  return S_OK;
}

inline HRESULT CATPolyPolygon2D::RemoveBar(CATPolyBar2D* iBar)
{
  if (iBar)
  {
    RemoveBar(*iBar);
    return S_OK;
  }
  else
  {
    return S_FALSE;
  }
}

inline HRESULT CATPolyPolygon2D::RemoveFace(CATPolyFace2D *iFace)
{
  if (iFace)
    RemoveFace(*iFace);
  return S_OK;
}

inline HRESULT CATPolyPolygon2D::RemoveLoop(CATPolyLoop2D* iLoop)
{
  if (iLoop)
    RemoveLoop(*iLoop);
  return S_OK;
}

#endif
