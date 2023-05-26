#ifndef CATLengthFromBodyOnWire_h
#define CATLengthFromBodyOnWire_h

// COPYRIGHT DASSAULT SYSTEMES  1999

/**
* @level Protected
* @usage U1
 */ 

#include "YJ000GSM.h"
#include "ListPOfCATVertex.h"
#include "ListPOfCATEdge.h"
#include "CATSkillValue.h"
#include "CATMathDef.h"
#include "CATTopDef.h"
#include "CATMathPoint.h"
#include "CATCrvParam.h"
#include "CATTopOperator.h"
#include "CATTopData.h"

class CATVertex;
class CATEdge;
class CATWire;
class CATBody;
class CATGeoFactory;
class CATString;
class CATLengthFromBodyOnWireImpl;
/**
* Class defining the operator that computes the length between two point bodies.
* This operator can be used in two modes.
* In BASIC mode, the operation is run at the operator creation. In this mode,
* you have to read the resulting distance, and delete the operator, as in the following 
* example:
*<pre>CATLengthFromBodyOnWire * Op =  CATLengthFromBodyOnWire (factory,vertex1,vertex2); 
* double distance = Op->GetDistance(NULL,NULL);
* delete Op;</pre>
* If you need specific parameters, use the ADVANCED mode:
* <ul>
*<li> Create the operator ,
*<li> Set parameters,
*<li> Run,
*<li> Get the resulting distance,
*<li> Delete the operator.
*</ul>
* Example:
* <pre> 
* CATLengthFromBodyOnWire * Op =  CATLengthFromBodyOnWire (factory,vertex1,vertex2); 
* Op->SetSupport(Wire); // on a wire
* Op->Run();
* CATMathPoint Point1, Point2;
* double distance = Op->GetDistance(&Point1,&Point2);
* delete Op;
*</pre>
*/
class ExportedByYJ000GSM CATLengthFromBodyOnWire  : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATLengthFromBodyOnWire);
public:
  friend class CATLengthFromBodyOnWireImpl;

 /**
	 * Constructs an operator that computes the distance between two vertices along a wire.
	 * @param iFactory
	 * The factory that creates the resulting body.
     * @param iData
	 * The pointer to the data defining the software configuration.
	 * @param iVertex1
	 * A pointer to the first vertex.
	 * @param iVertex2
	 * A pointer to the second vertex.
	 * @param iWire
	 * A pointer to the wire on which the distance is computed.
     * @param iMode
	 * The operator mode.
	 * <dl><dt><tt>BASIC</tt> The operation is performed at the operator creation.
     *     <dt><tt>ADVANCED</tt>Use the Run method. </dl>
	 */
  CATLengthFromBodyOnWire( CATGeoFactory      *iFactory,
                           CATTopData         *iData,
                           CATVertex          *iVertex1, 
                           CATVertex          *iVertex2,
                           CATWire            *iWire,
                           CATSkillValue      iMode     = BASIC );


 /**
	 * Constructs an operator that computes the distance between two vertices along a wire.
	 * @param iFactory
	 * The factory that creates the resulting body.
     * @param iVertex1
	 * A pointer to the first vertex.
	 * @param iVertex2
	 * A pointer to the second vertex.
	 * @param iWire
	 * A pointer to the wire on which the distance is computed.
     * @param iMode
	 * The operator mode.
	 * <dl><dt><tt>BASIC</tt> The operation is performed at the operator creation.
     *     <dt><tt>ADVANCED</tt>Use the Run method. </dl>
	 */
  CATLengthFromBodyOnWire( CATGeoFactory      *iFactory,
                           CATVertex          *iVertex1, 
                           CATVertex          *iVertex2,
                           CATWire            *iWire,
                           CATSkillValue      iMode     = BASIC );

/**
	 * Constructs an operator that computes the distance between two vertices along a wire body.
	 * @param iFactory
	 * The factory that creates the resulting body.
      * @param iData
	 * The pointer to the data defining the software configuration.
	 * @param iVertex1
	 * A pointer to the first body point.
	 * @param iVertex2
	 * A pointer to the second body point.
	 * @param iWire
	 * A pointer to the wire body on which the distance is computed.
     * @param iMode
	 * The operator mode.
	 * <dl><dt><tt>BASIC</tt> The operation is performed at the operator creation.
     *     <dt><tt>ADVANCED</tt>Use the Run method. </dl>
	 */
  CATLengthFromBodyOnWire( CATGeoFactory      *iFactory,
                           CATTopData         *iData,
                           CATBody            *iVertex1, 
                           CATBody            *iVertex2,
                           CATBody            *iWire,
                           CATSkillValue      iMode     = BASIC );
