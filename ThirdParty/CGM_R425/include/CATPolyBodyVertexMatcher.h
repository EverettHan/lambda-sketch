//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2019
//=============================================================================
//
// CATPolyBodyVertexMatcher
//
// Finds vertex matching between two CATPolyBodies
//
//=============================================================================
// 2019-01-24 JXO: New.
// 2019-06-13 JXO: Full impl
//=============================================================================
#ifndef CATPolyBodyVertexMatcher_H
#define CATPolyBodyVertexMatcher_H

#include "PolyBodyBVHOperators.h"

// Poly math
#include "CATSetOfPtr.h"
#include "CATMapOfPtrToPtr.h"

// System
#include "CATBoolean.h"
#include "CATErrorDef.h"

class CATPolyBody;
class CATPolyVertex;
class CATMathTransformation;

/**
 * This class finds vertex matching between two CATPolyBodies
 */
class ExportedByPolyBodyBVHOperators CATPolyBodyVertexMatcher
{

public:

  CATPolyBodyVertexMatcher ();
  ~CATPolyBodyVertexMatcher ();

public:
  class ExportedByPolyBodyBVHOperators Observer
  {
  public:
    /** 
     * Called each time two matching vertices are found.
     */
    virtual void Match (const CATPolyBody& iPolyBody1, const CATPolyVertex& iPolyVertex1,
                        const CATPolyBody& iPolyBody2, const CATPolyVertex& iPolyVertex2) = 0;

  protected:
    Observer(){}
    ~Observer(){}
  };

/** @name Main Method
    @{ */

    /**
    * Finds vertex matching between two CATPolyBodies
    * @return
    *         S_OK: All vertices from body 1 have at least one match, all vertices from body 2 have at least one match.
    *         S_FALSE: At least one vertex has no match.
    *         E_FAIL: unrecoverable error.
    */
  HRESULT Run(CATPolyBody& iPolyBody1, const CATMathTransformation * pos1,
              CATPolyBody& iPolyBody2, const CATMathTransformation * pos2,
              double iTol = -1.,
              Observer * obs = 0);

  /**
  * Finds vertex matching between two CATPolyBodies.
  * This method generates and update a map of the poly bodies to accelators, for a faster run each time it is called.
  * This means the CATPolyBody must not be modified nor deleted as long as the operator is called.
  * @return
  *         S_OK: All vertices from body 1 have at least one match, all vertices from body 2 have at least one match.
  *         S_FALSE: At least one vertex has no match.
  *         E_FAIL: unrecoverable error.
  */
  HRESULT MultiRun(CATPolyBody& iPolyBody1, const CATMathTransformation * pos1,
                   CATPolyBody& iPolyBody2, const CATMathTransformation * pos2,
                   double iTol = -1.,
                   Observer * obs = 0);

  /** @} */

  class ExportedByPolyBodyBVHOperators ListObserver : public Observer
  {
  public:
    /**
     * After the Run on the operator:
     * ilistOfVertices1 will contain the CATPolyVertex from iPolyBody1 that have matches in iPolyBody2
     * ilistOfVertices2 will contain the CATPolyVertex from iPolyBody2 that have matches in iPolyBody1
     */
    ListObserver(const CATPolyBody& iPolyBody1, const CATPolyBody& iPolyBody2, CATSetOfPtr & ilistOfVertices1, CATSetOfPtr & ilistOfVertices2);
    ~ListObserver(){}
    /** 
     * Called each time two matching vertices are found.
     */
    void Match (const CATPolyBody& iPolyBody1, const CATPolyVertex& iPolyVertex1,
                const CATPolyBody& iPolyBody2, const CATPolyVertex& iPolyVertex2);

    /** Will contain the CATPolyVertex from iPolyBody1 that have matches in iPolyBody2 */
    CATSetOfPtr & m_listOfVertices1;
    /** Will contain the CATPolyVertex from iPolyBody2 that have matches in iPolyBody1 */
    CATSetOfPtr & m_listOfVertices2;

    /**
     * Little helper that takes a percentage tolerance as input.
     * Returns TRUE if more than iPercentage vertices are similar.
     * @param percentage, between 0 and 1 (0.8 means 80%)
     */
    CATBoolean AreSimilar(double iPercentage);

  private:
    int m_nbvertices1;
    int m_nbvertices2;
  };

private:
  CATMapOfPtrToPtr m_mapofBodiesToAccelerators;
};


#endif // !CATPolyBodyVertexMatcher_H
