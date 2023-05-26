#ifndef CATTopCrvToNurbsCrvOperator_h
#define CATTopCrvToNurbsCrvOperator_h

//COPYRIGHT DASSAULT SYSTEMES 2000

/**
 * @required Protected
 * @usage U1
 */ 
#include "CATIACGMLevel.h"

#include "CATTopOperator.h"
#include "BasicTopology.h"
#include "CATCGMJournal.h"

class CATCell;
class CATSurface;
class CATGeometry;
class CATEdge;
#include "ListPOfCATEdge.h"
#include "CATFreeFormDef.h"

/**
* Class defining a topological operator that converts the geometry of an edge into a NURBS curve.
* This operator follows the general scheme of the topological operators
* <ul>
*<li> Create the operator with the global function <tt>CATCreateTopCrvToNurbsCrvOperator</tt>, which defines
* the edge to transform using a wire body
*<li> Set the parameters
*<li> Run
*<li> Get the resulting body
*<li> Delete the operator with the usual C++ <tt>delete</tt> operator.
*</ul>
*/

class ExportedByBasicTopology CATTopCrvToNurbsCrvOperator : public CATTopOperator
{
  
  //-------------------------------------------------------------------
  CATCGMVirtualDeclareClass(CATTopCrvToNurbsCrvOperator);
public:
  //-------------------------------------------------------------------
  
  /**
  * @nodoc
  * Constructor. Do not use. Use <tt>CATCreateTopCrvToNurbsCrvOperator</tt> to create an
  * <tt>CATTopCrvToNurbsCrvOperator</tt>.
  */
  CATTopCrvToNurbsCrvOperator(CATGeoFactory* iFactory, CATTopData* iTopData);

  /**
  * @nodoc
  * Constructor. Do not use. Use <tt>CATCreateTopCrvToNurbsCrvOperator</tt> to create an
  * <tt>CATTopCrvToNurbsCrvOperator</tt>.
  */
  CATTopCrvToNurbsCrvOperator(CATGeoFactory* iFactory, CATCGMJournalList* iJournal=0);

  virtual ~CATTopCrvToNurbsCrvOperator();
  
  //
  // ADVANCED mode settings
  //-----------------------
  //
  // The following setting methods follow the creation of a CATTopCrvToNurbsCrvOperator,
  // (see CATCreateTopCrvToNurbsCrvOperator global function)
  //
  
  /**
  * Defines the fitting tolerance.
  * @param iTolerance
  * The tolerance value. By default, set to the factory resolution.
  * @return
  * Not null in case of error.
  */
  virtual CATLONG32 SetTolerance(double iTolerance)=0;
  
  /**
  * Defines the maximum degree for the created NURBS.
  * @param iMaxDegree
  * The maximum degree allowed for the created NURBS curve.
  * In case of both <tt>SetMaxDegree</tt> and <tt>SetMaxArcs</tt> methods are used, the
  * priority is given to the maximum degree.
  * Default value is 5.
  * @return
  * Not null in case of error. 
  */
  virtual CATLONG32 SetMaxDegree(CATLONG32 iMaxDegree)=0;
  
  /**
  * Defines the maximum number of arcs allowed for the NURBS curve.
  * @param iMaxArcs
  * The maximum number of arcs allowed for the NURBS curve.
  * In case of both <tt>SetMaxDegree</tt> and <tt>SetMaxArcs</tt> methods are used, 
  * the priority is given to the maximum degree.
  * Default value is 3.
  * @return
  * Not null in case of error.
  */
  virtual CATLONG32 SetMaxArcs(CATLONG32 iMaxArcs)=0;
  
  /**
  * Defines whether the resulting curve must be defined as a PCurve or not.
  * @param iOutputDimension
  * The dimension of the output curve.
  * <br><b>Legal values</b>: <tt>TRUE</tt> to force the created curve to be a NURBS curve (and not a PNurbsCurve), 
  * <tt>FALSE</tt> (default value) to force the created curve to be a PNurbs curve. 
  * If the resulting curve must be PCurve, a surface must be defined using the <tt>SetSurface</tt> method.
  * @return
  * Not null in case of error.
  */
  virtual CATLONG32 Set3DOutputDimension(CATBoolean i3DOutputDimension)=0;

