#ifndef CATGeoFilling_H
#define CATGeoFilling_H

// COPYRIGHT DASSAULT SYSTEMES  1999
#include "CATCGMOperator.h"
#include "GeoPlate.h"
#include "CATMathDef.h"
#include "CATSurface.h"
#include "CATIncompatibilityType.h"
class CATGeoFactory;
class CATCurve;
class CATPCurve;
class CATSurface;
class CATPoint;
class CATCrvLimits;
class CATPointOnSurface;
class CATNurbsSurface;
class CATSoftwareConfiguration;

/**
 * Operator that creates a surface passing through a set of curves.
 */ 
class ExportedByGeoPlate   CATGeoFilling : public CATCGMOperator
{

   CATCGMVirtualDeclareClass(CATGeoFilling);
public:
   /**
   * @nodoc
   * Constructs a CATGeoFilling operator.<br>
   * Can never be called. Use the <tt>CATCreateGeoFilling</tt> global function
   * to create a CATGeoFilling operator.
   */
   CATGeoFilling(CATGeoFactory * iGeoFactory);
   //

   ~CATGeoFilling();

   /**
   * Adds a curve as constraint to the definition of <tt>this</tt> CATGeoFilling operator.
   * @param iCurve
   * A pointer to the curve through which the surface must pass.
   * @param iIsABound
   * <b>Legal values</b>:
   * <dl><dt>1</dt><dd>The curve defines a boundary of the surface to compute.
   *     <dt>0</dt><dd>otherwise.
   * WARNING  iIsABound must be  set to 1  for all curves defining an outer boundary 
   *          iIsABound must be  set to 0  for all curves defining an inner boundary 
   *          At Level=5 only one closed boundary is allowed, others curves must be set as inner. 
   * </dl>
   * @param iLimits
   * The limitations of the curve.
   * @param iTolerance
   * The G0 tolerance.
   * If <tt>iTolerance == resolution</tt> the default tolerance is used. 
   * @return
   * The index of the corresponding constraint.
   */
   virtual int AddConstraint(const CATCurve     * iCurve,
                             const CATCrvLimits & iLimits,
                             const CATBoolean     iIsBound = 1, 
                             const double         iTolerance = 0.0 )=0;

   /**
   * Adds a curve on surface as constraint to the definition of <tt>this</tt> CATGeoFilling operator.
   * <br>The degree is automatically updated to the minimum possible value
   * depending on the constraint.
   * @param iPCurve
   * A pointer to the curve on surface through which the surface must pass.
   * @param iLimits
   * The limitations on <tt>iPCurve</tt> 
   * @param iOrder
   * The type of contact.
   * <b>Legal values</b>:
   * <dl><dt>0</dt><dd>G0.
   *     <dt>1</dt><dd>G1.
   *     <dt>2</dt><dd>G2.
   * </dl>
   * @param iIsABound
   * <b>Legal values</b>:
   * <dl><dt>1</dt><dd>The curve defines a boundary of the surface to compute.
   *     <dt>0</dt><dd>otherwise.
   * WARNING  iIsABound must be  set to 1  for all curves defining an outer boundary 
   *          iIsABound must be  set to 0  for all curves defining an inner boundary 
   *          At Level=5 only one closed boundary is allowed, others curves must be set as inner. 
   * </dl>
   * @param iTolerance
   * the G0 tolerance
   * @param iTolAngular
   * the G1 tolerance 
   * @param iTolCurvature
   * the G2 tolerance 
   * @return
   * The index of the corresponding constraint.
   * 
   * WARNING: with level option 4 the G2 absolute tolerance iTolCurvature is not take into account
   * A relative G2 tolerance defined in percent is used and its value is 5%
   *  
   */
   virtual int AddConstraint(const CATPCurve    * iPCurve,
                             const CATCrvLimits & iLimits,
                             const short          iOrder,
                             const CATBoolean     iIsBound       = 1,
                             const double         iTolG0         = 0.0,
                             const double         iTolAngular    = 0.5,
                             const double         iTolCurvature  = 0.1 ) = 0;

   /**
   * Adds a ponctual constraint to the definition of <tt>this</tt> CATGeoFilling operator.
   * @param iPoint
   * A pointer to the point through which the surface must pass.
   * @param iTolerance
   * The value of the G0 tolerance. 
   * @return
   * The index of the corresponding constraint.
   */
   virtual int AddConstraint(const CATPoint * iPoint, 
                             const double iTolerance = 0.0)=0;

