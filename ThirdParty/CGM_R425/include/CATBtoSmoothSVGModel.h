//====================================================================
// Copyright Dassault Systemes Provence 2014, all rights reserved 
//====================================================================
//
//====================================================================
//
// Usage notes:
//
//====================================================================
//  Dec 2014    : ANR : Creation 
//====================================================================
#ifndef CATBtoSmoothSVGModel_H
#define CATBtoSmoothSVGModel_H

#include "CATBtoSmoothing.h"
#include "CATPGMBtoSmoothSVGModel.h"

#include "CATGeoFactory.h"
#include "CATMathSetOfPointsND.h"
#include "CATMathVector.h" 
#include "CATListOfInt.h"
#include "CATCldScan.h"

#include "CATBody.h" 
#include "ListPOfCATBody.h" 
 
class CATSoftwareConfiguration;
class CATTopData;
class CATFrFSmoothingOperCx2 ;
class CATBody;

/**
 * Class defining a geometric operator that convert a set of Controles points (representing a C0, C1 or C2 curves ) to create a Bezier, B-spline C2 result.
 * <br>The CATBtoSmoothSVGModel operator follows the global frame of the geometric operators: 
 *<ul>
 * <li>A CATBtoSmoothSVGModel operator is created with the <tt>CATBtoCreateSmoothSVGModel</tt> global method 
 * and must be directly <tt>delete</tt>d with the usual C++ delete operator after use.
 * It is is not streamable. 
 *<li>Options can be precised with the <tt>SetXxx</tt> methods, before
 * asking for the computation with the <tt>Run</tt> method. 
 *<li>In both cases, the result is accessed with the <tt>Getxxx</tt> methods. 
 *</ul>
 */
class ExportedByCATBtoSmoothing CATBtoSmoothSVGModel : public CATPGMBtoSmoothSVGModel
{
public :
  
  //---------------
  //  Constructor !
  //---------------
  CATBtoSmoothSVGModel (CATGeoFactory            * iFactory,
                        CATSoftwareConfiguration * iConfig,
                        int                        iOrder,
                        int                        iNbOfPoints,
                        CATMathPoint             * iTabOfCtrlPoints);

  ~CATBtoSmoothSVGModel (); 
  
  /**
  * Runs <tt>this</tt> operator .
  */ 
  int Run () ;

   
  // 1 Mode Exact
  // 2 Mode C2 (Nurbs Catia )
  // 3 Mode Simplify 
  void setModeConversion(const int iMode=2) ;


  /**
  * Defines the degree of the resulting curve.
  * @param iDegree
  * The degree value for each curve (iDegree >= (iOrder-1)).
  */
  void SetDegree (const int iDegree=5);
  
  /**
  * Defines the maximum number of arcs of the created curve ( Use In Simplfy Mode : not yet implemented ).
  * @param iMaxNumberOfArcs
  * The maximum number of arcs of each created curve 
  * @param iInternalContinuity
  * The Internal continuity of each created curve, iInternalContinuity = 2, 3, 4.
  */
  void SetMaxNumberOfArcs (int iMaxNumberOfArcs = 64);
   
  /**
  * Defines the Tolerance of the result ( Use In Simplfy Mode : not yet implemented) . 
  * @param iTol3d
  * The maximum distance between the input points and the SetOfCurves. 
  */
  virtual void SetTolerance (const double iTol3d  = 0.1 ); 

  // ===========================================================================================
  //
  // ***************************** Les Fonctions Get ***************************** 
  //
  // ===========================================================================================

  /**
  * Returns the SetOfCurves Result.  
  * List Of body result according to G1 discontinuities detected 
  */
   
  void GetResult (CATLISTP(CATBody) &oBodiesResult) ;
   

private: 

  void RunExact                  (CATGeoFactory* piGeomFactory, CATSoftwareConfiguration * pConfig, CATTopData &topdata,
                                  int iNbOfPoints, CATMathPoint *iTabOfCtrlPoints, int iOrder, CATBody *&oResultBody) ;

  void RunC1ToC2                 (CATGeoFactory* piGeomFactory, CATSoftwareConfiguration * pConfig, CATTopData &topdata,
                                  int iNbOfPoints, CATMathPoint *iTabOfCtrlPoints, int iOrder, CATLISTP(CATBody) &oListOfBodyResult) ;

  CATGeoFactory            * _Factory ;
  CATSoftwareConfiguration * _Config  ;
  CATTopData               * _TopData ;
    
  int                        _Order ;
  int                        _NbOfCtrPts ;
  CATMathPoint             * _TabOfCtrlPoints ; 

  int                        _Degree ;
  double                     _TolLiss ;
  int                        _MaxOfArcs ;
  CATLISTP(CATBody)          _ListOfBodyResult ;
//CATFrFSmoothingOperCx2   * _Operator ;


  CATBoolean                _ModeConversion ;
};

/**
* Creates the operator that smoothes a set of Controles points to create a Set of Body.
* @param iFactory
* The pointer to the factory of the geometry.
* @param iOrder
* The ??? = 4 .
* @param iNbOfPoints
* The number of Controles points (multiple of iOrder).
* @param iTabOfCtrlPoints
* The pointer to the set of Controles points (Its dimension=3).
* @return
* The pointer to the created operator. To <tt>delete</tt> with the usual C++ delete operator afer use.
*/

ExportedByCATBtoSmoothing 
CATBtoSmoothSVGModel * CATBtoCreateSmoothSVGModel (CATGeoFactory            * iFactory   ,
                                                   CATSoftwareConfiguration * iConfig    ,
                                                   int                        iOrder     ,
                                                   int                        iNbOfPoints,
                                                   CATMathPoint             * iTabOfCtrlPoints);

#endif


