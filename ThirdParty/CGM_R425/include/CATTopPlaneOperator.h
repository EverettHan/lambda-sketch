/* -*-c++-*- */
#ifndef CATTopPlaneOperator_h
#define CATTopPlaneOperator_h
//COPYRIGHT DASSAULT SYSTEMES 2004
//===================================================================
//
// Author : ALV
// Date   : 20/07/2004
// Class CATTopPlaneOperator :
// Operator offers the topological build of a plane :
//  - Through one line angle with a plane
//  - offset of a plane at a given distance,
//  - offset of a plane through a point,
//  - by rotation of a plane of an angle round an axis (axis and plane being parallel) 
//  - passing through three points,
//  - passing through two lines,
//  - passing through a point and a line,
//  - passing through a planar curve,
//  - normal to a curve at a point,
//  - tangent to a surface at a point,
//  - defined by A,B,C,D such as Ax + By + Cz = D,
//  - as mean plane of points.
//
//===================================================================

#include "CATMathDef.h"
#include "CATTopSurfaceOperator.h"
#include "BasicTopology.h"
#include "CATMathVector.h"

  /** 
  * ================== 
  * ================== 
  * ================== 
  * ================== 
  * ==================
  *
  * DO NOT USE THIS OPERATOR
  * OPERATOR IS UNDER CONSTRUCTION
  *
  * ================== 
  * ================== 
  * ================== 
  * ================== 
  * ================== 
  */

class ExportedByBasicTopology CATTopPlaneOperator :public CATTopSurfaceOperator
{
  //-------------------------------------------------------------------
  CATCGMVirtualDeclareClass(CATTopPlaneOperator);
public:
  //-------------------------------------------------------------------
  

  /**
  * Constructor. Do not use. Use <tt>CATCreateTopPlaneXXX</tt> to create an
  * <tt>CATTopPlaneOperator</tt>.
  */
  CATTopPlaneOperator(CATGeoFactory* factory, CATTopData* iTopData);

  virtual ~CATTopPlaneOperator();  

  virtual void SetNormale(const CATMathVector & NormalePlane) = 0;

  virtual void GetNormale(CATMathVector & NormalePlane) = 0;


};


ExportedByBasicTopology CATTopPlaneOperator * 
CATCreateTopPlaneByLineAngularOperator( CATGeoFactory * iFactory,
                                        CATTopData    * iTopData,
                                        CATBody       * iPlane,
                                        CATBody       * iLine,
                                        CATAngle        iAngle);