  /**
  * Defines the underlying surface on which the PCurves must be computed.
  * <br>In case of <tt>iOutputDimension = FALSE</tt> in the <tt>Set3DOutputDimension</tt> method.
  * @param iSurface
  * The pointer to the surface.
  * @return
  * Not null in case of error.
  */
  virtual CATLONG32 SetSurface(CATSurface* iSurface)=0;

  /**
  * Defines whether the resulting curve is rational. 
  * @param iRationalAbility
  * <br><b>Legal values</b>:
  * <tt>0</tt> to convert the curve to a non rational curve, <tt>1</tt>
  * to convert the curve to a rational curve.
  * Some canonic curves are transformed into rational CATNurbsCurve,
  * but setting <tt>iRationalAbility = 0</tt> forces the conversion to a non rational curve.
  * The default mode is the conversion into rational (equivalent to <tt>iRationalAbility = 1</tt>).
  * @return
  * Not null in case of error.
  */
  virtual CATLONG32 SetRationalAbility(CATLONG32 iRationalAbility)=0;

  /**
  * @nodoc
  * Checks whether input geometry <tt>iEdgeCell</tt> verifies (or not) the constraints
  * defined by the SetMaxDegree, SetMaxArcs methods.
  * @param oMatchConstraints 
  * oMatchConstraints 1 if all constraints are verified on input cell geometry
  * oMatchConstraints 0 if any constraint is not verified.
  * MatchConstraints() method may be called before of after the Run() call.
  * @return
  * Not null in case of error.
  */
  virtual CATLONG32 MatchConstraints(CATLONG32& ioMatchConstraints)=0;

  /**
  * Retrieves whether the created curve has been approximated.
  * <br>To be called after the <tt>Run</tt> method.
  * @param ioIsExact
  * <tt>0</tt> if there is an approximation, not null otherwise.
  * @return
  * Not null in case of error.
  */
  virtual CATLONG32 IsExactTransformation(CATLONG32& ioIsExact)=0;

  /** @nodoc */
  virtual CATGeometry* GetDescendant(CATGeometry* iGeometry);

  /** @nodoc */  
  virtual CATCGMJournal::Type GetJournalBodyType(CATBody* iBody);

  /**
  * @nodoc
  *Set the continuity constraint at the extremities of the curves
  *Legal values: CATFrFTangentCont (default value)
  *              CATFrFCurvatureCont 
  *
  * @param iSideContinuity
  * The continuity constraint.
  * @return
  * Not null in case of error.
  */
  virtual CATLONG32 SetSideContinuity(CATFrFContinuity iSideContinuity) = 0;

  /**
  * @nodoc
  */
  virtual CATLONG32 StoreCheckInformation() = 0;

};

//
// creation of operator (ADVANCED mode)
//-------------------------------------

/**
* Creates a topological operator to converts the geometry of an edge into a NURBS curve.
* @param iFactory
* The pointer to the factory that creates the resulting body.
* @param iTopData
* The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
* is <tt>NULL</tt>, it is not filled. 
* @param iWireBody
* The pointer to the wire that contains the edge <tt>iEdgeCell</tt>.
* @param iEdgeCell
* The edge whose curve will be transformed into a NURBS curve.
* @return
* The pointer to the created operator. To delete with the usual <tt>delete</tt> C++ operator.
*/
ExportedByBasicTopology CATTopCrvToNurbsCrvOperator* 
CATCreateTopCrvToNurbsCrvOperator(CATGeoFactory* iFactory,
                                  CATTopData* iTopData,    
                                  CATBody* iWireBody,               
                                  CATCell* iEdgeCell);

/**
* Creates a topological operator to convert the geometry of an edge into a NURBS curve.
* @param iFactory
* The pointer to the factory that creates the resulting body.
* @param iTopData
* The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
* is <tt>NULL</tt>, it is not filled.
* @param iWireBody
* The pointer to the wire that contains the edges <tt>iEdgeList</tt>.
* @param iEdgeList
* The list of edges whose curve will be transformed into a NURBS curve.
* Notice that all the edges must belong to the wire.
* @return
* The pointer to the created operator. To delete with the usual <tt>delete</tt> C++ operator.
*/
ExportedByBasicTopology CATTopCrvToNurbsCrvOperator* 
CATCreateTopCrvToNurbsCrvOperator(CATGeoFactory* iFactory,
                                  CATTopData* iTopData,    
                                  CATBody* iWireBody, 
                                  CATLISTP(CATEdge)* iEdgeList);

#endif
