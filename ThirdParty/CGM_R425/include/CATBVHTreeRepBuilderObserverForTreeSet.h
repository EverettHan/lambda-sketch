// COPYRIGHT DASSAULT SYSTEMES 2015, ALL RIGHTS RESERVED.
//===================================================================
//
// CATBVHTreeRepBuilderObserver
//
//===================================================================
// 2015-03-03   JXO
//      * New
// 2019-02-01   JXO, SetEditMode callbacks for IR 645509
//===================================================================
#ifndef CATBVHTreeRepBuilderObserverForTreeSet_H
#define CATBVHTreeRepBuilderObserverForTreeSet_H

// Poly
#include "CATBVHTreeRepBuilderObserver.h"
#include "CATPolyVisuBVHTreeSet.h"
#include "CATMapOfPtrToPtr.h"
#include "CATMapOfIntToPtr.h"
class CATBVHTreeRepBuilderEventSubscriber;

// Visu
class CATRepCallbackManager;
class CATRep;
class CATVizVertexBuffer;

// System
#include "CATNotification.h"
#include "CATEventSubscriberTypedefs.h"
#include "CATBoolean.h"

#define BVHTREESETNUMBEROFCALLBACKS   14
#define INDEXFORSURFACICREP           0
#define INDEXFORVIZVERTEXBUFFER       1
#define INDEXFORVIZUV3D               2
#define INDEXFOR3DCURVEPIPE           3
#define INDEXFOR3DCURVE               4
#define INDEXFOR3DCYLINDER            5
#define INDEXFOR3DCUSTOM              6
#define INDEXFOR3DLINE                7
#define INDEXFOR3DPLAN                8
#define INDEXFOR3DPOINT               9
#define INDEXFORMONOWIRE              10
#define INDEXFORVIZMONOWIRE           11
#define INDEXFORSURFACICEDITMODE      12
#define INDEXFOR3DCANONICALREP        13


class CATBVHTreeRepBuilderObserverForTreeSet : public CATBVHTreeRepBuilderObserver
{
public:
  /** Constructor */
  CATBVHTreeRepBuilderObserverForTreeSet(CATPolyVisuBVHTreeSet & iBVTReeSet);
  /** Destructor */
  ~CATBVHTreeRepBuilderObserverForTreeSet();
  /** Notify that a terminal node has been created on this ternimal rep */
  void AddTerminalRepNode(CATBVHNode * iNode, CATRep * iRep, const CAT4x4Matrix * iMat);

  /** Sets the current bvh tree set id being constructed */
  void SetCurrentId(int id) { m_currentid = id; }

public:
  void RepDestroyed(CATRep * iRep);
  void VizVertexBufferDestroyed(CATVizVertexBuffer * iBuffer);
  void RemoveTree(int id);
  void RefreshBuffer(CATRep & iRep);
  void RepModified(CATRep * iRep);

private:
  CATVizVertexBuffer * GetVizVertexBuffer(CATRep & iRep);
  void RemoveRepFromTree(int treeid, void * iRep);
  void RemoveBufferFromTree(int treeid, void * iBuffer);
  void SwapBuffer(int treeid, void * iBuffer, void * iNewBuffer);

private:
  CATPolyVisuBVHTreeSet & m_bvhtreeset;
  int m_currentid;
  CATMapOfPtrToPtr m_mapofRepsToIds;
  CATMapOfIntToPtr m_mapofIdsToReps;
  CATMapOfPtrToPtr m_mapofBuffersToIds;
  CATMapOfIntToPtr m_mapofIdsToBuffers;
  CATMapOfPtrToPtr m_mapofBuffersToReps;
  CATMapOfPtrToPtr m_mapofRepsToBuffers;

  // Callbacks
  CATBVHTreeRepBuilderEventSubscriber * m_sub;
  CATRepCallbackManager * m_callbackmanager;
  CATCallback m_CBs[BVHTREESETNUMBEROFCALLBACKS];
public:
  CATBoolean m_okbvhtreeset;
};

#endif
