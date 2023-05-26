// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyVisuContext
//
//===================================================================
// 2009-11-04   JXO
//      * New
// 2011-07-08   JXO
//      * Visu context is now ref counted
//===================================================================
#ifndef CATPolyBodyVisuContext_H
#define CATPolyBodyVisuContext_H

#include "PolyVisuBVH.h"

// Poly Interfaces
#include "CATPolyRefCounted.h"

// Poly Math
#include "CATMapOfPtrToPtr.h"
#include "CATMapOfPtrToInt.h"

// Poly Model
#include "CATPolyBody.h"

// Poly Visu
#include "CATPolyBodyRepAdapter.h"
class CATPolyUVRefiner;

// System
#define MULTITHREADEDCONTEXT
#ifdef MULTITHREADEDCONTEXT
#include "CATMutex.h"
#include "CATWaitingPoint.h"
#include "CATPolySetOfMutex.h"
#endif

/**
 * Class to manage links between Reps and PolyBody in multi-instances context.
 * This class builds polybodies with the @CATPolyBodyRepAdapter and links them
 * to the reps. Life cicle of this object should be equal to the transaction
 * (for example a bunch of Sections, Clashes and so on)
 * Be careful not to abuse it. If a context is shared between computations and if
 * representations have been deleted in the mean time, results could be unexpected.
 * ******************************************************************************
 * This class may be used in a multithreaded context. Several threads may be
 * using one instance of this class.
 * Note that several threads using several instances of this class may lead to
 * problems.
 * ******************************************************************************
 */
class ExportedByPolyVisuBVH CATPolyBodyVisuContext : public CATPolyRefCounted
{
public:
  CATPolyBodyVisuContext();

public:
  /**
   * Returned polybody to be released by caller, with @ReleaseAssociatedPolyBody.
   * Polybody is constructed the first time, not the next times.
   * Note that iCellTypes has no effect as soon as polybody is constructed the first time.
   */
  CATPolyBody * GetPolyBody(CATRep& iRep, int iCellTypes = CATPolyBodyRepAdapter::eFace | 
                                                           CATPolyBodyRepAdapter::eEdge | 
                                                           CATPolyBodyRepAdapter::eVertex);
  /**
   * On a given rep, ReleaseAssociatedPolyBody should be called as many times as GetPolyBody.
   * Last ReleaseAssociatedPolyBody will cause polybody to be deleted.
   */
  void ReleaseAssociatedPolyBody(CATRep& iRep);

  /**
   * Returned polybody to be deleted by caller, with regular delete. This polybody is actually
   * NOT added to the context.
   */
  static CATPolyBody * GetStaticPolyBody(CATRep& iRep, int iCellTypes = CATPolyBodyRepAdapter::eFace | 
                                                                        CATPolyBodyRepAdapter::eEdge | 
                                                                        CATPolyBodyRepAdapter::eVertex);


protected:
  CATPolyBody * GetNewPolyBody(CATRep& iRep, int iCellTypes = CATPolyBodyRepAdapter::eFace | 
                                                              CATPolyBodyRepAdapter::eEdge | 
                                                              CATPolyBodyRepAdapter::eVertex) const;

  ~CATPolyBodyVisuContext();

private:
  CATMapOfPtrToPtr _MapOfRepToPolyBodies;
  CATMapOfPtrToInt _MapOfRefCount;
  CATPolyUVRefiner * _uvrefiner;
#ifdef MULTITHREADEDCONTEXT
  CATMutex _mutMaps;
  CATPolySetOfMutex _mutBuild;

  static CATMutex & GetStaticBuildMutex();
#endif

};

#endif

