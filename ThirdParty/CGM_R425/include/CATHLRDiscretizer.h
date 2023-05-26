/* -*-C++-*-*/
#ifndef CATHLRDiscretizer_H
#define CATHLRDiscretizer_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLRDiscretizer 
//
// DESCRIPTION :
/**
* Object that performs the discretization fo a part of CATHLRCurve.
* <BR> Use the method GetPoints to read the array of results.
* <BR> NOTE : The same object can be used many times.
*/
//
//=============================================================================
// Abstract Class     : No
// Inline Functions   : No
//=============================================================================
//
// History
//
// Jan. 98 JCH Creation            
// Sep. 99 HKL Donner acces aux parametres utilises pour discretiser
//
//=============================================================================

#include "CATDataType.h"
// For Windows NT
#include "HLRGeometry.h"
#include "CATTolerance.h"

class CATSoftwareConfiguration;
class CATCrvParam;
class CATHLRCurve;

class ExportedByHLRGeometry CATHLRDiscretizer
{
public:

  //=============================================================================
  // CONSTRUCTORS AND DESTRUCTOR
  //=============================================================================
  /**
  * Deprecated Default constructor
  */
  CATHLRDiscretizer();

  /**
  * Mandatory constructor with contextual iTol 
  * Please use a CATGeoFactory CATTolerance by CATGetTolerance(GeoFactory)) else CATGetDefaultTolerance()
  */
  CATHLRDiscretizer(const CATTolerance &iTol, CATSoftwareConfiguration * ipConfig=NULL);

  /**
  * Destructor
  */
  ~CATHLRDiscretizer();

  //=============================================================================
  // METHODS
  //=============================================================================
  /** Discretize a curve between the given parameters
  */
  void Discretize(CATHLRCurve       * iCurve,
    const CATCrvParam & iStartParam,
    const CATCrvParam & iEndParam);

  /** Gets the number of points of the discretization
  */
  inline CATLONG32 GetCountPoints() const;

  /** Gets the array of double that defines the discretization
  */
  inline double * GetArrayPoints() const;

  /** Gets the array of coordinates as an array of float
  */
  float * GetFloatPoints();

  /** Gets the array ofparameters used
  */
  inline double * GetParameters();

  /** Gets the parameter of sampling point
  */
  int LocateParameter(int          iSampplingIndex,
    CATCrvParam &oParam);


  //=============================================================================
  // INTERNAL DATAS
  //=============================================================================
protected:

  // Tolerance for XScale
  const CATTolerance & _ClientTol;

  // Array of the coordinates of the points
  double  * _ArrayCoordinates;

  // Array of parameters
  double  * _ArrayParameters;

  // Size allocated (unit is 3 double)
  int      _Allocated;

  // Number of points used
  int      _CountPoints;

  // Array of float
  float  * _ArrayFloat;

  // Size allocated for the float array
  int      _FloatAllocated;

  CATHLRCurve * _Curve;

  short  _LevelConfig;
};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================
inline CATLONG32 CATHLRDiscretizer::GetCountPoints() const
{
  return _CountPoints;
}

inline double * CATHLRDiscretizer::GetArrayPoints() const
{
  return _ArrayCoordinates;
}

inline double * CATHLRDiscretizer::GetParameters()
{
  return _ArrayParameters;
}

#endif
