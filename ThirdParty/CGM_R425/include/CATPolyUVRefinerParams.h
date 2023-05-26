// COPYRIGHT DASSAULT SYSTEMES 2010, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyUVRefinerParams.h
//
//===================================================================
//
// October 2010  Creation: ndo
//===================================================================
#ifndef CATPolyUVRefinerParams_h
#define CATPolyUVRefinerParams_h

#include "PolyVizRefiners.h"
#include "CATErrorDef.h"  // HRESULT definition.
#include "CATBoolean.h"
#include "CATMathInline.h"

#include "CATPolyRefinerDefaultParams.h"
#include "CATPolyUVRefiner.h"

/**
* This class encapsulates the parameters required for refinement by the CATPolyUVRefiner.
*/
class ExportedByPolyVizRefiners CATPolyUVRefinerParams
{

public:

  /**
   * Constructor of the refinement parameters.
   * @param iRefinementType
   *   The type of refinement.
   * @param iRefinementLevelMax
   *   For adaptive refinement, the level that won't be exceeded and for uniform refinement, the level
   *   of refinement.
   * @param iSag
   *   The sag for adaptive refinement (useless for uniform refinement.)
   * By default the refinement is set in the adaptive mode.
   */
  CATPolyUVRefinerParams (CATPolyUVRefiner::RefinementType iRefinementType = CATPolyUVRefiner::eAdaptive, 
                          const unsigned int iRefinementLevelMax = CATPolyRefinerDefaultParams::GetRefinementLevelMax (),
                          const double iSag = 0.1);

  ~CATPolyUVRefinerParams ();

public:


public:

  INLINE CATPolyUVRefiner::RefinementType GetRefinementType () const;
  INLINE CATBoolean IsRefinementAdaptive () const;

  INLINE double GetSag () const;
  INLINE unsigned int GetRefinementLevel () const;

public:

  /**
   * Gets the sag. 
   * Returns <tt>S_OK</tt> if the sag is set and <tt>S_FALSE</tt> if the sag is not set.
   */
  INLINE HRESULT GetSag (double& oSag) const;

  /**
   * Gets the refinement level. 
   * Returns <tt>S_OK</tt> if the level is set and <tt>S_FALSE</tt> if the level is not set.
   */
  INLINE HRESULT GetRefinementLevel (unsigned int& oLevel) const;

  /**
   * Gets the refinement type. 
   * Returns <tt>S_OK</tt> if the level is set and <tt>S_FALSE</tt> if the level is not set.
   */
  INLINE HRESULT GetRefinementType (CATPolyUVRefiner::RefinementType& oType) const;

protected:

  CATPolyUVRefiner::RefinementType _RefinementType;
  unsigned int _RefinementLevel;
  double _Sag;

};


INLINE HRESULT CATPolyUVRefinerParams::GetSag (double& oSag) const
{
  oSag = _Sag;
  return S_OK;
}

INLINE HRESULT CATPolyUVRefinerParams::GetRefinementLevel (unsigned int& oLevel) const
{
  oLevel = _RefinementLevel;
  return S_OK;
}

INLINE HRESULT CATPolyUVRefinerParams::GetRefinementType (CATPolyUVRefiner::RefinementType& oType) const
{
  oType = _RefinementType;
  return S_OK;
}

INLINE CATPolyUVRefiner::RefinementType CATPolyUVRefinerParams::GetRefinementType () const
{
  CATPolyUVRefiner::RefinementType type = CATPolyUVRefiner::eAdaptive;
  GetRefinementType(type);
  return type;
}
INLINE CATBoolean CATPolyUVRefinerParams::IsRefinementAdaptive () const
{
  CATPolyUVRefiner::RefinementType type = CATPolyUVRefiner::eUniform;
  GetRefinementType(type);
  return type == CATPolyUVRefiner::eAdaptive;
}
INLINE double CATPolyUVRefinerParams::GetSag () const
{
  double sag = 0.;
  GetSag(sag);
  return sag;
}
INLINE unsigned int CATPolyUVRefinerParams::GetRefinementLevel () const
{
  unsigned int lev = 0;
  GetRefinementLevel(lev);
  return lev;
}

#endif
