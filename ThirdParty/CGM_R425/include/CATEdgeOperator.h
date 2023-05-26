#ifndef CATEdgeOperator_h
#define CATEdgeOperator_h

// COPYRIGHT DASSAULT SYSTEMES 1999

//-------------------------------------------------------------------------
// Usage :  to create an edge 
//-------------------------------------------------------------------------
//
// The Run method is mandatory. 
// The Target Body can be provided it will be created in other cases
// The Target body will be frozen by default and a report can be done. 
//
// Warning :
//----------
//    In case of usage on closed curves the operator will create an 
//    single edge without check.
//    In other cases use the CATWireOperator ...
//
// Example :
//----------
//    CATEdgeOperator  MyOperator(factory,curve);
//    MyOperator.Run();
//    CATBody* Edgeresult = MyOperator.GetResult();
//
//-------------------------------------------------------------------------
#include "CATGeoToTopOperator.h"
#include "CATCrvLimits.h"

class CATDomain;
class CATEdge;
class CATLoop;
class CATVertex;
class CATCurve;
class CATSurface;
class CATGeoFactory;
class CATBody;
class CATCGMJournalList;
class CATEdgeOperatorExt;

//-------------------------------------------------------------------------
class ExportedByPrimitivesLight CATEdgeOperator :public CATGeoToTopOperator
{
  CATCGMVirtualDeclareClass(CATEdgeOperator);
public:

  // Creates a face bounded by pcurves
  CATEdgeOperator(CATGeoFactory*    factory,
                  CATCurve*	    curve,
                  CATBody*          bodyforcellcreation=NULL,
                  CATBodyFreezeMode bodyfreezemode=CATBodyFreezeOn,
                  CATCGMJournalList *report=NULL);
  CATEdgeOperator(CATGeoFactory*    factory,
    CATTopData * iData,
                  CATCurve*	    curve,
                  CATBody*          bodyforcellcreation=NULL);

  CATEdgeOperator(CATGeoFactory*    iFactory,
									CATTopData *  iData,
                  CATCurve*	    iCurve, const CATCrvLimits & iLims);
  
  ~CATEdgeOperator();

  int Run();

  // return the edge matching the last added curve
  CATEdge*	GetEdge()   const;

		//KY1 : 10-12-2010
public:
	/**	@nodoc @nocgmitf */ 
	static const  CATString  *GetDefaultOperatorId();

	//KY1 : 10-12-2010
	/**	@nodoc @nocgmitf */
	int RunOperator();
protected:
	/**	@nodoc @nocgmitf */
	static  CATString  _OperatorId;
	/**	@nodoc @nocgmitf */
	const  CATString  *GetOperatorId();
	/**  @nodoc @nocgmitf */
	void   RequireDefinitionOfInputAndOutputObjects();

private:

  /**  @nodoc @nocgmitf */
  CATEdgeOperatorExt & GetEdgeOperatorExt() const;
  
};

ExportedByPrimitivesLight CATEdgeOperator * CATCreateEdgeOperator(CATGeoFactory*    iFactory,
									CATTopData *  iData,
                  CATCurve*	    iCurve,
									const CATCrvLimits & iCrvLims);


#endif
//-------------------------------------------------------------------------


