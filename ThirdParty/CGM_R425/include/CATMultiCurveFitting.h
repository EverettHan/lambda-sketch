#ifndef CATMultiCurveFitting_H 
#define CATMultiCurveFitting_H 

//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2000
//=============================================================================

#include "FrFOpeCrv.h"
#include "CATCGMOperator.h"
#include "CATSkillValue.h"
#include "CATListOfCATCurves.h"
#include "CATListOfCATCrvLimits.h"
#include "CATListOfCATMathCurveFunction.h"
#include "ListVOfLong.h"
#include "CATListOfDouble.h"
#include "CATFreeFormDef.h"

class CATGeoFactory;
class CATFrFNurbsMultiForm;
class CATCurve;
class CATCrvLimits;
class CATMathInterval;
class CATCrvParam;
class CATSoftwareConfiguration;

/**
 * Class defining the operator that computes a Nurbs approximation of a set of curves.
 * The approximation is global : all the output Nurbs have the same Knot vector.
 * Each input curve can be defined as a CATCurve or as a CATMathCurveFunction.
 * The output is a CATFrFNurbsMultiForm.
 *<br>
 * This operator follows the global frame of the geometrical operators.
 * It is not streamable.
 * To use it:
 *<ul>
 * <li>Create it with the <tt>CATCreateMultiCurveFitting</tt> global function 
 * <li>Tune it with appropriate options, using the <tt>SetXxx</tt> methods 
 * <li>Run it
 * <li>Get the result with the <tt>GetResult</tt> method. 
 * <li>Delete it with the usual C++ <tt>delete</tt> operator after use.
 *</ul>  
 */

//-----------------------------------------------------------------------------
class ExportedByFrFOpeCrv CATMultiCurveFitting : public CATCGMOperator
{
public :
    
    /**
     * Runs <tt>this</tt> operator.
     */
    // virtual int Run() = 0;

    /**
    * Returns the resulting MultiForm for a given curve.
    * @param iCurveRank
    * The rank (beginning at <tt>1</tt>) of the input curve to consider.
    * @return
    * The pointer to the corresponding Multiform.
    */
    virtual CATFrFNurbsMultiForm *  GetResult(int iCurveRank) = 0;
    
    /**
    * Defines the reference curve.
    * @param iCurveRank
    * The rank <tt>(1 <=iCurveRank <= NbCurve)</tt> of the curve.
    * The default value for iCurveRank is 1, if one or more CATCurve are in the input.
    */
    virtual void SetReferenceCurve(int iCurveRank ) = 0;

    /**
    * Returns the maximum deviation between the input curves and the result.
    * @return
    * The maximum deviation value. 
    */
    virtual double GetMaxDeviation() const= 0;

    /**
    * Returns the maximum deviation for one given curve between the input curve and 
    * the resulting curve.
    * @param iCurveRank
    * The rank <tt>(1 <=iCurveRank <= NbCurve)</tt> of the Curve.
    * @return
    * The maximum deviation value. 
    */    
    virtual double GetCurveMaxDeviation(int iCurveRank) const = 0;
        
    /**
    * Defines the tolerance for one given curve.
    * @param iTolerance
    * The tolerance for one curve
    * @param iCurveRank
    * The rank <tt>(1 <=iCurveRank <= NbCurve)</tt> of the curve.
    */   
    virtual void SetTolerance(double iTolerance, int iCurveRank) = 0;
    
    /**
    * Defines the internal min length for one given curve.
    * @param iInternalMinLength
    * The internal min length for one curve
    * @param iCurveRank
    * The rank <tt>(1 <=iCurveRank <= NbCurve)</tt> of the curve.
    */   
    virtual void SetInternalMinLength(double iInternalMinLength, int iCurveRank) = 0;
    
    /**
    * @return
    * The value 1 if the transformation is exact, the value 0 otherwise. 
    */
    virtual CATLONG32 IsExactTransformation() = 0;
    
    /**
    * Sets the maximum degree of the resulting MultiForm.
    *
    * @param iMaxDegree
    * The maximum degree for the Multiform.
    * It is equal to the maximum degree for conversion, if exact conversion, and equal to 5 otherwise. 
    */    
    virtual void SetMaxDegree(int iMaxDegree ) = 0;
        
    /**
    * Sets the maximum number of Arcs for the result.
    *
    * @param iMaxArcs
    * The maximum number of Arcs.
    * The default value is 64.
    */
    virtual void SetMaxArcs(int iMaxArcs ) = 0;
    
    /**
    * Sets the rational mode for the Curve conversion
    *
    * @param AllowRational
    * If  AllowRational = 1, the output curve will be rational (default value).
    * If  AllowRational = 0, the output curve will be non rational.
    */
    virtual void SetRationalAllowed(CATLONG32 iAllowRational) = 0;

    /**
    * Maps a parameter on the initial curve to the corresponding parameter 
    * on the result curve.
    *
    * @param iParamOnCurve
    * The parameter on the initial curve.
    * @param iCurveRank
    * The rank (beginning at <tt>1</tt>) of the curve.
    * @return
    * The parameter on the result curve.
    */
    virtual double GetEquivalentParam(const CATCrvParam & iParamOnCurve, int iCurveRank) = 0;

