// COPYRIGHT DASSAULT SYSTEMES  2000

#ifndef CATExtractNurbsCurve_H
#define CATExtractNurbsCurve_H


#include "CATCGMOperator.h"
#include "FrFOpeCrv.h"
#include "CATSkillValue.h"
#include "CATBoolean.h"
#include "CATNurbsCrvSpecs.h"

class CATGeoFactory;
class CATCurve;
class CATNurbsCurve;
class CATPNurbs;
class CATCrvLimits;
class CATCrvParam;
class CATFrFNurbsMultiForm;


/**
 * Class defining a geometric operator that computes an exact NURBS representation of a CATCurve.
 * <br>The resulting curve matches all the defined constraints, that are either defined by
 * the <tt>Set</tt> methods, or by a @href CATNurbsCrvSpecs instance, directly created at 
 * the operator creation and deleted at the operator deletion. 
 * The <tt>CATNurbsCrvSpecs</tt> instance contains all the parameters that can modify the
 * ability of the curve to be convertible: the ability of the output curve to be rational, to be
 * periodic, its degree, its number of arcs and its parameterization.
 * <ul>
 * <li>a CATPCurve, or
 * <li>a CATEdgeCurve whose reference curve is a CATPCurve after recursion.
 * </ul>
 * <br>The following conversions are available:
 * <ul>
 * <li>An input CATNurbsCurve or CATPNurbs is directly output if it matches the constraints:
 * the <tt>GetResult</tt> method outputs the same pointer.
 * <li>A CATCircle and CATEllipse give a rational CATNurbsCurve.
 * <li>A CATSplineCurve and CATLine give a CATNurbsCurve.
 * <li>A CATPNurbs, CATPCircle, CATPEllipse, CATPHyperbola, CATPParabola, CATPSpline, CATPLine can 
 * always be converted into a CATPNurbs,
 * that is rational for a CATPCircle, a CATPEllipse and a CATPHyperbola.
 * Moreover, if the supporting surface is a CATPlane they can also be converted into a CATNurbsCurve.
 * <li>A CATPLine can be converted in a CATNurbsCurve, if it is an iso-parametric curve that can be retrieved
 * by its supporting surface (<tt>ExtractIsopar</tt>) as a curve of an other type than a CATPLine.
 * <li>A CATEdgeCurve is converted according to its reference curve ( @href CATEdgeCurve#GetRefCurve ).
 * </ul>
 * WARNING:
 * If an input CATNurbsCurve or CATPNurbs match all the defined constraints,
 * the <tt>GetNurbsCurve</tt> or <tt>GetPNurbs</tt> methods output the same pointer.
 * The CATExtractNurbsCurve operator follows the global frame of the geometric operators: 
 *<ul>
 * <li>A CATExtractNurbsCurve operator is created with the <tt>@href CATCreateExtractNurbsCurve </tt> global method 
 * and must be directly <tt>delete</tt>d after use.
 * It is is not streamable.
 *<li>In case of <tt>BASIC</tt>
 * mode, the operation is automatically performed at the operator creation. 
 * <li>In case of <tt>ADVANCED</tt>
 * mode, the current limits of the output curve are defined by the <tt>SetLimits</tt> methods, before
 * asking for the computation with the <tt>Run</tt> method. The specifications of the conversion 
 * can also be tuned. To do that, get the <tt>@href CATNurbsCrvSpecs </tt> instance linked to the operator
 * with the <tt>GetNurbsCrvSpecs</tt>, and change the values with the corresponding methods of this object. 
 * The <tt>IsConvertible</tt> method allows you to check that the input constraints lead to a possible
 * conversion.
 *<li>In both cases, the result is accessed with the <tt>Getxxx</tt> methods. 
 *</ul>
 * If the input curve is not convertible with the specified constraints, the <tt>Run</tt> method 
 * throws an error and the <tt>GetNurbsCurve</tt> and <tt>GetPNurbs</tt> methods return a <tt>NULL</tt>
 * pointer. 
 * <br>code sample :
 *<pre>
 * CATExtractNurbsCurve * ExtractNurbsCurveOperator = CATCreateExtractNurbsCurve(piFactory,
 *                                                                               piCurveToConvert,
 *                                                                               ADVANCED);
 * CATNurbsCrvSpecs * NurbsCrvSpecs = ExtractNurbsCurveOperator->GetNurbsCrvSpecs();
 * NurbsCrvSpecs->SetRationalAbility(FALSE);
 * if (ExtractNurbsCurveOperator->IsConvertible())
 * {
 *   ExtractNurbsCurveOperator->Run();
 *   CATNurbsCurve ResultCurve = ExtractNurbsCurveOperator->GetNurbsCurve();
 * }
 * delete _ExtractNurbsCurveOperator;
 * </pre>
 */


class ExportedByFrFOpeCrv CATExtractNurbsCurve : public CATCGMOperator
{
  public:
/**
 * Destructor.
 */ 
  virtual ~CATExtractNurbsCurve();

