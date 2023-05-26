// COPYRIGHT DASSAULT SYSTEMES 2004, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPolygonOper2D.h
// Header definition of CATPolyPolygonOper2D
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// December 2004 Creation: ndo
//===================================================================
#ifndef CATPolyPolygonOper2D_H
#define CATPolyPolygonOper2D_H

#include "PolygonalOperators.h"
#include "CATListOfInt.h"
#include "CATListPV.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"     // HRESULT definition

class CATPolyPolygon2D;
class CATPolyLoop2D;
class CATPolyFace2D;
class CATPolyCoBar2D;
class CATPolyVertex2D;
class CATPolyExactArithmetic;
class CATMathPoint2D;


/**
 OBSOLETE OPERATOR.  SEE INSTEAD CATPolyPolygonOverlay2D or CATPolyBooleanOper2D.
 DO NOT USE!
/*
 Operator that constructs a polygon from a set of segments in random order.
 To construct a polygon:
   - Set the polygon to be constructed.
   - Add the vertices to the operator.
   - Add the segments and/or loops that link these vertices.  
   - Run the operator.
 After successful completion, a valid polygon will be constructed.
 The vertices of each segment must have distinct coordinates.
*/

class ExportedByPolygonalOperators CATPolyPolygonOper2D
{

public :

  CATPolyPolygonOper2D (const CATPolyExactArithmetic& iExactArithmetic);

  ~CATPolyPolygonOper2D ();

  /**
   * Sets the polygon to be constructed.  The polygon will be cleared of all its data.
   * @param iPolygon
   *   The polygon.
   */
  void SetPolygon (CATPolyPolygon2D* iPolygon);

  /**
   * Set on or off the option to construct one and only one face.
   * When this option is turned on, only one face is constructed with multiple loops.
   * By default, this option is set to FALSE (multiple faces are constructed for different loops.)
   */
  void SetOneFaceOption (const CATBoolean iOneFaceOption);

  /**
   * Adds an array of vertices.  The vertices will be directly added to the 2D polygon.
   * @param iNbVertices
   *   The number of vertices to add.
   * @param iPoints
   *   The positions of the vertices to add.
   *   The dimension of the array is equal to the number of vertices.
   * @param oVertices
   *   The list of vertices that have been added.
   * @return
   *   S_OK if the vertices are added successfully.
   *   E_FAIL otherwise.
   */
  HRESULT AddVertices (const int              iNbVertices,
                       const CATMathPoint2D*  iPoints,
                       CATListPV             &oVertices) ;

  /**
   * Adds a segment using the indices of the vertices based on their order of insertion in AddVertices ().
   * This method can be called as many times as needed to add several segments.
   * The indices of the vertices start at 0.
   * @param iVertex0
   *   The index of the start vertex of the segment.
   * @param iVertex1
   *   The index of the end vertex of the segment.
   * @return
   *   S_OK if the segment is added successfully.
   *   E_FAIL otherwise.
   */
  HRESULT AddSegment (const int iVertex0, const int iVertex1) ;

  /**
   * Adds segments using the indices of the vertices based on their order of insertion in AddVertices ().
   * This method can be called as many times as needed to add several polylines.
   * @param iIdxVertices
   *   The list of indices of the vertices defining the segments.  The segments define a polyline.
   *   The number of segments added is the number of indices in the list minus one.
   *   The indices start at 0.
   * @return
   *   S_OK if the segments are added successfully.
   *   E_FAIL otherwise.
   */
  HRESULT AddSegments (const CATListOfInt& iIdxVertices) ;

  /**
   * Adds a series of segments forming a loop using the indices of the vertices based on their order of insertion 
   * in AddVertices (). This method can be called as many times as needed to add several loops.
   * @param iIdxVertices
   *   The list of indices of the vertices defining the loop.  The loop is composed of segments
   *   defined by successive pair of indices.  The last segment of the loop is defined by the pair formed 
   *   by the last and first indices.  (The loop is automatically closed; there is no need to repeat the
   *   first index.)  Therefore, the number of segments in the loop is equal to the number of indices 
   *   in the list. The indices start at 0.
   * @return
   *   S_OK if the segments are added successfully.
   *   E_FAIL otherwise.
   */
  HRESULT AddLoop (const CATListOfInt& iIdxVertices) ;

