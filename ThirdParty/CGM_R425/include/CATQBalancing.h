// COPYRIGHT DASSAULT SYSTEMES 2000
//==========================================================================
//
// CATQBalancing:
//
//==========================================================================
//
// Usage notes:
//
//========================================================================== 
//   /07/00 CCK Creation                                                 CCK
// 08/08/14 NLD Ajout CATCreateQBalancing() avec factory et configuration
//========================================================================== 

#ifndef CATQBalancing_H
#define CATQBalancing_H

#include "FrFFitting.h"
#include "CATCGMVirtual.h"

class CATGeoFactory;
class CATSoftwareConfiguration;

//#include "CATCGMOperator.h"


/**
 * Class defining the operator to compute a new parameterization of a curve.
 * <br>The new parameterization consists in defining a new segmentation
 * such that the length difference between two consecutive arcs is not too large.
 * <pre>1/Q < (s_(i+1) - s_(i)) / (s_(i) - s_(i-1)) < Q</pre>
 * where Q is the Q-balancing coefficient (usually taken as <tt>1.5</tt>), 
 * and <tt>s_(i-1)</tt>, <tt>s_(i)</tt>, <tt>s_(i+1)</tt> are the knot values of
 * three consecutive points.
 * As any geometric operator, CATQBalancing must be called as follows:
 * <ul><li>Create it with the @href CATCreateQBalancing global method
 * <li>If needed, tune some option with the <tt>SetXxx</tt> methods
 * <li>Run it
 * <li>Gets the resulting parameterization
 * <li><tt>delete</tt> it.
 * </ul>
 */
// class ExportedByFrFFitting CATQBalancing : CATCGMOperator
class ExportedByFrFFitting CATQBalancing : public CATCGMVirtual
{
  public :

    virtual ~CATQBalancing();
    /**
     * Runs <tt>this</tt> operator.
     */
    virtual int     Run() = 0;

    /**
     * Retrieves the array of the new knot values.
     * @return
     * The array of the new knots values.
     * @param ioNbKnots
     * The size of the <tt>oKnots</tt> array.
     */
    virtual double* GetNewKnots(int& oNbKnots) = 0;

    /**
     * Returns the Q-balancing coefficient corresponding to the new knot values.
     * @return
     * The Q-balancing coefficient. May be not equal to the input coefficient.
     */
    virtual double  GetQeffective()            = 0;
    
    /**
     * Defines the number of segments between two consecutive breakpoints.
     * <br>Optional method.
     * @param iImposedNbPerInterval
     * The number of segments between two consecutive breakpoints.
     * @param ioNbOfBreakPoints
     * The size of the <tt>iImposedNbPerInterval</tt> array.
     */
    virtual void    SetNbOfSegments(int* iImposedNbPerInterval, int& ioNbOfBreakPoints) = 0;

};

#endif


/**
 * Constructs the geometric operator of Q-balancing.
 * @param iQCoeff
 * The coefficient of Q-balancing.
 * @param iKnotsInit
 * The array <tt>[iNbOfKnots]</tt> of the initial knot values. 
 * @param  iNbOfKnots
 * The size of <tt>iKnotsInit</tt>.
 * @param iBreakPointParams
 * The array <tt>[iNbOfBreakPoints]</tt> of the break points parameters.
 * A break point is a knot that must not be changed. The first and last knot values,
 * defining the first and last ends of the curve, are directly put as break points
 * by the operator.
 * @param iNbOfBreakPoints
 * The size of <tt>iBreakPointParams</tt>.
 * @return
 * The pointer to the created operator. To <tt>delete</tt> after use.
 */
//-----------------------------------------------------------------------------
ExportedByFrFFitting
CATQBalancing* CATCreateQBalancing(CATGeoFactory           * iFactory           ,
                                   CATSoftwareConfiguration* iConfig            ,
                                   double                    iQCoeff            ,
                                   double                  * iKnotsInit         ,
                                   int                       iNbOfKnots         ,
                                   double                  * iBreakPointParams  ,
                                   int                       iNbOfBreakPoints   ,
                                   int                     * iElasticBreakPtRank,
                                   int                       iNbOfElasticBreakPt,
                                   double                  * iRightDelta        ,
                                   double                  * iLeftDelta         );
// DEPRECATED use CATCreateQBalancing with factory and software configuration
ExportedByFrFFitting
CATQBalancing* CATCreateQBalancing(double                    iQCoeff            ,
                                   double                  * iKnotsInit         ,
                                   int                       iNbOfKnots         ,
                                   double                  * iBreakPointParams  ,
                                   int                       iNbOfBreakPoints   ,
                                   int                     * iElasticBreakPtRank,
                                   int                       iNbOfElasticBreakPt,
                                   double                  * iRightDelta        ,
                                   double                  * iLeftDelta         );
