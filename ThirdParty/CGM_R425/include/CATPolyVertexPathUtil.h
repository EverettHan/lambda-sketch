// COPYRIGHT DASSAULT SYSTEMES 2006, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyVertexPathUtil.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// May 2006 Creation: tie
//===================================================================
#ifndef CATPolyVertexPathUtil_h
#define CATPolyVertexPathUtil_h

#include "CATPolyMCrv.h"
#include "CATListOfInt.h"
#include "CATBoolean.h"
#include "CATLISTP_CATVertexPath.h"

// To use vertex paths instead of mesh curves to speed-up healing, define this variable.
#define USE_NEW_VERTEX_PATH_CODE


class ExportedByCATPolyMCrv CATPolyVertexPathUtil 
{
public :

  /**
  * Default constructor.
  */
  CATPolyVertexPathUtil (void);

  /**
  * Destructor.
  */
  ~CATPolyVertexPathUtil (void);

  static unsigned Hash (CATListOfInt vertexPath);

  static CATBoolean GetOverlap (const CATListOfInt & vertexPath0, 
                                const CATListOfInt & vertexPath1,
                                int & index0,
                                int & index1,
                                int & rhsIndex0,
                                int & rhsIndex1);

  static CATBoolean GetDoubleOverlap (const CATListOfInt & vertexPath0, 
                                      const CATListOfInt & vertexPath1,
                                      int & index0,
                                      int & index1,
                                      int & rhsIndex0,
                                      int & rhsIndex1);

  static void MergeOverlap (CATListOfInt & vertexPath0, 
                            CATListOfInt & vertexPath1,   
                            const int index0,
                            const int index1,
                            const int rhsIndex0,
                            const int rhsIndex1);

  static void MergeDoubleOverlap (CATListOfInt & vertexPath0, 
                                  CATListOfInt & vertexPath1,       
                                  const int index0,
                                  const int index1,
                                  const int rhsIndex0,
                                  const int rhsIndex1);

  static CATBoolean BreakVertexPath (CATListOfInt & vertexPath, const CATListOfInt & breakPoints,
                                     CATListOfVertexPath & newVertexPaths);

  static  CATBoolean GetSubVertexPath (const int startIndex, 
                                       const int endIndex,
                                       CATListOfInt & vertexPath,
                                       CATListOfInt & subVertexPath);

  static CATBoolean Merge (CATListOfInt &vertexPath0, CATListOfInt &vertexPath1);

};

#endif