   /** 
   * Sets the maximum number of spans on the resulting NUPBS surface.
   * @param iMaxNumberOfSpans
   * The value of the maximum number of spans.
   */
   virtual void  SetMaxNumberOfSpans (const int iMaxNumberOfSpans=256)=0;

   /** 
   * Sets the minimum continuity order of the resulting NUPBS surface.
   * @param iContinuity
   * The value of the minimum continuity order.
   */
   virtual void  SetContinuity (const int iContinuity=2)=0; 

   /** 
   * Sets the level option.
   * <br>This method must be called before the <tt>Run</tt> method.
   * This method has to be used for taking advantage of new improvments.
   * It can be used only for new versions.
   * @param iLevel
   * The value of the level.
   * <b>Legal values</b>:
   * <dl><dt>-1</dt><dd> Automatic (Up to Date)
   * <dl><dt>0</dt><dd>Standard and default
   * <dt>1</dt><dd>Solver improvement.
   * <dt>2</dt><dd>Cases where plane is not acceptable improvement.
   * </dl>
   * <dt>4</dt><dd>This level must be used to take advantage of G2 continuity improvements
   * </dl>
   * <dt>5</dt><dd>This level returned an error when multiples outer boundaries. 
   * </dl>
   */

   virtual void  SetLevel (const int iLevel=0)=0; 

   /**
   * Enable C2Cuttings for not Closed Boundaries 
   * Use only when iLevel=4. Inactive for others levels. 
   * Use for models older than R19SP2 to get the older behavior (SPR 558779)
   * 
   **/
   virtual void SetC2CuttingsForNotClosedBoundaries()=0;

   /**
   * Retrieves the initial plane computed from the input constraints.
   * <br>This method must be called before the <tt>Run</tt> method.
   * If the plane is not acceptable, the algorithm automatically computes another
   * initial surface. 
   * @param  oComputedPlane
   * The plane computed from input constraints. 
   * This plane has to be deleted by the interface user.
   * @param oMaxPointsAngle 
   * The maximum value of the angle between two consecutive points on a constraint
   * and their projections on the plane.  
   * @param oMaxNormalsAngle
   * The maximum value of the angle between the normals on the constraints and the plane. 
   * @return
   * The plane criterion.
   * <br><b>Legal values</b>:
   * <dl>
   * <dt><tt>2</tt><dd> if the constraints define more than one boundary constraint (at level5).   
   * <dt><tt>-1</tt><dd> if an initial surface has been given in the constructor 
   * <dt><tt> 1</tt><dd>  if the plane is acceptable 
   *(<tt>oMaxPointsAngle < 60</tt> and <tt>oMaxNormalsAngle < 69.9</tt>)
   * <dt><tt>0</tt><dd> otherwise .
   * </dl>
   */
   virtual int IsInitialPlaneAcceptable (CATPlane * & oComputedPlane, CATAngle & oMaxPointsAngle, CATAngle & oMaxNormalsAngle)=0;


   /** 
   * Sets a CATPCurve associated with a constraint.
   * @param iNumConst
   * The rank of the corresponding constraint. 
   * @param iPCurve
   * the Pcurve  associated to contraint number iNumConst 
   * @return 
   * <tt>1</tt> if the PCurve is not on the initial surface, <tt>0</tt> otherwise. 
   * The PCurve must have the same parameterization than the corresponding
   * curve constraint.
   */ 
   virtual int Link (const int iNumConst,const CATPCurve * iPCurve )=0;


   /**
   * Runs <tt>this</tt> operator.
   * This method must be called once for a given instance of CATGeoFilling Operator.
   * @return 
   * <tt>1</tt> if this method is not called once.  
   * <tt>300</tt> if there is more than one outer boundary (at level5).
   */

   virtual int Run()=0;

   /**
   * Returns the number of incompatibilities  of <tt>this</tt> CATGeoFilling operator 
   * This method must be used after the <tt>Run</tt> method. 
   */
   virtual int  GetNumberOfIncompatibilities  () const = 0;

   /**
   * Initializes the iterator of the resulting incompatibilities.
   * This method must be used after the <tt>Run</tt> method. 
   */
   virtual void BeginningIncompatibility () = 0;

