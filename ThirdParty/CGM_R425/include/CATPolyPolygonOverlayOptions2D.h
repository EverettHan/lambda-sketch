
// COPYRIGHT DASSAULT SYSTEMES 2018, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPolygonOverlayOptions2D.h
//
//===================================================================
// June 2018 Creation: xxc
//===================================================================
#ifndef CATPolyPolygonOverlayOptions2D_H
#define CATPolyPolygonOverlayOptions2D_H

#include "PolygonalBoolean.h"
#include "CATErrorDef.h"   // For the definition of HRESULT.
#include "CATTolerance.h"
#include "CATLib.h"        // CATGetEnv
#include "CATPolyExactArithmetic.h"
#include "CATMathBox2D.h"

#include <algorithm>
#include <cmath>

class CATSoftwareConfiguration;
class CATPolyBarIntersector2D;
class CATPolySpatialPartition2D;
class CATPolyBentleyOttmannExactCoordinateInterface;

/**
 Options for all CATPolyPolygonOverlay operators.
 By default, the tolerant options are not activated.
 To perform tolerant operations, set the tolerance
 and activate the tolerant mode.
*/
class ExportedByPolygonalBoolean CATPolyPolygonOverlayOptions2D
{

public:

  inline CATPolyPolygonOverlayOptions2D ();

  inline CATPolyPolygonOverlayOptions2D (const CATPolyPolygonOverlayOptions2D& iRHS);

  inline CATPolyPolygonOverlayOptions2D (const CATPolyExactArithmetic* iExactArithmetic,
                                         const CATPolySpatialPartition2D* iSpatialPartition,
                                         CATPolyBarIntersector2D* iBarIntersector = 0);

  ~CATPolyPolygonOverlayOptions2D () {}

  inline CATPolyPolygonOverlayOptions2D& operator = (const CATPolyPolygonOverlayOptions2D& iRHS);

public:

/** @name Software Configuration
    @{ */

  /**
   * Sets the software configuration.
   * No AddRef is performed on the set configuration.
   * The life cycle of the set instance should be longer than the life cycle of this instance.
   */
  inline void SetSoftwareConfiguration (const CATSoftwareConfiguration* iSoftConfig);

  /**
   * Returns the software configuration.
   * Unless an AddRef is performed, the returned instance should not be released.
   */
  inline const CATSoftwareConfiguration* GetSoftwareConfiguration () const;

/** @} */

public:

/** @name Geometric Modeler Tolerance
    @{ */

  /**
   * Sets the geometric modeler tolerance.
   * For a tolerant overlay, the geometric modeler tolerance must be set.
   * It must not be set for non-tolerant overlay.
   * No AddRef is performed on the tolerance instance.
   * The life cycle of the set instance should be longer than the life
   * cycle of this instance.
   * After setting a new GM tolerance, the overlaying tolerance (see below) is
   * equal to:
   *   * The GM resolution if iGMTolerance is not null;
   *   * 0 otherwise.
   */
  inline void SetGMTolerance (const CATTolerance* iGMTolerance);

  /**
   * Returns the geometric modeler tolerance.
   * Unless an AddRef is performed, the returned instance should not be released.
   */
  inline const CATTolerance* GetGMTolerance () const;

  /**
   * Returns true for tolerant overlays and false for non-tolerant overlays.
   * The operator becomes tolerant when a CATTolerance is set.
   */
  inline bool DoTolerant () const;

  /** @} */

public:

/** @name Versionning levels access
    @{ */


  // Versions in Bar Splitter 2D
  enum SplitterLevel /*CPT : KO sur AIX : unsigned int */
  {
    eSplitter_Standard = 0,
    eSplitter_EnhancedPerformances = 1, // First performance enhancement
    eSplitter_V2 = 2, // Ordering of bar-bar contacts + performances
  };

  /** Versioning: get the level of code to use in the Bar Splitter 2D,
   * according to the CATSoftwareConfiguration.
   */
  inline SplitterLevel GetSplitterLevel() const;

  inline bool UseAdaptiveSpatialPartition () const;

/** @} */

public:

/** @name Resolution and Tolerances
    @{ */

  /**
   * Returns the geometric modeler resolution.
   * In a tolerant overlay, topological cells must be separated by at least the resolution.
   * No two cell-vertices can be closer than the resolution for instance.
   */
  inline double GetGMResolution () const;

