#ifndef CATTopologicalFillLight_H
#define CATTopologicalFillLight_H

// COPYRIGHT DASSAULT SYSTEMES  1999


#include "FrFTopologicalOpeLight.h"
#include "CreateTopologicalFillLight.h"
#include "CATMathDef.h"
#include "CATTopOperator.h"
#include "CATSkillValue.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATBody.h"
#include "CATTopologicalFillType.h"

class CATVertex;
class CATShell;
class CATEdge;
class CATMathPoint;

#define MigrDataFill

/**
*  ***********************************************************************
*  *******                         WARNING                         *******
*  ***********************************************************************
*  *******
*  *******  This class is Not supported any longer.
*  *******  it has been replaced by CATICGMTopologicalFillLight
*  *******
*  *******
*  ***********************************************************************
*  ***********************************************************************
*
*   CATTopologicalFillLight  class has been removed from CAA in 3DEXPERIENCE level and
*  has been replaced by CATICGMTopologicalFillLight.
*  We recommend you to use only CATICGMTopologicalFillLight, in order you will  be
*  able to easily migrate your CAA code from  V5 to 3DEXPERIENCE level.
*
*  **************************************************************************
* Class defining the topological operator that fills a space defined by a set of wires.
* <br> The wires must define a closed area.
* Continuity criteria can be precised: G0, G1 if the supporting surfaces of the wire
* are given, G0 otherwise. The supporting surfaces must be coherent to allow the operator to
* compute a G1 continuity.
* <br>The CATTopologicalFill operator creates the resulting filling skin body
* separately from the inputs: the wires of the input bodies are not used to define the topology
* of the resulting fill body.  
*<ul>
* <li>A CATTopologicalFill operator is created with the <tt>CreateTopologicalFill</tt> global function.
* It must be directly deleted with the usual C++ <tt>delete</tt> operator. It is is not streamable. 
*<li>Options can be precised with the <tt>SetXxx</tt> methods, before
* asking for the computation with the <tt>Run</tt> method 
*<li>The result is accessed with the <tt>GetResult</tt> method. If you do not want 
* to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
* geometric factory. Although several sucessive 
* <tt>Run</tt>s with different inputs
* are possible, it is strongly recommended to <tt>Run</tt> it only once.
* <li>The journal corresponding to the fill operation is not yet implemented.
*</ul>
*/
class ExportedByFrFTopologicalOpeLight CATTopologicalFill 
:public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATTopologicalFill);
public :

/**
  * Defines the fill type.
  * @param    analytic
  * The edges of the domain to fill are isoparametric  curves of the final surfaces. The number
  *  of generated faces is depending on the number of wires.
  *	Use it for simple domain to fill, as rectangular area.
  * @param   power   
  * The area is filled with a single surface. This allows you to manage wires which describe 
  * a complex topology.
  * @param   powerplane  
  * The area is filled with a single surface which is obtained by deforming a plane. 
  * @param   automatic
  * Automatically determines the most suitable method according to the input topology.
  */
  enum CATFillType
  {
    analytic =           CATTopologicalFillType_analytic,
    power =              CATTopologicalFillType_power,
    automatic =          CATTopologicalFillType_automatic,
    powerfill =          CATTopologicalFillType_powerfill,
    powerplane =         CATTopologicalFillType_powerplane,
    autofillnosingular = CATTopologicalFillType_autofillnosingular,
    autofill_level1 =    CATTopologicalFillType_autofill_level1,
    autofill_level2 =    CATTopologicalFillType_autofill_level2
  };

  /** @nodoc */
  CATTopologicalFill(CATGeoFactory* iFactory, CATTopData* iTopData);
  
  /** @nodoc */
  CATTopologicalFill(CATGeoFactory* factory, CATCGMJournalList* journal=0);
  

  virtual ~CATTopologicalFill();

	/**
	 * Runs <tt>this</tt> operator (<tt>ADVANCED</tt> mode).
	 * <br>It is possible to <tt>Run</tt> the operator several times,
	 * with different parameters. After each <tt>Run</tt>, a new body is created.
	 */
  virtual int Run()=0;


 #ifdef CATIACGMV5R20
/**
* @nodoc
  * Enables operator to recognize canonic forms and return a canonic surface. 
*/
  virtual void SetCanonicalDetection();
#endif

/**
* Returns the maximum continuity gap on the result. 
  * @return
  * The value of maximum continuity gap.   
*/
  virtual double GetG0MaxDeviation ()=0;

/**
* Returns the maximum  tangency gap (in radians) on the result.
  * @return
  * The value in radians of maximum tangency gap.  
*/
  virtual CATAngle GetG1MaxDeviation()=0;


