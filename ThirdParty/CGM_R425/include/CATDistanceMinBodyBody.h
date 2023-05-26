#ifndef CATDistanceMinBodyBody_h
#define CATDistanceMinBodyBody_h

// COPYRIGHT DASSAULT SYSTEMES  1999

/**
* @CAA2Level L1
* @CAA2Usage U1
*/ 

//#include "AnalysisTools.h"
#include "AnalysisToolsLight.h"
#include "CATTopOperator.h"
#include "CATHybDef.h"
#include "CATMathDef.h"
#include "CATIACGMLevel.h"
#include "CATIAV5Level.h"

class CATDistanceMinImpl;
class CATDistanceMinBodyFDM;
class BodyFDM;

/**
 * @deprecated V5R27-R419 CATICGMDistanceBodyBody
 * This API has been deprecated. 
 * Please use the new API instead:
 *   CATICGMDistanceBodyBody (created using CATCGMCreateDistanceBodyBodyOp)
 *
 * Class defining the operator that computes the minimum distance between two bodies.
 * To use the operator:
 * <ul><li>Create it with the <tt>CATCreateDistanceMinTopo</tt> global function,
 * <li>Set parameters to tune its use (<tt>ADVANCED</tt> mode),
 * <li>Run the operator (<tt>ADVANCED</tt> mode),
 * <li>Retrieve the results with the <tt>Get</tt> methods, 
 * <li>If needed, change an input body and rerun the modified operator (<tt>ADVANCED</tt> mode),
 * <li><tt>delete</tt> it after use with the usual C++ <tt>delete</tt> operator.
 * </ul>
 * Note: If the operator is used in <tt>BASIC</tt> mode, the operation is directly computed at the 
 * operator creation. So that you directly access the result without <tt>Run</tt>ning the operator.
 * But you cannot tune the parameters, nor reuse it in another run with other input bodies.
 */
class ExportedByAnalysisToolsLight CATDistanceMinBodyBody : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATDistanceMinBodyBody);
  public :
    /** @nodoc */
    CATDistanceMinBodyBody(CATGeoFactory  *iFactory,CATTopData * iData,
                           CATBody        *iBody1,
                           CATBody        *iBody2);

    /** @nodoc */
    CATDistanceMinBodyBody(CATGeoFactory  *iFactory,CATTopData * iData,
                           CATBody        *iBody1,
                           CATBody        *iBody2,
                           CATBoolean iInternalMode);


#ifndef CATIACGMV5R17 
    /** @nodoc */
    CATDistanceMinBodyBody(CATGeoFactory  *iFactory,
                           CATBody        *iBody1,
                           CATBody        *iBody2);
#endif

    virtual ~CATDistanceMinBodyBody();     

 		/**
		 * Defines a maximum distance between the two bodies (<tt>ADVANCED</tt> mode).
		 * @param iDistance
		 * The value of the distance known to be an upper bound of the distance between the 
		 * two bodies. This can optimize the performance of the computation.
		 */
    void    SetDistanceMax(double iDistance);

		/**
		 * Asks for the computation of the points realizing the minimum distance (<tt>ADVANCED</tt> mode).
		 * This method is to be used prior to calling the GetSupportCells method.
		 * <br>The life cycle of the points is managed by the operator: they are deleted at the
		 * operator deletion, or when another computation is asked for
		 * (@href CATDistanceMinBodyBody#ReplaceBody. This is not applicable to the GetPoints method.
		 * Points retrieved by using GetPoints must be deleted when they become useless.
		 * @param iTrueOrFalse
		 * The computation mode.
		 * <br><b>Legal values</b>:
		 * <tt>TRUE</tt> if the points must be computed, <tt>FALSE</tt> otherwise.
		 */
    void    SetPointComputationMode(CATBoolean iTrueOrFalse);

#ifndef CATIACGMV5R17 
		/** @nodoc */
    void    SetMaxNumberOfTests(CATLONG32 iMaxNumberOfTests); 
#endif

		/** 
		* Defines another computation (<tt>ADVANCED</tt> mode).
		* <br>If points were computed, they are deleted.
		* @param iBodyToReplace
		* The pointer to the body to be replaced in the definition of the operator.
		* @param iNewBody
		* The pointer to the body replacing <tt>iBodyToReplace</tt> in this operator.
		*/
    void    ReplaceBody(CATBody *iBodyToReplace, CATBody *iNewBody);

    //-------------------------------------------------------------------------
    // Run and Result Access
    //-------------------------------------------------------------------------
		/**
		 * Computes the distance (<tt>ADVANCED</tt> mode).
		 */
    virtual int    Run();

		/**
		 * Returns the computed minimum distance between the two bodies.
		 * @return
		 * The minimum distance. If the distance could not be computed, returns <tt>-1</tt>.
		 */
    double  GetDistance();

		/**
		 * Returns the points realizing the minimum distance (<tt>ADVANCED</tt> mode).
		 * <br>Useless points must be deleted. Their life cycle is not managed by the operator.
		 * @param oPoint1
		 * The pointer to the point on the first body.
		 * @param oPoint2
		 * The pointer to the point on the second body.
		 */
    void    GetPoints(CATPoint *&oPoint1, CATPoint *&oPoint2);

		/**
		 * Returns the cells on which are the points realizing the minimum distance (<tt>ADVANCED</tt> mode).
		 * The SetPointComputationMode method should be called before, otherwise NULL pointers are returned.
		 * <br>The life cyle of the cells is managed by the operator.
		 * @param oCell1
		 * The pointer to the cell on the first body.
		 * @param oCell2
		 * The pointer to the cell on the second body.
		 */
		void    GetSupportCells(CATCell *&oCell1, CATCell *&oCell2);

		/**
		* Returns the computation mode (<tt>ADVANCED</tt> mode).
		* @return
		* The computation mode.
		* <br><b>Legal values</b>:
		* <tt>TRUE</tt> if the points must be computed, <tt>FALSE</tt> otherwise.
		*/
		CATBoolean GetPointComputationMode();

#if  defined  (  CATIACGMV5R21  )
		//KY1 : 10-12-2010
		/**	@nodoc @nocgmitf */ 
		static const  CATString  *GetDefaultOperatorId();
		/**	@nodoc @nocgmitf */
		const  CATString  *GetOperatorId();
		//KY1 : 10-12-2010
    /**  @nodoc @nocgmitf */
    void   GetPoints_forDebug(CATPoint *&oPoint1, CATPoint *&oPoint2);

protected:
	/**	@nodoc */
	int RunOperator();
	/**	@nodoc @nocgmitf */
	static  CATString  _OperatorId;
	/**  @nodoc @nocgmitf */
	void   RequireDefinitionOfInputAndOutputObjects();
#endif

#ifndef CATIACGMV5R17 

  protected:

    // Private Data
    CATBody                 *_Body1;
    CATBody                 *_Body2;
    BodyFDM                 *_BodyFDM1;
    BodyFDM                 *_BodyFDM2;
    CATGeoFactory           *_Factory;
    CATTopologicalOperator  *_Topo;
    CATPoint                *_ResultPoint1;
    CATPoint                *_ResultPoint2;
    CATCell                 *_SupportCell1;
    CATCell                 *_SupportCell2;
    double                   _Distance;
    double                   _Dist_Max;
    CATBoolean               _pointasked;
    CATBoolean               _compute_pts;
    CATBoolean               _done;
    CATLONG32                     _nb_tests;
    short                    show_trace; 

    CATDistanceMinBodyFDM   *_ope_FDM;
   /** @nodoc */
    void ErasePoint(CATPoint *&oPoint);
#endif
};
#endif