  /**
   * Sets the overlaying tolerance.
   * This distance applies to the overlaying of faces, edges and vertices for the computation of a tolerant overlay.
   * The overlaying tolerance is the maximum distance allowable between cells from separate operands for
   * their overlaying (from one operand to the other.)
   * Topological cells closer than this distance will be considered overlapping.
   * It is always greater or equal to the geometric modeler resolution (see GetGMResolution ().)
   * It will be overriden by the geometric modeler resolution otherwise.
   * If it is not set, it will be equal by default to the geometric modeler resolution.
   * Otherwise, it should be set after setting the geometric modeler tolerance to override the
   * default value.
   */
  inline void SetOverlayingTolerance (const double dtol);

  /**
   * Returns the overlaying tolerance.
   */
  inline double GetOverlayingTolerance () const;

  /**
   * Sets the instance of exact arithmetic.
   * By default, exact arithmetic is performed in double-precision.
   */
  inline void SetExactArithmetic (const CATPolyExactArithmetic& iArithmetic);

  /**
   * Returns the instance of exact arithmetic.
   * By default, exact arithmetic is performed in double-precision.
   */
  inline const CATPolyExactArithmetic& GetExactArithmetic () const;

  /**
   * Sets the optional spatial partition.
   */
  inline void SetSpatialPartition (const CATPolySpatialPartition2D* iSpatialPartition);

  /**
   * Lets the spatial partition grid adapts its size to the number of elements.
   */
  inline void ChooseAdaptiveSpatialPartition ();

  /**
   * Gets the optional spatial partition.
   */
  inline const CATPolySpatialPartition2D* GetSpatialPartition () const;

  /**
   * Sets an optional bar intersector for custom computation of the bar intersections.
   */
  inline void SetBarIntersector (CATPolyBarIntersector2D* iBarIntersector);

  /**
   * Gets the optional bar intersector.
   */
  inline CATPolyBarIntersector2D* GetBarIntersector () const;

  /** @} */

  /**
   * Enable/disable Bentley Ottmann algorithms.
   * The algorithm will map the vertices on a grid whose pixel length is defined by tolerance
   * or length resolution (GMTolerance).
   * Works only with CATPolyExactArithmetic::eDouble.
   * BE CAREFUL partition must be set to nullptr.
   */
  bool IsBentleyOttmann() const;
  void SetBentleyOttmann(bool iEnable, double iTolerance);
  void SetBentleyOttmann(bool iEnable, CATTolerance const *ipTolerance);
  void SetBentleyOttmann(const CATMathBox2D& iBox);
  void SetBentleyOttmann(CATPolyBentleyOttmannExactCoordinateInterface &iInterface);
  CATPolyBentleyOttmannExactCoordinateInterface* GetBentleyOttmannInterface() const;

  /**
   * Enable/disable Bentley Ottmann snapping (default true).
   * REQUIRED for boolean with circle arcs.
   * CAREFUL ! 
   * If snapping is disabled result may contain auto-intersections.
   */
  void SetBentleyOttmannSnapping(bool iEnable);
  bool IsBentleyOttmannSnapping() const;

protected:

  // Tolerances for tolerant overlays.
  double _OverlayingTolerance;               // Distance tolerance (by default it is set to the resolution from GM tolerance.)
  //const double _ReclassificationOverResolution;  // Ratio between the reclassification tolerance and the resolution. By default 0.1.

  const CATSoftwareConfiguration * _SoftConfig;  // Software configuration (no AddRef/Release on this instance.)
  const CATTolerance * _GMTolerance;  // Geometric modeler tolerance (no AddRef/Release on this instance.)

  CATPolyExactArithmetic _DefaultExactArithmetic;
  const CATPolyExactArithmetic * _ExactArithmetic;
  const CATPolySpatialPartition2D * _SpatialPartition;
  CATPolyBarIntersector2D * _BarIntersector;
  CATPolyBentleyOttmannExactCoordinateInterface* _BentleyOttmannInterface;

private:

  void UpdateLevels();

  SplitterLevel _SplitterLevel;
  bool _AdaptiveSpatialPartition;
  bool _EnableBentleyOttmann;
  bool _BentleyOttmannSnapping;
};