   /**
   * Skips to the next incompatibility  of <tt>this</tt> CATGeoFilling operator.
   *<br>After <tt>BeginningIncompatibility/tt>, it skips to the first incompatibility 
   * @return
   * The existence of the next incompatibility.
   * <br><b>Legal values</b>:
   *<dl><dt><tt>TRUE</tt> <dd>if there is an incompatibility
   *    <dt><tt>FALSE</tt> <dd>no more incompatibility.</dl>
   * @params oNumCont1 oNumCont2
   * The numbers of constraints between which an incompatibility  exists.
   * @param oParam1
   * The parameter on constraint <tt>oNumCont1</tt> where the incompatibility is located.
   * @param oParam2
   * The parameter on constraint <tt>oNumCont2</tt> where the incompatibility is located.
   * @param oType 
   * The kind of incompatibility between the constraints <tt>oNumCont1</tt> and <tt>oNumCont2</tt>. 
   * @oValue 
   * The value of incompatibility.
   * <ul>
   *<li><tt>if oType= G0andG0Incompatible</tt>, <tt>oValue</tt> is a distance 
   * <li><tt>if oType= G0andG1Incompatible</tt>, <tt>oValue</tt> is an angle 
   * <li><tt>if oType= G1andG1Incompatible</tt>, <tt>oValue</tt> is an angle 
   * <li><tt>if oType= G2Incompatible</tt>, <tt>oValue</tt> curvature value. 
   * </ul>
   */

   virtual CATBoolean GetNextIncompatibility( int & oNumCont1,int & oNumCont2, double & oParam1, double & oParam2, 
                                              FillingIncompatibilityType & oType, double & oValue)=0;


   /**
   * Returns a pointer to the resulting Nupbs surface computed by <tt>this</tt> CATGeoFilling operator.
   */
   virtual CATNurbsSurface * GetSurface() const =0 ; 

   /**
   * Returns a pointer to the PCurve on the resulting surface corresponding to a given constraint.
   * @param iNumConst
   * The index of the constraint that must be output as a PCurve on the resulting surface.
   */
   virtual CATPCurve * GetPCurve(const int iNumConst)=0;


   /**
   * Returns a pointer to the point on surface on the resulting surface 
   * corresponding to a given constraint.
   * @param iNumConst
   * The index of the constraint that must be output as a CATPointOnSurface on the resulting surface.
   */
   virtual CATPointOnSurface * GetPointOnSurface(const int iNumConst)=0;

   /**
   * Returns the global result accuracy on the G0 constraints.
   */
   virtual double GetG0MaxDeviation() const =0;

   /**
   * Returns the global result accuracy on the G1 constraints.
   */
   virtual double GetG1MaxDeviation() const =0;

   /**
   * Returns the global result accuracy on the G2 constraints.
   */
   virtual double GetG2MaxDeviation() const =0;

   /**
   * Returns the result accuracy on a given G0 constraint.
   */
   virtual double GetG0MaxDeviation(const int iNumConst) const =0;
   /**
   * Returns the result accuracy on a given G1 constraint.
   */
   virtual double GetG1MaxDeviation(const int iNumConst) const =0; 
   /**
   * Returns the result accuracy on a given G2 constraint.
   */
   virtual double GetG2MaxDeviation(const int iNumConst) const =0;

   /**
   * to define deformation orientation 
   * this method must be used only with level >=3
   */
   virtual void SetOrientation(CATBoolean iKeepConvention=TRUE) = 0;

   /**
   In some cases, G2 constraints are not taken into account. 
   Returns a code to indicate the reason.
   * -1   the input contraints are not G2. 
   * 0  G2  is loaded   
   * 1  G2 is not loaded because  of too big slope  
   * 2  G2 is not loaed because of incompatibilities 
   * 3  G2 is not loaded because PCurves are not C2 
   * 4  G2 is not loaded because Support Surfaces are not C2. 
   */
   virtual int  G2ConstraintsLoaded( )= 0;


};

/**
* Creates a CATGeoFilling operator.
* @param iFactory
* The factory where the surface must be created.
* @param iInitialSurface
* The surface that will be deformed to compute the result. 
* Warning: the constraints must have a normal projection on the given
* initial surface.
* If <tt>NULL</tt>, the initial surface is automatically computed.
*/
ExportedByGeoPlate CATGeoFilling * CATCreateGeoFilling(CATGeoFactory           * iFactory        ,
                                                       CATSoftwareConfiguration* iSoftConfig     ,
                                                       CATSurface              * iInitialSurface = NULL);


/**
* Creates a CATGeoFilling operator.
* @param iFactory
* The factory where the surface must be created.
* @param iInitialSurface
* The surface that will be deformed to compute the result. 
* Warning: the constraints must have a normal projection on the given
* initial surface.
* If <tt>NULL</tt>, the initial surface is automatically computed.
* DEPRECATED
*/
ExportedByGeoPlate CATGeoFilling * CATCreateGeoFilling(CATGeoFactory           * iFactory        ,
                                                       CATSurface              * iInitialSurface = NULL);


#endif



