  /**
   * Adds a series of segments forming a hole loop using the indices of the vertices based on their order of 
   * insertion in AddVertices (). No face is constructed for hole loops.
   * This method can be called as many times as needed to add several hole loops.
   * @param iIdxVertices
   *   The list of indices of the vertices defining the loop.  The loop is composed of segments
   *   defined by successive pair of indices.  The last segment of the loop is defined by the pair formed 
   *   by the last and first indices.  (The loop is automatically closed; there is no need to repeat the
   *   first index.)  Therefore, the number of segments in the loop is equal to the number of indices 
   *   in the list. The indices start at 0.
   * @return
   *   S_OK if the segments are added successfully.
   *   E_FAIL otherwise.
   */
  HRESULT AddHoleLoop (const CATListOfInt& iIdxVertices);

  /**
   * Runs the operator to construct a valid polygon.  The polygon will be oriented positively.
   * (Outer loops of the faces in the counter-clockwise direction.)
   */
  HRESULT Run () ;

  /**
   * Given the indices of the vertices.  Returns the face associated to the cobar between
   * iVertex0 and iVertex1 or NULL if this is a hole face.
   * Note: GetFace (iVertex0, iVertex1) != GetFace (iVertex1, iVertex0) in most cases.
   * This method can be used to set an attribute to the face returned.
   * (see also CATPolyPolygon2D::SetAttribute ()).
   * This method should only be used after a successful invocation of Run ().
   */
  CATPolyFace2D* GetFace (const int iVertex0, const int iVertex1) const;
  
  /** 
   * Returns the error code different from 0 when the operator fails.
   * See CATPolyError2D.h for a definition of the various errors.
   */
  int GetError () const;

protected :

  /**
   * Add a bar between Vertex 0 and Vertex 1.  If a bar already exists, then do nothing.
   * @param vertex0
   *   The start vertex of the cobar associated to the bar.
   * @param vertex1
   *   The end vertex of the cobar associated to the bar.
   * @param cobar
   *   The cobar added or existing between vertex0 and vertex1.
   * @return
   *   TRUE if the method runs successfully and FALSE a bar between vertex0 and vertex1 cannot be added.
   */
  CATBoolean AddBar (CATPolyVertex2D* vertex0, CATPolyVertex2D* vertex1, 
                     CATPolyCoBar2D*& cobar);

  /**
   * Calculate the vertex position with respect to a cobar.
   * The method returns TRUE if a valid vertex position is calculated and FALSE otherwise.
   * The valid positions are:
   * 1) -1: The vertex is below the cobar.
   * 2)  0: The vertex is equal to the end vertex of the cobar. 
   * 3) +1: The vertex is above the cobar.
   * Otherwise, the position of the vertex is invalid.  An invalid position is coded as -2.
   */
  int VertexPosition (CATPolyCoBar2D* cobar, CATPolyVertex2D* vertex);

  /**
   * Find the cobar that has vertex0 as an end vertex and to which the cobar between vertex0 and vertex1
   * can be linked with the correct loop orientation. If a cobar already exists between vertex0 and vertex1,
   * then the method returns this cobar and sets the flag cobarFound to TRUE.
   * The method returns TRUE if it runs successfully and FALSE if an error is encountered.
   */
  CATBoolean FindPreviousCoBar (CATPolyVertex2D* vertex0, CATPolyVertex2D* vertex1,
                                CATPolyCoBar2D*& ocobar, CATBoolean& cobarFound);

private :

  const CATPolyExactArithmetic& _ExactArithmetic;

  CATPolyPolygon2D* _Polygon;
  CATBoolean        _OneFaceOption;  // By default, this option is FALSE.

  CATListPV         _Vertices;
  CATListPV         _CoBars;
  CATListPV         _HoleLoops;

  int _ErrorCode;

  // No implementation of copy constructor and operator =.
  CATPolyPolygonOper2D (CATPolyPolygonOper2D& iOther) ;
  CATPolyPolygonOper2D& operator= (CATPolyPolygonOper2D& iOther) ;

public:

  // DO NOT USE.
  CATPolyPolygonOper2D (const CATPolyExactArithmetic* iExactArithmetic);

};

#endif
