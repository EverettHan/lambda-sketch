//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2018
//=============================================================================
// Oct. 2018   Creation                                                     DPS
//-----------------------------------------------------------------------------
//
// Virtual extensible class for CATTopologicalFill operator (and derivations)
// in order to take advantage of the delegation mechanism for polyhedral bodies
//
//=============================================================================
#ifndef CATExtTopFill_h
#define CATExtTopFill_h

#include "CATExtTopOperator.h"      // Derivation
#include "FrFTopologicalOpeLight.h" // ExportedBy

#include "ListPOfCATBody.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATEdge.h"
#include "CATListOfInt.h"
#include "CATListOfDouble.h"

#include "CATIACGMLevel.h"

class CATTopologicalFill; // Master CATTopOperator defined in CATTopologicalFillLight.h
class CATBody;
class CATShell;
class CATVertex;


//=============================================================================
/** @nodoc @nocgmitf (do not create any specific interface) */

class ExportedByFrFTopologicalOpeLight CATExtTopFill : public CATExtTopOperator
{
public:

  //============================
  // Destructor
  //============================

  virtual ~CATExtTopFill();


  //=============================================================================
  // static method under study, do not use yet
  // Retrieve the specific operator extension as a CATExtTopFill pointer, from the CATTopologicalFill master operator
  // in order to avoid to make the cast in the caller code, in another module or FW,
  // this request answer depending directly on the implementation of the CATTopologicalFill constructors which build this extension on the fly or not !
  //=============================================================================
  static CATExtTopFill * GetTopFillExtensible(const CATTopologicalFill & iControlledExclusiveOwnerTopOper);


  //============================
  // Settings
  //============================

 /**
  * @nodoc
  */
  virtual void SetBody(CATBody * iBody, CATShell * iShell) = 0;

  // Define the continuity with supports
  virtual void SetWiresAndSupports(const ListPOfCATBody & iListOfWires, const ListPOfCATBody & iListOfSupports, const CATListOfInt & iListOfWiresCont) = 0;

  virtual void SetEdgesAndFaces(const ListPOfCATEdge & iListOfEdges, const ListPOfCATFace  & iListOfFaces, const CATListOfInt & iListOfEdgesCont) = 0;


 /**
  * @param  iTolValue
  * the required maximum tolerance on the result surface with iTolerance
  * Must be consistent with the tolerant modeler range [ ResolutionForLengthTest (== 0.001mm in NS), LargeResolutionForLengthTest (== 0.1mm in NS) ]
  */
  virtual void SetMaxGapTolValue(double iTolValue) = 0;

 /**
  * @nodoc
  * Defines whether the computed topology must be linked to the inputs (<tt>ADVANCED mode</tt>).
  * @param iSharedTopology
  * The option value.
  * <br><b>Legal values</b>: 
  * <dl><dt><tt>FALSE</tt></dt><dd> if the computed topology is not linked to the input bodies. This
  * is the default value. 
  * <dt><tt>TRUE</tt></dt><dd> if the computed topology is linked to the input bodies, and the smart
  * mechanism applies. 
  * </dl>
  */
  virtual void SetSmartBehavior(CATBoolean iSharedTopology) = 0;

 /**
  * Activates the flat face mode.
  * In this mode, a planar face is created if the hole being filled is flat.
  * @param iFlatMode
  * The flat mode.
  * <br><b>Legal values</b>: 
  * <dl><dt>TRUE</dt><dd> to activate the flat face mode.
  * <dt>FALSE</dt><dd> to deactivate the flat face mode.
  *</dl>
  */
  virtual void SetFlatFaceMode(CATBoolean iFlatMode) = 0;

 /**
  * @nodoc
  * Enables operator to recognize canonic forms and return a canonic surface. 
  */
  virtual void SetCanonicalDetection(CATBoolean iCanonicalMode) = 0;


 /**
  *@nodoc
  * Checks whether holes must be detected in the input wires (<tt>ADVANCED mode</tt>).
  * Only available if the type of fill is analytic 
  * @param iMode
  * The validation mode.
  * <br><b>Legal values</b>: <tt>1</tt> to check the inputs, <tt>0</tt> for no check (default mode).
  */
  virtual void SetInputValidationMode(CATLONG32 iMode = 1) = 0;

 /**
  * @nodoc
  * Only available if the type of fill is analytic 
  * Set the Simplify option. Only available in FreeStyle.
  * Default value is TRUE, i.e. the operator will never try
  * to simplify the geometry in input.
  */
  virtual void SetSimplifyOption(CATBoolean iSimplify=TRUE) = 0;

 /** 
  * @param iListOfInnerWires
  * The list of pointers to wire bodies representing the inner wire.
  * @param iListOfInnerSupports
  * The list of pointers to shell bodies representing the supports associated with the wire bodies.
  * If a  wire  body has no support, the corresponding element of <tt> iListOfSupports</tt> must be
  * set to <tt> NULL</tt>.  
  * @param iListOfInnerContinuities
  * The list of the continuity criteria associated with the wire bodies.
  * The continuity criteria
  * <br><b>Legal values</b>: <tt>0</tt> for G0 continuity (default mode), <tt>1</tt> for G1 continuity,
  * or <tt>2</tt> for G2 continuity.
  */
  virtual void AddInnerWires(const CATLISTP(CATBody) & iListOfInnerWires, const CATLISTP(CATBody) & iListOfInnerSupports, const CATListOfInt & iListOfInnerContinuities) = 0;

 /** 
  * Sets a list of passing curves. The resulting fill surface must pass by the passing curves,
  * but the passing curves do not belong to the resulting topology. In particular, a passing curve
  * is not a boundary of the fill surface.  
  * @param iListOfWires
  * The list of bodies (wires) representing the passing curves.
  */
  virtual void SetPassingCurves(const CATLISTP(CATBody) & iListOfWires, const CATListOfDouble & iCrvTolerances) = 0;

 /** 
  * Sets a list of passing points. The fill result must pass through these points.   
  * @param iListOfVertices  
  * The list  of pointers to vertex bodies representing the passing points.  
  */
  virtual void SetPassingPoints(const CATLISTP(CATBody) & iListOfVertices, const CATListOfDouble & iPtTolerances) = 0;


 /** 
  * @nodoc
  * Sets a list of cutting wires
  */
  virtual void SetCuttingWires(const CATLISTP(CATBody) & iListOfWires) = 0;

 /**
  * @nodoc
  * if the type of fill is analytic: 
  * Defines the center point inside the hole to fill (<tt>ADVANCED mode</tt>).
  * <br>The fill algorithm fills the hole with four sided faces. In case of not four sided input holes,
  * this method defines a center point allowing the algorithm to create four sided faces. 
  * otherwise Defines a passing point for the fill surface 
  * @param iCenterPoint
  * The vertex representing the center point.
	*/
  virtual void SetCenterPoint(CATVertex * iCenterPoint) = 0;


  //==================================
  // Run dedicated to polyhedral data
  //==================================

  virtual int RunPolyOperator() = 0;



protected:

  //============================
  // Constructor
  //============================

  CATExtTopFill();


  //============================
  // Poly/Exact Config Management 
  //============================

  virtual CATBoolean Is_PolyInputs_Allowed() = 0;

};

#endif
