// COPYRIGHT DASSAULT SYSTEMES 2007, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyUVRefiner.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// May 2007  Creation: ndo
//===================================================================
#ifndef CATPolyUVRefiner_h
#define CATPolyUVRefiner_h

#include "PolyVizRefiners.h"
#include "CATPolyRefCounted.h"
#include "CATIAV5Level.h"

#include "CATErrorDef.h"  // HRESULT definition.
#include "CATBoolean.h"
#include "CATDataType.h"

#include "CATPolyRefinerDefaultParams.h"
#ifdef CATIAR210
#include "CATPolyPool.h"
#else
#define NBPOLYPOOLS 16
#endif

class CATPolySurfaceRefiner;
class CATPolyCurveRefiner;


// Refinement engine for UV data.
class  ExportedByPolyVizRefiners CATPolyUVRefiner : public CATPolyRefCounted
{

public:

  enum RefinementType
  {
    eUniform = 0,
    eAdaptive
  };

  /*
   * Constructor of a UV refiner engine. 
   * Note: A Refiner should always be associated to CATPolyUVRefinerParams
   * (for example inside CATPolyBodyRepAttributes) so sag and level 
   * are not contained inside the UV Refiner engine.
   * @param iRefinementType
   *   The type of refinement.
   */
  CATPolyUVRefiner (RefinementType iRefinementType = eAdaptive);

  virtual ~CATPolyUVRefiner ();

public:

  /*
   * Returns a Curve Refiner, same for all asking threads.
   */
  inline CATPolyCurveRefiner* GetCurveRefiner ();
  /*
   * Releases a previously used Curve Refiner
   */
  void ReleaseRefiner (CATPolyCurveRefiner* i);

  /*
   * Returns a Surface Refiner, same for all asking threads.
   */
  inline CATPolySurfaceRefiner* GetSurfaceRefiner ();
  /*
   * Releases a previously used Surface Refiner
   */
  void ReleaseRefiner (CATPolySurfaceRefiner* i);
  /*
   * Returns a currently non-working Surface Refiner. Usefull for multi-thread
   */
  CATPolySurfaceRefiner* GetIdleSurfaceRefiner ();
  /*
   * Returns a currently non-working Curve Refiner. Usefull for multi-thread
   */
  CATPolyCurveRefiner* GetIdleCurveRefiner ();

public:

  inline RefinementType GetRefinementType () const;
  inline CATBoolean IsRefinementAdaptive () const;

protected:

  RefinementType _RefinementType;
  CATPolyCurveRefiner* _CurveRefiner;
  CATPolySurfaceRefiner* _SurfaceRefiner;

  // Multithread
  CATPolySurfaceRefiner * _SurfaceRefiners[NBPOLYPOOLS];
  int _refs[NBPOLYPOOLS];
  // Multithread
  CATPolyCurveRefiner * _CurveRefiners[NBPOLYPOOLS];
  int _refsc[NBPOLYPOOLS];

public:
  // Debug. Don't use
  static void * s_RefinerDebug;
#ifdef CATIAR213
    static void* s_Run;
    static void* s_PushData;
    static void* s_CopyGPU;
    static void* s_CopyCPU;
    static void* s_BuildData;
    static int s_GPUCalls;
    static int s_CPUCalls;
    static CATBoolean s_uv2;
#endif
};


inline CATPolyCurveRefiner* CATPolyUVRefiner::GetCurveRefiner ()
{
  return _CurveRefiner;
}

inline CATPolySurfaceRefiner* CATPolyUVRefiner::GetSurfaceRefiner ()
{
  return _SurfaceRefiner;
}

inline CATPolyUVRefiner::RefinementType CATPolyUVRefiner::GetRefinementType () const
{
  return _RefinementType;
}

inline CATBoolean CATPolyUVRefiner::IsRefinementAdaptive () const
{
  return _RefinementType == eAdaptive;
}

#endif