inline CATPolyPolygonOverlayOptions2D::CATPolyPolygonOverlayOptions2D() :
  _OverlayingTolerance(0),         // Default value.
  _SoftConfig(NULL),
  _GMTolerance(NULL),
  _DefaultExactArithmetic(CATPolyExactArithmetic::eDouble),
  _ExactArithmetic(NULL),
  _SpatialPartition(NULL),
  _BarIntersector(NULL),
  _BentleyOttmannInterface(0),
  _SplitterLevel (eSplitter_Standard),
  _AdaptiveSpatialPartition (false),
  _EnableBentleyOttmann(false),
  _BentleyOttmannSnapping(true)
{
  UpdateLevels(); // For forced levels by env variable
}

inline CATPolyPolygonOverlayOptions2D::CATPolyPolygonOverlayOptions2D (const CATPolyPolygonOverlayOptions2D& iRHS) :
  _OverlayingTolerance (iRHS._OverlayingTolerance),
  _SoftConfig (iRHS._SoftConfig),    // No AddRef.
  _GMTolerance (iRHS._GMTolerance),  // No AddRef.
  _DefaultExactArithmetic(CATPolyExactArithmetic::eDouble),
  _ExactArithmetic(iRHS._ExactArithmetic),
  _SpatialPartition(iRHS._SpatialPartition),
  _BarIntersector(iRHS._BarIntersector),
  _BentleyOttmannInterface(iRHS._BentleyOttmannInterface),
  _SplitterLevel(iRHS._SplitterLevel),
  _AdaptiveSpatialPartition (iRHS._AdaptiveSpatialPartition),
  _EnableBentleyOttmann(iRHS._EnableBentleyOttmann),
  _BentleyOttmannSnapping(iRHS._BentleyOttmannSnapping)
{}

inline CATPolyPolygonOverlayOptions2D::CATPolyPolygonOverlayOptions2D (const CATPolyExactArithmetic* iExactArithmetic,
                                                                       const CATPolySpatialPartition2D* iSpatialPartition,
                                                                       CATPolyBarIntersector2D* iBarIntersector) :
  _OverlayingTolerance (0),         // Default value.
  _SoftConfig (NULL),
  _GMTolerance (NULL),
  _DefaultExactArithmetic (CATPolyExactArithmetic::eDouble),
  _ExactArithmetic (iExactArithmetic),
  _SpatialPartition (iSpatialPartition),
  _BarIntersector (iBarIntersector),
  _BentleyOttmannInterface(0),
  _SplitterLevel(eSplitter_Standard),
  _AdaptiveSpatialPartition (false),
  _EnableBentleyOttmann(false),
  _BentleyOttmannSnapping(true)
{
  UpdateLevels(); // For forced levels by env variable
}

inline CATPolyPolygonOverlayOptions2D& CATPolyPolygonOverlayOptions2D::operator = (const CATPolyPolygonOverlayOptions2D& iRHS)
{
  _OverlayingTolerance = iRHS._OverlayingTolerance;
  _SoftConfig = iRHS._SoftConfig;    // No AddRef.
  _GMTolerance = iRHS._GMTolerance;  // No AddRef.
  _ExactArithmetic = iRHS._ExactArithmetic;
  _SpatialPartition = iRHS._SpatialPartition;
  _BarIntersector = iRHS._BarIntersector;
  _BentleyOttmannInterface = iRHS._BentleyOttmannInterface;
  _SplitterLevel = iRHS._SplitterLevel;
  _AdaptiveSpatialPartition = iRHS._AdaptiveSpatialPartition;
  _EnableBentleyOttmann = iRHS._EnableBentleyOttmann;
  _BentleyOttmannSnapping = iRHS._BentleyOttmannSnapping;
  return *this;
}

inline void CATPolyPolygonOverlayOptions2D::SetSoftwareConfiguration (const CATSoftwareConfiguration* iSoftConfig)
{
  _SoftConfig = iSoftConfig;
  UpdateLevels();
}

inline const CATSoftwareConfiguration* CATPolyPolygonOverlayOptions2D::GetSoftwareConfiguration () const
{
  return _SoftConfig;
}

inline void CATPolyPolygonOverlayOptions2D::SetGMTolerance (const CATTolerance* iGMTolerance)
{
  _GMTolerance = iGMTolerance;
  _OverlayingTolerance = 0.0;
  if (_GMTolerance)
    _OverlayingTolerance = _GMTolerance->ResolutionForLengthTest ();
}

inline const CATTolerance* CATPolyPolygonOverlayOptions2D::GetGMTolerance () const
{
  return _GMTolerance;
}

inline double CATPolyPolygonOverlayOptions2D::GetGMResolution () const
{
  return _GMTolerance ? _GMTolerance->ResolutionForLengthTest () : 0;
}