    /**
    * @nodoc
    * Maps a parameter on the initial curve to the corresponding parameter 
    * on the result curve.
    *
    * @param iParamOnCurve
    * The parameter on the initial curve.
    * @param iCurveRank
    * The rank (beginning at <tt>1</tt>) of the curve.
    * @return
    * The parameter on the result curve.
    */
    virtual double GetEquivalentParam(double iParamOnCurve, int iCurveRank) = 0;

    /**
    * @nodoc
    *Set the list of preference cuts, ie the preferred parameters for the arc limits.
    *
    * @param iPreferenceCuts
    * The list of preferred parameters for arc limits.
    * @param iCurveRank
    * The rank (beginning at <tt>1</tt>) of the curve.
    */
    virtual void SetPreferenceCuts(const CATListOfDouble & iPreferenceCuts, int iCurveRank) = 0;

  /**
  * @nodoc
  *Set the list of Mandatory cuts, ie the Mandatory parameters for the arc limits.
  *
  * @param iMandatoryCuts
  * The list of Mandatory parameters for arc limits.
  * @param iCurveRank
  * The rank (beginning at <tt>1</tt>) of the curve.
  */
  virtual void SetMandatoryCuts(const CATListOfDouble & iMandatoryCuts, int iCurveRank) = 0;

    /**
    * @nodoc
    *Set the internal continuity of the result.
    *The default value is CATFrFCurvatureCont.
    *Legal values: CATFrFPointCont (ie the result curves are C0).
    *              CATFrFTangentCont (ie the result curves are C1).
    *              CATFrFCurvatureCont (ie the result curves are C2).
    *
    *Warning: C0 or C1 curves can only be used for internal purpose.
    *         It is illegal to have a persistent non-C2 CATCurve in a
    *         CATIA Model.
    *
    * @param iInternalContinuity
    * The internal continuity of the result.
    */
    virtual void SetInternalContinuity(CATFrFContinuity iInternalContinuity) = 0;
    /**
  * @nodoc
  * Sets the continuity constraint at the extremities of the curve.
  * @param iSideContinuity
  * The continuity constraint.
    * <tt>CATFrFTangentCont</tt> : Tangent continuity. 
  * <tt>CATFrFCurvatureCont</tt> : Curvature continuity.
  */
    virtual void SetSideContinuity(CATFrFContinuity iInternalContinuity) = 0;

    virtual ~CATMultiCurveFitting();

    
  protected :
      
      CATMultiCurveFitting(CATGeoFactory *iFactory);
      
  private :
      
CATMultiCurveFitting();
CATMultiCurveFitting(const CATMultiCurveFitting &);
void operator = (const CATMultiCurveFitting &);
      
};


/**
 * Creates the operator from two sets of curves: one list of CATCurve and one list of CATMathCurveFunction.
 * One and only one of these lists can be empty.
 *
 * @param iFactory
 * The pointer to the geometry factory.
 *
 *@param iSoftwareConfiguration
 *The pointer to the software configuration
 *
 * @param iTolerance
 * The tolerance of approximation.
 *
 * @param iListOfCATCurves
 * The list of CATCurve.
 *
 * @param iListOfCATCrvLimits
 * The list of CATCrvLimits to take into account for the CATCurve contained in iListOfCATCurves.
 *
 * @param iListOfCATMathCurveFunctions
 * The list of CATMathCurveFunction.
 *
 * @param iListOfLimits
 * The list of limits to take into account for the CATCurve contained in iListOfCATMathCurveFunctions.
 * Size: 2 * size of iListOfCATMathCurveFunctions.
 * Ordered: { start for curve 1, end for curve 1, start for curve 2, ... }.
 *
 * @param iListOrientation
 * The list of orientations for curves contained in iListOfCATCurves and for curves contained in iListOfCATMathCurveFunctions.
 * Size: size of iListOfCATCurves + size of iListOfCATMathCurveFunctions. 
 * Legal values: 1 for the same orientation as the input reference curve
 *              -1 for the opposite orientation with respect to the input reference curve
 *
 * @param iMode
 * The mode of use.
 *
 * @return
 * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator afer use.
 */
ExportedByFrFOpeCrv
CATMultiCurveFitting * CATCreateMultiCurveFitting (       CATGeoFactory                 * iFactory,
                                                          CATSoftwareConfiguration      * iSoftwareConfiguration,
                                                          double                          iTolerance, 
                                                   const CATLISTP(CATCurve)             & iListOfCATCurves,
                                                   const CATLISTP(CATCrvLimits)         & iListOfCATCrvLimits,
                                                   const CATLISTP(CATMathCurveFunction) & iListOfCATMathCurveFunctions,
                                                   const CATListOfDouble                & iListOfLimits,
                                                   const CATListOfLong                  & iListOrientation,
                                                         CATSkillValue                    iMode = BASIC);

#endif



