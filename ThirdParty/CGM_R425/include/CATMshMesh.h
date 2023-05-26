//==============================================================================================================
// COPYRIGHT DASSAULT SYSTEMES PROVENCE 1999
//==============================================================================================================
// CATMshMesh
//==============================================================================================================
// Creation: DNR - April -2008
//==============================================================================================================

#ifndef CATMshMesh_H
#define CATMshMesh_H

#include "CATCloudBasicResources.h"
#include "CATListOfInt.h"
#include "CATBooleanDef.h"


class ExportedByCATCloudBasicResources CATMshMesh

{

public:

  CATMshMesh();
  
  virtual ~CATMshMesh();

  virtual int GetNbTriangles (const CATBoolean iAllTriangles = TRUE) const = 0 ;

  virtual CATBoolean IsTriangleValid (const int iNoTriangle) const = 0 ;

  virtual int GetNbPoints (const CATBoolean iAllPoints = TRUE) const = 0 ;

  virtual void GetNumCoords (const int iNoPoint,
                             double    oCoords[3]) const = 0 ;

  virtual void GetNumCoords (const int   iNbPoints,
                             const int*  iNoPoints,
                             double*     &ioCoords) const = 0 ;

  virtual void GetNeighbours (const int     iNoVertex,
                              CATListOfInt &ioNoTriangles) const = 0 ;



  virtual void GetNeighbours (const int  iNoVertex1,
                              const int  iNoVertex2,
                              int       &oNoTriangle1,
                              int       &oNoTriangle2) const = 0 ;


  virtual void GetTriangle (const int   iNoTriangle,
                            int         oNoVertices[3],
                            CATBoolean &oDirect) const = 0 ;

  virtual void GetTriangle (const int iNoTriangle,
                            int       oNoVertices[3],
                            int       oNoConnexes[3]) const = 0 ;



   virtual CATBoolean GetNeighbours (const int     iNoVertex,
                                    const int     iLevel,
                                    int*          &ioLevels,
                                    CATListOfInt &ioNoVertices) const = 0 ;

  virtual void ComputeTriangleNormal (const int        iNoTriangle,
                                      double           oNormal[3],
                                      const CATBoolean iNormalize = FALSE) const = 0 ;



} ;

#endif
