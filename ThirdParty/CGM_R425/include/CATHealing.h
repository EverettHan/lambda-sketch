#ifndef CATHealing_H
#define CATHealing_H
//
// COPYRIGHT DASSAULT SYSTEMES 1999
//
//#define BaseHealing
#include "CATSurfacicTopoOperators.h"
#include "CATGeometryType.h"
#include "ListPOfCATVertex.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATFace.h"
#include "CATBaseHealing.h"
#include "CATHealingControlMode.h"
#include "CATString.h"

class CATCGMJournalList;

class CATHealingImp;
class CATGeoFactory;
class CATBody;
class CATFace;
class CATEdge;
class CATVertex;
class CATTopData;


/**
 * Class defining the topological operator that heals geometric holes and geometric tangency
 * defaults inside skin bodies.
 * <br>The principle is to create new surfaces by deforming the initial surfaces, so that the
 * the gap of the edges and if required the angle between the two surfaces are
 * reduced to a given value. Continuity objectives can be precised between
 * the surfaces. The healed body is created, using these new surfaces and 
 * sharing the non-modified geometry and topology of the initial body (smart concept).
 * The healing operator failed in case of non-manifold topology detected on an edge impacted
 * by the healing.
 * To use a CATHealing operator:
 * <ul>
 * <li> Create it with the constructor.
 * <li> Define the parameters (such as the continuity constraints) with the <tt>SetXxx</tt> methods.
 * <li> <tt>run</tt> it.
 * <li> Retrieve the created healed body with the <tt>GetResult</tt> method. Some additional
 * informations are also available with the <tt>GetXxx</tt> methods.
 * <li> <tt>delete</tt> it with the usual C++ operator after use. 
 * A CATHealing operator is not a persistent object (it is not streamable).
 * </ul>
 */

	class ExportedByCATSurfacicTopoOperators  CATHealing	: public	CATBaseHealing

