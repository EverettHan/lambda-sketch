// COPYRIGHT DASSAULT SYSTEMES 2003, ALL RIGHTS RESERVED.
//=============================================================================
//
// CATPolyCell
//
//=============================================================================
// 2014-11-19   NDO: Replaced CATIPolySurface by CATPolyFaceSurface in constructor.
// 2009-11-03   NDO: Revisited implementation, Optimizations (size of CATPolyCell objects.)
// 2006-08-27   BPG: Raise
// 2003-03-20   FDS: New
//=============================================================================
#pragma once

#include "PolyMODEL.h"
#include "CATPolyCellOrbit.h"
#include "CATPolyMacroTopologyFwd.h"
#include "CATErrorDef.h"  // Definition of HRESULT.

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Poly 
{
  ExportedByPolyMODEL CATPolyBody* NewEditableBody (const CATPolyBody& iPolyBody);
}
#endif


/*
 * Base class for these classes: CATPolyVertex, CATPolyEdge, CATPolyFace and CATPolyVolume.
 * This class is not virtual.  Do not make it virtual.
 */
class ExportedByPolyMODEL CATPolyCell
{

public:

  ~CATPolyCell ();  // DO NOT MAKE THIS CLASS VIRTUAL!

public:

  /** 
   * @return
   *   Returns the dimension of this CATPolyCell:
   *   <dl>
   *     <dt> 0 </dt><dd> for a CATPolyVertex.</dd>
   *     <dt> 1 </dt><dd> for a CATPolyEdge.</dd>
   *     <dt> 2 </dt><dd> for a CATPolyFace.</dd>
   *     <dt> 3 </dt><dd> for a CATPolyVolume.</dd>
   *   </dl>
   */
  int GetDimension () const;

  /**
   * @return
   *   Returns the tag identifying this cell.
   */
  unsigned int GetCellTag () const;

public:

/** @name Reserved (Manual Edition)
    @{ */

  /**
   * Returns the state of the observer.
   */
  inline bool IsObserverSuspended () const;

  /**
   * Suspends the observer that propagates editing events
   * to adjacent and incident cells. The edition of the 
   * adjacent cells must be done manually including 
   * updates of the surface-cell layers from the CATPolyFace.
   */
  inline void SuspendObserver ();

  /**
   * Resumes the observer that propagates editing events
   * to adjacent and incident cells. 
   */
  inline void ResumeObserver ();

/* @} */

protected:

  // The placement variables come first in the definition of the CATPolyCell.  
  // It's reserved memory space for objects (observers.)
  // The overal size of the placement space must be at least equal to the largest size of the 
  // following objects:
  //   o CATPolyVertexPoint (a CATIPolyPointObserver.)
  //   o CATPolyEdgeCurve (a CATIPolyCurveObserver.)
  //   o CATPolyFaceSurface* (a pointer to a CATIPolySurfaceObserver.)
  // *** Do not change order of member variables! ***
  // *** Do not make CATPolyCell virtual! ***
  void* _PlacementPointer;   // Space reserved for a pointer.
  int   _PlacementInteger;   // Space reserved for an integer.

  // Bitfields: see below.
  unsigned int _BitFields;

private:

  // A tag used to identify the cell. It is zero by default and should be set
  // by the body the cell is attached to.
  unsigned int _CellTag;

  CATPolyCellOrbit _Orbit;

  friend class CATPolyBody;
  friend class CATPolyBodyHelpers;
  friend class CATPolyDartHelpers;
  friend class CATPolyCellOrbit;
  friend class CATPolyCellOrbitIterator;
  friend class CATPolyBodyTopologyUnstreamer;
  friend CATPolyBody* Poly::NewEditableBody (const CATPolyBody& iPolyBody);

protected:

