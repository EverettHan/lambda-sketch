#ifndef CATTopWireExtr_h
#define CATTopWireExtr_h

// COPYRIGHT DASSAULT SYSTEMES  2000


#include "CATTopWire.h"
#include "CATTopDef.h"
#include "CATMathInline.h"

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
class CATCrvParam;

/** 
* Class representing the operator that creates a wire body from one or several curves. 
* <br>To use the CATTopWireExtr:
* <ul><li>Create it with one of the <tt>CATCreateTpoWire</tt> global methods. 
* You must order the input curves and precise the
* limits of each, as well as their relative orientation, such that the end of
* one curve (possibly reversed) is the beginning of the following.
* <br>Every created edge is positively oriented in the wire. 
* <li>If needed, tune some parameters with the <tt>SetXxx</tt> methods.
* <li> <tt>Run</tt> the operator
* <li>Retrieve the created body (frozen by default) with the <tt>GetResult</tt> method. 
* <li><tt>delete</tt> with the usual C++ delete operator after use.</ul>
* If there is only one closed curve, the operator creates a wire with two edges.
*/
class ExportedByPrimitivesLight CATTopWireExtr : public CATTopWire
{
  CATCGMVirtualDeclareClass(CATTopWireExtr);
public:
	
	/** @nodoc */
	INLINE CATTopWireExtr(CATGeoFactory      *iFactory,
		CATTopData         * iData);

	/** @nodoc */
	INLINE CATTopWireExtr(CATGeoFactory      *iFactory, 
		CATBody            *iBodyForCellCreation,
		CATBodyFreezeMode   iBodyFreezeMode=CATBodyFreezeOn,
		CATCGMJournalList  *iReport=NULL);
	INLINE virtual ~CATTopWireExtr();
  virtual void SetResultInTargetBody(CATBody * iTB)=0;
  virtual void GetSemiClosureParam(CATCrvParam & Param)=0;
  virtual void SetSemiClosureParam(const CATCrvParam &Param)=0;

};

		/**
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
	  */
ExportedByPrimitivesLight CATTopWireExtr * CATCreateTopWire(CATGeoFactory*    factory,
    CATTopData *      iData,
		CATBody*          iBody,
		CATVertex*        iEndVertex,
		CATCurve*         iExtrapolationCurve);
	
ExportedByPrimitivesLight CATTopWireExtr * CATCreateTopOldWire(CATGeoFactory      *iFactory,
                                                   CATTopData         *iData,
                                                   int                 iNbCurves,
                                                   CATCurve          **iCurves,
                                                   CATCrvLimits       *iLimits,
                                                   short              *iOrientations);

//-------------------------------------------------------------------------------------
// INLINE functions
//-------------------------------------------------------------------------------------
INLINE CATTopWireExtr::CATTopWireExtr(CATGeoFactory      *iFactory,
					                  CATTopData         * iData) :
CATTopWire(iFactory, iData)
{
}
//
INLINE CATTopWireExtr::CATTopWireExtr(CATGeoFactory      *iFactory, 
		CATBody            *iBodyForCellCreation,
		CATBodyFreezeMode   iBodyFreezeMode,
		CATCGMJournalList  *iReport) :
CATTopWire(iFactory,iBodyForCellCreation, iBodyFreezeMode, iReport)
{
}
//	
INLINE CATTopWireExtr::~CATTopWireExtr()
{
}
	
#endif