/*
ExportedByBasicTopology CATTopPlaneOperator * 
CATCreatePlaneOffset( CATGeoFactory * Factory,
                      CATTopData    * iTopData,
                      CATBody       * iPlane,
                      CATLength       iOffset);

ExportedByBasicTopology CATTopPlaneOperator * 
CATCreatePlaneOffset( CATGeoFactory * Factory,
                      CATTopData    * iTopData,
                      CATBody       * iPlane,
                      CATBody       * iPoint);

ExportedByBasicTopology CATTopPlaneOperator * 
CreatePlaneRotation(CATGeoFactory * Factory,
                    CATTopData* iTopData,
                    CATBody * iPlane,
                    CATBody * iAxis,
                    CATAngle * iAngle);

ExportedByBasicTopology CATTopPlaneOperator * 
CreatePlaneByPoints(CATGeoFactory * Factory,
                    CATTopData* iTopData,
                    CATBody * iPoint1,
                    CATBody * iPoint2,
                    CATBody * iPoint3);

ExportedByBasicTopology CATTopPlaneOperator * 
CreatePlaneByLines(CATGeoFactory * Factory,
                   CATTopData* iTopData,
                   CATBody * iLine1,
                   CATBody * iLine2);

ExportedByBasicTopology CATTopPlaneOperator * 
CreatePlaneByPointLine(CATGeoFactory * Factory,
                       CATTopData* iTopData,
                       CATBody * iPoint,
                       CATBody * iLine);

ExportedByBasicTopology CATTopPlaneOperator * 
CreatePlaneByPlanarCurve(CATGeoFactory * Factory,
                         CATTopData* iTopData,
                         CATBody * iWire);

ExportedByBasicTopology CATTopPlaneOperator * 
CreatePlaneNrmlToCrvPnt(CATGeoFactory * Factory,
                        CATTopData* iTopData,
                        CATBody * iCurve,
                        CATBody * iPoint);

ExportedByBasicTopology CATTopPlaneOperator * 
CreatePlaneTngtToSurPnt(CATGeoFactory * Factory,
                        CATTopData* iTopData,
                        CATBody * iSurface,
                        CATBody * iPoint);

ExportedByBasicTopology CATTopPlaneOperator * 
CreatePlaneEquation(CATGeoFactory * Factory,
                    CATTopData* iTopData,
                    CATLength iA, CATLength iB, CATLength iC, CATLength iD);

ExportedByBasicTopology CATTopPlaneOperator * 
CreateMeanPlaneByPoints(CATGeoFactory * Factory,
                        CATTopData* iTopData,
                        CATBody * iPoints);

// old style with a journal
ExportedByBasicTopology CATTopPlaneOperator * CreatePlaneOffset(CATGeoFactory * Factory,
                                                                CATBody * iPlane,
                                                                CATLength iOffset,
                                                                CATCGMJournalList * Report=NULL);

ExportedByBasicTopology CATTopPlaneOperator * CreatePlaneOffset(CATGeoFactory * Factory,
                                                                CATBody * iPlane,
                                                                CATBody * iPoint,
                                                                CATCGMJournalList * Report=NULL);

ExportedByBasicTopology CATTopPlaneOperator * CreatePlaneRotation(CATGeoFactory * Factory,
                                                                  CATBody * iPlane,
                                                                  CATBody * iAxis,
                                                                  CATAngle * iAngle,
                                                                  CATCGMJournalList * Report=NULL);

ExportedByBasicTopology CATTopPlaneOperator * CreatePlaneByPoints(CATGeoFactory * Factory,
                                                                  CATBody * iPoint1,
                                                                  CATBody * iPoint2,
                                                                  CATBody * iPoint3,
                                                                  CATCGMJournalList * Report=NULL);

ExportedByBasicTopology CATTopPlaneOperator * CreatePlaneByLines(CATGeoFactory * Factory,
                                                                 CATBody * iLine1,
                                                                 CATBody * iLine2,
                                                                 CATCGMJournalList * Report=NULL);

ExportedByBasicTopology CATTopPlaneOperator * CreatePlaneByPointLine(CATGeoFactory * Factory,
                                                                     CATBody * iPoint,
                                                                     CATBody * iLine,
                                                                     CATCGMJournalList * Report=NULL);

ExportedByBasicTopology CATTopPlaneOperator * CreatePlaneByPlanarCurve(CATGeoFactory * Factory,
                                                                       CATBody * iWire,
                                                                       CATCGMJournalList * Report=NULL);

ExportedByBasicTopology CATTopPlaneOperator * CreatePlaneNrmlToCrvPnt(CATGeoFactory * Factory,
                                                                      CATBody * iCurve,
                                                                      CATBody * iPoint,
                                                                      CATCGMJournalList * Report=NULL);

ExportedByBasicTopology CATTopPlaneOperator * CreatePlaneTngtToSurPnt(CATGeoFactory * Factory,
                                                                      CATBody * iSurface,
                                                                      CATBody * iPoint,
                                                                      CATCGMJournalList * Report=NULL);

ExportedByBasicTopology CATTopPlaneOperator * CreatePlaneEquation(CATGeoFactory * Factory,
                                                                  CATLength iA, CATLength iB, CATLength iC, CATLength iD,
                                                                  CATCGMJournalList * Report=NULL);

ExportedByBasicTopology CATTopPlaneOperator * CreateMeanPlaneByPoints(CATGeoFactory * Factory,
                                                                   CATBody * iPoints,
                                                                   CATCGMJournalList * Report=NULL);

*/

#endif
