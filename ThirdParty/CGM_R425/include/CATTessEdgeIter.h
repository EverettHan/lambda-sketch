/* -*-C++-*-*/
#ifndef CATTessEdgeIter_H
#define CATTessEdgeIter_H


// COPYRIGHT DASSAULT SYSTEMES  1999

/**
 * @level Protected
 * @usage U1
 */ 

#include "TessAPI.h"

#include "CATBoolean.h"
#include "CATCGMNewArray.h"
#include "CATFace.h"
#include "CATPCurve.h"

#include "CATIACGMLevel.h"
#include "CATThrowForNullPointer.h"
#include "CATCGMTessEdgeIter.h"

class CATTessEdge;
class CATTessContour;
/**
 * Class that outputs the point tessellation numbers corresponding to the
 * the points on a given edge.
 * <br>The points are given relatively to one bounded (or adjacent) face. By assumption, the edges are
 * considered here to bound two faces at most.
 * <br> Such class is directly created by the @href CATBodyTessellator#GetEdge method. 
 * Its deletion is managed at the
 * CATBodyTessellator deletion. 
 * <br> Use it according to the following scheme:
 * <ul> 
 * <li> Retrieve the number of points for a given edge, with regards to a given face. 
 * <li> Allocate the array of numbers
 * <li> Retrieve the result
 * <li> Delete the array.
 * </ul>
 */
class ExportedByTessAPI CATTessEdgeIter: public CATCGMTessEdgeIter
{
public:
  /**
   * @nodoc
   * Default constructor.
   */
  CATTessEdgeIter();

  /**
   * Destructor
   */
  virtual ~CATTessEdgeIter();

  /** @nodoc */
  CATCGMNewClassArrayDeclare;

  /**
   * Returns the pointer to an adjacent face.
   * @param iNuFace
   * The first (<tt>iNuFace=1</tt>) or second (<tt>iNuFace=2</tt>) adjacent face.
   * @return
   * The pointer to the corresponding face.
   */
  inline CATFace * GetFace(int iNuFace) const;

  /**
   * Returns the pointer to a PCurve.
   * @param iNuFace
   * The first (<tt>iNuFace=1</tt>) or second (<tt>iNuFace=2</tt>) adjacent face.
   * @return
   * The pointer to the corresponding PCurve.
   */
  inline CATPCurve * GetPCurve(int iNuFace) const;

  /**
   * Returns a CATBoolean is TRUE if the tessellation point numbers for the edge and
   * the Edge are traveling throughtthe same sense.
   * @param iNuFace
   * The first (<tt>iNuFace=1</tt>) or second (<tt>iNuFace=2</tt>) adjacent face.
   * @return
   * a CATBoolean is TRUE if the tessellation point numbers for the edge and
   * the Edge are traveling throughtthe same sense.
   */
  inline CATBoolean GetSameSens(int iNuFace) const;

  /**
   * Returns the number of tesselation points for the edge relative to an adjacent face.
   * @param iNuFace
   * The first (<tt>iNuFace=1</tt>) or second (<tt>iNuFace=2</tt>) adjacent face.
   * @return
   * The number of tessellation points for the edge relative the <tt>iNuFace</tt> adjacent face.
   */
  inline int GetEdgeNbPts(int iNuFace) const;

  /**
   * Returns the tessellation point numbers for the edge relative to an adjacent face.
   * @param iNuFace
   * The first (<tt>iNuFace=1</tt>) or second (<tt>iNuFace=2</tt>) adjacent face.
   * @param ioNuPts
   * The array of the tessellation point numbers. This array must be allocated and deallocated
   * by the caller. Its dimension is given by the @href CATTessEdgeIter#GetEdgeNbPts method.
   * If the contour is open, the first and last points are different.
   */
  virtual void GetEdgeNuPts(int iNuFace, int  ioNuPts[]) const;

#if defined (CATIACGMV5R17)
  /**
   * Returns the tessellation point parameters for the edge relative to an adjacent face.
   * @param iNuFace
   * The first (<tt>iNuFace=1</tt>) or second (<tt>iNuFace=2</tt>) adjacent face.
   * @param ioCrvParam
   * The array of the tessellation point parameters (as a CATCrvParam on the underlying edge curve)
   * @param ioQualPts
   * The array which allows you to determine the ioCrvParam  quality:
   *   <ul>
   * <li> 0 : ioCrvParam impossible computation
   * <li> 1 : ioCrvParam exact computation
   * <li> 2 : ioCrvParam does not neccessarily correspond to Xyz or Uv (merged points)
   * </ul>
   * These arrayes must be allocated and deallocated by the caller. 
   * Its dimension is given by the @href CATTessEdgeIter#GetEdgeNbPts method.
   * If the contour is open, the first and last points are different.
   */
  virtual void GetEdgeW(int iNuFace, double ioCrvParam[], short ioQualPts[] ) const;
#endif

  /** 
   * @nodoc 
   * Initializes the iterator for one edge.
   */
  virtual void Initialize(CATTessEdge *  iEdge);

  /** 
   * @nodoc 
   * Copies an iterator.
   */
  inline void Initialize(CATTessEdgeIter *  iEdgeIter);

protected:
 /** @nodoc */
  CATFace        * _Face[2];
 /** @nodoc */
  CATPCurve      * _PCurve[2];
 /** @nodoc */
  CATTessContour * _ContourEdge[2];
 /** @nodoc */
  CATTessEdge    * _TessEdge;
 /** @nodoc */
  int              _NbPts[2];
  /** @nodoc */
  /* le ContourEdge est-il parcouru dans le meme sens que l'Egde ?*/
  CATBoolean       _MemeSens[2];
};

//=============================================================================
// INLINE IMPLEMENTATIONS 
//=============================================================================

inline CATFace * CATTessEdgeIter::GetFace(int NuFace) const
{
  CATFace * Face = NULL;
  if ( NuFace>=1 && NuFace<=2 ) {
    Face = _Face[NuFace-1];
  }

  return Face;
}

inline CATPCurve * CATTessEdgeIter::GetPCurve(int NuFace) const
{
  CATPCurve * PCurve = NULL;
  if ( NuFace>=1 && NuFace<=2 ) {
    PCurve = _PCurve[NuFace-1];
  }

  return PCurve;
}
inline CATBoolean CATTessEdgeIter::GetSameSens(int NuFace) const
{
  CATBoolean SameSens = -1;
  if ( NuFace>=1 && NuFace<=2 ) {
    SameSens = _MemeSens[NuFace-1];
  }
  return SameSens;
}

inline int CATTessEdgeIter::GetEdgeNbPts(int NuFace) const
{
  int NbPts = 0;
  if ( NuFace>=1 && NuFace<=2 ) {
    NbPts = _NbPts[NuFace-1];
  }

  return NbPts;
}

inline void CATTessEdgeIter::Initialize(CATTessEdgeIter *  iEdgeIter)
{
  if ( iEdgeIter==NULL ) CATThrowForNullPointer();
  if (iEdgeIter->_TessEdge) {
    Initialize(iEdgeIter->_TessEdge);
  }
}


#endif
