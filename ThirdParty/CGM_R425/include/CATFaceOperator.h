#ifndef CATFaceOperator_h
#define CATFaceOperator_h

// COPYRIGHT DASSAULT SYSTEMES 1999

//-------------------------------------------------------------------------
// Usage :  To create a face 
//-------------------------------------------------------------------------
//
// The Run method is mandatory. 
// The Target Body can be provided it will be created in other cases
// The Target body will be frozen by default and a report can be done. 
//
// Warning :
//----------
//    In case of usage on closed surfaces the operator will create an 
//    single face without check.
//    In other cases use the CATSkinOperator ...
//
// Example :
//----------
//    CATFaceOperator  MyOperator(factory,surface);
//    MyOperator.Run();
//    CATBody* faceresult = MyOperator.GetResult();
//
// 
//    CATFaceOperator  MyOperator(factory,npcrv1,pcurves1);
//    MyOperator.AddInternalLoop(npcrv2,pcurves2);
//    MyOperator.Run();
//    CATBody* faceresult = MyOperator.GetResult();
//  
//-------------------------------------------------------------------------
#include "CATGeoToTopOperator.h"
#include "PrimitivesLight.h"

class CATDomain;
class CATFace;
class CATLoop;
class CATEdge;
class CATVertex;
class CATPCurve;
class CATPlane;
class CATSurface;
class CATGeoFactory;
class CATBody;
class CATCGMJournalList;
class CATMathLine;
class CATMathBox;
class CATFaceOperatorExt;

class ExportedByPrimitivesLight CATFaceOperator :public CATGeoToTopOperator
{
  CATCGMVirtualDeclareClass(CATFaceOperator);
public:

  // Creates a body with one face bounded by Surface Boundaries
  CATFaceOperator(CATGeoFactory*     factory, 
                  CATSurface*        surface,
                  CATBody*           targetBody=NULL,
                  CATBodyFreezeMode  bodyfreezemode=CATBodyFreezeOn,
                  CATCGMJournalList* report=NULL);

   CATFaceOperator(CATGeoFactory * iFactory, 
                   CATTopData    * iTopData,
                   CATSurface     * iSurface);

  // Creates a body with one face bounded by pcurves
  CATFaceOperator(CATGeoFactory*     factory,
                  int                iNbCurves,
                  CATPCurve * const ipCurveArray[],
                  CATBody*           targetBody=NULL,
                  CATBodyFreezeMode  bodyfreezemode=CATBodyFreezeOn,
                  CATCGMJournalList *report=NULL);
  //
  CATFaceOperator(CATGeoFactory    * iFactory, 
                  CATTopData       * iData,
                  int                iNbCurves,
                  CATPCurve * const ipCurveArray[]);
  
  // Adds An internal loop 
	void AddInternalLoop(int               nbpcurves,
		CATPCurve**       pcurves);

	int Run();

	~CATFaceOperator();

	//  void CheckCrossing() const;

	CATFace* GetFace() const;

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
  CATFaceOperatorExt & GetFaceOperatorExt() const;
};
#endif

