#ifndef CATDistanceMinImplOld_h
#define CATDistanceMinImplOld_h

// COPYRIGHT DASSAULT SYSTEMES  1999

#include "CATDistanceMinImpl.h"
#include "CATExtTopOperator.h"
#include "CATHybDef.h"
#include "CATMathDef.h"
#include "AnalysisToolsLight.h"

class CATDistanceMinBodyFDM;
class CATTopOpEnvironment;
class BodyFDM;

/**
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
class ExportedByAnalysisToolsLight CATDistanceMinImplOld : public CATDistanceMinImpl
{
  public :
    /** @nodoc */
    CATDistanceMinImplOld(CATGeoFactory  *iFactory,CATTopData * iData,
                           CATBody        *iBody1,
                           CATBody        *iBody2);
   // Surcharge du new/delete
   CATCGMNewClassArrayDeclare;

   virtual ~CATDistanceMinImplOld();     

 		/**
		 * Defines a maximum distance between the two bodies (<tt>ADVANCED</tt> mode).
		 * @param iDistance
		 * The value of the distance known to be an upper bound of the distance between the 
		 * two bodies. This can optimize the performance of the computation.
		 */
    void    SetDistanceMax(double iDistance);

		/**
		 * Asks for the computation of the points realizing the minimum distance (<tt>ADVANCED</tt> mode).
		 *<br>The life cycle of the points is managed by the operator: they are deleted at the
		 * operator deletion, or when another computation is asked for 
		 * (@href CATDistanceMinImplOld#ReplaceBody).
		 * @param iTrueOrFalse
		 * The computation mode.
		 * <br><b>Legal values</b>:
		 * <tt>TRUE</tt> if the points must be computed, <tt>FALSE</tt> otherwise.
		 */
    void    SetPointComputationMode(CATBoolean iTrueOrFalse);

		/** @nodoc */
    void    SetMaxNumberOfTests(CATLONG32 iMaxNumberOfTests); 

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
		 * <br>The life cyle of the points is managed by the operator.
		 * @param oPoint1
		 * The pointer to the point on the first body.
		 * @param oPoint2
		 * The pointer to the point on the second body.
		 */
    void    GetPoints(CATPoint *&oPoint1, CATPoint *&oPoint2);

		/**
		 * Returns the cells on which are the points realizing the minimum distance (<tt>ADVANCED</tt> mode).
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

    void SetEnvironment(CATTopOpEnvironment * iEnviron);
    void ErasePoint(CATPoint *&oPoint);
		/**
		 * Returns the cells on which are the points realizing the minimum distance (<tt>ADVANCED</tt> mode).
		 * <br>The life cyle of the cells is managed by the operator.
		 * @param iNum
		 * 1 for first body, 2 for second body.
		 * @param oCell2
		 * The pointer to the specified body.
		 */
    void    GetBody(CATLONG32 iNum, CATBody *& oBody);
		/**
		 * Has been done
		 */
    CATBoolean    Done();

		/**
		 * Has been done
		 */
     void  SetDone(CATBoolean idone);
		 
	   /**  @nodoc @nocgmitf */
    double GetDistanceMax();

    /**  @nodoc @nocgmitf */
    CATLONG32 GetMaxNumberOfTests(); 

    /**  @nodoc @nocgmitf */
    CATBody* GetBody1(); 

    /**  @nodoc @nocgmitf */
    CATBody* GetBody2(); 

    CATBoolean GetMathPoints(CATMathPoint& oP1, CATMathPoint& oP2);

    //KY1 : 10-12-2010
protected:		 
	   /**  @nodoc @nocgmitf */
	   void   RequireDefinitionOfInputAndOutputObjects();

     /**  @nodoc @nocgmitf */
     void   GetPoints_forDebug(CATPoint *&oPoint1, CATPoint *&oPoint2);

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
    CATTopOpEnvironment     *_Environment;
    CATBoolean               _ImportedEnvironment;

    CATDistanceMinBodyFDM   *_ope_FDM;
   /** @nodoc */
};
#endif