/**
* @nodoc
* Returns the maximum curvature gap on the result.
  * @return
  * The value of maximum curvature gap.   
*/
  virtual double GetG2MaxDeviation();

/**
* @nodoc
* Returns the maximum continuity gap regards to a particular edge. 
  * <br> If ioMaxPoint is not null, then it will be filled with the coordinates
* where maximum has been reached.
  * @param iEdge
  * The pointer to the edge to analyse.
  * @param ioMaxPoint
  * The pointer to an empty CATMathPoint.
  * @return
  * The value of maximum continuity gap.  
*/
  virtual double GetG0MaxDeviation (const CATEdge * iEdge,CATMathPoint * ioMaxPoint=NULL);

/**
* @nodoc
* Returns the maximum  tangency gap (in radians) regards to a particular edge.
* If ioMaxPoint is not null, then it will be filled with the coordinates
* where maximum has been reached.
  * @param iEdge
  * The pointer to the edge to analyse.
  * @param ioMaxPoint
  * The pointer to an empty CATMathPoint.
  * @return
  * The value in radians of maximum tangency gap.  
*/
  virtual CATAngle GetG1MaxDeviation(const CATEdge * iEdge,CATMathPoint * ioMaxPoint=NULL);

/**
* @nodoc
* Returns the maximum curvature gap regards to a particular edge.
* If ioMaxPoint is not null, then it will be filled with the coordinates
* where maximum has been reached.
  * @param iEdge
  * The pointer to the edge to analyse.
  * @param ioMaxPoint
  * The pointer to an empty CATMathPoint.
  * @return
  * The value of maximum curvature gap.  
*/
  virtual double GetG2MaxDeviation(const CATEdge * iEdge,CATMathPoint * ioMaxPoint=NULL);

/**
*  Returns  the maximum admissible continuity gap on the result.
  * <br> This value is computed by taking into account some incompatibilities in the input model. 
* Hence, it can be larger than the factory resolution.
  * @return
  * The value of maximum admissible continuity gap.  
*/
  virtual double GetG0MaxAccuracy()=0;

/**
  * Returns the result of <tt>this</tt> operator.
	* @return
  * The pointer to the created body. You must delete it with the @href CATICGMContainer#Remove 
	* method if you do not want to keep it. Note: in case of multiple <tt>Run</tt>s, the operator
	* deletes the intermediate bodies.
	*/
  virtual CATBody * GetResult()=0;

	/**
	 * Checks whether holes must be detected in the input wires (<tt>ADVANCED mode</tt>).
	 * @param iMode
	 * The validation mode.
  * <br><b>Legal values</b>: 
  * <dl><dt><tt>1</tt></dt><dd> to check the inputs.
  *     <dt><tt>0</tt></dt><dd> no check (default mode). </dl>
	 */
  virtual void SetInputValidationMode(const CATLONG32 iMode = 1)=0;

 
 /**
	 * Defines the continuity criteria to take into account for a given wire (<tt>ADVANCED mode</tt>).
	 * @param iWhichWire
	 * The rank (beginning at 1) of the input wire.
	 * @param iTransitionContinuity
	 * The continuity criteria
  * <br><b>Legal values</b>: 
  * <dl><dt><tt>0</tt></dt><dd> for G0 continuity (default mode).
  *     <dt><tt>1</tt></dt><dd> for G1 continuity. </dl>
	 */ 
  virtual void SetTransitionContinuity(const CATLONG32 iWhichWire, 
				       const CATLONG32 iTransitionContinuity)=0;

	
	/**
	 * @nodoc
         * Set the Simplify option. Only available in FreeStyle.
  * <br>Default value is TRUE, i.e. the operator will never try
         * to simplify the geometry in input.
	 */
  virtual void SetSimplifyOption(CATBoolean iSimplify=TRUE);


	/**
	 * @nodoc
 * Not used.
	 */
  virtual void SetTangencyParameter(const CATLONG32 iside,
				    const double iTangencyParameter)=0;

 
  /**
	 * Returns the center point inside the hole to fill.
	 * <br>The fill algorithm fills the hole with four sided faces. In case of not four sided input holes,
	 * the algorithm defines a center point allowing it to create four sided faces. This point can also
	 * be defined by the <tt>SetCenterPoint</tt> method (<tt>ADVANCED mode</tt>).
	 * @param ioCenterPoint
	 * The vertex representing the center point.
	 */
  virtual void GetCenterPoint(CATVertex &ioCenterPoint)=0;

	/**
	 * @nodoc
  * Returns if there is a center point or not.
  * @return
  * <br><b>Legal values</b>: 
  * <dl><dt><tt>TRUE</tt></dt><dd> there is a center point.
  *     <dt><tt>FALSE</tt></dt><dd> there isn't a center point. </dl>
	 */
  virtual CATBoolean IsCenterPointCreated() const;

	/**
	 * Defines the center point inside the hole to fill (<tt>ADVANCED mode</tt>).
	 * <br>The fill algorithm fills the hole with four sided faces. In case of not four sided input holes,
	 * this method defines a center point allowing the algorithm to create four sided faces. 
	 * @param iCenterPoint
	 * The vertex representing the center point.
	 */
  virtual void SetCenterPoint(CATVertex & iCenterPoint)=0;

	/**
  * Removes the defined center point.
  * The algorithm defines the default center point.
	 */
  virtual void ResetCenterPoint()=0; 

