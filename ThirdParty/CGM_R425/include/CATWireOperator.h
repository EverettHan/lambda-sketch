#ifndef CATWireOperator_h
#define CATWireOperator_h

// COPYRIGHT DASSAULT SYSTEMES  1999


#include "CATTopWireExtr.h"
#include "CATTopDef.h"

class CATEdge;
class CATVertex;
class CATCurve;
class CATEdgeCurve;
class CATPointOnEdgeCurve;
class CATGeoFactory;
class CATBody;
class CATCGMJournalList;
class CATWire;
class CATMacroPoint;
class CATPointOnEdgeCurve;
class CATCrvLimits;
class CATWireOperatorExt;

/** 
* Deprecated. Use now @href CATTopWire .
* Class representing the operator that creates a wire body from one or several curves. 
* <br>To use the CATWireOperator:
* <ul><li>Create it with one of the available constructors. You must order the input curves and precise the
* limits of each, as well as their relative orientation, such that the end of
* one curve (possibly reversed) is the beginning of the following.
* <br>Every created edge is positively oriented in the wire. 
* <li>If needed, tune some parameters with the <tt>SetXxx</tt> methods.
* <li> <tt>Run</tt> the operator
* <li>Retrieve the created body (frozen by default) with the <tt>GetResult</tt> method. 
* <li><tt>delete</tt> the operator after use.</ul>
* If there is only one closed curve, the operator creates a wire with two edges.
*/
class ExportedByPrimitivesLight CATWireOperator :public CATTopWireExtr
{
  CATCGMVirtualDeclareClass(CATWireOperator);
public:
	 /** @nodoc */
	CATWireOperator(CATGeoFactory      *iFactory,
		int                 iNbCurves,
		CATCurve          **iCurves,
		CATCrvLimits       *iLimits,
		short              *iOrientations,
		CATBody            *iTargetBody=NULL,
		CATBodyFreezeMode   iBodyfreezemode=CATBodyFreezeOn,
		CATCGMJournalList  *iReport=NULL);
  /**
	* Creates an operator to build a wire body from several curves.
	* @param iFactory
	* The pointer to the factory of the geometry.
	* @param iNbCurves
	* The number of curves to assemble in the wire.
	* @param iCurves
	* The array <tt>[iNbCurves]</tt> of pointers to the curves used to define the wire.
    * @param iLimits
	* The array <tt>[iNbCurves]</tt> of the limits for each curve.
	* @param iOrientations
	* The array <tt>[iNbCurves]</tt> of the relative orientation for each curve.
	* <br><b>Legal values</b>:
	* <dl><dt><tt>1</tt></dt><dd>The curve is used in is original orientation.
	* <dt><tt>-1</tt></dt><dd>The curve is used with an opposite orientation.
	* </dl>
	* Combine with <tt>iLimits</tt>, these specifications must insure that the end of
    * one curve (possibly reversed) is the beginning of the following.
	* Every created edge is positively oriented in the wire.
	* @param iTopData
	* The pointer to the data defining the configuration and the journal. If the journal inside <tt>iData</tt> 
    * is <tt>NULL</tt>, it is not filled.
	*/
	CATWireOperator(CATGeoFactory      *iFactory,
		CATTopData * iData,
		int                 iNbCurves,
		CATCurve          **iCurves,
		CATCrvLimits       *iLimits,
		short              *iOrientations);
	
	/**
    * @nodoc
	* Creates an operator to build a wire body from one curve.
	* @param iFactory
	* The pointer to the factory of the geometry.
	* @param iCurve
	* The pointer to the curve used to define the wire.
    * @param iLimits
	* The limits for <tt>iCurve</tt>.
	* @param iOrientation
	* The relative orientation for <tt>iCurve</tt>.
	* <br><b>Legal values</b>:
	* <dl><dt><tt>1</tt></dt><dd>The curve is used in is original orientation.
	* <dt><tt>-1</tt></dt><dd>The curve is used with an opposite orientation.
	* </dl>
	* The created edge is positively oriented in the wire.
	* @param iTargetBody
	* Must be kept to <tt>NULL</tt>.
	* @param iBodyfreezemode
	* The smart mode of the resulting body.
	* @param iReport
	* The pointer to the journal to fill with the operation report. If <tt>NULL</tt>, the 
	* journal is not written.
	*/
	CATWireOperator(CATGeoFactory      *iFactory,
		CATCurve           *iCurve,
		const CATCrvLimits &iLimits,
		short               iOrientation,
		CATBody            *iTargetBody=NULL,
		CATBodyFreezeMode   iBodyfreezemode=CATBodyFreezeOn,
		CATCGMJournalList  *report=NULL);
	