  /**
   * Bitfields.
   * The first three bits are reserved for the cell type:
   *   * Vertex:                                                       0 0 1   = 0x01
   *   * Edge:                                                         0 1 0   = 0x02
   *   * Face with positive orientation w.r.t. CATPolyBody:            1 0 0   = 0x04
   *   * Face with no orientation w.r.t. CATPolyBody:                  1 0 1   = 0x05
   *   * Face with negative orientation w.r.t. CATPolyBody:            1 1 0   = 0x06
   *   * Volume:                                                       1 1 1   = 0x07
   *
   * Relative orientation:
   *   Four bits are reserved to specify the orientation of a cell C of dimension N w.r.t.
   *   the cells of dimension N+1 if there are at most two, let say A1 and A2.
   *   These bits enable the definition of the relative orientation of the two pairs: (C, A1) and (C, A2).
   *   (Relative orientation of C w.r.t. A1 and relative orientation of C w.r.t. A2.)
   *   The two pairs are distinguished by the values of the cell tags for A1 and A2;
   *   Let A1 be the N+1 cell with the smallest cell tag.
   *   The first two-bits are reserved to define the relative orientation of the (C, A1) pair.
   *   The second two-bits are reserved to define the relative orientation of the (C, A2) pair.
   *   Given the two-bits, the relative orientation is defined as follows:
   *     * 00: (C, Ai) has unset relative orientation
   *     * 01: (C, Ai) has positive relative orientation
   *     * 10: (C, Ai) has negative relative orientation
   *     * 11: (C, Ai) has null relative orientation
   *   Any change of the incidence of the cells require an update of the relative orientation bits.
   * 
   *   The relative orientation of an edge with at most two incident faces can be defined in this manner.
   *   And similarly, for the relative orientation of a face with at most two incident volumes.
   */
  enum BitFields
  {
    /* Cell type */              Bit0                 = 0x0001,  // Bit 0
    /* Cell type */              Bit1                 = 0x0002,  // Bit 1
    /* Cell type */              Bit2                 = 0x0004,  // Bit 2
    /* Mask for cell type */     MaskCells            = 0x0007,  // Bits 0, 1 & 2
    /* Map to Dart2 */           BitOrbit2            = 0x0008,  // Bit 3
    /* Map to Dart3 */           BitOrbit3            = 0x0010,  // Bit 4
    /* Mask for darts */         MaskOrbits           = 0x0018,  // Bits 3 & 4
    /* Observer suspended */     BitObserverSuspended = 0x0100,  // Bit 8
    /* Relative orientation. */  BitOrientation00     = 0x0400,  // Bit 10
    /* Relative orientation. */  BitOrientation01     = 0x0800,  // Bit 11
    /* Relative orientation. */  BitOrientation10     = 0x1000,  // Bit 12
    /* Relative orientation.*/   BitOrientation11     = 0x2000   // Bit 13
  };

  enum CellType
  {
    /* Vertex */               Vertex = Bit0,
    /* Edge */                 Edge   = Bit1,
    /* Face */                 Face   = Bit2,  // Face without relative orientation w.r.t. CATPolyBody by default.
    /* Volume */               Volume = Bit0 | Bit1 | Bit2
  };

  /**
    * Relative orientation of a cell w.r.t. incident cell of dimension K+1.
    * By default, the relative orientation is unset.
    */
  enum RelativeCellOrientation
  {
    /* Positive orientation */   PositiveRelativeOrientation0  = BitOrientation00,
    /* Negative orientation */   NegativeRelativeOrientation0  = BitOrientation01,
    /* Null orientation */       NullRelativeOrientation0      = BitOrientation00 | BitOrientation01,
    /* Positive orientation */   PositiveRelativeOrientation1  = BitOrientation10,
    /* Negative orientation */   NegativeRelativeOrientation1  = BitOrientation11,
    /* Null orientation */       NullRelativeOrientation1      = BitOrientation10 | BitOrientation11,
  };

  // For derived classes.
  CATPolyCell (CellType iCellType, unsigned int iTag = 0);

  inline bool IsVertex () const;
  inline bool IsEdge () const;
  inline bool IsFace () const;
  inline bool IsVolume () const;

public:

/** @name Internal usage only
    @{ */

  /**
   * Returns true if the cell refers to at least one or several orbits.
   */
  template<class DART>
  inline bool HasOrbits () const;

  /**
   * Returns true if the cell refers to at least one orbit (CATPolyDart2 or CATPolyDart3).
   */
  inline bool HasAnyOrbit () const;

  /**
   * Returns true if the cell refers to two or more orbits.
   */
  inline bool HasMultipleOrbits () const;

  /**
   * Returns the number of orbits:
   *   * Pseudo-manifold vertices
   *   * Manifold edges
   *   * Face loops
   *   * Volume shells
   */
  unsigned int GetNbOrbits () const;

  inline unsigned int DartType () const;

  /**
   * Clears a cell by removing all its orbits.
   */
  void Clear ();

  enum RelativeOrientation
  {
    /* Unset */      UnsetOrientation    = 2,
    /* Positive */   PositiveOrientation = 1,
    /* Negative */   NegativeOrientation = -1,
    /* Null */       NullOrientation     = 0,
  };

/** @} */

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:

/** @name Casting methods
    @{ */

