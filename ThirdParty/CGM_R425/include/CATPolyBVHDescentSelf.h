// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBVHDescentSelf.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Aug 2009 JXO : Creation
// May 2018 F1Z : Add DiscardDifferentFaces option
// Sep 2018 JXO : GetInitCouples for multithread
// Dec 2018 F1Z : Can directly pass a CATBVHNodeConst
//===================================================================
#ifndef CATPolyBVHDescentSelf_h
#define CATPolyBVHDescentSelf_h

#include "PolyBodyBVHOperators.h"

#include "CATPolyBVHNodePairStack.h"

class CATBVHTree;
class CATBVHNodeConst;
class CATBVHNodeConst;
class CATIPolyMesh;
class CATMutex;

/**
 * Self BV/BV descent.
 */

class ExportedByPolyBodyBVHOperators CATPolyBVHDescentSelf
{
public:
  // ---------------------------------------------------------------------
  // enum for options
  // ---------------------------------------------------------------------
  enum Options
  {
    /** Discard or not identical face */ DiscardIdenticalFaces = 0x0001,
    /** Discard or not different face */ DiscardDifferentFaces = 0x0002
  };

  // ---------------------------------------------------------------------
  // Object Management
  // ---------------------------------------------------------------------
  CATPolyBVHDescentSelf(CATBVHTree & iTree                          ,
                        CATBoolean   iDiscardIdenticalFaces = FALSE ,
                        double       iCheckTolerance        = 0.    );

  CATPolyBVHDescentSelf(CATBVHTree & iTree                          ,
                        int          iOptions                       ,
                        double       iCheckTolerance        = 0.    );

  CATPolyBVHDescentSelf(CATBVHNodeConst * iRoot                      ,
                        int               iOptions                   ,
                        double            iCheckTolerance        = 0.);
  virtual ~CATPolyBVHDescentSelf ();

public:
  /**
  * This method does not compute.
  */
  CATPolyBVHNodePairStack & GetInitCouples();

  /**
  * This method actualy does the computation.
  */
  CATPolyBVHNodePairStack & GetCouples();

  /** Used in multithread context */
  void SetMutex(CATMutex * mut){m_mut = mut;}

  /** Default in constructor is FALSE */
  void DiscardValidFaces(CATBoolean m_DiscardValidFaces = TRUE);

protected:
  virtual int ProcessLeafNodes(CATBVHNodeConst * ipNode1, CATBVHNodeConst * ipNode2);
  // Different nodes:
  virtual int ContinueDescent(CATBVHNodeConst * ipNode1, CATBVHNodeConst * ipNode2, int & index1, int & index2);
  virtual int ContinueDescent(CATBVHNodeConst * ipNode, int & index);
  virtual int Choose(CATBVHNodeConst * ipNode1, CATBVHNodeConst * ipNode2);
  virtual int Break(int & status);

  int Descent(CATBVHNodeConst * pNode, int index = -1);

  // pNode1 and pNode2 are DIFFERENT
  int Descent(CATBVHNodeConst * pNode1, CATBVHNodeConst * pNode2, int index1 = -1, int index2 = -1);
  // pNode1 and pNode2 are DIFFERENT
  int DescentToFaces(CATBVHNodeConst * pNode1, CATBVHNodeConst * pNode2, int index1 = -1, int index2 = -1);
  // pNode1 and pNode2 are DIFFERENT
  int DescentInsideFaces(CATBVHNodeConst * pNode1, CATBVHNodeConst * pNode2, int index1 = -1, int index2 = -1, CATBoolean checkforBV = TRUE);



  static CATBoolean IsFace(CATBVHNodeConst & iNode);

private:
  // ---------------------------------------------------------------------
  // Attributs (private)
  // ---------------------------------------------------------------------
  // Options
        unsigned int               m_options;
        double                     m_checktolerance;

  // BVH support
        CATBVHNodeConst        *   _Root;

  // Descent variables
  const CATBVHNodeConst        *   _CurrentFaceNode1;
  const CATBVHNodeConst        *   _CurrentFaceNode2;
        int                        _currentindex1;
        int                        _currentindex2;

  // Output
        CATPolyBVHNodePairStack    _Couples;

        CATMutex               *   m_mut;
        CATBoolean                 m_DiscardValidFaces;
};

#endif // CATPolyBVHDescentSelf_H

