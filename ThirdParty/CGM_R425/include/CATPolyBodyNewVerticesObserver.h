//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2018, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyNewVerticesObserver
//
//===================================================================
// 12/03/18 F1Z : Creation
// DD/MM/YY
//===================================================================
#ifndef CATPolyBodyNewVerticesObserver_H
#define CATPolyBodyNewVerticesObserver_H

// Polyhedral Interfaces
#include "CATPolyRefCounted.h"
#include "CATIPolySurfaceObserver.h"
#include "CATIPolyCurveObserver.h"

// Polyhedral Objects
#include "CATPolyBody.h"

// Polyhedral Body Operators
#include "PolyBodyRegularize.h"

class CATSetOfInt;

/**
* Class which fills the poly body face surface & edge curve
* with observers to catch any new points. <br/>
* The deleted one, if the were previously catched, are removed
* from this class correctly.
*
* idFace corresponds to the face id from 1 to NbFace obtained by the
* poly body iterator. (cf. CATPolyBodyIteratorIdServices.h) If the poly body topology change, this class
* content became obsolete.
*/
class ExportedByPolyBodyRegularize CATPolyBodyNewVerticesObserver : virtual public CATPolyRefCounted
{
public:
  // -----------------------------------------------------------------
  // Object management
  // -----------------------------------------------------------------
  CATPolyBodyNewVerticesObserver(      CATPolyBody & iPolyBody                   ,
                                 const bool          iAddExistingVertices = false);
  ~CATPolyBodyNewVerticesObserver();

  // -----------------------------------------------------------------
  // Activate the observation or not
  // -----------------------------------------------------------------
  void Activate();
  void Desactivate();

  // -----------------------------------------------------------------
  // Check if a point is new or not
  // -----------------------------------------------------------------
  bool IsNewFaceVertex(const int    iIdFace  ,
                       const int    iIdVertex);

  bool IsNewEdgeVertex   (const int iIdEdge  ,
                          const int iIdVertex);

private:
  class SurfaceObserver;
  class CurveObserver;
  friend class SurfaceObserver;
  friend class CurveObserver;

  // -----------------------------------------------------------------
  // Methods (private)
  // -----------------------------------------------------------------
  void InitStructure(      CATPolyBody & iPolyBody           ,
                     const bool          iAddExistingVertices);

  // -----------------------------------------------------------------
  // Attributs (private)
  // -----------------------------------------------------------------
  CATSetOfInt * m_faceNewVertices;
  CATSetOfInt * m_edgeNewVertices;

  // surface observer
  SurfaceObserver * m_surfaceObservers;
  CurveObserver   * m_curveObservers;

  bool m_obsActive;
};

// ============================================================================== //
//                                 SurfaceObserver                                //
// ============================================================================== //
class CATPolyBodyNewVerticesObserver::SurfaceObserver : CATIPolySurfaceObserver
{
public:
  // -----------------------------------------------------------------
  // Object management
  // -----------------------------------------------------------------
  SurfaceObserver();
  ~SurfaceObserver();

  HRESULT ReactToAddVertex     (int iV);
  HRESULT PrepareToRemoveVertex(int iV);

  void Set(CATSetOfInt     * iListOfNewId,
           CATIPolySurface * iSurface    ,
           bool            * iActivateObs);

private:
  // -----------------------------------------------------------------
  // Attributs (private)
  // -----------------------------------------------------------------
  CATSetOfInt     * m_listOfNewId;
  CATIPolySurface * m_surface    ;
  bool            * m_activateObs;
};

// ============================================================================== //
//                                  CurveObserver                                 //
// ============================================================================== //
class CATPolyBodyNewVerticesObserver::CurveObserver : CATIPolyCurveObserver
{
public:
  // -----------------------------------------------------------------
  // Object management
  // -----------------------------------------------------------------
  CurveObserver();

  ~CurveObserver();

  HRESULT ReactToAppendVertex      (const CATIPolyCurve & iC    ,
                                          int             iV    );
  HRESULT ReactToSetVertexPosition (const CATIPolyCurve & iC    ,
                                          int             iV    ,
                                    const CATMathPoint  & iP    ) { return S_OK; };
  HRESULT ReactToSplitBar          (      CATIPolyCurve & iCurve,
                                          int             iCv0  ,
                                          int             iCv1  ,
                                          int             iN    );
  HRESULT PrepareToMergeVertices  (       CATIPolyCurve & iCurve,
                                          int             iCv0  ,
                                          int             iCv1  );
  HRESULT ReactToClose            (const  CATIPolyCurve & iC    ) {return S_OK; };
  HRESULT ReactToOpen             (const  CATIPolyCurve & iC    ) {return S_OK; };


  void Set(CATSetOfInt   * iListOfNewId,
           CATIPolyCurve * iCurve      ,
           bool          * iActivateObs);

private:
  // -----------------------------------------------------------------
  // Attributs (private)
  // -----------------------------------------------------------------
  CATSetOfInt   * m_listOfNewId;
  CATIPolyCurve * m_curve      ;
  bool          * m_activateObs;
};

#endif
