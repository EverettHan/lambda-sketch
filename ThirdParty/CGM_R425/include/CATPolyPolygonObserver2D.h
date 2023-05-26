// COPYRIGHT DASSAULT SYSTEMES 2007, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPolygonObserver2D.h
//
//===================================================================
// January 2007 Creation: ndo
//===================================================================
#ifndef CATPolyPolygonObserver2D_H
#define CATPolyPolygonObserver2D_H

#include "PolygonalModel.h"
#include "CATErrorDef.h"     // HRESULT definition (for compil under UNIX)

class CATPolyPolygon2D;
class CATPolyVertex2D;
class CATPolyBar2D;
class CATPolyFace2D;
class CATPolyLoop2D;


/**
* Observer base class for CATPolyPolygon2D objects.  When events occur to an observed instance of
* a CATPolyPolygon2D object, calls to the observer signaling the events are made.  A call can be made
* before or after the event:
*   - Methods starting by PrepareTo and followed by the event name are called just before the event.
*   - Methods staring by ReactTo and followed by the event name are made just after the event.
*/
class ExportedByPolygonalModel CATPolyPolygonObserver2D
{

public :

  CATPolyPolygonObserver2D ();
  virtual ~CATPolyPolygonObserver2D ();

public:

/** @name Listening to Vertex Events
    @{ */

  /**
   * A call made after a vertex is added.
   */
  virtual HRESULT ReactToAddVertex (const CATPolyVertex2D* vertex);

  /**
   * A call made before a vertex is removed.
   */
  virtual HRESULT PrepareToRemoveVertex (const CATPolyVertex2D* vertex);

  /**
   * A call made after an update to the position of a vertex.
   */
  virtual HRESULT ReactToSetVertexPosition (const CATPolyVertex2D* vertex);

/** @} */

public:

/** @name Listening to Bar Events
    @{ */

  /**
   * A call made after a bar is added.
   */
  virtual HRESULT ReactToAddBar (const CATPolyBar2D* bar);

  /**
   * A call made before a bar is removed.
   */
  virtual HRESULT PrepareToRemoveBar (const CATPolyBar2D* iBar);

/** @} */

public:

/** @name Listening to Full-Vertex Events
    @{ */

  /**
   * A call made after a full-vertex is added.
   */
  virtual HRESULT ReactToAddFullVertex (const CATPolyVertex2D* vertex);

  /**
   * A call made before a full-vertex is removed.
   */
  virtual HRESULT PrepareToRemoveFullVertex (const CATPolyVertex2D* vertex);

/** @} */

public:

/** @name Listening to Face Events
    @{ */

  /**
   * A call made after a face is added.
   */
  virtual HRESULT ReactToAddFace (const CATPolyFace2D* iFace);

  /**
   * A call made before a face is removed.
   */
  virtual HRESULT PrepareToRemoveFace (const CATPolyFace2D* iFace);

  /**
   * A call made after addition of a loop to a face.
   */
  virtual HRESULT ReactToFaceAddLoop (const CATPolyFace2D* iFace, const CATPolyLoop2D* iLoop);

  /**
   * A call made before removal of a loop from a face.
   */
  virtual HRESULT PrepareToFaceRemoveLoop (const CATPolyFace2D* iFace, const CATPolyLoop2D* iLoop);

/** @} */

public:

/** @name Listening to Split and Merge Events
    @{ */

  /**
   * A call made before two vertices are merged.
   */
  virtual HRESULT PrepareToMergeVertices (const CATPolyVertex2D* iMergeVertex, const CATPolyVertex2D* iDuplicateVertex);

  /**
   * A call made before a bar is split.
   * The iSplitBar will be split by iVertex
   */
  virtual HRESULT PrepareToSplitBar (const CATPolyBar2D* iSplitBar, const CATPolyVertex2D* iVertex);

  /**
   * A call made after a bar is split.
   */
  virtual HRESULT ReactToSplitBar (const CATPolyBar2D* iSplitBar, const CATPolyVertex2D* iVertex, 
                                   const CATPolyBar2D* iNewBar); 

  /**
   * A call made before two bars are merged.
   */
  virtual HRESULT PrepareToMergeBars (const CATPolyBar2D* iMergeBar, const CATPolyBar2D* iDuplicateBar);

/** @} */

/** @name Listening to Euler events
    @{ */

  /**
   * A call made after a vertex and a loop are added.
   */
  virtual HRESULT ReactToEulerAddVertexAndLoop (CATPolyFace2D* iFace, CATPolyVertex2D* oVertexFull, CATPolyLoop2D* oLoop);

  /**
   * A call made before a vertex and a loop are removed. 
   */
  virtual HRESULT PrepareToEulerRemoveVertexAndLoop (CATPolyVertex2D* iVertexFull, CATPolyLoop2D* iLoop);

  /**
   * A call made after a vertex and a bar are added.
   */
  virtual HRESULT ReactToEulerAddVertexAndBar (CATPolyVertex2D* iVertexFrom,
                                               CATPolyVertex2D* oVertex, CATPolyBar2D* oBar);