inline void CATPolyPolygonOverlayOptions2D::SetOverlayingTolerance (const double dtol)
{
  if (!_GMTolerance)
    _OverlayingTolerance = 0.0;
  else if (_GMTolerance->ResolutionForLengthTest () > dtol)
    _OverlayingTolerance = _GMTolerance->ResolutionForLengthTest ();
  else
    _OverlayingTolerance = dtol;
}

inline double CATPolyPolygonOverlayOptions2D::GetOverlayingTolerance () const
{
  return _OverlayingTolerance;
}

inline void CATPolyPolygonOverlayOptions2D::SetExactArithmetic (const CATPolyExactArithmetic& iArithmetic)
{
  _ExactArithmetic = &iArithmetic;
}

inline const CATPolyExactArithmetic& CATPolyPolygonOverlayOptions2D::GetExactArithmetic () const
{
  return (_ExactArithmetic ? *_ExactArithmetic : _DefaultExactArithmetic);
}

inline void CATPolyPolygonOverlayOptions2D::SetSpatialPartition (const CATPolySpatialPartition2D * iSpatialPartition)
{
  _SpatialPartition = iSpatialPartition;
  _AdaptiveSpatialPartition = false;
}

inline void CATPolyPolygonOverlayOptions2D::ChooseAdaptiveSpatialPartition ()
{
  _SpatialPartition = 0;
  _AdaptiveSpatialPartition = true;
}

inline const CATPolySpatialPartition2D* CATPolyPolygonOverlayOptions2D::GetSpatialPartition () const
{
  return _SpatialPartition;
}

inline void CATPolyPolygonOverlayOptions2D::SetBarIntersector (CATPolyBarIntersector2D * iBarIntersector)
{
  _BarIntersector = iBarIntersector;
}

inline CATPolyBarIntersector2D* CATPolyPolygonOverlayOptions2D::GetBarIntersector () const
{
  return _BarIntersector;
}

inline bool CATPolyPolygonOverlayOptions2D::DoTolerant () const
{
  return _GMTolerance != 0;
}

inline CATPolyPolygonOverlayOptions2D::SplitterLevel CATPolyPolygonOverlayOptions2D::GetSplitterLevel() const
{
  return _SplitterLevel;
}

inline bool CATPolyPolygonOverlayOptions2D::UseAdaptiveSpatialPartition () const
{
  return _AdaptiveSpatialPartition;
}

inline bool CATPolyPolygonOverlayOptions2D::IsBentleyOttmann() const
{
  return _EnableBentleyOttmann;
}

inline void CATPolyPolygonOverlayOptions2D::SetBentleyOttmann(bool iEnable, double iTolerance)
{
  _EnableBentleyOttmann = iEnable;
  _OverlayingTolerance = iTolerance;
}

inline void CATPolyPolygonOverlayOptions2D::SetBentleyOttmann(bool iEnable, CATTolerance const* ipTolerance)
{
  _EnableBentleyOttmann = iEnable;
  SetGMTolerance(ipTolerance);
}

inline void CATPolyPolygonOverlayOptions2D::SetBentleyOttmann(const CATMathBox2D& iBox)
{
  _EnableBentleyOttmann = true;

  if (!iBox.IsEmpty())
  {
    double XMin, XMax, YMin, YMax;
    iBox.GetExtremities(XMin, XMax, YMin, YMax);
    double const maxcoord = (std::max) ((std::max)(std::fabs(XMin), std::fabs(XMax)) , (std::max)(std::fabs(YMin) , std::fabs(YMax)));
    _OverlayingTolerance = std::ldexp(maxcoord, -50);
  }
}

inline void CATPolyPolygonOverlayOptions2D::SetBentleyOttmann(CATPolyBentleyOttmannExactCoordinateInterface& iInterface)
{
  _EnableBentleyOttmann = true;
  _BentleyOttmannInterface = &iInterface;
}

inline CATPolyBentleyOttmannExactCoordinateInterface* CATPolyPolygonOverlayOptions2D::GetBentleyOttmannInterface() const
{
  return _BentleyOttmannInterface;
}

inline void CATPolyPolygonOverlayOptions2D::SetBentleyOttmannSnapping(bool iEnable)
{
  _BentleyOttmannSnapping = iEnable;
}

inline bool CATPolyPolygonOverlayOptions2D::IsBentleyOttmannSnapping() const
{
  return _BentleyOttmannSnapping;
}

#endif