  virtual CATNurbsCrvSpecs *GetNurbsCrvSpecs() = 0;

/**
* Defines the maximum limits on the output curve.
* @param iMaxLimits
* The maximum limits.
*/
  virtual void SetMaxLimits(const CATCrvLimits & iMaxLimits) = 0;

/**
 * Defines the current limits on the output curve.
 * @param iLimits
 * The current limits.
 */
  virtual void SetLimits(const CATCrvLimits & iLimits) = 0;

/**
 * Tests whether the input constraints lead to a possible conversion.
 * @param ioComputedDegree
 * The necessary degree value to have an available conversion. 
 * If <tt>NULL</tt>, this argument is not filled.
 * @param ioComputedArcsNb
 * The necessary number of arcs to have an available conversion. 
 * If <tt>NULL</tt>, this argument is not filled.
 * @param ioIsRational
 * The rational property of the output curve (<tt>TRUE</tt> if the output curve is rational). 
 * If <tt>NULL</tt>, this argument is not filled.
 * @param ioIsParamChanged
 * The changement of parameterization  (<tt>TRUE</tt> if the parameterization is changed). 
 * If <tt>NULL</tt>, this argument is not filled.
 * @return
 * The result of the test.
 * <br><b>Legal values</tt>: <tt>TRUE</tt> if the conversion is possible with the input constraints,
 * <tt>FALSE</tt> otherwise.
 */
  virtual CATBoolean IsConvertible(int *ioComputedDegree=NULL,
                                   int *ioComputedArcsNb=NULL,
                                   CATBoolean *ioIsRational=NULL,
                                   CATBoolean *ioIsParamChanged=NULL) = 0;
/**
 * Runs <tt>this</tt> operator (<tt>ADVANCED</tt> mode).
 */
  virtual int Run() = 0;

/**
* Returns the corresponding CATNurbsCurve, if the output dimension is 3.
* @return
* The pointer to the created CATNurbsCurve. Use the @href CATICGMContainer#Remove if you do not want
* to keep it in the geometric factory. 
* <br>Warning: If the input CATNurbsCurve matches all the defined constraints,
* the method outputs the same pointer.
*/
  virtual CATNurbsCurve *GetNurbsCurve() = 0;

/**
* Returns the corresponding CATPNurbs, if the support dimension is 2.
* @return
* The pointer to the created CATPNurbs. Use the @href CATICGMContainer#Remove if you do not want
* to keep the nurbs in the geometric factory.
* <br>Warning: If the input CATPNurbs matches all the defined constraints,
* the method outputs the same pointer.
*/
  virtual CATPNurbs *GetPNurbs() = 0;

/**
* Maps a parameter on the initial curve to the corresponding parameter on the computed NURBS representation.
* @param iParamOnCurve
* The parameter on the initial curve.
* @param ioNewCrvParam
* The parameter on the computed Nurbs representation.
*/
  virtual int GetEquivalentParam(const CATCrvParam &iParamOnCurve,
                                 CATCrvParam &ioNewCrvParam) = 0;
/**
 * @nodoc
 */
  virtual CATFrFNurbsMultiForm *GetNurbsMultiForm() = 0;

/**
 * Constructors.
 */
  protected:
  CATExtractNurbsCurve(CATGeoFactory *iFactory);
  private:
   CATExtractNurbsCurve();
   CATExtractNurbsCurve(const CATExtractNurbsCurve &);
   void operator = (const CATExtractNurbsCurve & );
};



/**
 * Creates the operator that extracts the <b>exact</b> NURBS representation of a CATCurve.
 * By default,
 * <ul>
 * <li>The current limits of the input curve are reported on the resulting curve
 * <li>The <tt>CATNurbsCrvSpecs</tt> instance has following values:
 * <dl>
 * <dt><tt>RationalAbility</tt></dt><dd>Yes: the output curve can be rational.
 * <dt><tt>PeriodicityAbility</tt></dt><dd>Yes: the output curve can be periodic 
 * <dt><tt>Degree</tt></dt><dd>No constraint on the degree.
 * <dt><tt>Arcs</tt></dt><dd>No constraint on the number of arcs.
 * <dt><tt>Support dimension</tt></dt><dd>3D: The output curve is not constraint to be on a surface
 * <dt><tt>Parameterization</tt></dt><dd>CATAutomaticParameterization: the parameterization is
 * internally defined.
 * </dl>
 *</ul>
 * @param iCurve
 * The pointer to the curve.
 * @param iMode
 * <b>Legal values</b>:
 * <dl><dt><tt>BASIC</tt> <dd>The operation is performed at the operator creation.
 *     <dt><tt>ADVANCED</tt> <dd>Use the <tt>Run</tt> method to compute the operation.</dl>
 * @return
 * The pointer to the created operator. To delete after use.
 */
CATExtractNurbsCurve *CATCreateExtractNurbsCurve(CATGeoFactory *iFactory,
                                                 CATSoftwareConfiguration * iSoftwareConfiguration, 
                                                 const CATCurve *iCurve,
                                                 CATSkillValue iMode=BASIC);

#endif