/**
	 * Constructs an operator that computes the distance between two vertices along a wire body.
	 * @param iFactory
	 * The factory that creates the resulting body.
	 * @param iVertex1
	 * A pointer to the first body point.
	 * @param iVertex2
	 * A pointer to the second body point.
	 * @param iWire
	 * A pointer to the wire body on which the distance is computed.
      * @param iMode
	 * The operator mode.
	 * <dl><dt><tt>BASIC</tt> The operation is performed at the operator creation.
     *     <dt><tt>ADVANCED</tt>Use the Run method. </dl>
	 */
  CATLengthFromBodyOnWire( CATGeoFactory      *iFactory,
                           CATBody            *iVertex1, 
                           CATBody            *iVertex2,
                           CATBody            *iWire,
                           CATSkillValue      iMode     = BASIC );

  ~CATLengthFromBodyOnWire();

  /**
   * Runs the operator in <tt>ADVANCED</tt> mode.
   * @return
   * A diagnosis.
   * <br>Legal values</tt>: 0 if some arguments of the operator are invalid, 1 otherwise.
   */
  int  Run();
  
  /**
   * Returns the computed distance.
   * @param iMathPoint1
   * A pointer to the mathematical definition of the first point. 
   * <br>If <tt>NULL</tt>, this argument is not computed.
   * @param iMathPoint2
   * A pointer to the mathematical definition of the second point.
   * <br>If <tt>NULL</tt>, this argument is not computed.
   * @return
   * The computed distance.
   * <br>Sample: to retrieve the distance and the mathematical definition of the first point:
   * <pre>CATMathPoint Point1;
   * double distance = Op->GetDistance(&Point1,NULL);</pre>
   */
  CATLength GetDistance( CATMathPoint *iMathPoint1 = NULL, CATMathPoint *iMathPoint2 = NULL) const;

  /** 
	 * Defines the new vertices between which the distance is computed.
	 * <br>To use in <tt>ADVANCED</tt> mode.
  	 * @param iNewVertex1
	 * A pointer to the first vertex.
	 * @param iNewVertex2
	 * A pointer to the second vertex.
	 */
  void SetVertices( CATVertex *iNewVertex1, CATVertex *iNewVertex2 );

	/** 
	 * Defines the new vertices between which the distance is computed.
	 * <br>To use in <tt>ADVANCED</tt> mode.
  	 * @param iNewVertex1
	 * A pointer to the first vertex.
	 * @param iNewVertex2
	 * A pointer to the second vertex.
	 */
  void SetVertices( CATBody *iNewVertex1, CATBody *iNewVertex2 );

	/**
  * Defines a new edge along which the distance is computed.
  * <br>To use in <tt>ADVANCED</tt> mode.
  * @param iNewEdge
  * A pointer to the edge along which the distance is computed.
  */
  void SetEdge( CATEdge *iNewEdge );

	/**
  * Defines a new wire body along which the distance is computed.
  * <br>To use in <tt>ADVANCED</tt> mode.
  * @param iNewEdge
  * A pointer to the wire body along which which the distance is computed.
  */
  void SetEdge( CATBody *iNewEdge );

#if  defined  (  CATIACGMV5R21  )
	//KY1 : 10-12-2010
public:
//	/**	@nodoc @nocgmitf */ 
	static const  CATString  *GetDefaultOperatorId();
//	/**	@nodoc @nocgmitf */
	const  CATString  *GetOperatorId();

#endif

#if  defined  (  CATIACGMV5R21  )
	//KY1 : 10-12-2010
protected:
	///**	@nodoc @nocgmitf */
	int RunOperator();
  CATLengthFromBodyOnWire *GetImplementation();
  CATLengthFromBodyOnWire* _Implementation;
	///**	@nodoc @nocgmitf */
	//static  CATString  _OperatorId;
	///**  
	//@nodoc @nocgmitf 
	//pour le flaggage definitif de la definition complete des donnees Input/Output de l'operateur
	//*/
	void   RequireDefinitionOfInputAndOutputObjects();
#endif

private:

#ifndef   CATIACGMV5R21 
  CATVertex *GetVertexFromBody( CATBody  **iBody );
  //
  void FillEdgesAndOrientationsFromWire( CATWire **iEdge );
  //
  void RunNoEdge();
  //
  void RunWithEdges();
  //
  void GetVertexOnEdge( CATVertex    *iVertex,
			CATMathPoint &oTheResultingPoint,
			CATCrvParam  &oTheResultingParam,
			int          &EdgePos );

  //
  void GetEdgeLimits(  int iEdgePos, 
		       CATCrvParam &StartParam, 
		       CATCrvParam &EndParam );

  //
  int MoveToNextEdge( int &oEdgePos );
  //
  double ComputeLengthOnEdge( int &oEdgePos,
			      CATCrvParam &StartParam,
			      CATCrvParam &EndParam  );

  //
  void SetInternalData();
  

  //- Input data
  CATTopData           _TopData;
  CATGeoFactory       *_Factory;
  CATVertex           *_Vertex1,
                      *_Vertex2;
  CATWire             *_Wire;
  CATLISTP(CATEdge)    _Edge;
  CATSide             *_EdgeSides;

  //- Internal Data;
  CATCrvParam          _StartParam;
  int                  _StartEdgePos;
  CATCrvParam          _EndParam;
  int                  _EndEdgePos;

  //- _Direction must have the values : 
  //-  "1" : for increasing;
  //-  "-1": for decreasing:
  //-  "0" " for vertex on same edge or closed wire.
  int                  _Direction;

  

  //- Computed data
  CATLength           _Result;
  CATMathPoint        _MPt1;
  CATMathPoint        _MPt2;

#endif
  
};


ExportedByYJ000GSM
CATLengthFromBodyOnWire* CATCreateLengthFromBodyOnWire(CATGeoFactory      *iFactory,
                           CATTopData         *iData,
                           CATVertex          *iVertex1, 
                           CATVertex          *iVertex2, 
                           CATWire            *iWire,
                           CATSkillValue      iMode     = BASIC );


ExportedByYJ000GSM
CATLengthFromBodyOnWire* CATCreateLengthFromBodyOnWire(CATGeoFactory      *iFactory,
                           CATTopData         *iData,
                           CATBody            *iVertex1, 
                           CATBody            *iVertex2,
                           CATBody            *iWire,
                           CATSkillValue      iMode     = BASIC );

#endif

