/* -*-C++-*-*/
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2004
//=============================================================================
// CATDistanceMaxBodyBody :
//=============================================================================
//=============================================================================
// Apr 04  Creation                          OAU
//=============================================================================
/* @fullreview AAD OAU 04:04:04
*/
#ifndef CATDistanceMaxBodyBody_h
#define CATDistanceMaxBodyBody_h

// COPYRIGHT DASSAULT SYSTEMES  2004


#include "AnalysisTools.h"
#include "CATTopOperator.h"
#include "CATHybDef.h"
#include "CATMathPoint.h"
#include "CATMathDef.h"


/**
 * Creates an operator for computing the maximum normal distance from body1 to body2.
 * The input surfaces (or volume) must be G1 continuous.
 * You must SetInitializationPoints, this set of MathPoint is approximated, as computed on the tesselation of the two surfaces,
 * then reconverged on the exact geometries.
 * If reconvergence on exact geometries fails, we keep the approximate distance but computed on the exact geometries.
 * To use the operator:
 * <ul><li>Create it with the <tt>CATCreateDistanceMaxTopo</tt> global function,
 * <li>Set parameters to tune its use,
 * <li>Run the operator ,
 * <li>Retrieve the results with the <tt>Get</tt> methods, 
 * <li><tt>delete</tt> it after use with the usual C++ <tt>delete</tt> operator.
 * </ul>
 */
class ExportedByAnalysisTools CATDistanceMaxBodyBody : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATDistanceMaxBodyBody);
  protected :

    CATDistanceMaxBodyBody(CATGeoFactory  *iFactory,CATTopData * iData,
                           CATBody        *iBody1,
                           CATBody        *iBody2);
  public :
     ~CATDistanceMaxBodyBody();     

	//-----------------------------------------------------------------------------
	//  Settings
	//-----------------------------------------------------------------------------
	virtual void SetInitializationPoints(const CATMathPoint &iPoint1, const CATMathPoint &iPoint2) = 0;
		

    //-------------------------------------------------------------------------
    // Result Access
    //-------------------------------------------------------------------------

	/**
	* Returns the computed maximum distance between the two bodies.
	* @return
	* The maximum distance. If the distance could not be computed, returns <tt>-1</tt>.
	*/
    virtual double  GetDistance() = 0;

	/**
	* Returns the points realizing the maximum distance .
	* @param oPoint1
	* The CATMathPoint to the point on the first body.
	* @param oPoint2
	* The CATMathPoint to the point on the second body.
	*/
    virtual void    GetMathPoints(CATMathPoint &oPoint1, CATMathPoint &oPoint2) = 0;

  
  protected:

    // Private Data
    CATBody                 *_Body1;
    CATBody                 *_Body2;
    CATGeoFactory           *_Factory;
    CATMathPoint            _InitPoint1;
    CATMathPoint            _InitPoint2;
    CATMathPoint            _ResultPoint1;
    CATMathPoint            _ResultPoint2;
	CATCell					*_SupportCell1;
	CATCell					*_SupportCell2;
    double                  _Distance;

};
#endif