/**
 * Activates the flat face mode.
 * @param iMode
 * The flat mode.
 * <br><b>Legal values</b>: 
 * <dl><dt>1</dt><dd> to activate the flat face mode: in this case, it creates a planar face if the hole
 * to fill is flat.
 * <dt>0</dt><dd> to deactivate the flat face mode: this is the default mode.
 *</dl>
 */
  virtual void SetFlatFaceMode(const CATLONG32 iMode = 1)=0;

  /**
   * @nodoc
   * Not yet implemented.
	 * Defines whether the computed topology must be linked to the inputs (<tt>ADVANCED mode</tt>).
	 * @param iLevel
	 * The option value.
	 * <br><b>Legal values</b>: 
	 * <dl><dt><tt>0</tt></dt><dd> if the computed topology is not linked to the input bodies. This
	 * is the default value. 
	 * <dt><tt>1</tt></dt><dd> if the computed topology is linked to the input bodies, and the smart
	 * mechanism applies. 
	 * </dl>
	 */
  virtual void SetLinkedTopology(const CATLONG32 iLevel) = 0;

  
  /**
   * @nodoc
  * Asks operator to merge all topologies in a same body.
  * @param ioBody
  * The body in which to merge topologies.
  * @param ioShell
  * The shell in the body in which to merge topologies.
   */
  virtual void SetBody(CATBody * ioBody,CATShell * ioShell);

  /**
   * @nodoc
  * Asks operator to force orientation of the result face according to the orientation of the first
  * edge in the first wire. 
   */
  virtual void OrientationByFirstEdge();

  /** 
   * @nodoc
   * Sets one inner wire. An inner wire is an inner boundary of the fill result. 
   * To set N inner wires,the method AddInnerWires must be called N times. 
  * This method is not available in light operator.
   * @Param iListOfWires
   * The list of pointers to wire bodies representing the inner wire.
   * @Param iListOfSupports
   * The list of pointers to shell bodies representing the supports associated with the wire bodies.
   * if a  wire  body has no support, the corresponding element of <tt> iListOfSupports</tt> must be
   * set to <tt> NULL</tt>.  
   * @Param iListOfInnerTransitionContinuity
   * The list of the continuity criteria associated with the wires bodies.
   * The continuity criteria
   * <br><b>Legal values</b>: <tt>0</tt> for G0 continuity (default mode), <tt>1</tt> for G1 continuity.
   */ 
   virtual void AddInnerWires(ListPOfCATBody const & iListOfWires,ListPOfCATBody const & iListOfSupports,CATListOfInt & 
   iListOfInnerTransitionContinuity ) ;


  /** 
   * @nodoc
   * Sets a list of passing curves. The resulting fill surface must pass by the passing curves,
   * but the passing curves do not belong to the resulting topology. In particular a passing curve
   * is not a boundary of the fill surface.  
  * This method is not available in light operator.
   * @Param iListOfWires
   * The list of bodies (wires) representing the passing curves.
  */
  virtual void SetPassingCurves(ListPOfCATBody const & iListOfWires);


  /** 
   * @nodoc
   * Sets a list of passing points. The fill result must pass  through this points.   
  * This method is not available in light operator.
   * @Param iListOfVertices  
   * The list  of pointers to vertex bodies representing the passing points.  
   */
  virtual void SetPassingPoints (ListPOfCATBody const & iListOfVertices);

  /**
  *@nodoc
  * Sets tolerance.
  * @param  iTolerance
  * the required maximum tolerance on the result surface. 
  */
  virtual void SetGapTolerance( const double iTolerance);
  
  /**
  *@nodoc
  * Sets surface parameters.
  *@param  iDegreeU 
  * the required degree in  U of the result surface 
  * @param iDegreeV
  * the required degree in  V of the result surface 
  *@param  iNumberUOfPatch
  *the required maximum number of patches in  U of the result surface 
  *@param  iNumberVOfPatch
  * the required maximum number of patches in  V of the result surface 
  */
  virtual void SetSurfaceParameters ( int iDegreeU, int iDegreeV, int iNumberUOfPatch, int iNumberVOfPatch);
  
  /**
  *@nodoc
  * Gets surface parameters.
  *@param  oDegreeU 
  * the degree in  U of the result surface 
  * @param oDegreeV
  * the  degree in  V of the result surface 
  *@param  oNumberUOfPatch
  *the number of patches in  U of the result surface 
  *@param  oNumberVOfPatch
  * the  number of patches in V of the result surface 
  */
  virtual void GetSurfaceParameters ( int &  oDegreeU, int  & oDegreeV, int  & oNumberUOfPatch, int &  oNumberVOfPatch);

 
  /** 
  * @nodoc
  * Asks operator to check if there is a common support to all wires and to use it to compute the filled surface.
  * This method is not available in light operator.
  */
  virtual void UsingCommonSupport();
  
  /**
   * @nodoc
   * Not yet implemented.
   * Returns whether the computed topology must be linked to the inputs.
	 * @return 
	 * The option value.
	 * <br><b>Legal values</b>: 
	 * <dl><dt><tt>0</tt></dt><dd> if the computed topology is not linked to the input bodies. This
	 * is the default value. 
	 * <dt><tt>1</tt></dt><dd> if the computed topology is linked to the input bodies, and the smart
	 * mechanism applies. 
	 * </dl>
	 */
  virtual CATLONG32 GetLinkedTopology() const = 0;


  /**
   * Checks the computation.
   * @return
   * <tt>0</tt> if the computation occured without problem.
   */
  virtual CATLONG32 Check() =0;