		/**
		* @nodoc
		* DO NOT USE - SEE ABOVE.
	*/
  CATWireOperator(CATGeoFactory*    factory,
		int               inbcurves,
		CATCurve**        icurves,
		CATBody*          iTargetBody=NULL,
		CATBodyFreezeMode bodyfreezemode=CATBodyFreezeOn,
		CATCGMJournalList *report=NULL);
		/**
		* @nodoc
		* DO NOT USE - SEE ABOVE.
	*/
  CATWireOperator(CATGeoFactory*    factory,
		CATCurve*         icurve,
		CATBody*          iTargetBody=NULL,
		CATBodyFreezeMode bodyfreezemode=CATBodyFreezeOn,
		CATCGMJournalList *report=NULL);
		/**
		* @nodoc
		* DO NOT USE - SEE ABOVE.
	*/
  CATWireOperator(CATGeoFactory*    iFactory,
		int               inbcurves,
		CATCurve**        icurves,
		short*            iorientations,
		CATBody*          iTargetBody=NULL,
		CATBodyFreezeMode bodyfreezemode=CATBodyFreezeOn,
		CATCGMJournalList *report=NULL);
	
	
		/**
        * @nodoc
		* Creates an operator to add a new edge at the end of an existing wire body.
		* <br>To adhere to the smart mechanism, the input body is not modified. The
		* touched cells are duplicated in the resulting body, which shares the
		* non modified cells with the input body.
		* @param iFactory
	    * The pointer to the factory of the geometry.
		* @param iBody
		* The pointer to the body to modify. It must only contain one wire.
		* @param iEndVertex
		* The pointer to one extremity vertex.
		* @param iExtrapolationCurve
		* The pointer to the curve to add. The current limits of the curve define the
		* extremity of the new edge.
		* @param iBodyfreezemode
		* The smart mode of the resulting body.
	    * @param iReport
	    * The pointer to the journal to fill with the operation report. If <tt>NULL</tt>, the 
    	* journal is not written. 
	    */
  CATWireOperator(CATGeoFactory*    factory,
		CATBody*          iBody,
		CATVertex*        iEndVertex,
		CATCurve*         iExtrapolationCurve,
		CATBodyFreezeMode iBodyfreezemode=CATBodyFreezeOn,
		CATCGMJournalList *report=NULL);
  /** @nodoc */
  CATWireOperator(CATGeoFactory*    factory,
    CATTopData *      iData,
		CATBody*          iBody,
		CATVertex*        iEndVertex,
		CATCurve*         iExtrapolationCurve);
	
		/**
        * @nodoc 
		* Creates an operator that closes an existing wire body with a new edge between its extremities.
	    * <br>To adhere to the smart mechanism, the input body is not modified. The
		* touched cells are duplicated in the resulting body, which shares the
		* non modified cells with the input body.
		* @param iFactory
	    * The pointer to the factory of the geometry.
		* @param iBody
		* The pointer to the body to modify. It must only contain one wire.
		* @param iExtrapolationCurve
		* The pointer to the curve to add. The current limits of the curve define the
		* extremity of the new edge.
		* @param iOriNewEdgeVsWire
		* The relative orientation of the curve.
		* <br><b>LegalValues</b>: <tt>1</tt> if the curve goes from the last vertex of the wire to its first,
		* <tt>-1</tt> otherwise.
		* @param iBodyfreezemode
		* The smart mode of the resulting body.
	    * @param iReport
	    * The pointer to the journal to fill with the operation report. If <tt>NULL</tt>, the 
  	    * journal is not written. 
		*/
  CATWireOperator(CATGeoFactory*    factory,
		CATBody*          iBody,
		CATCurve*         iExtrapolationCurve,
		CATOrientation    iOriNewEdgeVsWire,
		CATBodyFreezeMode iBodyfreezemode=CATBodyFreezeOn,
		CATCGMJournalList *iReport=NULL);
	
	~CATWireOperator();

	/**
	 * Runs <tt>this</tt> operator.
	 */
	int Run();
  /* @nodoc @nocgmitf */
  int RunOperator();
	
	/**
	* Asks for the closure of the wire.
	* <br> The start extremity of the first curve and 
    * the end extremity of the last curve must be the same.
	*/
	void ForceWireClosure();

   /**
	* Asks for the wire to be marked infinite.
	* <br> The input can only be a single linear curve defined on a plane.
	*/
	void MakeWireInfinite();
	
	/**
	* Returns the pointer to the wire of the resulting body.
	* @return
	* The pointer to the wire of the resulting body. Remember that the whole body is retrieved with
	* the <tt>GetResult</tt> method, and you must manage its deletion if you do not want to keep it.
	*/
	CATWire* GetWire() const;
	
  virtual void SetResultInTargetBody(CATBody * iTB);
  virtual void GetSemiClosureParam(CATCrvParam & Param);
  virtual void SetSemiClosureParam(const CATCrvParam &Param); 

  //***************************************************************************************
  // CGMReplay
  //***************************************************************************************

public:

  /* @nodoc @nocgmitf */
  static const CATString *GetDefaultOperatorId() { return &_OperatorId; }

protected:

  const  CATString  *GetOperatorId();
  CATExtCGMReplay   *IsRecordable(short &LevelOfRuntime, short &VersionOfStream);
  void               RequireDefinitionOfInputAndOutputObjects();

  static CATString   _OperatorId;

  //***************************************************************************************
	

private:

  /**  @nodoc @nocgmitf */
  CATWireOperatorExt & GetWireOperatorExt() const;
};
#endif
