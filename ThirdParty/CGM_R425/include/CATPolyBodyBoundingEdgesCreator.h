//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2019
//=============================================================================
//
// CATPolyBodyBoundingEdgesCreator
//
// Adds bounding edges to surfaces, if not already there.
// Note that it does not stitch adjacent faces.
//
//=============================================================================
// 2014-06-13 JXO: New.
// 2022-04 F1Z : Add observer
//=============================================================================
#ifndef CATPolyBodyBoundingEdgesCreator_H
#define CATPolyBodyBoundingEdgesCreator_H

#include "PolyBodyServices.h"

// Math
#include "CATMathConstant.h"

// System
#include "CATErrorDef.h"
#include "CATBoolean.h"

class CATPolyBody;
class CATPolyFace;
class CATPolyBodyUnaryObserver;

/**
 * Adds bounding edges to all the faces from the CATPolyBody, if not already there.
 * Note that it does not stitch adjacent faces.
 */
class ExportedByPolyBodyServices CATPolyBodyBoundingEdgesCreator
{

public:

  CATPolyBodyBoundingEdgesCreator ();
  ~CATPolyBodyBoundingEdgesCreator ();

public:
  class VertexCreator;
  
 /** @name Main Method
    @{ */

 /**
  * Adds bounding edges to all the faces from the CATPolyBody, if not already there.
  * Note that it does not stitch adjacent faces.
  * @param iBody
  *        Body for which edges have to be created.
  * @param iCreator
  *        Optional vertex creator.
  */
  HRESULT Run(CATPolyBody& iBody, VertexCreator * iCreator = 0, CATPolyBodyUnaryObserver * obs=0) const;

 /**
  * Adds bounding edges to iFace, if not already there.
  * @param iBody
  *        Body for which edges have to be created.
  * @param iFace
  *        Face for which edges have to be created.
  * @param iCreator
  *        Optional vertex creator.
  */
  HRESULT Run(CATPolyBody& iBody, CATPolyFace & iFace, VertexCreator * iCreator = 0, CATPolyBodyUnaryObserver * obs=0) const;

  /*
   * Returns a static VertexCreator that will put vertices when the angle between
   * two consecutive bars is more than iSharpAngle.
   */
  static VertexCreator & SharpAnglesVertexCreator(double iSharpAngle = CATPIBY4);

  /*
   * Returns a static VertexCreator that will put vertices when an edge becomes equal or longer than iEdgeLength
   */
  static VertexCreator & EdgeLengthVertexCreator(double iEdgeLength);

  /**
   * A little helper to position CATPolyVertex where you want.
   */
  class ExportedByPolyBodyServices VertexCreator
  {
  public:
    /** Answer TRUE if you want a CATPolyVertex to be created at this location */
    virtual CATBoolean CreateVertex(CATPolyFace & iFace, int previousVertexInLoop, int SurfaceVertex, int nextVertexInLoop,
                                    double currentEdgeLoop,
                                    double currentLoopLength) = 0;

  protected:
    VertexCreator();
    virtual ~VertexCreator();
  };

  /** Return vc1 || vc2 */
  class ExportedByPolyBodyServices Or : public VertexCreator
  {
  public:
    Or(VertexCreator & vc1, VertexCreator & vc2):m_vc1(vc1), m_vc2(vc2){}
    ~Or(){}
    CATBoolean CreateVertex(CATPolyFace & iFace, int previousVertexInLoop, int SurfaceVertex, int nextVertexInLoop,
                            double currentEdgeLoop,
                            double currentLoopLength) override;
  private:
    VertexCreator & m_vc1;
    VertexCreator & m_vc2;
  };

  /** Return vc1 && vc2 */
  class ExportedByPolyBodyServices And : public VertexCreator
  {
  public:
    And(VertexCreator & vc1, VertexCreator & vc2):m_vc1(vc1), m_vc2(vc2){}
    ~And(){}
    CATBoolean CreateVertex(CATPolyFace & iFace, int previousVertexInLoop, int SurfaceVertex, int nextVertexInLoop,
                            double currentEdgeLoop,
                            double currentLoopLength) override;
  private:
    VertexCreator & m_vc1;
    VertexCreator & m_vc2;
  };


  /** @} */
};


#endif // !CATPolyBodyBoundingEdgesCreator_H