/**
 * Returns the fill type.
 * @return
 * The fill type.
 * <br>Useful in automatic mode to know which solution was chosen.
 */
 virtual  CATFillType GetFillType () =0;

};




/**
 * @nodoc
 * Creates a topological operator that fills a closed area defined by a set of wires.
 * @param iFactory
 * The pointer to the factory that creates the resulting body.
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iNumberOfWires
 * The number of wires defining the boundary of the area to fill. 
 * @param iArrayOfWires
 * The array of pointers to the wire bodies, each containing only one wire. 
 * The set of wires must defined a closed area, 
 * and the wires must be given in the right order (but the orientation
 * of each wire is computed by the operator).
 * @param iArrayOfBodySupports
 * The array of pointers to the supporting bodies of the wires, thus allowing you to define G1 and G2 continuity
 * criteria.
 * @return
 * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
 * @see CATTopologicalFill
 */
ExportedByFrFTopologicalOpeLight
CATTopologicalFill * CATCreateTopologicalFillLight(CATGeoFactory  *iFactory,
                                                   CATTopData* iTopData,
                                                   CATLONG32 iNumberOfWires,
                                                   const CATBody**iArrayOfBodyWires,
                                                   const CATBody**iArrayOfBodySupports);

/**
 * @nodoc
 * Creates a topological operator that fills a closed area defined by a set of wires.
 * @param iFactory
 * The pointer to the factory that creates the resulting body.
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iListOfEdges
 * The list of pointers to edges of <tt>iBody</tt>. 
 * The list of edges must defined a closed area, 
 * and the edges must be given in the right order (but the orientation
 * of each edge is computed by the operator).
 * @param iListOfFaces
 * The list of pointers to the supporting faces of the edges, thus allowing you to define G1 and G2 continuity
 * criteria.
 * @param iBody
 * The pointer to the body containing the cells of <tt>iListOfEdges</tt> and <tt>iListOfFaces</tt>.
 * @return
 * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
 * @see CATTopologicalFill
 */
ExportedByFrFTopologicalOpeLight
CATTopologicalFill * CATCreateTopologicalFillLight(CATGeoFactory  *iFactory,
                                                   CATTopData* iTopData,
                                                   const ListPOfCATEdge *iListOfEdges,
                                                   const ListPOfCATFace *iListOfFaces,
                                                   const CATBody *iBody);


/**
 * @deprecated V5R14
 * Use the signature with the body supports or any other exposed function.
 */
ExportedByFrFTopologicalOpeLight
CATTopologicalFill * CATCreateTopologicalFillLight(CATGeoFactory  *iFactory,
                                                   CATTopData* iTopData,
                                                   CATLONG32 iNumberOfWires,
                                                   const CATBody **iArrayOfWires);

#endif