//class ExportedByCATSurfacicTopoOperators  CATHealing
{

  CATCGMVirtualDeclareClass(CATHealing);
  public:

/**
  * Defines the healing control mode.
  * @param    global
  * The global continuity of the body has to be improved by the
  * healing process for a given order.
  * @param   local   
  * For a given order the continuity of each edge has to be improved by the
  * healing process (No degradation is authorized for the given order relatively 
  * to the corresponding tolerance).
  * @param   strict
  * For a given order the continuity of each edge has to be improved by the
  * healing process (No degradation is authorized for the given order relatively 
  * to a percentage of the initial default).
  */
  enum HealingControlMode {global = CATHealingControlMode_global, local = CATHealingControlMode_local, strict = CATHealingControlMode_strict};


    ~CATHealing();

/** 
 * Appends the body to heal. Can be used when the body to heal has not been
 * initialized in the constructor
 * @param iBodyToHeal
 * The Body to heal
 */
	int SetBodyToHeal(CATBody * iBodyToHeal);
 
	int Reset();
 

 /** 
 * @nodoc
 * Internal use 
 * Requires Healing Topo.
 * @param iHealingTopoOnly
 * <br><b>Legal values</b>: <tt>FALSE</tt> if geometric deformations are allowed (default value), <tt>TRUE</tt>
 * if it wasn't.
 */
	int SetWithHealingTopo(const CATBoolean iHealingTopoOnly = FALSE );

/**
 * Appends another edge to be healed.
 * @param
 * The pointer to the edge to be healed. The edge must belong to the input body.
 * @param iOrder
 * The associated continuity objective.
 * <br><b>Legal values</b>:
 * <dl>
 * <dt><tt>0</tt></dt><dd> for a G0 continuity 
 * <dt><tt>1</tt></dt><dd> for a G1 continuity 
 * </dl>
 */
	int Add(CATEdge * iE,const short iOrder);

/**
 * Appends a list of edges to be healed.
 * @param iEdgeList
 * The list of edge pointers. The edges must belong to the input body.
 * @param iOrder
 * The associated continuity objective.
 * <br><b>Legal values</b>:
 * <dl>
 * <dt><tt>0</tt></dt><dd> for a G0 continuity 
 * <dt><tt>1</tt></dt><dd> for a G1 continuity 
 * </dl>
 */
	int Add(ListPOfCATEdge &iEdgeList, const short iOrder);

/**
 * Appends a vertex to be healed.(Healing Local G0 only)
 * @param iVertexToHeal
 * The pointer to the vertex to be healed.
 * @param iEdgeToFix
 * The pointer to the edge to be fixed if needed. The vertex must belong to the edge.
 * @param iOrder
 * The associated continuity objective (G0 only).
 */
	int Add(CATVertex * iVertexToHeal, CATEdge * iEdgeToFix=0, const short iOrder=0);

/**
 * Defines the constraints on the geometry of a vertex.(Healing Local G0 only)
 * @param iVertexToFix
 * The pointer to the vertex to be fixed. Warning : a vertex to heal can not be fixed.
 * @param iEdge
 * The pointer to the edge with tangency constraint. The vertex must belong to the edge.
 * @param iOrder
 * The associated continuity objective (G1 only).
 */
	int SetVertex(CATVertex * iVertexToFix, CATEdge * iEdge, const short iOrder);

/**
 * Defines the default global continuity of <tt>this</tt> healing operator. 
 * @param iOrder
 * The default global continuity for <tt>this</tt> healing operator. This default can be overridden
 * by the <tt>Add</tt> method associated with an edge or a list of edges.
 * <br><b>Legal values</b>:
 * <dl>
 * <dt><tt>0</tt></dt><dd> for a G0 continuity 
 * <dt><tt>1</tt></dt><dd> for a G1 continuity 
 * </dl>
 */
    int SetGlobalContinuity(const short iOrder);

/**
 * Defines the global default for the G0 continuity tolerance required 
 * after healing.
 * @param iTolG0
 * The G0 continuity tolerance. By default (when the method is not called), 
 * <tt>iTolG0</tt> is set to the factory resolution.
 */
	void SetG0Tolerance ( const double iTolG0);


/** 
 * Defines the maximum G0 default for selecting the edges to be healed 
 * @param iTolG0Max
 * The G0 Maximum continuity tolerance. 
 * The healing only applies to the edges whose initial default 
 * is lower than this tolerance.
 */ 
	void SetMaxG0Tolerance ( const double iTolG0Max);	


/**
 * Defines the G0 continuity tolerance required for healing topo.
 * @param iTolHT
 * The G0 continuity tolerance. By default (when the method is not called), 
 * <tt>iTolHT</tt> is set to the usual G0 continuity tolerance (see the method SetG0Tolerance(const double iTolG0)). 
*/
	void SetG0ToleranceForHealingTopo(const double iTolHT);

/** 
 * Defines the maximum G1 default for selecting the edges to be healed 
 * for G1 healing only.
 * @param iTolAngular
 * The G1 continuity tolerance. 
 * The healing only applies to the edges whose initial default 
 * is lower than this tolerance. By default (when the method is not called), 
 * <tt>iTolAngular</tt> is set to 3 degrees. The maximum value is 5 degrees.
 */ 
	void SetMaxG1Tolerance ( const double iTolAngular);	
/**
 * Defines the global default for the G1 continuity tolerance.
 * @param iTolAngular
 * The G1 continuity tolerance in degree.
 * default value is 0.5.
 */
	void SetG1Tolerance ( const double iTolAngular );

/**
 * Defines the Sharpness tolerance.
 * @param iTolSharpness
 * The Sharpness tolerance in degree.
 * default value is 0.5.
 */
	void SetSharpnessTolerance ( const double iTolSharpness);

/**
 * Defines the maximum value allowed for a face deformation.
 * @param iMaxDef
 * if iMaxDef > 0., a deformation of face greater than iMaxDef will be refused
 * if iMaxDef = 0., the control of the deformation is assumed by the healing process
 * default value is 0.
 */
	void SetMaxShapeDeformation (const double iMaxDef);

/**
 * Defines an automatic control mode for faces deformation.
 * The healing process computes the maximum G0 gap on the whole body : MaxGapG0. 
 * Any deformation of face greater than MaxGapG0 will be refused
 * WARNING : don't use simultaneously with the method SetMaxShapeDeformation (const double iMaxDef);
 */
	void SetAutoMaxShapeDeformation ();

/** 
 * @nodoc
 * Not Yet Implemented.
 */
	void SetG2Tolerance ( const double iTolCurvature );


/**
 * Defines  the control mode for improvement of the global continuity 
 * during healing process for a given order.
 * @param iOrder
 * The order of continuity to control.
 * <br><b>Legal values</b>:
 * <dl>
 * <dt><tt>0</tt></dt><dd> for a G0 continuity 
 * <dt><tt>1</tt></dt><dd> for a G1 continuity 
 * @param iMode
 * The control mode
 * <br><b>Legal values</b>:
 * <dl>
 * <dt><tt>HealingControlMode::global</tt></dt><dd> for a global control
 * <dt><tt>HealingControlMode::local</tt></dt><dd> for a local control
 * Not Yet Implemented.
 * <dt><tt>HealingControlMode::strict</tt></dt><dd> for a strict control
 * Not Yet Implemented.
 * </dl>
 */
	void SetControlMode ( const short iOrder , 
						  const CATHealing::HealingControlMode iMode);

/**
 * Defines the constraints on the geometry of a face.
 * <br>By default
 * <ul>
 * <li>Canonical faces are not free: <tt>iIsTypeFree == FALSE</tt>, <tt>iIsGeomFree == FALSE</tt>.
 * <li>All non-canonical faces are free: <tt>iIsTypeFree == TRUE</tt>, <tt>iIsGeomFree == TRUE</tt>.
 * </ul>
 * @param iF
 * The pointer to the face.
 * @param iIsGeomFree
 * The status of the modification of the face geometry.
 * <br><b>Legal values</b>: <tt>FALSE</tt> if its geometry cannot be changed, <tt>TRUE</tt>
 * if it can.
 * @param iIsTypeFree
 * The status of the preservation of the face geometry type (if <tt>TRUE == iIsGeomFree</tt>).
 * <br><b>Legal values</b>: <tt>FALSE</tt> if the canonicity must be kept (a cylinder
 * cannot become a Nurbs surface), <tt>TRUE</tt>
 */
	int SetFace(CATFace * iF, const CATBoolean iIsGeomFree, const CATBoolean iIsTypeFree);

/**
 * Defines the constraints on the geometry of faces.
 * <br>By default
 * <ul>
 * <li>Canonical faces are not free: <tt>iIsTypeFree == FALSE</tt>, <tt>iIsGeomFree == FALSE</tt>.
 * <li>All non-canonical faces are free: <tt>iIsTypeFree == TRUE</tt>, <tt>iIsGeomFree == TRUE</tt>.
 * </ul>
 * @param iListOfFaces
 * The list of the face pointers. 
 * @param iIsGeomFree
 * The status of the modification of the face geometry.
 * <br><b>Legal values</b>: <tt>FALSE</tt> if its geometry cannot be changed, <tt>TRUE</tt>
 * if it can.
 * @param iIsTypeFree
 * The status of the preservation of the face geometry type (if <tt>TRUE == iIsGeomFree</tt>).
 * <br><b>Legal values</b>: <tt>FALSE</tt> if the canonicity must be kept (a cylinder
 * cannot become a Nurbs surface), <tt>TRUE</tt>
 */
	int SetFace(const ListPOfCATFace &iListOfFaces, 
				const CATBoolean iIsGeomFree, const CATBoolean iIsTypeFree);

/**
 * Defines the constraints on the geometry of faces of a given type.
 * <br>By default
 * <ul>
 * <li>Canonical faces are not free: <tt>iIsTypeFree == FALSE</tt>, <tt>iIsGeomFree == FALSE</tt>.
 * <li>All non-canonical faces are free: <tt>iIsTypeFree == TRUE</tt>, <tt>iIsGeomFree == TRUE</tt>.
 * </ul>
 * @param iType
 * The geometric type of the faces.
 * @param iIsGeomFree
 * The status of the modification of the face geometry.
 * <br><b>Legal values</b>: <tt>FALSE</tt> if its geometry cannot be changed, <tt>TRUE</tt>
 * if it can.
 * @param iIsTypeFree
 * The status of the preservation of the face geometry type (if <tt>TRUE == iIsGeomFree</tt>).
 * <br><b>Legal values</b>: <tt>FALSE</tt> if the canonicity must be kept (a cylinder
 * cannot become a Nurbs surface), <tt>TRUE</tt>
 */
	int SetFace(const CATGeometricType iType, const CATBoolean iIsGeomFree, const CATBoolean iIsTypeFree);
/**
 * Defines the constraints on the geometry of faces of a given type.
 * <br>By default
 * <ul>
 * <li>Canonical faces are not free: <tt>iIsTypeFree == FALSE</tt>, <tt>iIsGeomFree == FALSE</tt>.
 * <li>All non-canonical faces are free: <tt>iIsTypeFree == TRUE</tt>, <tt>iIsGeomFree == TRUE</tt>.
 * </ul>
 * @param iType
 * The geometric type of the faces.
 * @param iIsGeomFree
 * The status of the modification of the face geometry.
 * <br><b>Legal values</b>: <tt>FALSE</tt> if its geometry cannot be changed, <tt>TRUE</tt>
 * if it can.
 * @param iIsTypeFree
 * The status of the preservation of the face geometry type (if <tt>TRUE == iIsGeomFree</tt>).
 * <br><b>Legal values</b>: <tt>FALSE</tt> if the canonicity must be kept (a cylinder
 * cannot become a Nurbs surface), <tt>TRUE</tt>
 */
	int SetCanonic(const CATBoolean iIsGeomFree, const CATBoolean iIsTypeFree);

/**
 * Defines the constraints on the geometry of an edge.
 * @param iE
 * The pointer to the edge.
 * @param iOrder
 * <br>By default an edge can be modified.
 * It is possible to keep the initial gap of an edge or to minimize the deformation
 * of an edge.
 * <br>By default the G1 continuity of an edge can be modified.
 * It is possible to keep the initial sharpness of an edge.
 * The angle between the 2 surfaces will be kept relatively to the G1 Tolerance
 * <tt>0</tt> for a G0 continuity.
 * <tt>1</tt> for a G1 continuity.
 */ 
    int SetEdge(CATEdge * iE, const short iOrder);	

/**
 * Defines the constraints on the geometry of a list of edges.
 * <br>By default an edge can be modified.
 * It is possible to keep the initial gap of an edge or to minimize the deformation
 * of an edge.
 * By default the G1 continuity of an edge can be modified.
 * It is possible to keep the initial sharpness of an edge.
 * The angle between the 2 surfaces will be kept relatively to the G1 Tolerance
 * <tt>0</tt> for a G0 continuity.
 * <tt>1</tt> for a G1 continuity.
 */  
    int SetEdge(const ListPOfCATEdge &iListOfEdges , const short iOrder);	

/**
 * Defines an option for adjusting PCurves when there is a hole between them.
 * <br>By default the PCurves are adjusted only if their adjacent vertex belongs
 * to an edge to heal.
 * It is possible to adjust the PCurves on other kind of vertex.
 * <tt>0</tt> adjust PCurves adjacent to a vertex of an edge to heal.
 * <tt>1</tt> adjust also PCurves if the vertex belongs to the shell boundary.
 * <tt>2</tt> for G1 healing only, the vertex will be adjusted in tangency.
 */  
    int SetAdjustPCurve(const short iAdjustPCurve);	
	
	/**
	* Activates multiprocesses mode if  iNumberOfProcessesToUse is greater that 1.
	* @param iNumberOfProcessesToUse [in]
	*  The number of processes to use
	* Return value::<br><tt>
	* <ul>
	* <li> 0     : success
	* <li> other : failure. Only mono process context is availables
	* </ul> 
	*/
	int SetParallelComputingContext( const int iNumberOfProcessesToUse );


/** 
 * @nodoc
 * Internal use for debug purpose.
 */
	int SetApproxParam (const int iMaxNumberOfPatch, const short iMaxdegree);

/** 
 * @nodoc
 * Internal use for debug purpose.
 * To set the maximum number of iterations in the healing process
 */
	void SetMaxIter (const int iMaxIter);

/** 
 * Runs <tt>this</tt> operator.
 */
	int Run();
	int RunOperator();
		
	void              RequireDefinitionOfInputAndOutputObjects();

	//---------
	// Results
	//---------    
/**
 * Defines whether the resulting body must be frozen.
 * @param iFreezeMode
 * The freeze mode.
 */
	void SetFreezeMode (CATBodyFreezeMode   iFreezeMode=CATBodyFreezeOn);

/**
 * Returns the pointer to the resulting healed body.
 * @return
 * The pointer to the resulting body. 
 * If you do not want to keep the resulting body, 
 * use the @href CATICGMContainer#Remove method to remove it from the 
 * geometry factory.
 */
    CATBody * GetResult();

/**
 * Returns the global maximum G0 deviation.
 * @return
 * The maximum G0 gap on the whole body.
 * Can also be used for the initial Body.
 */
    double G0MaxError();

/**
 * Returns the global maximum G1 deviation.
 * @return
 * The maximum G1 gap on the whole body.
 */
    double G1MaxError(); 

/** 
 * @nodoc
 * Not Yet Impemented.
 */
    double G2MaxError();

/**
 * After healing, this method returns the final maximum G0 gap on Vertices to be healed
 * @return
 * The maximum G0 gap
 */
    double G0MaxErrorOnVertices();

/**
 * Retrieves the G0 continuity diagnosis for a given vertex.
 * @param iV
 * The pointer to the vertex to be tested.
 * @param ioG0Error
 * The value of the maximum G0 gap on this Vertex.
 * @return
 * -1 if the vertex has not been impacted by the deformation
 */
    int G0MaxError(CATVertex * iV , double &ioG0Error);


/**
 * Tests whether the global continuity constraint is satisfied by the resulting body
 * relatively to the default tolerances or the tolerances entered by the method 
 * SetTolerance.
 * @return
 * The result of the test. 
 * <br>>b<Legal values</b>: <tt>TRUE</tt> if it is, <tt>FALSE</tt> otherwise.
 */
    CATBoolean IsSatisfied();

/**
 * Retrieves the G0 continuity diagnosis for a given edge.
 * The edges have to belong to one of the deformed faces.
 * @param iE
 * The pointer to the edge to be tested.
 * @param ioG0Error
 * The value of the maximum G0 deviation along the edge.
 * @return
 * -1 if the edge has not been impacted by the deformation
 */
    int G0MaxError(CATEdge * iE , double &ioG0Error);

/**
 * Retrieves the G1 continuity diagnosis for a given edge.
 * The edges have to belong to one of the deformed faces.
 * @param iE
 * The pointer to the edge to be tested.
 * @param ioG0Error
 * The value of the maximum G0 deviation along the edge.
 * @return
 * -1 if the edge has not been impacted by the deformation
 */
    int G1MaxError(CATEdge * iE , double &ioG1Error); 

/** 
 * @nodoc
 * Not Yet Implemented.
 */
    int G2MaxError(CATEdge * iE, double &ioG2Error );

/**
 * Tests whether the continuity constraint is satisfied for a given edge relatively 
 * to the required tolerances
 * @param iE
 * The pointer to the edge to be tested.
 * @param ioIsSatisfied
 * The result of the test. 
 * <br>>b<Legal values</b>: <tt>TRUE</tt> if it is, <tt>FALSE</tt> otherwise.
 * @return
 */
    int IsSatisfied(CATEdge * iE , CATBoolean & ioIsSatisfied);

/**
 * Tests whether the continuity constraint required for a given edge is compatible
 * with the constraints on its adjacent faces.
 * If two adjacent faces are not Free, the edge is not Compatible.
 * @param iE
 * The pointer to the edge to be tested.
 * @param oIsCompatible
 * The result of the test. 
 * <br>>b<Legal values</b>: <tt>TRUE</tt> if it is, <tt>FALSE</tt> otherwise.
 * @return
 */
		int IsCompatible(CATEdge * iE , CATBoolean &oIsCompatible);

/**
 * Tests whether the continuity constraint required for a given edge is compatible
 * with the constraints on its adjacent faces.
 * If two adjacent faces are not Free, the edge is not Compatible for G0 or G1 Healing.
 * @param iE
 * The pointer to the edge to be tested.
 * @param iOrder
 * The order to test 
 * @param oIsCompatible
 * The result of the test. 
 * <br>>b<Legal values</b>: <tt>TRUE</tt> if it is, <tt>FALSE</tt> otherwise.
 * @return
 */
		int IsCompatible(CATEdge * iE , const short iOrder , 
			             CATBoolean &oIsCompatible);

/**
 * This method can be called before healing and after healing
 * Before healing, it returns the list of the edges with G0 continuity 
 * default relatively to the tolerance : it is the list of edges to be healed.
 * After healing, it returns the list of the edges with remaining G0 
 * continuity default relatively to the tolerance.
 * @param ioListOfEdges
 * The list of the pointers to the Edges that have not been corrected.
 * @return
**/
	int GetOpenEdges(ListPOfCATEdge & ioListOfEdges);

/**
 * This method can be called before healing and after healing
 * Before healing, it returns the list of the edges with G1 continuity 
 * default relatively to the tolerance (See SetMaxG1Tolerance) : 
 * it is the list of edges to be healed with tangency.
 * After healing, it returns the list of the edges with remaining G1 
 * continuity default relatively to the tolerance (See SetG1Tolerance).
 * @param ioListOfEdges
 * The list of the pointers to the Edges that have not been corrected.
 * @return
**/
	int GetSharpEdges(ListPOfCATEdge & ioListOfEdges);

/**
 * After healing, this method returns the list of the vertices with remaining G0 
 * continuity default relatively to the tolerance.
 * @param ioListOfVertices
 * The list of the pointers to the vertices that have not been corrected.
 * @return
**/
	int GetOpenVertices(ListPOfCATVertex & ioListOfVertices);

/**
 * Retrieves the value of the maximum deformation for a given edge.
 * @param iE
 * The pointer to the edge to be tested.
 * @param oMaxDef
 * The value of the maximum deformation along the edge.
 * @return
 * -1 if the edge has not been impacted by the deformation
 */
	int GetMaxDeformationOnEdge(CATEdge * iE, double &oMaxDef);

/**
 * Retrieves the faces that could not be satisfactorily deformed.
 * <br>In this case, they remain the same.
 * @param ioListOfFaces
 * The list of the pointers to the faces that could not be deformed.
 * @return
 */
	int GetNoDeformedFaces(ListPOfCATFace & ioListOfFaces);

/**
 * Retrieves the faces that have been deformed.
 * @param ioListOfFaces
 * The list of the pointers to the faces that have been  deformed.
 * @return
 */
	int GetDeformedFaces(ListPOfCATFace & ioListOfFaces);

/**
 * Retrieves the value of the maximum deformation for a given face.
 * @param iF
 * The pointer to the face to be tested.
 * @param oMaxDef
 * The value of the maximum deformation along the face.
 * @return
 * -1 if the face has not been impacted by the deformation
 */
	int GetMaxDeformationOnFace(CATFace * iF, double &oMaxDef);

/**
 * Retrieves the value of the maximum deformation allowed, computed by the method SetAutoMaxShapeDeformation();
 * @param oMaxDef
 * The value of the maximum deformation allowed
 * @return
 * -1 if the method SetAutoMaxShapeDeformation() has not been used
 */
  int GetAutoMaxShapeDeformation(double &oMaxDef);


 //protected:
/**
 * @nodoc
 * Constructs a healing operator.
 * @param iGeoFactory
 * The pointer to the factory of the geometry.
 * @param iTopData
 * The pointer to the topological data corresponding to the configuration and the journal
 * @param iBody
 * The pointer to the body to be healed.
 */
  CATHealing(CATGeoFactory * iGeoFactory,
	           CATTopData * iTopData,
			   CATBody * iBody);
	
protected:		
	const CATString  *GetOperatorId() ;

private :

 CATHealingImp *    _Oper;
 CATBoolean  _DeleteTopData;
 CATTopData * _TopData;
};

/**
 * Creates a topological operator that heals geometric holes and geometric tangency
 * defaults inside skin bodies.
 * <br>The principle is to create new surfaces by deforming the initial surfaces, so that the
 * the gap of the edges and if required the angle between the two surfaces are reduced to a given value.
 * Continuity objectives can be precised between
 * the surfaces. The healed body is created, using these new surfaces and 
 * sharing the non-modified geometry and topology of the initial body (smart concept).
 * @param iGeoFactory
 * The pointer to the factory of the geometry. 
 * @param iData
 * The pointer to the topological data corresponding to the configuration and the journal.
 * @param iBodyToHeal
 * The pointer to the body to be healed.
 * This pointer can be NULL. Then use the method SetBodyToHeal before using all the other
 * methods.
 * @return
 * The pointer ti the created operator. To delete with the usual C++ operator after use.
 */
ExportedByCATSurfacicTopoOperators
CATHealing * CATCreateHealing(CATGeoFactory  *iFactory, CATTopData *iData, CATBody * iBodyToHeal);
#endif