  // Use CATPolyVertex::Cast ().
  CATPolyVertex* CastToVertex ();
  const CATPolyVertex* CastToVertex () const;

  // Use CATPolyEdge::Cast ().
  CATPolyEdge* CastToEdge ();
  const CATPolyEdge* CastToEdge () const;

  // Use CATPolyFace::Cast ().
  CATPolyFace* CastToFace ();
  const CATPolyFace* CastToFace () const;

  // Use CATPolyVolume::Cast ().
  CATPolyVolume* CastToVolume ();
  const CATPolyVolume* CastToVolume () const;

/* @} */

protected:

  template<class DART>
  inline bool MatchingType () const;

  inline const CATPolyCellOrbit* GetFirstOrbit () const;

  inline CATPolyCellOrbit* GetFirstOrbit ();

private:

  CATPolyCellOrbit* NewOrbit () const;
  void DeleteOrbit (CATPolyCellOrbit*& orbit) const;

  // Invoking placement new.
  CATPolyCellOrbit* ConstructOrbit (CATPolyCellOrbit* orbit) const;
  void DestructOrbit (CATPolyCellOrbit*& orbit) const;

  template<class DART>
  inline void SetOrbitFlag ();

  inline void UnsetOrbitFlag ();

  inline void SetCellTag (unsigned int tag);  // Reserved for CATPolyBodyTopologyUnstreamer.

  static bool WithVolumes (const CATPolyBody* B);

#endif
};

inline bool CATPolyCell::IsVertex () const
{
  return (MaskCells & _BitFields) == 0x01;
}

inline bool CATPolyCell::IsEdge () const
{
  return (MaskCells & _BitFields) == 0x02;
}

inline bool CATPolyCell::IsFace () const
{
  return 0x04 <= (MaskCells & _BitFields) && (MaskCells & _BitFields) < 0x07;
}

inline bool CATPolyCell::IsVolume () const
{
  return (MaskCells & _BitFields) == 0x07;
}

inline bool CATPolyCell::IsObserverSuspended () const
{
  return BitObserverSuspended & _BitFields ? true : false;
}

inline void CATPolyCell::SuspendObserver ()
{
  _BitFields |= BitObserverSuspended;
}

inline void CATPolyCell::ResumeObserver ()
{
  _BitFields &= ~BitObserverSuspended;
}

inline void CATPolyCell::SetCellTag (unsigned int tag)
{
  _CellTag = tag;
}

inline bool CATPolyCell::HasAnyOrbit () const
{
  return (BitOrbit2 | BitOrbit3) & _BitFields;
}

template<>
inline bool CATPolyCell::MatchingType<CATPolyDart2> () const
{
  return (BitOrbit2 & _BitFields) || !(BitOrbit3 & _BitFields);
}

template<>
inline bool CATPolyCell::MatchingType<CATPolyDart3> () const
{
  return (BitOrbit3 & _BitFields) || !(BitOrbit2 & _BitFields);
}

template<>
inline bool CATPolyCell::HasOrbits<CATPolyDart2> () const
{
  return BitOrbit2 & _BitFields;
}

template<>
inline bool CATPolyCell::HasOrbits<CATPolyDart3> () const
{
  return BitOrbit3 & _BitFields;
}

template<>
inline void CATPolyCell::SetOrbitFlag<CATPolyDart2> ()
{
  _BitFields &= ~MaskOrbits;
  _BitFields |= BitOrbit2;
}

template<>
inline void CATPolyCell::SetOrbitFlag<CATPolyDart3> ()
{
  _BitFields &= ~MaskOrbits;
  _BitFields |= BitOrbit3;
}

inline void CATPolyCell::UnsetOrbitFlag ()
{
  _BitFields &= ~MaskOrbits;
}

inline bool CATPolyCell::HasMultipleOrbits () const
{
  return HasAnyOrbit () && _Orbit.GetNext ();
}

inline const CATPolyCellOrbit* CATPolyCell::GetFirstOrbit () const
{
  return HasAnyOrbit () && _Orbit.GetCell () ? &_Orbit : 0;
}

inline CATPolyCellOrbit* CATPolyCell::GetFirstOrbit ()
{
  return HasAnyOrbit () && _Orbit.GetCell () ? &_Orbit : 0;
}

inline unsigned int CATPolyCell::DartType () const
{
  if (HasOrbits<CATPolyDart2> ())
    return 2;
  else if (HasOrbits<CATPolyDart3> ())
    return 3;
  else
    return 0;
}