  /**
   * A call made after a vertex and a bar are added.
   */
  virtual HRESULT ReactToEulerAddVertexAndBar (CATPolyBar2D* iBarFrom, CATPolyVertex2D* iVertexFrom,
                                               CATPolyVertex2D* oVertex, CATPolyBar2D* oBar);

  /**
   * A call made before a vertex and a bar is removed (from a loop).
   */
  virtual HRESULT PrepareToEulerRemoveVertexAndBar (CATPolyVertex2D* iVertex, CATPolyBar2D* iBar);

  /**
   * A call made after a bar, a loop and a face are added.
   */
  virtual HRESULT ReactToEulerAddBarLoopAndFace (CATPolyBar2D* iBarFrom, CATPolyVertex2D* iVertexFrom,
                                                 CATPolyVertex2D* iVertexTo, CATPolyBar2D* iBarTo,
                                                 CATPolyBar2D* oBar, CATPolyLoop2D* oLoop, CATPolyFace2D* oFace);

  /**
   * A call made before a bar, a loop and a face are removed.
   */
  virtual HRESULT PrepareToEulerRemoveBarLoopAndFace (CATPolyBar2D* iBar, CATPolyLoop2D* iLoop, CATPolyFace2D* iFace);

  /**
   * A call made before a bar is added and a loop is removed.
   */
  virtual HRESULT PrepareToEulerAddBarRemoveLoop (CATPolyBar2D* iBarFrom, CATPolyVertex2D* iVertexFrom,
                                                  CATPolyVertex2D* iVertexTo, CATPolyBar2D* iBarTo, CATPolyLoop2D* iLoop);

  /**
   * A call made before a bar is added and a loop is removed.
   */
  virtual HRESULT PrepareToEulerAddBarRemoveLoop (CATPolyBar2D* iBarFrom, CATPolyVertex2D* iVertexFrom,
                                                  CATPolyVertex2D* iVertexFull, CATPolyLoop2D* iLoop);

  /**
   * A call made before a bar is added and a loop is removed.
   */
  virtual HRESULT PrepareToEulerAddBarRemoveLoop (CATPolyVertex2D* iVertexFullFrom, CATPolyVertex2D* iVertexFullTo, 
                                                  CATPolyLoop2D* iLoop);

  /**
   * A call made after a bar is added and a loop is removed.
   */
  virtual HRESULT ReactToEulerAddBarRemoveLoop (CATPolyBar2D* oBar);

  /**
   * A call made before a bar is removed and a loop is added.
   */
  virtual HRESULT PrepareToEulerRemoveBarAddLoop (CATPolyBar2D* iBar);

  /**
   * A call made after a vertex is added and a bar is splitted.
   */
  virtual HRESULT ReactToEulerAddVertexSplitBar (CATPolyVertex2D* iVertexFrom, CATPolyBar2D* iBar, 
                                                 CATPolyVertex2D* oVertex, CATPolyBar2D* oBar);

  /**
   * A call made before two vertices are merged and a bar is removed.
   */
  virtual HRESULT PrepareToEulerMergeVerticesRemoveBar (CATPolyBar2D* iBar, CATPolyVertex2D* iVertex);

/** @} */

public:

/** @name Listening to Other Events
    @{ */

  /**
   * Remove all vertices, bars, loops and faces from the polygon.
   */
  virtual HRESULT PrepareToClear ();

/** @} */

public:

#if 0
  // Methods that can be implemented in derived classes to control the observer.
  inline HRESULT Suspend ();
  inline HRESULT Resume ();
#endif

protected:

  friend class CATPolyPolygon2D;

  CATPolyPolygonObserver2D* _Prev;
  CATPolyPolygonObserver2D* _Next;

protected:

  inline CATPolyPolygonObserver2D* Prev () const;
  inline CATPolyPolygonObserver2D* Next () const;

  inline void SetPrev (CATPolyPolygonObserver2D* prev);
  inline void SetNext (CATPolyPolygonObserver2D* next);

};


inline CATPolyPolygonObserver2D* CATPolyPolygonObserver2D::Prev () const
{
  return _Prev;
}

inline CATPolyPolygonObserver2D* CATPolyPolygonObserver2D::Next () const
{
  return _Next;
}

inline void CATPolyPolygonObserver2D::SetPrev (CATPolyPolygonObserver2D* prev)
{
  _Prev = prev;
}

inline void CATPolyPolygonObserver2D::SetNext (CATPolyPolygonObserver2D* next)
{
  _Next = next;
}


// Methods to suspend or resume an observer.
// To be implemented in derived classes.
#if 0
inline HRESULT DerivedFromCATPolyPolygonObserver2D::Suspend ()
{
  _Suspended = true;
  return S_OK;
}

inline HRESULT DerivedFromCATPolyPolygonObserver2D::Resume ()
{
  _Suspended = false;
  return S_OK;
}
#endif

#endif
